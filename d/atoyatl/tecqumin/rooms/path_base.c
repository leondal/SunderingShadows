#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit ROOM;

string long_desc();

void create() {
  ::create();
  set_indoors(0);
  set_property("light", 2);
  set_terrain(CITY);
  set_travel(DIRT_ROAD );
  set_name("An ancient dirt path");
  set_short("%^ORANGE%^On an ancient dirt path%^RESET%^");
  set_long( (:TO, "long_desc":) );
  set_items(([ ({"pyramid"}) : " The pyramid looms over the whole area of the city ruins."
   +" It is made of huge sections of grey stone, and rises in a series of steps, giving"
   +" it a jagged outline. There appears to be a stairway leading up the centre.",
     ({"structure", "cat", "cat's head"}) : "The strange structure appears to be a"
    +" cat's head and forequarters rising out of the earth, in the manner of a"
    +" zombie crawling from the grave. The cat's mouth is open wide, as if in a"
    +" snarl." ]));
  set_smell("default","The air is dryer here than in the surrounding jungle and carries"
   +" faint floral and other plant aromas.");
  set_listen("default","You can hear some bird calls and insect life buzzing in the"
   +" background.");
}

long_desc(){
  return "The dirt path is in terrble condition; rutted and pockmarked, overgrown with"
  +" %^GREEN%^plants%^RESET%^ and sometimes almost indistinguishable from the general"
  +" scrub that surrounds it. It is clear that it has not been used or maintained in an"
  +" age. ";
}

void GoJungle(){
  tell_object(TP, "You shoulder your way between the trees into the %^BOLD%^%^GREEN%^j"
   +"%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e%^RESET%^.");
  tell_room(TO, TPQCN + " shoulders " + TP->QCN + " way between the trees into the %^BOLD%^"
   +"%^GREEN%^j%^RESET%^%^GREEN%^u%^BOLD%^%^GREEN%^ng%^RESET%^%^GREEN%^l%^BOLD%^%^GREEN%^e"
   +"%^RESET%^.", TP);
  return 1;
}

void GoSwamp(){
  tell_object(TP, "You trudge your way into the %^GREEN%^swamp%^RESET%^. Your feet squelch"
   +" as the %^ORANGE%^muddy ground%^RESET%^ sucks at your soles.");
  tell_room(TO, TPQCN + " trudges into the %^GREEN%^swamp%^RESET%^. " + TP->QCN + " feet"
  +" squelch as the %^ORANGE%^muddy ground%^RESET%^ sucks at " + TP->QCN + " soles.", TP);
  return 1;
}