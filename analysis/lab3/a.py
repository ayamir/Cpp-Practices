#!/usr/bin/env python3

# 高斯相似变换求上hessenberg矩阵
def gauss_hessen(A):
    [row, column] = np.shape(A)
    k = 0
    while k < (column - 2):
        G = np.eye(row)
        x = A[:, k][k + 1]
        if x != 0:
            for i in range(row - (k + 2)):
                a = -(A[:, k][k + 2 + i] / x)
                G[(k + 2 + i)][(k + 1)] = a
            A = G @ A @ inv(G)
        else:
            lie = A[:, k]
            now = k + 2
            while now < row:
                if lie[now] != 0:
                    A[[k + 1, now], :] = A[[now, k + 1], :]
                    A[: [k + 1, now]] = A[: [now, k + 1]]
                    for i in range(row - (k + 2)):
                        a = -(A[:, k][k + 2 + i] / x)
                        G[(k + 2 + i)][(k + 1)] = a
                    A = G @ A @ inv(G)
                    break
                now += 1
        k += 1
    return A

