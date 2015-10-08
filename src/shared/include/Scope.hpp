#ifndef _SCOPE_HPP_
#define _SCOPE_HPP_

template <class T> class Scope {
public:
    Scope(T& obj) : obj(obj) {
        obj.scope_enter();
    }

    ~Scope() {
        obj.scope_leave();
    }

private:
    T& obj;
};

#endif