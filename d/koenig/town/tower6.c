#include <std.h>
inherit ROOM;

void create()
{
  ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
  set_property("light", 0);
  set_property("indoors", 1);
  set_short("Before a Staircase");
  set_long("%^BOLD%^%^WHITE%^Well, well... What have we here? There are %^RESET%^stairs%^BOLD%^%^WHITE%^ that lead "
           "up to that interesting and somewhat pleasant smell. "
           "You can hear a lot of commotion and movement up above... such a contrast from the deathly silence you've grown accustomed to. I "
           "guess the question is do you go up, or continue to investigate "
           "this lower floor? Hmmmmm. Decisions, decisions.%^RESET%^\n");
  set_smell("default", "A pleasant, if some what odd, smell comes from above you.");
  set_listen("default", "You can hear a lot of noise from above you.");
  set_pre_exit_functions( ({"up"}),({"go_up"}) );
  set_exits( ([
     "north" : "/d/koenig/town/tower5",
     "east" : "/d/koenig/town/tower7",
     "up" : "/d/koenig/town/tower9"
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
    write("The Dark Knight blocks your path upward.");
    say("The Dark Knight blocks "+TPQCN+"'s path.");
    return 0;
}
    return 1;
}
