//	_inventory.c written by Descartes October 1992

#include "move.h"
#include <std.h>
#include <daemons.h>

inherit DAEMON;

string alltext;

int worn_wielded(object ob)
{
    if(!objectp(ob)) return 0;
    if(undefinedp(ob->query_short())) return 0;
    if(!ob->query_worn() && !ob->query_wielded()) return 0;
    return 1;
}

int cmd_eq()
{
    object *items, *exclude = ({});
    int x,silly;
    string result;
    string short;
    string stuff;

    alltext = "";
    set_property("information",1);
    items = all_inventory(this_player());
    result = "%^BLUE%^--=%^BOLD%^< %^CYAN%^You are using%^BLUE%^ >%^RESET%^%^BLUE%^=--\n";
    exclude = filter_array(items, "worn_wielded");
    items -= exclude;
    stuff = TP->describe_item_contents(items);

    if(stuff != "")
    {
        stuff = "   "+stuff;
        stuff = replace_string(stuff,",","\n  ");
        stuff = replace_string(stuff," are here.","");
        stuff = replace_string(stuff," is here.","");
    }
    if(stuff == "")
        result += "%^RED%^You are not currently using anything.\n";
    else
        result = result + stuff;
    alltext += result;
    this_player()->more(explode(alltext,"\n"));
    return 1;
}

void help() {
    write("
%^CYAN%^NAME%^RESET%^

eq - view equipped items

%^CYAN%^DESCRIPTION%^RESET%^

This command displays a list of the items that you are currently using.

%^CYAN%^SEE ALSO%^RESET%^

inventory, limbs, score, money
"
        );
}
