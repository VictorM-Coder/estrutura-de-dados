#include <iostream>
#include <queue>

using namespace std;

int main() {
    char teamName[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
    queue<char> teams;
    for(int cont = 0; cont < 16; cont++){
        teams.push(teamName[cont]);
    }

    for (int cont = 1; cont < 16; cont++) {
        int golsTeam1, golsTeam2;
        char winner;
        cin >> golsTeam1;
        cin >> golsTeam2;

        if (golsTeam1 > golsTeam2){
            winner = teams.front();
            teams.pop();
            teams.pop();
        }else{
            teams.pop();
            winner = teams.front();
            teams.pop();
        }

        teams.push(winner);
    }

    cout << teams.front() << endl;

    return 0;
}

