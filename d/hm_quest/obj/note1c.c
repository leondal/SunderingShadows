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
    set("long", "A small town, long abandoned, is where you are due,\n"+
                        "A house near the river will reveal your next clue.");
    set_value(0);
}
