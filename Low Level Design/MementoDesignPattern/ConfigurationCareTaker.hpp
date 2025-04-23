#ifndef CONFIGURATIONCARETAKER_HPP
#define CONFIGURATIONCARETAKER_HPP

#include "ConfigurationMemento.hpp"
#include <bits/stdc++.h>
using namespace std;


class ConfigurationCareTaker{
    vector<ConfigurationMemento*> history;

    public:
        ConfigurationCareTaker()
        {
            this->history = vector<ConfigurationMemento*>();
        }

        void addMemento(ConfigurationMemento* memento)
        {
            history.push_back(memento);
        }

        ConfigurationMemento* undo()
        {
            if(!history.empty())
            {
                ConfigurationMemento* lastMemento = history.back();
                history.pop_back();
                return lastMemento;
            }

            return NULL;
        }
};


#endif