#include <std.h>

inherit VAULT;

int blocked;

void init()
{
  ::init();
  add_action("lift_rug", "lift");
}

void create()
{
  ::create();
  set_door("kitchen", "/d/koenig/town/house3.c", "kitchen", "open_kitchen");
  set_open("kitchen", 0);
  set_string("kitchen", "open", "You open the door and it leads you back to the kitchen.");
  set_door("trapdoor", "/d/koenig/town/tunnel1.c", "trapdoor", "open_trapdoor");
  set_open("trapdoor", 0);
  set_string("trapdoor", "open", "As you open the trapdoor you get a blast of stale air in your face.");
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Kitchen Pantry");
  set_long("%^CYAN%^Well, Well, adventurer some things are just not what they appear to be are they. Upon entering what you thought to be a pantry turns out to be a very tiny room with a set of %^ORANGE%^stairs%^CYAN%^ leading down into %^BOLD%^%^BLACK%^darkness%^CYAN%^. I wonder where they could lead you...%^RESET%^\n");
  set_smell("default", "It smells rather dusty in here.");
  set_listen("default", "You can hear the faint squeek of a mouse some where.");
  set_items( ([
     "room" : "The room is very tiny and along one wall there are shelves and a rug lays upon the floor...",
     "shelves" : "There are many containers on these shelves. Some look to contain spices, others strange things, and still others that you can not see into."
]) );
  set_exits( ([
     "kitchen" : "/d/koenig/town/house3",
     "trapdoor" : "/d/koenig/town/tunnel1"
]) );
}
void reset()
{
  ::reset();
  remove_exit("trapdoor");
  blocked = 0;
  if(!present("rug"))
{
  new("/d/koenig/town/items/rug.c")->move(this_object());
  }
}
int lift_rug(string str)  {
  if(!str || str != "rug")  {
  notify_fail("Lift what?");
  return 0;
}
  write("You lift the rug finding a trapdoor!");
  say(this_player()->query_cap_name()+" lifts the rug and finds a hidden trapdoor!", this_player());
  add_exit("/d/koenig/town/tunnel1.c", "trapdoor");
  blocked = 1;
  return 1;
}
  string rug(string str)  {
  if(blocked) return "You cant lift that!";
}
