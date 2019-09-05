#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct User{
    int id;
    int money;
};

struct SetUserInfo{
    SetUserInfo() { UserCount =100;}

    User operator() (){
        User user;
        ++UserCount;

        user.id = UserCount;
        user.money = 1000;
    }

    int UserCount;
};

int main(){
    vector<User> vec(5);
    vector<User> vec_copy;
    vector<User>::iterator removePos;

    //generate
    cout <<"generate: ";
    generate(vec.begin(), vec.end(), SetUserInfo());

    for(int i=0; i<vec.size(); i++)
        cout << vec[i].id << ", ";
    cout << endl;

    // //copy
    // cout <<"copy: ";
    // copy(vec.begin(),vec.end(),vec_copy);
    // vec_copy = vec;
    // for(int i=0; i<vec_copy.size(); i++)
    //     cout << vec_copy[i].id << ", ";
    // cout << endl;

    // //remove
    // cout <<"remove 101 user: ";
    // remove(vec_copy.begin()->id,vec_copy.end()->id,101);
    // for(int i=0; i<vec_copy.size(); i++)
    //     cout << vec_copy[i].id << ", ";
    // cout << endl;

    // //replace
    // cout <<"replace 102 to 999: ";
    // replace(vec_copy.begin()->id,vec_copy.end()->id,102,999);
    // for(int i=0; i<vec_copy.size(); i++)
    //     cout << vec_copy[i].id << ", ";
    // cout << endl;

    return 0;
}