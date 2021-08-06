#ifndef _STL_FOR_C_H
#define _STL_FOR_C_H

#ifndef EXPORTS
    //we are building dll library
	#ifdef BUILD_STL_FOR_C

	    #define EXPORTS __declspec(dllexport)

	#else
        //we are consuming dll in C
		#pragma  comment(lib,"stlforc.lib")
		#define EXPORTS __declspec(dllimport)

	#endif // end of BUILD_STL_FOR_C

#endif // end of EXPORTS
//here, EXPORTS macro is defined

#ifndef __cplusplus

	// in C, type bool is not defined
	// so, we define bool as type int
	typedef int bool;

	//because in C, true and false are not defined
	const int false = (0 != 0);
	const int true = (0 == 0);


#endif

#ifdef __cplusplus
	extern "C" {
#endif
		/*declare C interface here */
		typedef long long color_t;

		typedef struct st_map
		{
			color_t color;
			const char* key;
			int value;
		}map_t;

		//create a new map
		EXPORTS map_t map_create();
		EXPORTS bool map_delete(map_t*);
		EXPORTS bool map_get_value(map_t* map);
		EXPORTS bool map_set_value(map_t* map);

#ifdef __cplusplus
}

#endif 


#endif //end of file for _STL_FOR_C_H
