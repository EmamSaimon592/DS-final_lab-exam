#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to evaluate postfix expression
int evaluatePostfix(string expr) {
    stack<int> st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // Skip spaces
        if (ch == ' ')
            continue;

        // If it's a digit, push it to stack
        else if (isdigit(ch)) {
            st.push(ch - '0');  // Convert char digit to int
        }

        // If it's an operator
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();

            int result;
            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                default:
                    cout << "Invalid operator: " << ch << endl;
                    return -1;
            }

            // Push result back to stack
            st.push(result);
        }
    }

    // Final result
    return st.top();
}

int main() {
    string expression;

    cout << "Enter postfix expression (e.g., 5 6 +): ";
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << "Result = " << result << endl;

    return 0;
}



// 🔍 How it Works (Step-by-Step for "5 6 +")

//     Push 5 → Stack: [5]

//     Push 6 → Stack: [5, 6]

//     See +, pop 6 and 5 → Compute 5 + 6 = 11

//     Push result → Stack: [11]

//     Final result = 11


/*Input:

5 6 2 * + 3 -

Step-by-step Breakdown:

    6 2 * → 12

    5 + 12 → 17

    17 - 3 → 14

Output:

Result = 14 */