#pragma once

#include "defs.h"
#include "types.h"

as nil {};

lambda <par head, par tail> as cons {};

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

