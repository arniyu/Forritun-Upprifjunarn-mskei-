#include "StringSet.h"

StringSet::StringSet()
{
    //ctor
}

StringSet::~StringSet()
{
    //dtor
}

string StringSet::at(int i) const
{
  return Set.at(i);
}

int StringSet::size()
{
    return Set.size();
}

void StringSet::insert(string word)
{
    if(!find(word))
    {
        Set.push_back(word);
    }
}

bool StringSet::find(string word)
{
    for(int i = 0; i < Set.size(); i++)
    {
        if(Set.at(i) == word)
        {
            return true;
        }
    }
    return false;
}

ostream& operator << (ostream& os, StringSet& ba)
{
    for(int i = 0; i < ba.size(); i++)
    {
        cout << ba.at(i) << endl;
    }
    return os;
}

StringSet operator *(StringSet& setOne, StringSet& setTwo)
{
    StringSet out;
    for(int i = 0;  i < setOne.size(); i++)
    {
        for(int j = 0; j < setTwo.size(); j++)
        {
            if(setOne.at(i) == setTwo.at(j))
            {
                out.insert(setOne.at(i));
            }
        }
    }
    return out;
}

StringSet operator + (StringSet& setOne, StringSet& setTwo)
{
    StringSet out;

    for(int i = 0; i < setOne.size(); i++)
    {
        out.insert(setOne.at(i));
    }

    for(int i = 0; i < setTwo.size(); i++)
    {
        out.insert(setTwo.at(i));
    }

    return out;
}
