#include <std.h>
inherit ROOM;

void create()
{
 ::create();
  set_property("indoors",1);
  set_property("light",1);
  set_short("%^BOLD%^%^RED%^The Cursed Imp's Lair!%^RESET%^");
  set_long(

@STOP
You are inside the %^BOLD%^%^RED%^Cursed Imp's%^RESET%^ lair.
It is a dark and creepy place.  The atmosphere is very uninviting,
%^CYAN%^You get the feeling that you are not welcomed here.%^RESET%^

STOP
);

  set_smell("default","For some strange reason, you smell"+
                " what appears to be animal manure!");
  set_listen("default","You listen closely as you hear faint sounds of:\n"+
        "a web being weaved, the squawkings of a raven, a pest running"+
        " along the floor, and .... what???.... the sounds of a goat"+
        " bahahing???  And finally a hideous creature's laughter.");

  set_exits((["east":"/d/cursed/cave1/cave1-4.c"]));
}
void reset()
{
 ::reset();
 if(!present("imp") && !present("raven") && !present("goat")
        && !present("spider") && !present("rat"))
 {new("/realms/apocalypse/mon/imp.c")->move(this_object());}
}

