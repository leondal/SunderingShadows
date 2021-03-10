#include <std.h>

inherit "/d/attaya/spec/cliff";

void create(){
    ::create();
    set_long("%^RESET%^%^BOLD%^%^WHITE%^Obsidian %^BLACK%^s%^WHITE%^tair%^BLACK%^c%^BLACK%^a%^WHITE%^se%^RESET%^
%^RESET%^%^BOLD%^%^WHITE%^You are upon the Obsidian Staircase of the Kinnesaruda, a series of steps and mountain ledges that winds its way from the River of Flame to the Crystalline Tower of the Black Dawn. You are very high up, and the air is getting somewhat thin. All around you is a white haze, blurring the %^BLUE%^ocean%^WHITE%^ in the distance.");
    set_property("no teleport",1);
    set_climate("mountain");
    set_travel(LEDGE);
    set_terrain(OLD_MOUNTS);
}

