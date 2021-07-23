#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create(){
	::create();
	set_name("chilling touch");
	set_id(({ "chilling touch", "white leather glove", "leather glove", "glove" }));
	set_short("%^BOLD%^%^WHITE%^C%^CYAN%^h%^WHITE%^i%^CYAN%^l%^WHITE%^l%^CYAN%^i%^WHITE%^n%^WHITE%^g To%^CYAN%^u%^WHITE%^ch%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^a white leather glove%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Hardy white leather is used in the "+
	   "creation of this glove.  The thick leather is heavily "+
	   "padded across the knuckles and the back of the hand, "+
	   "adding some extra bulk to the glove.  %^CYAN%^Crystal%^WHITE%^ "+
	   "spikes rise up from across the knuckles, glittering like "+
	   "icicles.  A minute pattern of %^CYAN%^snowflakes%^WHITE%^ "+
	   "is burned into the leather, the images so small that they "+
	   "are often overlooked.  The fingerless gloves are finished "+
	   "off with %^CYAN%^crystal%^WHITE%^ strips across each opening "+
	   "of the fingers, sealing the leather off.%^RESET%^");
   set_value(0);
	set_lore("%^BOLD%^%^CYAN%^Chilling Touch is another of the strange "+
	   "weapons used by the Monks of Ibrandul, a religous order devoted "+
	   "to the slain god.  This glove seems to center around one person "+
	   "in paticular, Leveshta the Icy.  Leveshta was a human monk of "+
	   "Ibrandul, a rare feat for any female.  She was nicknamed the Icy "+
	   "for her chillingly cold attitude towards others, always seeming "+
	   "to thwart any romantic advances with an icy gaze.  She was said "+
	   "to have been chillingly cold as well when she was moved to "+
	   "attack.  A pair of gloves was made for her by the Order of the "+
	   "Four Silver Ring, the monks of Ibrandul, in honor of her commitment.%^RESET%^");
	set_property("lore difficulty",16);
   while ((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
      set_item_bonus("attack bonus",3);
      set_item_bonus("damage bonus",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
	set_overallStatus(220);
    set_property("no disenchant",1);
}
int wield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETOQCN+" pulls on the white leather glove.  A %^CYAN%^frosted runes%^WHITE%^ crackle to life across the back of their hand.  A %^B_CYAN%^%^BOLD%^%^WHITE%^frosted aura%^RESET%^%^BOLD%^ wraps around their hand.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^As you pull the gloves on %^CYAN%^frosted runes%^WHITE%^ crackle to life across the back of your hand.  A %^B_CYAN%^%^BOLD%^%^WHITE%^frosted aura%^RESET%^%^BOLD%^ wraps around your hand to aid your attacks.");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^BOLD%^%^WHITE%^Sparyas of %^CYAN%^ice%^WHITE%^ shards fall from "+ETOQCN+"'s hand as they remove the glove.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^The frosted aura cracks and shatters, spraying shards of%^CYAN%^ ice%^WHITE%^, that melt before they hit the ground, out.");
	return 1;
}
int hit_func(object targ){
	if(random(1000) < 250){
	tell_room(environment(query_wielded()),"%^BOLD%^%^WHITE%^Long jagged shard of pure %^CYAN%^ice%^WHITE%^ cover "+ETOQCN+"'s hand for a brief instant, allowing them to tear into "+targ->QCN+"",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^The frosted aura around your hand solidifies for a brief instant, forming long jagged shards of pure %^CYAN%^ice%^WHITE%^, ripping through "+targ->QCN+"");
	tell_object(targ,"%^BOLD%^%^WHITE%^Long jagged shard of pure %^CYAN%^ice%^WHITE%^ cover "+ETOQCN+"'s hand for a brief instant, allowing them to tear into you with a their piercing chill!");
		return roll_dice(2,4)+2;	}
}