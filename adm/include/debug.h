#ifndef _DEBUG_H
#define _DEBUG_H
/*
   debug(x,y) macro added by Truilkan@TMI 92/03/03:

   #define DEBUG_MACRO to cause the debug macro to be expanded (compiled).
   #undef DEBUG_MACRO to cause the preprocessor to strip the debug code out.
   If one wishes to use the debug(x,y) macro, DEBUG_MACRO should be defined
   prior to including this file (debug.h).
*/

#ifdef DEBUG_MACRO
nosave int _debug_level;
#define set_debug_level(x) _debug_level = x;
#ifdef TELL
/* debug tries to tell the player specifed by #define TELL "playername" */
#define debug(x,y) if (x & _debug_level) tell_object(find_player(TELL),y)
#else
#define debug(x,y) if (x & _debug_level) write(y)
#endif
#else
/* here debug macro expands to nothing */
#define debug(x,y)
#define set_debug_level(x)
#endif DEBUG_MACRO

/* end of debug(x,y) code */

#define T_UNKNOWN  0
#define T_INT      1
#define T_STRING   2
#define T_POINTER  3
#define T_OBJECT   4

#define TYPES ({ \
        "UNKNOWN", \
        "INT    ", \
        "STRING ", \
        "POINTER", \
        "OBJECT ", \
        })

#endif _DEBUG_H
