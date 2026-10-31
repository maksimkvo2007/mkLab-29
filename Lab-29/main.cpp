#include <iostream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <fstream>

using namespace std;

using ZoneData = array<list<string>, 3>;

// Function to print the map data neatly
void displayMap(map<string, ZoneData>& ecoMap) {
    // Loop through every zone in the map
    for (auto const& pair : ecoMap) {
        cout << "Zone: " << pair.first << endl;
        
        // Print Trees
        cout << "  Trees: ";
        for (string tree : pair.second[0]) {
            cout << tree << ", ";
        }
        cout << endl;

        // Print Animals
        cout << "  Animals: ";
        for (string animal : pair.second[1]) {
            cout << animal << ", ";
        }
        cout << endl;
        cout << "-----------------------\n";
    }
}

int main(){
    
}