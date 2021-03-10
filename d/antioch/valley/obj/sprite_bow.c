//Added lore and an obvious Short- Cythera 4-05\\
//converted to new lrweapon system. No small crossbow; inheriting heavy & modifying weight/etc. N, 12/13.
#include <std.h>
#include "../valley.h"
inherit "/d/common/obj/lrweapon/hcrossbow";

void create() {
	::create();
	set_name("crossbow");
	set_id(({"crossbow","bow","sprite bow","sprite crossbow","ivory crossbow","sprite arrows"}));
	set_short("%^BOLD%^%^WHITE%^Sea Sprite Crossbow%^RESET%^");
	set_obvious_short("%^BOLD%^%^WHITE%^An ivory crossbow%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Made of ivory, this crossbow is"+
		" elegant, graceful and very strange.  The slender "+
		"light crossbow is made of pure ivory.  %^YELLOW%^Gold"+
		" %^WHITE%^filigree stripes only help to heighten the"+
		" ivorys luster and the elegance of the bow.  A bow"+
		" string made of glittering silver looks very thin and"+
		" fragile, as if it might break at any moment.  Though"+
		" it is in truth deceptively strong.  The crossbow rises"+
		" out of what looks to be half of a bracer, with leather"+
		" straps the finish the half-circle.  It looks as if one"+
		" would strap the crossbow to their arm and use their"+
		" free hand to load it with arrows.  Very strange!");
	set_lore("The Sprite Bow is a rather newer creation of the"+
		" brilliant minds of the fey folk.  The crossbow helps "+
		"to play on the feys natural dexterity and overcomes the"+
		" physical weakness many of them seem to have.  The crossbow"+
		" is well balanced allowing for land, air and sea use, when needed."+
		" The crossbow is rumored to have large moonstone tucked away "+
		"somewhere inside the ivory, that helps improve its aim.");
	set_property("lore",9);
	set_weight(6);
	set_size(1);
	set_value(800);
      set_wc(1,6);
      set_large_wc(1,6);
	set_rate_of_fire(2);
	set_range(5,10,15);
   	set_two_handed();
    set_item_bonus("magic resistance",1);
    set_ammo("sprite arrows");
	set_wield((:TO,"wieldme":));
	set_unwield((:TO,"removeme":));
	set_lrhit((:TO,"extra_lrhit":));
	set_property("enchantment",3);
    set_property("able to cast",1);    
}

int wieldme() {
	tell_object(ETO,"%^BOLD%^You fix the light crossbow to your"+
	" forearm and marvel at the balance.");
	tell_room(environment(ETO),"%^BOLD%^"+ETO->query_cap_name()+""+
	" fixes the crossbow to "+ETO->query_possessive()+" arm.",ETO);
	return 1;
}

int use_shots(){ return 1; }
int query_shots(){ return -1; }
string query_ammo_type(){ return "sprite arrows"; }

int removeme() {
	tell_object(ETO,"%^CYAN%^You remove the lightweight crossbow.");
	return 1;
}

int extra_lrhit(object targ){
   if(!objectp(targ)) return 0;
   if(!objectp(ETO)) return 0;
   targ = ETO->query_current_attacker();
   if(!random(15)){
     tell_object(ETO,"%^BOLD%^%^BLUE%^The crossbow is so light that you can follow "+targ->QCN+"'s "
"movements with ease, aiming another deadly shot!");
     tell_object(targ,"%^BOLD%^%^BLUE%^"+ETOQCN+" seems to have no trouble following your movements "
"with the light crossbow, aiming another shot at you!%^RESET%^");
     tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+" seems to have no trouble following "+targ->QCN+"'s "
"movements with the light crossbow, aiming another shot at "+targ->QO+"!%^RESET%^",({ETO,targ}));
     targ->do_damage("torso",random(6)+10);
   }
   if(!random(10)){
     tell_object(ETO,"%^BOLD%^%^WHITE%^Even as the bowstring hums with an arrow loosed, you're "
"loading a second shot with your free hand!");
     tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s bowstring hums with an arrow loosed, and "
"already "+ETO->QS+" is loading a second shot with "+ETO->QP+" free hand!%^RESET%^",ETO);
     if(sizeof(ETO->query_attackers())) ETO->execute_attack();
     return 1;
   }
}
