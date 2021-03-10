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
    set("long", "Deep in the shadowlord's forest, far west.\n"+
    "There rests the chest you next seek.");
    set_value(0);
}
