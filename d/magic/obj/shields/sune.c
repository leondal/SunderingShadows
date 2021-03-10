#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
    ::create();
    set_name("%^YELLOW%^Golden La%^RED%^t%^YELLOW%^t"+
      "%^RED%^i%^YELLOW%^ce Shield");
    set_short("%^YELLOW%^Golden La%^RED%^t%^YELLOW%^t"+
      "%^RED%^i%^YELLOW%^ce Shield%^RESET%^");
    set_id(({"golden lattice shield of protection","shield","golden lattice shield"}));
    set_long("%^RED%^This strange shield takes the form of a cloth "+
      "of %^YELLOW%^gol%^RESET%^%^ORANGE%^d%^YELLOW%^en"+
      "%^RESET%^%^RED%^ lace.  Woven with the glittering lattice"+
      " are threads of radiant %^BOLD%^rubies%^RESET%^%^RED%^.  "+
      "The fabric is woven into an intricate %^YELLOW%^ne%^RED%^t"+
      "%^YELLOW%^t%^RED%^i%^YELLOW%^ng%^RESET%^%^RED%^, without a single flaw.  "+
      "The cloth it seems is made to wear woven around one's hand."+
      "  Though it looks delicate and fragile, a glimmer about it "+
      "carries a feeling of %^BOLD%^strength%^RESET%^%^RED%^ and"+
      " %^BOLD%^%^WHITE%^protection%^RESET%^%^RED%^.\n");
    set_value(0);
    set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
    if(!random(10)) {
	tell_room(environment(query_worn()),"%^YELLOW%^Sparkling motes "+
	  "dance across the surface of "+ETO->QCN+"'s shield, driving back "+
         ""+who->QCN+"'s attack.",({ETO,who}));
	tell_object(ETO,"%^YELLOW%^Sparkling motes dance across the surface"+
	  "of your shield, driving back "+who->QCN+"'s attack.");
	tell_object(who,"%^YELLOW%^Sparkling motes dance across "+
	  "the surface of "+ETO->QCN+"'s"+
	  " shield, driving back your attack!");
	return (-1)*damage;
	return 1;
    }
}
