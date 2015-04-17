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
	

	// fprintf(stdout, "Test dfs #1 ");
	// dfs(gr, 3, &err);
	// (err == GR_SUCCESS) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test dfs #1 ");
	// dfs(gr, 0, &err);
	// (err == GR_SUCCESS) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test dfs #2 ");
	// dfs(NULL, 3, &err);
	// (err == GR_EMPTY) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test dfs #3 ");
	// dfs(gr, -1, &err);
	// (err == GR_BADSIZE) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test print_buf #1 ");
	// print_buf(gr, &err);
	// (err == GR_SUCCESS) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test print_buf #2 ");
	// print_buf(NULL, &err);
	// (err == GR_EMPTY) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test bfs #1 ");
	// bfs(gr, 0, &err);
	// (err == GR_SUCCESS) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test bfs #2 ");
	// bfs(NULL, 3, &err);
	// (err == GR_EMPTY) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test bfs #3 ");
	// bfs(gr, -1, &err);
	// (err == GR_BADSIZE) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test print_buf #1 ");
	// print_buf(gr, &err);
	// (err == GR_SUCCESS) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");



	// fprintf(stdout, "Test destroy_graph #1 ");
	// destroy_graph(NULL, &err);
	// (err == GR_EMPTY) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	// fprintf(stdout, "Test destroy_graph #2 ");
	// destroy_graph(gr, &err);
	// (err == GR_SUCCESS) ? fprintf(stdout, "PASSED\n") : fprintf(stdout, "FAILED\n");

	return 0;
}