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
            int eventsFromIndex = 0;
            bool isPartitionPossible = isValidDayStartingFromIndex(events, startDayIndex, eventsFromIndex);
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
    bool isValidDayStartingFromIndex(const std::vector<int>& events, const int startIndex,
                                     int& eventsCountToday) {
        eventsCountToday = 0;
        
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
                    return false;
                }
                employeesInTheOfficeAtThisTime.insert(employeeId);
                uniqueEmployeesIdsSeenToday.insert(employeeId);
            } else if(isOutEvent) {
                if(!isEmployeeAlreadyIn) {
                    return false;
                }
                employeesInTheOfficeAtThisTime.erase(employeeId);
            }
            
            bool isOfficeEmpty = (employeesInTheOfficeAtThisTime.size() == 0);
            if(isOfficeEmpty) {
                eventsCountToday = index - startIndex + 1;
                return true;
            }
            
            index++;
        }
        
        bool isOfficeEmpty = (employeesInTheOfficeAtThisTime.size() == 0);
        if(isOfficeEmpty) {
            eventsCountToday = index - startIndex + 1;
            return true;
        }
        return false;
    }
};

#endif
