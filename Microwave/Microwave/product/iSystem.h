#ifndef ISYSTEM_H
#define ISYSTEM_H

class iSystem
{
public:
    virtual ~iSystem() {};

    virtual void SetTimer(int ms) = 0;
};

#endif
