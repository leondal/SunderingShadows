#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("Inside the Painting");
  set_long("%^RESET%^%^CYAN%^You have entered the painting and are now in a place of nothingness. Well, almost nothing. You are in the presence of the %^GREEN%^snakeman%^CYAN%^ now!%^RESET%^\n");
  set_smell("default", "You can smell dirt and brimstone.");
  set_listen("default", "You can hear the hissing of the snakeman and his scales as they move against one another.");
  set_exits( ([
     "out" : "/d/koenig/town/house6"
]) );
}
void reset()
{
  ::reset();
  if(!present("mansnake"))
{
  new("/d/koenig/town/mon/mansnake.c")->move(this_object());
  }
}
