#ifndef SOURCEMAP_TYPEDEF
#define SOURCEMAP_TYPEDEF

#include <cstddef> // __GLIBCXX__, _HAS_TR1

#include <memory>
#define USE_STD_SHARED_PTR

#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>

#ifdef __cplusplus

// #define HAS_PANDA
// #define PANDA_REFCNT

#ifdef HAS_PANDA

	#include <panda/def.h>
	#include <panda/cast.h>
	#include <panda/refcnt.h>
	#include <panda/traits.h>

	#ifdef PANDA_REFCNT
		#define PANDA_INHERIT : virtual public panda::RefCounted
	#endif

#endif

#ifndef PANDA_INHERIT
	#define PANDA_INHERIT
#endif

// add namespace for c++
namespace SourceMap
{

	// import some stuff
	using std::cerr;
	using std::endl;
	using std::vector;
	using std::string;
	using std::ostream;
	using std::stringstream;
	using std::istringstream;
	using std::logic_error;
	using std::out_of_range;
	using std::runtime_error;
	using std::invalid_argument;

	#if defined(USE_STD_SHARED_PTR)
		using std::shared_ptr;
		using std::make_shared;
	#elif defined(USE_STD_TR1_SHARED_PTR)
		using std::tr1::shared_ptr;
		template< class T, class... Args >
		shared_ptr<T> make_shared( Args&&... args )
		{ return shared_ptr<T>(new T(args...)); }
	#elif defined(USE_BOOST_SHARED_PTR)
		using boost::shared_ptr;
		using boost::make_shared;
	#else
		#error No shared-pointer implementation selected!
	#endif

	#define foreach(type, variable, array) \
		auto variable = array.begin(); \
		auto end_##variable = array.end(); \
		for(; variable != end_##variable; ++variable)

	#define foreach_ptr(type, variable, array) \
		auto it_##variable = array.begin(); \
		auto end_##variable = array.end(); \
		for(shared_ptr<type> variable; it_##variable != end_##variable && (variable = *it_##variable); ++it_##variable)

	#define const_foreach(type, variable, const_array) \
		auto variable = const_array.begin(); \
		auto end_##variable = const_array.end(); \
		for(; variable != end_##variable; ++variable)

	#define const_foreach_ptr(type, variable, array) \
		auto it_##variable = array.begin(); \
		auto end_##variable = array.end(); \
		for(shared_ptr<type> variable; it_##variable != end_##variable && (variable = *it_##variable); ++it_##variable)

};
// EO namespace


// declare for c
extern "C" {
#endif

// void foobar();

#ifdef __cplusplus
}
#endif

#endif
