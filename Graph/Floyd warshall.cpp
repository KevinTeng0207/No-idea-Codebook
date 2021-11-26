/*SPA - Floyd-Warshall*/
// 有向圖，正邊　　O(V³)
// 有向圖，無負環　O(V³)
// 有向圖，有負環　不適用

// 無向圖，正邊　　O(V³)
// 無向圖，無負環　不適用
// 無向圖，有負環　不適用
/*Find min weight cycle*/
#define inf 99999
void floyd_warshall(vector<vector<int>> &distance, vector<vector<int>> &ancestor, int n)
{
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                    ancestor[i][j] = ancestor[k][j];
                }
            }
        }
    }
}

vector<vector<int>> distance(n, vector<int>(n, inf));
vector<vector<int>> ancestor(n, vector<int>(n, -1));
distance[a][b] = w;
ancestor[a][b] = w;
floyd_warshall(distance, ancestor, n);
/*Negative cycle detection*/
for (int i = 0; i < n; i++)
{
    if (distance[i][i] < 0)
    {
        cout << "Negative cycle!" << endl;
        break;
    }
}

