#include <std.h>
inherit "/d/common/obj/weapon/longsword.c";

void create(){
	::create();
	set_name("forests gleam");
	set_id(({ "sword", "longsword", "long sword", "forests gleam", "forest's gleam", "gleam" }));
	set_short("%^BOLD%^%^GREEN%^Fo%^WHITE%^r%^GREEN%^est's Gl%^WHITE%^e%^GREEN%^am%^RESET%^");
	set_obvious_short("%^RESET%^%^GREEN%^leather hilted longsword%^RESET%^");
	set_long("%^RESET%^%^GREEN%^Clearly crafted by elven hand, this "+
	   "longsword is finely made and very ornate despite its simple "+
	   "form.  The blade itself is forged of the finest mithril and "+
	   "tinted so that it holds a greenish tint that grows darker the "+
	   "closer it gets to the central blood groove.  Further, dark "+
	   "green glyphs have been etched up and down the blade, covering "+
	   "the surface in their faintly glowing scrollwork.  The crosspiece "+
	   "is a simple beam of mithril shaped to look like a bow, complete "+
	   "with a band of sinew that stretches from either end to the ball "+
	   "shaped pommel.  A groove in the ball of the pommel keeps this "+
	   "string of sinew from slipping down onto the leather wrapped "+
	   "hilt of the blade.%^RESET%^");
   set_value(0);
	set_lore("These swords are said to be fashioned by skilled elven "+
	   "magi who have learned to bind the art of smithing with the "+
	   "craft of magic.  Bound within the mithril is a spell of "+
	   "power, which those who have mastered the blade are capable "+
	   "of calling upon when engaging in specific movements.  Though "+
	   "rarely seen outside of an elf's grip, there are a select few "+
	   "that have been awarded over the years to members of other "+
	   "races as a reward for aid to the elven people.");
	set_property("lore difficulty",15);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
      set_item_bonus("attack bonus",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
    set_overallStatus(220);
    set_property("no disenchant",1);
}
int wield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^The sigils along the length of "+ETOQCN+"'s "+query_short()+" %^RESET%^%^CYAN%^glow faintly.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^The sigils along the length of the blade %^BOLD%^%^GREEN%^glow %^RESET%^%^CYAN%^faintly as you take "+query_short()+" %^RESET%^%^CYAN%^into your hand.%^RESET%^");
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"%^RESET%^%^CYAN%^As "+ETOQCN+" unwields their "+query_short()+"%^RESET%^%^CYAN%^, the glowing sigils fade from sight.%^RESET%^",ETO);
	tell_object(ETO,"%^RESET%^%^CYAN%^The glowing sigils fade from sight as you unwield "+query_short()+"");
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^RESET%^%^CYAN%^Moving quickly in a short series of steps, "+ETOQCN+" brings their "+query_short()+" %^RESET%^%^CYAN%^slashing down in front of "+targ->QCN+".  The sigils along the blade suddenly %^BOLD%^%^GREEN%^flash %^RESET%^%^CYAN%^into life and a %^BOLD%^%^GREEN%^gl%^WHITE%^o%^GREEN%^wing o%^WHITE%^r%^GREEN%^b %^RESET%^%^CYAN%^shoots from tip of the blade as though fired from the bow shaped hilt.%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^RESET%^%^CYAN%^Moving quickly in a short series of steps, you bring your "+query_short()+" %^RESET%^%^CYAN%^slashing down in front of "+targ->QCN+".  The sigils along the blade suddenly %^BOLD%^%^GREEN%^flash %^RESET%^%^CYAN%^into life and a %^BOLD%^%^GREEN%^gl%^WHITE%^o%^GREEN%^wing o%^WHITE%^r%^GREEN%^b %^RESET%^%^CYAN%^shoots from tip of the blade as though fired from the bow shaped hilt.%^RESET%^");
	tell_object(targ,"%^RESET%^%^CYAN%^Moving quickly in a short series of steps, "+ETOQCN+" brings their "+query_short()+" %^RESET%^%^CYAN%^slashing down in front of you.  The sigils along the blade suddenly %^BOLD%^%^GREEN%^flash %^RESET%^%^CYAN%^into life and a %^BOLD%^%^GREEN%^gl%^WHITE%^o%^GREEN%^wing o%^WHITE%^r%^GREEN%^b %^RESET%^%^CYAN%^shoots from tip striking you forcefully in the chest!%^RESET%^");
		return roll_dice(2,6)+0;	}
}