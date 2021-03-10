#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

void create(){
	::create();
	set_name("%^GREEN%^serpent's trench%^RESET%^");
	set_id(({ "coat", "velvet coat", "trench coat", "coat of serpents", "serpent coat" }));
	set_short("%^RESET%^%^GREEN%^Coat of %^BOLD%^S%^RESET%^%^GREEN%^e"+
		"%^YELLOW%^r%^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^e%^YELLOW%^n%^GREEN%^t"+
		"%^RESET%^%^GREEN%^s%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^A green velvet trench coat%^RESET%^");
	set_long("%^GREEN%^Cut from deep green velvet, this masculine trench has a"+
		" sleek look to it.  Embossed into the velvet is a faint pattern of"+
		" interlocking %^BOLD%^serpents%^RESET%^%^GREEN%^ slithering across"+
		" the hem of the coat, and sleeves.  Some of the serpents in the "+
		"pattern rise up, climbing higher up the coat and sleeves.  The "+
		"double breasted coat is full in the chest before tapering in at "+
		"the waist, creating a classic V shape that is pleasing on men. "+
		" %^YELLOW%^Brass%^RESET%^%^GREEN%^ clasps in the shape of coiled"+
		" serpents serve as a way to secure the coat closed.  Chips of "+
		"%^BOLD%^%^BLACK%^malachite %^RESET%^%^GREEN%^and %^BOLD%^peridot"+
		"%^RESET%^%^GREEN%^ create the scales of the brass serpents, "+
		"giving them a life light quality. %^RESET%^\n");
	set_weight(5);
	set_value(2000);
      set_max_internal_encumbrance(21);
	set_lore("Thought to have been crafted at first by a cult of humans "+
		"calling themselves the Children of the Serpents, copies of this"+
		" trench coat have been popping up since 623.  The Children of "+
		"the Serpents view the Yuan-ti as the higher life forms, the "+
		"descendants from the divine serpent known as Set.  The "+
		"apocalyptic group claim that Set will awaken soon to slay "+
		"the gods and to devour the world, and only by following them "+
		"and the Yuan-ti can anyone hope to survive.");
          set_property("lore difficulty", 8);
	set_type("clothing");
	set_limbs(({ "torso" }));
	set_size(2);
        set_property("enchantment",3+random(2));
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){

	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" slips into the velvet coat,"+
			" the serpents dancing in jubilation along the hem.",ETO);
	tell_object(ETO,"%^GREEN%^The serpents on the coat dance in jubilation as you slip"+
			" the coat on.\n%^GREEN%^Hidden in the pattern you find a pair of pockets!");
     	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" loosens the trench coat "+
			"and pulls it off, the serpents along the hem look angry and discontent.",ETO);
	tell_object(ETO,"%^GREEN%^The serpents look angry and discontent as you pull off the coat.");
	return 1;
}
