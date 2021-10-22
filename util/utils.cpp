#include "utils.h"


namespace Util {
    using namespace std;

    /**
     * Writes directly to a file.
     * @param fileName the name of the file.
     * @param data The bytes to write.
     * @return True if successful, false otherwise.
     */
    bool writeFile(const string& fileName, const vector<byte>& data) {
        std::ofstream file(fileName.c_str(), std::ofstream::binary);
        if (file.is_open()) {
            file.write(reinterpret_cast<const char*>(data.data()), int(data.size()));
            file.close();
            return true;
        } else {
            std::cout << fileName << "does not exist.";
            return false;
        }
    }

    /**
     * Reads a file and returns an array of bytes.
     * @param fileName the file to read.
     * @return The file's contents as an array of bytes.
     */
     vector<byte> readFile(const string& fileName) {
        vector<byte> result ;
        std::streampos size;
        std::ifstream file(fileName.c_str(), std::ios::in|std::ios::binary|std::ios::ate);

        if (!file.is_open()) {
            std::cout << fileName << "could not be read.";
            return vector<byte>();
        }

        size = file.tellg();

        byte* data = new byte[size];
        file.seekg(0, std::ios::beg);
        file.read(reinterpret_cast<char*>(data), size);
        file.close();

        result.assign(data, data + size);
        return result;
    }

    vector<byte> splitShort(unsigned short value) {
        vector<byte> result(2);

        result.at(0) = value & 0x00FF;
        result.at(1) = (value >> 8);

        return result;
    }

    unsigned short fuseShort(byte high, byte low) {
        unsigned short result = 0;
        result = (result<<8) + high;
        result = (result<<8) + low;
        return result;
    }


    /**
     * Returns an array of strings by splitting a string according to a given delimiter.
     */
    vector<string> split(const string &s, char token) {
        vector<string> result(0);
        std::stringstream ss(s);
        string item;

        while (std::getline(ss, item, token)) {
            result.push_back(item);
        }
        return result;
    }
}