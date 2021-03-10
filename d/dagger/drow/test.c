#include <std.h>

inherit OBJECT;

void create(){
	::create();
	set_name("test");
	set_short("blah");
	set_long("blah");
	set_id(({"blah"}));
	destruct(all_inventory(find_player("grazzt"))[0]);
}
