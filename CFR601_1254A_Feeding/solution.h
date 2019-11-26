#ifndef solution_h
#define solution_h

#include <vector>
#include <string>

class Solution {
public:
    void updateMapByAssigningChickens(std::vector<std::vector<char>>& map,
                                      const int chickensNumber) {
        this->currentChickenIdIndex = 0;
        this->currentAssignmentPosition = std::make_pair(0, 0);
        this->rowsCount = static_cast<int>(map.size());
        this->columnsCount = static_cast<int>(map[0].size());
        
        const int riceNumber = getNumberOfRiceCells(map);
        const int extraFedChickensNumber = riceNumber % chickensNumber;
        const int extraFedChickensQuantity = riceNumber / chickensNumber + 1;
        const int normallyFedChickensNumber = chickensNumber - extraFedChickensNumber;
        const int normallyFedChickensQuantity = riceNumber / chickensNumber;
        assignChickensLineByLineAlternatingDirection(map, extraFedChickensNumber, extraFedChickensQuantity);
        assignChickensLineByLineAlternatingDirection(map, normallyFedChickensNumber, normallyFedChickensQuantity);
    }
private:
    const std::string chickenIds = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    
    int rowsCount;
    int columnsCount;
    std::pair<int, int> currentAssignmentPosition;
    int currentChickenIdIndex;
    
    int getNumberOfRiceCells(const std::vector<std::vector<char>>& map) const {
        int count = 0;
        for(int i = 0; i < rowsCount; i++) {
            for(int j = 0; j < columnsCount; j++) {
                bool cellContainsRice = (map[i][j] == 'R');
                if(cellContainsRice) {
                    count++;
                }
            }
        }
        return count;
    }
    
    void assignChickensLineByLineAlternatingDirection(std::vector<std::vector<char>>& map,
                                                      const int chickensNumber,
                                                      const int numberOfRiceEachChicken) {
        if(chickensNumber == 0) { return; }
        
        int riceCount = 0;
        int fedChickens = 0;
        bool finishedFeedingChickens = false;
        
        int i = currentAssignmentPosition.first;
        int j = currentAssignmentPosition.second;
        while(true) {
            bool cellContainsRice = (map[i][j] == 'R');
            if(cellContainsRice) {
                riceCount++;
                if(riceCount > numberOfRiceEachChicken) {
                    riceCount = 1;
                    fedChickens++;
                    currentChickenIdIndex++;
                    finishedFeedingChickens = (fedChickens == chickensNumber);
                    if(finishedFeedingChickens) {
                        currentAssignmentPosition = std::make_pair(i, j);
                        break;
                    }
                }
            }
            map[i][j] = chickenIds[currentChickenIdIndex];
            
            if(hasNextPosition(i, j)) {
                advancePosition(i, j);
            } else {
                break;
            }
        }
    }
    bool hasNextPosition(const int i, const int j) const {
        bool isPositionOnLastRow = (i == this->rowsCount - 1);
        
        if(!isPositionOnLastRow) {
            return true;
        }
        else {
            int direction = getDirectionForJ(i);
            if(direction == -1 && j == 0) {
                return false;
            }
            if(direction == 1 && (j == this->columnsCount - 1)) {
                return false;
            }
            return true;
        }
    }
    void advancePosition(int& i, int& j) const {
        int direction = getDirectionForJ(i);
        if(direction == -1) {
            if(j == 0) {
                i++;
            } else {
                j--;
            }
        }
        if(direction == 1) {
            if(j == this->columnsCount - 1) {
                i++;
            } else {
                j++;
            }
        }
    }
    
    int getStartingValueForJ(const int i) const {
        bool isFirstRowIterated = (i == this->currentAssignmentPosition.first);
        bool isEvenRow = (i % 2 == 0);
        if(isFirstRowIterated) {
            return this->currentAssignmentPosition.second;
        }
        
        if(isEvenRow) {
            return 0;
        } else {
            return columnsCount - 1;
        }
    }
    int getDirectionForJ(const int i) const {
        bool isEvenRow = (i % 2 == 0);
        if(isEvenRow) {
            return 1;
        } else {
            return -1;
        }
    }
};

#endif
