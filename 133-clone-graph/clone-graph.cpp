class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        unordered_map<Node*, Node*> visited;
        return dfs(node, visited);
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*>& visited) {
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // create a copy of current node
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;

        // explore neighbors
        for (auto neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(dfs(neighbor, visited));
        }

        return cloneNode;
    }
};
