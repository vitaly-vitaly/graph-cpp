const int success_graph = 0;
const int badsize_graph = 1;
const int malloc_graph = 2;
const int empty_graph = 3;
const int error_graph = 4;

class graph {
private:
	int size;
	int * matrix;
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
	void dfs(int root);
	void dfs_visit(int v, int times);
	void bfs(int root);
};