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
    set("long", "In the Gentleman's garden, where the roses grow,\n"+
    			"The next piece of the puzzle waits for you.");
    set_value(0);
}
