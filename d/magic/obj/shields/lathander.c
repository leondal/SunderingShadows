//Kelemvor
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^RED%^P%^RESET%^%^ORANGE%^h%^YELLOW%^o"+
           "%^RESET%^%^RED%^e%^MAGENTA%^n%^BOLD%^%^RED%^i"+
           "%^YELLOW%^x %^RESET%^%^RED%^F%^ORANGE%^i%^BOLD%^"+
           "r%^RED%^e Shield");
   	set_short("%^BOLD%^%^RED%^P%^RESET%^%^ORANGE%^h%^YELLOW%^o"+
           "%^RESET%^%^RED%^e%^MAGENTA%^n%^BOLD%^%^RED%^i"+
           "%^YELLOW%^x %^RESET%^%^RED%^F%^ORANGE%^i%^BOLD%^"+
           "r%^RED%^e Shield%^RESET%^");
   	set_id(({"phoenix shield of protection","shield","phoenix fire shield"}));
   	set_long("%^BOLD%^%^RED%^Taking the form of a %^BOLD%^p%^RESET%^"+
		"%^ORANGE%^h%^BOLD%^%^MAGENTA%^o%^YELLOW%^e%^RESET%^%^RED%^n"+
		"%^MAGENTA%^i%^BOLD%^%^RED%^x raptor, this shield is composed"+
		" of pure %^YELLOW%^f%^RESET%^%^ORANGE%^i%^RED%^r%^BOLD%^e.  "+
		"The wings of the phoenix are spread and arched over it's head,"+
		" with it's beak open wide as if releasing a scream.  The flames"+
		" that create the shield are %^BOLD%^%^WHITE%^pure%^RED%^ and "+
		"%^MAGENTA%^clean%^RED%^, as if they carry the magic of rebirth in them.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The fires of"+
			" "+ETO->QCN+"'s shield flare, turning back "+
                  ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^%^RED%^The fires of your shield"+
			"flare, turning back "+who->QCN+"'s attack.");
      	tell_object(who,"%^BOLD%^%^RED%^The fires of "+ETO->QCN+"'s"+
			" shield flare, turning back your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
