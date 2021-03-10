//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create()
{
    ::create();
    loads = 10;
    set("id", ({ "dwarf's pride tobacco", "tobacco" }));
    set_name("dwarf's pride tobacco");
    set_short("%^RESET%^%^BLUE%^Dwarf's Pride Tobacco%^RESET%^");
    set_long("%^BLUE%^A mild blend of orange and mahogany dwarven tobaccos with aromatic Halfling Burley and Fired Stoutfolk leaf, lightly flavoured with whiskey.\n%^BOLD%^%^BLUE%^You should pack this in a pipe.\n%^WHITE%^There are " + loads + " loads left.");
    set_value(250);
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^ORANGE%^You enjoy the rich taste of the whiskey infused dwarven tobacco.%^RESET%^" }));
    set_your_messages(({ "%^RESET%^%^ORANGE%^You smell the aroma of whiskey infused dwarven tobacco.%^RESET%^" }));
}

int use_load()
{
    ::use_load();
    set_long("%^BLUE%^A mild blend of orange and mahogany dwarven tobaccos with aromatic Halfling Burley and Fired Stoutfolk leaf, lightly flavoured with whiskey.\n%^BOLD%^%^BLUE%^You should pack this in a pipe.\n%^WHITE%^There are " + loads + " loads left.");
}
