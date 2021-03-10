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
    set_items(([]));
    set_smell("default", "There is no %^BOLD%^%^CYAN%^a%^WHITE%^i"
              + "%^CYAN%^r%^RESET%^%^ORANGE%^. You can't smell anything.");
    set_listen("default", "There is no %^BOLD%^%^CYAN%^a%^WHITE%^i"
               + "%^CYAN%^r%^RESET%^%^GREEN%^. You can't hear anything.");
    vacuum = 1;
    set_pre_exit_functions(({ "forward", "backward", "right", "left",
                              "up", "down", "out" }), ({ "move_around", "move_around",
                                                         "move_around", "move_around", "move_around", "move_around",
                                                         "go_out" }));
    set_heart_beat(1);
}

int move_around()
{
    if (TP->query_property("flying")) {
        tell_object(TP, "You float through the void.");
        tell_room(TO, TPQCN + " floats through the %^BOLD%^%^BLACK%^vo"
                  + "%^RESET%^i%^BOLD%^%^BLACK%^d", TP);
        return 1;
    }
    if (!present("unfettered", TO) || random(3)) {
        tell_object(TP, "You can't find any leverage to move!");
        return 0;
    }
    tell_object(TP, "You manage to push off of a passing %^BOLD%^"
                + "%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^MAGENTA%^a"
                + "%^BOLD%^%^BLACK%^cle%^RESET%^ and get leverage to move"
                + " through the %^BOLD%^%^BLACK%^vo%^RESET%^i%^BOLD%^%^BLACK%^d"
                + "%^RESET%^.");
    tell_room(TO, TPQCN + " manages to push off of a passing %^BOLD%^"
              + "%^BLACK%^t%^RESET%^e%^BOLD%^%^BLACK%^nt%^RESET%^%^MAGENTA%^a"
              + "%^BOLD%^%^BLACK%^cle%^RESET%^ and gets leverage to move"
              + " through the %^BOLD%^%^BLACK%^vo%^RESET%^i%^BOLD%^%^BLACK%^d"
              + "%^RESET%^.", TP);
    return 1;
}

int go_out()
{
    tell_object(TP, "You manage to get hold of the lip of the%^BLUE%^"
                + " rift%^RESET%^ and haul yourself out.");
    tell_room(TO, TPQCN + " manages to get hold of the lip of the"
              + " %^BLUE%^rift%^RESET%^ and haul " + TP->QO + "self out.", TP);
    return 1;
}

string long_desc()
{
    string desc;
    object unf;
    desc = "You are in an %^BOLD%^%^WHITE%^"
           + "i%^RESET%^n%^BOLD%^%^WHITE%^t%^BOLD%^%^BLACK%^e%^BOLD%^"
           + "%^WHITE%^r%^RESET%^%^BLUE%^d%^BOLD%^%^WHITE%^i%^RESET%^m"
           + "%^BOLD%^%^WHITE%^e%^RESET%^%^BLUE%^n%^BOLD%^%^WHITE%^s"
           + "%^RESET%^i%^BOLD%^%^BLACK%^o%^BOLD%^%^WHITE%^n%^RESET%^a"
           + "%^BOLD%^%^WHITE%^l %^RESET%^%^BLUE%^void%^RESET%^.";
    if (present("unfettered", TO)) {
        desc += " If you time it right, you might be able to move"
                + " around by pushing  off some part of the huge bulk of the"
                + " %^BLUE%^U%^MAGENTA%^n%^BLUE%^f%^MAGENTA%^e%^BLUE%^tt"
                + "%^MAGENTA%^e%^BLUE%^r%^MAGENTA%^e%^BLUE%^d%^RESET%^.";
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
