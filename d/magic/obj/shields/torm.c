//Sune
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^YELLOW%^Golden Lion Shield");
        set_short("%^YELLOW%^Golden Lion Shield%^RESET%^");
   	set_id(({"golden lion shield of protection","shield","golden lion shield"}));
       set_long("%^BOLD%^%^BLUE%^Fashioned from %^YELLOW%^gold%^BLUE%^,"+
          	" this solid kite shield bears the image of a regal lion.  "+
          	"The solid thick shield looks ready to repel any attack, "+
		"and stand strong.  The shield is polished to a brilliant"+
               " %^WHITE%^sheen%^BLUE%^, and in impeccable condition.  "+
		"With a curling mane that radiates outwards, the %^YELLOW%^"+
		"lion's head%^BLUE%^ on the shield carries a valorous regal "+
               "air to it.  %^WHITE%^White diamonds%^BLUE%^ are inlaid "+
		"into its eyes, sparkling with a pure courageous light.\n");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^YELLOW%^With a valorous roar"+
			""+ETO->QCN+"'s shield repels back "+
                 ""+who->QCN+"'s attack.",({ETO,who}));
      	 tell_object(ETO,"%^YELLOW%^With a valorous roar your shield"+
			" repels back "+who->QCN+"'s attack.");
      	tell_object(who,"%^YELLOW%^With a valorous roar"+
                  ""+ETO->QCN+"'s shield repels back your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
