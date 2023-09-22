#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <limits>

using namespace std;

enum Position
{
    Goalkeeper = 1,
    Defender,
    Midfielder,
    Forward
};

struct FootballPlayer
{
    char Name[64];
    Position position;
    int Age;
    int GamesPlayed;
    int GoalsScored;
};

struct Header
{
    int NumberPlayers;
};


void SavePlayersToFile(const FootballPlayer* players, int numPlayers, const string& footballers)
{
    ofstream file(footballers, ios::binary);
    if (!file)
    {
        cout << "Error.Cannot open file for writing." << endl;
        return;
    }
    Header header;
    header.NumberPlayers = numPlayers;
    file.write((char*)&header, sizeof(Header));

    for (int i = 0; i < numPlayers; ++i)
    {
        file.write(players[i].Name, sizeof(players[i].Name));
        file.write((char*)&players[i].position, sizeof(Position));
        file.write((char*)&players[i].Age, sizeof(int));
        file.write((char*)&players[i].GamesPlayed, sizeof(int));
        file.write((char*)&players[i].GoalsScored, sizeof(int));
    }

    cout << "Data saved to " << footballers << " successfully." << endl;
}

bool LoadPlayersFromFile(FootballPlayer*& players, int& numPlayers, const string& footballers)
{
    ifstream file(footballers, ios::binary);
    if (!file)
    {
        cout << "Error: Cannot open file for reading." << endl;
        return false;
    }
    Header header;
    file.read((char*)&header, sizeof(Header));
    numPlayers = header.NumberPlayers;

    players = new FootballPlayer[numPlayers];

    for (int i = 0; i < numPlayers; ++i)
    {
        file.read(players[i].Name, sizeof(players[i].Name));
        file.read((char*)&players[i].position, sizeof(Position));
        file.read((char*)&players[i].Age, sizeof(int));
        file.read((char*)&players[i].GamesPlayed, sizeof(int));
        file.read((char*)&players[i].GoalsScored, sizeof(int));
    }

    cout << "Data loaded from " << footballers << " successfully." << endl;
    return true;
}

void ShowAllPlayers(const FootballPlayer* players, int numPlayers)
{
    if (numPlayers == 0)
    {
        cout << "No players. Add players first." << endl;
        return;
    }

    cout << "All Players:" << endl;
    for (int i = 0; i < numPlayers; i++)
    {
        cout << i + 0 << ". ";
        cout << "Name: " << players[i].Name << "\nPosition: ";
        switch (players[i].position)
        {
        case Goalkeeper:
            cout << "Goalkeeper";
            break;
        case Defender:
            cout << "Defender";
            break;
        case Midfielder:
            cout << "Midfielder";
            break;
        case Forward:
            cout << "Forward";
            break;
        }
        cout << "\nAge: " << players[i].Age << "\nGames Played: " << players[i].GamesPlayed << "\nGoals Scored: " << players[i].GoalsScored << endl;
    }
}

FootballPlayer FindBestForward(const FootballPlayer* players, int numPlayers)
{
    FootballPlayer bestForward;
    bestForward.position = Forward;
    bestForward.GoalsScored = 0;

    bool hasForwards = false;

    for (int i = 0; i < numPlayers; ++i)
    {
        if (players[i].position == Forward)
        {
            hasForwards = true;
            if (players[i].GoalsScored > bestForward.GoalsScored)
            {
                bestForward = players[i];
            }
        }
    }
    if (!hasForwards)
    {
        strcpy_s(bestForward.Name, "No forwards in the team");
    }

    return bestForward;
}

void DisplayBestForward(const FootballPlayer& bestForward)
{
    cout << "Best Forward:" << endl;
    cout << "Name: " << bestForward.Name << "\nPosition: ";
    switch (bestForward.position)
    {
    case Goalkeeper:
        cout << "Goalkeeper";
        break;
    case Defender:
        cout << "Defender";
        break;
    case Midfielder:
        cout << "Midfielder";
        break;
    case Forward:
        cout << "Forward";
        break;
    }
    cout << "\nAge: " << bestForward.Age << "\nGoals Scored: " << bestForward.GoalsScored << endl;
}

