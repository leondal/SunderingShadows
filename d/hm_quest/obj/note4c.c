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
    set("long", "The next place you seek is a burial ground.\n"+
    			"But do not enter -- just look around.");
    set_value(0);
}
