class Functor {
        int val;
    public:
        Functor(int x): val(x) {};
        int operator()(int x) {
            return val * x;
        }
};


class MultiplyBy {
private:
    int factor;

public:
    MultiplyBy(int x) : factor(x) {
    }

    int operator () (int other) const {
        return factor * other;
    }
};

class Multiplier {  
    public:  
      Multiplier(int factor) : factor_(factor) {}  
      
      int operator()(int x) const {  
        return x * factor_;  
      }  
      
    private:  
      int factor_;  
    };  