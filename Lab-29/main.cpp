#include <iostream>
#include <map>
#include <array>
#include <list>
#include <string>
#include <fstream>

using namespace std;

using ZoneData = array<list<string>, 3>;

// Function to read data from file
void loadData(map<string, ZoneData>& ecoMap, string fileName) {
    ifstream inFile(fileName);
    
    if (!inFile) {
        cout << "Error: Cannot open " << fileName << endl;
        return;
    }
    string zone, tree, animal, weather;
    while (inFile >> zone >> tree >> animal >> weather) {
        ecoMap[zone][0].push_back(tree);
        ecoMap[zone][1].push_back(animal);
        ecoMap[zone][2].push_back(weather);
    }
    
    inFile.close();
    cout << "Data successfully loaded from " << fileName << "!\n\n";
}


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

    map<string, ZoneData> myForest;

    ZoneData northWoods;
    northWoods[0].push_back("Pine");
    northWoods[0].push_back("Oak");
    northWoods[1].push_back("Deer");
    northWoods[1].push_back("Bear");
    northWoods[2].push_back("Sunny");
    
    myForest["North Woods"] = northWoods;

    cout << "=== INITIAL ENVIRONMENT STATE ===" << endl;
    displayMap(myForest);

    // Begin a time-based simulation for environmental changes
    int timePeriods = 25;
    
    cout << "\n=== STARTING SIMULATION ===" << endl;
    for (int time = 1; time <= timePeriods; time++) {// For each time period, simulate changes
            
        // Print basic update to show time passing
        if (time == 1 || time == timePeriods) {
            cout << "Simulating time period " << time << "..." << endl;
        }
    }

    // Print the final state of the environment
    cout << "\n=== FINAL ENVIRONMENT STATE ===" << endl;

    return 0;

}