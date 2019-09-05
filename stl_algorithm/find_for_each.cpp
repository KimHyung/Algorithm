//find, for_each
#include <iostream>
#include <algorithm>
#include <vector>
#include <boost/foreach.hpp>

void update(int &n){
    n+=10;
}

int main(){
    std::vector<int> vec;
    std::vector<int>::iterator pos;
    vec.push_back(4);vec.push_back(8);vec.push_back(15);vec.push_back(3);

    for(int i=0; i<vec.size(); i++){
        std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;
    
    std::cout << "find 8: "; 
    pos = find(vec.begin(), vec.end(), 8);
    if(pos != vec.end())
        std::cout<<"here" << std::endl;
    
    std::cout << "for_each ";
    for_each(vec.begin(), vec.end(), update);
    for(int i=0; i<vec.size(); i++){
        std::cout << vec[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}