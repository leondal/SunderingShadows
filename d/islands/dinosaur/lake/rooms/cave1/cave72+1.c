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
      "up" : CAVEONE "cave62+1.c",
      "east" : CAVEONE "cave71+1.c",
      "west" : CAVEONE "cave73+1.c",
      "down" : CAVEONE "cave82+1.c",
      "north" : CAVEONE "cave72+0.c",
      "south" : CAVEONE "cave72+2.c",
    ]) );
}
