//Grumbar
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^RESET%^%^ORANGE%^S%^YELLOW%^a%^RESET%^%^ORANGE%^n"+
		"%^YELLOW%^d%^RESET%^%^ORANGE%^ Shield");
   	set_short("%^RESET%^%^ORANGE%^S%^YELLOW%^a%^RESET%^%^ORANGE%^n"+
                "%^YELLOW%^d%^RESET%^%^ORANGE%^ Shield%^RESET%^");
   	set_id(({"sand shield of protection","shield","sand shield"}));
   	set_long("%^ORANGE%^Composed of a swirling mass of %^BOLD%^sand"+
		"%^RESET%^%^ORANGE%^, this shield vaguely resembles a tower"+
		" shield.  The sand is of fine grit, allowing to to move "+
		"with ease in a uniform and solid pattern.  Bits of "+
		"%^RESET%^mica%^ORANGE%^, %^BOLD%^%^WHITE%^quartz%^RESET%^"+
		"%^ORANGE%^, and %^BOLD%^%^BLACK%^raw ores%^RESET%^%^ORANGE%^"+
		" can be seen in the sand, glinting in the surrounding light."+
		"  The sand fixes itself in place, never wavering outside of "+
		"the tower shield shape.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^ORANGE%^The sand of"+
			" "+ETO->QCN+"'s shield solidifies, blocking "+
                 ""+who->QCN+"'s attack, before crumbles apart.",({ETO,who}));
      	 tell_object(ETO,"%^RED%^The sand of the shield "+
			"solidifies, blocking "+who->QCN+"'s attack,"+
			" before crumbling apart.");
      	tell_object(who,"%^RED%^The sand of "+ETO->QCN+"'s shield"+
                  " solidifies, blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
