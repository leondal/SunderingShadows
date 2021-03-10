//Gave new desc and made it more IG - Cythera 4/05
//Modified from new inherit. Nienne, 02/08.
#include <std.h>
inherit "/d/common/obj/misc/tobacco/tobacco";

void create()
{
    ::create();
    set_id(({ "luxury of tharis tobacco", "tobacco", "luxury of tharis" }));
    set_name("luxury of tharis tobacco");
    set_short("%^BOLD%^%^BLACK%^Luxury of Tharis tobacco%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Incredibly popular and very rare.  Mild, golden Cordazethes, that possess a naturally high sweetness, are mixed with a very mild Black Cavendish. A fresh flavor with essences of exotic fruits and a touch of Bourbon Vanilla is added to make this a very mild blend.\n%^YELLOW%^You should pack this in a pipe.\n%^RESET%^There are " + loads + " loads left.");
    set_value(2000);
    min_con = 14;
    set_has_messages();
    set_my_messages(({ "%^RESET%^%^ORANGE%^You enjoy the rich taste of the bourbon-infused tobacco.%^RESET%^" }));
    set_your_messages(({ "%^RESET%^%^ORANGE%^You smell the sweet aroma of the bourbon-infused tobacco.%^RESET%^" }));
}

int use_load()
{
    ::use_load();
    set_long("%^BOLD%^%^BLACK%^Incredibly popular and very rare.  Mild, golden Cordazethes, that possess a natuarlly high sweetness, are mixed with a very mild Black Cavendish. A fresh flavor with essences of exotic fruits and a touch of Bourbon Vanilla is added to make this a very mild blend.\n%^YELLOW%^You should pack this in a pipe.\n%^RESET%^There are " + loads + " loads left.");
}
