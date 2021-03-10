//Barracks Template - Githyanki Fortress - LoKi - 01-02-2008


#include <std.h>
#include "../githyanki.h"

inherit CVAULT;
int items;
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
    set_name("Barracks");
    set_short("%^RESET%^%^ORANGE%^Barra%^RESET%^%^WHITE%^c%^RESET%^"+
"%^ORANGE%^ks%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^This room is obviously living quarters for the"+
" occupants of the fortress. Simple %^RESET%^%^WHITE%^bunks %^RESET%^%^ORANGE%^"+
"line the walls and in the centre of the room is a meditation area. Instead of "+
"being constructed, it has been carved directly out of %^RESET%^%^RED%^pure ro"+
"%^RESET%^%^WHITE%^c%^RESET%^%^RED%^k%^RESET%^%^ORANGE%^. The workmanship is "+
"amazing, as even though there was no construction, the surface of the %^RESET%^"+
"%^RED%^ro%^RESET%^%^WHITE%^c%^RESET%^%^RED%^k %^RESET%^%^ORANGE%^has been carved"+
" to emulate it as large tiles forming the floor, and smaller tiles decorating the"+
" wall.\n\n%^RESET%^");
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
        ({"bunks"}) : "%^RESET%^%^ORANGE%^Bunks line the walls. They are constr"+
"ucted from wood and have a single thin sheet. Some look like they have been "+
"recently used.%^RESET%^",
        ({"ceiling"}) : "%^RESET%^%^ORANGE%^the ceiling is tall, massive enough"+
" to fit even a large beast easily. You wonder why it has to be so tall%^RESET%^",
        ({"walls"}) : "%^RESET%^%^ORANGE%^The walls here are hewn directly from"+
" the rock, yet great care has been taken to carve tiles into the wall. The walls"+
" are covered in runes",
    ]));
    set_search("default","%^BOLD%^Where do you want to search?%^RESET%^");
    set_search("bunks",(:TO,"search_bunk":));
}



void reset() {
/*   int active;
   active = has_mobs();
   if(!active) {
     if(mons) mons = ([]);
     pick_critters();
   }
*/
   ::reset();
   items = 1;
   }

int search_bunk(string str) {
    if (!items) {
      tell_object(TP,"%^RESET%^%^RED%^It seems like someone has searched around "+
"here already.%^RESET%^");
      return 1;
    }
    switch(random(100)) {
      case 0..22:
      ob = new("/std/obj/coins");
      ob->set_money("gold",random(2000)+random(100));
      ob->set_money("electrum",random(200)+100);
      ob->move(ETP);
      tell_object(TP,"%^YELLOW%^You search through the bunks, collecting coins.");
      tell_room(ETP,"%^YELLOW%^"+TP->QCN+"%^YELLOW%^ collects coins from the bunks "+
"and puts them in a pile.",TP);
      break;

      case 23..40:
      ob = new("/d/common/obj/potion/healing");
      ob->set_uses(random(5)+6);
      ob->move(ETP);
      tell_object(TP,"%^RESET%^%^CYAN%^You find a kit hidden in the bunks%^RESET%^.");
      tell_room(ETP,"%^RESET%^%^CYAN%^"+TP->QCN+"%^RESET%^%^CYAN%^ pulls out a case "+
"of bottles%^RESET%^.",TP);
      break;

      case 41..70:
      ob = new("/d/magic/scroll");
      ob->set_spell(random(4)+4);
      ob->move(ETP);
      tell_object(TP,"%^RESET%^%^ORANGE%^You find a scroll tucked under a pillow%^RESET%^.");
      tell_room(ETP,"%^RESET%^%^ORANGE%^"+TP->QCN+"%^RESET%^%^ORANGE%^ pulls a scroll "+
"from under a pillow%^RESET%^.",TP);
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
