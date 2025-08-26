#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Struct to represent a blockchain transaction
struct Transaction {
    string sender;
    string receiver;
    int amount;
};

// Struct to represent a blockchain block
struct Block {
    int blockNumber;
    vector<Transaction> transactions;
    string previousBlockHash;
    string blockHash;
};

// Class to represent the blockchain
class Blockchain {
private:
    vector<Block> chain;
    unordered_set<string> uniqueSenders;
    unordered_set<string> uniqueReceivers;

public:
    void addBlock(const Block& block) {
        chain.push_back(block);
        for (const auto& transaction : block.transactions) {
            uniqueSenders.insert(transaction.sender);
            uniqueReceivers.insert(transaction.receiver);
        }
    }

    int getTransactionCount() {
        int count = 0;
        for (const auto& block : chain) {
            count += block.transactions.size();
        }
        return count;
    }

    int getUniqueSendersCount() {
        return uniqueSenders.size();
    }

    int getUniqueReceiversCount() {
        return uniqueReceivers.size();
    }

    void printBlockchainInfo() {
        cout << "Blockchain Info:" << endl;
        cout << "Transaction Count: " << getTransactionCount() << endl;
        cout << "Unique Senders Count: " << getUniqueSendersCount() << endl;
        cout << "Unique Receivers Count: " << getUniqueReceiversCount() << endl;
    }
};

int main() {
    Blockchain blockchain;

    // Create sample transactions and blocks
    Transaction tx1 = {"Alice", "Bob", 10};
    Transaction tx2 = {"Bob", "Charlie", 20};
    Transaction tx3 = {"Charlie", "Alice", 30};

    Block block1 = {1, {tx1, tx2}, "", ""};
    Block block2 = {2, {tx3}, block1.blockHash, ""};

    // Add blocks to the blockchain
    blockchain.addBlock(block1);
    blockchain.addBlock(block2);

    // Print blockchain info
    blockchain.printBlockchainInfo();

    return 0;
}