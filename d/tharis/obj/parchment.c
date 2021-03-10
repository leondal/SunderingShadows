#include <std.h>
inherit OBJECT;
void create(){
	::create();
	set_name("parchment");
    set_id(({"parchment","parchment11", "sheet of parchment"}));
        set_short("sheet of parchment");
        set_long("This is a high quality piece of parchment. Its weave and consistency are of very good quality");
	set_value(100);
}

string query_long(string str){
    string hold = ::query_long(str);
    if (stringp(query("read"))) {
        hold += " It has writing on it.";
    }
    return hold;
}

int is_parchment()
{
	return 1;
}
