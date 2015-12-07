#ifndef FACTORY_H
#define FACTORY_H

template <class T>
class Factory
{
public:
    virtual T create() = 0;
};

#endif // FACTORY_H
