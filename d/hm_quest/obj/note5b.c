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
    //set("long", "To the haunted house, with the Knight of Death.\n"+
    //			"That is where you must look to find the next chest.");
    set("long", "In the profane Shadowlord's graveyard.\n"+
                "That is where you must look to find the next chest.");
    set_value(0);
}
