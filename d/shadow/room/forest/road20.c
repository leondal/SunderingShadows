#include "forest.h"
inherit "/std/rquestroom.c";

void create(){
    ::create();
    set_terrain(HEAVY_FOREST);
    set_travel(DIRT_ROAD);
    set_property("indoors",0);
	set_property("light",2);
	set_short("%^RESET%^%^GREEN%^A small campsite%^RESET%^");
	set_long(
	   "%^RESET%^%^GREEN%^A %^ORANGE%^small camp %^GREEN%^has been set up here in the %^BOLD%^%^BLACK%^shadows "+
	   "%^RESET%^%^GREEN%^of the trees. The forest brush has been pushed back enough to allow room for a "+
	   "%^BOLD%^%^RED%^firepit %^RESET%^%^GREEN%^and a small bit of space for tired horses to graze. Old "+
	   "%^ORANGE%^logs %^GREEN%^and %^ORANGE%^stumps %^GREEN%^provide some seating around the "+
	   "%^BOLD%^%^BLACK%^charred stones %^RESET%^%^GREEN%^of the firepit. It is very quiet and relaxing "+
	   "here, the only sounds being songbirds high in the trees.%^WHITE%^\n");
	set_items(([
	({"pit","fire pit"}) : "%^BOLD%^%^BLACK%^A ring of stones marks the borders of this fire pit. "+
	"The big rocks are charred from many years of holding back flames of traveller's fires.%^RESET%^",
	({"trees","foliage"}) : "%^RESET%^%^GREEN%^The camp is set back far enough from the road that the trees "+
	"block out most sights and sounds coming from that direction. These trees are old, with fat trunks and "+
	"crowns that are far overhead. A soft layer of moss circles the space, and some foliage and weeds have "+
	"managed to take root in the spaces where sunlight manages to find its way through the branches.%^WHITE%^",]));
    set_exits(([
	"east" : FORESTDIR+"road19",
	"southwest" : FORESTDIR+"road21",
	"northwest" : FORESTDIR+"road22"
   	]));
    set_smell("default","%^CYAN%^The fresh scent of the forest surrounds you.%^WHITE%^");
    set_listen("default","%^ORANGE%^You can hear birds singing.%^RESET%^");
    set_listen("birds","They seem to sing songs of love - or murder - depending on your mood.");

    set_quest_daemon("/daemon/quests_mid");
}
