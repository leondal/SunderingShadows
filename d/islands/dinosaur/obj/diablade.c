#include <std.h>

inherit WEAPON;

string OWNER;

void init(){
    ::init();
    if(interactive(TP) && TP==ETO && !OWNER) OWNER = TPQN;
    add_action("read_ruby", "read");
}

void create(){
    ::create();
    set_name("Diamond Blade");
    set_id( ({"sword", "blade", "diablade", "diamond sword", "diamond blade", "diamond"}) );
    set_short("%^RESET%^%^BOLD%^Diamond Blade%^RESET%^");
    set_long(
      "This great longsword is made from the purest %^BOLD%^diamonds%^RESET%^, enchanted to never dull its blade sharp enough to cut the hardest steel.  Set within the pommel and encased in the clear diamond there is a sparkling %^RED%^%^BOLD%^ruby%^RESET%^.  You can make out some ancient runes etched upon the ruby, glowing slightly on it."
    );
    set_weight(8);
    set("value", 50000);
    set_wc(2,4);
    set_large_wc(2,6);
    set_size(2);
    set_type("slashing");
    set_property("enchantment", 5);

    set_wield( (:TO, "extra_wield":) );
    set_unwield("The %^RED%^ruby%^RESET%^ shines brilliantly for a second, then goes dim as you release the blade.");
    set_hit( (:TO, "extra_hit":) );
}

int read_ruby(string str){
    if(!str || str != "ruby") return notify_fail("Read what?\n");

    tell_object(TP, "The %^BOLD%^%^RED%^ruby%^RESET%^ is inscribed with the following words:%^RESET%^");
    tell_object(TP, "%^BOLD%^This blade was forged from the pyre of a live volcano, the heat of its creation quenched in the blood of a live man.  Its power is great, but the power of its owner must be greater.%^RESET%^");
    tell_room(ETP, TPQCN+" reads over the runes on the %^RED%^%^BOLD%^ruby%^RESET%^.", TP);
    return 1;
}

int extra_wield(){
    if((string)TP->query_name() != OWNER){
	tell_object(TP, "The %^RED%^%^BOLD%^ruby%^RESET%^ shrieks in anger and the sword explodes in your hands!");
	tell_room(ETP, "The sword in "+TPQCN+"'s hands explodes!", TP);
	TP->do_damage("torso", roll_dice((31-(int)TP->query_lowest_level()), 10));
	TO->remove();
	return 0;
    }

    tell_object(TP, "%^BOLD%^The %^BOLD%^%^RED%^ruby%^RESET%^ glows slightly in your grasp.%^RESET%^");
    tell_room(ETP, "%^BOLD%^"+TPQCN+" grips the Blade of Diamonds", TP);
    return 1;
}

