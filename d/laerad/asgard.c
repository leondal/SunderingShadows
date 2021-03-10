// Coded by ~Circe~ 3/29/13 for Tarrasque plot/return
// of the druids. Will be reverted after the plot and a
// short rebuilding.

#include <std.h>

inherit CROOM;

void create(){
   if(!random(3)) set_monsters( ({"/d/laerad/mon/faith_warrior"}),({random(3)}));
   if(!random(5)) set_monsters( ({"/d/laerad/mon/shambling_mound"}),({1}));
   if(!random(8)) set_monsters( ({"/d/laerad/mon/shambling_mound"}),({1}));
   ::create();
   set_repop(35);
   set_terrain(RUINS);
   set_travel(RUBBLE);
   set_name("Ruins of Asgard");
   set_short("%^GREEN%^Ruins of %^CYAN%^Asgard");
   set_long("%^GREEN%^Ruins of %^CYAN%^Asgard
%^WHITE%^You are standing in the ruins of %^CYAN%^Asgard%^WHITE%^. All around you, buildings have been toppled, leaving rubble strewn about the streets. In some places, walls have been reduced to piles of tiny stones, while in others, they stand largely untouched. Here and there, the ground seems compressed, giving the only clue as to what could have caused such total destruction. Between the stones, %^GREEN%^grass%^RESET%^ and %^ORANGE%^moss %^RESET%^have begun to grow, perhaps a sign of life returning.
");
    set_property("indoors",0);
    set_property("light",2);
    set_smell("default","The air is filled with dust and %^RED%^smo%^BOLD%^%^BLACK%^ke%^RESET%^%^ORANGE%^ from the rubble.");
    set_listen("default","The city seems %^CYAN%^eerily quiet%^GREEN%^, missing the chatter of daily life.");
}

void_reset(){
   ::reset();
   if(!random(3)) set_monsters( ({"/d/laerad/mon/faith_warrior"}),({random(3)}));
   if(!random(1)) set_monsters( ({"/d/laerad/mon/shambling_mound"}),({1}));
   if(!random(2)) set_monsters( ({"/d/laerad/mon/shambling_mound"}),({1}));
   if(!random(3)) set_monsters( ({"/d/laerad/mon/shambling_mound"}),({1}));
   if(!random(4)) set_monsters( ({"/d/laerad/mon/shambling_mound"}),({1}));
   if(!random(5)) set_monsters( ({"/d/laerad/mon/shambling_mound"}),({1}));
}
