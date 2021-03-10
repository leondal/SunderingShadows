#include <std.h>
#include "../tomb.h"

inherit ROOM;

void create()
{
    ::create();
    set_indoors(1);
    set_property("light",2);
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_name("Former Glory");
    set_short("%^RESET%^%^RED%^F%^RED%^o%^BOLD%^%^RED%^rmer%^RESET%^%^ORANGE%^ Glory%^RESET%^");
    set_long(query_short() + "
%^ORANGE%^The hall has a series of uncovered %^GREEN%^t%^CYAN%^a%^GREEN%^b%^CYAN%^l%^CYAN%^e%^GREEN%^s%^ORANGE%^ and %^CYAN%^c%^CYAN%^h%^CYAN%^a%^GREEN%^irs%^ORANGE%^ drawn up to each table. The %^RED%^f%^BOLD%^%^BLACK%^i%^BLACK%^r%^BLACK%^e%^RESET%^%^RED%^p%^BOLD%^%^BLACK%^l%^BLACK%^a%^RESET%^%^RED%^c%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^ is laid with tinder. Perfectly laid floor is easy to walk on. Small door leads outside, single but huge segmented %^CYAN%^wi%^WHITE%^n%^WHITE%^d%^CYAN%^ow%^ORANGE%^ opens view at the street. A stairway on the side leads upstairs, and small door on the eastern side invites with numerous smells. Cozy atmosphere allows you to forget where you actually are.

There is a %^MAGENTA%^m%^BOLD%^%^BLACK%^enu%^RESET%^%^ORANGE%^ on a sign next to the counter that lists what can be bought here.
");
    set_smell("default", "You smell the faint aroma of lamb stew.");
    set_listen("default", "You hear cracking of the fireplace.");
    set_items(([
                   "tables" : "There are eight over all, made from oak with vines and lillies engraved on the table legs.",
                   "chairs" : "Smooth polished wood with a high back which has a tree engraved in the center.",
                   "fireplace" : "Many weary travellors have warmed themselves while leaning against the bricks.",
                   "window" : "Frosted glass allows a soft light to enter.",
                   ]));

  set_exits(([
                 "east" : ROOMS + "/bakery",
                 "south" : ROOMS + "/village",
     ]));
}


void reset()
{
    ::reset();
    if (!present("innkeeper"))
        new(MONS + "/inkeep")->move(TO);
}

void init()
{
    ::init();

    add_action("read", "read");
}

int read(string str)
{
    object ob;
    string *menu_item, melnmarn, *names;
    int i, x;

    ob = present("innkeeper");

    if (str == "menu") {
        menu_item = ob->query_menu();
        i = sizeof(menu_item);

        write("%^RED%^      @%^ORANGE%^}~'~,~%^WHITE%^    Menu%^ORANGE%^    ~,~'~{%^RED%^@      ");
        write("");
        while (i--) {
            write("%^RED%^   " + arrange_string(capitalize(menu_item[i]), 22) + "%^ORANGE%^" + sprintf("%6s", english_number(ob->get_price(menu_item[i])),) + " %^WHITE%^gold");
        }
        write("");

        return 1;
    }
    return 0;
}
