#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("The Top of a Staircase");
  set_long("%^BOLD%^%^WHITE%^The stairs have led you to the lower floors of the tower. "
           "You are in the heart of the %^RED%^evil%^WHITE%^ that has rooted itself here in "
           "Muileann. Tread carefully, for you cannot be sure what lies around "
           "the next corner - or on the next landing of the stairs. If you make "
           "it through this alive, be sure to give thanks to whatever "
           "God you pray to, and most of all to the Master of Luck who was by your "
           "side.%^RESET%^\n");
  set_smell("default", "You can still catch a faint whiff of the dungeons, ACK!");
  set_listen("default", "You hear little noises here and there carried on the still air.");
  set_exits( ([
     "down" : "/d/koenig/town/tower2",
     "west" : "/d/koenig/town/tower4"
]) );
}
