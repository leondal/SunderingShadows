/******** CRITICAL "/d/shadow/room/forest/road1"!!!!!! *******************
/******** If you fuck this room up, you will make people never
/******** able to get back to the game from the freezer or the void.
/******** please be careful! - Garrett. ******************/
#include "/d/shadow/room/forest/forest.h"
inherit "/d/shadow/room/forest/road1";

void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("A Crossroads %^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^");
    set_items(([
	"road":"A new road through the forest.",
	"forest":"A quiet forest, for sure. Only the sounds of birds."
	]));
    set_long(::query_long()+"%^WHITE%^ The path is split as it goes eastward here and there is a rough path north headed into the mountains.%^RESET%^");

    set_exits(([
   "north" : "/d/newbie/rooms/roadout/mtnroad49",
	"west" : FORESTDIR+"road31",
	"southeast" : FORESTDIR+"road29",
	"northeast" : FORESTDIR+"road28"
   	]));
    set_smell("default","You smell fresh air and the odor of %^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^.");
    set_listen("default","You can hear birds singing.");

}

void init(){
	::init();
	if(!present("sign"))
	new("/d/newbie/obj/misc/roadsign1.c")->move(TO);
}
