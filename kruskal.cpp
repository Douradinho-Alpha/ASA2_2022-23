#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int num_nodes, num_edges;

struct Edge {
	int node1, node2, weight;
};

bool compare_edges(Edge edge1, Edge edge2) {
	return edge1.weight > edge2.weight;
}

vector<int> parents;

int find_root(int node) {
	if (parents[node] == node)
		return node;
	return parents[node] = find_root(parents[node]);
}

void get_input(vector<Edge> &edges) {
	
	scanf("%d %d", &num_nodes, &num_edges);
	int node1, node2, weight;

	for (int i = 1; i <= num_edges; i++) {
		scanf("%d%d%d", &node1, &node2, &weight);
		Edge e;
		e.node1 = node1;
		e.node2 = node2;
		e.weight = weight;
		edges.push_back(e);
	}
}

int kruskal_dings(vector<Edge> edges) {
	sort(edges.begin(), edges.end(), compare_edges);

	parents.resize(num_nodes + 1);
	for (int i = 1; i <= num_nodes; i++) parents[i] = i;

	int num_edges_in_tree = 0;
	int result = 0;
	int node1, node2, weight;
	int root_node1, root_node2;
	for (int i = 0; i < num_edges; i++) {
		
		node1 = edges[i].node1,
		node2 = edges[i].node2,
		weight = edges[i].weight;

		root_node1 = find_root(node1),
		root_node2 = find_root(node2);
		
		if (root_node1 != root_node2) {
			parents[root_node1] = root_node2;
			num_edges_in_tree++;
			result += weight;
			if (num_edges_in_tree == num_nodes - 1)
				break;
		}
	}

	return result;
}

int main() {
	vector<Edge> edges;
	get_input(edges);

	int result = kruskal_dings(edges);
	printf("%d\n", result);

	return 0;
}
