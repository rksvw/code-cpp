#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
using namespace std;

#define MAX_LEVEL 6

// Node definition
template <typename T>
class SkipNode
{
public:
    T value;
    SkipNode<T> **forward;
    SkipNode(T val, int level)
    {
        value = val;
        forward = new SkipNode<T> *[level + 1];
        for (int i = 0; i <= level; i++)
        {
            forward[i] = nullptr;
        }
    }
};

// SkipList definition
template <typename T>
class SkipList
{
private:
    int level;
    SkipNode<T> *header;

public:
    SkipList()
    {
        level = 0;
        header = new SkipNode<T>(T(), MAX_LEVEL);
    }

    int randomLevel()
    {
        int lvl = 0;
        while (rand() % 2 && lvl < MAX_LEVEL)
            lvl++;
        return lvl;
    }

    void insert(T value)
    {
        SkipNode<T> *current = header;
        SkipNode<T> *update[MAX_LEVEL + 1];
        for (int i = level; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
            update[i] = current;
        }

        current = current->forward[0];

        if (current == nullptr || current->value != value)
        {
            int rlevel = randomLevel();
            if (rlevel > level)
            {
                for (int i = level + 1; i <= rlevel; i++)
                {
                    update[i] = header;
                }
                level = rlevel;
            }

            SkipNode<T> *newNode = new SkipNode<T>(value, rlevel);

            for (int i = 0; i <= rlevel; i++)
            {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }

            cout << "Inserted: " << value << "\n";
        }
    }

    bool search(T value)
    {
        SkipNode<T> *current = header;
        for (int i = level; i >= 0; i--)
        {
            while (current->forward[i] != nullptr && current->forward[i]->value < value)
                current = current->forward[i];
        }

        current = current->forward[0];

        return current != nullptr && current->value == value;
    }

    void display()
    {
        cout << "\nSkip List Levels:\n";
        for (int i = level; i >= 0; i--)
        {
            SkipNode<T> *node = header->forward[i];

            cout << "Level " << i << ": ";
            while (node != nullptr)
            {
                cout << node->value << " ";
                node = node->forward[i];
            }

            cout << "\n";
        }
    }
};

int main()
{
    srand(time(0)); // For random level generation
    SkipList<int> list;

    list.insert(3);
    list.insert(6);
    list.insert(7);
    list.insert(9);
    list.insert(12);
    list.insert(19);
    list.insert(17);
    list.insert(26);
    list.insert(30);

    list.display();

    return 0;
}
