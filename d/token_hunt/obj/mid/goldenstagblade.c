#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword.c";

void create(){
	::create();
	set_name("golden sword");
	set_id(({ "sword", "two handed sword", "twohanded sword", "two-handed sword", "great sword", "akarel", "golden sword", "greatsword" }));
	set_short("%^BOLD%^%^RED%^A%^RESET%^%^RED%^k%^BOLD%^%^BLACK%^a%^RED%^r%^RESET%^%^RED%^e%^BOLD%^l %^WHITE%^- %^YELLOW%^G%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^den B%^RESET%^%^ORANGE%^l%^BOLD%^%^BLACK%^a%^YELLOW%^de %^BLACK%^o%^YELLOW%^f t%^RESET%^%^ORANGE%^h%^YELLOW%^e S%^RESET%^%^ORANGE%^t%^BOLD%^%^BLACK%^a%^YELLOW%^g%^RESET%^");
	set_obvious_short("%^RESET%^%^ORANGE%^a %^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^den %^RESET%^%^ORANGE%^great sword%^RESET%^");
	set_long("%^RESET%^%^ORANGE%^The hilt of this two handed sword is entwined in %^GREEN%^emerald wire %^ORANGE%^that appears to be molded after "
"rose vines, complete with tiny %^MAGENTA%^amethyst %^ORANGE%^and %^WHITE%^pearl %^ORANGE%^roses that grow upon its length.  The vines extend up and "
"around the antler shapped cross guard, curling back toward the hilt to add a basket of sorts that protects the wielder's hands.  The blade itself "
"is a length of %^YELLOW%^golden metal %^RESET%^%^ORANGE%^that shimmers with a nearly divine light.  The full length is untouched by any form of "
"etching or design work, which makes it almost more stunning then if it had been adorned fully.  Upon the pommel, a glittering %^RED%^ruby "
"%^ORANGE%^has been set, and through it, you can see the %^BOLD%^%^BLACK%^rampant stag %^RESET%^%^ORANGE%^insignia that seems to just go with this "
"brilliant weapon.%^RESET%^");
   set_value(0);
	set_lore("%^RED%^Remembered from an ancient journal:%^RESET%^  As the fog of morning burned away under the noon day sun, the countless hoards "
"of the Dresttel were revealed.  Even with their General, Ta'marni the Golden Stag, the forces of Inomor felt their hearts stutter and fear clutch "
"at their souls.  Thousands upon thousands spread out over the fertile valley, their orcish features horrific in the light of day.  And for a moment, "
"the men and women of Inomor thought to run.  But Ta'marni lifted his great sword Akarel above his head and called out to the gods who, knowing of "
"his right, sent the fire of righteousness down upon the lifted golden blade, which in turn cast the light over the Dresttel hoards.");
	set_property("lore difficulty",23);
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
	tell_object(ETO,"%^YELLOW%^Taking the "+query_short()+" %^YELLOW%^into your hands, you feel a sense of complete calmness spill over you.  The battle ahead beckons you to victory.%^RESET%^");
	return 1;
}

int unwield_func(){
	tell_object(ETO,"%^YELLOW%^Battle over, you sheath the "+query_short()+" %^YELLOW%^knowing it will come to your hand when next you are in need.%^RESET%^");
	return 1;
}

int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 25){
	tell_room(environment(query_wielded()),"%^YELLOW%^With perfect calmness, "+ETOQCN+" points the tip of their "+query_short()+" %^YELLOW%^toward "+targ->QCN+" and sends a %^RED%^burning blaze of light%^YELLOW%^ outward toward their enemy!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^YELLOW%^The battle seems hard and harsh, but the weight of victory is in your hands.  Stepping forward, you point the tip of your "+query_short()+" %^YELLOW%^toward "+targ->QCN+" and with perfect calmness send a %^RED%^burning blaze of light%^YELLOW%^ outward toward your enemy!%^RESET%^");
	tell_object(targ,"%^YELLOW%^With perfect calmness, "+ETOQCN+" points the tip of their "+query_short()+" %^YELLOW%^toward you!  From the tip, a brilliant light ignites and then bursts into a %^RED%^burning blaze of light%^YELLOW%^ that strikes out at you and burns you to your soul!%^RESET%^");
		return roll_dice(10,4)+10;	}
}