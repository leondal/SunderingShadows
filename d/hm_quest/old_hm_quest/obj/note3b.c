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
    set("long", "In a chapel near Antioch, a chest shall be found,\n"+
    			"If you have in you the patience to search around.");
    set_value(0);
}
