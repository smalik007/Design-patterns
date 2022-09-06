#pragma once

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class HTMLElemnt
{

    const size_t indent_ = 2;

public:
    string name_, text_;
    vector<HTMLElemnt> elements_;

    HTMLElemnt() {}
    HTMLElemnt(const string &name, const string &text) : name_(name), text_(text) {}

    string str(int indent = 0) const
    {
        ostringstream oss;
        string i(indent_ * indent, ' ');
        oss << i << "<" << name_ << ">" << endl;

        if (text_.size() > 0)
            oss << string(indent_ * (indent + 1), ' ') << text_ << endl;

        // recursive call to the this func
        for (const auto &e : elements_)
        {
            oss << e.str(indent + 1);
        }

        oss << i << "</" << name_ << ">" << endl;
        return oss.str();
    }
};

class HTMLBuilder
{
    HTMLElemnt root;

public:
    HTMLBuilder(const string &root_name)
    {
        root.name_ = root_name;
    }

    // void add_children(string child_name, string child_text)
    // {
    //     HTMLElemnt e{child_name, child_text};
    //     root.elements_.emplace_back(e);
    // }

    HTMLBuilder &add_children(string child_name, string child_text)
    {
        HTMLElemnt e{child_name, child_text};
        root.elements_.emplace_back(e);
        return *this;
    }

    string str() const
    {
        return root.str();
    }
};