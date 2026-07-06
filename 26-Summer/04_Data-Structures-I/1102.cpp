#include <iostream>
#include <stack>

using namespace std;

int main() {
    // 변수 선언
    int n, a;
    char c;
    stack<int> stk;

    cin >> n;

    while(n--) {
        // 명령 입력
        cin >> c;

        // 명령이 'i'일 때만 입력이 추가로 필요
        if(c == 'i') {
            cin >> a;

            stk.push(a);
        }
        else if(c == 'c') cout << stk.size() << "\n";
        else if(c == 'o') {
            // 비어있는 stack에 .top(), .pop() 사용시 프로그램이 정지되니 주의
            // 즉, .empty()로 확인 필요
            if(stk.empty()) cout << "empty\n";
            else {
                cout << stk.top() << "\n";

                stk.pop();
            }
        }
    }

    return 0;
}