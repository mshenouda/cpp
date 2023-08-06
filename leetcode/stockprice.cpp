#include "./stockprice.h"

stockprice::stockprice() {
}

void stockprice::update(int time, int price) {
    if(m.find(-time)!= m.end()) {
        s.erase({m[-time],-time});
    }
    m[-time]= price;
    s.insert({price,-time});
}   

int stockprice::current() {
    return m.begin()->second;
}

int stockprice::maximum() {
    return s.rbegin()->second;
}
int stockprice::minimum() {
    return s.begin()->second;
}
