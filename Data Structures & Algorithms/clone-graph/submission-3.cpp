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
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;  // Base case: Empty input

        // If node already cloned, return the clone
        if (cloned.find(node) != cloned.end())
            return cloned[node];

        // Create a new clone node with the same value
        Node* newNode = new Node(node->val);

        // Store the cloned node in the map
        cloned[node] = newNode;

        // Recursively clone all neighbors
        for (auto neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return newNode;
    }
};
