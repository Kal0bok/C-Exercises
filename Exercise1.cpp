#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void checkNumber() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    cout << "Number " << num << " is: ";
    if (num > 0) cout << "Positive, ";
    else if (num < 0) cout << "Negative, ";
    else cout << "Zero, ";

    if (num % 2 == 0) cout << "Even.\n";
    else cout << "Odd.\n";
}

void calculateFactorial() {
    int n;
    cout << "Enter a positive integer (0-12): ";
    cin >> n;

    if (n < 0 || n > 12) {
        cout << "Invalid input! Please enter a number between 0 and 12.\n";
        return;
    }

    long long factorial = 1;
    for (int i = 1; i <= n; ++i) {
        factorial *= i;
    }
    cout << n << "! = " << factorial << endl;
}

void processArray() {
    int count;
    cout << "How many numbers do you want to enter? ";
    cin >> count;

    if (count <= 0) {
        cout << "Invalid count!\n";
        return;
    }

    vector<int> numbers(count);
    cout << "Enter " << count << " integers:\n";
    for (int i = 0; i < count; ++i) {
        cout << "Element " << (i + 1) << ": ";
        cin >> numbers[i];
    }

    int minVal = *min_element(numbers.begin(), numbers.end());
    int maxVal = *max_element(numbers.begin(), numbers.end());
    double sum = accumulate(numbers.begin(), numbers.end(), 0.0);
    double avg = sum / count;

    cout << "\n--- Array Analysis ---\n";
    cout << "Min value: " << minVal << "\n";
    cout << "Max value: " << maxVal << "\n";
    cout << "Average: " << avg << "\n";
}

void checkPalindrome() {
    string str;
    cout << "Enter a word (no spaces): ";
    cin >> str;

    string reversedStr = str;
    reverse(reversedStr.begin(), reversedStr.end());

    if (str == reversedStr) {
        cout << "Result: '" << str << "' IS a palindrome!\n";
    } else {
        cout << "Result: '" << str << "' is NOT a palindrome.\n";
    }
}

void swapNumbers(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void demoPointers() {
    int x, y;
    cout << "Enter value X: ";
    cin >> x;
    cout << "Enter value Y: ";
    cin >> y;

    cout << "Before swap: X = " << x << ", Y = " << y << "\n";
    swapNumbers(&x, &y);
    cout << "After swap (via pointers): X = " << x << ", Y = " << y << "\n";
}

int main() {
    int choice;

    do {
        cout << "\n=================== C++ FUNDAMENTALS ===================\n";
        cout << "1. Check Number (Even/Odd, Positive/Negative)\n";
        cout << "2. Calculate Factorial (Loops)\n";
        cout << "3. Array Operations (Min, Max, Average)\n";
        cout << "4. String Check (Palindrome)\n";
        cout << "5. Pointer Swap Demo\n";
        cout << "0. Exit\n";
        cout << "========================================================\n";
        cout << "Choose an option (0-5): ";
        cin >> choice;
        cout << "--------------------------------------------------------\n";

        switch (choice) {
            case 1: checkNumber(); break;
            case 2: calculateFactorial(); break;
            case 3: processArray(); break;
            case 4: checkPalindrome(); break;
            case 5: demoPointers(); break;
            case 0: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid option! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}