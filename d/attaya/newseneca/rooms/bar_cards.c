//bar_cards - pokiir room for new Seneca ~Circe~ 11/19/07
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_travel(PAVED_ROAD);
   set_terrain(WOOD_BUILDING);
   set_name("Back Room of the Salt Merchant, Seneca");
   set_short("Back Room of the Salt Merchant, Seneca");
   set_property("indoors",1);
   set_property("light",3);
   set_long("This room is somewhat cramped, and the %^ORANGE%^wooden "+
      "card table %^RESET%^in the center dominates most of the space.  "+
      "Several %^BOLD%^wicker chairs %^RESET%^are crowded around it, "+
      "giving players a place to sit - if not a very large space to "+
      "relax in.  The walls here are unadorned, save by a %^BOLD%^"+
      "%^BLACK%^spiderweb %^RESET%^or two.  A narrow %^ORANGE%^door "+
      "%^RESET%^in the western wall looks to lead into a %^BOLD%^"+
      "storage room%^RESET%^.\n");
   set_items(([
      ({"chair","chairs","wicker chairs"}) : "The chairs gathered around the card table "+
         "are made of %^BOLD%^wicker %^RESET%^and have arms.  While "+
         "they may seem flimsy, the wicker gives them the benefit of "+
         "being resilient to breaking from things like drunken players "+
         "throwing chairs after losing a game.",
      ({"wall","walls"}) : "The walls here are painted white, or were at "+
         "one time.  They look a little dingy now and have no ornamentation.",
      "floor" : "A bit of the %^YELLOW%^g%^WHITE%^o%^RESET%^l"+
         "%^YELLOW%^d%^WHITE%^e%^RESET%^n sand has been dragged in here.",
      ({"spiderweb","spiderwebs"}) : "%^BOLD%^%^BLACK%^In a few corners "+
         "near the ceiling are several large spiderwebs.%^RESET%^"
   ]));
   set_smell("default","The stench of unwashed bodies and large amounts of alcohol wafts into the room.");
   set_listen("default","The raucous laughter from the bar is muffled by the door.");
   set_exits(([
      "north" : ROOMS"bar",
      "west" : ROOMS"bar_storage"
   ]));
   set_door("door","/d/attaya/newseneca/rooms/bar","north",0);
   set_door_description("door","The door in the northern wall leads "+
      "to the bar.  It has been painted the same dingy white as the walls.");
   set_door("storage door","/d/attaya/newseneca/rooms/bar_storage","west",0);
   set_door_description("storage door","Nearly blending in, the door on the "+
      "western wall is narrow and the same color as the walls.");
}

void reset(){
  object ob;
  ::reset();
  if(!present("maddox",TO)){
  ob=new(MON"maddox");
  ob->set_speed(0);
  ob->move(TO);
  }
}
