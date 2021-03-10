#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Huge Room");
  set_long("%^BOLD%^%^WHITE%^You have moved over to the nearest %^BOLD%^%^BLACK%^fireplace%^BOLD%^%^WHITE%^, and now "
           "that you are closer you notice that it is by no means small "
           "in size. There are more %^MAGENTA%^tapestries%^BOLD%^%^WHITE%^ here on the wall, and a "
           "huge %^RESET%^%^ORANGE%^table%^BOLD%^%^WHITE%^ that sits in front of this fireplace. There is "
           "another %^RESET%^%^ORANGE%^table%^BOLD%^%^WHITE%^just like it to the north in front of the "
           "other fireplace. This room could almost be pleasant and "
           "comfortable if you didn't already know who "
           "owned it, and some of the hidden %^RED%^pains%^BOLD%^%^WHITE%^ within this place.%^RESET%^\n");
  set_smell("default", "There is the pleasant smell of burning wood.");
  set_listen("default", "The only sound is the crackling of the fire.");
  set_items( ([
     "tapestries" : "There are four tapestries here. You might try looking at them individually.",
     "tapestry 1" : "%^RESET%^This tapestry is of an unknown and very bloody battle. However, you think you recognize a %^BOLD%^figure%^RESET%^ in it.",
     "figure" : "%^RESET%^Hmmm, the only thing that is familiar is the %^BOLD%^armor%^RESET%^ it wears.",
     "armor" : "It looks identical to the armor you saw earlier, to the east.",
     "tapestry 2" : "This shows a tall dark tower in the middle of a forest somewhere.",
     "tapestry 3" : "This shows two armies fighting. One is surrounded in light, and the other in darkness.",
     "tapestry 4" : "This shows a man being torn apart in the foray of a battle.",
     "table" : "This table's size is somewhat unnerving, but you do notice it is made of the same stonewood as the gates to this hellish town. It is surrounded by chairs.",
     "chairs" : "They are simple, but look somewhat comfortable."
]) );
  set_exits( ([
     "north" : "/d/koenig/town/tower14",
     "east" : "/d/koenig/town/tower12"
]) );
}
void reset()
{
  ::reset();
  if(!present("maid"))new("/d/koenig/town/mon/maid.c")->move(this_object());
}
