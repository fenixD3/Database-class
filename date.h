#pragma once

#include <iostream>
#include <cstdint>
#include <tuple>

using namespace std;

class Date
{
public:
	Date(const uint16_t& n_year, const uint16_t &n_month, const uint16_t &n_day);
	uint16_t GetYear() const;
	uint16_t GetMonth() const;
	uint16_t GetDay() const;

private:
	const uint16_t		year;
	const uint16_t		month, day;
};

Date		ParseDate(istream& is);
ostream&	operator<<(ostream& out, const Date& date);
void		SkipSymbol(istream& is);
bool		operator<(const Date& lhs, const Date& rhs);
bool		operator<=(const Date& lhs, const Date& rhs);
bool		operator>(const Date& lhs, const Date& rhs);
bool		operator>=(const Date& lhs, const Date& rhs);
bool		operator==(const Date& lhs, const Date& rhs);
bool		operator!=(const Date& lhs, const Date& rhs);