#include <iostream>
#include <malloc.h>
#include "graph.h"

using namespace std;

#define WHITE 0
#define GRAY 1
#define BLACK 2

graph::graph(int val) {
	if(val <= 0) {
		throw badsize_graph;
		return;
	}
	matrix = vector< vector<int> > (val);
	buf = new int[val];
	size = val;
	return;
}

graph::graph() {
	graph(10);
}

graph::~graph() {
	delete [] buf;
}

void graph::add_edge(int vertex1, int vertex2) {
	if((vertex1 < 0) || (vertex1 >= size) || (vertex2 < 0) || (vertex2 >= size)) {
		throw badsize_graph;
		return;
	}
	matrix[vertex1].push_back(vertex2);
	return;
}

void graph::add_edges(int* vertices, int val) {
	for(int i = 0; i < size; i++) {
		add_edge(*(vertices + i * 2), *(vertices + i * 2 + 1));
	}
	return;
}

void graph::print_graph() {
	fprintf(stdout, "\n");
	for(int i = 0; i < size; i++) {
		fprintf(stdout, "%d: ", i);
		for(size_t j = 0; j < matrix[i].size(); j++){
			fprintf(stdout, "%d ", (int)j);
		}
		fprintf(stdout, "\n");
	}
	return;	
}

void graph::print_buf() {	
	fprintf(stdout, "\n");
	int i;
	fprintf(stdout, "buf: ");
	for(i = 0; i < size; i++) {
		fprintf(stdout, "%d ", buf[i]);
	}
	fprintf(stdout, "\n");
	return;	
}

void graph::dfs(int root) {
	if(root < 0 || root >= size) {
		throw badsize_graph;
		return;
	}
	for(int i = 0; i < size; i++) {
		if(i != root) {
			buf[i] = -1;
		}
	}
	dfs_visit(root);
}

void graph::dfs_visit(int v) {
	buf[v] = 1;
	for (vector<int>::iterator i = matrix[v].begin(); i != matrix[v].end(); ++i)
		if (buf[*i] == -1)
			dfs_visit (*i);

}

void graph::bfs(int root) {
	if(root < 0 || root >= size) {
		throw badsize_graph;
		return;
	}
	for(int i = 0; i < size; i++) {
		if(i != root) {
			buf[i] = -1;
		}
	}

	queue<int> q;
	q.push(root);
	vector<bool> used (size);
	used[root] = true;
	buf[root] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (size_t i = 0; i < matrix[v].size(); ++i) {
			int to = matrix[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				buf[to] = buf[v] + 1;
			}
		}
	}
}