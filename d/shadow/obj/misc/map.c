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
    set("short", "A map of Shadow");
set("long","This is a map. You should read it.");
    set_weight(0);
    set_value(0);
}

int read_map(string str){
	if(!str) notify_fail("Read what?");
	if("map" != str) return 0;
        TP->more("/d/shadow/obj/MAP");
	return 1;

}
