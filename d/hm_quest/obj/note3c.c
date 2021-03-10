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
    set("long", "The City of Thieves holds the next piece of the puzzle.\n"+
    			"Watch out for the cubes, and beware the crusher.");
    set_value(0);
}
