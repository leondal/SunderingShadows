#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})

inherit "/d/common/obj/armour/bracers";

void create()
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_name("mineral bracers");
    set_id(({ "bracers", "mineral bracers"}));
    set_short(myCol+"A pair of mineral bracers%^RESET%^");
    set_obvious_short(myCol+"A pair of mineral bracers%^RESET%^");
    set_long(myCol+"These bracers are composed of an unknown material. It "+
    "appears to be some type of mineral, but the exact nature of it is a mystery. "+
    "They cover almost the entire forearm by clasping together in several "+
    "places. When worn it is impossible to determine where they connect, but "+
    "it is possible to remove them simply by pressing them. They are also quite thin "+
    "but seem remarkably durable despite this.%^RESET%^"); 
    set_value(0);
}

int is_metal() { return 0; }