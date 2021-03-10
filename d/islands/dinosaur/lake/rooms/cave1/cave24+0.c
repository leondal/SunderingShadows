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
      "up" : CAVEONE "cave14+0.c",
      "west" : CAVEONE "cave25+0.c",
      "east" : CAVEONE "cave23+0.c",
      "south" : CAVEONE "cave24+1.c",
      "down" : CAVEONE "cave34+0.c",
    ]) );
}
