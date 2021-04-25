#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("vest of the storms");
	set_id(({ "vest", "storm vest", "purple vest", "suede vest" }));
	set_short("%^RESET%^%^MAGENTA%^Vest of the %^BLUE%^S%^BOLD%^t%^CYAN%^o%^WHITE%^r%^YELLOW%^m%^BLUE%^s%^RESET%^");
	set_obvious_short("%^MAGENTA%^A dusky purple suede vest%^RESET%^");
set_long("%^MAGENTA%^Deep dusky violet suede is used in the creation of "+
            "this heavily embroidered vest.  The vest itself looks to be cut where it will "+
            "always hang open.  A pointed up turned collar mirrors the stiffened suede that "+
            "juts out from the shoulders, giving it a sharply angled appearance.  Patches of "+
            "%^BOLD%^%^BLACK%^dark grey%^RESET%^%^MAGENTA%^ and %^BLUE%^blue%^RESET%^%^MAGENTA%^"+
            " suede cover the upper part of the vest, giving an illusion of storm clouds in the "+
            "sky.   Glass beads in %^BOLD%^%^WHITE%^white%^RESET%^%^MAGENTA%^, "+
            "%^RESET%^silver%^MAGENTA%^, %^YELLOW%^gold%^RESET%^%^MAGENTA%^ and "+
            "%^BOLD%^%^CYAN%^pale blue%^RESET%^%^MAGENTA%^ have been stitched into the "+
            "suede.  The beading takes on the shape of bolts of %^BOLD%^%^YELLOW%^l%^WHITE%^i"+
            "%^CYAN%^g%^WHITE%^h%^YELLOW%^t%^CYAN%^i%^WHITE%^n%^YELLOW%^g%^RESET%^%^MAGENTA%^ "+
            "that illuminate the clouds and fall chaotically down the vest. As the light hits "+
            "the beaded lighting it almost seems as if it is real!\n%^RESET%^");
	set_weight(4);
	set_value(1999);
	set_lore(
@AVATAR
The Vest of the Storms, many believe to be Talosian in desing and origin.  When in truth Talos and his faithful had little to do with its creation.  The vest is attributed to a sorceress by the name of Ororo, who was known as the Weather Witch.  The Weather Witch favored spells that delt with lighting, wind, and other meterlogical effects thus how she earned her nickname.  This vest is one of the last items of hers to be in existance in the lands, so it is rumored.

AVATAR
	);
	set_type("clothing");
	set_limbs(({ "torso" }));
set_size(2);
set_property("enchantment",5);
	set_ac(0);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" slides the dusky purple suede vest on with ease",ETO);
	tell_object(ETO,"%^MAGENTA%^You slide the vest on with ease");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^MAGENTA%^"+ETOQCN+" slides the dusky purple suede vest off with ease.",ETO);
	tell_object(ETO,"%^MAGENTA%^You slide the vest off with ease");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(!random(10)){
	tell_room(environment(query_worn()),"%^BOLD%^%^CYAN%^"+who->QCN+" is hit with an electrical discharge from "+ETOQCN+"'s vest as the smell of ozone lingers in the air.",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^CYAN%^An electrical discharge issues forth from the vest shocking "+who->QCN+"");
	tell_object(who,"%^BOLD%^%^CYAN%^You are struck with an electrical discharge from "+ETOQCN+"'s vest. The smell of ozone fills your senses!");
		who->do_damage("torso",random(8)+8);
	}
    return damage;
}
