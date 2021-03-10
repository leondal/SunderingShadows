#include "../../undead.h"
inherit STABLE;
#define HOR "/d/common/mounts/"

void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_terrain(CITY);
    set_travel(DIRT_ROAD);
    set_name("The stables of Graez");
    set_short("%^RESET%^%^GREEN%^The stables of Graez%^RESET%^");
    set_long("%^RESET%^%^GREEN%^The stables of Graez%^RESET%^\n"
"Bigger than most of the other buildings around, this one is out of the way "
"from the main %^RED%^bustle %^RESET%^of the town.  Semi-open, you can see "
"that the inside has been partitioned into several holding stalls, many of "
"which are currently home to a variety of trained mounts.  %^YELLOW%^Straw "
"%^RESET%^crunches underfoot, and at the entry you could probably %^BOLD%^"
"%^WHITE%^read list %^RESET%^of the ones available for sale today.\n");
    set_smell("default","The thick scent of animals overwhelms everything else here.");
    set_listen("default","You hear the sounds of battle in the distance.");
    set_animal(({"pony","horse","workhorse","war horse","barded war horse"}),({HOR"pony",HOR"horse",HOR"clydesdale",HOR"war_horse",HOR"barded_war_horse"}));
    set_animal_price(({"pony","horse","workhorse","war horse","barded war horse"}),({50,80,250,500,2500}));
    set_stalls(8);
    ::fill_stalls();
    set_exits( ([
        "south":TOWN"street5",
        "east":TOWN"tether"
    ]) );
}

void reset(){
   if(!present("klaus")) new(MON"klaus")->move(TO);
}
