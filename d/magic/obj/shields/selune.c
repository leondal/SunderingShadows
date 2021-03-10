//Selune
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
        set_name("%^BOLD%^%^WHITE%^S%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^l%^RESET%^i%^BOLD%^g%^RESET%^h%^BOLD%^t Shield%^RESET%^");
        set_short("%^BOLD%^%^WHITE%^S%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^l%^RESET%^i%^BOLD%^g%^RESET%^h%^BOLD%^t Shield%^RESET%^");
   	set_id(({"starlight shield of protection","shield","starlight shield"}));
   	set_long("%^BLUE%^A soft %^MAGENTA%^violet%^BLUE%^ cloud creates"+
		" the surface of this shield.  Within the cloud, a multitude"+
            " of %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^s"+
            "%^RESET%^%^BLUE%^ can be seen.  The %^RESET%^s%^BOLD%^t%^RESET%^"+
            "a%^BOLD%^r%^RESET%^s%^BLUE%^ follow no pattern or rhythm, they"+
            " move at their own will.  They shine with a faint %^BOLD%^"+
            "%^WHITE%^silver%^RESET%^%^BLUE%^ radiance, pulsating and twinkling.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^The stars of"+
			" "+ETO->QCN+"'s shield spiral around, driving back "+
                  ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^The stars of your shield"+
			"spiral around, driving back "+who->QCN+"'s attack.");
      	tell_object(who,"%^BOLD%^The stars of "+ETO->QCN+"'s"+
			" shield spiral around, driving back your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
