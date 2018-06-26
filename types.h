#pragma once

#include "defs.h"

as null {};

lambda <bool b, par x, par y> as churchbool
{
	letf value = y;
};
lambda <par x, par y> as churchbool<true, x, y>
{
	letf value = x;
};

lambda <int n> as integer
{
	let int value = n;
};

lambda <par n> as succ
{
};

lambda <int n> as succ<integer<n>>
{
	letf value = integer<n + 1>;
};

lambda <par n> as eq0 {};
lambda <int n> as eq0<integer<n>>
{
	letf value = churchbool<false, integer<n>, null>;
};
lambda <> as eq0<integer<0>>
{
    letf value = churchbool<true, integer<0>, null>;
};

