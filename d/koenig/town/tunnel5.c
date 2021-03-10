#include <std.h>
inherit ROOM;

int blocked;

void init()
{
  ::init();
  add_action("shove_statue","shove");
}

void create()
{
  ::create();
   set_terrain(BUILT_TUNNEL);
   set_travel(PAVED_ROAD);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("A Dead End");
  set_long("%^BOLD%^%^BLUE%^You have finally reached the end of the tunnel and find yourself standing before a very large %^RESET%^statue%^BOLD%^%^BLUE%^. You also notice that you have some company!%^RESET%^\n");
  set_smell("default", "You smell damp earth surrounding you.");
  set_listen("default", "You can hear some soft moaning on the other side of the wall.");
  set_items( ([
     "statue" : (:this_object(), "statue":)
]) );
  set_exits( ([
     "south" : "/d/koenig/town/tunnel4"
]) );
  set_pre_exit_functions( ({"south"}),({"go_south"}) );
}
void reset()
{
  ::reset();
  remove_exit("north");
    remove_property("flagged");
  blocked = 0;
  if(!present("gremishka"))  {
  new("/d/koenig/town/mon/gremishka.c")->move(this_object());
   }
  }
  int go_south()  {
  int num;
  if(present("gremishka"))  {
      if(query_property("flagged")) return 0;
  tell_room(environment(this_player()),"\n%^MAGENTA%^Gremishka says: %^RESET%^Where do you think your off to?\n\n%^BOLD%^%^RED%^You gasp in surprize as you see more come from no where to join the first!");
  for(num = 1;num < 10; num++)  {
      new("/d/koenig/town/mon/gremishko.c")->move(TO);
   }
      set_property("flagged", 1);
    return 0;
  }
  return 1;
}
int shove_statue(string str) {
  if(!str) {
  notify_fail("Shove what?!");
  return 0;
}
  if(str == "statue left") {
write("You shove the statue to the left and find a secret exit.");
say(this_player()->query_cap_name()+" shoves the statue to the left and finds a hidden exit north.");
  add_exit("/d/koenig/town/dungeon1.c", "north");
  blocked = 1;
  return 1;
}
  if(str == "statue right") {
write("You shove the statue to the right and find a secret exit.");
say(this_player()->query_cap_name()+" shoves the statue to the right and finds a hidden exit to the north.");
  add_exit("/d/koenig/town/tower1.c", "north");
  blocked = 1;
  return 1;
}
  write("The statue either goes left or right!");
  return 1;
}

string statue(string str)  {
  if(blocked) return "It stays in place.";
  else return "The statue is made of stone and jewels. Its form is that of a strange insect-human hybrid, and it is utterly eerie to look upon. Looking more closely, you get the impression you could shove it left or right.";
}
