#ifndef CONFIGURATIONORIGINATOR_HPP
#define CONFIGURATIONORIGINATOR_HPP


#include "ConfigurationMemento.hpp"
#include <bits/stdc++.h>
using namespace std;


class ConfigurationOriginator{
    int height;
    int width;

    public:
        ConfigurationOriginator(int height,int width)
        {
            this->height = height;
            this->width = width;
        }

        int getHeight()
        {
            return height;
        }

        void setHeight(int height)
        {
            this->height = height;
        }

        int getWidth()
        {
            return width;
        }

        void setWidth(int width)
        {
            this->width = width;
        }

        ConfigurationMemento* createMemento()
        {
            return new ConfigurationMemento(this->height,this->width);
        }

        void restoreMemento(ConfigurationMemento* mementoToBeRestored)
        {
            this->height = mementoToBeRestored->getHeight();
            this->width = mementoToBeRestored->getWidth();
        }
};


#endif