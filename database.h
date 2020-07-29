#pragma once

#include "date.h"
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <algorithm>

class Database
{
public:
	void Add(const Date& date, const string& event);
	ostream& Print(ostream& cout) const;

	template <typename Func>
	int RemoveIf(Func func)
	{
		int		deleted = 0;
		for (auto& rec : db)
			for (auto event = rec.second.second.begin(); event != rec.second.second.end(); )
			{
				if (func(rec.first, **event))
				{
					vector<set<string>::const_iterator>
						&vec = rec.second.second;
					rec.second.first.erase(**event);
					event = vec.erase(find(vec.begin(), vec.end(), *event));
					++deleted;
				}
				else
					event = next(event);
			}
		for (auto item = db.begin(); item != db.end();)
		{
			if (item->second.first.empty())
				item = db.erase(item);
			else
				item = next(item);
		}
		return deleted;
	}

	template <typename Func>
	vector<string> FindIf(Func func) const
	{
		vector<string> events;
		for (const auto& rec : db)
			for (auto event : rec.second.second)
				if (func(rec.first, *event))
				{
					stringstream find_stream;
					find_stream << rec.first << ' ' << *event;
					string ev;
					getline(find_stream, ev);
					events.push_back(ev);
				}
		return events;
	}

	string Last(const Date& date) const;
private:
	map<Date, pair<set<string>, vector<set<string>::const_iterator>>> db;
};

template <typename T, typename U>
ostream& operator<<(ostream& out, const pair<T, U>& p)
{
	out << p.first << ' ' << p.second;
	return out;
}
