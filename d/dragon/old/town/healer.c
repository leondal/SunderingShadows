#include <std.h>
#include <objects.h>
#include <money.h>

inherit HEALER;

void create() {
   ::create();
   set_light(1);
   set_indoors(1);
   set_short("Healer of Sanctuary");
   set_long(
@DESC
%^BOLD%^%^BLUE%^
This room shows signs of recent repair.  Sturdy wooden beams support
the damaged floor above, and most of the old floorboards have been
replaced.  Chunks of rubble that once constituted a fireplace within
the north wall, have been piled against a rebuilt section of wall.
The room is unfurnished except for the long table in the center.
There is a %^RED%^list%^BLUE%^ beside the table with some writing. There doesn't
appear to be anyone around to help serve you however.
DESC
   );
   set_smell("default", "The room has a distinct musty odor to it.");
   set_exits(([
      "up" : "/d/dragon/town/church"
   ] ));
   set_cl_price(100);
   set_cs_price(200);
   set_cc_price(300);
   set_np_price(400);
   set_cb_price(400);
   set_bp_price(500);
}

