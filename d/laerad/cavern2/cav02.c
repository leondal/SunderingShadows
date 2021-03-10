//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern2/special/cavern.c";
void create(){
    ::create();
    set_short("Laerad caverns");
    set_long(
	"You are in some kind of underground cavern system.  The air here is damp "+
	"and humid.  The area is much darker here below the first level of the caves.  "+
	"The ground is covered in a few inches of water, it trickles down from the "+
	"walls all around you.  Strange mosses and fungi grow on the walls."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air smells very musty and old.");
    set_listen("default","You can hear the trickling of water down the walls and passages.");
    set_exits( ([
	"northeast":"/d/laerad/cavern2/cav01",
	"southeast":"/d/laerad/cavern2/cav03"
    ]) );
    set_pre_exit_functions( ({"northeast"}), ({"no_mon"}) );
}

int no_mon(){
    if(TP->query_property("wandermon")) return 0;
    else return 1;
}
