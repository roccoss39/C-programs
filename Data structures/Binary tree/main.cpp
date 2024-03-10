#include <iostream>

using namespace std;

struct Node
{
    int Value;
    static int RootsNum;
    
    Node *Left, *Right;
    
    int Find(Node *&Root, int Numb, int Counter);
    void AddRoot(Node *&Root, int Value);
    Node(int Val = 0) : Value(Val), Left(nullptr), Right(nullptr) {}
};

int Node::RootsNum = 0;

void Node::AddRoot(Node *&Root, int Value)
{
    RootsNum++;

    if (Root == nullptr)
    {
        Root = new Node(Value);
    }
    else if (Value < Root->Value)
    {
        AddRoot(Root->Left, Value);
    }
    else
    {
        AddRoot(Root->Right, Value);
    }
}

int Node::Find(Node *&Root, int Numb, int Counter)
{
    if (RootsNum == 0)
    {
        cout << "No existing Roots yet ";
        return 0;
    }

    if (Root == nullptr)
    {
        cout << "Not find" << endl;
        return -1;
    }
    else if (Numb == Root->Value)
        return Counter;
    else if (Root->Left != nullptr && Numb == Root->Left->Value)
    {
        cout << "\nHave found, Node nr:";
        return 2 * Counter;
    }
    else if (Root->Right != nullptr && Numb == Root->Right->Value)
    {
        cout << "\nHave found, Node nr:";
        return 2 * Counter + 1;
    }
    else if (Numb < Root->Value)
    {
        return Find(Root->Left, Numb, Counter *= 2);
    }
    else if (Numb > Root->Value)
    {

        return Find(Root->Right, Numb, Counter *= 2);
    }
    return 0;
}

void Commit(Node *&Root, Node Obiect);
void Display(Node *Root);
void Menu();
////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Node *Root = nullptr;
    Node Three;

    Menu();
    Commit(Root, Three);

    delete Root;
    return 0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(Node *Root)
{

    if (Root == nullptr)
        cout << "Empty tree" << endl;

    else if (Root->Right == nullptr && Root->Left == nullptr && Node::RootsNum == 1)
        cout << "Root value is:" << Root->Value << endl;

    else
    {
        if (Root->Right != nullptr || Root->Left != nullptr)
            cout << "Father's value:" << Root->Value << endl;

        if (Root->Left != nullptr)
            cout << "Left child has value:" << Root->Left->Value << endl;

        if (Root->Right != nullptr)
            cout << "Right child has value:" << Root->Right->Value << endl;
    }
    if (Root->Left != nullptr)
        Display(Root->Left);
    if (Root->Right != nullptr)
        Display(Root->Right);
}

void Menu()
{
    cout << "1. Add Root \n"
         << "2. Find node \n"
         << "3. Display tree relations \n"
         << "4. End \n";
}

void Commit(Node *&Root, Node Obiect)
{
    int Numb, a;

    do
    {
        cin >> a;
        switch (a)
        {
        case 1:
            cout << "Enter the value:";
            cin >> Numb;
            Obiect.AddRoot(Root, Numb);
            break;
        case 2:
            cout << "Searching node:";
            cin >> Numb;
            cout << Obiect.Find(Root, Numb, 1) << "\n";
            break;
        case 3:
            Display(Root);
            break;
        case 4:
            break;
        default:
            cin.clear();
            cin.ignore();
            cout << ("Choose properly!");
            break;
        };

    } while (a != 4);
}
