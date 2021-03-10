//      /std/sign.c
//      from the Nightmare mudlib
//      an inheritable sign object
//      created by Hanse@Nightmare

#include <std.h>

inherit OBJECT;

int get() { 
    if(query("get message")) write(query("get message"));
    return 0;
}

void clean_up() { return; }
