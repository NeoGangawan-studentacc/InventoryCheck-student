#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Item
{  
    public:
    string name;
    double price;
    Item(string name, double price)
    {
        this->name = name;
        this->price = price;
    }
};

class Store
{
    public:
    vector<Item> items;
    void addItem(string name, double price)
    {
        items.push_back(Item(name, price));
    }
    void storeInput()
    {
        int n;
        cout << "Enter the number of items: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string name;
            double price;
            cout << "Enter the name of the item: ";
            cin >> name;
            cout << "Enter the price of the item: ";
            cin >> price;
            addItem(name, price);
        }
    }
    void maxSort()
    {
        sort_heap(items.begin(), items.end(), [](Item a, Item b) { return a.price < b.price; });
        sort_heap(items.begin(), items.end(), [](Item a, Item b) { return a.price > b.price; });
    }
    void printItems()
    {
        for (Item item : items)
        {
            cout << item.name << ":" << " " << item.price << endl;
        }
    }
};

int main()
{
    Store store;
    store.storeInput();
    cout << endl;
    
    store.maxSort();
    store.printItems();
    return 0;
}