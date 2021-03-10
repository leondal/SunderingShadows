#include <std.h>
#define COLORS1 ({"%^BOLD%^%^WHITE%^","%^RESET%^%^RED%^","%^BOLD%^%^RED%^","%^RESET%^%^GREEN%^","%^BOLD%^%^BLACK%^","%^RESET%^%^BLUE%^","%^YELLOW%^","%^RESET%^%^ORANGE%^","%^BOLD%^%^CYAN%^","%^RESET%^%^CYAN%^","%^RESET%^%^MAGENTA%^","%^BOLD%^%^MAGENTA%^",})

inherit "/d/common/obj/armour/horseshoes";

void create() 
{
    string myCol = COLORS1[random(sizeof(COLORS1))];

    ::create();
    set_name("pair of mineral horseshoes");
    set_id(({"horseshoes","mineral horseshoes", "shoes", "mineral shoes"}));
    set_short(myCol+"A pair of mineral horseshoes%^RESET%^");
    set_long(myCol+"These horseshoes are made from a very sturdy but "+
    "unknown substance. It appears to be some foreign and mysterious "+
    "mineral which you are unable to identify. Each one of the pair forms a "+
    "perfect arc, that ends parted to allow fitting below the front "+
    "of the hoof. They are also quite sturdy, suggesting that they "+
    "might hold up well to frequent use.%^RESET%^");
    set_value(0);
}
