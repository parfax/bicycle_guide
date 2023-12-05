#include "Dependencies/nlohmann/json.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
using namespace nlohmann;

struct Option {
	string name, path;
};

void getOptions();
void checkFile(ifstream& file);
vector<Option>& getVectorOfOptions();