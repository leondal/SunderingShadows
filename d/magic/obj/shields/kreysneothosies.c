//Kreysneothosies
#include <std.h>
inherit "/d/magic/obj/shields/divine_shield_inherit";

void create()
{
   ::create();
   	set_name("%^RESET%^%^BOLD%^%^GREEN%^W%^WHITE%^a%^GREEN%^ll %^RESET%^%^GRE"
             "EN%^of %^YELLOW%^J%^WHITE%^u%^ORANGE%^st%^WHITE%^i%^ORANGE%^ce%^RESET%^");
   	set_short("%^RESET%^%^GREEN%^A %^YELLOW%^g%^WHITE%^old%^ORANGE%^en %^BLUE%^dr%^RESET%^%^B"
              "LUE%^a%^BOLD%^go%^RESET%^%^BLUE%^n%^BOLD%^sc%^RESET%^%^BLUE%^a%^BOLD%^le %^RES"
              "ET%^%^GREEN%^s%^BOLD%^hiel%^RESET%^%^GREEN%^d%^RESET%^");
   	set_id(({"wall of justice ","shield","dragonscale shield"}));
   	set_long("%^RESET%^%^GREEN%^This %^YELLOW%^masterpiece %^RESET%^%^GREEN%^is naturally formed"
             " from one large %^BOLD%^%^BLUE%^scale%^RESET%^%^GREEN%^, gifted by a %^YELLOW%^g"
             "o%^WHITE%^l%^ORANGE%^d d%^WHITE%^rago%^ORANGE%^n%^RESET%^%^GREEN%^. The %^BOLD%"
             "^%^WHITE%^metallic %^RESET%^%^GREEN%^exterior gl%^BOLD%^i%^RESET%^%^GREEN%^t%^BO"
             "LD%^te%^RESET%^%^GREEN%^r%^BOLD%^s %^RESET%^%^GREEN%^like the %^YELLOW%^purest"
             "%^RESET%^%^GREEN%^of %^ORANGE%^minerals%^GREEN%^, %^BOLD%^flawless %^RESET%^%^G"
             "REEN%^and %^BOLD%^%^BLUE%^magnificent %^RESET%^%^GREEN%^in its %^ORANGE%^simplic"
             "ity%^GREEN%^. The %^YELLOW%^radiant %^GREEN%^shield %^RESET%^%^GREEN%^tapers nat"
             "urally downwards, into a triangular shape, ready to deflect the heaviest of blows."
             " The inside is %^WHITE%^dimmed %^GREEN%^and %^ORANGE%^leathery%^GREEN%^, like the"
             " %^YELLOW%^rough hide%^RESET%^%^GREEN%^. Sturdy %^YELLOW%^enarmers %^RESET%^%^GREEN%^have"
             " %^ORANGE%^grown %^GREEN%^from the %^BOLD%^living material%^RESET%^%^GREEN%^, magically adj"
             "usting to perfectly fit a %^BOLD%^%^WHITE%^faithful %^RESET%^%^GREEN%^grip.  The %^BOLD%^%^BL"
             "UE%^entire scale %^GREEN%^pulses %^RESET%^%^GREEN%^with the %^YELLOW%^spirit %^RESET%^%^GREEN%^of"
             " %^ORANGE%^justice%^GREEN%^. As %^YELLOW%^light %^RESET%^%^GREEN%^dances across the shield, you"
             " could swear the %^WHITE%^tr%^BOLD%^an%^RESET%^sl%^BOLD%^uce%^RESET%^nt %^BOLD%^image %^RESET%^%^G"
             "REEN%^of a %^BOLD%^%^BLUE%^roaring dragon %^RESET%^%^GREEN%^flared across its surface."
             " %^BOLD%^Emblazoned %^RESET%^%^GREEN%^upon the front of the %^ORANGE%^shield %^GREEN%^is"
             " the %^ORANGE%^holy symbol %^GREEN%^of %^YELLOW%^Kreysneothosies%^RESET%^%^GREEN%^: A %^BOLD%"
             "^%^WHITE%^sword %^RESET%^%^GREEN%^crossed with a %^YELLOW%^sheaf %^RESET%^%^GREEN%^of %^YELLOW%^w"
             "heat%^RESET%^%^GREEN%^.%^RESET%^");
	set_value(0);
	set_struck((:TO,"strikeme":));
}
int strikeme(int damage, object what, object who){
  	if(!random(10)) {
      	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^The dragonscale of"+
			" "+ETO->QCN+"'s shield rapidly grow in side, blocking "+
                 ""+who->QCN+"'s attack, before they shrink.",({ETO,who}));
      	 tell_object(ETO,"%^BOLD%^%^RED%^The dragonscale in the shield rapidly"+
                  " grow in size, blocking "+who->QCN+"'s attack, before they"+
                  " shrink.");
      	tell_object(who,"%^BOLD%^%^RED%^The dragonscale of "+ETO->QCN+"'s shield"+
                  " rapidly grow in size, blocking your attack!");
      		return (-1)*damage;
      	return 1;
   }
}
