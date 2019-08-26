#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;

struct File_Header {
	int blocksize;
	int RootBID;
	int depth;
};

struct Index_Entry {
	int Key;
	int BID;
};

struct Data_Entry {
	int Key;
	int Value;
};

struct NonLeafNode {
	vector <Index_Entry> Indices;
	int NextLevelBID;
};

struct LeafNode {
	vector <Data_Entry> Data;
	int NextBiD;
};

class BTree {
	int blocksize;
	int root;
	int depth;
	const char* filename;

public:
	BTree(const char *fileName, int blockSize) {
		filename = fileName;
		blocksize = blockSize;
		root = 0;
		depth = 0;
		ofstream output(filename, ios::out | ios::binary);
		output.write((char*)&blocksize, sizeof(int));
		output.write((char*)&root, sizeof(int));
		output.write((char*)&depth, sizeof(int));
		output.close();
	}
	BTree(const char *fileName, int blockSize, int RT, int DP) {
		filename = fileName;
		blocksize = blockSize;
		root = RT;
		depth = DP;
	}
	bool insert(int key, int rid) {
		NonLeafNode Root;
		return true;
	}
	void print() {
	}
	int* search(int key) {
	}// point search
	int* search(int startRange, int endRange) {
	}// range search
};

void PrintBTree(string fileName) {
	int BlockSize;
	int RootBID;
	int Depth;

	ifstream file(fileName, ios::in | ios::binary);
	file.read((char*)&BlockSize, sizeof(int));
	file.read((char*)&RootBID, sizeof(int));
	file.read((char*)&Depth, sizeof(int));


	int root = 12 + ((RootBID - 1) * BlockSize);
	file.seekg(root);

	fstream Text("print.txt", ios::out);


	if (Depth == 0) {
		int *ptr = new int[BlockSize / sizeof(int)];
		int BID;
		int NLBID;
		file.read((char*)ptr, sizeof(BlockSize));
		Text << "<0>\n";
		for (int i = 0; i < BlockSize / 4; i++) {
			if (ptr[i] != 0)
				Text << ptr[i] << ",";
		}
		Text << "\n";
	}

	else if (Depth == 1) {
		int *ptr = new int[BlockSize / sizeof(int)];
		int BID;
		int NLBID;
		int NextBID;
		int count = (BlockSize - 4) / 8;

		file.read((char*)ptr, sizeof(BlockSize));
		NLBID = ptr[0];
		Text << "<0>\n";
		for (int i = 1; i < BlockSize / 4; i += 2) {
			if (ptr[i] != 0)
				Text << ptr[i] << ",";
		}
		Text << "\n";

		Text << "<1>\n";

		file.seekg(12 + ((NLBID - 1) * BlockSize));
		file.read((char*)ptr, sizeof(BlockSize));
		for (int i = 0; i < BlockSize / 4 - 1; i += 2) {
			if (ptr[i] != 0)
				Text << ptr[i] << ",";
		}
		NextBID = ptr[(BlockSize / 4) - 1];
		while (NextBID != 0) {
			file.seekg(12 + ((NextBID - 1) * BlockSize));
			file.read((char*)ptr, sizeof(BlockSize));
			for (int i = 0; i < BlockSize / 4 - 1; i += 2) {
				if (ptr[i] != 0)
					Text << ptr[i] << ",";
			}
			NextBID = ptr[(BlockSize / 4) - 1];
		}
	}

	else if (Depth >= 2) {
		int BID;
		int NLBID;
		int NextBID;
		int *ptr = new int[BlockSize / sizeof(int)];
		vector <int> pointer;
		file.read((char*)ptr, sizeof(BlockSize));
		Text << "<0>\n";
		NLBID = ptr[0];
		pointer.push_back(NLBID);
		for (int i = 1; i < BlockSize / 4; i += 2) {
			if (ptr[i] != 0)
				Text << ptr[i] << ",";
			if (ptr[i + 1] != 0) {
				BID = ptr[i + 1];
				pointer.push_back(BID);
			}
		}
		Text << "\n";

		Text << "<1>\n";

		for (int i = 0; i < pointer.size(); i++) {
			int p = pointer[i];
			file.seekg(12 + ((p - 1) * BlockSize));
			file.read((char*)ptr, sizeof(BlockSize));
			for (int i = 1; i < BlockSize / 4; i += 2) {
				if (ptr[i] != 0)
					Text << ptr[i] << ",";
			}
		}

	}
}


	// Test
	int main(int argc, char* argv[])
	{
		char command = argv[1][0];
		const char* file_name = argv[2];
		switch (command)
		{
		case 'c': {// create index file
			int blocksize = atoi(argv[3]);
			BTree* newBTree = new BTree(file_name, blocksize);

			break;
		}
		case 'i': {// insert records from [records data file], ex) records.txt
			const char* text_file = argv[3];
			ifstream file(file_name, ios::in | ios::binary);
			int size;
			file.read((char*)&size, sizeof(int));
			BTree* newBTree = new BTree(file_name, size);
			file.close();
			ifstream input(text_file, ios::in | ios::binary);
			while (input.eof()) {
				int key = 0;
				int id = 0;
				char line[20];
				input.getline(line, sizeof(line));
				for (int i = 0; i < 20; i++) {
					if (line[i] == ',') {
						for (int j = i + 1; j < 20; j++) {
							if (line[j] > 57 || line[j] < 48) { break; };
							id *= 10;
							id *= (line[j] - '0');
						}
						break;
					}
					key *= 10;
					key *= (line[i] - '0');
				}
				cout << id << ' ' << key << "\n";
				cout << newBTree->insert(id, key);
			}
			input.close();
			break;
		}
		case 's':
			// search keys in [input file] and print results to [output file]
			break;
		case 'r':
			// search keys in [input file] and print results to [output file]
			break;
		case 'p': {
			// print B+-Tree structure to [output file]
			PrintBTree(argv[1]);
			break;

		}
		}
	}

