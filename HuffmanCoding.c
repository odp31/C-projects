#include <stdio.h>
#include <stdlib.h>

struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
};

struct MinHeapNode {
    unsigned freq;
    char data;
    struct MinHeapNode *left, *right;
};

struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// Function to create a new Min Heap Node
struct MinHeapNode* newNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct   
 MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Function to create a Min Heap   

struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size   
 = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;   

}

// Function to swap two Min Heap Nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;   

}

// Function to heapify   
 a subtree rooted with node i
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);   

    }
}

// Function to extract minimum element from Min Heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;   

}

// Function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;   

}

// Function to build   
 a Huffman Tree
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;   


    while (minHeap->size != 1) {
        struct MinHeapNode *left = extractMin(minHeap);
        struct MinHeapNode *right = extractMin(minHeap);

        struct Node* node = (struct Node*)malloc(sizeof(struct Node));
        node->left = left;
        node->right = right;
        node->freq = left->freq + right->freq;

        insertMinHeap(minHeap, node);
    }

    return extractMin(minHeap);
}

// Function to print codes by traversing the tree
void printCodes(struct Node* root, int arr[], int top) {
    if (!root)
        return;

    if (root->data != '$') {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    arr[top] = 0;
    printCodes(root->left, arr, top + 1);

    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
}

// Function to encode the text
void encode(char *str) {
    // ... (Calculate frequency, build Huffman tree, and encode the string)
}

// Function to decode the encoded text
void decode(char *str) {
    // ... (Decode the string using the Huffman tree)
}

int main() {
    char arr[] = "Huffman coding is a data compression algorithm.";
    int size = strlen(arr);

    // Calculate frequency of each character
    int freq[size];
    // ... (Calculate frequency)

    struct Node* root = buildHuffmanTree(arr, freq, size);

    int arr[MAX_TREE_HT];
    printCodes(root, arr, 0);

    return 0;
}
