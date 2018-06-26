#include "defs.h"
#include "fact.h"
#include "fibo.h"
#include "list.h"
#include "types.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	letf l0 = cons<integer<1>, cons<integer<1>, cons<integer<2>, nil>>>;

	letf l1 = map<succ, l0>::value;

	letf l2 = filter<eq1, l0>::value;

	cout << sum<l1>::value << endl;
	cout << sum<l2>::value << endl;

	return 0;
}

