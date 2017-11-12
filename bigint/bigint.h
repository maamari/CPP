#include <string>
#include <vector>

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

class BigInt {
   public:
		BigInt(string s, int base);
		BigInt(string s); 
		string to_string(); 
		void add(BigInt b);
   private:
		vector<int> digits;
   		int baseB;
};
