#ifndef solution_h
#define solution_h

#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> getEventsPartition(const std::vector<int>& events) {
        std::vector<int> numberOfEvents;
        int startDayIndex = 0;
        while(startDayIndex < events.size()) {
            int eventsFromIndex = getMinimumNumberOfEventsFromIndex(events, startDayIndex);
            bool isPartitionPossible = (eventsFromIndex != 0);
            if(!isPartitionPossible) {
                std::vector<int> emptyArray;
                return emptyArray;
            }
            numberOfEvents.emplace_back(eventsFromIndex);
            startDayIndex += eventsFromIndex;
        }
        
        return numberOfEvents;
    }
    
private:
    int getMinimumNumberOfEventsFromIndex(const std::vector<int>& events, const int startIndex) {
        int index = startIndex;
        std::unordered_set<int> uniqueEmployeesIdsSeenToday;
        std::unordered_set<int> employeesInTheOfficeAtThisTime;
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
};

#endif
