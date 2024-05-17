#ifndef PlayGround_hpp
#define PlayGround_hpp

template<typename T>
class TemplateEx {
    
private:
    T a;
    T b;
    
public:
    TemplateEx(T a, T b):a(a), b(b) {}
    
    T GetA() {return a;}
    T GetB() {return b;}
    void SetA(T a) { this->a = a;}
    void SetB(T b) { this->b = b;}
    
    T Add();
    void Print();
    
    ~TemplateEx() {}
};
template<typename T>
T TemplateEx<T>::Add() {
    return this->a + this->b;
}


#endif /* PlayGround_hpp */
