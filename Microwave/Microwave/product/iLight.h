#ifndef ILIGHT_H
#define ILIGHT_H

class iLight
{
public:
    virtual ~iLight() {};

    virtual void LightOn() = 0;
    virtual void LightOff() = 0;
};

#endif
