#include <iostream>

using namespace std;


int main() {
    int n, k, f;
    int deletedCount = 0, result;
    bool repeat;

    cin >> n >> k >> f;

    int **matrix;
	matrix = new int*[n+1];
    for (int i = 0; i <= n; i++)
		matrix[i] = new int[n+1];
    
    bool *deleted = new bool[n+1];


    for (int i = 0; i < f; i++){
        int start, end;
        cin >> start >> end;
        matrix[start][end] = 1;
        matrix[end][start] = 1;
    }

    do {
        repeat = false;
        for (int i = 1; i <= n; i++) {
            if (!deleted[i]) {
                int count = 0;
                for (int j = 1; j <= n; j++) {
                    if (matrix[i][j] > 0)
                        count++;
                }
                if (count < k) {
                    repeat = true;
                    deleted[i] = true;
                    deletedCount++;
                    for (int j = 1; j <= n; j++) {
                        matrix[i][j] = 0;
                        matrix[j][i] = 0;
                    }
                    continue;
                }
            }
        }
    } while (repeat);

    result = n - deletedCount;
    cout << result;
}