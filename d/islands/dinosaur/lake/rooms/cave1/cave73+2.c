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
      "east" : CAVEONE "cave72+2.c",
      "west" : CAVEONE "cave74+2.c",
      "up" : CAVEONE "cave63+2.c",
      "down" : CAVEONE "cave83+2.c",
      "north" : CAVEONE "cave73+1.c",
      "south" : CAVEONE "cave73+3.c",
    ]) );
}
