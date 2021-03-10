//coded by Circe 9/14/04 - designed by Eiryasha
#include <std.h>
inherit ARMOUR;

void create()
{
	::create();
	set_name("golden rose anklet");
	set_short("%^YELLOW%^anklet of golden roses%^RESET%^");
	set_id(({"anklet","rose","roses","golden roses","vine","golden vine"}));
	set_long(
         "%^BOLD%^A loop fashioned from gleaming gold to resemble "+
         "viney roses wrapped around the ankle.  The golden anklet "+
         "is soft to the touch with the thorns of the vines blunted "+
         "so as not to harm the wearer.%^RESET%^"
	);
	set_weight(1);
	set_value(150);
	set_type("ring");
	set_limbs(({"right foot"}));
}
