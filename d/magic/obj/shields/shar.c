//Selune
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^N%^BLUE%^i%^RESET%^%^MAGENTA%^g"+
            "%^BOLD%^%^BLACK%^ht Shield");
   	set_short("%^BOLD%^%^BLACK%^N%^BLUE%^i%^RESET%^%^MAGENTA%^g"+
            "%^BOLD%^%^BLACK%^ht Shield%^RESET%^");
   	set_id(({"night shield of protection","shield","night shield"}));
   	set_long("%^BLUE%^An inky %^MAGENTA%^violet%^BLUE%^ cloud creates"+
		" the surface of this shield.  Within the cloud, a faint"+
            " glimmer of %^BOLD%^%^WHITE%^s%^RESET%^t%^BOLD%^a%^RESET%^r%^BOLD%^s"+
            "%^RESET%^%^BLUE%^ can be seen.  The %^RESET%^s%^BOLD%^t%^RESET%^"+
            "a%^BOLD%^r%^RESET%^s%^BLUE%^ follow no pattern or rhythm, they"+
            " move at their own will.  They shine with a faint %^MAGENTA%^"+
            "amethyst%^RESET%^%^BLUE%^ radiance, pulsating and twinkling.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^MAGENTA%^The stars of"+
			" "+ETO->QCN+"'s shield spiral around, driving back "+
                  ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^MAGENTA%^The stars of your shield"+
			"spiral around, driving back "+who->QCN+"'s attack.");
      	tell_object(who,"%^MAGENTA%^The stars of "+ETO->QCN+"'s"+
			" shield spiral around, driving back your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