void PrintPlayersWithLessThanFiveGames(const FootballPlayer* players, int numPlayers)
{
    cout << "Players who played fewer than 5 games:" << endl;
    bool found = false;
    for (int i = 0; i < numPlayers; ++i)
    {
        if (players[i].GamesPlayed < 5)
        {
            cout << "Name: " << players[i].Name << "\nPosition: ";
            switch (players[i].position)
            {
            case Goalkeeper:
                cout << "Goalkeeper";
                break;
            case Defender:
                cout << "Defender";
                break;
            case Midfielder:
                cout << "Midfielder";
                break;
            case Forward:
                cout << "Forward";
                break;
            }
            cout << "\nAge: " << players[i].Age << "\nGames Played: " << players[i].GamesPlayed << "\nGoals Scored: " << players[i].GoalsScored << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "There are no players who played fewer than 5 games" << endl;
    }
}

void RemovePlayerByIndex(FootballPlayer*& players, int& numPlayers, int index)
{
    if (numPlayers <= 0 || index < 0 || index >= numPlayers)
    {
        cout << "Invalid operation. No players to remove or invalid index." << endl;
        return;
    }

    for (int i = index; i < numPlayers - 1; ++i)
    {
        players[i] = players[i + 1];
    }
    numPlayers--;
    cout << "Player removed successfully." << endl;
}

void AddNewPlayer(FootballPlayer*& players, int& numPlayers)
{
    int newSize = numPlayers + 1;
    FootballPlayer* newPlayers = new FootballPlayer[newSize];

    for (int i = 0; i < numPlayers; ++i)
    {
        newPlayers[i] = players[i];
    }

    FootballPlayer newPlayer;
    cout << "Name: ";
    cin.ignore();
    cin.getline(newPlayer.Name, sizeof(newPlayer.Name));

    cout << "1 - Goalkeeper\n2 - Defender\n3 - Midfielder\n4 - Forward ";
    cout << "\nChoose the player's position: ";
    int positionChoice;
    cin >> positionChoice;
    if (positionChoice >= 1 && positionChoice <= 4)
    {
        switch (positionChoice)
        {
        case 1:
            newPlayer.position = Goalkeeper;
            break;
        case 2:
            newPlayer.position = Defender;
            break;
        case 3:
            newPlayer.position = Midfielder;
            break;
        case 4:
            newPlayer.position = Forward;
            break;
        }
    }
    else
    {
        cout << "Invalid position choice." << endl;
    }

    cout << "Age: ";
    cin >> newPlayer.Age;
    cout << "Number of games played: ";
    cin >> newPlayer.GamesPlayed;
    cout << "Number of goals scored: ";
    cin >> newPlayer.GoalsScored;

    newPlayers[numPlayers] = newPlayer;
    numPlayers = newSize;

    delete[] players;
    players = newPlayers;
}

int main()
{
    int numPlayers;
    FootballPlayer* players = nullptr;

    if (LoadPlayersFromFile(players, numPlayers, "players.bin"))
    {
        cout << "Data loaded successfully." << endl;
    }
    else
    {
        cout << "No data found. Starting with an empty player list." << endl;
        numPlayers = 0;
        players = nullptr;
    }

    int choice;
    while (true)
    {
        cout << "\nMenu:" << endl;
        cout << "1. Find the best forward and display their information" << endl;
        cout << "2. Display details of players who played fewer than 5 games" << endl;
        cout << "3. Add a new player" << endl;
        cout << "4. Remove a player" << endl;
        cout << "5. Show all players" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 1:
        {
            FootballPlayer bestForward = FindBestForward(players, numPlayers);
            DisplayBestForward(bestForward);
            break;
        }
        case 2:
            PrintPlayersWithLessThanFiveGames(players, numPlayers);
            break;
        case 3:
            AddNewPlayer(players, numPlayers);
            break;
        case 4:
            ShowAllPlayers(players, numPlayers);
            int index;
            cout << "Enter the index of the player to remove: ";
            cin >> index;
            RemovePlayerByIndex(players, numPlayers, index);
            break;
        case 5:
            ShowAllPlayers(players, numPlayers);
            break;
        case 6:
            SavePlayersToFile(players, numPlayers, "players.bin");
            delete[] players;
            return 0;
        default:
            cout << "Invalid choice. Please select an existing option." << endl;
            break;
        }
    }
    return 0;
}
