//Bane
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLACK%^Sp%^RED%^i%^BLACK%^ked"+
               " Ra%^GREEN%^v%^BOLD%^%^BLACK%^en Sh"+
		"%^BOLD%^%^RED%^i%^BLACK%^eld%^RESET%^");
   	set_short("%^BOLD%^%^BLACK%^Sp%^RED%^i%^BLACK%^ked"+
		" Ra%^GREEN%^v%^BOLD%^%^BLACK%^en Sh"+
		"%^BOLD%^%^RED%^i%^BLACK%^eld%^RESET%^");
   	set_id(({"spiked raven shield of protection","shield","spiked raven shield"}));
   	set_long("%^BOLD%^%^BLACK%^Crafted from blackened titanium this"+
		" shield has a wicked and deadly appearance.  Twisted spikes"+
		" run around the outer lip of the shield, in an orderly and"+
		" uniform size.  Sharpened to a razor edge, the spikes "+
		"%^WHITE%^glint%^BOLD%^%^BLACK%^ in the surrounding light"+
		", giving them an intimidating appearance.  Set on the "+
		"surface of the shield is an image of five black ravens, "+
		"in a circle.  %^GREEN%^Emeralds%^BOLD%^%^BLACK%^ have "+
		"been inlaid into the eyes of the black ravens, adding a"+
           " %^BOLD%^%^RED%^m%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^l%^RED%^"+
                "e%^RESET%^%^RED%^v%^BOLD%^%^RED%^o%^RESET%^%^RED%^l"+
		"%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^n%^BOLD%^t%^BLACK%^ "+
		"feeling to them. \n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^RED%^The spikes of"+
			" "+ETO->QCN+"'s shield surge in size, blocking "+
                  ""+who->QCN+"'s attack, before they return to normal.",({ETO,who}));
      	 tell_object(ETO,"%^RED%^The spikes on the shield "+
			"surge in size, blocking "+who->QCN+"'s attack,"+
			" before returning to normal.");
      	tell_object(who,"%^RED%^The spikes of "+ETO->QCN+"'s shield"+
                  " surge in size, blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
