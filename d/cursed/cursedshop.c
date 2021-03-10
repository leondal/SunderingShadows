#include <std.h>
inherit ROOM;

void create()
{
     ::create();
          set_property("indoors",1);
          set_property("light",3);
          set_short("Cursed Land's shop.");
          set_long(
@STOP
You are in the Cursed Land's shop.
You can buy some various and unusual stuff
here.  You see a huge shadow of a hideous
monster peering through the window.
STOP
);
        set_exits((["out":"/d/cursed/cursed1.c"]));
}

void reset()
{
    ::reset();
    if(!present("shopkeeper"))
        new("/d/cursed/mon/shopkeeper")->move(TO);
    if(!present("omen"))
        new("/d/cursed/mon/omen")->move(TO);
}
