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
    set("long", "A room is to be found close by Merve,\n"+
    			"The ruffians guard this next treasure.");
    set_value(0);
}
