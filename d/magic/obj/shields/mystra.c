//Kelemvor
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^WHITE%^S%^BLUE%^p%^WHITE%^e%^BLUE%^l"+
		"%^WHITE%^l%^BLUE%^f%^WHITE%^i%^BLUE%^r%^WHITE%^e"+
            "%^BLUE%^ Shield");
   	set_short("%^BOLD%^%^WHITE%^S%^BLUE%^p%^WHITE%^e%^BLUE%^l"+
		"%^WHITE%^l%^BLUE%^f%^WHITE%^i%^BLUE%^r%^WHITE%^e"+
            "%^BLUE%^ Shield%^RESET%^");
   	set_id(({"spellfire shield of protection","shield","spellfire shield"}));
   	set_long("%^BLUE%^Woven from %^BOLD%^%^WHITE%^silvery %^BLUE%^blue"+
            " %^RESET%^%^BLUE%^netting, this round shield radiates a"+
		" %^BOLD%^b%^WHITE%^l%^BLUE%^u%^WHITE%^e%^BLUE%^-%^WHITE%^"+
            "w%^BLUE%^h%^WHITE%^i%^BLUE%^t%^WHITE%^e%^RESET%^%^BLUE%^ "+
            "glow.  Looking closer at the webbing, bands of energy can "+
            "be seen moving through the fibers.  From where this power is"+
            ", or what it is composed of, remains a mystery.  The power "+
            "though, is quite clear, and seems extremely ancient.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^The fibers of"+
			" "+ETO->QCN+"'s shield glow, a force pushes back "+
                  ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^%^BLUE%^The fibers of your shield"+
			"glow, a force pushes back "+who->QCN+"'s attack.");
      	tell_object(who,"%^BOLD%^%^BLUE%^The fibers of "+ETO->QCN+"'s"+
			" shield glow, pushing back your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
