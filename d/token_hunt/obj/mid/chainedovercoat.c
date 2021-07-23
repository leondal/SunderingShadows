#include <std.h>
inherit "/d/common/obj/armour/studded.c";

void create(){
	::create();
	set_name("leather overcoat");
	set_id(({ "overcoat", "over coat", "coat", "chained overcoat", "leather overcoat", " chained mans overcoat", " chained man's overcoat" }));
	set_short("%^BOLD%^%^BLACK%^c%^WHITE%^h%^RESET%^a%^BOLD%^%^BLACK%^in%^RESET%^e%^BOLD%^%^BLACK%^d m%^WHITE%^a%^BOLD%^%^BLACK%^n%^RESET%^'%^BOLD%^%^BLACK%^s o%^WHITE%^v%^RESET%^e%^BOLD%^%^BLACK%^rco%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a l%^WHITE%^e%^RESET%^a%^BLACK%^%^BOLD%^th%^RESET%^e%^BOLD%^%^BLACK%^r o%^WHITE%^v%^RESET%^e%^BOLD%^%^BLACK%^rco%^RESET%^a%^BOLD%^%^BLACK%^t%^RESET%^");
	set_long("%^BOLD%^%^BLACK%^This tailored garment is formed out of "+
	   "black leather with a contrasting panel of %^RESET%^slate-gray "+
	   "%^BOLD%^%^BLACK%^down the front.  The foot-wide, V-shaped "+
	   "panel fastens down the middle of the garment, extending from "+
	   "neck to waist and fastened with cleverly hidden hook-and-eye "+
	   "closure on either side.  Over the panel links of %^RESET%^"+
	   "tarnished silver chain %^BOLD%^%^BLACK%^form accents extending "+
	   "in a zigzag along the panel's edge.  This chain motif can be "+
	   "found on the back as well, hanging in several cape-like, ever "+
	   "widening loops from the shoulders to the waist, with dangling "+
	   "trim on either side.  The overcoat has long sleeves that end at "+
	   "the wrists in wide cuffs where more of the %^RESET%^tarnished "+
	   "silver links %^BOLD%^%^BLACK%^can be found pinning the upturned "+
	   "cuffs.  A stiff black leather collar peaks high along the neck, "+
	   "brushing the underside of the jaw and chin in the front and "+
	   "rising to nearly the top of the head in back.   The garment "+
	   "ends at just above the ankles, sweeping out in a wide swath "+
	   "of leather.%^RESET%^");
   set_value(0);
	set_lore("%^BOLD%^%^RED%^F%^BOLD%^%^BLACK%^orge me in chains that "+
	   "cannot break,\n"+
	   "%^BOLD%^%^RED%^O%^BOLD%^%^BLACK%^f silver links that rattle "+
	   "and shake.\n"+
	   "%^BOLD%^%^RED%^M%^BOLD%^%^BLACK%^y soul bound by mistake.\n"+
	   "%^BOLD%^%^RED%^H%^BOLD%^%^BLACK%^olding me down though I ache, \n"+
	   "%^BOLD%^%^RED%^F%^BOLD%^%^BLACK%^or sweet release, oh! let me "+
	   "partake.%^RESET%^");
	set_property("lore difficulty",10);
	set_size(-1);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
      set_item_bonus("will",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}

int wear_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You wrap the thick leather about your body and listen to the chains rattle as they settle into place.%^RESET%^");
	return 1;
}

int remove_func(){
	tell_object(ETO,"%^BOLD%^%^BLACK%^You sigh as the heavy, chain reinforced leather, slides off your shoulders.%^RESET%^");
	return 1;
}

int strike_func(int damage, object what, object who){
	if(random(1000) < 100){
	tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^A %^RESET%^%^RED%^haunting wail %^BOLD%^%^BLACK%^can be heard coming from somewhere near "+who->QCN+"!  Suddenly "+who->QCN+" shrieks and grows rigid with fear!%^RESET%^",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^BLACK%^The %^RESET%^chains %^BOLD%^%^BLACK%^rattle and shake and a %^RESET%^%^RED%^haunting wail %^BOLD%^%^BLACK%^takes up as "+who->QCN+"'s weapon strikes you. Suddenly "+who->QCN+" gives out a shriek of their own and grows rigid with fear!%^RESET%^");
	tell_object(who,"%^BOLD%^%^BLACK%^As your weapon strikes the chains of "+ETOQCN+"'s %^RESET%^"+query_short()+"%^BOLD%^%^BLACK%^, you see a %^RESET%^ghostly shape %^BOLD%^%^BLACK%^rising up out of them.  It turns glowing %^RESET%^%^RED%^red eyes %^BOLD%^%^BLACK%^upon you and then streaks toward you with a piercing wail!%^RESET%^");
		who->set_paralyzed(roll_dice(6,2));
return damage;	}
}