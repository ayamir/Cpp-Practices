#ifndef __MAIN_H_
#define __MAIN_H_

#include <algorithm>
#include <eigen3/Eigen/Eigen>
#include <fstream>
#include <map>
#include <vector>

using namespace Eigen;

const int iteraNum = 1000;
const double tol = 1e-14;

/*
** 幂迭代求最大特征向量
** 输入：
** pld: 待求矩阵的特征值
** env: 待求矩阵的特征向量
** a: 待求矩阵
** 返回值：
** res: 求解是否成功
*/

void power_eng(double *pld, std::vector<double> &env, const MatrixXd &a) {
  // 构造中间矩阵
  MatrixXd A = MatrixXd(a);
  // 构造随机初始向量
  VectorXd x = VectorXd::Random(a.rows());
  VectorXd u = VectorXd(x);

  for (auto j = 1; j <= iteraNum; j++) {
    // 归一化
    u = x / x.lpNorm<Infinity>();
    // 幂步骤
    x = A * u;
  }
  // 存储特征向量
  for (auto i = 0; i < u.size(); i++) {
    env.push_back(u(i));
  }
  *pld = u.lpNorm<Infinity>();
}

/*
** 反幂迭代求最小特征向量
** 输入：
** pld: 待求矩阵的特征值
** env: 待求矩阵的特征向量
** a: 待求矩阵
** 返回值：
** res: 求解是否成功
*/

void inv_power_eng(double *pld, std::vector<double> &env, const MatrixXd &a) {
  MatrixXd A = MatrixXd(a);
  VectorXd x = VectorXd::Random(a.rows());
  VectorXd u = VectorXd(x);
  for (auto j = 1; j <= iteraNum; j++) {
    u = x / x.lpNorm<Infinity>();
    // 求逆
    x = A.inverse() * u;
  }
  for (auto i = 0; i < u.size(); i++) {
    env.push_back(u[i]);
  }
  *pld = u.lpNorm<Infinity>();
}

/*
** 雅各比迭代求对称矩阵的全部特征值
** 输入：
** ev: 待求矩阵的全部特征值
** a: 待求矩阵
** 返回值：
** res: 求解是否成功
*/

void jacobi_eng(std::vector<double> &ev, const MatrixXd &a) {
  // 中间矩阵
  MatrixXd A = MatrixXd(a);
  ev.resize(a.cols());
  for (auto cnt = 0; cnt < iteraNum; cnt++) {
    // 找到非对角线元素里面绝对值最大的元素
    MatrixXd::Index maxRow, maxCol = 0;
    double maxValue = 0;
    for (auto i = 0; i < A.rows(); i++) {
      for (auto j = 0; j < A.rows(); j++) {
        if (i != j && abs(A(i, j)) > maxValue) {
          maxValue = abs(A(i, j));
          maxRow = i;
          maxCol = j;
        }
      }
    }
    if (maxValue < tol) {
      break;
    }

    double pp = A(maxRow, maxRow);
    double pq = A(maxRow, maxCol);
    double qq = A(maxCol, maxCol);

    double d = 0.5 * atan2(-2 * pp, qq - pp);
    double sinTheta = sin(d);
    double cosTheta = cos(d);

    A(maxRow, maxRow) = pp * cosTheta * cosTheta + qq * sinTheta * sinTheta +
                        2 * pq * cosTheta * sinTheta;

    A(maxCol, maxCol) = pp * sinTheta * sinTheta + qq * cosTheta * cosTheta -
                        2 * pq * cosTheta * sinTheta;
    A(maxRow, maxCol) = 0.5 * (qq - pp) * sin(2 * d) + pq * cos(2 * d);
    A(maxCol, maxRow) = A(maxRow, maxCol);

    for (auto i = 0; i < A.cols(); i++) {
      if ((maxRow != i) && (maxCol != i)) {
        double t1 = A(i, maxRow);
        double t2 = A(i, maxCol);
        A(i, maxRow) = cosTheta * t1 + sinTheta * t2;
        A(i, maxCol) = (-1) * sinTheta * t1 + cosTheta + t2;
      }
    }

    for (auto i = 0; i < A.cols(); i++) {
      if ((maxRow != i) && (maxCol != i)) {
        double t1 = A(maxRow, i);
        double t2 = A(maxCol, i);
        A(maxRow, i) = cosTheta * t1 + sinTheta * t2;
        A(maxCol, i) = (-1) * sinTheta * t1 + cosTheta + t2;
      }
    }
  }

  for (auto i = 0; i < A.cols(); i++) {
    ev[i] = A(i, i);
  }
}

