#include <bits/stdc++.h>
using namespace std;

enum ItemType
{
    COKE,
    PEPSI,
    JUICE,
    SODA
};

enum Coin
{
    PENNY = 1,
    NICKEL = 5,
    DIME = 10,
    QUARTER = 25
};

class Item
{
public:
    ItemType type;
    int price;

    ItemType getType()
    {
        return type;
    }

    void setType(ItemType type)
    {
        this->type = type;
    }

    int getPrice()
    {
        return price;
    }

    void setPrice(int price)
    {
        this->price = price;
    }
};

class ItemShelf
{
public:
    int code;
    Item *item;
    bool soldOut;

    int getCode()
    {
        return code;
    }

    void setCode(int code)
    {
        this->code = code;
    }

    Item *getItem()
    {
        return item;
    }

    void setItem(Item *item)
    {
        this->item = item;
    }

    bool isSoldOut()
    {
        return soldOut;
    }

    void setSoldOut(bool soldOut)
    {
        this->soldOut = soldOut;
    }
};

class Inventory
{
public:
    vector<ItemShelf *> inventory;

    Inventory(int itemCount)
    {
        inventory = vector<ItemShelf *>(itemCount);
        initialEmptyInventory();
    }

    vector<ItemShelf *> getInventory()
    {
        return inventory;
    }

    void initialEmptyInventory()
    {
        int startCode = 101;

        for (int i = 0; i < inventory.size(); i++)
        {
            ItemShelf *space = new ItemShelf();
            space->setCode(startCode++);
            space->setSoldOut(true);
            inventory[i] = space;
        }
    }

    void addItem(Item *item, int codeNumber) throw(exception)
    {
        for (auto shelf : inventory)
        {
            if (shelf->getCode() == codeNumber)
            {
                if (shelf->isSoldOut())
                {
                    shelf->item = item;
                    shelf->setSoldOut(false);
                }
                else
                {
                    throw("already item is present, you can not add item here");
                }
            }
        }
    }

    Item *getItem(int codeNumber) throw(exception)
    {
        for (auto shelf : inventory)
        {
            if (shelf->code == codeNumber)
            {
                if (shelf->isSoldOut())
                {
                    throw("item is sold out");
                }
                else
                {
                    return shelf->item;
                }
            }
        }

        throw("invalid code number");
    }

    void updateSoldOutItem(int codeNumber)
    {
        for (auto shelf : inventory)
        {
            if (shelf->code == codeNumber) // Fixed: = to == (comparison instead of assignment)
            {
                shelf->setSoldOut(true);
            }
        }
    }
};

// Forward declaration of classes
class State;
class VendingMachine;
class IdleState;
class HasMoneyState;
class SelectionState;
class DispenseState;

class VendingMachine
{
    State *vendingMachineState; // Fixed typo: vendinMachingState to vendingMachineState
    Inventory *inventory;
    list<Coin> coinList;

public:
    VendingMachine(); // Declaration only, defined after State class

    State *getVendingMachineState();
    void setVendingMachineState(State *state);

    Inventory *getInventory()
    {
        return inventory;
    }

    void setInventory(Inventory *inventory)
    {
        this->inventory = inventory;
    }

    list<Coin>& getCoinList()
    {
        return coinList;
    }

    void setCoinList(list<Coin> coinList)
    {
        this->coinList = coinList;
    }
};

class State
{
public:
    virtual void clickInsertCoinButton(VendingMachine *machine) throw(exception) = 0;
    virtual void clickOnStartProductSelectionButton(VendingMachine *machine) throw(exception) = 0;
    virtual void insertCoin(VendingMachine *machine, Coin coin) throw(exception) = 0;
    virtual void chooseProduct(VendingMachine *machine, int codenumber) throw(exception) = 0;
    virtual int getChange(int returnChangeMoney) throw(exception) = 0;
    virtual Item *dispenseProduct(VendingMachine *machine, int codeNumber) throw(exception) = 0;
    virtual list<Coin> refundFullMoney(VendingMachine *machine) throw(exception) = 0;
    virtual void updateInventory(VendingMachine *machine, Item *item, int codeNumber) throw(exception) = 0;
    virtual ~State() {} // Add virtual destructor for polymorphic class
};

class IdleState : public State
{
public:
    IdleState()
    {
        cout << "Currently Vending machine is in Idle State" << endl;
    }

    IdleState(VendingMachine *machine)
    {
        cout << "Currently Vending machine is in Idle State" << endl;
    }

    void clickInsertCoinButton(VendingMachine *machine) throw(exception) override; // Forward declaration
    void clickOnStartProductSelectionButton(VendingMachine *machine) throw(exception) override
    {
        throw("first you need to click on insert coin button");
    }

    void insertCoin(VendingMachine *machine, Coin coin) throw(exception) override
    {
        throw("you can not insert coin in idle state");
    }

