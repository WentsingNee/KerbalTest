/**
 * @file       could_use_helper.hpp
 * @brief
 * @date       2024-11-09
 * @author     Peter
 * @copyright
 *      Peter of [ThinkSpirit Laboratory](http://thinkspirit.org/)
 *   of [Nanjing University of Information Science & Technology](http://www.nuist.edu.cn/)
 *   all rights reserved
 */

#ifndef COULD_USE_HELPER_HPP
#define COULD_USE_HELPER_HPP

namespace ktest
{

	namespace type_traits
	{

		struct cu_empty
		{
		};



		struct cu_public_typedef
		{
				typedef int member;
		};

		struct cu_private_typedef
		{
			private:
				typedef int member;
		};


		struct cu_public_field
		{
				int member;
		};

		struct cu_private_field
		{
			private:
				int member;

			public:
				// use private field to avoid warning
				void unused_helper()
				{
					kerbal::utility::ignore_unused(member);
				}
		};

		struct cu_public_static_field
		{
				static int member;
		};

		struct cu_private_static_field
		{
			private:
				static int member;

			public:
				// use private field to avoid warning
				void unused_helper()
				{
					kerbal::utility::ignore_unused(member);
				}
		};


		struct cu_public_method
		{
				void member();
		};

		struct cu_private_method
		{
			private:
				void member();
		};

		struct cu_public_static_method
		{
				static void member();
		};

		struct cu_private_static_method
		{
			private:
				static void member();
		};

	} // namespace type_traits

} // namespace ktest

#endif//COULD_USE_HELPER_HPP
