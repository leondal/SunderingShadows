#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("A Lovely Meadow");
  set_long("%^RESET%^%^GREEN%^You find yourself standing in a small %^BOLD%^meadow%^RESET%^%^GREEN%^ with a %^CYAN%^waterfall%^RESET%^%^GREEN%^, just like in the painting. You realize with a shock that this is indeed the painting when you see before you the %^BOLD%^%^WHITE%^unicorn%^RESET%^%^GREEN%^. Oh boy.%^RESET%^\n");
  set_smell("default", "You can smell fresh air and the sweet fragrance of flowers.");
  set_listen("default", "You can hear birds singing sweetly in the distance.");
  set_exits( ([
     "out" : "/d/koenig/town/house8.c"
]) );
}
void reset()
{
  ::reset();
  if(!present("unicorn"))
{
new("/d/koenig/town/mon/unicorn.c")->move(this_object());
  }
}
