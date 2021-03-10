// was /d/tharis/obj/paper.c, moved to /d/common/obj/misc/paper.c  -Ares 09/07/05
#include <std.h>
inherit OBJECT;
void create(){
	::create();
	set_name("paper");
    set_id(({"paper", "piece of paper"}));
        set_short("piece of paper");
        set_long("This is a piece of paper.  It is a regular quality sheet used for writing.");
	set_value(1);
}

string query_long(string str){
    string hold = ::query_long(str);
    if (stringp(query("read"))) {
        hold += " It has writing on it.";
    }
    return hold;
}
