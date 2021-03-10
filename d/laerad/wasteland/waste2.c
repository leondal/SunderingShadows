#include <std.h>
inherit "/d/laerad/wsland";

void create(){
	::create();
    
	set_long(TO->query_long()+"%^BOLD%^%^BLACK%^A large %^RESET%^%^ORANGE%^wooden palisade wall %^BOLD%^%^BLACK%^has been raised. Just north of here you see a opening in the wall into a small outpost.\n");
	add_item("wall","The wall is tall and made from quality wood. Clearly not from around here! and from the looks of it. raised recently");
	
	set_exits( ([
	"west":"/d/laerad/wasteland/waste1",
	"east":"/d/laerad/wasteland/waste3",
	"north":"/d/laerad/outpost/rooms/1",
	"south":"/d/laerad/wasteland/waste5"
    ]) );
}
