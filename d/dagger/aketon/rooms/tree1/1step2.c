#include "/d/dagger/aketon/short.h"

inherit GENERATOR;

void create() {
   ::create();
   set_short("Steps around the giant tree");
   set_long("%^GREEN%^Steps around the giant tree%^RESET%^
You are on the steps around the giant tree. These steps leads you to the "
      "elven civilization hidden deep inside the Kilkean forest in the "
      "Dagger area, the elven city of Aketon. The steps continue circling "
      "up and down the huge tree trunk.");
   set_items( (["steps":"These steps twist around the giant tree trunk.",
      ({"forest","kilkean"}):"The dense Kilkean forest is all around you.",
      "city":"You can see shadows moving around upon the tree branches.",
      "trunk":"This is a party of the huge tree body."]) );
   set_exits( (["up":RPATH1+"1step3",
      "down":RPATH1+"1step1"]) );
}
