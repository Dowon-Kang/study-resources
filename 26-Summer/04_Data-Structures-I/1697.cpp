#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 변수 선언
    int n, num;
    char c;
    queue<int> q;

    cin >> n;

    for(int i = 0; i < n; ++i) {
        // 명령 입력
        cin >> c;

        // 명령이 'i'일 때만 입력이 추가로 필요
        if(c == 'i') {
            cin >> num;

            q.push(num);
        }
        else if(c == 'o') {
            // 비어있는 queue에 .front(), .back(), .pop() 사용시 프로그램이 정지되니 주의
            // 즉, .empty()로 확인 필요
            if(q.empty()) cout << "empty\n";
            else {
                cout << q.front() << "\n";

                q.pop();
            }
        }
        else cout << q.size() << "\n";
    }
    
    return 0;
}