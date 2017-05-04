/*
Adrian Borrego

Data Structures COP4530
Cutpoints Project: graph.cpp
*/

#include "graph.h"
#include <cassert>
#include <stack>

//Constructor
graph::graph()
{
  int vertex;
  cin >> size;
  adjList.resize(size,NULL);
  for(int i = 0; i < size; ++i) {
    cin >> vertex;
    while(vertex != -1) {
      adjList[i] = new vnode(vertex,adjList[i]); // insert at begining
      cin >> vertex;
    }
  }
}

//Function returns the first false index.
int firstFalse(vector<bool> b)
{
  int i = 0;
  while(i < b.size() && b[i])
    i += 1;
  return i;
}

//Function checks if the entire vector of vertices are true.
bool all(vector<bool> b)
{
  for(int i = 0; i < b.size(); ++i)
    if(!b[i])
      return false;
  return true;
}

//Depth First Search Function.
void graph::dfs(vector<bool> &visited)
{
  int start = firstFalse(visited);
  int nbr, current = start;
  stack<int> S;
  vnodeptr cursor;
  visited[start] = true;
  S.push(start);
  //Loop will run until the stack of vertices is empty.
  while(!S.empty())
  {
	//Assigning value at the top of list to current.
    current = S.top();
	//Loop will run through the adjacency list of the current viewed vertex.
    for(cursor = adjList[current]; cursor != NULL; cursor = cursor->next)
	{
	  nbr = cursor->vertex;
	  //Checking if the vertex has already been visited.
	  if(!visited[nbr])
	  {
		//If vertex has not been visited, push into stack.
	    S.push(nbr);
		//Mark the vertex as visited.
	    visited[nbr] = true;
	    break;
	  }
	}
	//Check if all vertices were already visited prior to function call.
    if(cursor == NULL)
	{
	  S.pop();
	}
  }
}

//Function determines if a graph is connected.
bool graph::connected(int excluded = -1)
{
  vector<bool> visited(size,false);
  if(excluded != -1)
  {
    visited[excluded] = true;
  }
  dfs(visited);
  return all(visited);

}

//Function will find and return the cutpoints of the graph.
vector<int> graph::get_cutpoints()
{
  vector<int> cutpts;
  for(int i = 0; i < size; i++)
  {
    if(!connected(i))
	{
	  cutpts.push_back(i);
	}
  }
  return cutpts;
}
