#include <std.h>
#include "crypt.h"
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  new("/d/koenig/town/items/chair.c")->move(this_object());
  new("/d/koenig/town/items/chair.c")->move(this_object());
  set_short("A Room With Chairs");
  set_long("%^BOLD%^%^WHITE%^Now this is interesting. There are two empty %^RESET%^%^ORANGE%^chairs%^BOLD%^%^WHITE%^ in "
           "this room, but there is no one around. The chairs look sturdy "
           "enough, but they do not appear to have been used in some time. You know, "
           "now that you think of it, you could go for a bit of a rest before "
           "going up those stairs. Why dont you sit down in one and take a "
           "break? Couldn't hurt... could it?%^RESET%^\n");
  set_smell("default", "You can catch a whiff of the pleasant smells from above, but now you can smell something else, too...");
  set_listen("default", "You hear faint stirrings of movement.");
  set_exits( ([
     "west" : "/d/koenig/town/tower7"
]) );
}
void init()
{
  ::init();
  add_action("sit_in_chair", "sit");
}
int sit_in_chair(string str)
{
  if(!str)
    return notify_fail("You wanna sit where?\n");
    if(lower_case(str) != "in chair")
    return notify_fail("You can't sit there!\n");
  write("You sit in the chair and as you start to get comfortable. The floor suddenly drops out from beneath you and the chair! Oooppss!");
  say((string)TP->query_cap_name() +" sits in the chair and looks rather comfortable until the floor suddenly drops out from beneath them and the chair!");
  write("%^BOLD%^%^BLACK%^The floor disappears from beneath you, and you fall into utter darkness!\n");
  if(!TP->move("/d/koenig/town/fall2"))
    environment(TP)->start_fall();
  return 1;
}
