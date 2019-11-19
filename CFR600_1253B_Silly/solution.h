#ifndef solution_h
#define solution_h

#include <vector>
#include <unordered_set>


class Solution {
public:
    std::vector<int> getEventsPartition(const std::vector<int>& events) const {
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
                                     int& eventsCountToday) const {
        eventsCountToday = 0;
        
        int index = startIndex;
        EventValidatorState state;
        bool isValidDayEnd = false;
        while(index < events.size()) {
            int event = events[index];
            
            processEvent(event, state);
            if(state.IsInvalidated) {
                break;
            }
            if(state.IsOfficeEmpty()) {
                isValidDayEnd = true;
                break;
            }
            
            index++;
        }
        
        if(isValidDayEnd) {
            eventsCountToday = index - startIndex + 1;
            return true;
        }
        return false;
    }
    
    struct EventValidatorState;
    void processEvent(const int event, EventValidatorState& state) const {
        bool isInEvent = (event > 0);
        bool isOutEvent = (event < 0);
        int employeeId = abs(event);

        bool isEmployeeAlreadyIn = state.IsEmployeeInOffice(employeeId);
        
        if(isInEvent) {
            if(isEmployeeAlreadyIn) {
                state.IsInvalidated = true;
            }
            state.ProcessInEvent(employeeId);
        } else if(isOutEvent) {
            if(!isEmployeeAlreadyIn) {
                state.IsInvalidated = true;
            }
            state.ProcessOutEvent(employeeId);
        }
    }
    
    struct EventValidatorState {
        std::unordered_set<int> uniqueEmployeesIdsSeenToday;
        std::unordered_set<int> employeesInTheOfficeAtThisTime;
        
        bool IsOfficeEmpty() const {
            return (employeesInTheOfficeAtThisTime.size() == 0);
        }
        bool IsEmployeeInOffice(int id) const {
            return (uniqueEmployeesIdsSeenToday.find(id) != uniqueEmployeesIdsSeenToday.end());
        }
        void ProcessInEvent(int employeeId) {
            employeesInTheOfficeAtThisTime.insert(employeeId);
            uniqueEmployeesIdsSeenToday.insert(employeeId);
        }
        void ProcessOutEvent(int employeeId) {
            employeesInTheOfficeAtThisTime.erase(employeeId);
        }
        bool IsInvalidated = false;
    };
};

#endif
