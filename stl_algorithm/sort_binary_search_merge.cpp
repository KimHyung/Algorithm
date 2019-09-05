#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void printVec(vector<int> &n){
    for(int i=0; i<6; i++){
        cout << n[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec;
    vec.push_back(3);vec.push_back(7);vec.push_back(27);vec.push_back(5);vec.push_back(5);vec.push_back(9);

    cout << "vec : ";
    printVec(vec);
    // for(int i=0;i<vec.size();i++)
    //     cout << vec[i] << " ";
    // cout << endl;

    cout << "sort(ascending): ";
    sort(vec.begin(),vec.end()); // default->Ascending
    printVec(vec);

    bool aFind = binary_search(vec.begin(),vec.end(),7);
    if(aFind)
        cout << "binary_search : there is 7 in vec" << endl;
    else
        cout << "no" <<endl;
    
    cout << "sort(decending): ";
    sort(vec.begin(),vec.end(),greater<int>()); 
    printVec(vec);

    bool bFind = binary_search(vec.begin(),vec.end(),7);
    if(bFind)
        cout << "binary_search : there is 7 in vec" << endl;
    else
        cout << "no" <<endl;
    
    return 0;
}

/*
    binary_search -> used when you want to find a value quickly under the assumption that is sorted\
*/
