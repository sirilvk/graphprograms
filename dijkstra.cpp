#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <list>
#include <limits.h>

using namespace std;
typedef pair<char, int> vPair;
class vPairGreater { public: bool operator() (const vPair& a, const vPair& b) { return a.second > b.second; } };
typedef priority_queue<vPair, vector<vPair>, vPairGreater> PriorityQueue;
typedef unordered_map<char, list<vPair> >  AdjList;
typedef unordered_map<char, int> Dist;
typedef unordered_map<char, char> Parent;

AdjList adjList;
Dist dist;
Parent pnt;
const vector<char> nodes = { 'a', 'b', 'c', 'd', 'e', 'f' };

void dijkstra(const char& start)
{
    vector<char>::const_iterator iter = nodes.begin();
    while(iter != nodes.end())
    {
	dist[*iter] = INT_MAX;
	++iter;
    }

    // starting dist as zero
    dist[start] = 0;

    PriorityQueue pq;
    pq.push({start, 0});

    while(!pq.empty())
    {
	vPair elem = pq.top();
	pq.pop();

	// check for the adjacent nodes
	list<vPair>& adj = adjList[elem.first];
	list<vPair>::iterator iter = adj.begin();
	while(iter != adj.end())
	{
	    if (dist[iter->first] > dist[elem.first] + iter->second)
	    {
		// update dist for adjacent node and push it on priority queue
		dist[iter->first] = dist[elem.first] + iter->second;
		pq.push({iter->first, dist[iter->first]});
		pnt[iter->first] = elem.first;
	    }
	    ++iter;
	}
    }
}

int main()
{
    adjList['a'] = {{'b', 5}, {'f', 10}};
    adjList['b'] = {{'c', 1}, {'f', 4}};
    adjList['c'] = {{'d', 6}, {'e', 2}};
    adjList['f'] = {{'b', 3}, {'c', 7}};
    adjList['e'] = {{'f', 1}, {'d', 3}};

    dijkstra('a');
    
    
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
