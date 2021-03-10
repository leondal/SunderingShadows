#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})

inherit ARMOUR;

void create()
{
    string myCol = COLORS1[random(sizeof(COLORS1))];
    ::create();
    set_name("metal greaves");
    set_id(({ "greaves", "metal greaves" }));
    set_short("metal greaves");
    set_long("These greaves are crafted from steel.  They have a rough and unfinished "
    "look about them as if they were crafted in haste.");
    set_weight(3);
    set_value(12);
    set_ac(1);
    set_size(2);
    set_type("armor");
    set_armor_prof("medium");
    set_limbs(({ "left leg", "right leg" }));
}

int is_metal() { return 1; }
