#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

void printVec(vector<int> &n,int size){
    for(int i=0; i<size; i++){
        cout << n[i] << " ";
    }
    cout << endl;
}

int main(){
    vector<int> vec, vec1, vec2;
    vec.push_back(3);vec.push_back(7);vec.push_back(27);vec.push_back(5);vec.push_back(5);vec.push_back(9);
    printVec(vec,vec.size());

    cout << "accumulate : " <<accumulate(vec.begin(), vec.end(), 0) << endl;
    for(int i=1; i<10; i++){
        vec2.push_back(i);vec1.push_back(i);
    }
    printVec(vec1,vec1.size());printVec(vec2,vec2.size());
    cout<< "inner_product:" << inner_product(vec1.begin(),vec1.end(),vec2.begin(), 0) << endl;
    return 0;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         c
