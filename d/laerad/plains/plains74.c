//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_long(::query_long()+"\n\n%^RESET%^%^ORANGE%^Just to the north, "
       "a crude camp has been set up between the mountain ridges that "
       "border the plains.%^RESET%^\n");
set_exits( ([
	"west":"/d/laerad/plains/plains66",
        "south":"/d/laerad/plains/plains75",
        "north":"/d/laerad/lgnolls/rooms/1"
    ]) );
}

