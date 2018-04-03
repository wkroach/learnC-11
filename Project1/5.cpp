#include"5.h"
using namespace std;

void Problem5_24() {
	int a = 0, b = 0;
	while (cin >> a >> b) {
		try {
			if (0 == b) {
				throw exception("b must not be 0");
			}
		}
		catch (exception err) {
			cout << err.what() << endl;
			cout << "do you want to reinput? y/n" << endl;
			char ch;
			cin >> ch;
			if (!cin || ch == 'n') {
				break;
			}
			else if (ch == 'y'){
				continue;
			}
		}
		cout << a / b << endl;
		break;
	}

}
