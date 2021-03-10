#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",-7);
    set_property("indoors",1);
    set_short("A REALLY BAD place to be.");
    set_long("
    YOU REALLY DON'T WANT TO KNOW!
");

     set_listen("default","The howling to the south becomes a shrieking.");
     set_smell("default","It is very musty down here, and smells strongly of decay.");
 
    set_exits(([

      "north" : "/d/attaya/tower/hallb18",
       "south" : "/d/attaya/tower/doom2",

    ] ));
}
