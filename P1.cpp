#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int input, output = 0;
    int digit_num, digit_count = 0;

    cin >> input;

    while (input) {
        digit_num = input % 10;
        if (digit_num > 4)
            digit_num--;

        output += digit_num * pow(9, digit_count);
        input /= 10;

        digit_count++;
    }
    cout << output << endl;
}
