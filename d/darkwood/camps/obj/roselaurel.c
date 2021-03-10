#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("rose laurel");
	set_id(({ "rose laurel", "laurel" }));
	set_short("%^BOLD%^%^RED%^R%^MAGENTA%^o%^RED%^s%^MAGENTA%^e%^RED%^ Laurel%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^R%^MAGENTA%^o%^RED%^s%^MAGENTA%^e%^RED%^ Laurel%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^RED%^A small crown made up of a cluster of roses.  The tiny roses range in colors from %^BOLD%^%^WHITE%^white%^RED%^,%^MAGENTA%^pink%^RED%^, and %^RESET%^%^RED%^crimson%^BOLD%^.  Silk ribbons have been braided into the leaves of the roses and flutter down one's back.

AVATAR
	);
        set_weight(0);
	set_value(3000);
	set_lore(
@AVATAR
Made by the famed elven jewerler Elderthanal Silverspring

AVATAR
	);
	set_type("ring");
	set_limbs(({ "head" }));
	set_size(2);
	set_property("enchantment",0);
}


