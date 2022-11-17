#include<iostream>
using namespace std;

class Clock
{
    public:
        Clock(int hour=0,int minute=0,int second=0);
        void showTime() const;
        Clock operator - (Clock &c);
        Clock& operator ++ ();
        Clock operator ++ (int);
    private:
        int hour,minute,second;
} ;

Clock::Clock(int hour,int minute,int second)
{
    if (0 <= hour && hour <= 24 && 0 <= minute && minute <= 60 && 0 <= second && second <= 60)
    {
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    }   else
            cout << "Time error!" << endl;
}

void Clock::showTime() const {
    cout << hour << ":" << minute << ":" << second << endl;
}
Clock Clock::operator-(Clock &c)
{
    int t,t1,t2;
    t1=hour*3600+minute*60+second;
    t2=c.hour*3600+c.minute*60+c.second;
    t=abs(t1-t2);
    Clock cc(t/3600,t%3600/60,t%60);
    return cc;
}

Clock & Clock::operator++()
{
    second++;
    if (second>=60)
    {
        second-=60;
        minute++;
        if (minute>=60)
        {
            minute-=60;
            hour++;
            hour=(hour+1)%24;
        }
    }
    return *this;
}

Clock Clock::operator++ (int)
{
    Clock old = *this;
    ++(*this);
    return old;
}

int main()
{
    Clock c1(10,10,20),c2(21,30,15);
    (++c1).showTime();
    c1.showTime();
    (c2++).showTime();
    c2.showTime();
    (c1-c2).showTime();
    return 0;
}