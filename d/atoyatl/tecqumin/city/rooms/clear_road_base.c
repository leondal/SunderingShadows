#include <std.h>
#include <move.h>
#include "../../tecqumin.h"


inherit JUNG_ROOM + "jung_base.c";

string plaza_dir;

void create() {
  ::create();
  set_long( (:TO, "long_desc" :) );
  set_name("A road through the jungle");
  set_short("A %^ORANGE%^road through the %^BOLD%^%^GREEN%^ju%^BOLD%^"
    +"%^GREEN%^n%^RESET%^%^GREEN%^gl%^BOLD%^%^GREEN%^e");
  set_items( ([({"causeway", "stone causeway", "broad stone causeway", "road"}):
    "The %^ORANGE%^causeway %^RESET%^is clearly ancient and long abandoned,"
   +" but the section here is in relatively good condition. Several metres"
   +" across, it is constructed from large slabs of gray stone that are mostly"
   +" intact, even though the %^BOLD%^%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng"
   +"%^RESET%^%^GREEN%^l%^BOLD%^e f%^RESET%^%^GREEN%^o%^BOLD%^l%^RESET%^"
   +"%^GREEN%^i%^BOLD%^%^BLACK%^a%^GREEN%^g%^RESET%^%^GREEN%^e%^RESET%^ has"
   +" grown right up to the edges, and"
   +" %^BOLD%^%^GREEN%^pl%^RESET%^%^GREEN%^a%^BOLD%^nts %^RESET%^spring forth"
   +" from the cracks between the blocks.",
     ({"plaza", "stone plaza", "grand plaza", "grand stone plaza"}) : 
    "The stone flagged plaza opens up an enormous space in the %^BOLD%^"
   +"%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^ng%^RESET%^%^GREEN%^l%^BOLD%^e"
   +"%^RESET%^. The %^BOLD%^%^CYAN%^sky%^RESET%^ is open above it, allowing"
   +" you to see the ziggurat and the other building facing each other to the"
   +" south and north side of the plaza respectively.",
      ({"ziggurat", "stone ziggurat", "enormous stone ziggurat", "enormous ziggurat"}):
    "The ziggurat takes the form of a huge, stepped stone pyramid, rising"
   +" above the tallest trees of the jungle. The main tiers are built from"
   +" massive blocks of stone, each many metres high. A broad central stairway"
   +" leads up toward some kind of ceremonial platform at the top.",
     ({"building", "other building", "striking building", "building to the north",
       "north building", "northern building", "jaguar", "stone jaguar", 
       "other building", "great stone jaguar"}) :
    "You can't see all of the building from here, but it is clear that the"
   +" entryway is in the form of the head of a %^ORANGE%^j%^BOLD%^%^BLACK%^a"
   +"%^RESET%^%^ORANGE%^g%^BOLD%^u%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^,"
   +" with the door situated inside its mouth, which is open in a snarl or roar."
   +" You can also see a low tower in the form of a jaguar's paw, on each side of"
   +" the entryway. More of the jaguar's body lies behind all of this.",
    ({"platform", "ceremonial platform", "stairway", "central stairway", 
      "broad stairway", "broad central stairway", "paw", "head", "mouth", 
      "tower", "low tower"}) : 
      "You'll need to get closer to see that properly." ]) );
  plaza_dir = "";
}


string long_desc(){
  string desc;
  desc = base_desc();
  desc += "\n %^RESET%^A broad stone %^ORANGE%^causeway%^RESET%^"
    +" leads east-west through the %^BOLD%^%^GREEN%^ju%^BOLD%^%^GREEN%^n"
    +"%^RESET%^%^GREEN%^gl%^BOLD%^%^GREEN%^e %^RESET%^here. To the "
    + plaza_dir + ", the %^ORANGE%^causeway%^RESET%^ leads to a grand"
    +" stone plaza. South of the plaza, an enormous stone ziggurat rises"
    +" high above the %^BOLD%^%^GREEN%^ju%^BOLD%^%^GREEN%^n%^RESET%^"
    +"%^GREEN%^gl%^BOLD%^%^GREEN%^e c%^RESET%^%^GREEN%^a%^BOLD%^n"
    +"%^RESET%^%^GREEN%^o%^BOLD%^py%^RESET%^. Facing it on the north of the"
    +" plaza is a less elevated but still striking building in the form of"
    +" a great stone %^ORANGE%^j%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^g"
    +"%^YELLOW%^u%^BOLD%^%^BLACK%^a%^RESET%^%^ORANGE%^r%^RESET%^.\n";
  return desc;
}

