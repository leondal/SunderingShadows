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
  set_short("A Secret Passage");
  set_long("%^BOLD%^%^BLUE%^You have entered yet another secret passage, adventurer. It almost makes you wonder if this place you're headed to is beyond your abilities. This tunnel is made of %^RESET%^%^ORANGE%^dirt%^BOLD%^%^BLUE%^ and %^RESET%^%^ORANGE%^wooden braces%^BOLD%^%^BLUE%^ to keep the tunnel from falling in upon itself. You hear the braces groan with the weight they hold up. Maybe you should move on or go back...%^RESET%^\n");
  set_smell("default", "You smell damp earth surrounding you.");
  set_listen("default", "You hear the braces groan with their weight.");
  set_items( ([
     "braces" : "They are made of wood and look to be very old.",
     "wall" : (:this_object(),"wall":)
]) );
  set_exits( ([
     "northwest" : "/d/koenig/town/tunnel4"
]) );
}
void reset()
{
  ::reset();
  remove_exit("east");
  blocked = 0;
}
int shove_wall(string str)  {
  if(! str || str != "wall")  {
  notify_fail("Shove what?!");
  return 0;
}
write("You shove the wall aside to reveal an exit east.");
say(this_player()->query_cap_name()+" shoves the wall and reveals an exit east.", this_player());
  add_exit("/d/koenig/town/tunnel2.c", "east");
  blocked = 1;
  return 1;
}
  string wall(string str)  {
  if(blocked) return "It is sealed.";
  else return "A section of wall seems to stick out about 2 inches. Maybe you can shove it?";
}
