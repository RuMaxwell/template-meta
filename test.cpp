#include "defs.h"
#include "fact.h"
#include "fibo.h"
#include "list.h"
#include "types.h"
#include "io.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	letf l0 = cons<integer<1>, cons<integer<1>, cons<integer<2>, nil>>>;
	letf l1 = map<succ, l0>::value;
	letf l2 = filter<eq1, l0>::value;
	letf l3 = range<5>::value;
	letf l4 = concat<l1, l3>::value;
	letf l5 = reverse<range<4>::value>::value;

	print<l0>::_();
	print<l1>::_();
	print<l2>::_();
	print<l3>::_();
	print<l4>::_();
	cout << sum<l4>::value << endl;
	print<l5>::_();

	return 0;
}

