//#include <QCoreApplication>
#include <iostream>
#include <vector>
#include "Range.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    RangeModule range;
    int x,y;
    bool k = true;

    while(k){
        while (true) {
            std::cout << "Please, input initial value of the range: ";
            std::cin >> x;
            if (!std::cin) {
                std::cout << "Date needs to be an integer. ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else break;
        }

        while (true) {
            std::cout << "Please, input the final value of the range: ";
            std::cin >> y;
            if (!std::cin) {
                std::cout << "Date needs to be an integer. ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else if(x>=y) {
                std::cout << "Invalid range set. ";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else break;
        }
        range.AddRange(x,y);
        std::cout<<"List ranges:";
        range.GetListRange();
        std::cout<<std::endl;

        std::cout << "Do you want continue add new range? [y/n] ";
        char type = '\0';
        std::cin>>type;
        while(true){
            if(type != 'y' && type != 'n') {
                std::cout << "Invalid data. Try again"<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else if(type == 'n'){
                k = false;
                break;
            }
            else if(type == 'y') break;
        }
    }

    std::cout<<"List ranges:";
    range.GetListRange();

    //std::cout<<"Remove (3,4)"<<std::endl;
    //range.RemoveRange(3,4);
    //std::cout<<"List ranges:";
    //range.GetListRange();
    return 0;
}
