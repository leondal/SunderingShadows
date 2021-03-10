#include <std.h>
inherit ROOM;

int blocked;

void init()
{
  ::init();
  add_action("shove_wall", "shove");
}

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Tunnel Leading Downward");
  set_long("%^BOLD%^%^BLUE%^You have reached the bottom of the stairs, and find yourself in a basement of %^RED%^horror%^BOLD%^%^BLUE%^! There are small %^RESET%^cages%^BOLD%^%^BLUE%^ hanging from the ceilings along one wall, a huge %^RESET%^%^ORANGE%^butcher table%^BOLD%^%^BLUE%^ stands in the center, and along the wall closest to the table hang %^RESET%^instruments%^BOLD%^%^BLUE%^ for butchering, such knives and hatchets. It would appear something was butchered here recently for all the %^BOLD%^%^RED%^gore%^BOLD%^%^BLUE%^ about the table and floor.%^RESET%^\n");
  set_smell("default", "You smell blood and bile.");
  set_listen("default", "You hear nothing.");
  set_items( ([
     "cages" : "These cages hold some straw and feces and look to have been occupied recently. The wall below and behind them looks rather odd...",
     "table" : "This table is gigantic and looks to be very well used.",
     "instruments" : "There are instruments of butchering on this wall, and all of them look to be honed to a very fine edge.",
     "floor" : "The floor is covered in blood and gore.",
     "wall" : (:this_object(),"wall":) ]) );
  set_exits( ([
     "up" : "/d/koenig/town/tunnel1"
]) );
}
void reset()
{
  ::reset();
  remove_exit("west");
  blocked = 0;
}
int shove_wall(string str) {
  if((!str) || (str != "wall")) {
  return notify_fail("Shove what?\n");
}
write("You shove the wall aside, revealing a secret passage!");
say(this_player()->query_cap_name()+" shoves on the wall, and it slides in and to one side revealing a secret passage way!", this_player());
  add_exit("/d/koenig/town/tunnel3.c", "west");
  blocked = 1;
  return 1;
}
string wall(string str) {
  if(blocked) return "It is sealed!";
  else return "A section of the wall seems to sink in about 2 inches. Maybe you can shove it?";
}
