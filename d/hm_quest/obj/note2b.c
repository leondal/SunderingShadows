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
    set("long", "Above the Western Gate of the City of Thieves\n"+
    			"You will find the next item that you seek.");
    set_value(0);
}
