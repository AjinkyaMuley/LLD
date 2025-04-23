#include "ConfigurationCareTaker.hpp"
#include "ConfigurationOriginator.hpp"
#include "ConfigurationMemento.hpp"
#include <bits/stdc++.h>
using namespace std;


int main()
{

    ConfigurationCareTaker* careTaker = new ConfigurationCareTaker();
    ConfigurationOriginator* originator = new ConfigurationOriginator(5,10);

    ConfigurationMemento* snapShot1 = originator->createMemento();
    careTaker->addMemento(snapShot1);
    
    originator->setHeight(7);
    originator->setHeight(12);

    ConfigurationMemento* snapShot2 = originator->createMemento();
    careTaker->addMemento(snapShot2);

    originator->setHeight(9);
    originator->setWidth(15);

    ConfigurationMemento* restoredStateMemento = careTaker->undo();
    originator->restoreMemento(restoredStateMemento);
    cout << "Height: " << originator->getHeight() << ", Width: " << originator->getWidth() << endl;

    return 0;
}