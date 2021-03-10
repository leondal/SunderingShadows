#include <std.h>

inherit "/d/deku/open/forest42i";

void create() {
    ::create();
    set_long(TO->query_long()+"\n%^RED%^There is a sign here.%^RESET%^\n");
    set_exits(([
       "west" : "/d/deku/open/forest45",
      "north" : "/d/deku/open/forest47",
       "east" : "/d/deku/open/forest42i"
    ] ));
    set_items(([
       "sign":"%^RED%^Town of Verbobone to the east."
    ] ));
}

