#include <std.h>
#include "../defs.h"
inherit INH+"town";

void create(){ 
   ::create();
   set_long("%^BOLD%^A dark cavern%^RESET%^\n"
"The roof of this dark cavern arcs far above you, lost from view in the cave's %^BLACK%^%^BOLD%^shadows"
"%^RESET%^.  The walls are made of dull stone, still rough and jagged as though naturally formed.  Piles of "
"%^ORANGE%^trash%^RESET%^ and %^BLUE%^debris%^RESET%^ cover nearly the entire ground, where various "
"creatures have obviously taken up residence amidst the squalour.  Through the mess, a rough pathway has "
"been cleared, revealing enough stone floor to navigate around the area.  A few little %^ORANGE%^shanties "
"%^RESET%^have been set up in the area, though they're merely a few pieces of scavenged wood, cloth and "
"metal, leaning together in vague semblances of structure.  Within the southwest wall is a large opening, "
"leading out of the cavern.\n");

   set_exits(([
     "north":ROOMS"cavern2",
     "east":ROOMS"cavern10",
     "out":ROOMS"path7",
   ]));
   set_pre_exit_functions(({"east","north"}),({"go_past","go_past"}));
}

void reset(){
   ::reset();
   if(!present("hobgoblin guard")) new(MON"guard2")->move(TO);
   if(!present("ogre guard")) new(MON"guard3")->move(TO);
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
