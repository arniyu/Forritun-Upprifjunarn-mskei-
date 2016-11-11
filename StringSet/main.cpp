#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include "StringSet.h"

using namespace std;


// The following functions are used
// within the main() function.
// You should implement those functions
// as well as the StringSet class.
void readFileKeywords(StringSet& setDocument, const char filename[]);
double similarity(StringSet& set1, StringSet& set2);


int main()
{
	StringSet doc1;
	StringSet doc2;
	StringSet theUnion;
	StringSet query;


    readFileKeywords(doc1, "doc1.txt");
    readFileKeywords(doc2, "doc2.txt");


    cout << "Doc1: " << doc1 << endl;
    cout << "Doc2: " << doc2 << endl;

    theUnion = doc1 + doc2;
    cout << "Union: " << theUnion << endl;


    readFileKeywords(query, "query.txt");
    cout << "Query: " << query << endl;


    int count = 0;
    for (unsigned int i = 0; i < query.size(); i++)
	{
        if (theUnion.find(query.at(i)))
		{
            count++;
		}
    }
    cout << "Query size: " << query.size() << endl;
    cout << "Found in union: " << count << endl;


    // Calculate similarity to each document
    double sim1 = similarity(doc1, query);
    cout << "Similarity to doc1: " << sim1 << endl;


    double sim2 = similarity(doc2, query);
    cout << "Similarity to doc2: " << sim2 << endl;

    return 0;
}



void readFileKeywords(StringSet& setDocument, const char filename[])
{
    ifstream file;
    file.open (filename);
    if (!file.is_open()) return;

    string word;
    while (file >> word)
    {
        setDocument.insert(word);
    }
    file.close();
}

double similarity(StringSet& set1,  StringSet& set2)
{
    StringSet intersection = set1 * set2;
    double sim = intersection.size() / (sqrt(set1.size()) * sqrt(set2.size()));

    return sim;
}
