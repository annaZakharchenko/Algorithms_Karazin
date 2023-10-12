#include <iostream>
#include <string>

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
    string Name;
    Position position;
    int Age;
    int GamesPlayed;
    int GoalsScored;
    FootballPlayer* next;

    FootballPlayer(const string& name, Position pos, int age, int gamesPlayed, int goalsScored)
        : Name(name), position(pos), Age(age), GamesPlayed(gamesPlayed), GoalsScored(goalsScored), next(nullptr) {}
};

FootballPlayer CreateNewPlayer()
{
    string name;
    int position, age, gamesPlayed, goalsScored;

    cout << "Name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Position (1 - Goalkeeper, 2 - Defender, 3 - Midfielder, 4 - Forward): ";
    cin >> position;

    cout << "Age: ";
    cin >> age;

    cout << "Games Played: ";
    cin >> gamesPlayed;

    cout << "Goals Scored: ";
    cin >> goalsScored;

    Position pos = static_cast<Position>(position);
    FootballPlayer newPlayer(name, pos, age, gamesPlayed, goalsScored);
    return newPlayer;
}

void AddPlayer(FootballPlayer*& first, FootballPlayer*& last, const string& name, Position posit, int age, int gamesPlayed, int goalsScored)
{
    FootballPlayer* newPlayer = new FootballPlayer(name, posit, age, gamesPlayed, goalsScored);
    if (first == NULL)
    {
        first = newPlayer;
        last = newPlayer;
    }
    else
    {
        last->next = newPlayer;
        last = newPlayer;
    }
}

void ShowPlayer(const FootballPlayer* player)
{
    cout << "Name: " << player->Name << "\nPosition: ";
    switch (player->position)
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
    cout << "\nAge: " << player->Age << "\nGames Played: " << player->GamesPlayed << "\nGoals Scored: " << player->GoalsScored << endl;
}

void ShowAllPlayers(const FootballPlayer* first)
{
    if (first == NULL)
    {
        cout << "No players in the team." << endl;
        return;
    }

    FootballPlayer* current = const_cast<FootballPlayer*>(first);
    int index = 1;

    while (current)
    {
        cout << index << ". ";
        ShowPlayer(current);
        current = current->next;
        index++;
    }
}

void RemovePlayer(FootballPlayer*& first, int index)
{
    if (index < 1)
    {
        cout << "Invalid index." << endl;
        return;
    }

    if (first == NULL)
    {
        cout << "No players in the team." << endl;
        return;
    }

    if (index == 1)
    {
        FootballPlayer* temp = first;
        first = first->next;
        delete temp;
        return;
    }

    FootballPlayer* prev = nullptr;
    FootballPlayer* current = first;
    int currentIndex = 1;

    while (current && currentIndex < index)
    {
        prev = current;
        current = current->next;
        currentIndex++;
    }

    if (current == NULL)
    {
        cout << "Invalid index." << endl;
        return;
    }

    prev->next = current->next;
    delete current;
}

FootballPlayer* FindBestForward(const FootballPlayer* first)
{
    if (first == NULL)
    {
        cout << "No players in the team." << endl;
        return nullptr;
    }

    FootballPlayer* bestForward = nullptr;
    int maxGoals = 0;

    FootballPlayer* current = const_cast<FootballPlayer*>(first);
    while (current)
    {
        if (current->position == Forward && current->GoalsScored >= maxGoals)
        {
            bestForward = current;
            maxGoals = current->GoalsScored;
        }
        current = current->next;
    }

    if (!bestForward)
    {
        cout << "No forwards in the team." << endl;
    }

    return bestForward;
}

void ShowPlayersWithLessThanFiveGames(const FootballPlayer* first)
{
    if (!first)
    {
        cout << "No players in the team." << endl;
        return;
    }

    FootballPlayer* current = const_cast<FootballPlayer*>(first);
    int index = 1;

    while (current)
    {
        if (current->GamesPlayed < 5)
        {
            cout << index << ". ";
            ShowPlayer(current);
        }
        current = current->next;
        index++;
    }
}

int main()
{
    FootballPlayer* first = nullptr;
    FootballPlayer* last = nullptr;

    int choice;
    while (true)
    {
        cout << "1. Add a new player" << endl;
        cout << "2. Show all players" << endl;
        cout << "3. Remove a player" << endl;
        cout << "4. Find the best forward and display their information" << endl;
        cout << "5. Show players with less than 5 games played" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int numPlayersToAdd;
            cout << "Enter the number of players you want to add: ";
            cin >> numPlayersToAdd;

            for (int i = 0; i < numPlayersToAdd; i++)
            {
                FootballPlayer newPlayer = CreateNewPlayer();
                AddPlayer(first, last, newPlayer.Name, newPlayer.position, newPlayer.Age, newPlayer.GamesPlayed, newPlayer.GoalsScored);
            }
            break;
        }
        case 2:
            ShowAllPlayers(first);
            break;
        case 3:
        {
            int index;
            cout << "Enter the index of the player to remove: ";
            cin >> index;
            RemovePlayer(first, index);
            break;
        }
        case 4:
        {
            FootballPlayer* bestForward = FindBestForward(first);
            if (bestForward)
            {
                cout << "Best Forward:" << endl;
                ShowPlayer(bestForward);
            }
            break;
        }
        case 5:
            ShowPlayersWithLessThanFiveGames(first);
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please select an existing option." << endl;
            break;
        }
    }

    return 0;
}
