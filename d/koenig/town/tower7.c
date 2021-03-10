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
  set_long("%^BOLD%^%^WHITE%^Going this way you may not have to fight, and perhaps "
           "there is no chance of discovery. The walls still "
           "remain %^RESET%^bare%^BOLD%^%^WHITE%^ and the floors still look well travelled. But you are "
           "beginning to have the creeping sensation that you are being %^RESET%^watched%^BOLD%^%^WHITE%^.");
  set_smell("default", "You can only smell those strange yet pleasing smells from above.%^RESET%^\n");
  set_listen("default", "The noise from above fades as you travel away from the stairs.");
  set_exits( ([
     "east" : "/d/koenig/town/tower8",
     "west" : "/d/koenig/town/tower6"
]) );
}
