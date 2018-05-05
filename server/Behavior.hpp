#pragma once

#include <map>

#include "types.hpp"

class Entity;

class Behavior
{
protected:
    Entity  *self_;
    bool    resolved_;

    NON_MOVABLE_OR_COPYABLE(Behavior);

protected:
    Behavior();

public:
    void setSelf(Entity *self);

public:
    virtual bool update(float delta, Env &env) = 0;
};

class Walk : public Behavior
{
private:
    float t_;

    NON_MOVABLE_OR_COPYABLE(Walk);

public:
    Walk();
    bool update(float delta, Env &env) override;
};

class AreaLimit: public Behavior
{
public:
    enum AreaType
    {
        Square,
        Circle,
    };

private:
    AreaType    areaType_;
    int         size_;

    NON_MOVABLE_OR_COPYABLE(AreaLimit);

public:
    AreaLimit(AreaType type, int size);
    bool update(float delta, Env &env) override;
};