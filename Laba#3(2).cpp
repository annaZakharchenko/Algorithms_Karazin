void InsertBefore(FootballPlayer*& first, FootballPlayer*& last, int index, const string& name, Position posit, int age, int gamesPlayed, int goalsScored)
{
    FootballPlayer* newPlayer = new FootballPlayer(name, posit, age, gamesPlayed, goalsScored);

    if (index < 1)
    {
        cout << "Invalid index." << endl;
        //delete newPlayer; 
        return;
    }

    if (first == NULL)
    {
        cout << "No players in the team." << endl;
        return;
    }

    if (index == 1)
    {
        newPlayer->next = first;
        first = newPlayer;
        if (last == nullptr)
        {
            last = newPlayer;
        }
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

    if (currentIndex != index)
    {
        cout << "Invalid index." << endl;
        delete newPlayer;
        return;
    }

    prev->next = newPlayer;
    newPlayer->next = current;

    if (current == nullptr)
    {
        last = newPlayer;
    }
}

void InsertAfter(FootballPlayer*& first, FootballPlayer*& last, int index, const string& name, Position posit, int age, int gamesPlayed, int goalsScored)
{
    FootballPlayer* newPlayer = new FootballPlayer(name, posit, age, gamesPlayed, goalsScored);

    if (index < 0)
    {
        cout << "Invalid index." << endl;
        delete newPlayer; 
        return;
    }

    FootballPlayer* current = first;
    int currentIndex = 1;

    while (current && currentIndex < index)
    {
        current = current->next;
        currentIndex++;
    }

    if (currentIndex != index)
    {
        cout << "Invalid index." << endl;
        delete newPlayer;
        return;
    }

    newPlayer->next = current->next;
    current->next = newPlayer;

    if (current == nullptr)
    {
        last = newPlayer;
    }
}
