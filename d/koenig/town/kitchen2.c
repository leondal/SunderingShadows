#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Kitchen");
  set_long("%^RESET%^%^RED%^There are a number of %^RESET%^stoves%^RESET%^%^RED%^ and %^RESET%^vats%^RESET%^%^RED%^ along the east wall. All of them seem to be in use at the moment. In the middle of this area is a %^ORANGE%^butcher block%^RESET%^%^RED%^, it appears to have some %^GREEN%^fo%^ORANGE%^o%^GREEN%^d%^RESET%^%^RED%^ and -%^MAGENTA%^things%^RESET%^%^RED%^- on it. Maybe you should take a closer look at the food on the table.%^RESET%^\n");
  set_smell("default", "You smell lots of different foods cooking.");
  set_listen("default", "You can still hear banging, shouting, and now you can hear fat sizzling on the fires here.");
  set_items( ([
     "stoves" : "All of these appear to be in use and they all appear to be very large.",
     "vats" : "Hmmm there is some kind of yellow fat sizzling there.",
     "butcher block" : "It is good sized - people-sized, one might say.",
     "food" : "OH MY GOD! It is a woman's arm, and it appears to have a ring on the finger still."
]) );
  set_exits( ([
     "west" : "/d/koenig/town/kitchen1",
     "south" : "/d/koenig/town/kitchen4"
]) );
}
void reset()
{
  ::reset();
  if(!present("cook") || !present("underling"))
  {
  new("/d/koenig/town/mon/asscook.c")->move(this_object());
  new("/d/koenig/town/mon/assunder1.c")->move(this_object());
  }
}