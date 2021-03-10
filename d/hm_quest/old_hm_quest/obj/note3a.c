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
    set("long", "Your next chest is in the desert of Shadow.\n"+
    			"To the east and the south is where you must go.");
    set_value(0);
}
