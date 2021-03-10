#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_short("Underwater Cave");
    set_long(
      "You are in a great underwater cavern.  All around you there is nothing but water and more water."
    );
    set_light(-1);
    set_property("indoors", 1);
    set_items( ([
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
    ]) );
    set_exits( ([
      "east" : CAVEONE "cave61+1.c",
      "west" : CAVEONE "cave63+1.c",
      "down" : CAVEONE "cave72+1.c",
      "north" : CAVEONE "cave62+0.c",
      "south" : CAVEONE "cave62+2.c",
    ]) );
}
