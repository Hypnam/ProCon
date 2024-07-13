#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void print(const vector<vector<int>>& numlist) {
    for (int i = 0; i < numlist.size(); i++) {
        for (int j = 0; j < numlist[i].size(); j++) cout << numlist[i][j];
        cout << endl;
    }
    
    cout << endl;
}

int main(void){
    // Your code here!
    long long count = 0; //intだとoverflow
    
    string S;
    cin >> S;
    
    vector<vector<int>> numlist(S.size()+1, vector<int>(10));
    for (int i = 0; i < 10; i++) {
        numlist[0][i] = 0;
    }

    for (int i = 1; i <= S.size(); i++) {
        numlist[i] = numlist[i-1];
        numlist[i][S[i-1] - '0']++;
        numlist[i][S[i-1] - '0'] %= 2;
    }
    
    // こっちでは時間がかかりすぎる
    // int l, r;
    // 
    // for (l = 0; l <= S.size()-1; l++) {
    //     auto check = numlist[l];
    //     for(r = l+1; r <= S.size(); r++) {
    //         auto check2 = numlist[r];
    //         if (check == check2) count++;
    //     }
    // }
    
    map<vector<int>, int> freq;
    for (int i = 0; i <= S.size(); i++) {
        freq[numlist[i]]++;
    }
    
    for (const auto&[key, value]: freq) {
        count +=  1LL*value * (value-1) / 2; // 1LLがないとoverflow
    }
    
    cout << count << endl;
    
    return 0;
}
