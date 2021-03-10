#include <std.h>
inherit "/d/deku/plains/plains03i";

void create() {
    ::create();
    set_long(TO->query_long()+"Toward the west is an entrance into the forest "
      "and to the east is the vast expanse of the northern plains.");
     set_listen("default","It's fairly quiet along the forest edge.");
    set_exits(([
       "west" : "/d/deku/plains/road01i",
       "south" : "/d/deku/plains/plains59"
    ] ));
}
