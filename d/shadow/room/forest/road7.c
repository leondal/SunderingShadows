#include "forest.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^RESET%^%^GREEN%^On the Quiet %^BOLD%^%^GREEN%^Fo%^RESET%^%^GREEN%^r%^GREEN%^e%^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^t %^ORANGE%^R%^BOLD%^%^ORANGE%^o%^ORANGE%^a%^ORANGE%^d%^RESET%^");
    set_long(
@MELNMARN
%^GREEN%^You are walking on the %^ORANGE%^Q%^BOLD%^%^ORANGE%^u%^ORANGE%^i%^RESET%^%^ORANGE%^et %^BOLD%^%^GREEN%^F%^RESET%^%^GREEN%^ore%^BOLD%^%^GREEN%^s%^GREEN%^t%^RESET%^ %^BOLD%^%^ORANGE%^R%^RESET%^%^ORANGE%^oa%^BOLD%^%^ORANGE%^d%^RESET%^ %^RESET%^
%^GREEN%^A %^ORANGE%^dirty road %^GREEN%^leads through f%^BOLD%^o%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^st und%^BOLD%^e%^RESET%^%^GREEN%^rg%^BOLD%^row%^RESET%^%^GREEN%^th. The forest is not very dense, and the path is visible for a good distance.
There is a %^BOLD%^BLUE%^sign%^RESET%^%^GREEN%^ near the road.
MELNMARN
);

    set_items(([
	"road":"A new road through the forest.",
	"sign":"Try reading it.",
	"forest":"A quiet forest, for sure. Only the sounds of birds."
	]));

    set_exits(([
	"east" : FORESTDIR+"road6",
//	"south" : PLAYERVILLAGEDIR+"pvroad9",
	"west" : FORESTDIR+"road8"
   	]));
    set_smell("default","You smell fresh air and the odor of %^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^.");
    set_listen("default","You can hear birds singing.");
    set_climate(CLIMATE);

}
void init(){
    ::init();
	add_action("read_sign","read");
}
int read_sign(string str){
     if(!str) return notify_fail("Read what?\n");
     if(str != "sign") return notify_fail("Read what?\n");
	tell_room(environment(TP),TPQCN+" reads the sign.",TP);
	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
//	write("%^BOLD%^%^GREEN%^The Player Village lies south of here.");
	write("%^BOLD%^%^GREEN%^      Shadow lies east of here.");
	write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
	return 1;


}
