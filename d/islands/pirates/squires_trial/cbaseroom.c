#include <std.h>
#include "squires_trial.h"

inherit CROOM;

void create(){
  
  ::create();
  set_terrain(BUILT_TUNNEL);
  set_travel(BACK_ALLEY);
  set_property("indoors",1);
  set_property("no sticks",1);
  set_property("light",-2);
  
  set_short("A carved tunnel");
  set_items( ([  ({"wall","walls","stone"})   : "The walls are grey cut " +
                                        "stone, with black marbling."]) );
  set_smell("default","The air is stale.");
  set_listen("default","No sound disturbs the air.");
  set_search("default","Nothing of note here, the area is quite clear.");
}

string stonedesc(){
  return "%^RESET%^%^WHITE%^The walls are light grey st%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^ne marbled with thin v%^BOLD%^%^BLACK%^ei%^RESET%^%^WHITE%^ns of %^BOLD%^%^BLACK%^bl%^RESET%^%^WHITE%^a%^BOLD%^%^BLACK%^ck%^RESET%^%^WHITE%^.  The craftsmanship of the walls is flawless; it must have taken years to complete.";
}

string darkhall(){
  return "%^BOLD%^%^BLACK%^The darkness here is complete, with no light sources in line of sight.";
}

string marbledstone(){
  return "%^RESET%^%^WHITE%^ma%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^b%^BOLD%^%^BLACK%^l%^RESET%^%^WHITE%^ed st%^BOLD%^%^BLACK%^o%^RESET%^%^WHITE%^ne";
}

string stonedamage(){
  return "The scratches are immense, each %^RESET%^%^RED%^gouge %^RESET%^%^WHITE%^is at least three inches wide and an inch deep.  The spread is at least a foot across, and surrounded by c%^BOLD%^%^BLACK%^r%^RESET%^%^WHITE%^ac%^BOLD%^%^BLACK%^k%^RESET%^%^WHITE%^ed stone, as if the stone was struck with immense %^BOLD%^%^RED%^force%^RESET%^%^WHITE%^.";
}

string scratchsearch(){
  tell_object(TP,"One of the cracks contains a small chip of %^RESET%^%^ORANGE%^brown stone%^RESET%^%^WHITE%^, mismatching the surroundings.");
  return "";
}

string specialscratchsearch(){
  tell_object(TP,"One of the cracks contains a small chip of %^RESET%^%^ORANGE%^brown stone%^RESET%^%^WHITE%^, mismatching the surroundings.  The wall is cracked badly enough that you think you might be able to get through!");
  return "";
}

