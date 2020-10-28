#include <iostream>
#include <vector>
#include "Pentagon.h"
#include "Hexagon.h"
#include "Octagon.h"

void SummaryData(std::vector<Figure*> figuresPtr){
    double summaryArea = 0;
    for (int i = 0; i < figuresPtr.size(); ++i){
        std::cout << "figure number " << i << "\n";
        std::cout << "center:" << figuresPtr[i]->GetCenter() << "\n";
        std::cout << "cords: ";
        figuresPtr[i]->print();
        std::cout << "\n";
        std::cout << "area: " << figuresPtr[i]->Area() << "\n";
        summaryArea += figuresPtr[i]->Area();
    }
    std::cout << "summary area: " << summaryArea << "\n";
}

int main(){
    std::vector<Figure*> figuresPtr;
    Cord curCenter;
    double curRadius;
    double x,y;
    int type;
    std::cout << "insert operation type:";
    while (std::cin >> type){
        if (type == 1){
            std::cout << "insert pentagon center and radius:";
            if (!(std::cin >> curCenter.X >> curCenter.Y >> curRadius)){
                std::cout << "invalid input";
                return -1;
            }
            Pentagon pentagon(curCenter, curRadius);
            figuresPtr.push_back(&pentagon);
        }
        else if (type == 2){
            std::cout << "insert hexagon center and radius:";
            if (!(std::cin >> curCenter.X >> curCenter.Y >> curRadius)){
                std::cout << "invalid input";
                return -1;
            }
            Hexagon hexagon(curCenter, curRadius);
            figuresPtr.push_back(&hexagon);
        }
        else if (type == 3){
            std::cout << "insert octagon center and radius:";
            if (!(std::cin >> curCenter.X >> curCenter.Y >> curRadius)){
                std::cout << "invalid input";
                return -1;
            }
            Octagon octagon(curCenter, curRadius);
            figuresPtr.push_back(&octagon);
        }
        else if (type == 0){
            SummaryData(figuresPtr);
        }
        else if (type == -1){
            int index;
            std::cout << "insert index to delete:";
            if (!(std::cin >> index)){
                std::cout << "invalid input";
                return -1;
            }
            if (index < 0 && index >= figuresPtr.size()){
                std::cout << "invalid input";
                return -1;
            }
            figuresPtr.erase(figuresPtr.begin() + index);
        }
        std::cout << "insert operation type:";
    }
    return 0;
}
