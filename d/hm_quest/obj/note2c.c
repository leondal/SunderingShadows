#include <std.h>
inherit OBJECT;
void init(){
        ::init();
}

void create() {
    ::create();
    set_id( ({"paper","note"}) );
    set_name("note");
    set("short", "a piece of paper");
    set_weight(0);
    set("long", "In the Echoes Mountains, one level down,\n"+
    			"Another chest is there to be found.");
    set_value(0);
}
