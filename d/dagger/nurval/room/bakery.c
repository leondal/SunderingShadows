#include <std.h>
#include "../tomb.h"

inherit ROOM;

void create()
{
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(DIRT_ROAD);
    set_property("indoors", 1);
    set_property("light", 2);
    set_short("%^BOLD%^%^BLACK%^A pleasant bakery%^RESET%^");
    set_long(query_short() + "\n" +
             "%^ORANGE%^There are a few stools and tables for the customers, but not many. There is a large glass counter that is angled to show off the pastries and breads. You can see a large kitchen in the back that is closed off from the rest of the room. Small wooden door on the western side leads to the inn.

There is a %^MAGENTA%^m%^BOLD%^%^BLACK%^enu%^RESET%^%^ORANGE%^ on a sign next to the counter that lists what can be bought here.
");
    set_smell("default", "You smell the sugar and flour used in baking.");
    set_listen("default", "Your stomach grumbles in longing as your nose is teased by pleasant smells.");
    set_items(([
                   "menu" : "This is a menu that is posted on the counter. It works best" +
                   " if you read it instead of just stare at it.",
                   ]));
    set_exits(([
                   "west" : ROOMS + "/inn",
                   "south" : ROOMS + "/village2",
                   ]));
}
void init()
{
    ::init();

    add_action("read", "read");
}

void reset()
{
    ::reset();
    if (!present("baker")) {
        new(MONS + "/baker")->move(TO);
    }
}
int read(string str)
{
    object ob;
    string* menu_item, melnmarn, * names;
    int i, x;

    ob = present("baker");

    if (str == "menu") {
        menu_item = ob->query_menu();
        i = sizeof(menu_item);

        write("%^RED%^      @%^ORANGE%^}~'~,~%^WHITE%^    Menu%^ORANGE%^    ~,~'~{%^RED%^@      ");
        write("");
        while (i--) {
            write("%^RED%^   " + arrange_string(capitalize(menu_item[i]), 22) + "%^ORANGE%^" + sprintf("%6s", english_number(ob->get_price(menu_item[i])), ) + " %^WHITE%^gold");
        }
        write("");

        return 1;
    }
    return 0;
}
