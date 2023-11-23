#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries) {
        unordered_map<string, int> nodes;
        int n = equations.size();
        int node_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (nodes.find(equations[i][0]) == nodes.end()) {
                nodes[equations[i][0]] = node_idx++;
            }
            if (nodes.find(equations[i][1]) == nodes.end()) {
                nodes[equations[i][1]] = node_idx++;
            }
        }
        vector<vector<pair<int, double>>> edges(node_idx);
        for (int i = 0; i < n; ++i) {
            int start = nodes[equations[i][0]];
            int end = nodes[equations[i][1]];
            edges[start].push_back(make_pair(end, values[i]));
            edges[end].push_back(make_pair(start, 1 / values[i]));
        }
        vector<double> ret;
        for (const auto &q : queries) {
            double result = -1.0;
            if (nodes.find(q[0]) == nodes.end() ||
                nodes.find(q[1]) == nodes.end()) {
                ret.push_back(result);
                continue;
            }
            int start_idx = nodes[q[0]];
            int end_idx = nodes[q[1]];
            if (start_idx == end_idx) {
                result = 1.0;
            } else {
                queue<int> points;
                points.push(start_idx);
                vector<double> ratios(node_idx, -1.0);
                ratios[start_idx] = 1.0;
                while (!points.empty() && ratios[end_idx] < 0) {
                    int x = points.front();
                    points.pop();
                    for (const auto [y, ratio] : edges[x]) {
                        if (ratios[y] < 0) {
                            ratios[y] = ratios[x] * ratio;
                            points.push(y);
                        }
                    }
                }
                result = ratios[end_idx];
            }
            ret.push_back(result);
        }
        return ret;
    }
};

int main(int argc, char *argv[]) {
    Solution s;
    return 0;
}
