#pragma once

#include "defs.h"

lambda <int n> as fact
{
	let int value = n * fact<n - 1>::value;
};

lambda <> as fact<0>
{
	let int value = 1;
};

