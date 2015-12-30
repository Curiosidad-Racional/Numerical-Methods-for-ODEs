#ifndef __rk4_h__
#define __rk4_h__

#include <vector>
#include <iostream>

template<class T>
class rk4 {
 private:
    unsigned int size;
    T h;
    T (**f)(T* x);
 public:
    std::vector<T*> x;

    rk4(T lap, T (**functions)(T* x), T* initials, unsigned int size);
    void iterate(unsigned int iters);
    ~rk4();

    T rk0(unsigned int i, T* x);
    T rk1(unsigned int i, T* x);
    T rk2(unsigned int i, T* x);
    T rk3(unsigned int i, T* x);
};

// Template implementation

template<class T>
rk4<T>::rk4(T lap, T (**functions)(T* x), T* initials, unsigned int size) {
    this->size = size;
    h = lap;
    f = functions;

    T* xx = new T[size];
    for (unsigned int i = 0; i < size; i++)
        xx[i] = initials[i];
    x.push_back(xx);
}

template<class T>
void rk4<T>::iterate(unsigned int iters) {
    T* x_;
    for (unsigned int i = 0; i < iters; i++) {
        T* xx = new T[size];

        x_ = x.back();
        xx[0] = x_[0] + h;
        for (unsigned int i = 1; i < size; i++)
            xx[i] = x_[i] + h/6*(rk0(i, x_) + 2*rk1(i, x_) + 2*rk2(i, x_) + rk3(i, x_));
        x.push_back(xx);
    }
}

template<class T>
rk4<T>::~rk4() {
    for(unsigned int i = 0; i < x.size(); i++)
        delete[] x[i];
    x.clear();
}

template<class T>
T rk4<T>::rk0(unsigned int i, T* x) {
    return f[i-1](x);
}

template<class T>
T rk4<T>::rk1(unsigned int i, T* x) {
    T result;
    T* xx = new T[size];
    
    xx[0] = x[0] + h/2;
    for (unsigned int i = 1; i < size; i++)
        xx[i] = x[i] + h/2*rk0(i, x);
    result = rk0(i, xx);

    delete[] xx;
    return result;
}

template<class T>
T rk4<T>::rk2(unsigned int i, T* x) {
    T result;
    T* xx = new T[size];
    
    xx[0] = x[0] + h/2;
    for (unsigned int i = 1; i < size; i++)
        xx[i] = x[i] + h/2*rk1(i, x);
    result = rk0(i, xx);

    delete[] xx;
    return result;
}

template<class T>
T rk4<T>::rk3(unsigned int i, T* x) {
    T result;
    T* xx = new T[size];
    
    xx[0] = x[0] + h;
    for (unsigned int i = 1; i < size; i++)
        xx[i] = x[i] + h*rk2(i, x);
    result = rk0(i, xx);

    delete[] xx;
    return result;
}


#endif
