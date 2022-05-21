#ifndef EX3_HEALTH_POINTS
#define EX3_HEALTH_POINTS

#include <iostream>


class HealthPoints
{
public:
    HealthPoints(int maxHP = 100);
    HealthPoints(const HealthPoints& other) = default;
    HealthPoints& operator=(const HealthPoints& other) = default;

    HealthPoints& operator+=(int hp);
    HealthPoints& operator-=(int hp);
    operator int() const;

    bool operator==(const HealthPoints& right) const;
    bool operator!=(const HealthPoints& right) const;
    bool operator<=(const HealthPoints& right) const;
    bool operator>=(const HealthPoints& right) const;
    bool operator>(const HealthPoints& right) const;
    bool operator<(const HealthPoints& right) const;
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& hp);
    class InvalidArgument{};

private:
    int m_currentHP;
    int m_maxHP;
};

bool operator==(const HealthPoints& left, int right);
bool operator==(int left, const HealthPoints& right);
bool operator!=(const HealthPoints& left, int right);
bool operator!=(int left, const HealthPoints& right);
bool operator>=(const HealthPoints& left, int right);
bool operator>=(int left, const HealthPoints& right);
bool operator<=(const HealthPoints& left, int right);
bool operator<=(int left, const HealthPoints& right);
bool operator>(const HealthPoints& left, int right);
bool operator>(int left, const HealthPoints& right);
bool operator<(const HealthPoints& left, int right);
bool operator<(int left, const HealthPoints& right);
HealthPoints operator+(const HealthPoints& left, int right);
HealthPoints operator+(int left, const HealthPoints& right);
HealthPoints operator-(const HealthPoints& left, int right);
HealthPoints operator-(int left, const HealthPoints& right);


#endif // EX3_HEALTH_POINTS