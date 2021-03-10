#include <std.h>

inherit "/d/deku/open/forest2i";

void create() {
    ::create();
    set_long(TO->query_long()+"\n%^RED%^There is a sign here pointing to the "
             "east.%^RESET%^\n");
     set_listen("default","Peculiar, the forest is deadly quiet but"
                          " you hear some kind of activity eastward.");
    set_exits(([
       "north" : "/d/deku/open/forest5",
       "east" : "/d/deku/open/forest41",
       "south" : "/d/deku/open/forest3"
    ] ));
    set_items(([
       "sign":"The sign reads:                 \n"+
              "     To the east is the small town of Verbobone.\n"
    ] ));
}

