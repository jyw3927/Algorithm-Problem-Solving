#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n, remain_words_cnt;
vector<string> words;
vector<string> shiritori;
bool can_finish = true;

void print_shiritori() {
    for (int i = 0; i < shiritori.size(); i++)
        cout << shiritori[i] << endl;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        string new_word;

        cin >> new_word;

        words.push_back(new_word);
    }
    sort(words.begin(), words.end());

    shiritori.push_back(words[0]);
    words.erase(words.begin());

    while(words.size() > 0) {
        remain_words_cnt = words.size();

        for (int idx = 0; idx < words.size(); idx++) {
            if (shiritori.back().back() == words[idx].front()) {
                shiritori.push_back(words[idx]);
                words.erase(words.begin() + idx);
            }
        }

        for (int idx = words.size()-1; idx >= 0; idx--) {
            if (words[idx].back() == shiritori[0].front()) {
                shiritori.insert(shiritori.begin(), words[idx]);
                words.erase(words.begin() + idx);
            }
        }

        if (remain_words_cnt == words.size()) {
            can_finish = false;
            break;
        }
    }

    if (can_finish) print_shiritori();
    else cout << can_finish << endl;

    return 0;
}