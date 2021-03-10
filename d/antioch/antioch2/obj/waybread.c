#include <std.h>
inherit "/std/food.c";

void create()
{
	::create();
	set_name("waybread");
	set_short("Elven waybread");
	set_id(({"waybread","elven waybread","Elven waybread","bread","way bread","food"}));
	set_long(
	"This is a loaf of elven waybread.  It was made by Andrerrard from a"+
	" recipe handed down in his family.  It has a light taste but is very"+
	" durable and filling."
	);
	set_weight(5);
	set_value(20);
	set_destroy();
	set_poison(0);
   set_strength(50);
	set_canSave(1);
   set_my_mess("The elven waybread is filling, though only has a light taste.");
	set_your_mess("eats some elven waybread.");
}
