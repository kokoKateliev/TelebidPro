#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void rotNeighbours(pair<size_t, size_t> coords, vector<pair<size_t, size_t>>& rotten, vector<vector<size_t>>& field, size_t& counter, size_t K, size_t L) {
    size_t x = coords.first, y = coords.second;

    if (x + 1 < K) {
        if (field[x + 1][y] == 0) {
            counter++;
            field[x + 1][y]++;
            pair<size_t, size_t> p(x + 1, y);
            rotten.push_back(p);
        }
    }
    if (x - 1 >= 0) {
        if (field[x - 1][y] == 0) {
            counter++;
            field[x - 1][y]++;
            pair<size_t, size_t> p(x - 1, y);
            rotten.push_back(p);
        }
    }
    if (y + 1 < L) {
        if (field[x][y + 1] == 0) {
            counter++;
            field[x][y + 1]++;
            pair<size_t, size_t> p(x, y + 1);
            rotten.push_back(p);
        }
    }
    if (y - 1 >= 0) {
        if (field[x][y - 1] == 0) {
            counter++;
            field[x][y - 1]++;
            pair<size_t, size_t> p(x, y - 1);
            rotten.push_back(p);
        }
    }
}

size_t countRotten(vector<vector<size_t>>& field, size_t K, size_t L, size_t R, vector<pair<size_t, size_t>>& rotten) {
    size_t counter = rotten.size();
    size_t index = 0;

    for (size_t i = 0; i < rotten.size(); i++) {
        field[rotten[i].first][rotten[i].second]++;
    }
    for (size_t d = 0; d < R; d++) {
        size_t size = rotten.size();
        for (; index < size; index++) {
            rotNeighbours(rotten[index], rotten, field, counter, K, L);
        }
    }
    return counter;
}


int main() {
    size_t K, L, R, x, y;
    cin >> K >> L >> R;

    vector<vector<size_t>> field;
    for (size_t i = 0; i < K; i++) {
        vector<size_t> v;
        for (size_t j = 0; j < L; j++) {
            v.push_back(0);
        }
        field.push_back(v);
    }
    vector<pair<size_t, size_t>> coords;
    while (cin >> x >> y) {
        pair<size_t, size_t> p(x - 1, y - 1);
        coords.push_back(p);
    }

    cout << K * L - countRotten(field, K, L, R, coords);;

    return 0;
}