    void chooseProduct(VendingMachine *machine, int codenumber) throw(exception) override
    {
        throw("you can not choose product in idle state");
    }

    int getChange(int returnChangeMoney) throw(exception) override
    {
        throw("you can not get change in idle state");
    }

    list<Coin> refundFullMoney(VendingMachine *machine) throw(exception) override
    {
        throw("you can not refund full money in idle state");
    }

    Item *dispenseProduct(VendingMachine *machine, int codeNumber) throw(exception) override
    {
        throw("you can not dispense product in idle state");
    }

    void updateInventory(VendingMachine *machine, Item *item, int codeNumber) throw(exception) override
    {
        machine->getInventory()->addItem(item, codeNumber);
    }
};

class HasMoneyState : public State
{
public:
    HasMoneyState()
    {
        cout << "Currently Vending machine is in HasMoney State" << endl;
    }

    void clickInsertCoinButton(VendingMachine *machine) throw(exception) override
    {
        return;
    }

    void clickOnStartProductSelectionButton(VendingMachine *machine) throw(exception) override; // Forward declaration

    void insertCoin(VendingMachine *machine, Coin coin) throw(exception) override
    {
        cout << "Accepted the coin" << endl;
        machine->getCoinList().push_back(coin);
    }

    void chooseProduct(VendingMachine *machine, int codenumber) throw(exception) override
    {
        throw("you need to click on start product selection button");
    }

    int getChange(int returnChangeMoney) throw(exception) override
    {
        throw("you can not get change in has money state");
    }

    list<Coin> refundFullMoney(VendingMachine *machine) throw(exception) override; // Forward declaration

    Item *dispenseProduct(VendingMachine *machine, int codeNumber) throw(exception) override
    {
        throw("you can not dispense product in has money state");
    }

    void updateInventory(VendingMachine *machine, Item *item, int codeNumber) throw(exception) override
    {
        throw("you can not update inventory in has money state");
    }
};

class SelectionState : public State
{
public:
    SelectionState()
    {
        cout << "Currently Vending machine is in Selection State" << endl;
    }

    void clickInsertCoinButton(VendingMachine *machine) throw(exception) override
    {
        throw("you can not insert coin in selection state");
    }

    void clickOnStartProductSelectionButton(VendingMachine *machine) throw(exception) override
    {
        return;
    }

    void insertCoin(VendingMachine *machine, Coin coin) throw(exception) override
    {
        throw("you can not insert coin in selection state");
    }

    void chooseProduct(VendingMachine *machine, int codenumber) throw(exception) override; // Forward declaration

    int getChange(int returnChangeMoney) throw(exception) override
    {
        cout << "Returning the change in the Coin Dispense Tray" << returnChangeMoney << endl;
        return returnChangeMoney;
    }

    list<Coin> refundFullMoney(VendingMachine *machine) throw(exception) override; // Forward declaration

    Item *dispenseProduct(VendingMachine *machine, int codeNumber) throw(exception) override
    {
        throw("you can not dispense product in selection state");
    }

    void updateInventory(VendingMachine *machine, Item *item, int codeNumber) throw(exception) override
    {
        throw("you can not update inventory in selection state");
    }
};

class DispenseState : public State
{
public:
    DispenseState(VendingMachine *machine, int codeNumber) throw(exception); // Forward declaration

    void clickInsertCoinButton(VendingMachine *machine) throw(exception) override
    {
        throw("you can not insert coin in dispense state");
    }

    void clickOnStartProductSelectionButton(VendingMachine *machine) throw(exception) override
    {
        throw("you can not click on start product selection button in dispense state");
    }

    void insertCoin(VendingMachine *machine, Coin coin) throw(exception) override
    {
        throw("you can not insert coin in dispense state");
    }

    void chooseProduct(VendingMachine *machine, int codenumber) throw(exception) override
    {
        throw("you can not choose product in dispense state");
    }

    int getChange(int returnChangeMoney) throw(exception) override
    {
        throw("you can not get change in dispense state");
    }

    list<Coin> refundFullMoney(VendingMachine *machine) throw(exception) override
    {
        throw("you can not refund full money in dispense state");
    }

    Item *dispenseProduct(VendingMachine *machine, int codeNumber) throw(exception) override; // Forward declaration

    void updateInventory(VendingMachine *machine, Item *item, int codeNumber) throw(exception) override
    {
        throw("you can not update inventory in dispense state");
    }
};

// Now that all classes are declared, implement the constructor and methods that had circular dependencies

// VendingMachine constructor implementation
VendingMachine::VendingMachine()
{
    vendingMachineState = new IdleState(this);
    inventory = new Inventory(10);
    coinList = list<Coin>();
}

State *VendingMachine::getVendingMachineState()
{
    return vendingMachineState;
}

