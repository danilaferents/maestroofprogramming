#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

#define cin fin
#define cout fout




int main() {
    ifstream fin("/Users/danilafurenc/AllMyProjects/maestroofprogramming/2019/test/in.txt");
    ofstream fout("out.txt");

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    int n, a, b, p1, p2;

    cin >> n;

    vector<vector<int>> sets(n, vector<int>());
    vector<pair<int,int>> maxmini(n + 1);
    vector<int> v(n + 1);


    for (int i = 1; i <= n; i++) {
        maxmini[i].first = maxmini[i].second = v[i] = i;
        sets[i].push_back(i);
    }

    while (cin >> str) {
        if (str == "union") {
            cin >> a >> b;
            if (v[a] != v[b]) {
                if (sets[v[a]].size() < sets[v[b]].size()) {
                    for (auto u : sets[v[a]]) {
                        sets[v[b]].push_back(u);
                        v[u] = v[b];
                    }
                    maxmini[v[b]].first = min(maxmini[v[b]].first, maxmini[v[a]].first);
                    maxmini[v[b]].second = max(maxmini[v[b]].second, maxmini[v[a]].second);
                } else {
                    for (auto u : sets[v[b]]) {
                        sets[v[a]].push_back(u);
                        v[u] = v[a];
                    }
                    maxmini[v[a]].first = min(maxmini[v[a]].first, maxmini[v[b]].first);
                    maxmini[v[a]].second = max(maxmini[v[a]].second, maxmini[v[b]].second);
                }
            }

        } else {
            cin >> a;
            cout << maxmini[v[a]].first << " " << maxmini[v[a]].second << " " << sets[v[a]].size() << '\n';
        }
    }

    return 0;
}