#pragma once

#include "defs.h"

as null {};

as churchfalse {};
as churchtrue {};

lambda <par b, par x, par y> as churchbool {};
lambda <par x, par y> as churchbool<churchfalse, x, y>
{
	letf value = y;
};
lambda <par x, par y> as churchbool<churchtrue, x, y>
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

lambda <par n> as eq1 {};
lambda <int n> as eq1<integer<n>>
{
	letf value = churchfalse;
};
lambda <> as eq1<integer<1>>
{
	letf value = churchtrue;
};

