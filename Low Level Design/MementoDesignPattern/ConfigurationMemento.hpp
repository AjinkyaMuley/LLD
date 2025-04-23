#ifndef CONFIGURATIONMEMENTO_HPP
#define CONFIGURATIONMEMENTO_HPP


class ConfigurationMemento{
    int height;
    int width;

    public:
        ConfigurationMemento(int height, int width)
        {
            this->height = height;
            this->width = width;
        }

        int getHeight()
        {
            return height;
        }

        int getWidth()
        {
            return width;
        }
};


#endif