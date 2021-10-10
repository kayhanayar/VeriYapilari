#include "Nokta.hpp"
Nokta::Nokta(int x,int y)
{
    m_X = x;
    m_Y = y;
}
Nokta::Nokta()
{

}
int Nokta::X()
{
    return m_X;
}
int Nokta::Y()
{
    return m_Y;
}
void Nokta::setX(int x)
{
    m_X = x;
}
void Nokta::setY(int y )
{
    m_Y = y;
}
