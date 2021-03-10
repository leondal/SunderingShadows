//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create()
{
    ::create();
    loads = 10;
    set_id(({ "white dragon tobacco", "dragon tobacco", "tobacco" }));
    set_name("white dragon tobacco");
    set_short("%^BOLD%^%^WHITE%^White Dragon Tobacco%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This excellent mixture is a blend of first choice Undalish, Burley, and Black Cavendish. A promise for a unique smoking experience, which is crowned by a wonderful amaretto aroma that also gives enjoyment to the smokers' surroundings. A popular tobacco that was first sold in Antioch's White Dragon Inn.\n%^BOLD%^%^CYAN%^You should pack this in a pipe.\n%^BOLD%^%^BLUE%^There are " + loads + " loads left.");
    set_value(950);
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^ORANGE%^You enjoy the rich taste of the amaretto infused tobacco.%^RESET%^" }));
    set_your_messages(({ "%^RESET%^%^ORANGE%^You smell the rich amaretto infused aroma of the tobacco.%^RESET%^" }));
}

int use_load()
{
    ::use_load();
    set_long("%^BOLD%^%^WHITE%^This excellent mixture is a blend of first choice Undalish, Burley, and Black Cavendish. A promise for a unique smoking experience, which is crowned by a wonderful amaretto aroma that also gives enjoyment to the smokers' surroundings. A popular tobacco that was first sold in Antioch's White Dragon Inn.\n%^BOLD%^%^CYAN%^You should pack this in a pipe.\n%^BOLD%^%^BLUE%^There are " + loads + " loads left.");
}
