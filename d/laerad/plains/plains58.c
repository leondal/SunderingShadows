//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_base.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains45",
	"east":"/d/laerad/plains/plains69",
	"south":"/d/laerad/plains/plains59",
	"north":"/d/laerad/plains/plains57"
    ]) );
}
