#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
 
using namespace std;
 
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int playerCount; // the amount of players (always 2)
    int myId; // my player ID (0 or 1)
    int zoneCount; // the amount of zones on the map
    int linkCount; // the amount of links between all zones
    cin >> playerCount >> myId >> zoneCount >> linkCount;
    int platinumSource[zoneCount];
    for (int i = 0; i < zoneCount; i++) {
        int zoneId; // this zone's ID (between 0 and zoneCount-1)
        cin >> zoneId;
        cin >> platinumSource[zoneId];
    }
    
    vector <int> adjacentZone[zoneCount];
    for (int i = 0; i < linkCount; i++) {
        int zone1;
        int zone2;
        cin >> zone1 >> zone2;
        adjacentZone[zone1].push_back(zone2);
        adjacentZone[zone2].push_back(zone1);
    }
 
    int ownerId[zoneCount];
    int podsP0[zoneCount];
    int podsP1[zoneCount];
    bool visible[zoneCount];
    int myPlatinum;
    int prio[zoneCount];
    // game loop
    while (1) {
        cin >> myPlatinum; 
        //queue <int> prioQueue;
        for (int i = 0; i < zoneCount; i++) {
            int zId; // this zone's ID
            cin >> zId;
            cin >> ownerId[zId] >> podsP0[zId] >> podsP1[zId] >> visible[zId] >> platinumSource[zId]; cin.ignore();
 
        }
 
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
 
        // first line for movement commands, second line no longer used (see the protocol in the statement for details)
        for (int i = 0; i < zoneCount; ++i) {
            if (((myId == 0 && podsP0[i] != 0) || (myId == 1 && podsP1[i] != 0))) {
                int next = adjacentZone[i][0];
                if (myId == 0) cout << podsP0[i];
                else cout << podsP1[i];
                cout << ' ' << i << ' ' << next << ' ';
            }
        }
        cout << endl;
        cout << "WAIT" << endl;
    }
}