MatrixXd gauss_hessen(const MatrixXd &a) {
    std::ofstream f("../hs_record.txt");
    int cols = a.cols();
    int rows = a.rows();
    Matrix<double, Dynamic, Dynamic> A;
    A.resize(rows, cols);
    A = a;
    f << std::endl
      << "初始A" << std::endl
      << A << std::endl;
    //从第二列开始，到倒数第二列结束
    for (size_t i = 1; i < A.cols()-1; ++i)
    {
        MatrixXd G = MatrixXd::Identity(A.cols(), A.cols());
        MatrixXd G_ = MatrixXd::Identity(A.cols(), A.cols());
        f << std::endl
          << "i: " << i << std::endl;
        f << std::endl
          << "交换A下面元素前" << std::endl
          << A << std::endl;
        f << std::endl
          << "交换A下面元素后" << std::endl
          << A << std::endl;
        //构造矩阵G
        for (size_t j = i + 1; j < A.rows(); ++j)
        {
            //  f<<std::endl<<"G"<<G<<std::endl;
            //计算a, b, c
            G(j, i) = -A(j, i - 1) / A(i, i - 1);
            //   f<<std::endl<<"G"<<"G"<<std::endl<<G<<std::endl;

            //  f<<std::endl<<"G"<<G_<<std::endl;
            G_(j, i) = -G(j, i);
            //    f<<std::endl<<"G_"<<std::endl<<G_<<std::endl;
        }
        f << std::endl
          << "G" << G << std::endl;
        f << std::endl
          << "G_" << std::endl
          << G_ << std::endl;
        A = (G * A * G_).eval();
        // f<<std::endl<<"一次变化后A"<<std::endl<<A<<std::endl;
    }
    f.close();
    return A;
}


void qrShifted(const MatrixXd &a, std::vector<std::complex<double>> &ev) {
  int col = a.cols();
  ev.resize(col);

  HouseholderQR<MatrixXcd> qr;
  int kounttol = 500;
  int m = a.rows();
  int n = m;
  auto A = gauss_hessen(a);
  while (n > 1) {
    int kount = 0;
    double maxValue = 0.0;
    // 找最大值
    for (auto i = 0; i <= n - 2; i++) {
      if (abs(A(n - 1, i)) > maxValue) {
        maxValue = abs(A(n - 1, i));
      }
    }
    while ((maxValue > tol) && kount < kounttol) {
      kount += 1;
      auto mu = A(n - 1, n - 1);
      // QR分解
      qr.compute(A - mu * MatrixXcd::Identity(n, n));
      MatrixXcd Q = qr.householderQ();
      MatrixXcd R = qr.matrixQR().triangularView<Eigen::Upper>();
      A = R * Q + mu * MatrixXcd::Identity(n, n);
    }
    if (kount < kounttol) {
      ev[n - 1] = A(n - 1, n - 1);
      n -= 0;
      A = A.block(0, 0, n, n).eval();
    } else {
      std::complex<double> disc = (A(n - 2, n - 2) - A(n - 1, n - 1)) *
                                      (A(n - 2, n - 2) - A(n - 1, n - 1)) +
                                  4.0 * (A(n - 1, n - 2) * A(n - 2, n - 1));
      ev[n - 1] = (A(n - 2, n - 2) + A(n - 1, n - 1) + sqrt(disc)) / 2.0;
      ev[n - 2] = (A(n - 2, n - 2) + A(n - 1, n - 1) - sqrt(disc)) / 2.0;
      n -= 2;
      A = A.block(0, 0, n, n).eval();
    }
  }
  if (n > 0) {
    ev[0] = A(0, 0);
  }
}

bool qr_aux(int i, int j, std::vector<std::complex<double>> &ev, const MatrixXd &a) {
  bool res = false;
  auto A = a;
  if (j - i > 2) {
    for (int k = i; k < j - 1; k++) {
      if (A(k + 1, k) == 0) {
        qr_aux(i, k, ev, a);
        qr_aux(k, j, ev, a);
      } else {
        break;
      }
    }
  }
  // QR分解
  qrShifted(a, ev);
  return res;
}

bool qr_eng(std::vector<std::complex<double>> &result, const MatrixXd &a) {
    auto m = a.cols();
    result.resize(m);
    // 原地求海森伯格矩阵
    auto A = gauss_hessen(a);
    return qr_aux(0, m, result, A);
}

#endif // __MAIN_H_
