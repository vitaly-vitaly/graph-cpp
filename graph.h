#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int success_graph = 0;
const int badsize_graph = 1;
const int malloc_graph = 2;
const int empty_graph = 3;
const int error_graph = 4;

class graph {
private:
	int size;
	vector < vector<int> > matrix;
	int * buf;
public:
	graph();
	graph(int val);
	~graph();
	void destroy_graph();
	void add_edge(int vertex1, int vertex2);
	void add_edges(int* vertices, int size);
	void print_graph();
	void print_buf();
	void dfs(int root); // помещает в буфер 1, если путь существует, -1 в противном случае
	void dfs_visit(int v);
	void bfs(int root); // помещает в буфер длину наименьшего пути для каждой вершины, если пути не существует, то выводим -1
};