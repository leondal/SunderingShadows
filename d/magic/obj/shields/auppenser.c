//Auppenser
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^BLUE%^G%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^o"+
		"%^RESET%^%^BLUE%^d%^BOLD%^%^CYAN%^e %^RESET%^%^CYAN%^Shield"+
		" of P%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^o%^BOLD%^%^BLUE%^t"+
		"%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^c%^RESET%^%^CYAN%^t%^BOLD%^"+
            "%^BLUE%^i%^BOLD%^%^BLACK%^o%^RESET%^%^BLUE%^n%^RESET%^");
   	set_short("%^BOLD%^%^BLUE%^G%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^o"+
		"%^RESET%^%^BLUE%^d%^BOLD%^%^CYAN%^e %^RESET%^%^CYAN%^Shield"+
		" of P%^BOLD%^%^BLACK%^r%^RESET%^%^BLUE%^o%^BOLD%^%^BLUE%^t"+
		"%^RESET%^%^CYAN%^e%^BOLD%^%^BLACK%^c%^RESET%^%^CYAN%^t%^BOLD%^"+
            "%^BLUE%^i%^BOLD%^%^BLACK%^o%^RESET%^%^BLUE%^n%^RESET%^");
   	set_id(({"geode shield of protection","shield","geode shield"}));
   	set_long("%^CYAN%^The outer shell of this geode is formed from a"+
            " %^BOLD%^%^BLACK%^dark black%^RESET%^%^CYAN%^ stone.  The "+
            "surface of the %^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^ stone "+
            "has been polished smooth, and is completely symmetrical.  Shaped"+
            " into a disk, the interior of the geode has been left exposed.  "+
            "Raw %^BOLD%^c%^RESET%^%^BLUE%^r%^BOLD%^y%^RESET%^%^CYAN%^s%^RESET%^"+
            "t%^BOLD%^%^CYAN%^a%^RESET%^%^BLUE%^l%^BOLD%^s%^RESET%^%^CYAN%^ hug "+
            "the surface of the stone, ranging in size and shape. Composed of "+
            "many hues of %^BOLD%^%^BLUE%^b%^RESET%^%^CYAN%^l%^BOLD%^u%^RESET%^"+
            "%^BLUE%^e%^CYAN%^, the crystals have an orderly balance feel to them.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^The crystals of"+
			" "+ETO->QCN+"'s shield rapidly grow in side, blocking "+
                 ""+who->QCN+"'s attack, before they shrink.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^%^CYAN%^The crystals in the geode rapidly"+
                  " grow in size, blocking "+who->QCN+"'s attack, before they"+
                  " shrink.");
      	tell_object(who,"%^BOLD%^%^CYAN%^The crystals of "+ETO->QCN+"'s shield"+
                  " rapidly grow in size, blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
