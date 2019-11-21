#ifndef solution_h
#define solution_h

#include <vector>
#include <string>

class Solution {
public:
    void updateMapByAssigningChickens(std::vector<std::vector<char>>& map,
                                      const int chickensNumber) {
        this->currentI = 0;
        this->currentJ = 0;
        this->currentChickenIdIndex = 0;
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
    
    int currentI = 0;
    int currentJ = 0;
    int currentChickenIdIndex = 0;
    
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
        for(int i = currentI; i < this->rowsCount; i++) {
            int jDirection = getDirectionForJ(i % 2 == 0);
            int jStart = getStartingValueForJ(i == currentI, i % 2 == 0);
            
            for(int j = jStart; (j >= 0 && j < this->columnsCount); j += jDirection) {
                bool cellContainsRice = (map[i][j] == 'R');
                if(cellContainsRice) {
                    riceCount++;
                    if(riceCount > numberOfRiceEachChicken) {
                        riceCount = 1;
                        fedChickens++;
                        currentChickenIdIndex++;
                        finishedFeedingChickens = (fedChickens == chickensNumber);
                        if(finishedFeedingChickens) {
                            currentI = i;
                            currentJ = j;
                            break;
                        }
                    }
                }
                map[i][j] = chickenIds[currentChickenIdIndex];
            }
            
            if(fedChickens == chickensNumber) {
                break;
            }
        }
    }
    
    int getStartingValueForJ(const bool isFirstRowIterated, const bool isEvenRow) const {
        if(isFirstRowIterated) {
            return currentJ;
        }
        
        if(isEvenRow) {
            return 0;
        } else {
            return columnsCount - 1;
        }
    }
    int getDirectionForJ(const bool isEvenRow) const {
        if(isEvenRow) {
            return 1;
        } else {
            return -1;
        }
    }
};

#endif
