//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create()
{
    ::create();
    loads = 10;
    set_id(({ "hafling's homeblend tobacco", "tobacco" }));
    set_name("halfling's homeblend tobacco");
    set_short("%^RESET%^%^GREEN%^Halfling's Homeblend Tobacco%^RESET%^");
    set_long("%^GREEN%^A mixture of broad and very ripe Halfling Burley, double fermented Black Cavendish. A wonderful natural sweetness with a touch of apple flavor.\n%^BOLD%^%^GREEN%^You should pack this in a pipe.\n%^YELLOW%^There are " + loads + " loads left.");
    set_value(350);
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^ORANGE%^You enjoy the rich taste of the naturally sweet tobacco with a touch of apple flavor.%^RESET%^" }));
    set_your_messages(({ "%^RESET%^%^ORANGE%^You smell the aroma of naturally sweet tobacco infused with a touch of apple.%^RESET%^" }));
}

int use_load()
{
    ::use_load();
    set_long("%^GREEN%^A mixture of broad and very ripe Halfling Burley, double fermented Black Cavendish. A wonderful natural sweetness with a touch of apple flavor.\n%^BOLD%^%^GREEN%^You should pack this in a pipe.\n%^YELLOW%^There are " + loads + " loads left.");
}
