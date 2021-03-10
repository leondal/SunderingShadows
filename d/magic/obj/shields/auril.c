//Auril
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^BOLD%^%^WHITE%^F%^CYAN%^r%^WHITE%^o%^CYAN%^s%^WHITE%^t"+
            " Shield%^RESET%^");
   	set_short("%^BOLD%^%^WHITE%^F%^CYAN%^r%^WHITE%^o%^CYAN%^s%^WHITE%^t"+
            " Shield%^RESET%^%^RESET%^");
   	set_id(({"frost shield of protection","shield","frost shield"}));
   	set_long("%^BOLD%^%^BLUE%^A concentrated mass of frigid %^CYAN%^arctic"+
		" wind%^BLUE%^ and %^BOLD%^%^WHITE%^frost%^BLUE%^ create this "+
		"shield.  The wind howls ferociously, as %^BOLD%^%^WHITE%^snowflakes"+
		" %^BLUE%^swirl around in a wild and untamed fashion.  The mass of "+
		"air is thick with %^WHITE%^f%^CYAN%^r%^WHITE%^o%^CYAN%^s%^WHITE%^t"+
                "%^BLUE%^, to the point of making everything opaque.  Frigid cold "+
		"radiates off the shield, creating a trail of %^RESET%^vapor"+
		"%^BOLD%^%^BLUE%^ around it.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^The frost of"+
			" "+ETO->QCN+"'s shield solidifies, repelling "+
                  ""+who->QCN+"'s attack, before it cracks.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^The mass of frost solidifies"+
                  ", repelling "+who->QCN+"'s attack, before it cracks,"+
                  " returning back to its previous form.");
      	tell_object(who,"%^BOLD%^The frost of "+ETO->QCN+"'s shield"+
                  " solidifies, repelling your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
