#include <std.h>
inherit OBJECT;

string query_long(string str)
{
	return "This is test one";
}

void create() {
        ::create();
        set_name("A map of the deku forest");
        set_id( ({"map", "deku map","worn map"}) );
        set_short("A worn map of the deku forest");
        set_weight(1);
        set_value(10);
}
