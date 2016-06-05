#include <iostream>
using namespace std;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
problem:
input: n
function: 将n用2的指数表示，使得指数表达式的个数最少
output: int num (指数的最少的个数)
e.g: input = 28
28 = 2^4 + 2^3 +2^2 => num = 3
28 = 2^5 - 2^2 => num = 28
output = 2

method:
1...1 = 10...0 - 1
当连续的1的数量大于1个时，替换成减
二进制1...1段与另一段之间是独立的，两段是相加的关系，因此对二进制表示从尾到头扫描一遍即可

note:
"lastBit = n & (-n);"
"lastBit << 1" won't change lastBit
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int minExp(int n) {
	int ans = 0;
	while(n != 0) {
		int lastBit = n & (-n); // n的二进制表示中最后一位1的位置，28 & (-28) = 4
		if((n & (lastBit << 1)) != 0) { // 若为真，有连续1
			ans++;
			n += lastBit; // 对这位的1加1进位，最终表示为减
		}else {
			ans++;
			n -= lastBit; // 单个1，用lastBit单独表示
		}
	}
	return ans;
}

int main() {
	cout << minExp(28) << endl; // 11100 = 100000 - 100
	cout << minExp(19) << endl; // 10011 = 10000 + 100 - 1
	cout << minExp(29) << endl; // 11101 = 100000 - 100 + 1
	cout << minExp(2684354559) << endl; // 32'b10011111111111111111111111111111 程序上界
	cout << minExp(0) << endl; // 0 程序下界
	cout << minExp(-1610612737) << endl; // 32'b10011111111111111111111111111111 负数用补码表示，在本程序中与正数同
	return 0;
}
