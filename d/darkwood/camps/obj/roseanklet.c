#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("rose anklet");
	set_id(({ "rose anklet", "anklet" }));
	set_short("%^BOLD%^%^RED%^R%^MAGENTA%^o%^RED%^s%^MAGENTA%^e %^RED%^Anklet");
	set_obvious_short("%^BOLD%^%^RED%^R%^MAGENTA%^o%^RED%^s%^MAGENTA%^e %^RED%^Anklet");
	set_long(
@AVATAR
%^BOLD%^%^RED%^A tiny anklet make up of a cluster of roses. The tiny roses range in colors from %^BOLD%^%^WHITE%^white%^BOLD%^%^RED%^, %^MAGENTA%^pink%^BOLD%^%^RED%^, %^BOLD%^%^RED%^and %^RESET%^%^RED%^crimson%^BOLD%^%^RED%^. Silk ribbons have been braided into the leaves of the roses allowing one to wrap it around their ankle.

AVATAR
	);
        set_weight(0);
	set_value(2500);
	set_lore(
@AVATAR
Made by the famed elven jewerler Elderthanal Silverspring

AVATAR
	);
	set_type("ring");
	set_limbs(({ "left leg" }));
	set_size(2);
	set_property("enchantment",0);
}


