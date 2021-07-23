//added more obvious ids so people knew how to target it. ~Circe~ 2/5/13
#include <std.h>
inherit "/d/common/obj/weapon/claw.c";

void create(){
	::create();
	set_name("cestus");
	set_id(({ "cestus", "cestus of the silver rings", "knuckles", "glove", "leather glove" }));
	set_short("%^RESET%^%^MAGENTA%^Cestus of the %^BOLD%^%^WHITE%^Silver Rings%^RESET%^");
	set_obvious_short("%^RESET%^%^MAGENTA%^A leather glove%^RESET%^");
	set_long("%^MAGENTA%^ At first this just seems like a pair of "+
	   "fingerless gloves, but it is more that just that.  The cestus "+
	   "is made of a soft leather that is as strong as flexible.  The "+
	   "glove slips on to rest tight against the wrist.  Leather cordin "+
	   "is used to tighten the glove.  Strip of metal are sandwiched "+
	   "between two layers of leather.  On the back of the glove "+
	   "four interlocking rings in %^BOLD%^%^WHITE%^silver%^RESET%^"+
	   "%^MAGENTA%^ have been tooled into the leather.  The cestus "+
	   "is often a pugilists' weapon of choice, giving that they "+
	   "tend to rely on their brute strength rather than weapons.%^RESET%^");
	set_value(0);
	set_lore("The Cestus of the Silver Rings are worn by the monks "+
	   "of Ibrandul in defense of their temple.  The monks spend "+
	   "countless hours honing their bodies into deadly weapons. "+
           "It is possible for an outsider to gain one of these gloves, "+
	   "but no one yet has used them to the deadly accuracy that "+
	   "the monks have.");
   while ((int)TO->query_property("enchantment") != 2) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",2);
   }
    set_item_bonus("damage bonus",1);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
   set_overallStatus(220);
   set_property("no disenchant",1);
    set_damage_type("bludgeoning");
}
int wield_func(){
	tell_room(ETP,"%^MAGENTA%^"+ETO->query_cap_name()+" slips on the glove and pulls the laces taunt, getting a nice snug fit.",TP);
	tell_object(TP,"%^MAGENTA%^You slip on the gloves and pull the laces taunt, getting a nice snug fit.");
	return 1;
}
int unwield_func(){
	tell_room(ETP,"%^MAGENTA%^"+ETO->query_cap_name()+" unlaces the glove and slips it off.",TP);
	tell_object(TP,"%^MAGENTA%^You unlace the glove and slip them off.");
	return 1;
}
int hit_func(object targ){
        if(!objectp(targ)) return 0;
        if(random(1000) < 200){
        tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" moves with lightning speed and delivers a series of rabbit punches to "+targ->query_cap_name()+"",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^WHITE%^You move in with lightning speed and deliver a series of rabbit punches to "+targ->query_cap_name()+"");
	tell_object(targ,"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" moves with lightning speed and delivers a series of rabbit punches.");
		return roll_dice(5,2)+0;	}
}