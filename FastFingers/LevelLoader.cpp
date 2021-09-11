#include <fstream>
#include <sstream>

#include "LevelLoader.h"

using namespace std;

vector<KeyInfo> loadLevel(const string& level) {
	ifstream fin;
	fin.open(level);
	vector<KeyInfo> keys;
	while (!fin.eof()) {
		if (fin.good()) {
			char ch;
			float time, x, y, velocity;
			fin >> ch >> time >> x >> y >> velocity;
			keys.push_back(KeyInfo(ch, time, x, y, velocity));
#if _DEBUG
			stringstream stream;
			stream << ch << " " << velocity << " " << time << endl;
			OutputDebugString(stream.str().c_str());
#endif
		}
	}
	fin.close();
	return keys;
}
