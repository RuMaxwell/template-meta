#pragma once

#include "defs.h"
#include "types.h"

as nil {};

lambda <par head, par tail> as cons {};

lambda <par left, par right> as concat {};
lambda <par x, par xs, par right> as concat<cons<x, xs>, right>
{
	letf value = cons<x, par concat<xs, right>::value>;
};
lambda <par left> as concat<left, nil>
{
	letf value = left;
};
lambda <par right> as concat<nil, right>
{
	letf value = right;
};

lambda <par list> as reverse {};
lambda <par x, par xs> as reverse<cons<x, xs>>
{
	letf value = par concat<par reverse<xs>::value, cons<x, nil>>::value;
};
lambda <> as reverse<nil>
{
	letf value = nil;
};

lambda <int x> as reverseRange
{
	letf value = cons<integer<x>, par reverseRange<x - 1>::value>;
};
lambda <> as reverseRange<0>
{
	letf value = nil;
};

lambda <int x> as range
{
	letf value = par reverse<par reverseRange<x>::value>::value;
};

lambda <func f, par list> as map {};
lambda <func f, par x, par xs> as map<f, cons<x, xs>>
{
	letf value = cons<par f<x>::value, par map<f, xs>::value>;
};
lambda <func f> as map<f, nil>
{
	letf value = nil;
};

lambda <func f, par list> as filter {};
lambda <func f, par x, par xs> as filter<f, cons<x, xs>>
{
	letf value = par churchbool<
		par f<x>::value,
		cons<x, par filter<f, xs>::value>,
		par filter<f, xs>::value
	>::value;
};
lambda <func f> as filter<f, nil>
{
	letf value = nil;
};

lambda <par list> as sum {};
lambda <par car, par cdr> as sum<cons<car, cdr>>
{
	let int value = car::value + sum<cdr>::value;
};
lambda <par cdr> as sum<cons<null, cdr>>
{
	let int value = sum<cdr>::value;
};
lambda <> as sum<nil>
{
	let int value = 0;
};

