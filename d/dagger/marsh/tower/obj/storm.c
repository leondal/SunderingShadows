// fixed wield/unwield to use ETO & added obvious short  *Styx* 8/2003

#include <std.h>
inherit "/d/common/obj/weapon/two_hand_sword";
int uses,STORM;
object owned;
void init() {
    ::init();
    STORM = 0;
    if(interactive(TP) && !owned) owned = TPQN;
}
void create() {
    ::create();
    set_name("stormbringer");
    set_id(({"sword","two handed sword","sword_of_storms", "stormbringer"  }));
    set_obvious_short("%^RESET%^%^BLUE%^two-handed sword%^RESET%^");
    set_short("%^RESET%^%^BLUE%^Stormbringer%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Made entirely of glit%^WHITE%^te"+
      "%^BLACK%^ring jet, this sword is fitted with a long, jagged "+
      "%^RED%^blood groove %^BLACK%^filled with a thin layer of "+
      "%^YELLOW%^molten gold %^BLACK%^that makes it look much like "+
      "a %^YELLOW%^lightning bolt%^BLACK%^.  The sword is double-"+
      "edged and serrated near the hilt, giving it an added "+
      "vicious appearance.  The hilt itself is fitted with black "+
      "leather covered in strips of %^RESET%^gray%^BOLD%^%^BLACK%^, "+
      "%^WHITE%^white%^BLACK%^, and %^BLUE%^blue cloth %^BLACK%^"+
      "that give it added grip as well as mimicking the appearance "+
      "of %^RESET%^storm clouds%^BOLD%^%^BLACK%^.  The ends of the "+
      "strips have been left free to whip about in the %^CYAN%^wind "+
      "%^BLACK%^that seems always present whenever this sword is "+
      "near.%^RESET%^");
    set_lore("%^GREEN%^The two handed sword known as stormbringer is a long "
      "lost artifact of reknown power. In mythology, it was wielded "
      "by Verondis of Daggerdale, a holy knight of great virtue. He used it to "
      "incredible benefit to mankind in the Goblin wars which raged "
      "in Daggerdale for over a century. Buried with him in his final place "
      "of resting, it remained until a time passed where his grandson "
      "went to reclaim the weapon to use in the Drow slavery wars. To "
      "much surprise, the knight's body and the storm had disappeared with "
      "no explanation as to what happened to either. Many spoke of a terrible "
      "beast which ravished the Northern lands for a decade wielding a sword similar "
      "to the one described in history detailing the knight's battles, but because "
      "the beast, often refered to as 'Render', was never slain, none could be "
      "sure.%^RESET%^"
    );
    set_size(3);
    set_value(2000);
    set_hit((: TO, "extra_hit":));
    set_wield((: TO, "extra_wield":));
    set_property("enchantment",5);
        set_item_bonus("attack bonus",3);
   set_item_bonus("damage bonus",3);
   set_weapon_prof("exotic");
    set_heart_beat(1);
    uses = random(500)+70;
}
void heart_beat() 
{
    object owner,env,obj,*inv,vic;
    env = ETO;
    if(!objectp(ETO)) return;
    if(!objectp(TO)) return;
    if(objectp(env) && living(env)) 
    {
        owner = env;
        env = environment(owner);
        if(!objectp(env)) return;
    }
    if(!objectp(env)) return;
    if(!(TO->query_wielded())) return;
    if(env->query_property("indoors") && (string)owner->query_name() != "render") return;
    if(uses < 1) return;
    if(!(vic = owner->query_current_attacker()) && STORM == 1) {
	tell_room(environment(owner),
	  "%^MAGENTA%^The %^BLUE%^dark storm clouds%^MAGENTA%^ slowly vanish "
	  "and the %^CYAN%^raging wind%^MAGENTA%^ ceases its howling."
	);
	STORM = 0;
	return;
    }
    if((vic = owner->query_current_attacker()) && STORM == 0) {
	tell_room(environment(owner),
	  "%^RESET%^%^BLUE%^Dark storm clouds gather above and the wind "+
           "begins to howl across the land!\n"
	  "%^YELLOW%^Lightning scorches across the sky and the air is "+
           "charged with an intense energy!"
	  "%^RESET%^"
	);
	STORM = 1;
	return;
    }
    if((vic = owner->query_current_attacker()) && STORM == 1) {
	if(random(30) < 1) {
	    tell_object(vic,
	      "%^YELLOW%^A bolt of lightning streaks down from the "
	      "%^RESET%^%^BLUE%^dark storm clouds%^YELLOW%^ "
	      "and strikes your body!%^RESET%^"
	    );
	    tell_object(owner,
	      "%^YELLOW%^A bolt of lightning streaks down from the "
	      "%^RESET%^%^BLUE%^dark storm clouds%^YELLOW%^ "
	      "and strikes "+vic->QCN+"'s body!%^RESET%^"
	    );
	    vic->do_damage(vic->return_target_limb(),random(15)+5);
	    uses = uses - 1;
	    return;
	}
	if(random(50) < 1) {
	    tell_object(vic,
	      "%^RESET%^%^CYAN%^The %^BLUE%^dark storm clouds%^CYAN%^ "
	      "release a powerful gust of wind at you!\n"
	      "%^RED%^The wind throws you to the ground and holds you there!%^RESET%^"
	    );
	    tell_object(owner,
	      "%^RESET%^%^CYAN%^The %^BLUE%^dark storm clouds%^CYAN%^ "
	      "release a powerful gust of wind at "+vic->QCN+"!\n"
	      "%^RED%^The wind throws "+vic->QCN+" to the ground "
	      "and holds "+vic->QP+" body there!%^RESET%^"
	    );
	    vic->set_paralyzed(random(15)+5,"%^CYAN%^The wind holds you down with great force!%^RESET%^");
	    uses = uses - 1;
	    return;
	}
	return;
    }
    return;
}
int extra_hit(object ob) {
    object vic;
    int dam,cycle,amnt;
    vic = ETO->query_current_attacker();
    if(random(6) < 4) return 1;
    if((string)ETO->query_name() == "render") {
	for(cycle=0;cycle<2;cycle++) {
	    message("my_action",
	      "%^BOLD%^%^BLUE%^The %^GREEN%^Stormbringer%^BLUE%^ channels "+
            "the power of the dark clouds overhead "
	      "deliver a powerful wound to "
	      +vic->query_cap_name()+"!%^RESET%^"
      ,ETO);
	    message("other_action",
      "%^BOLD%^%^BLUE%^The %^GREEN%^Stormbringer%^BLUE%^ wielded by "+
            ""+ETOQCN+" howls with energy as it slices into the flesh of "
	      +vic->QCN+"!"
      ,environment(vic),(({ETO, vic})));
	    message("my_action",
      "%^BOLD%^%^BLUE%^The %^GREEN%^Stormbringer%^BLUE%^ wielded by "+ETO->query_cap_name()+
	      " howls with energy as it slices deep into your flesh!%^RESET%^"
	      ,vic);
	    amnt = random(10)+10;
	    vic->do_damage(vic->return_target_limb(),amnt);
	}
    }
    if (uses < 1) {
	dam = random(1)+1;	    
    } else {  
	if(STORM == 1) { 
	    message("my_action",
	      "%^BOLD%^%^BLUE%^The %^GREEN%^Stormbringer%^BLUE%^ channels the power of the dark clouds overhead "
	      "deliver a powerful wound to "
	      +vic->query_cap_name()+"!%^RESET%^"
      ,ETO);
	    message("other_action",
      "%^BOLD%^%^BLUE%^The %^GREEN%^Stormbringer%^BLUE%^ wielded by "+ETO->query_cap_name()+
	      " howls with energy as it slices into the flesh of "
	      +vic->query_cap_name()+"!"
      ,environment(vic),(({ETO, vic})));
	    message("my_action",
      "%^BOLD%^%^BLUE%^The %^GREEN%^Stormbringer%^BLUE%^ wielded by "+ETO->query_cap_name()+
	      " howls with energy as it slices deep into your flesh!%^RESET%^"
	      ,vic);
	    uses = uses - 1;
	    dam = random(6) + 2;
	} else {
	    message("my_action",
	      "%^GREEN%^The Stormbringer slices deep!%^RESET%^"
      ,ETO);
	    message("my_action",
	      "%^GREEN%^The Stormbringer slices deep!%^RESET%^"
	      ,vic);
	    dam = random(3)+2;
	    uses = uses - 1;
	}	 
    }
    return dam;
}
int extra_wield() {
    object tp;
    tp = ETO;
    if (!tp) return 0;
    if((int)tp->query_level() < 30) {
	write("You could not control the storm this weapon can summon!");
	return 0;
    }
    if((string)ETOQN != owned && (string)ETOQN != "render") {
	write("The Stormbringer fails to bond with you and vanishes!");
	TO->remove();
	return 0;
    }
    if(uses > 0) {
	write(
	  "%^RESET%^%^BLUE%^You hear thunder rumble in the distance.\n"
	  "%^YELLOW%^The air is suddenly charged with electrical energy!%^RESET%^"
	);
	tell_room(environment(ETO),
	  "%^RESET%^%^BLUE%^You hear thunder rumble in the distance.\n"
	  "%^YELLOW%^The air is suddenly charged with electrical energy!%^RESET%^"
	  ,ETO);
	return 1;
    } else {
	write(
	  "%^BLUE%^The Stormbringer can no longer bring the storm.%^RESET%^"
	);
	return 1;
    }
}
