//Kelemvor
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^RED%^L%^YELLOW%^a%^RESET%^%^RED%^"+
		"v%^BOLD%^a Shield");
   	set_short("%^BOLD%^%^RED%^L%^YELLOW%^a%^RESET%^%^RED%^"+
                "v%^BOLD%^a Shield%^RESET%^");
   	set_id(({"lava shield of protection","shield","lava shield"}));
   	set_long("%^RED%^Composed of molten magma, this shield of "+
		"%^BOLD%^l%^RESET%^%^RED%^a%^BOLD%^%^RED%^v%^RESET%^"+
		"%^RED%^a radiates an intense heat.  The lava bubbles"+
		" and hisses as it moves about to create this round "+
		"shield.  Even when exposed to the air, the lava never"+
		" cools or hardens, it continues to remain %^BOLD%^fiery"+
		" hot%^RESET%^%^RED%^.  On occasion, a bubble of air will"+
		" rise to the surface and pop, spraying hot lava onto the"+
		" ground.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^RED%^The lava of"+
			" "+ETO->QCN+"'s shield speeds up, the waves of heat "+
                  "blocking "+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^RED%^The lava of your shield"+
			"speeds up, the waves of heat blocking"+
			" "+who->QCN+"'s attack.");
      	tell_object(who,"%^RED%^The lava of "+ETO->QCN+"'s"+
			" shield speeds up, waves of heat blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
