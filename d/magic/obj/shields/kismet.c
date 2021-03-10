//Kismet
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^RESET%^%^MAGENTA%^W%^CYAN%^al%^MAGENTA%^l of I%^BOLD%^%^BLUE%^r%^GREEN%^id%^CYA"
             "N%^e%^RESET%^%^MAGENTA%^s%^BOLD%^%^BLUE%^ce%^GREEN%^nc%^RESET%^%^MAGENTA%^e%^RESET%^");
   	set_short("%^RESET%^%^WHITE%^An %^MAGENTA%^i%^BOLD%^%^BLUE%^r%^GREEN%^id%^CYAN%^e%^BLUE%^sc%^G"
              "REEN%^en%^RESET%^%^MAGENTA%^t %^BOLD%^%^WHITE%^d%^RESET%^ia%^BOLD%^%^MAGENTA%^m%^RE"
              "SET%^on%^BOLD%^d s%^RESET%^h%^BOLD%^%^MAGENTA%^i%^RESET%^e%^BOLD%^ld%^RESET%^");
   	set_id(({"wall of iridescence ","shield","diamond shield"}));
   	set_long("%^RESET%^%^MAGENTA%^This %^BOLD%^%^GREEN%^masterpiece %^RESET%^%^MAGENTA%^is shaped"
             " from one piece of %^BOLD%^%^WHITE%^diamond%^RESET%^%^MAGENTA%^, as %^WHITE%^solid"
             " %^MAGENTA%^as it is i%^BOLD%^%^BLUE%^r%^GREEN%^id%^CYAN%^e%^BLUE%^sc%^GREEN%^en%^"
             "RESET%^%^MAGENTA%^t. The s%^BOLD%^h%^RESET%^%^MAGENTA%^imm%^BOLD%^e%^RESET%^%^M"
             "AGENTA%^r%^BOLD%^i%^RESET%^%^MAGENTA%^ng surface seems to re%^BOLD%^%^GREEN%^f%^R"
             "ESET%^%^MAGENTA%^r%^BOLD%^%^GREEN%^a%^RESET%^%^MAGENTA%^ct re%^WHITE%^a%^MAGENTA%^"
             "l%^WHITE%^i%^MAGENTA%^t%^WHITE%^y %^MAGENTA%^itself, %^WHITE%^b%^MAGENTA%^rea%^WHIT"
             "E%^k%^MAGENTA%^in%^WHITE%^g %^MAGENTA%^any image reflecting off it into a %^BOLD%^m"
             "illion %^RESET%^%^MAGENTA%^p%^GREEN%^i%^MAGENTA%^ec%^GREEN%^e%^MAGENTA%^s.  As the"
             " light hits the %^BOLD%^%^WHITE%^flawless d%^RESET%^ia%^BOLD%^%^MAGENTA%^m%^RESET%^"
             "on%^BOLD%^d%^RESET%^%^MAGENTA%^, a myriad of %^GREEN%^c%^MAGENTA%^o%^BOLD%^l%^RESET%^"
             "%^MAGENTA%^o%^BOLD%^%^BLUE%^r%^RESET%^%^MAGENTA%^s dance across it in d%^GREEN%^i%^BO"
             "LD%^s%^RESET%^%^MAGENTA%^to%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^t%^BOLD%^i%^RESET%^%^MA"
             "GENTA%^on. The heavy shield tapers downwards, into a triangular shape, ready to defle"
             "ct the heaviest of blows. The inside of the %^BOLD%^%^WHITE%^shield %^RESET%^%^MAGENTA%"
             "^is %^WHITE%^dimmed %^MAGENTA%^so as not to impair vision and sturdy %^BOLD%^enarmers %^RES"
             "ET%^%^MAGENTA%^woven from %^GREEN%^ferns %^MAGENTA%^magically adjust to fit a faithful grip."
             " Occasionally, the i%^BOLD%^%^BLUE%^r%^GREEN%^id%^CYAN%^e%^BLUE%^sc%^GREEN%^en%^RESET%^%^MAGE"
             "NTA%^t %^GREEN%^c%^MAGENTA%^o%^BOLD%^l%^RESET%^%^MAGENTA%^o%^BOLD%^%^BLUE%^r%^RESET%^%^MAGENT"
             "A%^s take on a %^BOLD%^life %^RESET%^%^MAGENTA%^of its own, joining to form the %^BOLD%^%^WHIT"
            "E%^holy symbol %^RESET%^%^MAGENTA%^of %^BOLD%^Kismet%^RESET%^%^MAGENTA%^."
            "A %^WHITE%^blank scroll %^MAGENTA%^crossed by a %^BOLD%^%^WHITE%^quill"
            " %^RESET%^%^MAGENTA%^and a %^GREEN%^smith's hammer%^MAGENTA%^. %^RESET%^");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The diamond of"+
			" "+ETO->QCN+"'s shield rapidly grow in side, blocking "+
                 ""+who->QCN+"'s attack, before they shrink.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^%^RED%^The diamond in the shield rapidly"+
                  " grow in size, blocking "+who->QCN+"'s attack, before they"+
                  " shrink.");
      	tell_object(who,"%^BOLD%^%^RED%^The diamond of "+ETO->QCN+"'s shield"+
                  " rapidly grow in size, blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
