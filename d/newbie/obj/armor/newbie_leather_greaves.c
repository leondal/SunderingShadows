#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})

inherit "/d/common/obj/armour/leather_greaves";

void create()
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_name("scaly leather greaves");
    set_id(({ "greaves", "leather greaves", "scaly leather greaves"}));
    set_short(myCol+"A pair of thick scaly leather greaves%^RESET%^");
    set_long(myCol+"These greaves are crafted from the thick leather of some "+
    "unknown and scaly creature. There are bumps and bulbous extrusions visible "+
    "all over them. It appears that the leather has been sewn into an equally "+
    "mysterious fabric, potentially in order to provide some padding so that they "+
    "the rougher leather does not rub against the shins and calves.%^RESET%^"); 
    set_value(0);
}

int is_metal() { return 0; }