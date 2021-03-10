//estreet21 - Circe 11/23/07 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit LILA;

void create(){
   ::create();
   set_long(::query_long()+"To the west is the wall of a plain "+
      "%^ORANGE%^wooden building %^RESET%^that seems to be a stable, "+
      "though there is no entrance here.  Just south of here, you can "+
      "see the junction of %^MAGENTA%^Lila Way %^RESET%^and %^GREEN%^"+
      "Verde Esplanade%^RESET%^.\n");
   set_exits(([
      "north" : ROOMS"estreet20",
      "south" : ROOMS"estreet22"
   ]));
   add_item("building","%^ORANGE%^The plain wall to the west is made "+
      "of wood and seems simple, but sturdy.  Judging from the sounds "+
      "coming from within, the building is probably a stable.%^RESET%^");
}