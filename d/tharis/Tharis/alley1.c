#include <std.h>
inherit ROOM;

void create()
{
  ::create();
    set_terrain(CITY);
    set_travel(BACK_ALLEY);
  set_property("light", 1);
  set_short("an Alley");
   set_long("You have just run into a dimly lit alley. It is filthy and there is garbage thrown here and there. This not a place you'd like to spend a lot of time in, unlike the drunk you find here.");
  set_smell("default", "The stench is barely tolerable here.");
  set_listen("default", "You hear a drunk mumbling and moving about the garbage here.");
  set_items( ([
      "garbage" : "It's just that garbage. Things that have been thrown out because they are no longer desired or wanted or are broken."
  ]) );
  set_exits( ([
     "east" : "/d/tharis/Tharis/warestreet4",
    "west":"/d/tharis/Tharis/alley2"
  ]) );
}
void reset()
{
  ::reset();
  if(!present("drunk"))new("/d/tharis/monsters/drunk")->move(this_object());
}

//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }