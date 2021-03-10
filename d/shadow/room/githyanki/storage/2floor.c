//Second Floor Template - Githyanki Fortress - LoKi - 12-02-2008


#include <std.h>
#include "../githyanki.h"

inherit CVAULT;

object ob;
void pick_critters();



void create() {
    pick_critters();
    set_repop(35);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",2);
    set_property("no teleport",1);
    set_name("Hall of a Fortress");
    set_short("%^RESET%^%^ORANGE%^ha%^RESET%^%^WHITE%^l%^RESET%^%^"+
"ORANGE%^l of a fo%^RESET%^%^WHITE%^r%^RESET%^%^ORANGE%^tress%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^The hallway here is immense, the "+
"ceiling reaching at least fifty feet in the air. The hall is also at least "+
"twenty feet across. %^RESET%^%^WHITE%^Large iron hewn lanterns %^RESET%^%^"+
"BOLD%^%^BLACK%^hang from the high vaulted ceiling casting %^RESET%^%^ORANGE%^"+
"d%^RESET%^%^BOLD%^%^RED%^i%^RESET%^%^ORANGE%^m ligh%^RESET%^%^BOLD%^%^RED%^t"+
"%^RESET%^%^BOLD%^%^BLACK%^. The walls are covered in rich %^RESET%^%^MAGENTA%^"+
"tapestries %^RESET%^%^BOLD%^%^BLACK%^and the floor is carved with excellent "+
"detail into %^RESET%^%^ORANGE%^large tiles.\n\n%^RESET%^");
    set_smell("default","%^RESET%^%^ORANGE%^You smell straw and wood.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^You hear the echos of.. wings?%^RESET%^");

    set_items
    (([
        ({"tiles", "floor"}) : "%^RESET%^%^ORANGE%^The ground here is hewn"+
" directly from the rock, yet the craftsmen took the time to carve specific floor"+
" tiles to make it look like a tiled floor%^RESET%^",
        ({"torch", "torches"}) : "%^BLACK%^%^BOLD%^Large iron hewn lanterns hang "+
"from the high vaulted ceiling.%^RESET%^",
        ({"tapestry", "tapestries"}) : "%^MAGENTA%^Tapestries depicting various "+
"Githyanki victories over either Illithids or Githzerai%^RESET%^",
        ({"ceiling"}) : "%^RESET%^%^ORANGE%^the ceiling is tall, massive enough"+
" to fit even a large beast easily. You wonder why it has to be so tall%^RESET%^",
        ({"walls"}) : "%^RESET%^%^ORANGE%^The walls here are covered in tapestries",
    ]));
}
/*
void reset() {
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
   ::reset();

   }
*/

void pick_critters(){
   switch(random(6)){
         case 0:   set_monsters(
({MOBS"gith_priest",MOBS"gith_hunt"}),({random(2),random(2)}) );
                   break;
         case 1:   set_monsters(
({MOBS"gith_guard",MOBS"gith_hunt"}),({random(2),random(1)}) );
                   break;
         case 2:   set_monsters(
({MOBS"gith_hunt",MOBS"gith_priest"}),({1,random(1)+1,random(2)}) );
                   break;
         case 3:   set_monsters(
({MOBS"gith_guard",MOBS"gith_priest"}),({random(1),1}) );
                   break;
         case 4..5: break;
   }
}
