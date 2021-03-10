// Fire Dragon Original.. Stablemaster/traner (TANNER)
// Sometime in fall 1995
// (grin)

give_horse(string type, object owner);

#include <std.h>
inherit MONSTER;

string time;

void create()
{
  ::create();
  set_name("tanner");
  set_id( ({ "tanner", "trainer", "stablemaster", "centaur" }) );
  set_short("%^RESET%^%^ORANGE%^Tanner, the Stablemaster%^RESET%^");
  set_long("Tanner looks very strong and capable of doing his profession well and honoring his clan above all else.");
  set_gender("male");
  set_race("centaur");
  set_class("fighter");
  set_level(12);
}

void reset() 
{
  ::reset();
    time = "daemon/events_d"->query_time_of_day();
    if(time != "day")
    remove();
}
