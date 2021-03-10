#include <std.h>
inherit VAULT;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_door("door", "/d/koenig/town/house6.c", "door", "open_door");
  set_open("door", 0);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Carpeted Stairway");
  set_long("%^RESET%^%^CYAN%^You stand at the foot of some stairs leading up. You notice a %^ORANGE%^door%^RESET%^%^CYAN%^ to your east that bears a %^MAGENTA%^strange%^RESET%^%^CYAN%^ design.\n");
  set_smell("default", "You smell a reaxing scent of incense.");
  set_listen("default", "You hear the distant crackling of a fire from the sitting room.");
  set_items( ([
     "stairs" : "They are covered in carpet the color of blood.",
     "door" : "The design is very detailed.",
     "design" : "It is of a manlike snake wrapped around a woman, who appears to be enjoying its attentions. EW."
]) );
  set_exits( ([
     "door" : "/d/koenig/town/house6",
     "up" : "/d/koenig/town/house8",
     "north" : "/d/koenig/town/house2"
]) );
}