void VendingMachine::setVendingMachineState(State *state)
{
    this->vendingMachineState = state;
}

// Implementation of methods that use other classes
void IdleState::clickInsertCoinButton(VendingMachine *machine) throw(exception)
{
    machine->setVendingMachineState(new HasMoneyState());
}

void HasMoneyState::clickOnStartProductSelectionButton(VendingMachine *machine) throw(exception)
{
    machine->setVendingMachineState(new SelectionState());
}

list<Coin> HasMoneyState::refundFullMoney(VendingMachine *machine) throw(exception)
{
    cout << "Returning the full amount back in the Coin Dispense Tray" << endl;
    machine->setVendingMachineState(new IdleState(machine));
    return machine->getCoinList();
}

void SelectionState::chooseProduct(VendingMachine *machine, int codenumber) throw(exception)
{
    Item *item = machine->getInventory()->getItem(codenumber);

    int paidByUser = 0;
    for (auto coin : machine->getCoinList())
    {
        paidByUser += coin;
    }

    if (paidByUser < item->getPrice())
    {
        cout << "Insufficient Amount, Product you selected is for price : " << item->getPrice() << " and you have paid : " << paidByUser << endl;
        refundFullMoney(machine);
        throw("Insufficient Amount");
    }
    else if (paidByUser >= item->getPrice())
    {
        if (paidByUser > item->getPrice())
        {
            getChange(paidByUser - item->getPrice());
        }

        machine->setVendingMachineState(new DispenseState(machine, codenumber));
    }
}

list<Coin> SelectionState::refundFullMoney(VendingMachine *machine) throw(exception)
{
    cout << "Returning the full amount back in the Coin Dispense Tray" << endl;
    machine->setVendingMachineState(new IdleState(machine));
    return machine->getCoinList();
}

DispenseState::DispenseState(VendingMachine *machine, int codeNumber) throw(exception)
{
    cout << "Currently Vending machine is in Dispense State" << endl;
    dispenseProduct(machine, codeNumber);
}

Item *DispenseState::dispenseProduct(VendingMachine *machine, int codeNumber) throw(exception)
{
    cout << "Product Dispensed Successfully" << endl;
    Item *item = machine->getInventory()->getItem(codeNumber);
    machine->getInventory()->updateSoldOutItem(codeNumber); // Mark the item as sold out
    machine->setVendingMachineState(new IdleState(machine));
    return item;
}

void fillUpInventory(VendingMachine *machine)
{
    vector<ItemShelf *> slots = machine->getInventory()->getInventory();

    for (int i = 0; i < slots.size(); i++)
    {
        Item *newItem = new Item();
        if (i >= 0 && i < 3)
        {
            newItem->setType(ItemType::COKE);
            newItem->setPrice(12);
        }
        else if (i >= 3 && i < 5)
        {
            newItem->setType(ItemType::PEPSI);
            newItem->setPrice(9);
        }
        else if (i >= 5 && i < 7)
        {
            newItem->setType(ItemType::JUICE);
            newItem->setPrice(13);
        }
        else if (i >= 7 && i < 10)
        {
            newItem->setType(ItemType::SODA);
            newItem->setPrice(7);
        }

        slots[i]->setItem(newItem);
        slots[i]->setSoldOut(false);
    }
}

void displayInventory(VendingMachine *machine)
{
    vector<ItemShelf *> slots = machine->getInventory()->getInventory();
    for (int i = 0; i < slots.size(); i++)
    {
        cout << "CodeNumber: " << slots[i]->getCode() << " Item: " << slots[i]->getItem()->getType() << " Price: " << slots[i]->getItem()->getPrice() << " isAvailable: " << !slots[i]->isSoldOut() << endl;
    }
}

int main()
{
    VendingMachine *machine = new VendingMachine();
    try
    {
        cout << "|";
        cout << "filling up the inventory"; // Fixed typo: invetory to inventory
        cout << "|";

        fillUpInventory(machine);
        displayInventory(machine);

        cout << "|";
        cout << "clicking on InsertCoinButton";
        cout << "|";

        State *vendingState = machine->getVendingMachineState();
        vendingState->clickInsertCoinButton(machine);

        vendingState = machine->getVendingMachineState();
        vendingState->insertCoin(machine, Coin::NICKEL);
        vendingState->insertCoin(machine, Coin::QUARTER);

        cout << "|";
        cout << "clicking on ProductSelectionButton";
        cout << "|";
        vendingState->clickOnStartProductSelectionButton(machine);

        vendingState = machine->getVendingMachineState();
        vendingState->chooseProduct(machine, 102);

        displayInventory(machine);

        // Clean up memory
        delete machine;
    }
    catch (const char *msg)
    {
        std::cerr << "Exception: " << msg << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }

    return 0;
}