#include "HealthPoints.h"

HealthPoints::HealthPoints(int maxHP) : m_currentHP(maxHP), m_maxHP(maxHP)
{
    if (maxHP <= 0)
    {
        throw InvalidArgument();
    }
}

HealthPoints& HealthPoints::operator+=(int hp)
{
    m_currentHP += hp;
    if (m_currentHP > m_maxHP)
    {
        m_currentHP = m_maxHP;
    }
    
    if (m_currentHP < 0)
    {
        m_currentHP = 0;
    }
    
    return *this;
}

HealthPoints::operator int() const
{
    return m_currentHP;
}


HealthPoints& HealthPoints::operator-=(int hp)
{
    *this += -hp;
    return *this;
}

bool HealthPoints::operator==(const HealthPoints& right) const
{
    return (m_currentHP == right.m_currentHP);
}

bool HealthPoints::operator!=(const HealthPoints& right) const
{
    return (m_currentHP != right.m_currentHP);
}

bool HealthPoints::operator>=(const HealthPoints& right) const
{
    return (m_currentHP >= right.m_currentHP);
}

bool HealthPoints::operator<=(const HealthPoints& right) const
{
    return (m_currentHP <= right.m_currentHP);
}

bool HealthPoints::operator>(const HealthPoints& right) const
{
    return (m_currentHP > right.m_currentHP);
}

bool HealthPoints::operator<(const HealthPoints& right) const
{
    return (m_currentHP < right.m_currentHP);
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& hp)
{
    os << hp.m_currentHP << '(' << hp.m_maxHP << ')';
    return os;
}


HealthPoints operator+(const HealthPoints& left, int right)
{
    HealthPoints result(left);
    result += right;
    return result;
}

HealthPoints operator+(int left, const HealthPoints& right)
{
    return (right + left);
}

HealthPoints operator-(const HealthPoints& left, int right)
{
    HealthPoints result(left);
    result -= right;
    return result;
}

HealthPoints operator-(int left, const HealthPoints& right)
{
    return (right - left);
}

bool operator==(const HealthPoints& left, int right)
{
    return int(left) == right;
}

bool operator==(int left, const HealthPoints& right)
{
    return right == left;
}

bool operator!=(const HealthPoints& left, int right)
{
    return int(left) != right;
}

bool operator!=(int left, const HealthPoints& right)
{
    return right != left;
}

bool operator>=(const HealthPoints& left, int right)
{
    return int(left) >= right;
}

bool operator>=(int left, const HealthPoints& right)
{
    return right >= left;
}

bool operator<=(const HealthPoints& left, int right)
{
    return int(left) <= right;
}

bool operator<=(int left, const HealthPoints& right)
{
    return right <= left;
}

bool operator<(const HealthPoints& left, int right)
{
    return int(left) < right;
}

bool operator<(int left, const HealthPoints& right)
{
    return right < left;
}

bool operator>(const HealthPoints& left, int right)
{
    return int(left) > right;
}

bool operator>(int left, const HealthPoints& right)
{
    return right > left;
}
