#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_short("Underwater Cave");
    set_long(
      "You are in a great underwater cavern.  You are sorrounded all around by millions of gallons of water.  You are able to stand on a small stone ledge sticking out of the wall here."
    );
    set_light(-1);
    set_property("indoors", 1);
    set_items( ([
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
    ]) );
    set_exits( ([
      "east" : CAVEONE "cave71-1.c",
      "west" : CAVEONE "cave73-1.c",
      "up" : CAVEONE "cave62-1.c",
      "south" : CAVEONE "cave72+0.c",
    ]) );
}
