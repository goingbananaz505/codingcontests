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
        const int invalidDayStartsAtGivenIndex = 0;
        int index = startIndex;
        std::unordered_set<int> uniqueEmployeesIdsSeenToday;
        std::unordered_set<int> employeesInTheOfficeAtThisTime;
        while(index < events.size()) {
            int value = events[index];
            
            bool isInEvent = (value > 0);
            bool isOutEvent = (value < 0);
            int employeeId = abs(value);

            bool isEmployeeAlreadyIn = (uniqueEmployeesIdsSeenToday.find(employeeId) != uniqueEmployeesIdsSeenToday.end());
            
            if(isInEvent) {
                if(isEmployeeAlreadyIn) {
                    return invalidDayStartsAtGivenIndex;
                }
                employeesInTheOfficeAtThisTime.insert(employeeId);
                uniqueEmployeesIdsSeenToday.insert(employeeId);
            } else if(isOutEvent) {
                if(!isEmployeeAlreadyIn) {
                    return invalidDayStartsAtGivenIndex;
                }
                employeesInTheOfficeAtThisTime.erase(employeeId);
            }
            
            bool isOfficeEmpty = (employeesInTheOfficeAtThisTime.size() == 0);
            if(isOfficeEmpty) {
                return index - startIndex + 1;
            }
            
            index++;
        }
        
        bool isOfficeEmpty = (employeesInTheOfficeAtThisTime.size() == 0);
        if(isOfficeEmpty) {
            return index - startIndex + 1;
        }
        return invalidDayStartsAtGivenIndex;
    }
};

#endif
