#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Compare function for priority queue
struct compare {
    bool operator()(Node* left, Node* right) {
        return left->freq > right->freq;
    }
};

// Traverse the Huffman Tree and store Huffman Codes in a map
void encode(Node* root, string str, unordered_map<char, string> &huffmanCode) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Traverse the Huffman Tree and decode the encoded string
void decode(Node* root, int &index, string str) {
    if (!root) return;

    // Leaf node
    if (!root->left && !root->right) {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

// Builds the Huffman Tree and decodes the given input text
void buildHuffmanTree(string text) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue to store live nodes of Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate until the size of queue becomes 1
    while (pq.size() != 1) {
        // Remove the two nodes of the highest priority (lowest frequency)
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies.
        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        // Add the new node to the priority queue
        pq.push(sum);
    }

    // Root of the Huffman Tree
    Node* root = pq.top();

    // Traverse the Huffman Tree and store Huffman Codes
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << "\n";
    }

    cout << "\nOriginal string:\n" << text << "\n";

    // Encode the input text
    string str = "";
    for (char ch : text) {
        str += huffmanCode[ch];
    }

    cout << "\nEncoded string:\n" << str << "\n";

    // Decode the encoded string
    int index = -1;
    cout << "\nDecoded string:\n";
    while (index < (int)str.size() - 2) {
        decode(root, index, str);
    }
    cout << endl;
}

int main() {
    string text;
    getline(cin, text);
    buildHuffmanTree(text);
    return 0;
}
// huffman coding is a data compression algorithm