#include "main.hpp"
#include <cmath>
#include <iostream>

void solve(const Matrix<double,Dynamic,Dynamic> &m,const std::string &name){
    /*A*/
    //幂法
    std::ofstream f("../ans.txt",std::ios::app);
    double pld;
    std::vector<double> env;
    power_eng(&pld, env, m);
    f<<"幂法"<<std::endl;
    f << name<<"的特征值   " <<pld << std::endl;
    f << name<<"的特征向量" << std::endl;
    for (double i : env)
    {
        f << i <<" ";
    }

    f<<std::endl;

    //jacobi
    env.clear();
    jacobi_eng(env, m);
    f<<"jacobi"<<std::endl;
    f << name<<"的特征值" << std::endl;
    sort(env.begin(),env.end());
    for (double i : env)
    {
        f << i <<" ";
    }
    f << std::endl;
    env.clear();

    //移动qr
    std::vector<std::complex<double>> env1;
    qr_eng(env1, m);
    f<<"移动QR"<<std::endl;
    f << name<<"的特征值" << std::endl;
    sort(env1.begin(),env1.end(),[](const std::complex<double>& a,const std::complex<double>& b){return a.real()<b.real();});
    for (auto & i : env1)
    {
        f << i <<" ";
    }
    f<<std::endl;

    f<<"hessen_berg形式"<<std::endl;
    gauss_hessen(m);
    f << m;
    f<< std::endl;
}


int main(int argc, char *argv[]) {
  Matrix<double, 8, 8> A;
  A << 611, 196, -192, 407, -8, -52, -49, 29, 196, 899, 113, -192, -71, -43, -8,
      -44, -192, 113, 899, 196, 61, 49, 8, 52, 407, -192, 196, 611, 8, 44, 59,
      -23, -8, -71, 61, 8, 411, -599, 208, 208, -52, -43, 49, 44, -599, 411,
      208, 208, -49, -8, 8, 59, 208, 208, 99, -911, 29, -44, 52, -23, 208, 208,
      -911, 99;

  Matrix<double, 10, 10> B;

  B << 1 / 1.0, 1 / 2.0, 1 / 3.0, 1 / 4.0, 1 / 5.0, 1 / 6.0, 1 / 7.0, 1 / 8.0,
      1 / 9.0, 1 / 10.0, 1 / 2.0, 1 / 3.0, 1 / 4.0, 1 / 5.0, 1 / 6.0, 1 / 7.0,
      1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0, 1 / 3.0, 1 / 4.0, 1 / 5.0, 1 / 6.0,
      1 / 7.0, 1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0, 1 / 12.0, 1 / 4.0, 1 / 5.0,
      1 / 6.0, 1 / 7.0, 1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0, 1 / 12.0,
      1 / 13.0, 1 / 5.0, 1 / 6.0, 1 / 7.0, 1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0,
      1 / 12.0, 1 / 13.0, 1 / 14.0, 1 / 6.0, 1 / 7.0, 1 / 8.0, 1 / 9.0,
      1 / 10.0, 1 / 11.0, 1 / 12.0, 1 / 13.0, 1 / 14.0, 1 / 15.0, 1 / 7.0,
      1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0, 1 / 12.0, 1 / 13.0, 1 / 14.0,
      1 / 15.0, 1 / 16.0, 1 / 8.0, 1 / 9.0, 1 / 10.0, 1 / 11.0, 1 / 12.0,
      1 / 13.0, 1 / 14.0, 1 / 15.0, 1 / 16.0, 1 / 17.0, 1 / 9.0, 1 / 10.0,
      1 / 11.0, 1 / 12.0, 1 / 13.0, 1 / 14.0, 1 / 15.0, 1 / 16.0, 1 / 17.0,
      1 / 18.0, 1 / 10.0, 1 / 11.0, 1 / 12.0, 1 / 13.0, 1 / 14.0, 1 / 15.0,
      1 / 16.0, 1 / 17.0, 1 / 18.0, 1 / 19.0;

  Matrix<double, 12, 12> C;
  C << 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 11, 11, 10, 9, 8, 7, 6, 5, 4, 3,
      2, 1, 10, 10, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 9, 9, 9, 9, 8, 7, 6, 5, 4, 3,
      2, 1, 8, 8, 8, 8, 8, 7, 6, 5, 4, 3, 2, 1, 7, 7, 7, 7, 7, 7, 6, 5, 4, 3, 2,
      1, 6, 6, 6, 6, 6, 6, 6, 5, 4, 3, 2, 1, 5, 5, 5, 5, 5, 5, 5, 5, 4, 3, 2, 1,
      4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 2, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 1, 2,
      2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1;

  Matrix<double, 20, 20> D;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      D(i, j) =
          std::sqrt(2.0f / 21.0f) * sin((double)(i + 1) * (j + 1) * acos(-1.0) / 21);
    }
  }

  Matrix<double, 50, 50> E;
  for (int i = 0; i < 50; i++) {
    for (int j = 0; j < 50; j++) {
      if (j < i)
        E(i, j) = -1;

      else if (i == j || j == 49)
        E(i, j) = 1;
      else
        E(i, j) = 0;
    }
  }
  double pld;
  std::vector<double> env;



  return 0;
}
