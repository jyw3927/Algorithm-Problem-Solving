#include <iostream>
#include <algorithm>
using namespace std;

int n, answer = 0;
int **mountain, **difficulty;
int find_difficulty(int x, int y);

int main() {
    cin >> n;

	mountain = new int*[n];
	for (int a = 0; a < n; a++)
		mountain[a] = new int[n];

	difficulty = new int*[n];
	for (int b = 0; b < n; b++)
		difficulty[b] = new int[n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mountain[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = max(answer, find_difficulty(i, j));
        }
    }

    cout << answer << endl;

    return 0;
}

int find_difficulty(int x, int y) {
    int direction[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    if (difficulty[x][y] == 0) {
        for (int i = 0; i < 4; i++) {
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];

            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n && mountain[x][y] > mountain[nextX][nextY]) {
                difficulty[x][y] = max(difficulty[x][y], find_difficulty(nextX, nextY) + mountain[x][y] - mountain[nextX][nextY]);
            }
        }
        return difficulty[x][y];
    } else {
        return difficulty[x][y];
    }
}