#include <iostream>
using namespace std;

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
method:
1...1 = 10...0 - 1
��������1����������1��ʱ���滻�ɼ�
������1...1������һ��֮���Ƕ����ģ���������ӵĹ�ϵ����˶Զ����Ʊ�ʾ��β��ͷɨ��һ�鼴��

note:
"lastBit = n & (-n);"
"lastBit << 1" won't change lastBit
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

int minExp(int n) {
	int ans = 0;
	while(n != 0) {
		int lastBit = n & (-n); // n�Ķ����Ʊ�ʾ�����һλ1��λ�ã�28 & (-28) = 4
		if((n & (lastBit << 1)) != 0) { // ��Ϊ�棬������1
			ans++;
			n += lastBit; // ����λ��1��1��λ�����ձ�ʾΪ��
		}else {
			ans++;
			n -= lastBit; // ����1����lastBit������ʾ
		}
	}
	return ans;
}

int main() {
	cout << minExp(28) << endl; // 11100 = 100000 - 100
	cout << minExp(19) << endl; // 10011 = 10000 + 100 - 1
	cout << minExp(29) << endl; // 11101 = 100000 - 100 + 1
	cout << minExp(2684354559) << endl; // 32'b10011111111111111111111111111111 �����Ͻ�
	cout << minExp(0) << endl; // 0 �����½�
	cout << minExp(-1610612737) << endl; // 32'b10011111111111111111111111111111 �����ò����ʾ���ڱ�������������ͬ
	return 0;
}
