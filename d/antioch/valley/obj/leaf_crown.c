// updated wis bonus from the new system. Nienne, 09/07.
#include <std.h>
#include "../valley.h"
inherit "/std/armour";

int FLAG;

void create()
{
	::create();
	set_name("crown of leaves");
	set_id(({"crown","crown of leaves","leaf crown","forest crown","green crown"}));
	set_short("%^RESET%^%^GREEN%^Crown of leaves%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A crown of leaves%^RESET%^");
	set_long(
	"			   %^GREEN%^C%^BOLD%^r%^RESET%^GREEN%^o%^BOLD%^w%^RESET%^%^GREEN%^n%^BOLD%^ %^WHITE%^o%^CYAN%^f %^RED%^L%^YELLOW%^e%^RED%^a%^YELLOW%^v%^RED%^e%^YELLOW%^s%^RESET%^ \n"+
	"	   The crown has four different sections of leaves. \n"+
	"      %^BOLD%^%^GREEN%^The front leaves are vibrant and green,"+
	" representing spring. \n"+
	"%^RESET%^%^GREEN%^To their left are the darker green leaves of the matured plants of summer. \n"+
	"      %^YELLOW%^At the back of the crown are golden and red leaves of autumn. \n"+
	"	   %^WHITE%^On the right are silver leaves of frosty winter.%^RESET%^\n"+
	"			      "
	);
	set_lore("Woven by the druids in the Moonstone Valley the Crown of Leaves"+
		" are given to the sorority of rangers devoted to Mielikki known as"+
		" Swanmays.  These enchanting woman are deeply respected among most"+
		" rangers as the Voice of the Woods.  Upon the introduction in a "+
		"secret ritual the Swanmays cast off their mortal lives to become"+
		" magical fey creatures.  With the ability to transform into swans,"+
		" the Swanmays have proven to be a valuable aid to the defenses of "+
		"the Moonstone Valley.  The Crown of Leaves that they wear, it is "+
		"said brings a sense of clarity to one's mind and puts them deeper "+
		"in touch with the natural world around them.");
	set_property("lore",15);
	set_size(2);
	set_weight(3);
	set_value(575);
	set_type("clothing");
	set_limbs(({"head"}));
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
	set_ac(0);
	set_property("enchantment",2);
	set_item_bonus("wisdom",1);
}

int wearme()
{
        if(ETO->query_highest_level() < 15) {
		tell_object(ETO,"You are not yet experienced enough to use this equipment.");
		return 0;
	}
	tell_object(ETO,"%^BOLD%^%^GREEN%^You place the crown"+
	" on your head and feel more connected with nature.");
	return 1;
}

int removeme()
{
	tell_object(ETO,"%^BOLD%^You feel distant from nature as"+
	" you remove your crown.");
	return 1;
}
