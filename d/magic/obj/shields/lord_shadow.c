//Lord shadow
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^RESET%^%^BOLD%^%^BLUE%^W%^CYAN%^al%^BLUE%^l %^BLACK%^of %^CYAN%^D%^RESET%^%^CYA"
             "N%^a%^BOLD%^%^BLUE%^r%^RESET%^%^BLUE%^kn%^BOLD%^e%^RESET%^%^CYAN%^s%^BOLD%^s%^RESET%^");
   	set_short("%^RESET%^%^BOLD%^%^BLACK%^A %^BLUE%^sh%^RESET%^%^BLUE%^ie%^BOLD%^ld %^BLACK%^w%^RESET%^e%^BO"
              "LD%^%^BLACK%^av%^RESET%^e%^BOLD%^%^BLACK%^d from %^BLUE%^p%^RESET%^%^BLUE%^ur%^BOLD%^e %^CYAN"
              "%^d%^RESET%^%^CYAN%^a%^BOLD%^%^BLUE%^r%^RESET%^%^BLUE%^kn%^BOLD%^e%^RESET%^%^CYAN%^s%^BOLD%^s %^RESET%^");
   	set_id(({"wall of darkness ","shield","darkness shield"}));
   	set_long("%^RESET%^%^BOLD%^%^BLACK%^This %^RESET%^%^MAGENTA%^masterpiece %^BOLD%^%^BLACK%^is w%^RESET%^e%^BOLD%^%^"
             "BLACK%^av%^RESET%^e%^BOLD%^%^BLACK%^d from %^BLUE%^p%^RESET%^%^BLUE%^ur%^BOLD%^e %^CYAN%^d%^RESET%^%^CYA"
             "N%^a%^BOLD%^%^BLUE%^r%^RESET%^%^BLUE%^kn%^BOLD%^e%^RESET%^%^CYAN%^s%^BOLD%^s%^BLACK%^, bordered by a %^RE"
             "SET%^%^MAGENTA%^spiked %^BOLD%^%^BLACK%^ed%^CYAN%^g%^BLACK%^e of %^RESET%^%^BLUE%^pitch black onyx%^BOLD%"
             "^%^BLACK%^. Its surface swa%^RESET%^ll%^BOLD%^%^BLACK%^ows %^RESET%^light%^BOLD%^%^BLACK%^, casting a %^"
             "RESET%^%^BLUE%^sh%^BOLD%^ado%^RESET%^%^BLUE%^wy %^BOLD%^%^BLACK%^hue upon its wielder. Dark %^RESET%^%^MA"
             "GENTA%^t%^BOLD%^%^BLUE%^e%^RESET%^%^MAGENTA%^ndri%^BOLD%^%^BLUE%^l%^RESET%^%^MAGENTA%^s %^BOLD%^%^BLACK%^s"
             "wirl within its %^RESET%^%^BLUE%^onyx %^BOLD%^%^BLACK%^confines, as though possessive of %^CYAN%^u%^RESET%"
             "^%^MAGENTA%^nna%^BOLD%^%^CYAN%^tu%^RESET%^%^MAGENTA%^ral life%^BOLD%^%^BLACK%^. The %^RESET%^%^CYAN%^heav"
             "y shield %^BOLD%^%^BLACK%^tapers downwards, into a triangular shape, ready to deflect the heaviest of blows."
             " Inside, the %^RESET%^%^CYAN%^enarmes %^BOLD%^%^BLACK%^are formed from %^BLUE%^inky blackness %^BLACK%^that"
             " %^RESET%^%^BLUE%^obscures %^BOLD%^%^BLACK%^the grip of a %^RESET%^%^MAGENTA%^faithful%^BOLD%^%^BLACK%^. Oc"
             "casionally, the %^RESET%^%^MAGENTA%^t%^BOLD%^%^BLUE%^e%^RESET%^%^MAGENTA%^ndri%^BOLD%^%^BLUE%^l%^RESET%^%^M"
             "AGENTA%^s %^BOLD%^%^BLACK%^of darkness %^CYAN%^gle%^RESET%^%^CYAN%^a%^BOLD%^m %^BLACK%^with an %^CYAN%^azure"
             " light%^BLACK%^, forming to display the %^CYAN%^holy symbol %^BLACK%^of %^RESET%^%^BLUE%^Lord Shadow%^BOLD%^"
             "%^BLACK%^. An %^CYAN%^azure %^RESET%^%^CYAN%^di%^BOLD%^amo%^RESET%^%^CYAN%^nd %^BOLD%^%^BLACK%^upon a %^RESET"
             "%^%^BLUE%^black backdrop%^BOLD%^%^BLACK%^.%^RESET%^");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The darkness of"+
			" "+ETO->QCN+"'s shield rapidly grow in side, blocking "+
                 ""+who->QCN+"'s attack, before they shrink.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^%^RED%^The darkness in the shield rapidly"+
                  " grow in size, blocking "+who->QCN+"'s attack, before they"+
                  " shrink.");
      	tell_object(who,"%^BOLD%^%^RED%^The darkness of "+ETO->QCN+"'s shield"+
                  " rapidly grow in size, blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
