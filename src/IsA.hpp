#ifndef IS_A_H
#define IS_A_H

template< class T, class U >
bool isA(U* c){
    if( c == nullptr) return false;
    return c == dynamic_cast<T*>(c);
}

#endif // IS_A_H
