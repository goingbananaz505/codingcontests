#include <iostream>
#include <vector>
#include "consoleutils.h"
#include "solution.h"

using namespace std;
namespace cu = consoleutils;
Solution solution;

int main() {
    vector<int> a = cu::readSizeAndArray<int>();
    vector<int> events = solution.getEventsPartition(a);
    
    bool isPartitionPossible = (events.size() != 0);
    if(isPartitionPossible) {
        cout << events.size() << endl;
        for(const int& e : events) {
            cout << e << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}
