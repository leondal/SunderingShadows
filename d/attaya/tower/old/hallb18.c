#include <std.h>

inherit "/d/attaya/tower/spec/tower";

void create() {
    ::create();
    set_property("light",-7);
    set_property("indoors",1);
    set_short("A REALLY BAD place to be");
    set_long("
    YOU REALLY DON'T WANT TO KNOW!
");

     set_listen("default","You can hear something howling to the south.");
     set_smell("default","It is very musty down here, and smells strongly of decay.");
 
    set_exits(([

//       "ladder" : "/d/attaya/tower/hallb17",
//taking this one out to stop bug reports until we can figure out if
//it was supposed to go somewhere else.  Circe 6/10/04
      "up" : "/d/attaya/tower/hallb17",
       "south" : "/d/attaya/tower/doom1",

    ] ));
}
