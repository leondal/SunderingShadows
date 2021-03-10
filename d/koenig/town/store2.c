#include <std.h>
inherit ROOM;

string time;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(DIRT_ROAD);
  set_property("indoors",1);
  set_property("light",2);
//  set_property("no attack",1);
//  set_property("no magic",1);
//Removing the above properties as they don't seem to fit an IC room like this
//Circe 12/1/07
  set_short("The Warrior's Alcove");
  set_long("%^RESET%^%^CYAN%^Shiny %^RESET%^armor%^RESET%^%^CYAN%^ and %^RESET%^weapons%^RESET%^%^CYAN%^ are put on proud display here. Mannequins are garbed in simple, but untested, suits of armor. Display cases reveal sharpened blades, and some large swords decorate the otherwise plain walls. Spears and other polearms are kept in neat racks along one side of the room. Type <%^BOLD%^help shop%^RESET%^%^CYAN%^> to see what can be done here.%^RESET%^\n");
  set_smell("default", "You smell new leather and freshly oiled steel.");
  set_listen("default", "You can hear people bickering over prices.");
  set_exits( ([
     "down" : "/d/koenig/town/general1"
]) );
}
void reset()
{
    ::reset();
      time = "daemon/events_d"->query_time_of_day();
      if(time == "dawn" || time == "day")
{
  if (!present("tolo",this_object()))
  {
     new("/d/koenig/town/mon/tolo.c")->move(this_object());
  }
 }
   else
  {
    if (!present("bhut",this_object()))
     new("/d/koenig/town/mon/bhuttolo.c")->move(this_object());
   }
}
