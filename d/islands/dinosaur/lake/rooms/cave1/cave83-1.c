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
      "up" : CAVEONE "cave73-1.c",
      "east" : CAVEONE "cave82-1.c",
      "down" : CAVEONE "cave93-1.c",
      "west" : CAVEONE "cave84-1.c",
      "south" : CAVEONE "cave83+0.c",
      "north" : CAVEONE "cave83-2.c",
    ]) );
}
