#include <std.h>
#include "../elf.h"
inherit "/d/common/obj/clothing/breeches";
int trak;
void create()
{
	::create();
   set_obvious_short("%^BOLD%^%^BLACK%^A pair of noble-looking pants%^RESET%^");
	set_name("Fancy Pants");
	set_short("%^BOLD%^%^BLACK%^Fancy Pants%^RESET%^");
    	set_id(({"pants","fancy pants","noble-looking pants"}));
 	set_long(
	"%^ORANGE%^These pants are very fancy.  They are black with gold"+
    " stitching on the legs that makes them shine.  Anyone doning"+
    " these would become very fancy."
	);
	set_lore("These are pants from an old elven style.  They "+
    "likely were made for diplomats considering the embelishments."+
    "  The style is very old and whoever created them is likely long gone."+
    "Legend has it that the wearer of this is %^RED%^immune to death magic.");
	set_property("lore_difficulty",35);  
	set_property("enchantment",4+random(3));
    set_item_bonus("magic resistance",1);
	set_item_bonus("charisma",2);
	set_value(2500);
	set_wear((:TO,"wearme":));
	set_remove((:TO,"removeme":));
}

int wearme(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^As you pull up the pant, you realize that"+
	" you are very dapper.");
	tell_room(environment(ETO),"%^YELLOW%^"+ETO->QCN+" pulls"+
	" on a pair of noble looking pants.",ETO);
    ETO->add_temporary_feat("death ward");
    trak = 1;
	return 1;
}

int removeme(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You remove your wonderful pants, immediately"+
	" feeling less fancy.");
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+" removes"+
	" "+ETO->query_possessive()+" noble-looking pants.",ETO);
    if(trak){
        ETO->remove_temporary_feat("death ward");
        trak = 0;
    }
	return 1;
}
