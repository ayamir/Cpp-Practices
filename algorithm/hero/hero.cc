#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using std::cin;

int n, m;
double map[105][105];
int num[105];

void inverseDijkstra() {
    bool visit[105];
    // init with false
    memset(visit, false, sizeof(visit));

    double lowwast[105];
    for (int i = 0; i < n; i++) {
        lowwast[i] = map[n - 1][i];
    }

    visit[n - 1] = true;
    for (int i = 0; i < n - 1; i++) {
        int k = -1;
        double max = -1;
        for (int j = 0; j < n; j++) {
            if (!visit[j] && max < lowwast[j]) {
                max = lowwast[j];
                k = j;
            }
        }
        visit[k] = true;
        for (int j = 0; j < n; j++) {
            if (!visit[j] && map[k][j] * max > lowwast[j]) {
                lowwast[j] = map[k][j] * max;
            }
        }
    }
    double sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += num[i] * lowwast[i];
    }
    printf("%0.2lf\n", sum);
}

int main(int argc, char *argv[]) {
    while (cin >> n >> m) {
        for (int i = 0; i < n - 1; i++) {
            cin >> num[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = 0;
            }
            map[i][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            double v;
            cin >> a >> b >> v;
            if (map[a - 1][b - 1] < 1.0 - v) {
                map[a - 1][b - 1] = map[b - 1][a - 1] = 1.0 - v;
            }
        }
        inverseDijkstra();
    }
    return 0;
}
