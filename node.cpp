#include "node.h"

bool EmptyNode::Evaluate(const Date &date, const string &event)
{
	return true;
}

DateComparisonNode::DateComparisonNode(const Comparison& cmp, const Date& date)
	: _cmp(cmp)
	, _date(date)
{}

bool DateComparisonNode::Evaluate(const Date &date, const string &event)
{
	if (_cmp == Comparison::Less)
		return date < _date;
	else if (_cmp == Comparison::LessOrEqual)
		return date <= _date;
	else if (_cmp == Comparison::Greater)
		return date > _date;
	else if (_cmp == Comparison::GreaterOrEqual)
		return date >= _date;
	else if (_cmp == Comparison::Equal)
		return date == _date;
	else if (_cmp == Comparison::NotEqual)
		return date != _date;
}

EventComparisonNode::EventComparisonNode(const Comparison& cmp, const string& event)
	: _cmp(cmp)
	, _event(event)
{}

bool EventComparisonNode::Evaluate(const Date &date, const string &event)
{
	if (_cmp == Comparison::Less)
		return event < _event;
	else if (_cmp == Comparison::LessOrEqual)
		return event <= _event;
	else if (_cmp == Comparison::Greater)
		return event > _event;
	else if (_cmp == Comparison::GreaterOrEqual)
		return event >= _event;
	else if (_cmp == Comparison::Equal)
		return event == _event;
	else if (_cmp == Comparison::NotEqual)
		return event != _event;
}

LogicalOperationNode::LogicalOperationNode(const LogicalOperation& logic_op, shared_ptr<Node> left, shared_ptr<Node> right)
	: _logic_op(logic_op)
	, _left(left)
	, _right(right)
{}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event)
{
	if (_logic_op == LogicalOperation::Or)
		return _left->Evaluate(date, event) || _right->Evaluate(date, event);
	else if (_logic_op == LogicalOperation::And)
		return _left->Evaluate(date, event) && _right->Evaluate(date, event);
}
