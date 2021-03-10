// Redid it because no one seems to like :( - Cythera
#include <std.h>
inherit "/d/common/obj/armour/leather.c";
#define COLORS ({"%^RESET%^%^RED%^R%^BOLD%^u%^RESET%^%^RED%^b%^BOLD%^y",\
"%^BOLD%^%^BLUE%^S%^CYAN%^a%^RESET%^%^CYAN%^p%^BLUE%^p%^BOLD%^h%^CYAN%^i%^RESET%^%^CYAN%^r%^BLUE%^e",\
"%^BOLD%^%^GREEN%^E%^RESET%^%^GREEN%^m%^BOLD%^%^GREEN%^eral%^RESET%^%^GREEN%^d",\
"%^BOLD%^%^BLACK%^O%^RESET%^n%^BOLD%^%^BLACK%^y%^RESET%^x",\
"%^RESET%^%^MAGENTA%^Am%^BOLD%^e%^RESET%^%^MAGENTA%^th%^BOLD%^y%^RESET%^%^MAGENTA%^st",\
"%^BOLD%^%^WHITE%^S%^RESET%^i%^BOLD%^l%^RESET%^v%^BOLD%^e%^RESET%^r",\
"%^RESET%^%^CYAN%^Aq%^BOLD%^u%^RESET%^%^CYAN%^am%^BOLD%^a%^RESET%^%^CYAN%^ri%^BOLD%^n%^RESET%^%^CYAN%^e",\
"%^ORANGE%^G%^BOLD%^o%^RESET%^%^ORANGE%^l%^BOLD%^d"})

void create(){
   string COLOR;
::create();
     	  COLOR = COLORS[random(sizeof(COLORS))];
   	  set_name("leather bodysuit");
        set_id(({"leather bodysuit","leather","bodysuit","armor" }));
        set_short(""+COLOR+" Leather Bodysuit%^RESET%^");
        set_obvious_short(""+COLOR+" leather bodysuit%^RESET%^");
        set_long("%^BOLD%^%^BLACK%^Soft "+COLOR+" %^BOLD%^%^BLACK%^leather is"+
		" used in the creation of this bodysuit.  Fashioned into a %^MAGENTA%^"
		"s%^RED%^e%^RESET%^n%^MAGENTA%^s%^BOLD%^u%^RED%^a%^RESET%^l"+
		"%^BOLD%^%^BLACK%^ silhouette, the bodysuit looks as if it might fit like a"+
		" second skin.  The strapless bodysuit features hardened leather "+
		"cups, partially for protection but mostly to help in the shaping "+
		"of the armor.  Ten small channels of minute %^WHITE%^eyelets%^BOLD%^%^BLACK%^"+
		" and laces run the length of the bodice, four in the front and back and"+
		" one on either side.  The channels help for the wearer to create a smooth"+
		" fit for a variety of bodytypes.  Attached over the skimpy bodysuit is a "+
		"short leather skirt, also crafted out of "+COLOR+"%^BOLD%^%^BLACK%^ leather."+
		"  The skirt offers a fair amount of protection, as well as providing a cover"+
		" for some modesty.%^RESET%^\n");
        set_weight(10);
set_value(1900);
        set_lore("It is often hard for women to find suitable armor to wear.  Too many"+
		" men seem to feel that women need to wear something skimpy in the course of"+
		" adventuring.  Such is the case of this bodysuit, crafted by the lecherous "+
		"Pralius, a half-elf blacksmith.  Pralius was rather famous for his creation of "+
		"platemail and chainmails armors.  That is until he devoted his remaining years"+
		" to creating impractical and  skimpy armor for women.  His scale mail bra and "+
		"chainmail bodysuit were seen as scandalous and frivolous.  Though he did seem to"+
		" find a following, enough to keep him quite comfortable.");
        set_size(2);
        set_property("enchantment",3);
        set_wear((:TO,"wear_func":));
        set_remove((:TO,"remove_func":));
}
int wear_func(){
        if((string)ETO->query_gender() == "male") {
        tell_object(ETO,"%^BOLD%^%^BLACK%^How do women manage to get"+
                        " these things on!?!");
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
                " scowls at the numerous eyelets and laces on the bodice, giving up with"+
                        " a frustrated sigh.",ETO);
                return 0;
        }
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
                	" %^BOLD%^%^BLACK%^slips into the leather bodysuit, "+
			"adjusting the laces to create a perfect fit.",ETO);
        tell_object(ETO,"%^BOLD%^%^BLACK%^You exhale deeply and"+
                	" tug on the leather bodysuit, tightening the laces "+
			"for a perfect fit.");
				return 1;
}
int remove_func(){
        tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
                " gasps for air after tearing off her leather bodysuit.",ETO);
        tell_object(ETO,"%^BOLD%^%^BLACK%^You gap for air as you"+
                " are finally free from that damn thing!");
                        return 1;
}
