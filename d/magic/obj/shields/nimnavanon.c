//Kelemvor
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^CYAN%^S%^RESET%^%^GREEN%^p%^CYAN%^e%^BOLD%^"+
		"c%^RESET%^%^GREEN%^t%^CYAN%^r%^BOLD%^a%^RESET%^%^GREEN%^l"+
		" %^CYAN%^Shield");
   	set_short("%^BOLD%^%^CYAN%^S%^RESET%^%^GREEN%^p%^CYAN%^e%^BOLD%^"+
		"c%^RESET%^%^GREEN%^t%^CYAN%^r%^BOLD%^a%^RESET%^%^GREEN%^l"+
                " %^CYAN%^Shield%^RESET%^");
   	set_id(({"spectral shield of protection","shield","spectral shield"}));
   	set_long("%^CYAN%^A faint %^BOLD%^glow%^RESET%^%^CYAN%^ outlines "+
		"the ghostly image of this round shield.  Composed of "+
		"%^GREEN%^s%^CYAN%^p%^BOLD%^e%^GREEN%^c%^RESET%^%^GREEN%^t"+
		"%^CYAN%^r%^BOLD%^a%^GREEN%^l%^RESET%^%^CYAN%^ energy, the "+
		"shield takes on an ethereal quality.  Wavering bands of "+
		"%^GREEN%^green%^CYAN%^ and %^BLUE%^dark blue%^CYAN%^ drift"+
		" around the surface of this shield.  The bands never seem "+
		"to quite blend, always kept separate by some unseen force.  "+
		"An unnatural %^BLUE%^chill%^CYAN%^ radiates off of the "+
		"surface of the shield.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^CYAN%^The spectral energy of"+
			" "+ETO->QCN+"'s shield hardens, repelling "+
                  ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^CYAN%^The spectral energy of your shield"+
			"hardens, repelling "+who->QCN+"'s attack.");
      	tell_object(who,"%^CYAN%^The spectral energy of "+ETO->QCN+"'s"+
			" shield hardens, repelling your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
