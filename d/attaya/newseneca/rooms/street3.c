//street3 - Circe 11/22/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit AZUL;

void create(){
   ::create();
   set_long(::query_long()+"To the south is a magnificent %^ORANGE%^"+
      "wooden structure %^RESET%^with a sloped %^CYAN%^glass-paneled "+
      "%^RESET%^roof.  A small sign above the door declares this the "+
      "%^YELLOW%^Bank of Seneca%^RESET%^.\n");
   set_exits(([
      "west" : ROOMS"street2",
      "east" : ROOMS"street4",
      "south" : ROOMS"bank"
   ]));
   add_item("bank","%^ORANGE%^The wooden building to the south reaches "+
      "two stories.  The roof of the building is a series of alternating "+
      "glass and wooden panes that would allow a good view of the sky.");
   add_item("structure","%^ORANGE%^The wooden building to the south reaches "+
      "two stories.  The roof of the building is a series of alternating "+
      "glass and wooden panes that would allow a good view of the sky.");
}