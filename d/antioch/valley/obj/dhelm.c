//Set to inherit common helm - Octothorpe 12/27/09
//dhelm.c - Added new long desc that showed the helm is different from a normal chain coif.  Circe 11/22/03

#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/armour/helm.c";

void create()
{
	::create();
    set_obvious_short("a silver helm");
	set_name("%^BLACK%^%^BOLD%^Darkened Helm%^RESET%^");
    set_id(({"helm","darkened helm","dark helm","helmet","shadow helm"}));
	set_short("%^BLACK%^%^BOLD%^Darkened Helm%^RESET%^");
    set_lore("%^BLACK%^%^BOLD%^Darkened Helm\n"+
	   "While this was once a shiny silver helm, it has been soaked"+
   	   " in the stuff of shadows, casting a gray sheen on the helm"+
	   " and making it dark. On the edges of the helmet are delicate"+
	   " carvings. You cannot tell what they once were, for now they"+
	   " have been warped by evil and appear to be slithering serpents.");
    set_long("Originally a shiny silver helm, something has cast a gray sheen "+
         "over the helm, leaving it dark.  Delicate carvings are along the edges "+
         "of the helmet, but you cannot tell what they once were.  Now they "+
         "appear to be slithering serpents.");
/*this long description added to show that it was magical & reflect what it really looks like.  We can change it if need be.  Before it was just the normal coif description, which was confusing people.  Circe
*/
 	//set_size(2);
    set_property("enchantment",2);
	set_value(20);
	//set_weight(10);
	//set_limbs(({"head"}));
	//set_type("armour");
	set_wear((:TO, "wearme":));
	set_remove((:TO, "removeme":));
	//set_ac(1);
	set_property("lore difficulty",3);
}

int wearme()
{
	int align;

	align = ETO->query_alignment();
	if(ETO->query_level() < 10) {
		notify_fail("You are not adept enough to use this equipment.");
		return 0;
	}
	switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"%^BLACK%^%^BOLD%^The helm fits very"+
			" nicely, almost as though it were made just for you.");
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BLUE%^%^BOLD%^As you slip the helm"+
			" onto your head you could swear you heard a myraid of"+
			" voices for a brief moment, but now all is quiet.");
			tell_room(environment(ETO),"%^BOLD%^%^BLUE%^"+ETO->query_cap_name()+" slips the %^BLACK%^Darkened Helm%^BLUE%^ on"+
			" "+ETO->query_possessive()+" head almost hesitantly.",ETO);
			return 1;

		case 1: case 4: case 7:
			 tell_object(ETO,"%^BOLD%^%^CYAN%^The snakes seem to"+
			" hiss at you as you place the helm on your head.");
   if((int)TO->query_property("enchantment")) {
     TO->remove_property("enchantment");
   }
                        return 1;
	}
}

int removeme()
{
	int align;

	align = ETO->query_alignment();
	switch(align) {
		case 3: case 6: case 9:
			tell_object(ETO,"%^BLACK%^%^BOLD%^You remove the"+
			" comfortable helm reluctantly.");
			return 1;

		case 2: case 5: case 8:
			tell_object(ETO,"%^BLUE%^%^BOLD%^You feel slightly dizzy"+
			" as you remove the helm, a thousand voices seem to echo"+
			" all at once in your mind and abruptly they are gone.");
			tell_room(environment(ETO),"%^BLUE%^%^BOLD%^"+ETO->query_cap_name()+" sways slightly as "+ETO->query_subjective()+""+
			" takes off the %^BLACK%^Darkened Helm.",ETO);
			return 1;
			
		case 1: case 4: case 7:
			tell_object(ETO,"%^BOLD%^%^CYAN%^The snakes on the helmet"+
			" cease their hissing as you finally remove the evil thing.");
   if(!(int)TO->query_property("enchantment")) {
     while((int)TO->query_property("enchantment") != 2) {
       TO->remove_property("enchantment");
       TO->set_property("enchantment",2);
     }
   }
                        return 1;
	}
}
