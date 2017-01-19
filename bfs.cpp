#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <limits.h>

using namespace std;
const int edge_distance = 1;
typedef unordered_map<char, list<char> >  AdjList;
typedef unordered_map<char, int> Dist;
typedef unordered_map<char, char> Parent;

AdjList adjList;
Dist dist;
Parent pnt;
const vector<char> nodes = { 'a', 'b', 'c', 'd', 'e', 'f' };

void bfs(const char& start)
{
    vector<char>::const_iterator iter = nodes.begin();
    while(iter != nodes.end())
    {
	dist[*iter] = INT_MAX;
	++iter;
    }

    // starting dist as zero
    dist[start] = 0;

    queue<char> que;
    que.push(start);

    while(!que.empty())
    {
	char elem = que.front();
	que.pop();

	// check for the adjacent nodes
	list<char>& adj = adjList[elem];
	list<char>::iterator iter = adj.begin();
	while(iter != adj.end())
	{
	    if (dist[*iter] > dist[elem] + edge_distance)
	    {
		// update dist for adjacent node and push it on priority queue
		dist[*iter] = dist[elem] + edge_distance;
		que.push(*iter);
		pnt[*iter] = elem;
	    }
	    ++iter;
	}
    }
}

int main()
{
    adjList['a'] = {'b', 'f'};
    adjList['b'] = {'c', 'f'};
    adjList['c'] = {'d', 'e'};
    adjList['f'] = {'b', 'c'};
    adjList['e'] = {'f', 'd'};

    bfs('a');
    
    
    Dist::iterator iter = dist.begin();
    while(iter != dist.end())
    {
	cout << iter->first << " : " << iter->second << endl;
	++iter;
    }

    Parent::iterator pIter = pnt.begin();
    while(pIter != pnt.end())
    {
	cout << "Parent of " << pIter->first << " : " << pIter->second << endl;
	++pIter;
    }
}
