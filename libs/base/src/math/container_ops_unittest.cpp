/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2014, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */


#include <mrpt/base.h>
#include <gtest/gtest.h>

using namespace mrpt;
using namespace mrpt::utils;
using namespace mrpt::math;
using namespace mrpt::random;
using namespace mrpt::utils::metaprogramming;
using namespace std;



TEST(dynamicsize_vector,resize)
{
	{
		mrpt::vector_double v;
		EXPECT_TRUE(v.size()==0);
	}

	for (int i=0;i<10;i++)
	{
		mrpt::vector_double v(i);
		EXPECT_TRUE(v.size()==i);
	}

	for (int i=0;i<10;i++)
	{
		mrpt::vector_double v;
		v.resize(i);
		EXPECT_TRUE(v.size()==i);
	}

	for (int i=10;i>=0;i--)
	{
		mrpt::vector_double v;
		v.resize(i);
		EXPECT_TRUE(v.size()==i);
	}

	{
		mrpt::vector_double v;
		for (int i=0;i<10;i++)
		{
			v.push_back(double(i));
			EXPECT_TRUE(v.size()==(i+1));
		}
		for (int i=0;i<10;i++)
		{
			EXPECT_TRUE(v[i]==i);
		}
	}

	{
		mrpt::vector_double v;
		v.reserve(10);
		for (int i=0;i<10;i++)
		{
			v.push_back(double(i));
			EXPECT_TRUE(v.size()==(i+1));
		}
		for (int i=0;i<10;i++)
		{
			EXPECT_TRUE(v[i]==i);
		}
	}
}


