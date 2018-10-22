#include <stdio.h>

#include "../Blockchain/Blockchain.h"

class TransactionData {
private:
	int sender, reciever, amount;

public:
	TransactionData() : TransactionData(0, 0, 0) {}
	TransactionData(int sender, int reciever, int amount) :
		sender{ sender },
		reciever{ reciever },
		amount{ amount }
	{}

	size_t createHash() {
		std::hash<std::string> hasher;
		return hasher(std::to_string(sender) + std::to_string(reciever) + std::to_string(amount));
	}

	std::string show() {
		return "Sender: " + std::to_string(sender) + "\n" +
			"Reciever: " + std::to_string(reciever) + "\n" +
			"Amount: " + std::to_string(amount);
	}
};

int main() {
	Blockchain<TransactionData> cryptocurrency;
	cryptocurrency.addBlock(TransactionData(123, 456, 42000));
	cryptocurrency.show();

	getchar();
	return 0;
}