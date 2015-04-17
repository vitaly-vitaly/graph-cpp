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
	matrix = new int[val * val];
	buf = new int[val];
	size = val;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) matrix[i * size + j] = 0;
		buf[i] = 0;
	}
	return;
}

graph::graph() {
	graph(10);
}

graph::~graph() {
	delete [] matrix;
	delete [] buf;
}

void graph::add_edge(int vertex1, int vertex2) {
	if((vertex1 < 0) || (vertex1 >= size) || (vertex2 < 0) || (vertex2 >= size)) {
		throw badsize_graph;
		return;
	}
	matrix[vertex1 * size + vertex2] = 1;
	return;
}

void graph::add_edges(int* vertices, int val) {
	for(int i = 0; i < size; i++) {
		add_edge(*(vertices + i * 2), *(vertices + i * 2 + 1));
	}
	return;
}

void graph::print_graph() {
	int i, j;
	fprintf(stdout, "\n");
	for(i = 0; i < size; i++) {
		for(j = 0; j < size; j++){
			fprintf(stdout, "%d ", matrix[i * size + j]);
		}
		fprintf(stdout, "\n");
	}
	return;	
}

void graph::print_buf() {	
	fprintf(stdout, "\n");
	int i;
	for(i = 0; i < size; i++) {
		fprintf(stdout, "%d ", buf[i]);
	}
	fprintf(stdout, "\n");
	return;	
}

// void dfs(graph *graph, int root, GRERR *err) {
// 	if(graph == NULL) {
// 		if(err != NULL) *err = GR_EMPTY;
// 		return;
// 	}
// 	if(root < 0 || root >= graph->size) {
// 		if(err != NULL) *err = GR_BADSIZE;
// 		return;
// 	}

// 	int i;
// 	for(i = 0; i < graph->size; i++) {
// 		if(i != root) {
// 			graph->buf[i] = -1;
// 		}
// 	}

// 	graph->buf[root] = 2;
// 	dfs_visit(graph, root, 0);
// 	if(err != NULL) *err = GR_SUCCESS;
// 	return;	
// }

// void dfs_visit(graph *graph, int v, int times) {
// 	int i;
// 	graph->buf[v] = 2;
// 	for(i = 0; i < graph->size; i++) {
// 		if(graph->matrix[v][i] > 0 && graph->buf[i] == -1) {
// 			dfs_visit(graph, i, times+1);
// 		}
// 	}
// 	graph->buf[v] = 1;
// }

// void bfs(graph *graph, int root, GRERR *err) {
// 	if(graph == NULL) {
// 		if(err != NULL) *err = GR_EMPTY;
// 		return;
// 	}
// 	if(root < 0 || root >= graph->size) {
// 		if(err != NULL) *err = GR_BADSIZE;
// 		return;
// 	}

// 	int *color;
// 	if((color = (int *) calloc(graph->size, sizeof(int))) < 0) {
// 		if(err != NULL) *err = GR_MALLOC;
// 		return;
// 	}
// 	int *q;
// 	if((q = (int *) calloc(graph->size, sizeof(int))) < 0) {
// 		if(err != NULL) *err = GR_MALLOC;
// 		return;
// 	}
// 	int qstart = 0, qend = 0;

// 	int i;
// 	for(i = 0; i < graph->size; i++) {
// 		graph->buf[i] = -1;
// 		color[i] = WHITE;
// 	}

// 	graph->buf[root] = 0;
// 	color[root] = GRAY;

// 	q[qend++] = root;

// 	while(qstart != qend) {
// 		int u = q[qstart++];
// 		int v;
// 		for(v = 0; v < graph->size; v++) {
// 			if(graph->matrix[u][v] > 0 && u != v) {
// 				if(color[v] == WHITE) {
// 					color[v] = GRAY;
// 					graph->buf[v] = graph->buf[u] + 1;
// 					q[qend++] = v;
// 				}
// 			}
// 		}
// 		color[u] = BLACK;
// 	}

// 	free(color);
// 	free(q);

// 	if(err != NULL) *err = GR_SUCCESS;
// 	return;	
// }