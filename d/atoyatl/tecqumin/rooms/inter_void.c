#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CVAULT;

string long_desc();

void create()
{
    ::create();
    set_indoors(0);
    set_property("light", 0);
    set_terrain(STONE_BUILDING);
    set_travel(DECAYED_FLOOR);
    set_name("A dark chamber");
    set_short("%^BOLD%^%^BLACK%^An %^BOLD%^%^WHITE%^"
              + "i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
              + "%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
              + "%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s"
              + "%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a"
              + "%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^");
    set_long((: TO, "long_desc" :));
    set_items(([ ({ "rent", "rent in space" }) : (: TO, "rent_desc" :), ]));
    set_smell("default", "There is no %^BOLD%^%^CYAN%^a%^WHITE%^i"
              + "%^CYAN%^r%^RESET%^%^ORANGE%^. You can't smell anything.");
    set_listen("default", "There is no %^BOLD%^%^CYAN%^a%^WHITE%^i"
               + "%^CYAN%^r%^RESET%^%^GREEN%^. You can't hear anything.");
    set_exits(([      "out" : JUNG_ROOM + "canyon_riverbank" ]));
    set_heart_beat(1);
}

string long_desc()
{
    string desc;
    object outside;
    outside = find_object_or_load(query_exit("out"));
    desc = "You are in an %^BOLD%^%^WHITE%^"
           + "i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
           + "%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
           + "%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s"
           + "%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a"
           + "%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^. The"
           + " %^BOLD%^%^BLACK%^r%^YELLOW%^e%^BOLD%^%^BLACK%^nt"
           + " %^RESET%^in %^BLUE%^space%^RESET%^ that you entered is"
           + " still here, and you can see out to ";
    if (objectp(outside)) {
        desc += outside->query_short();
    } else {
        desc += "where you came from";
    }
    desc += ".";
    return desc;
}

string rent_desc()
{
    object room;
    string rm_name, desc;
    rm_name = query_exit("out");
    room = find_object_or_load(rm_name);
    TP->move(room);
    TP->force_me("look");
    TP->move(TO);
    return "The view through the rent is very clear";
}
