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
      "up" : CAVEONE "cave44+1.c",
      "down" : CAVEONE "cave64+1.c",
      "east" : CAVEONE "cave53+1.c",
      "west" : CAVEONE "cave55+1.c",
      "south" : CAVEONE "cave54+2.c",
      "north" : CAVEONE "cave54+0.c",
    ]) );
}
