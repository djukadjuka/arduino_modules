#if !defined(__BASE_MODULE_H)
#define __BASE_MODULE_H

class BaseModule{

public:
    BaseModule(){};

    virtual void init_pins() = 0;

    virtual void reset() = 0;
};

#endif // __BASE_MODULE_H
