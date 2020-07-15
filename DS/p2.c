/**
 * This is a MST finder with the unoptimized Prim algorithm.
 * Expected time complexity is O(n^2).
 *
 * Required minimal compiler version is GCC 4.7.
 *
 * Copyright (C) 2020 Lucas Lu <itslucas@itslucas.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include <stdio.h>

#define maxn 233
#define inf 19260817 // for the old

int g[maxn][maxn]; // the graph
int mst[maxn];     // save mst
int d[maxn];       // mark
int n, m;          // number of vertex and edge

int prim(int x) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        d[i] =
            g[x][i]; // init the mark with the weight of directly connected edge
        mst[i] = x;  // the mst contains only vertex x at beginning
    }
    d[x] = -1; // mark x
    for (int i = 1; i <= n - 1; i++) {
        int w = inf,
            u = 0; // w means the weight of the chosen edge in current phase
        for (int j = 1; j <= n; j++) { // search for any edge shorter
            if (d[j] < w && d[j] != -1) {
                w = d[j]; // update
                u = j;
            }
        }
        sum += w; // update the total length of mst
        d[u] = -1;
        if (g[mst[u]][u] > 0) { // if edge exists, print the mst
            printf("%d %d\n", mst[u], u);
        }
        for (int i = 1; i <= n; i++) {
            if (d[i] > g[u][i]) {
                d[i] = g[u][i]; // update
                mst[i] = u;     // update path
            }
        }
    }
    return sum;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            g[i][j] = inf; // graph init
        }
    }
    int u, v, w;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        g[u][v] = g[v][u] = w; // undirected graph
    }
    printf("The following %d lines contains the MST, which each line means the "
           "tree contains the edge from x to y\n",
           n - 1);
    int sum = prim(1);
    printf("Total length of the MST: %d\n", sum);
}
