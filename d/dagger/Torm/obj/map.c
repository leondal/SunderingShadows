#include <std.h>
inherit OBJECT;

void init(){
	::init();
	add_action("read_map","read");
}
void create() {
    ::create();
    set_id( ({"map"}) );
    set_name("map");
    set("short", "A map of Torm");
    set("long","This is a map of Torm that you might want to read.");
    set_weight(0);
    set_value(20);
}

int read_map(string str){
	if(!str) notify_fail("Read what?");
	if(str != "map") return 0;
        TP->more("/d/dagger/Torm/obj/TORMMAP");
	return 1;

}
