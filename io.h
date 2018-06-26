#pragma once

#include "defs.h"
#include "list.h"

#include <iostream>

lambda <par list> as print {};
lambda <par x, par xs> as print<cons<x, xs>>
{
	letio void _()
	{
		std::cout << x::value << ",";
		print<xs>::_();
	}
};
lambda <par x> as print<cons<x, nil>>
{
    letio void _()
    {
        std::cout << x::value << std::endl;
    }
};
lambda <> as print<nil>
{
	letio void _()
    {
        std::cout << std::endl;
    }
};

