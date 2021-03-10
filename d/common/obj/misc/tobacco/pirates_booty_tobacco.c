//Gave new desc and made it more IG - Cythera 4/05
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create()
{
    ::create();
    loads = 10;
    set_id(({ "pirate's booty tobacco", "tobacco" }));
    set_name("pirate's booty tobacco");
    set_short("%^RESET%^%^CYAN%^Pirate's Booty Tobacco%^RESET%^");
    set_long("%^CYAN%^A smooth exquisite blend of black cavendish, burley and three different cordizans. Notes of honey, vanilla and orange are added to this favorite tobacco of sailors and pirates.\n%^GREEN%^You should pack this in a pipe.\n%^BOLD%^%^GREEN%^There are " + loads + " loads left.");
    set_value(500);
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^ORANGE%^You enjoy the rich taste of the honey and vanilla infused tobacco.%^RESET%^" }));
    set_your_messages(({ "%^RESET%^%^ORANGE%^You smell the aroma of honey and vanilla infused tobacco.%^RESET%^" }));
}

int use_load()
{
    ::use_load();
    set_long("%^CYAN%^A smooth exquisite blend of black cavendish, burley and three different cordizans. Notes of honey, vanilla and orange are added to this favorite tobacco of sailors and pirates.\n%^GREEN%^You should pack this in a pipe.\n%^BOLD%^%^GREEN%^There are " + loads + " loads left.");
}
