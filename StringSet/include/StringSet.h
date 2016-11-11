#ifndef STRINGSET_H
#define STRINGSET_H

#include <iostream>
#include <vector>

using namespace std;


class StringSet
{
    public:
        StringSet();
        ~StringSet();
        string at(int i) const;
        int size();
        void insert(string word);
        friend std::ostream& operator << (ostream& os, StringSet& ba);
        friend StringSet operator + (StringSet& setOne, StringSet& setTwo);
        friend StringSet operator * (StringSet& setOne, StringSet& setTwo);
        bool find(string word);

    private:
        vector<string> Set;

};

#endif // STRINGSET_H
