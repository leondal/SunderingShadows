#include <std.h>
#include <move.h>
#include "../tecqumin.h"


inherit TECBASE + "jung_base.c";
string pathdir;

void create() {
  setup_mobs(); //This function is defined in the jung_base.c base file
  report ("About to run create function");
   ::create();
  add_item( ({"hut", "huts", "small hut", "small stone hut", 
    "small huts", "small stone huts"}), 
    "The huts are all in ruins. Most of the walls are tumbled"
    +" down almost to the ground, and nothing remains of the"
    +" roofs. The general design appears to have been circular,"
    +" with walls sloping somewhat outwards at the base.");

  add_item( ({"path", "overgrown path"}), "The jungle has mostly"
    +" grown back over the %^ORANGE%^path%^RESET%^, but just"
    +" enough clearance remains to see where it once ran, and"
    +" occasional patches of %^ORANGE%^gravel surface%^RESET%^"
    +" and stone edging remain to give a clue to its original"
    +" construction.");
  set_repop(100);
}
/*
void reset(){
  int active;
  ::reset(); 
  report ("About to run has_mobs function");
  active = has_mobs();  
  if(!active) {  
     clear_mobs();  // this clears the array. defined in jung_base.c
     setup_mobs(); //This function is defined in the jung_base.c base file
  }
  report ("About to run reset function");


}*/

string short_desc(){
  return "%^ORANGE%^Residential district of a lost city in the"
    +" %^GREEN%^jungle%^RESET%^";
}




string long_desc(){

return base_desc() + "There are%^RESET%^ ruins%^GREEN%^ in the"
  +" j%^BOLD%^%^GREEN%^u%^RESET%^%^GREEN%^ng%^ORANGE%^l%^GREEN%^e"
  +" here, that seem like a%^RESET%^ residential district"
  +" %^GREEN%^of a long deserted city. An overgrown path heads "
  + pathdir + " through the jungle, and the remains of numerous"
  +" %^RESET%^small stone huts%^GREEN%^ can be seen to either side"
  +" of it.";
}

