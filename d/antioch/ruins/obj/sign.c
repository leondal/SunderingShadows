#include <std.h>
#include "../ruins.h"
inherit OBJECT;

void create()
{
	::create();
	set_name("sign");
	set_short("A sign post");
	set_id(({"sign","sign post"}));
	set_long(
	"A wooden sign has been staked into the ground here. It has some writing"+
	" on it that you could read."
	);
	set_weight(1000000);
	set_property("no animate",1);
	set_value(0);
}

void init()
{
	::init();
	add_action("read","read");
}

int read(string str)
{
	if(str == "sign" || str == "sign post") {
		tell_room(ETP,""+TP->query_cap_name()+" reads over the sign post.",TP);
		tell_object(TP,"The sign post reads:\n"+
            "Be wary travelers! The ruins of Antioch still hold dangerous creatures"+
		" that roam about, whole parties of adventurers have died to these"+
		" beasts! To venture forth is to invite death, turn back now!\n");
		return 1;
	}
}
