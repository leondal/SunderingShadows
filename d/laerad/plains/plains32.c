//Coded by Bane//
#include <std.h>
inherit "/d/laerad/plains_mobs.c";

void create(){
    ::create();
    set_exits( ([
	"west":"/d/laerad/plains/plains19",
	"east":"/d/laerad/plains/plains45",
	"south":"/d/laerad/plains/plains33",
	"north":"/d/laerad/plains/plains31"
    ]) );
}
