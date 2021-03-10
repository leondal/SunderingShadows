//Helm
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^RESET%^%^CYAN%^Mithril %^RED%^Eagle %^CYAN%^Shield");
        set_short("%^RESET%^%^CYAN%^Mithril %^RED%^Eagle%^CYAN%^ Shield%^RESET%^");
   	set_id(({"mithril eagle shield of protection","shield","mithril eagle shield"}));
   	set_long("%^CYAN%^Crafted out of %^BOLD%^mithril%^RESET%^%^CYAN%^,"+
		" this shield has been polished to a high %^BOLD%^%^WHITE%^"+
		"sheen%^RESET%^%^CYAN%^.  The mithril seems well used, but"+
		" still retains a bright shine to it.  The thick and solid"+
		" kite shield looks as if it could withstand any attack, "+
		"providing plenty of protection.  Emblazed on the front of"+
		" the shield is a %^RED%^red eagle%^CYAN%^ with alert"+
		" %^BOLD%^%^BLUE%^b%^CYAN%^l%^BLUE%^u%^CYAN%^e%^RESET%^"+
		"%^CYAN%^ eyes, keeping a vigilant watch.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^RED%^The eagle on"+
			" "+ETO->QCN+"'s shield lets out a screech, repelling "+
                 ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^RED%^The eagle on your shield "+
			"releases a screech, repelling "+who->QCN+"'s attack.");
      	tell_object(who,"%^RED%^The eagle on "+ETO->QCN+"'s shield"+
                  " release a screech, repelling your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
