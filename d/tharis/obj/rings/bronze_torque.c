//coded by Circe 9/14/04 - designed by Eiryasha
#include <std.h>
inherit ARMOUR;

void create()
{
	::create();
	set_name("%^ORANGE%^bronze torque%^RESET%^");
	set_short("%^RESET%^%^GREEN%^an elegant %^ORANGE%^torque "+
         "%^GREEN%^of %^ORANGE%^bronze%^RESET%^");
	set_id(({"torque","necklace","collar","bronze","jewelry","bronze torque"}));
	set_long(
         "%^GREEN%^A simple %^ORANGE%^collar %^GREEN%^of %^ORANGE%^"+
         "twisted bronze %^GREEN%^that rests upon the collar bone.  "+
         "Commonly worn by %^RESET%^%^BOLD%^Tharisians %^RESET%^"+
         "%^GREEN%^of moderate wealth or the favored servants of the "+
         "truly affluent.%^RESET%^"
	);
	set_weight(1);
	set_value(800);
	set_type("ring");
	set_limbs(({"neck"}));
}
