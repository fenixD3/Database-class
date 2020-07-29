#include "database.h"
#include <algorithm>

void Database::Add(const Date& date, const string& event)
{
	auto& [set, vector] = db[date];
	if (!set.count(event))
	{
		set.insert(event);
		vector.push_back(set.find(event));
	}
}

ostream& Database::Print(ostream& out) const
{
	for(const auto& item : db)
		for(set<string>::const_iterator event : item.second.second)
			out << item.first << " " << *event << endl;
	return out;
}

string Database::Last(const Date& date) const
{
	auto l_date = db.upper_bound(date); // map<Date, pair<set<string>, vector<set<string>::const_iterator>>>::const_iterator
	if (l_date == db.begin())
		throw invalid_argument("No entries");
	else
		l_date = prev(l_date);
    stringstream ss;
    ss << l_date->first << ' ' << *l_date->second.second.back();
    return ss.str();
}
