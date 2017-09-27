#ifndef IMOTOR_H
#define IMOTOR_H

class iMotor
{
public:
    virtual ~iMotor() {};

    virtual void SetPower(int power) = 0;
};

#endif