int extra_hit(object targ){
    int dam, i;

    if(random(4)) return roll_dice(2,4);

    if(random(150)){
      tell_object(ETO, "The %^RED%^ruby%^RESET%^ glows brighter as your blade slices deep into the flesh of your foe!");
      tell_object(targ, ETO->query_cap_name()+" strikes you mightily as "+ETO->query_possessive()+" great sword glows for a brief moment!");
      tell_room(environment(query_wielded()), "%^RED%^%^BOLD%^The blade wielded by "+ETO->query_cap_name()+" glows briefly as it drives into "+targ->query_cap_name()+"!!", ({ETO, targ}) );
	return roll_dice(4,5);
    }

    switch(random(4)){
    case 0:
      tell_object(ETO, "%^BOLD%^%^RED%^The %^RESET%^%^RED%^ruby%^BOLD%^ glows brilliantly as you raise the Sword of Diamonds above your head and then slam it into the ground blade first.\n\nA great earthquake shakes the entire room, causing a rift to open under "+targ->query_cap_name()+"'s feet!");
      tell_object(targ, "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" raises the Blade of Diamonds high above "+ETO->query_possessive()+" head and twirls it before slamming the blade into the ground before you!\n\nA great earthquake starts in the room, causing a rift to open at your feet, throwing you to the ground hard!");
      tell_room(environment(query_wielded()), "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" raises the blade of diamonds high above "+ETO->query_possessive()+" head, twirls it then slams the tip into the ground before "+targ->query_cap_name()+"!!\n\nA great earthquake shakes the room, causing a great rift to open at "+targ->query_cap_name()+"'s feet, throwing "+targ->query_objective()+" to the ground.", ({ETO, targ}) );
	targ->set_paralyzed(30, "%^BOLD%^%^RED%^The ground is too unsteady to walk on!");
	return roll_dice(4,30);
	break;

    case 1:
      tell_object(ETO, "%^BOLD%^%^RED%^The %^RESET%^%^RED%^ruby%^BOLD%^ glows brilliantly as you aim the Sword of Diamonds at your opponent.  "+capitalize(targ->query_subjective())+" starts to fidget and then shake and scream as suddenly the water in "+targ->query_objective()+" veins starts to boil.  Steam rises from "+targ->query_objective()+" body, then covers you and heals you with his essence.");
      tell_object(targ, "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" points the tip of the Blade of Diamonds at you.  You start to itch, then feel a great pain as the water in your veins begins to boil!  You rip at your skin as steam flows from your pores, and then are horrified as le essence of your life floats to "+ETO->query_cap_name()+" and heals "+ETO->query_objective()+"!");
      tell_room(environment(query_wielded()), "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" points the Blade of Diamonds at "+targ->query_cap_name()+". "+targ->query_cap_name()+" starts to squirm and then screams as steam pours from his pores, then wraps "+ETO->query_cap_name()+" in a healing mist.", ({targ, ETO}) );
	dam = random(150);
	TP->heal(dam);
	return (dam);
	break;

    case 2:
      tell_object(ETO, "%^BOLD%^%^RED%^   The %^RESET%^%^RED%^ruby%^BOLD%^ glows brilliantly as you point the tip of the Blade of Diamonds at the feet of your opponent.  The tip quivers slightly as a small flame starts to burn and suddenly erupts into a pillar of fire around "+targ->query_objective()+".  You smile as you listen to "+targ->query_possessive()+" screams of pain.");
      tell_object(targ, "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" aims the tip of the Blade of Diamonds at your feet.  You feel warm as a small flame at your feet suddenly bursts into a pillar of flame engulfing you!  Through the flames you can see a smirk on "+ETO->query_cap_name()+"'s face.");
      tell_room(environment(query_wielded()), "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" aims the tip of the Blade of Diamonds at "+targ->query_cap_name()+"'s feet.  A small flame at "+targ->query_cap_name()+"'s feet soon bursts into a pillar of flame engulfing "+targ->query_objective()+".  "+ETO->query_cap_name()+" smiles as "+targ->query_cap_name()+"'s screams drown out all other sounds.", ({targ, ETO}) );
	return (random(150));
	break;

    case 3:
      tell_object(ETO, "%^BOLD%^%^RED%^The %^RESET%^%^RED%^ruby%^BOLD%^ glows brilliantly as you hold the Blade of Diamonds above your head and slowly start to spin.  You spin faster and faster until you have created a small whirlwind around you!  You lower the blade so that it sticks out as you spin towards "+targ->query_cap_name()+" slicing "+targ->query_objective()+" several times!");
      tell_room(environment(query_wielded()), "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" holds the Blade of Diamonds above "+ETO->query_posessive()+" head and starts spinning slowly, but soon is spinning faster and faster until "+ETO->query_subjective()+" is like a small whirlwind.", ({targ, ETO}) );
      tell_room(environment(query_wielded()), "Soon you see the Blade of Diamonds points outwards from the whirlwind as "+ETO->query_cap_name()+" moves towards "+targ->query_cap_name()+" and slashes "+targ->query_objective()+" several times with the spinning blade!", ({targ, ETO}) );
      tell_object(targ, "%^BOLD%^%^RED%^"+ETO->query_cap_name()+" raises the blade of diamonds above "+ETO->query_possessive()+" head and begins to spin slowly, then faster and faster soon creating a small whirlwind.  Suddenly the whirlwind advances at you, the Blade of Diamonds sticking out from its side!");

	for(i=0;i<(5+random(10));i++){
        tell_object(targ, "%^BOLD%^%^CYAN%^"+ETO->query_cap_name()+" slices you deeply with the spinning blade!");
	    targ->do_damage("torso",roll_dice(4,4));
	}
	return 1;
	break;
    }
}
