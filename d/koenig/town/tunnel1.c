#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_door("trapdoor", "/d/koenig/town/pantry.c", "trapdoor", "open_trapdoor");
  set_open("trapdoor", 0);
  set_string("trapdoor", "open", "The hinges creak loudly as you open the trapdoor.");
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Tunnel Leading Downward");
  set_long("%^BOLD%^%^BLUE%^Upon desending the stairs down through the trapdoor, you notice that the walls are of %^BOLD%^%^BLACK%^solid stone%^BOLD%^%^BLUE%^, and the stairs are carved from the same. The stairs are very large and look as if they were carved for a giant. It kind of makes you wonder what is waiting below.%^RESET%^\n");
  set_smell("default", "You smell stone, dust and something you can't quite put your finger on.");
  set_listen("default", "You hear nothing, and the silence is unnerving.");
  set_exits( ([
     "trapdoor" : "/d/koenig/town/pantry",
     "down" : "/d/koenig/town/tunnel2"
]) );
}
