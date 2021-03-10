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
%^GREEN%^You are walking on the %^ORANGE%^Q%^BOLD%^%^ORANGE%^u%^ORANGE%^i%^RESET%^%^ORANGE%^et %^BOLD%^%^GREEN%^F%^RESET%^%^GREEN%^ore%^BOLD%^%^GREEN%^s%^GREEN%^t%^RESET%^ %^BOLD%^%^ORANGE%^R%^RESET%^%^ORANGE%^oa%^BOLD%^%^ORANGE%^d%^RESET%^
%^RESET%^%^GREEN%^A %^ORANGE%^dirty road %^GREEN%^leads through f%^BOLD%^o%^RESET%^%^GREEN%^r%^BOLD%^e%^RESET%^%^GREEN%^st und%^BOLD%^e%^RESET%^%^GREEN%^rg%^BOLD%^row%^RESET%^%^GREEN%^th. The forest is not very dense and the path is visible for a good distance.
%^BOLD%^%^RED%^There is a sign here.%^RESET%^
MELNMARN
);

    set_items(([
	"road":"A new road through the forest.",
	"forest":"A quiet forest, for sure. Only the sounds of birds."
	]));

    set_exits(([
//        "south" : "/d/deku/new/entrance",
         "north" : "/d/shadow/room/mountain/road1",
	"east" : FORESTDIR+"road8",
	"west" : FORESTDIR+"road10"
   	]));
    set_smell("default","You smell fresh air and the odor of %^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^.");
    set_listen("default","You can hear birds singing.");
    set_climate(CLIMATE);
}

void reset() {
   ::reset();
   if(!present("sign"))
     new("/d/shadow/obj/special/roadsign_echoes_mtn")->move(TO);
}
