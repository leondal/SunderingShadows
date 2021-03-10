#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_short("Underwater Cave");
    set_long(
      "You are in a great underwater cavern.  All around you there is nothing but water and more water."
      +"There is a large plank-like rock formation here that extends between the two walls of the cave here where it pinches close."
    );
    set_light(-1);
    set_property("indoors", 1);
    set_items( ([
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
    ]) );
    set_exits( ([
      "north" : CAVEONE "cave64+0.c",
      "east" : CAVEONE "cave63+1.c",
      "west" : CAVEONE "cave65+1.c",
      "up" : CAVEONE "cave54+1.c",
    ]) );
}
