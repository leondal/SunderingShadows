//Prison Template - Githyanki Fortress - LoKi - 01-02-2008


#include <std.h>
#include "../githyanki.h"

inherit CVAULT;
int items;
object ob;


void pick_critters();

void create() {
    pick_critters();
    set_repop(50);
    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("no teleport",1);
    set_property("light",0);
    set_name("A Dark Prison");
    set_short("%^RESET%^%^BOLD%^%^BLACK%^A D%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^"+
"%^BLACK%^rk Pris%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^%^BLACK%^n%^RESET%^");
    set_long("%^RESET%^%^BOLD%^%^BLACK%^Less light illuminates this room in the "+
"fortress, and the %^RESET%^%^ORANGE%^f%^RESET%^%^YELLOW%^l%^RESET%^%^ORANGE%^"+
"ickering tor%^RESET%^%^YELLOW%^c%^RESET%^%^ORANGE%^hes %^RESET%^%^BOLD%^%^BLACK%^"+
"cast long shadows. The %^RESET%^%^ORANGE%^ston%^RESET%^%^RED%^e%^RESET%^%^ORANGE%^"+
"s %^RESET%^%^BOLD%^%^BLACK%^here have less workmanship, and no runes decorate them."+
" Random piles of %^RESET%^%^ORANGE%^straw %^RESET%^%^BOLD%^%^BLACK%^are scattered "+
"around the room.%^RESET%^\n\n%^RESET%^");
    set_smell("default","%^RESET%^%^RED%^It smells like excrement and sweat%^RESET%^.");
    set_listen("default","%^BLACK%^%^BOLD%^you hear heavy chains rubbing against "+
"stone%^RESET%^");
    set_items
    (([
        ({"floor", "floor tiles"}) : "%^BLACK%^%^BOLD%^The floor is solid rock that "+
"has been carved into rough representations of tiles.%^RESET%^",
        ({"torch", "torches"}) : "%^YELLOW%^Torches line the walls, offering little "+
"illumination.%^RESET%^",
        ({"straw"}) : "%^RESET%^%^ORANGE%^piles of straw litter the floor%^RESET%^",
        ({"ceiling"}) : "%^RESET%^%^ORANGE%^the ceiling is tall, massive enough"+
" to fit even a large beast easily. You wonder why it has to be so tall%^RESET%^",
        ({"walls"}) : "%^RESET%^%^ORANGE%^The walls here are carved roughly from "+
"solid stone, and someone has carved out rough representation of tiles.%^RESET%^",
    ]));
    set_search("default","%^BOLD%^Where do you want to search?%^RESET%^");
    set_search("straw",(:TO,"search_straw":));
}

void reset() {
/*
   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
*/
   ::reset();
   items = 1;
   }

int search_straw(string str) {
    if (!items) {
      tell_object(TP,"%^RESET%^%^RED%^It seems like someone has searched around "+
"here already.%^RESET%^");
      return 1;
    }
    switch(random(100)) {

      case 23..40:
      ob = new("/d/common/obj/potion/healing");
      ob->set_uses(random(5)+6);
      ob->move(ETP);
      tell_object(TP,"%^RESET%^%^CYAN%^You find a kit hidden in the straw%^RESET%^.");
      tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ pulls out a case "+
"of bottles%^RESET%^.",TP);
      break;

      default:
      tell_object(TP,"%^BLACK%^%^BOLD%^You don't find anything.%^RESET%^");
      tell_room(ETP,"%^BLACK%^%^BOLD%^"+TP->QCN+"%^BLACK%^%^BOLD%^ can't seem to find "+
"anything.%^RESET%^",TP);
      break;
      }
    items = 0;
    return 1;
}
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
({MOBS"gith_guard",MOBS"gith_hunt"}),({random(2)+1,1}) );
                   break;
         case 4..5: break;
   }
}
