#include <iostream>
#include "graph.h"
using namespace std;

int main(int argc, char const *argv[])
{
	int vertices[5][2] = {{0, 1}, {1, 0}, {1, 2}, {2, 0}, {1, 3}};
	graph * gr;

	try {
		gr = new graph(-4);
	} catch(int i) {
		if(i == badsize_graph) cout<<"graph bad size"<<endl;
	}

	gr = new graph(5);

	try {
		gr->add_edge(10, -1);
	} catch(int i) {
		if(i == badsize_graph) cout<<"uncorrect size"<<endl;
	}

	gr->add_edges(&vertices[0][0], 5);
	gr->print_graph();
	gr->print_buf();

	try {
		gr->bfs(-3);
	} catch(int i) {
		if(i == badsize_graph) cout<<"uncorrect size in bfs"<<endl;
	}
	gr->bfs(1);
	gr->print_buf();

	try {
		gr->dfs(-3);
	} catch(int i) {
		if(i == badsize_graph) cout<<"uncorrect size in dfs"<<endl;
	}
	gr->dfs(1);
	gr->print_buf();


	delete gr;
	return 0;
}