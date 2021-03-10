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
      "up" : CAVEONE "cave24+0.c",
      "down" : CAVEONE "cave44+0.c",
      "west" : CAVEONE "cave35+0.c",
      "east" : CAVEONE "cave33+0.c",
      "north" : CAVEONE "cave34-1.c",
      "south" : CAVEONE "cave34+1.c",
    ]) );
}
