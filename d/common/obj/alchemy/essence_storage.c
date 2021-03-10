#include <std.h>

inherit OBJECT;

/*
   ardorite
   solumite
   imberol
   aurol
   noxiil
   vitriil
   sideriil
 */
int *essence = ({0, 0, 0, 0, 0, 0, 0});

void create()
{
    ::create();
    set_id(({"pouch", "essence pouch", "pouch with vials", }));
    set_name("essence storage");
    set_weight(2);
    set_value(1000);
    set_cointype("gold");

    set_obvious_short("%^RESET%^%^ORANGE%^A pouch with v%^BOLD%^i%^RESET%^%^ORANGE%^als%^RESET%^");
    set_short("%^RESET%^%^ORANGE%^Ess%^BOLD%^e%^RESET%^%^ORANGE%^nce P%^BOLD%^o%^RESET%^%^ORANGE%^uch%^RESET%^");
}
