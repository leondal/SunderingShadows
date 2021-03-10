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
    set("long", "Guarded by a fire giant and three hell hounds\n"+
    			"Is where the chest for which you look can be found.");
    set_value(0);
}
