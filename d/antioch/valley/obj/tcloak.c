#include <std.h>
#include "../valley.h"
inherit "/std/armour";

void create()
{
	::create();
	set_name("tattered cloak");
	set_id(({"tattered cloak","cloak"}));
	set_short("Tattered cloak");
	set_long(
	"This tattered cloak is covered in filth. It has a crusty"+
      " layer of dirt on it mixed with other things that can't be"+
	" named, giving it a ghastly smell. It's badly in need of"+
	" a good cleaning and patching."
	);
	set_size(2);
	set_property("enchantment",2);
	set_value(80);
	set_cointype("silver");
	set_weight(5);
//        set_ac(-2);
	set_limbs(({"neck"}));
	set_type("clothing");
	set_wear((:TO,"wear_me":));
	set_remove((:TO,"remove_me":));
}

int wear_me()
{
	write("You place the cloak about your neck and can almost"+
	" feel the lice climbing up your neck and into your hair.");
	return 1;
}

int remove_me()
{
	write("You remove the filthy cloak, glad to have it off!");
	return 1;
}
