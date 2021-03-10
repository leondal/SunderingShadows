#include <std.h>
inherit "/std/drink.c";

void create()
{
        ::create();
        set_name("%^CYAN%^nectar%^RESET%^");
        set_short("%^RESET%^%^MAGENTA%^iced nectar%^RESET%^");
        set_id(({"nectar","drink","iced nectar"}));
        set_long(
        "%^CYAN%^This is a cup of iced nectar.  It seems like a mix "+
		"of honey and flower nectar poured over snow. "+
		" It is served in a small leaf bowl.%^RESET%^");
        set_weight(1);
        set_value(5);
        set_destroy();
        set_poison(0);
        set_strength(10);
        set_my_mess("You slurp down the iced treat and a chill goes down your spine.");
        set_your_mess("slurps up some iced nectar.");
}
