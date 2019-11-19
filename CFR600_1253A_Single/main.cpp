#include <iostream>
#include <vector>

using namespace std;

void runTest(int id) {
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    bool isBeforeKInterval = true;
    bool isAfterKInterval = false;
    int KValue = 0;
    for(int i = 0; i < N; i++) {
        int diff = B[i] - A[i];
        if(diff < 0) {
            cout << "NO" << endl;
            return;
        }
        
        bool isInKInterval = !isBeforeKInterval && !isAfterKInterval;
        
        if(isBeforeKInterval && diff != 0) {
            KValue = diff;
            isBeforeKInterval = false;
            continue;
        }
        
        if(isInKInterval && diff != KValue) {
            if(diff != 0) {
                cout << "NO" << endl;
                return;
            }
            isAfterKInterval = true;
            continue;
        }
        
        if(isAfterKInterval && diff != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

int main() {
    int T; cin >> T;
    for(int t = 0; t < T; t++) {
        runTest(t);
    }
    
    return 0;
}
