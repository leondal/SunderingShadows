//First Floor Template - Githyanki Fortress - LoKi - 01-02-2008


#include <std.h>
#include "../githyanki.h"

inherit CVAULT;
int lit;
object ob;
void pick_critters();

void init() {
    ::init();
    add_action("check_light", "check");
}

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
    set_long("%^RESET%^%^ORANGE%^This hallway is wide, and the"+
" ceiling tall. Instead of being constructed, it has been carved directly"+
" out of %^RESET%^%^RED%^pure ro%^RESET%^%^WHITE%^c%^RESET%^%^RED%^k"+
"%^RESET%^%^ORANGE%^. The workmanship is amazing, as even though there "+
"was no construction, the surface of the %^RESET%^%^RED%^ro%^RESET%^%^"+
"WHITE%^c%^RESET%^%^RED%^k%^RESET%^%^ORANGE%^ has been carved to emulate "+
"it as large tiles forming the floor, and smaller tiles decorating the wall."+
" The entire surface of the wall is covered with runes. And %^BLACK%^"+
"%^BOLD%^torches%^RESET%^%^ORANGE%^ are set at regular intervals.\n\n%^RESET%^");
    set_smell("default","You cant quite put your finger on what that smell is.");
    set_listen("default","You hear soft whispers...");
    set_items
    (([
        ({"floor", "floor tiles"}) : "%^RESET%^%^ORANGE%^The ground here is hewn"+
" directly from the rock, yet the craftsmen took the time to carve specific floor"+
" tiles to make it look like a tiled floor%^RESET%^",
        ({"torch", "torches"}) : "%^BLACK%^%^BOLD%^Torches line the halls here "+
"and provide some illumination. You should check them to see if they are lit%^RESET%^",
        ({"rune", "runes"}) : "%^BLACK%^%^BOLD%^The runes along this wall are "+
"arranged in a circle. However no matter how long you look at them, they dont "+
"make any sense%^RESET%^",
        ({"ceiling"}) : "%^RESET%^%^ORANGE%^the ceiling is tall, massive enough"+
" to fit even a large beast easily. You wonder why it has to be so tall%^RESET%^",
        ({"walls"}) : "%^RESET%^%^ORANGE%^The walls here are hewn directly from"+
" the rock, yet great care has been taken to carve tiles into the wall. The walls"+
" are covered in runes",
    ]));
    lit = 1;
}

int check_light(){
    if (lit==1){
        tell_object(TP,"%^YELLOW%^The torches are lit, and cast a flickering glow on the room%^RESET%^");
    }
    else
        tell_object(TP,"%^BLACK%^%^BOLD%^Strangely, the torches here are not lit. Perhaps you can light them.%^RESET%^");
    
return 1;
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
({MOBS"gith_guard",MOBS"gith_hunt"}),({random(2),random(1)}) );
                   break;
         case 1:   set_monsters(
({MOBS"gith_guard",MOBS"gith_hunt"}),({random(2),random(1)}) );
                   break;
         case 2:   set_monsters(
({MOBS"gith_hunt",MOBS"gith_hunt"}),({1,random(1)+1,random(2)}) );
                   break;
         case 3:   set_monsters(
({MOBS"gith_guard",MOBS"gith_hunt"}),({0,1}) );
                   break;
         case 4..5: break;
   }
}
