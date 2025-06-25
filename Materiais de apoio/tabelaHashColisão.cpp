#include <iostream>
using namespace std;

const int TABLE_SIZE = 5;

struct HashEntry {
    int key;
    int value;
    bool occupied;
};

void initTable(HashEntry table[]) {
    for (int i = 0; i < TABLE_SIZE; ++i)
        table[i].occupied = false;
}

int hashFunc(int key) {
    return key % TABLE_SIZE;
}

// Função para tratamento de colisão usando linear probing
int resolveCollision(HashEntry table[], int idx) {
    int startIdx = idx;
    do {
        idx = (idx + 1) % TABLE_SIZE;
        if (!table[idx].occupied)
            return idx;
    } while (idx != startIdx);
    return -1; // tabela cheia
}

void insert(HashEntry table[], int key, int value) {
    int idx = hashFunc(key);
    if (!table[idx].occupied) {
        table[idx].key = key;
        table[idx].value = value;
        table[idx].occupied = true;
        cout << "Inserted (" << key << ", " << value << ") at " << idx << endl;
        return;
    }
    // Colisão: usar função de tratamento
    int newIdx = resolveCollision(table, idx);
    if (newIdx != -1) {
        table[newIdx].key = key;
        table[newIdx].value = value;
        table[newIdx].occupied = true;
        cout << "Inserted (" << key << ", " << value << ") at " << newIdx << " (collision resolved)\n";
    } else {
        cout << "Hash table is full!\n";
    }
}

bool search(HashEntry table[], int key, int &value) {
    int idx = hashFunc(key);
    int startIdx = idx;
    do {
        if (table[idx].occupied && table[idx].key == key) {
            value = table[idx].value;
            return true;
        }
        if (!table[idx].occupied)
            return false;
        idx = (idx + 1) % TABLE_SIZE;
    } while (idx != startIdx);
    return false;
}

void display(HashEntry table[]) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i].occupied)
            cout << i << ": (" << table[i].key << ", " << table[i].value << ")\n";
        else
            cout << i << ": empty\n";
    }
}

int main() {
    HashEntry table[TABLE_SIZE];
    initTable(table);

    insert(table, 1, 100);
    insert(table, 6, 200);
    insert(table, 11, 300);
    insert(table, 2, 400);
    insert(table, 7, 500);

    display(table);

    int value;
    if (search(table, 6, value))
        cout << "Found key 6 with value " << value << endl;
    else
        cout << "Key 6 not found\n";

    if (search(table, 3, value))
        cout << "Found key 3 with value " << value << endl;
    else
        cout << "Key 3 not found\n";

    return 0;
}
