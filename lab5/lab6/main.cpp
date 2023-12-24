#include<iostream>
#include<list>
#include<stack>
#include<vector>

using namespace std;
class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};
class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
    //Heling functions

    void topoRecur(int v, vector<bool> &visited, stack<int> &st)
    {
      visited[v] = true;
      for(int i=0;i<adj[v].getSize();i++){
        int getItem=adj[v].getElement(i);
        if(!visited[getItem]) topoRecur(getItem,visited,st);
      }
      st.push(v);
    }
  void topologicalSort()
  {
    // TODO
    vector<bool> visited(V,false);
    stack<int> st;
    for(int i=0;i<V;i++){
      if(!visited[i]) topoRecur(i,visited,st);
    }
    while(!st.empty()){
      cout<<st.top()<<" ";
      st.pop();
    }
  }
};