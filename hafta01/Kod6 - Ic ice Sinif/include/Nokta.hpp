#ifndef Nokta_hpp
#define Nokta_hpp
class Nokta
{
public:
    Nokta(int x,int y);
    Nokta();
    int X();
    int Y();
    void setX(int x);
    void setY(int y);
private:
    int m_X;
    int m_Y;
};
#endif