#include <std.h>
//Updated for weapon feats Octothorpe 5/11/09
inherit "/d/common/obj/weapon/longsword.c";

void create()
{
	::create();
	set_name("Sword of Silver");
	set_short("%^BOLD%^%^WHITE%^Sword of Silver%^RESET%^");
	set_id(({"silver sword","sword of silver","Sword of Silver","longsword","silver longsword","sword","long sword","silver long sword"}));
	set_long(
	"%^WHITE%^%^BOLD%^This straight, double edged longsword is made of pure"+
	" silver. It has some sort of enchantment on it to keep the blade"+
	" from breaking. The hilt of the sword is crafted of braided silver"+
	" and a pegasus has been etched into the bottom of the blade."
	);
        //set_weight(7);
        //set_size(2);
   set_value(40);
        //set_wc(1,8);
        //set_large_wc(1,12);
        //set_type("slashing");
	set_weapon_speed(4);
        set("no curse",1);
	set_property("enchantment",1);
	set_special_material_type("silver");
}
