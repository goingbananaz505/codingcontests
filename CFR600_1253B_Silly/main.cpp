#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int getMinimumNumberOfEventsFromStartingIndex(const vector<int>& events, const int startIndex) {
    int index = startIndex;
    unordered_set<int> uniqueEmployeesIdsSeenToday;
    unordered_set<int> employeesInTheOfficeAtThisTime;
    while(index < events.size()) {
        int value = events[index];
        
        if(value > 0) {
            bool alreadySeenValue = (uniqueEmployeesIdsSeenToday.find(value) != uniqueEmployeesIdsSeenToday.end());
            if(alreadySeenValue) {
                return 0;
            }
            employeesInTheOfficeAtThisTime.insert(value);
            uniqueEmployeesIdsSeenToday.insert(value);
        } else if(value < 0) {
            bool seenEntrance = (uniqueEmployeesIdsSeenToday.find(-1 * value) != uniqueEmployeesIdsSeenToday.end());
            if(!seenEntrance) {
                return 0;
            }
            employeesInTheOfficeAtThisTime.erase(-1 * value);
        }
        
        if(employeesInTheOfficeAtThisTime.size() == 0) {
            return index - startIndex + 1;
        }
        
        index++;
    }
    

    if(employeesInTheOfficeAtThisTime.size() == 0) {
        return index - startIndex + 1;
    }
    return 0;
}

void runTest(int id) {
    int N; cin >> N;
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    vector<int> numberOfEvents;
    int startDayIndex = 0;
    while(startDayIndex < a.size()) {
        int numberOfEventsFromStartingIndex = getMinimumNumberOfEventsFromStartingIndex(a, startDayIndex);
        if(numberOfEventsFromStartingIndex == 0) {
            cout << -1 << endl;
            return;
        }
        numberOfEvents.emplace_back(numberOfEventsFromStartingIndex);
        startDayIndex += numberOfEventsFromStartingIndex;
    }
    
    cout << numberOfEvents.size() << endl;
    for(const int& e : numberOfEvents) {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    int T = 1;
    for(int t = 0; t < T; t++) {
        runTest(t);
    }
    
    return 0;
}
