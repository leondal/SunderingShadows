#include "forest.h"
inherit ROOM;

void create(){
    ::create();
   set_terrain(LIGHT_FOREST);
   set_travel(DIRT_ROAD);
    set_property("light" , 2);
    set_property("indoors" , 0);
    set_short("%^RESET%^%^GREEN%^Fores%^BOLD%^%^GREEN%^t%^RESET%^ %^ORANGE%^O%^BOLD%^%^ORANGE%^u%^RESET%^%^ORANGE%^tpo%^BOLD%^%^ORANGE%^s%^ORANGE%^t%^RESET%^");
	set_long("%^RESET%^%^GREEN%^Fores%^BOLD%^%^GREEN%^t%^RESET%^ %^ORANGE%^O%^BOLD%^%^ORANGE%^u%^RESET%^%^ORANGE%^tpo%^BOLD%^%^ORANGE%^s%^ORANGE%^t%^RESET%^
%^RESET%^%^GREEN%^You stand in forest clearing that %^ORANGE%^dirty road%^GREEN%^ passes through. A simple wooden watchtower talls barely above the tree level here and large %^BOLD%^%^ORANGE%^w%^RESET%^%^ORANGE%^eath%^BOLD%^%^ORANGE%^e%^ORANGE%^r%^ORANGE%^e%^ORANGE%^d%^RESET%^ %^BOLD%^%^ORANGE%^t%^RESET%^%^ORANGE%^e%^BOLD%^%^ORANGE%^n%^ORANGE%^t%^RESET%^%^GREEN%^ is set below it. Wooden tables have been set up outside of it. Behind a wooden fence, there is a training circle with dirty floor and training dummies. Stall with horses stands just at the edge of this clearing. A number of armed people mill about the outpost.%^RESET%^
"
);
    set_items(([
	"road":"A new road through the forest.",
	"forest":"A quiet forest, for sure. Only the sounds of birds.",
    "tent":"%^ORANGE%^This tent resembles those used by the desert peoples of the Tsarvani Empire, only with less decorative flare and more utilitarian design. Heavy canvas is used for fabric, and judging by the wear on it, the tent has seen many seasons of use. Patches have been sewn into places where cuts or tears have happened.%^RESET%^"
	]));

    set_exits(([
	"east" : FORESTDIR+"road2",
        "north":"/d/shadow/room/forest/oocthall1",
    /*"north":"/d/shadow/room/goblin/rooms/gate1",*/
	"southwest" : FORESTDIR+"road4"
   	]));
    set_smell("default","You smell fresh air and the odor of %^GREEN%^w%^BOLD%^i%^MAGENTA%^l%^RESET%^%^MAGENTA%^d%^BOLD%^fl%^RESET%^%^MAGENTA%^o%^BOLD%^we%^RESET%^%^MAGENTA%^r%^BOLD%^s%^ORANGE%^.");
    set_listen("default","You can hear %^BOLD%^%^WHITE%^me%^RESET%^%^WHITE%^t%^WHITE%^a%^BOLD%^%^WHITE%^l %^WHITE%^c%^BOLD%^%^WHITE%^l%^WHITE%^a%^WHITE%^s%^WHITE%^h%^RESET%^%^WHITE%^ing, %^MAGENTA%^l%^BOLD%^%^MAGENTA%^aughter%^RESET%^%^GREEN%^ and %^MAGENTA%^drunk%^BOLD%^%^MAGENTA%^e%^RESET%^%^MAGENTA%^n %^MAGENTA%^singing.");
    set_climate(CLIMATE);
}

void reset()
{
    if(!present("merc_boss"))
    {
        new("/d/token_hunt/henchmen/hench_boss.c")->move(TO);
    }
}
