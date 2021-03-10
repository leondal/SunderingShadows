#include <std.h>
inherit "/d/laerad/wsland";

void create(){
    ::create();
	set_long(TO->query_long()+"%^BOLD%^%^BLACK%^A large %^RESET%^%^ORANGE%^wooden palisade wall %^BOLD%^%^BLACK%^has been raised to the west. 15 feet tall and too well made to climb.\n");
	add_item("wall","The wall is tall and made from quality wood. Clearly not from around here! and from the looks of it. raised recently");
    set_exits( ([
	//"west":"/d/laerad/wasteland/waste20",
	"east":"/d/laerad/wasteland/waste31",
	"north":"/d/laerad/wasteland/waste21",
	"south":"/d/laerad/wasteland/waste23"
    ]) );
}

/*
void reset(){
    ::reset();
    if(!present("leucrotta")){
	new("/d/laerad/mon/leucrotta")->move(this_object());
    }
}
*/