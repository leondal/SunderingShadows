#include <std.h>
#include "../elf.h"
inherit "/d/common/obj/jewelry/anklet";

void create(){
    ::create();
    set_name("anklet");
    set_id(({ "anklet", "sea bells", "roped anklets","anklets"}));
    set_short("%^CYAN%^s%^RESET%^e%^CYAN%^a b%^MAGENTA%^e%^CYAN%^lls%^RESET%^");
    set_obvious_short("%^RESET%^%^ORANGE%^roped anklets%^RESET%^");
    set_long("%^ORANGE%^These are anklets that are made of a silk rope. "+
	" They wrap around the ankle and have a second band that "+
	"wraps under the foot.  Upon the ankle sits a %^CYAN%^pearl%^ORANGE%^ that "+
	"is etched with %^CYAN%^mystical runes%^ORANGE%^.  It seems to shimmer with a %^CYAN%^mystical static.%^RESET%^");
    set_lore("It is rumored that the legendary elven pirate "+
	"Innithali had a flair for pearls.  It is also rumored that"+
	" she had a flair for magic.  Bards sing of a battle she was"+
	" in where a captain of a ship she raided was fighting her "+
	"in a dual and he launched a trip attack against her only "+
	"for the blow to pass through her feet like water.  This "+
	"turned the tide of battle and she forced the man to "+
	"surrender his cargo.");
    set_property("lore difficulty",35);
    set_value(5000);
    set_size(-1);
    set_property("enchantment",4);
    set_item_bonus("reflex",3);
    set_remove((:TO,"remove_func":));
    set_wear( (:TO,"check":) );
    set_struck((:TO,"strike_func":));
	set_item_bonus("cold resistance",30);
}

int check(){
      tell_object(ETO,"%^CYAN%^You slip your feet into "+
	  "the anklets and thoughts of a cool sea "+
	  "breeze through your mind.");
      tell_room(EETO,"%^CYAN%^"+ETOQCN+" slips their feet into the anklets. ",ETO);
      return 1;
}

int remove_func(){
    tell_object(ETO,"%^CYAN%^You remove the anklets and feel dehydrated.");
    return 1;
}

int strikeme(int damage, object what, object who){
        if(random(1000) < 250){
        tell_room(EETO,"%^CYAN%^"+who->QCN+
         "attack splashes harmlessly through"+ETOQCN+" like water.",ETO);
        tell_object(ETO,"%^CYAN%^Instead of connecting, the attack of "
		+who->QCN+" harmlessly passes through your legs "+
		"with a splash like it struck water.");
        return (damage*-1);
   }
}
