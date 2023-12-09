#include"Header.h"

ShortestPath::ShortestPath(int size) : SIZE(size)
{
    am.resize(SIZE, std::vector<int>(SIZE, 0));
    d.resize(SIZE, std::numeric_limits<int>::max());
    v.resize(SIZE, 1);
}

void ShortestPath::initializeGraph()
{
    for (int i = 0; i < SIZE; i++) 
    {
        am[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) 
        {
            std::cout << "Enter the distance between " << i + 1 << " and " << j + 1 << ": ";
            std::cin >> am[i][j];
            am[j][i] = am[i][j];
        }
    }
}

void ShortestPath::printGraph() const
{
    for (int i = 0; i < SIZE; i++) 
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << std::setw(3) << am[i][j];
        }
        std::cout << std::endl;
    }
}

void ShortestPath::dijkstraAlgorithm(int beginIndex)
{
    int minindex;
    d[beginIndex] = 0;

    do 
    {
        minindex = findMinIndex();
        if (minindex != -1) 
        {
            for (int i = 0; i < SIZE; i++)
            {
                if (am[minindex][i] > 0) 
                {
                    int temp = d[minindex] + am[minindex][i];
                    if (temp < d[i])
                    {
                        d[i] = temp;
                    }
                }
            }
            v[minindex] = 0;
        }
    } while (minindex != -1);
}

void ShortestPath::printShortestDistances() const 
{
    std::cout << "\nShortest distances to vertices: \n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << std::setw(5) << d[i];
    }
}

void ShortestPath::findShortestPath(int beginIndex, int endIndex) const
{
    std::vector<int> ver;
    ver.push_back(endIndex + 1);
    int end = endIndex;
    int k = 1;
    int weight = d[end];

    while (end != beginIndex)
    {
        for (int i = 0; i < SIZE; i++) 
        {
            if (am[i][end] != 0)
            {
                int temp = weight - am[i][end];
                if (temp == d[i])
                {
                    weight = temp;
                    end = i;
                    ver.push_back(i + 1);
                    k++;
                }
            }
        }
    }

    std::cout << "\nShortest path:\n";
    for (int i = k - 1; i >= 0; i--)
    {
        std::cout << std::setw(3) << ver[i];
    }
}

int ShortestPath::findMinIndex() const 
{
    int minindex = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::max();

    for (int i = 0; i < SIZE; i++) 
    {
        if (v[i] == 1 && d[i] < min) 
        {
            min = d[i];
            minindex = i;
        }
    }

    return (minindex == std::numeric_limits<int>::max()) ? -1 : minindex;
}