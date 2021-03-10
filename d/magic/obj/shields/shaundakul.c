//Shaundakul
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^RESET%^%^CYAN%^W%^BOLD%^i%^RESET%^%^CYAN%^"+
            "n%^BOLD%^d Shield");
   	set_short("%^RESET%^%^CYAN%^W%^BOLD%^i%^RESET%^%^CYAN%^"+
           "n%^BOLD%^d Shield%^RESET%^");
   	set_id(({"wind shield of protection","shield","wind shield"}));
   	set_long("%^CYAN%^A whirling mass of %^BOLD%^air%^RESET%^"+
		"%^CYAN%^ collects to create this buckler.  While "+
		"the buckler may be small, it carries with it a "+
		"promise of great power.  The whirling winds vibrate"+
		" the force that makes up this shield.  In the center"+
		" of the buckler, a small area of dead calm can be seen."+
		"  The winds calm for a moment before they pick up in "+
		"speed once more, raising to a howling %^BOLD%^%^BLACK%^"+
		"gale%^RESET%^%^CYAN%^ before falling back to a slight "+
            "%^MAGENTA%^breeze.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^CYAN%^A gust of wind rises off"+
			" of "+ETO->QCN+"'s shield, knocking back "+
                  ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^CYAN%^A gust of wind rises off your shield"+
			"knocking back "+who->QCN+"'s attack.");
      	tell_object(who,"%^CYAN%^A gust of wind rises off of "+ETO->QCN+"'s"+
			" shield knocking back your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
