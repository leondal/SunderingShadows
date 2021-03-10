//Lysara
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^RESET%^%^BOLD%^W%^RESET%^al%^BOLD%^l of F%^BLACK%^a%^RESET%^%^GREEN%^t%^BOLD%^%^WHITE%^e");
   	set_short("%^RESET%^%^A %^BOLD%^shield %^RESET%^%^CYAN%^f%^BOLD%^o%^RESET%^%^CYAN%^rm%^BOLD%^e%^RESET%^%^CYAN%^d"
              " from %^BOLD%^%^WHITE%^mi%^RESET%^st%^BOLD%^y m%^CYAN%^oon%^WHITE%^st%^RESET%^on%^BOLD%^e%^RESET%^%^C"
              "YAN%^%^RESET%^");
   	set_id(({"wall of fate","shield","moonstone shield"}));
   	set_long("%^RESET%^%^CYAN%^This %^BOLD%^%^CYAN%^masterpiece %^RESET%^%^CYAN%^looks to be naturally formed from %^BOLD%^%^WHI"
             "TE%^my%^RESET%^s%^BOLD%^tic%^RESET%^a%^BOLD%^l m%^CYAN%^oo%^WHITE%^nst%^RESET%^on%^BOLD%^e%^RESET%^%^CYAN%^, lined"
             " with a thin border of %^GREEN%^dark green jade%^CYAN%^. Its %^BOLD%^%^WHITE%^mi%^RESET%^st%^BOLD%^y %^RESET%^%^C"
             "YAN%^surface is like a breath of %^WHITE%^gray %^BOLD%^fog%^RESET%^%^CYAN%^, sw%^BOLD%^i%^RESET%^%^CYAN%^rl%^BOLD"
             "%^i%^RESET%^%^CYAN%^ng beneath a %^WHITE%^cr%^BOLD%^yst%^RESET%^al lake%^CYAN%^. It s%^BOLD%^h%^RESET%^%^CYAN%^im"
             "%^BOLD%^mer%^RESET%^%^CYAN%^s and %^WHITE%^dims%^CYAN%^, gl%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^t"
             "%^RESET%^%^CYAN%^er%^BOLD%^%^WHITE%^s %^RESET%^%^CYAN%^and %^BOLD%^%^BLACK%^fades%^RESET%^%^CYAN%^, reflecting the"
             " e%^BOLD%^v%^RESET%^%^CYAN%^erc%^BOLD%^h%^RESET%^%^CYAN%^ang%^BOLD%^i%^RESET%^%^CYAN%^ng hues of %^BOLD%^%^BLUE%^t"
             "%^WHITE%^w%^BLUE%^i%^RESET%^%^CYAN%^l%^GREEN%^i%^MAGENTA%^g%^CYAN%^ht. The beautiful shield tapers naturally down"
             "wards, into a triangular shape, ready to deflect the heaviest of blows. Inside, %^BOLD%^enarmers %^RESET%^%^CYAN%^"
             "weaved from %^GREEN%^blo%^BOLD%^om%^RESET%^%^GREEN%^ing l%^BOLD%^i%^RESET%^%^GREEN%^l%^BOLD%^i%^RESET%^%^GREEN%^es"
             " %^CYAN%^magically change to perfectly fit a %^BOLD%^%^WHITE%^faithful %^RESET%^%^CYAN%^grip. The %^WHITE%^mist %"
             "^CYAN%^sw%^BOLD%^i%^RESET%^%^CYAN%^r%^BOLD%^l%^RESET%^%^CYAN%^s within its %^WHITE%^cr%^BOLD%^yst%^RESET%^al %^CYA"
             "N%^confines, occasionally forming into a %^GREEN%^ghostly %^CYAN%^version of the %^BOLD%^holy symbol %^RESET%^%^CY"
             "AN%^of %^BOLD%^Lysara%^RESET%^%^CYAN%^. Three i%^BOLD%^n%^RESET%^%^CYAN%^t%^BOLD%^e%^RESET%^%^CYAN%^r%^BOLD%^l%^RE"
             "SET%^%^CYAN%^o%^BOLD%^c%^RESET%^%^CYAN%^k%^BOLD%^e%^RESET%^%^CYAN%^d %^BOLD%^rings%^RESET%^%^CYAN%^, one each of %"
             "^BOLD%^%^BLACK%^black%^RESET%^%^CYAN%^, %^WHITE%^gray %^CYAN%^and %^BOLD%^%^WHITE%^white%^RESET%^%^CYAN%^.%^RESET%^");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The misty moonstone of"+
			" "+ETO->QCN+"'s shield rapidly grow in side, blocking "+
                 ""+who->QCN+"'s attack, before they shrink.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^%^RED%^The misty moonstone in the magnificent shield rapidly"+
                  " grow in size, blocking "+who->QCN+"'s attack, before they"+
                  " shrink.");
      	tell_object(who,"%^BOLD%^%^RED%^The misty moonstone of "+ETO->QCN+"'s shield"+
                  " rapidly grow in size, blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
