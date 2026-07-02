/*
2D array key finding and return as pair 

*/

// Online C++ compiler to run C++ program online
#include <iostream>
#include<utility>
using namespace std;

pair<int , int> findPair(int matrix[3][3] , int key){
    for(int i = 0 ; i< 3 ; i++){
        for(int j = 0 ; j< 3 ; j++){
            if(matrix[i][j] == key){
                return {i , j};
            }
        }
    }
    return {-1 , -1} ;
}

int main() {
    // Write C++ code here
    int matrix[3][3]= {{1,2,3},{4,5,6},{7,8,9}};
    int key = 7;
    
    pair<int , int > ans = findPair(matrix , key);
    cout<<"{" << ans.first << " ,"<< ans.second<<"}" ;
    
    cout << "\n Start small. Ship something.";

    return 0;
}
