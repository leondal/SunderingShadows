
#include <std.h>
#include "../githyanki.h"

inherit VAULT;
int items;
object ob;




void create() {



    ::create();
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_property("light",0);
    set_name("A Dark Prison Cell");
    set_short("%^RESET%^%^BOLD%^%^BLACK%^A D%^RESET%^%^WHITE%^a%^RESET%^%^BOLD%^"+
"%^BLACK%^rk Pris%^RESET%^%^WHITE%^o%^RESET%^%^BOLD%^%^BLACK%^n Cell%^RESET%^");
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

 set_exits(([
      "north" : ROOMS"1_19",
   ]));

    set_door("iron door",ROOMS"1_19","north",OBJ"gith_key");
    set_locked("iron door", 1);
    lock_difficulty("iron door",-80, "lock");
    set_door_description("iron door","%^BLACK%^%^BOLD%^This door has been wrought "+
"from iron and looks very secure. %^RESET%^Arcane runes%^BLACK%^%^BOLD%^ have been "+
"carved into it around the hinges and around the lock%^RESET%^");
    set_string("ornate door", "open", "%^BLACK%^%^BOLD%^The hinges squeel as the door opens.%^RESET%^");
    set_string("ornate door", "close", "%^BLACK%^%^BOLD%^The door closes with a >THUD<.%^RESET%^");

}

void reset() {
   ::reset();
   if(!present("illithid"))
      new(MOBS"illithid.c")->move(TO);
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

