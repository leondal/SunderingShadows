//Stables Template - Githyanki Fortress - LoKi - 12-02-2008


#include <std.h>
#include "../githyanki.h"

inherit CVAULT;

object ob;
void pick_critters();

void init() {
    ::init();
}

void create() {
    pick_critters();
    set_repop(35);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",0);
    set_property("no teleport",1);
    set_property("light",2);
    set_name("Giant Stables");
    set_short("%^RESET%^%^ORANGE%^Gia%^RESET%^%^BOLD%^%^BLACK%^n%^RESET%^%^ORANGE%^"+
"t Sta%^RESET%^%^WHITE%^b%^RESET%^%^ORANGE%^les%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This immense area is wide open, with just %^RESET%^"+
"%^WHITE%^pillars %^RESET%^%^ORANGE%^holding up the vast vaulted ceiling. The ceiling"+
" here reaches sixty feet, and there are several giant %^RESET%^%^WHITE%^portals "+
"%^RESET%^%^ORANGE%^cut out of the it, to provide %^RESET%^%^BOLD%^%^BLUE%^op%^RESET%^"+
"%^CYAN%^e%^RESET%^%^BOLD%^%^BLUE%^n acc%^RESET%^%^CYAN%^e%^RESET%^%^BOLD%^%^BLUE%^ss "+
"to the s%^RESET%^%^CYAN%^k%^RESET%^%^BOLD%^%^BLUE%^y%^RESET%^%^ORANGE%^. The floor is "+
"covered in a thick layer of %^RESET%^%^YELLOW%^straw%^RESET%^%^ORANGE%^, and racks of "+
"giant leather saddles line the walls. Each stall is huge, easily large enough to park a"+
" large wagon.\n\n %^RESET%^");
    set_smell("default","%^RESET%^%^ORANGE%^You smell straw and wood.%^RESET%^");
    set_listen("default","%^BLACK%^%^BOLD%^The wind whips into the room, drowning out most sound?%^RESET%^");

    set_items
    (([
        ({"stalls","stables"}) : "%^RESET%^%^ORANGE%^The stalls here are huge, capable "+
"of holding the largest of beasts%^RESET%^",
        ({"tiles", "floor"}) : "%^RESET%^%^ORANGE%^The ground here is hewn"+
"directly from the rock, yet the craftsmen took the time to carve specific floor"+
"tiles to make it look like a tiled floor%^RESET%^",
        ({"holes", "portals"}) : "%^BLACK%^%^BOLD%^Giant holes are cut into the "+
"ceiling, showing the sky.%^RESET%^",
        ({"racks", "saddles"}) : "%^RESET%^%^ORANGE%^racks holding giant saddles and tack"+
" line the walls. Each saddle is larger then you could ever carry though",
        ({"ceiling"}) : "%^RESET%^%^ORANGE%^the ceiling is tall, massive enough"+
" to fit even a large beast easily. Giant holes are cut into it.%^RESET%^",
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
