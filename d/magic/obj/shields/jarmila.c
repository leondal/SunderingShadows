//Jarmila
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^RESET%^%^YELLOW%^W%^WHITE%^al%^ORANGE%^l %^RESET%^"
             "%^RED%^of %^BOLD%^R%^WHITE%^o%^ORANGE%^s%^WHITE%^e%^RED%^s%^RESET%^");
   	set_short("%^RESET%^%^RED%^A %^BOLD%^magnificent %^ORANGE%^shield %^RESET%^"
              "%^RED%^of %^YELLOW%^p%^WHITE%^ur%^ORANGE%^e g%^WHITE%^ol%^ORANGE%^d%^RESET%^");
   	set_id(({"wall of roses","shield","magnificent shield"}));
   	set_long("%^RED%^This %^BOLD%^masterpiece %^RESET%^%^RED%^is crafted from %^YELLOW%^"
             "p%^WHITE%^ur%^ORANGE%^e g%^WHITE%^ol%^ORANGE%^d%^RESET%^%^RED%^, yet it is"
             " as %^BOLD%^%^WHITE%^solid %^RESET%^%^RED%^and %^BOLD%^%^WHITE%^strong %^"
             "RESET%^%^RED%^as titanium. The %^BOLD%^flawless surface %^RESET%^%^RED%^"
             "sh%^BOLD%^i%^RESET%^%^RED%^m%^YELLOW%^m%^RESET%^%^RED%^e%^BOLD%^r%^RESET%"
             "^%^RED%^s and s%^YELLOW%^h%^RESET%^%^RED%^in%^YELLOW%^e%^RESET%^%^RED%^s"
             " as %^BOLD%^%^WHITE%^li%^RESET%^gh%^BOLD%^t %^RESET%^%^RED%^plays across it,"
             " amplified by the mineral's %^BOLD%^purity%^RESET%^%^RED%^. When %^YELLOW%^g"
             "%^WHITE%^ol%^ORANGE%^d %^RESET%^%^RED%^and %^BOLD%^%^WHITE%^li%^RESET%^gh%^B"
             "OLD%^t %^RESET%^%^RED%^meet at just the right angle, the %^BOLD%^%^WHITE%^s"
             "hield %^ORANGE%^gl%^WHITE%^o%^ORANGE%^ws %^RESET%^%^RED%^strongly as though"
             " a %^YELLOW%^b%^RED%^la%^ORANGE%^z%^RESET%^%^RED%^e with the %^BOLD%^rays %^"
             "RESET%^%^RED%^of the %^YELLOW%^sun %^RESET%^%^RED%^itself. The %^BOLD%^be"
             "autiful %^WHITE%^shield %^RESET%^%^RED%^tapers naturally downwards, into a"
             " triangular shape, ready to deflect the heaviest of blows. Inside, %^YELLO"
             "W%^enarmers %^RESET%^%^RED%^weaved from b%^BOLD%^loo%^ORANGE%^m%^RED%^in%^RE"
             "SET%^%^RED%^g %^YELLOW%^asters %^RESET%^%^RED%^provide a sturdy and secure grip"
             "  for a %^BOLD%^%^WHITE%^faithful %^RESET%^%^RED%^hand. The entire piece is shaped"
             " to display the %^BOLD%^%^WHITE%^holy symbol %^RESET%^%^RED%^of %^YELLOW%^Jarmila%^"
             "RESET%^%^RED%^. Emblazoned upon the %^YELLOW%^go%^WHITE%^ld%^ORANGE%^en sh%^WHITE%"
             "^ie%^ORANGE%^ld %^RESET%^%^RED%^is a %^BOLD%^crimson rose %^RESET%^%^RED%^formed from"
             " sh%^BOLD%^i%^RESET%^%^RED%^m%^BOLD%^m%^RESET%^%^RED%^e%^BOLD%^ri%^RESET%^%^RED%^ng"
             " ru%^BOLD%^bi%^RESET%^%^RED%^es.%^RESET%^");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The roses of"+
			" "+ETO->QCN+"'s shield rapidly grow in side, blocking "+
                 ""+who->QCN+"'s attack, before they shrink.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^%^RED%^The roses in the magnificent shield rapidly"+
                  " grow in size, blocking "+who->QCN+"'s attack, before they"+
                  " shrink.");
      	tell_object(who,"%^BOLD%^%^RED%^The roses of "+ETO->QCN+"'s shield"+
                  " rapidly grow in size, blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
