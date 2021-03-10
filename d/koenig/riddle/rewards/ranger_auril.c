//Reward for Auril ranger - Cythera 4/05
#include <std.h>
#include "../../nereid.h"
inherit NHIDE;

void create(){
	::create();
//	set_name("auril hide");
	set_id(({"snow leopard hide","hide of the snow leopard","hide","leopard hide"}));
	set_short("%^BOLD%^%^WHITE%^Snow L%^BLACK%^e%^WHITE%^op%^BLACK%^a%^WHITE%^rd Hide%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^A s%^BLACK%^p%^WHITE%^ott%^BLACK%^e%^WHITE%^d white leather hide%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^The snowy white pelt of a snow leopard "+
		"has been used in the creation of this hide armor.  The "+
		"sp%^BLACK%^o%^WHITE%^tt%^BLACK%^e%^WHITE%^d white fur "+
		"has been stretched taunt over a boiled leather base, "+
		"giving a rigid form to the hide.  %^BLACK%^Black spots"+
		"%^WHITE%^ dot the snow white fur, giving this armor a "+
		"wild and exotic look.  The inside of the hide armor has"+
		" been lined in matching fur, to keep the wearer warm.  "+
		"%^CYAN%^Frost%^WHITE%^ and i%^CYAN%^c%^WHITE%^e dusts "+
		"the surface of the fur, in an everlasting display of "+
		"Auril's power.\n%^RESET%^");
	set_lore("The Snow Leopard Hide was crafted for members of a "+
		"rare sect in Auril's faith, the Cats of the Tundra.  "+
		"The Cats of the Tundra were made up of rangers devoted to"+
		" spreading the tenants of the Frost Maiden to those that cross"+
		" the arctic landscape.  The Cats of the Tundra are well known "+
		"for how savage they can be to those that abuse or discredit the"+
		" might that is Auril."  );
   	set_property("lore difficulty",12);
	set_remove((:TO,"remove_func":));
}
int remove_func(){
	tell_object(ETO,"%^BOLD%^%^WHITE%^Your hands brush against the frost"+
		" on the outside of the hide, letting you feel the icy caress of"+
		" Auril's domain.");
	return 1;
}
