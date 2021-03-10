//	_inventory.c written by Descartes October 1992

#include "move.h"
#include <std.h>
#include <daemons.h>

inherit DAEMON;

string alltext;

int worn_wielded(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if (undefinedp(ob->query_short())) {
        return 0;
    }
    if (ob->query_worn()) {
        return 0;
    }
    if (ob->query_wielded()) {
        return 0;
    }
    return 1;
}

int cmd_inventory()
{
    object* items, * exclude = ({});
    int x, silly;
    string result;
    string short;
    string stuff;

    result = "";
    set_property("information", 1);
    if (x = TP->light_blind(-1)) {
        notify_fail(TP->light_blind_fail_message(x) + "\n");
        return 0;
    }
    items = all_inventory(this_player());

    alltext = "%^BLUE%^--=%^BOLD%^< %^CYAN%^You are carrying%^BLUE%^ >%^RESET%^%^BLUE%^=--\n";
    if (USER_D->get_flag(TP, "simple inventory") == "On") {
        exclude = filter_array(items, "worn_wielded");
        items -= exclude;
        stuff = TP->describe_item_contents(items);
    }else {
        stuff = TP->describe_item_contents(({}));
    }


    if (stuff != "") {
        stuff = "   " + stuff;
        stuff = replace_string(stuff, ",", "\n  ");
        stuff = replace_string(stuff, " are here.", "");
        stuff = replace_string(stuff, " is here.", "");
    }
    if (stuff == "") {
        result += "%^RED%^You are empty-handed.\n";
    } else {
        result = result + stuff;
        result = implode(sort_by_name(explode(result, "\n")), "\n");
    }

    alltext += result;
    this_player()->more(explode(alltext, "\n"));
    return 1;
}

string *sort_by_name(string* things)
{
    int i, j;
    object tmp;

    for (j = 0; j < sizeof(things); j++) {
        for (i = sizeof(things) - 1; i > j; i--) {
            if (strip_colors(things[i]) < strip_colors(things[i - 1])) {
                tmp = things[i - 1];
                things[i - 1] = things[i];
                things[i] = tmp;
            }
        }
    }
    return things;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

inventory - wiew your inventory

%^CYAN%^SYNOPSIS%^RESET%^

inventory

%^CYAN%^DESCRIPTION%^RESET%^

This command displays your inventory.

If simple inventory is turned on it won't show worn and equipped items.

%^CYAN%^SEE ALSO%^RESET%^

eq, set, look, score, stats
"
          );
}

/* EOF */
