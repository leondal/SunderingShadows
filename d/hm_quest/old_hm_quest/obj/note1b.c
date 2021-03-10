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
    set("long", "The goblins, in their stronghold, guard a chest;\n"+
    			"The first item you shall require to complete your quest.");
    set_value(0);
}
