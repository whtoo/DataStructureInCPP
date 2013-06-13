//
//  main.cpp
//  CPPDataStructure
//
//  Created by hong bo on 13-6-13.
//  Copyright (c) 2013年 OpenX. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
using std::cout;
using std::string;
using std::endl;

template <class T>
int getArrayLen(const T& array){
    return (sizeof(array)/sizeof(array[0]));
}

template <class T>
bool checkArrayOrder(const T& array){
    int endIndex = getArrayLen(array) - 1;
    for (int i = 0; i < endIndex; i++) {
        if (array[i] >= array[i+1]) {
            return false;
        }
    }
    
    return true;
}

template <class T>
bool checkInvaidPositiveNumber(void) {
    int leftTimes = 3;
    T number;
    bool sig = false;
    while (leftTimes) {
        cout << "Type number you want:" << endl;
        cin >> number;
        int castNum = static_cast<int>(number);
        
        if (castNum < 0) {
            leftTimes--;
            continue;
        }
        else{
            sig = true;
            break;
        }
    }
   
    return sig;
}

void testOrderCase(void){
    char a[] = {'1','2','3'};
    char b[] = {'1','3','2','5'};
    char c[] = {11,22,17,5};
    char d[] = {'a','b','f','d'};
    string testRet1 = *(checkArrayOrder(a)?new string("yes"):new string("no"));
    std::cout << testRet1 << endl;
}
void testNumCase(void){
    if (checkInvaidPositiveNumber<int>()) {
        cout << "positive num" << endl;
    }
    else{
        cout << "negative num" << endl;
    }
}
int fibNumNonRec(const int& N,const int& a0,const int& a1){
    if (N < 0) {
        cout << "Negative input , error" << endl;
        return 0;
        
    }
    
    if (N == 0) {
        return a0;
    }
    else if (N == 1){
        return a1;
    }
    else if (N > 1 && N < 15) {
        int next,prev,cur;
        cur = a1;
        prev = a0;
       
        
        for (int i = 0; i < N; i++) {
            next = cur + prev;
            if (i < (N - 1)) {
                prev = cur;
                cur = next;
            }
        }
        
        return cur;
    }
    else{
        cout << "over number limit" << endl;
        return 0;
    }
}
int fibNumRec(const int& N,const int& a0,const int& a1){
    if (N < 0) {
        cout << "Negative input , error" << endl;
        return 0;
        
    }
    
    if (N == 0) {
        return a0;
    }
    else if (N == 1){
        return a1;
    }
    else if (N > 1 && N < 15) {
        return fibNumRec(N-1, a0, a1) + fibNumRec(N-2, a0, a1);
    }
    else{
        cout << "over number limit" << endl;
        return 0;
    }
}

void recNMemberSet(){
        
}
int main(int argc, const char * argv[])
{

    // insert code here...
    //testOrderCase();
    //testNumCase();
    cout << fibNumNonRec(13,1,1) << endl;
    cout << fibNumRec(2,1,1) << endl;
    return 0;
}

