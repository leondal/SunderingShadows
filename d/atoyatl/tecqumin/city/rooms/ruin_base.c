#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit JUNG_ROOM + "jung_base.c";
string pathdir;

void create() {
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
}


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

