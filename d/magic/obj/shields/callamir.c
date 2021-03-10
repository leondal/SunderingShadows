//Sune
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^MAGENTA%^R%^BOLD%^%^WHITE%^i%^BLUE%^g%^WHITE%^h%^BLUE%^"+
		"t%^WHITE%^e%^BLUE%^o%^WHITE%^u%^RESET%^%^MAGENTA%^s "+
		"%^BLUE%^%^BOLD%^Wolf Shield");
   	set_short("%^MAGENTA%^R%^BOLD%^%^WHITE%^i%^BLUE%^g%^WHITE%^h%^BLUE%^"+
		"t%^WHITE%^e%^BLUE%^o%^WHITE%^u%^RESET%^%^MAGENTA%^s "+
                "%^BLUE%^%^BOLD%^Wolf Shield%^RESET%^");
   	set_id(({"righteous wolf shield of protection","shield","righteous wolf shield"}));
   	set_long("%^BLUE%^%^BOLD%^Crafted out of %^RESET%^%^MAGENTA%^purple"+
		"%^BOLD%^%^BLUE%^ hued metal, this large kite shield is thick"+
		" and solid.  The shield carries a feeling of %^BOLD%^%^BLACK%^"+
		"antiquity%^BLUE%^ with it, from the well worn edges to the nicks"+
		" and cuts into the metal.  Though it does posses some signs of use,"+
		" the shield still retains a %^WHITE%^clean%^BLUE%^ and well cared "+
		"for feeling.  Emblazing on the front of the shield is an image of a"+
		" %^RESET%^silver wolf%^BOLD%^%^BLUE%^.  The wolf's eyes are bound by"+
		" %^WHITE%^white%^BLUE%^ cloth, though he stands erect, striking a "+
		"righteous pose.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^The wolf on"+
			""+ETO->QCN+"'s shield growls as it swats back "+
                  ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^The wolf on your shield"+
			" growls as it swats back "+who->QCN+"'s attack.");
      	tell_object(who,"%^BOLD%^The wolf on "+ETO->QCN+"'s shield"+
			" growls as it swats back your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
