#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
  set_property("light", 1);
   set_travel(PAVED_ROAD);
  set_property("no teleport",1);
  set_property("indoors", 1);
  set_short("At the Top of the Tower");
  set_long("%^BOLD%^%^WHITE%^Hmm, this place is %^RESET%^bare%^BOLD%^%^WHITE%^ and dead ends. You made a "
           "wrong turn it would seem, and now you will have to argue with "
           "this petty %^BLUE%^guard%^BOLD%^%^WHITE%^ in order to go back the way you came. Tis "
           "a shame. You better hurry before it is time for the Gentleman's "
           "%^MAGENTA%^dessert%^BOLD%^%^WHITE%^...%^RESET%^\n");
  set_smell("default", "Judging by the smell, this guard should take a bath more often...phew!");
  set_listen("default", "You hear the guard grunt and swear under his breath.");
  set_exits( ([
     "west" : "/d/koenig/town/tower29" 
]) );
}
void reset()
{
  ::reset();
if(!present("knight"))new("/d/koenig/town/mon/knight.c")->move(this_object());
}
int go_west() {
  if(present("knight")) {
if((string)TP->query_name() == "freloc") return 1;
  write("%^RED%^The Dark Knight blocks your path.%^RESET%^");
  say("%^RED%^The Dark Knight blocks "+TPQCN+" from leaving the room.%^RESET%^");
  return 0;
}
  return 1;
}
