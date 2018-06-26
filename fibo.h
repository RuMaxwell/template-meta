#pragma once

#include "defs.h"

lambda <int N> as fibo
{
	let int value = fibo<N - 1>::value + fibo<N - 2>::value;
};

lambda <> as fibo<0>
{
	let int value = 0;
};

lambda <> as fibo<1>
{
	let int value = 1;
};

