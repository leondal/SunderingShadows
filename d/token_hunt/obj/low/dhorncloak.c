#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("cloak");
	set_id(({ "cloak", "dragonhorn cloak", "ragged cloak" }));
	set_short("%^RESET%^%^GREEN%^Dr%^BOLD%^%^BLACK%^a%^BOLD%^%^GREEN%^g%^BLACK%^o%^RESET%^%^GREEN%^nh%^BOLD%^%^BLACK%^o%^RESET%^%^GREEN%^rn Cl%^BOLD%^%^BLACK%^o%^GREEN%^a%^RESET%^%^GREEN%^k%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^a%^BLACK%^%^BOLD%^gg%^RESET%^%^GREEN%^e%^BOLD%^%^BLACK%^d cl%^RESET%^%^GREEN%^o%^BOLD%^%^BLACK%^ak%^RESET%^");
	set_long("%^CYAN%^Made from the hide of some sort of lizard, "+
	   "this %^GREEN%^gr%^BOLD%^%^BLACK%^e%^GREEN%^e%^BLACK%^n%^RESET%^"+
	   "%^GREEN%^ish-g%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^ay %^RESET%^"+
	   "%^CYAN%^cloak is adorned with a clasp made from two small dark "+
	   "%^ORANGE%^brown horns%^CYAN%^.  These %^ORANGE%^horns %^CYAN%^"+
	   "link over one another so that one piece curves with its point "+
	   "facing toward the chin of the wearer while the other points "+
	   "downward toward their feet.  %^BOLD%^%^BLACK%^Rough %^RESET%^"+
	   "%^CYAN%^to the touch and not particularly comfortable to wear "+
	   "against unprotected skin, the %^GREEN%^sc%^BOLD%^%^BLACK%^a"+
	   "%^RESET%^%^GREEN%^les %^CYAN%^are unpadded and seem barely "+
	   "tanned.  Ragged, uneven edges give it the appearance of "+
	   "having simply been ripped from the %^ORANGE%^hide %^CYAN%^of "+
	   "the beast that once wore it.  Despite this, it is quite durable "+
	   "and very resistant to all manner of elements, especially "+
	   "%^BOLD%^rain%^RESET%^%^CYAN%^, %^WHITE%^snow %^CYAN%^and "+
	   "%^BLACK%^%^BOLD%^sleet%^RESET%^%^CYAN%^.%^RESET%^");
	set_weight(5);
	set_value(0);
	set_lore("The original dragonhorn cloak was made by Orolof "+
	   "Towerstone, a dwarven warrior of exceptional skill of bringing "+
	   "down large game.  Legend holds that Orolof wandered the realms "+
	   "in and around 321 SG, slaying anything bigger then a human's "+
	   "house all the while muttering things like 'that's too big for "+
	   "its own good' and 'time to chop'm down to the proper size.'  "+
	   "Notably Orolof's first recorded kill, the green dragon "+
	   "Isterbicken, whose horn and hide were used to fashion the "+
	   "first cloak.  Several copies of the cloak were made over "+
	   "the years as the tales of Orolof's peculiar success continued "+
	   "to rise, that is until both Orolof and the original cloak "+
	   "vanished from the face of the realm.");
	set_property("lore difficulty",17);
	set_type("clothing");
	set_limbs(({ "neck" }));
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 1) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",1);
   }
      set_item_bonus("magic resistance",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}
int wear_func(){
	tell_room(environment(ETO),"%^RESET%^The "+query_short()+" %^CYAN%^drapes limply about "+ETOQCN+"'s shoulders.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You drape the "+query_short()+" %^CYAN%^limply about your shoulders.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^"+ETOQCN+" seems suddenly vulnerable as they take "+query_short()+" %^CYAN%^off.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^You peel the "+query_short()+" %^RESET%^%^CYAN%^from your shoulders and feel oddly more vulnerable.%^RESET%^");
	return 1;
}