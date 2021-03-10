//Many thanks to Shar for creating this item :)
#include <std.h>
inherit ARMOUR;

void create(){
        ::create();
        set_name("skullcap");
        set_id(({ "skullcap", "cap", "leather" }));
        set_short("%^ORANGE%^Leather Skullcap%^RESET%^");
        set_obvious_short("A leather skullcap");
        set_long(
@AVATAR
%^ORANGE%^This leather skullcap is quite small, obviously made for a human child.  The top of the skullcap has been sectioned off into quarters then stitched closed with thick leather cording.  The bottom of the hat has been rolled up.  It looks well worn, as if it's been in use for some time.

AVATAR
        );
        set_weight(3);
        set_value(15);
        set_lore(
@AVATAR
This Skullcap was made for a child, by his mother or grandmother.  You can almost feel the love that went into this hat.
AVATAR
        );
        set_property("lore difficulty",6);
        set_type("leather");
        set_limbs(({ "head" }));
        set_size(1);
        set_property("enchantment",1);
}
