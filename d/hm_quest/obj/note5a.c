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
    set("long", "The next chest you will need (the end is almost at hand),\n"+
    			"Is on the border of the God's Plains and the Wasteland.");
    set_value(0);
}
