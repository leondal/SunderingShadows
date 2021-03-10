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
  set_long("%^BOLD%^%^WHITE%^Well you have made it to the %^RESET%^second floor%^BOLD%^%^WHITE%^ and into a hallway. Judging by the smells here you are not far from the kitchen. %^RESET%^%^CYAN%^MMMMMmmmm!%^BOLD%^%^WHITE%^ Food would be good about now. You can hear your stomach grumble in agreement to that thought, and it seems to urge you in the direction of those strange yet very appealing %^MAGENTA%^scents%^BOLD%^%^WHITE%^.%^RESET%^");
  set_smell("default", "The smell of those strange yet appealing scents is very strong here.");
  set_listen("default", "You can hear a lot of clanging and banging and yelling from down the hall.");
  set_exits( ([
     "down" : "/d/koenig/town/tower6",
     "north" : "/d/koenig/town/tower10"
]) );
}