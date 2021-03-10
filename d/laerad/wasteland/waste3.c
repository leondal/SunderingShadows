#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
	set_long(TO->query_long()+"%^BOLD%^%^BLACK%^A large %^RESET%^%^ORANGE%^wooden palisade wall %^BOLD%^%^BLACK%^has been raised to the north. 15 feet tall and too well made to climb.\n");
	add_item("wall","The wall is tall and made from quality wood. Clearly not from around here! and from the looks of it. raised recently");
    set_exits( ([
	"west":"/d/laerad/wasteland/waste2",
	"east":"/d/laerad/wasteland/waste14",
	//"north":"/d/laerad/wasteland/waste12",
	"south":"/d/laerad/wasteland/waste13"
    ]) );
}

/*
void reset(){
    ::reset();
    if(!present("rhino")){
	new("/d/laerad/mon/wrhino")->move(this_object());
    }
}
*/