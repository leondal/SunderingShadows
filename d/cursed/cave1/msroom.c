#include <std.h>
inherit ROOM;

void create()
{
 ::create();
  set_property("indoors",1);
  set_property("light",1);
  set_short("A Manscorpion's chamber.");
  set_long(

@STOP
You have ventured into the home of a manscorpion.
The place is extremly uninviting, you definitly
wouldn't want too stay here too long, let alone
live in here.
STOP
);

  set_smell("default","You smell something extremely toxic in here.");
  set_listen("default","The cave suddenly turned into utter silence.");

  set_exits((["west":"/d/cursed/cave1/cave1-5.c"]));
}
void reset()
{
 ::reset();
 if(!present("manscorpion"))
 {new("/d/cursed/mon/manscorpion.c")->move(this_object());}
}

