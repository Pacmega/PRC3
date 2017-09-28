#ifndef IUSERINTERFACE_H
#define IUSERINTERFACE_H

class iUserInterface
{
public:
    virtual ~iUserInterface() {};

    virtual void Ping() const = 0;
    virtual int GetReqPower() const = 0;
    virtual void StartClock() = 0;
    virtual void StopClock() = 0;
};

#endif
