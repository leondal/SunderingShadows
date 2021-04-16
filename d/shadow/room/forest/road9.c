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
	"road":"This dirt road cuts through a quiet forest.",
	"forest":"This is an aptly named road through a quiet forest. You hear only the occasional bird song."
	]));

    set_exits(([
//        "south" : "/d/deku/new/entrance",
         "north" : "/d/shadow/room/mountain/road1",
	"east" : FORESTDIR+"road8",
	"west" : FORESTDIR+"road10"
   	]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","%^ORANGE%^You can hear birds singing.%^RESET%^");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");
    set_climate(CLIMATE);
}

void reset() {
   ::reset();
   if(!present("sign"))
     new("/d/shadow/obj/special/roadsign_echoes_mtn")->move(TO);
}
