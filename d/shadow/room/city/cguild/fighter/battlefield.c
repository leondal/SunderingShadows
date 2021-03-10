#include <std.h>
inherit ROOM;

void create() {
   ::create();
   set_light(2);
   set_indoors(0);
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_short("Field of Battle");
   set_long(
      "This field is the site of guild tournaments, tutoring, and "+
      "private challenges.  The walls run around the field in a large "+
      "circle and cuts off at the open ended ceiling.  Along the walls, "+
      "seats are set up for spectators of tournaments, but they are "+
      "used for people looking for a quiet place to sit when no "+
      "activities are scheduled.  The field is a large rectangular dirt "+
      "patch.  The edges are outlined by powder and this is probably "+
      "used for boundaries during events.  Beyond the boundaries, grass "+
      "grows in healthy amounts and is taken care of by someone."
   );
   set_smell("default","%^RESET%^%^GREEN%^There is no particular smell.%^RESET%^");
   set_listen("default","%^RESET%^%^BLUE%^It is quiet.");
   set_items(([
      "field" : "The field is relatively new and has not seen much use yet.",
   ]));
   set_exits(([
      "hall" : "/d/shadow/room/city/cguild/fighter/fighter.c"
   ]));
}
