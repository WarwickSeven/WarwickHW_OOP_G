#include <iostream>

class Date {
    int m_day;
    int m_month;
    int m_year;
public:
    void setDay(int d) {
        m_day = d;
    }
    void setMonth(int m) {
        m_month = m;
    }
    void setYear(int y) {
        m_year = y;
    }
    friend std::ostream& operator<<(std::ostream& os, Date& aDate);
};

std::ostream& operator<<(std::ostream& os, Date& aDate) {
    os << aDate.m_day << "." << aDate.m_month << "." << aDate.m_year;
    return os;
}

template <typename T>
class tPtr {
    T* p;
    int count;
public:
    tPtr(T* _p = nullptr) : p(_p) {
        count = 0;
    }
    
    tPtr(const tPtr& obj) {
        p = obj.p;
        count++;
    }
    tPtr operator=(const tPtr& obj) {
        p = obj.p;
        count++;
        return *this;
    }
    
    ~tPtr() {
        if ((p != nullptr) && (count == 0)) {
            std::cout << "Delete object" << std::endl;
            delete[] p;
        } else {
            std::cout << "Delete copy" << std::endl;
            count--;
        }
    }
    T* operator->() {
        return p;
    }
};

int main() {
    Date* nDate = new Date;
    tPtr<Date> today(nDate);
    today->setDay(21);
    today->setMonth(4);
    today->setYear(2022);
    
    std::cout << "Today is: " << *today << std::endl;
    
    return 0;
}


