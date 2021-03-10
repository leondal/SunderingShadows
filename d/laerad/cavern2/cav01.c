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
	"southwest":"/d/laerad/cavern2/cav02",
	"southeast":"/d/laerad/cavern2/cav04",
	"up":"/d/laerad/cavern1/cav058",
	"northwest":"/d/laerad/cavern2/cav33",
	"northeast":"/d/laerad/cavern2/cav07"
    ]) );
    find_object_or_load("/d/laerad/cavern2/lair");
}

