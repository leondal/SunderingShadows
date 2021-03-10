#include <std.h>
inherit OBJECT;

void create(){
	::create();
	set_name("girl doll");
	set_id(({ "girl doll", "doll", "toy", "fabric doll", "fabric toy", " cloth doll", "cloth girl doll", "cloth toy" }));
	set_short("%^BOLD%^%^MAGENTA%^a cloth doll in the shape of a little girl%^RESET%^");
	set_obvious_short("%^BOLD%^%^MAGENTA%^a cloth doll in the shape of a little girl%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^MAGENTA%^This little doll is made entirely out of cloth.  Her body is sewn from soft %^RESET%^%^ORANGE%^tan cotton%^BOLD%^%^MAGENTA%^ while her clothing is made out of a bit of light weight linen.  %^BOLD%^%^BLACK%^Black yarn %^MAGENTA%^extends from the top of her head and is gathered in a neat pony tail by a %^BOLD%^%^WHITE%^silver clasp%^MAGENTA%^.  A lovely %^RED%^red%^MAGENTA%^ and %^WHITE%^white%^MAGENTA%^ summer dress is fitted over the doll's body.  Princess cut, the top fits close and then flares out into a wide skirt with a little bit of frilly %^WHITE%^white lace%^MAGENTA%^ at the base.  The sleeves are puffy and reach to the middle of the doll's arm where more of the %^WHITE%^white lace%^MAGENTA%^ can be seen.  %^BOLD%^%^BLACK%^Black slippers%^MAGENTA%^ are fitted over the doll's feet and each has a small %^RED%^red bow%^MAGENTA%^ on top.  The doll is stuffed with soft lambs wool making it perfect for cuddling and playing with.%^RESET%^

AVATAR
	);
	set_weight(1);
	set_value(130);
}