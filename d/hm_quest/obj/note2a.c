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
    set_long("In the city under the the Shadowvar is an office where"
     +" once elves were made to register. In the back room you will"
     +" find the next chest.");
    set_value(0);
}
