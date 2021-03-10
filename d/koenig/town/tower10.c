#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Hallway");
  set_long("%^BOLD%^%^WHITE%^Well you are now standing before a set of %^RESET%^%^ORANGE%^doors%^BOLD%^%^WHITE%^ at the end of the hall. Oh my, your stomach is rumbling like %^MAGENTA%^crazy%^BOLD%^%^WHITE%^. Those sweet smells are coming from behind those doors! Hmmm, should you or shouldn't you enter here? My, my... that food sure is %^GREEN%^tempting%^BOLD%^%^WHITE%^...%^RESET%^\n");
  set_smell("default", "Your nose thinks you've hit the mother load...food wise!");
  set_listen("default", "All that racket you have been hearing is coming from behind those doors.");
  set_exits( ([
     "south" : "/d/koenig/town/tower9",
     "enter" : "/d/koenig/town/kitchen1"
]) );
}
