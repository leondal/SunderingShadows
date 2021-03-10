#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("A Bare Room");
  set_long("%^BOLD%^%^WHITE%^Yep, this place sure does give you the %^RESET%^chilly%^BOLD%^%^WHITE%^ feeling. "
           "No one has bothered to make this place feel homey or warm. "
           "You are definitely not feeling very welcome here, but at least you are still alive. This is "
           "possibly among the worst ten places to visit in the world, wouldn't you agree?%^RESET%^\n");
  set_smell("default", "You catch a faint whiff of something awful down the way, but the smell from above is definately appealing and strange.");
  set_listen("default", "The sounds of hustle and bustle are growing louder.");
  set_exits( ([
     "east" : "/d/koenig/town/tower4",
     "south" : "/d/koenig/town/tower6"
]) );
}
