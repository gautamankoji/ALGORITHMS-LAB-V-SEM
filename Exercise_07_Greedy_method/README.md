# EX 07: Implement Huffman coding technique

Huffman coding is a popular algorithm for lossless data compression. It assigns variable-length codes to input characters, with shorter codes assigned to more frequent characters. Here's how the algorithm works:

### Steps in Huffman Coding

1. **Frequency Count**: Count the frequency of each character in the input.
2. **Build a Min-Heap**: Create a priority queue (min-heap) of nodes based on frequency.
3. **Build the Huffman Tree**:
   - While there is more than one node in the heap:
     - Extract the two nodes with the smallest frequencies.
     - Create a new internal node with these two nodes as children and the frequency equal to the sum of their frequencies.
     - Insert this new node back into the heap.
4. **Generate Codes**: Traverse the tree to generate binary codes for each character.
5. **Encoding**: Replace each character in the input with its corresponding binary code.
6. **Decoding**: Use the Huffman tree to decode the binary string back to the original characters.

### Code Implementation

Here's a C++ implementation of Huffman coding:

```cpp
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency) 
        : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void generateHuffmanCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = str;
    }
    generateHuffmanCodes(root->left, str + "0", huffmanCodes);
    generateHuffmanCodes(root->right, str + "1", huffmanCodes);
}

void huffmanCoding(const string& text) {
    unordered_map<char, int> frequency;
    for (char ch : text) {
        frequency[ch]++;
    }
    priority_queue<Node*, vector<Node*>, Compare> minHeap;
    for (const auto& pair : frequency) {
        minHeap.push(new Node(pair.first, pair.second));
    }
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* combined = new Node('\0', left->freq + right->freq);
        combined->left = left;
        combined->right = right;
        minHeap.push(combined);
    }
    Node* root = minHeap.top();
    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);
    cout << "Huffman Codes:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCodes[ch];
    }
    cout << "Encoded String: " << encodedString << endl;
}

int main() {
    string text = "hello huffman";
    huffmanCoding(text);

    return 0;
}
```

### Output

```bash
Huffman Codes:
e: 1110
f: 110
 : 1011
m: 1010
h: 100
n: 000
u: 001
o: 010
a: 1111
l: 011
Encoded String: 1001110011011010101110000111011010101111000
```

### Explanation

- **Node Structure**: Each node in the Huffman tree contains a character, its frequency, and pointers to left and right children.
- **Frequency Count**: A frequency map is created to count occurrences of each character.
- **Min-Heap**: Nodes are stored in a priority queue sorted by frequency to facilitate tree construction.
- **Tree Construction**: Nodes are combined until a single node (the root of the tree) remains.
- **Code Generation**: A recursive function traverses the tree to generate binary codes for each character based on their position.
- **Output**: The program prints the generated Huffman codes and the encoded binary string.

This implementation can be expanded to include decoding and better memory management, but it serves as a basic demonstration of Huffman coding.
