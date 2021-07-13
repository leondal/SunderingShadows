#include <std.h>
#include "../defs.h"
inherit INH+"path";

void create(){ 
   ::create();
   set_long("%^BOLD%^Cavern entrance%^RESET%^\n"
"The %^ORANGE%^rough trail%^RESET%^ comes to an end here, at the wide mouth of a cavern in the side of the "
"mountain.  The rocky outline of the hole is is lined in various %^BLACK%^%^BOLD%^slashes%^RESET%^, %^RED%^"
"splatters%^RESET%^ and %^ORANGE%^handprints%^RESET%^ of paint, that may or may not have some meaning to "
"them.  The stench of dampness and decay emanates from the cave opening, carried on the air along with the "
"sounds of chattering, screeches, grumbles, and other indiscernable sounds.  The path itself heads back to "
"the west, through the crushed and broken remains of the surrounding %^GREEN%^forest%^RESET%^.\n");
   set("night long","%^BOLD%^Cavern entrance%^RESET%^\n"
"The %^ORANGE%^rough trail%^RESET%^ comes to an end here, at the wide mouth of a cavern in the side of the "
"mountain, which is difficult to see in the darkness of the night.  The rocky outline of the hole is is "
"lined in various %^BLACK%^%^BOLD%^slashes%^RESET%^, %^RED%^splatters%^RESET%^ and %^ORANGE%^handprints"
"%^RESET%^ of paint, that may or may not have some meaning to them.  The stench of dampness and decay "
"emanates from the cave opening, carried on the air along with the sounds of chattering, screeches, "
"grumbles, and other indiscernable sounds.  The path itself heads back to the south, shrouded in%^BLUE%^ "
"shadows%^RESET%^ through the crushed and broken remains of the surrounding %^GREEN%^forest%^RESET%^.\n");

   set_exits(([
     "west":ROOMS"path6",
     "cavern":ROOMS"cavern1",
   ]));
   add_item(({"cave","cavern","hole"}),"A wide cavern opens into the side of the mountain here, lined in "
"markings and handprints of paint.  A sickly odor of dampness and decay is carried forth on the air from "
"it.");
   add_item(({"paint","splatters","slashes","handprints","markings"}),"Various markings of paint outline "
"the cavern in the mountainside.  They seem almost like they might hold a meaning, if you could read them.");
   set_pre_exit_functions(({"cavern",}),({"go_past",}));
}

void init() {
   ::init();
   add_action("read_fun","read");
}

int read_fun(string str) {
   string race, subrace;
   race = (string)TP->query_race();
   subrace = (string)TP->query("subrace");
   if(!str) return 0;
   if(str != "paint" && str != "splatters" && str != "slashes" && str != "handprints" && str != "markings")
     return 0;
   if(race == "bugbear" || race == "half-drow" || race == "goblin" || race == "gnoll" || race == "half-ogre" || race == "half-orc" || race == "hobgoblin" || race == "kobold" || race == "ogre" || race == "ogre-mage" || race == "drow" || race == "orc" || (race == "dwarf" && subrace == "gray dwarf")) {
     tell_object(TP,"%^RED%^Muul'daan, welkome all yous to da hole!%^RESET%^");
     return 1;
   }
   tell_object(TP,"You struggle to decipher a meaning behind the painted markings, but you can't make sense "
"of any of it.");
   return 1;
}

void reset(){
   ::reset();
   if(!present("bugbear guard")) new(MON"guard1")->move(TO);
   if(!present("bugbear guard 2")) new(MON"guard1")->move(TO);
   if(!present("hobgoblin guard")) new(MON"guard2")->move(TO);
}

int go_past(){
   string race, subrace;
   race = (string)TP->query_race();
   subrace = (string)TP->query("subrace");
   if(avatarp(TP)) return 1;
   if(TP->query_invis()) return 1;
   if(race == "beastman" || race == "elf" || (race == "dwarf" && subrace != "gray dwarf") || race == "gnome" || race == "halfling" || race == "firbolg" || race == "voadkyn" || race == "wemic") {
     if(present("guard")) {
       tell_object(TP,"The guard growls and blocks your way forward, waving his weapon menancingly.");
       tell_room(ETP,"The guard growls and blocks "+TP->QCN+" when "+TP->QS+" attempts to move past.",TP);
       return 0;
     }
   }
   return 1;
}
