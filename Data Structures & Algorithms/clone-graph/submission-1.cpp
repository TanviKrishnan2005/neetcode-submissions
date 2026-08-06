/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    Node* cloneGraph(Node* node) {

        // Maps original node -> cloned node
        // Used to:
        // 1. Avoid cloning the same node multiple times
        // 2. Prevent infinite recursion in cyclic graphs
        map<Node*, Node*> oldToNew;

        // Start DFS cloning
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldToNew) {

        // Base case
        // Empty graph
        if (node == nullptr) {
            return nullptr;
        }

        // If this node has already been cloned,
        // return the existing copy.
        // Prevents infinite loops in graphs with cycles.
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        // Create a copy of the current node
        Node* copy = new Node(node->val);

        // Store mapping:
        // Original node -> Cloned node
        oldToNew[node] = copy;

        // Clone all neighbours recursively
        for (Node* nei : node->neighbors) {

            // dfs(nei) returns the cloned neighbour
            // Add it to the neighbour list of the cloned node
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }

        // Return the cloned node
        return copy;
    }
};