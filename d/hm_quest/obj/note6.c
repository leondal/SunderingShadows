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
    set("long", "At (45,16) you will find a dock on an island.\n"+
    			"That is where this adventure shall come to an end.");
    set_value(0);
}
