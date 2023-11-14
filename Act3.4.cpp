// =========================================================
// File: Act3.4.cpp
// Author: Iram Kim Pichardo - A01710231
// Date: 03/11/2023
// =========================================================

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char * argv[]){
    int n;
    cin >> n;

    int list[n];

    //crear lista con n elementos O(n)
    for (int i = 0; i < n-1; i++) {
        cin >> list[i];
    }
    
    //crear mapa 
    map<int, vector<int>> mp;
    
    //insertar elementos al mapa O(n)
    for (int i = 0; i < n-1; i++) {
        mp[list[i]].push_back(i+2);
    }
    
    //eliminar elementos del mapa O(n)
    for (auto it = mp.rbegin(); it != mp.rend(); ++it) {
        if (!it->second.empty()) {
            for (auto it2 = mp.begin(); it2 != mp.end(); ++it2) {
                it2->second.erase(std::remove(it2->second.begin(), it2->second.end(), it->first), it2->second.end());
            }
        }
    }


    //determinar si "Si" o "No" es un abeto O(n)
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        if (it->second.size() < 3) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}

    //Complejidad del programa O(n^3)