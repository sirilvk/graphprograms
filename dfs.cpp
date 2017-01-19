#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <limits.h>

using namespace std;
const int edge_distance = 1;
typedef unordered_map<char, list<char> >  AdjList;
typedef unordered_map<char, bool> Visited;

AdjList adjList;
Visited Vt;
const vector<char> nodes = { 'a', 'b', 'c', 'd', 'e', 'f', 'h' };

void dfs(const char& start)
{
    Vt[start] = true;
    cout << start << endl;

    list<char>::iterator aIter = adjList[start].begin();
    while (aIter != adjList[start].end())
    {
	if (!Vt[*aIter])
	{
	    dfs(*aIter);
	}
	++aIter;
    }
}

int main()
{
    adjList['a'] = {'b', 'c'};
    adjList['b'] = {'d', 'e'};
    adjList['c'] = {'f', 'h'};

    dfs('a');
    
    vector<char>::const_iterator iter = nodes.begin();
    while(iter != nodes.end())
    {
	Vt[*iter++] = false;
    }
    
    dfs('a');
}
