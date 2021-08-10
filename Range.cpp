#include "Range.h"

void RangeModule::AddRange(int lower, int upper)
{
    RangeData rangeTemp;

    //if the range doesn't exist:
    if( listRange.empty()){
        rangeTemp.lower = lower;
        rangeTemp.upper = upper;
        listRange.push_back(rangeTemp);
    }

    //if the range exists or includes an already created one:
    if(QueryRange(lower, upper)){
        return;
    }

    //if the range intersects an already created one:
    for(int i=0; i<listRange.size(); i++){
        //old range contains new range:
        //old range: (x,y)
        //new range: (a,b), where (a<x, b<y)
        if( lower <= listRange[i].lower && upper >= listRange[i].upper ) {
            //RangeData rangeTemp;
            rangeTemp.lower = lower;
            rangeTemp.upper = upper;
            //remove old range:
            listRange.erase(listRange.begin()+i);
            //add new range:
            listRange.push_back(rangeTemp);
            SortRanges();
            break;
        }
        //old range contains new range:
        //old range: (x,y)
        //new range: (a,b), where (a<=x, b<=y, but b>=x)
        else if( (lower <= listRange[i].lower && upper <= listRange[i].upper &&  upper >= listRange[i].lower)){
            //RangeData rangeTemp;
            rangeTemp.lower = lower;
            rangeTemp.upper = listRange[i].upper;
            //remove old range:
            listRange.erase(listRange.begin()+i);
            //add new range:
            listRange.push_back(rangeTemp);
            SortRanges();
            break;
        }
        //old range contains new range:
        //old range: (x,y)
        //new range: (a,b), where (a>=x, b>=y, but b<=x)
        else if( lower >= listRange[i].lower && upper > listRange[i].upper && lower <= listRange[i].upper ) {
            //RangeData rangeTemp;
            rangeTemp.lower = listRange[i].lower;
            rangeTemp.upper = upper;
            //remove old range:
            listRange.erase(listRange.begin()+i);
            //add new range:
            listRange.push_back(rangeTemp);
            SortRanges();
            break;
        }
        //old range contains new range:
        //old range: (x,y)
        //new range: (a,b), where (a>=x, b>=y, but b<=x)
        else if( lower >= listRange[i].lower && upper > listRange[i].upper && lower < listRange[i].upper ) {
            //RangeData rangeTemp;
            rangeTemp.lower = listRange[i].lower;
            rangeTemp.upper = upper;
            //remove old range:
            listRange.erase(listRange.begin()+i);
            //add new range:
            listRange.push_back(rangeTemp);
            SortRanges();
            break;
        }
        //old range contains new range:
        //old range: (x,y)
        //new range: (a,b), where (b<x OR a>y)
        else if( upper < listRange[i].lower || lower > listRange[i].upper ) {
            //RangeData rangeTemp;
            rangeTemp.lower = lower;
            rangeTemp.upper = upper;
            //add new range:
            listRange.push_back(rangeTemp);
            SortRanges();
            break;
        }
        break;
    }
    return;
}

bool RangeModule::QueryRange(int lower, int upper)
{
    for(int i=0; i<listRange.size(); i++){
        //Range exists:
        if( lower >= listRange[i].lower && upper <= listRange[i].upper ){
            return true;
        }
    }
    return false;
}

void RangeModule::RemoveRange(int lower, int upper)
{
    for(int i=0; i<listRange.size(); i++) {
        if( lower == listRange[i].lower && upper < listRange[i].upper && (upper+1) < listRange[i].upper) {
            RangeData rangeTemp;
            rangeTemp.lower = (upper+1);
            rangeTemp.upper = listRange[i].upper;
            listRange.erase(listRange.begin()+i);
            if(rangeTemp.lower != rangeTemp.upper)
                listRange.push_back(rangeTemp);
            break;
        }
        else if( lower > listRange[i].lower && upper == listRange[i].upper && (lower-1)>listRange[i].lower) {
            RangeData rangeTemp;
            rangeTemp.lower = listRange[i].lower;
            rangeTemp.upper = (lower-1);
            listRange.erase(listRange.begin()+i);
            if(rangeTemp.lower != rangeTemp.upper)
                listRange.push_back(rangeTemp);
            break;
        }
        else if(lower > listRange[i].lower && upper < listRange[i].upper
                && (lower-1)>=listRange[i].lower && (upper+1)<=listRange[i].upper){
            RangeData rangeTemp1, rangeTemp2;
            rangeTemp1.lower = listRange[i].lower;
            rangeTemp1.upper = (lower-1);
            rangeTemp2.lower = (upper+1);
            rangeTemp2.upper = listRange[i].upper;
            listRange.erase(listRange.begin()+i);
            if(rangeTemp1.lower != rangeTemp1.upper)
                listRange.push_back(rangeTemp1);
            if(rangeTemp2.lower != rangeTemp2.upper)
                listRange.push_back(rangeTemp2);
            break;
        }
        else if( lower == listRange[i].lower && upper == listRange[i].upper) {
            listRange.erase(listRange.begin()+i);
            break;
        }
        else {
            noop;}
    }
}


void RangeModule::GetListRange()
{
    for(int i=0; i<listRange.size(); i++){
        std::cout<<"("<<listRange[i].lower<<","<<listRange[i].upper<<") ";
    }
}

void RangeModule::SortRanges()
{
    int length = listRange.size();
    for (int startIndex = 0; startIndex < length - 1; ++startIndex)
    {
        int smallestIndex = startIndex;

        for (int currentIndex = startIndex + 1; currentIndex < length; ++currentIndex)
        {
            if (listRange.at(currentIndex).lower < listRange.at(smallestIndex).lower)
                smallestIndex = currentIndex;
        }
        std::swap(listRange.at(startIndex), listRange.at(smallestIndex));
    }
}
