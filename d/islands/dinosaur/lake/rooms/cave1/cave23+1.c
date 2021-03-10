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
      "up" : CAVEONE "cave13+1.c",
      "down" : CAVEONE "cave33+1.c",
      "west" : CAVEONE "cave24+1.c",
      "north" : CAVEONE "cave23+0.c",
      "south" : CAVEONE "cave23+2.c",
    ]) );
}
