#include <std.h>
#include "../inherit/ruins.h"
inherit OBJECT;

void create(){
        ::create();
        set_name("yellow sigil");
        set_id(({"sigil","Sigil","Yellow Sigil","yellow sigil"}));
        set_short("%^YELLOW%^glowing yellow sigil%^RESET%^");
        set_long("%^BLACK%^%^BOLD%^This sigil is formed of stone, though strangely it seems to weigh "
"nearly nothing, and glows with its own inner %^YELLOW%^yellow %^BLACK%^light.  It is carved into an "
"ornate symbol of some sort, in such a precise shape as though it were made to fit "
"somewhere.%^RESET%^\n");
        set_value(0);
        set_weight(0);
        set_lore("%^WHITE%^%^BOLD%^Sigils such as these were used in a similar fashion to keys, by the "
"members of a cult known only as 'the Faithful of the True Voice'.  They were used to negate the magical "
"wards upon certain doors within their sanctuary.%^RESET%^");
        set_property("lore difficulty",20);
}
