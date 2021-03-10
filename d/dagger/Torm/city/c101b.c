#include <std.h>
#include "../tormdefs.h"
inherit "/std/church";
void create()
  {
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("indoors",1);
   set_short("An extravagant church in Torm");
  set_long(
   "This is an extravagant but obviously unused church in the city of Torm\n"
   "  This church looks well cared for but seems small for a city of this size, in fact it seems pretty much deserted even for its capacity."
    "  The altar doesn't carry any symbol and you realize this temple is probably just for the visitors of the city to worship their gods while the citizens of Torm go to their own god's temple."
   "  There are no pictures or decorations of any kind, really. A few candles are lit along the walls for light and there are some incense holders that have incense burning in them."
 );
   set_smell("default","A musky scent from the incense fills the room.");
   set_listen("default","Everything is peacefully quiet.");
   set_items(([
   "candles" : "There are a few thick candles along the walls that have been lit to help provide the room with light.",
   "incense holders" : "There are a few iron incense holders in the shape or mermaids.",
   "incense" : "There are two incense sticks that are slowly burning and filling the room with a rather musky smell.",
   "altar" : "There is a very simple stone altar in the center of the room. It isn't dedicated to any god, so a cleric of any faith may pray before their own god there if they wish.",
   ]));
  set_exits(([
  "west":TCITY+"c101",
  ]));
}
