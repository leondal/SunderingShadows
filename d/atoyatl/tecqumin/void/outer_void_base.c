#include <std.h>
#include <move.h>
#include "../tecqumin.h"

inherit CVAULT;
int vacuum;

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
    vacuum = 1;
    set_exits(([     "down"  : JUNG_ROOM + "inter_void10",
                     "left" : JUNG_ROOM + "inter_void4"
               ]));
    set_heart_beat(1);
}

string long_desc()
{
    string desc;
    desc = "You are floating in the outer reaches of an %^BOLD%^%"
           + "^WHITE%^i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e"
           + "%^BOLD%^%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i"
           + "%^RESET%^m%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^"
           + "%^WHITE%^s%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n"
           + "%^RESET%^a%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void"
           + "%^RESET%^.";
    if (TP->query_property("flying")) {
        desc += " You can move around by flying, but there does not"
                + " seem to be anywhere to go further out.";
    } else {
        desc += " There doesn't seem to be any way to move yourself"
                + " around.";
    }
    return desc;
}

int is_vacuum()
{
    return vacuum;
}

void set_vacuum(int vac)
{
    vacuum = vac;
}
