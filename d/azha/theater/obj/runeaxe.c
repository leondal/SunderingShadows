#include <std.h>

inherit WEAPON;

void create(){
	::create();
	set_name("rune axe");
	set_id(({"axe","rune axe"}));
	set_short("%^RESET%^%^CYAN%^R%^BOLD%^%^BLUE%^u%^RESET%^%^CYAN%^"+
		"n%^BOLD%^%^BLUE%^e %^RESET%^%^CYAN%^A%^BOLD%^%^BLUE%^"+
		"x%^RESET%^%^CYAN%^e%^RESET%^");
	set_obvious_short("%^RESET%^%^CYAN%^A rune covered axe%^RESET%^");
	set_long("%^CYAN%^This old axe looks as if its seen its fair"+
		" share of battles.  The weathered steel has become oxidized,"+
		" taking on a %^BOLD%^%^BLACK%^darker color%^RESET%^%^CYAN%^."+
		"  Though old, this axe still retains a sharp edge.  The curv"+
		"ed blade of the axe tapers to fine points at the top and bot"+
		"tom.  The darkened metal is engraved with runes up and down "+
		"the blade.  Flecks of %^BOLD%^%^WHITE%^silver%^RESET%^%^CYAN%^"+
		" and %^YELLOW%^gold%^RESET%^%^CYAN%^ can be seen in the runes,"+
		" though these finishes have worn off the majority"+
		" of the runes.  Mounted onto a %^ORANGE%^yew wood%^CYAN%^ hand"+
		"le, the axe looks sturdy and strong.  Braided"+
		" strips of%^ORANGE%^ leather%^CYAN%^ create the hand guard of "+
		"the axe.  The pommel of the axe is fastened"+
		" with looks like what had might been a spike at one time.\n");
   set_weapon_prof("martial"); // since it does not inherit common files
        switch(random(3)) {
case 1:
   set_prof_type("axe");
	set_size(1);
	set_weight(4);
	set_weapon_speed(4);
	set_type("slashing");
	set_wc(1,6);
	set_large_wc(1,4);
	break;
case 2:
   set_prof_type("axe");
	set_size(3);
	set_weight(7);
	set_weapon_speed(8);
	set_type("slashing");
	set_wc(3,4);
	set_large_wc(3,4);    
	break;
default:
   set_prof_type("axe");
	set_size(2);
	set_weight(7);
	set_weapon_speed(7);
	set_type("slashing");
	set_wc(1,8);
	set_large_wc(1,10);    
	}
	set_lore("In The Two Faced Rakshasa, Gildore the possessed "+
		"a magical axe that could change size as he needed it.  The"+
		" Rune Axe, as Gildore named it in the play, was said to ca"+
		"rry with it enchantments carved into the metal during the "+
		"infancy of magic.  The runes allowed for Gildore to tear t"+
		"hrough the defenses of those that stood between him and Rj"+
		"arek. -  Lemons and Limes - A History of Failed Plays - De"+
		"vin Igarn");
	set_property("lore difficulty",15);
	set_property("enchantment",3);
	set_item_bonus("sight bonus",1);
	set_value(300);
	set_ac(0);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
  
}
int wield_func(string str) {
	if((int)ETO->query_highest_level() < 17) {
		tell_object(ETO,"%^CYAN%^The runes on the axe flash, rejecting "+
			"your grasp.%^RESET%^");
			return 0;
}
		tell_object(ETO,"%^CYAN%^The runes on the axe flash in response"+
			" to your touch.%^RESET%^");
		tell_room(environment(ETO),"%^CYAN%^The runes on "+ETO->QCN+"'s"+
                        " axe flash in response to "+ETO->QP+" touch.",ETO);
				return 1;
}
int unwield_func(string str) {
	tell_object(ETO,"%^CYAN%^The runes on your axe dim as you relea"+
		"se it.");
	tell_room(environment(ETO),"%^CYAN%^The runes on "+ETO->QCN+"'s"+
		" axe dim as "+ETO->QS+" release it.",ETO);
   			return 1;
}
int hit_func(object targ)
{
  	targ = ETO->query_current_attacker();
  	if(!objectp(ETO)) return 1;
  	if(!objectp(targ)) return 1;
  	if(random(1000) < 150)
    {
		switch(random(50))
        {

        case 0..11:
                tell_object(ETO,"%^CYAN%^Some of the runes on your axe glow"+
                " %^BLUE%^blue%^CYAN%^ as you tear into "+targ->QCN+".");
              tell_object(targ,"%^CYAN%^"+ETO->QCN+"'s axe glows %^BLUE%^"+
                "blue%^CYAN%^ as "+ETO->QS+" tear into you.");
              tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+"'s axe glows"+
                " %^BLUE%^blue%^CYAN%^ as they tear into "+targ->QCN+"", ({ETO,targ}));
			  targ->cause_typed_damage(targ, "torso", roll_dice(1, 8) + 3, "slashing");
              break;
        case 12..47:
            tell_object(ETO,"%^BLUE%^Some of the runes on your axe glow"+
                " %^BOLD%^%^WHITE%^white%^RESET%^%^BLUE%^ as you tear into "+
                ""+targ->QCN+".");
              tell_object(targ,"%^BLUE%^"+ETO->QCN+"'s axe glows %^BOLD%^"+
                        "%^WHITE%^white%^RESET%^%^BLUE%^ as "+ETO->QS+" tears into "+
                "you.");
              tell_room(EETO,"%^BLUE%^"+ETO->QCN+"'s axe glows %^BOLD%^"+
                        "%^WHITE%^white%^RESET%^%^BLUE%^ as "+ETO->QS+" tears into "+
                ""+targ->QCN+".", ({ETO,targ}));
			  targ->cause_typed_damage(targ, "torso", roll_dice(1, 6) + 1, "slashing");
            break;	
        case 48..49:
            tell_object(ETO,"%^BOLD%^%^BLUE%^All the runes on your axe light"+
                " up as you tear into "+targ->QCN+".");
            tell_object(targ,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s axe lights up in"+
                " a blaze as "+ETO->QS+" tear into you.");
            tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETO->QCN+"'s axe lights up in a"+
                " blaze as "+ETO->QS+" tear through "+targ->QCN+".",({ETO,targ}));
			targ->cause_typed_damage(targ, "torso", roll_dice(1, 10) + 7, "slashing");
            break;
        
        default:
            break;
        }


	}
    return 1;
}

