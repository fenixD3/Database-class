#include "date.h"
#include <stdexcept>
#include <string>
#include <iomanip>

Date::Date(const uint16_t& n_year, const uint16_t &n_month, const uint16_t &n_day)
	: year(n_year)
	, month(n_month)
	, day(n_day) {}

uint16_t	Date::GetYear() const
{
	return year;
}

uint16_t Date::GetMonth() const
{
	return month;
}

uint16_t Date::GetDay() const
{
	return day;
}

Date		ParseDate(istream& is)
{
	int16_t	year;
	int16_t	month, day;

	is >> year;
	if (year < 0 || year > 9999)
		throw invalid_argument("Wrong year: " + to_string(month));
	SkipSymbol(is);
	is >> month;
	if (month < 1 || month > 12)
		throw invalid_argument("Wrong month: " + to_string(month));
	SkipSymbol(is);
	is >> day;
	if (day < 1 || day > 31)
		throw invalid_argument("Wrong day: " + to_string(day));

	return Date(year, month, day);
}

void		SkipSymbol(istream& is)
{
	char d = is.peek();
	if (d == '-')
		is.ignore(1);
	else
	{
		string delim = {d};
		throw invalid_argument("Wrong delimetr: " + delim);
	}
}

ostream&	operator<<(ostream& out, const Date& date)
{
	out << setw(4) << setfill('0') << date.GetYear() << '-' << setw(2)
			<< setfill('0') << date.GetMonth() << '-' << setw(2) << setfill('0') << date.GetDay();
	return out;
}

bool		operator<(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) < make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool		operator<=(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) <= make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool		operator>(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) > make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool		operator>=(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) >= make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool		operator==(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) == make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}

bool		operator!=(const Date& lhs, const Date& rhs)
{
	return make_tuple(lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()) != make_tuple(rhs.GetYear(), rhs.GetMonth(), rhs.GetDay());
}
