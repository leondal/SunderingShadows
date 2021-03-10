#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("no teleport", 1);
  set_property("light", 1);
  set_property("indoors", 1);
  set_short("Before a Staircase");
  set_long("%^BOLD%^%^WHITE%^You stand before some %^BOLD%^%^BLACK%^stone stairs%^BOLD%^%^WHITE%^ leading upward into "
           "semi darkness. There really isn't much to see or examine here, "
           "so either push onward or try to go back.%^RESET%^\n");
  set_smell("default", "You smell only stale air and the faint wiff of the dungeon.");
  set_listen("default", "You hear nothing really.");
  set_pre_exit_functions( ({"up"}),({"go_up"}) );
  set_exits( ([
     "south" : "/d/koenig/town/tower1",
     "up" : "/d/koenig/town/tower3"
]) );
}

void reset()
{
  ::reset();
if(!present("knight"))new("/d/koenig/town/mon/knight.c")->move(this_object());
}

int go_up()
{
    if(present("knight")) {
    write("The DarkKnight blocks your path upward.");
    say("The DarkKnight blocks "+TPQCN+"'s path.");
    return 0;
}
    return 1;
}
