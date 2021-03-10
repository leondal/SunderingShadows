// fixed real name problem in messages *Styx*  2/1/03
// Stab revamp redone by Garrett on December 2004.
// 2017: revision to stab throughput in lib becoming far more reliable, resulting in
// multiple adjustments to damage formula. N.

/**
 * @file
 */

#include <move.h>
#include <std.h>
#include <daemons.h>
inherit DAEMON;

int flip_weapons(object sheath);
int do_strike(object play, object vic);
string damtype;

#define CLASS_STAB_DIE 8
#define MULTI_STAB_DIE 6

int check_other_stab(object play, object vic)
{
    object *weapon, *head, *armor;
    int percent,damage,level,thac0,AC,vic_size,magic;
    int i,j;
    int dex,ret;
    weapon = ({});
    if ( (!objectp(play)) || (!objectp(vic)) ) return 0;

    weapon = play->query_wielded();

    if (((int)play->query_skill("stealth") + roll_dice(1,20)) > ((int)vic->query_skill("perception") + roll_dice(1,20)))
        vic->add_attacker(play);
    else
        play->kill_ob(vic,1);

    i = 10; // bonuses to defender
    if (vic->query_in_vehicle()) i += 2;
    if (vic->query_watched()) i += 5;
    vic->add_attacker(play);
    play->add_attacker(vic);
    if (((int)play->query_skill("stealth") + roll_dice(1,20)) < ((int)vic->query_skill("perception")+ i))
    {
        tell_object(play,"%^BOLD%^"+vic->QCN+" %^BOLD%^was obviously watching and catches you!");
        tell_object(vic,"%^BOLD%^You catch "+play->QCN+" %^BOLD%^trying to stab you.");
        tell_room(environment(play),"%^BOLD%^"+vic->QCN+" catches "+play->QCN+" %^BOLD%^trying to stab "+vic->QO+"!",({play,vic}));
        return 0;
    }
    return 1;
}


int do_stab(object player, object victim)
{
    object *inv =({});
    object *inven, *wield, sheath, orig_dagger, sheath_dagger;
    int sheath_weight, orig_weight, lastwatched, successful_stab = 0;
    string p_qcn, v_qcn, p_poss, p_subj;

    if (objectp(present("wrist sheaths", player)))
    {
        inv = all_inventory(player)->valid_stab_sheath();
        inv -= ({ 0 });
        if(sizeof(inv))
        {
            // We don't need to do a thing here.
            // Well, in case we do, this is here. Note we do the check first.
        }
    }

    lastwatched = victim->query_watched();
    if(do_strike(player,victim))
    {
        // first stab
        successful_stab ++;
        if (!victim->has_stab_func()) victim->continue_attack();
        // If it  has a stab function, don't check for death yet....
        // We'll do this at the end, and the sheaths will have to get used more.
        // garrett

        if(!objectp(victim)) return successful_stab;

    }
    else
    {
        //  Original stab missed.
    }

    // Done with stabs.
    // Finish cleaning up.
    if(successful_stab)
    {
        if(objectp(victim))
            victim->do_stab_func();

        player->clean_up_attackers();
            //    if (objectp(victim) && !victim->query_deaths_door())
        if (objectp(victim))
            victim->continue_attack();
    }
    return successful_stab;
}

int scramble_stab(object stabber, object victim)
{
    int penalty,damage,level,roll,magic;
    object* weapon;
    int nostab = 0;

    // This is going to get messy. This is all new code.

    weapon = stabber->query_wielded();

    if (!objectp(victim))
        victim = stabber->query_current_attacker();

    if (interactive(victim))
    {
        if ((member_array((string)victim->query_race(),VALID_BACKS) == -1 ))
        {
            nostab = 1;
        }
    }
    else if (member_array((string)victim->query_body_type(),VALID_BACKS) == -1 )
    {
        nostab = 1;
    }

    if (!nostab)
    {
        return do_stab(stabber, victim);
        //stabber->clean_up_attackers();
    }

    else
    {
        if(!check_other_stab(stabber, victim)) return 0;
        switch(random(3))
        {
		case 0:
            tell_object(stabber,"%^BOLD%^%^YELLOW%^You move quickly into position and execute three quick slices at l%^RESET%^i%^YELLOW%^g%^RESET%^h%^BOLD%^%^YELLOW%^t%^RESET%^n%^BOLD%^%^YELLOW%^i%^RESET%^n%^BOLD%^%^YELLOW%^g speed!");
            tell_object(victim,"%^BOLD%^%^BLUE%^"+stabber->query_cap_name()+" quickly moves into position and executes three l%^RESET%^i%^BLUE%^g%^RESET%^h%^BOLD%^%^BLUE%^t%^RESET%^n%^BOLD%^%^BLUE%^i%^RESET%^n%^BOLD%^%^BLUE%^g quick slices!");
            tell_room(environment(stabber),"%^BOLD%^%^YELLOW%^"+stabber->query_cap_name()+" quickly moves into position on "+victim->query_cap_name()+" and executes three attacks at l%^RESET%^i%^BOLD%^%^YELLOW%^g%^RESET%^h%^BOLD%^%^YELLOW%^t%^RESET%^n%^BOLD%^%^YELLOW%^i%^RESET%^n%^BOLD%^%^YELLOW%^g speed!",({ victim, stabber }) );
	        break;
	    case 1:
            tell_object(stabber,"%^BOLD%^%^GREEN%^You drop a hidden %^BOLD%^%^BLACK%^d%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^gg%^RESET%^GREEN%^e%^BOLD%^%^GREEN%^r from the folds of your apparel and kick it from the %^BOLD%^%^YELLOW%^hilt%^BOLD%^%^GREEN%^, sending it flying at "+victim->query_cap_name()+"!");
            tell_object(victim,"%^BOLD%^%^BLUE%^"+stabber->query_cap_name()+" drops a hidden dagger from the folds of  "+stabber->query_possessive()+" apparel and kicks it from the hilt, sending it flying at you!");
            tell_room(environment(stabber),"%^BOLD%^%^GREEN%^"+stabber->query_cap_name()+" drops a hidden %^BOLD%^%^BLACK%^d%^RESET%^%^GREEN%^a%^BOLD%^%^BLACK%^gg%^RESET%^%^GREEN%^er %^BOLD%^%^GREEN%^from "+stabber->query_possessive()+" apparel and kicks it from the %^BOLD%^%^YELLOW%^hilt%^BOLD%^%^GREEN%^, sending it flying at "+victim->query_cap_name()+"!",({ victim, stabber }) );
	        break;
	    case 2:
            tell_object(stabber,"%^BOLD%^%^RED%^You reach into your pocket and slap a rune covered %^RESET%^%^RED%^note%^BOLD%^%^RED%^ on "+victim->query_cap_name()+"! You roll backwards as it *pause* E%^BOLD%^%^BLACK%^X%^BOLD%^%^RED%^P%^BOLD%^%^BLACK%^L%^BOLD%^%^RED%^O%^BOLD%^%^BLACK%^D%^BOLD%^%^RED%^E%^BOLD%^%^BLACK%^S%^BOLD%^%^RED%^ seconds later!");
            tell_object(victim,"%^BOLD%^%^RED%^"+stabber->query_cap_name()+" reaches into "+stabber->query_possessive()+" pocket and slaps an rune covered note on you before rolling away! Seconds later it EXPLODES!");
            tell_room(environment(stabber),"%^BOLD%^%^RED%^"+stabber->query_cap_name()+" reaches into "+stabber->query_possessive()+" pocket and slaps a rune covered %^RESET%^%^RED%^note%^BOLD%^%^RED%^ on "+victim->query_cap_name()+"! Seconds later *pause* it E%^BOLD%^%^BLACK%^X%^BOLD%^%^RED%^P%^BOLD%^%^BLACK%^L%^BOLD%^%^RED%^O%^BOLD%^%^BLACK%^D%^BOLD%^%^RED%^E%^BOLD%^%^BLACK%^S%^BOLD%^%^RED%^!",({ victim, stabber }) );
	        break;
        }

        if(victim->query_property("weapon resistance"))
        {
            int enchantment, resistance;
            enchantment = 0; //default 0
            resistance = (int) victim->query_property("weapon resistance");
            if(!objectp(weapon)) {enchantment = (int) COMBAT_D->unarmed_enchantment(TP);}
            else if(objectp(weapon)) {enchantment = (int) weapon->query_property("enchantment");}
            if (enchantment < resistance) { damage = 0; }
        }

        if (stabber->is_class("thief"))
        {
            if(userp(stabber)) { level = stabber->query_guild_level("thief"); }
            else { level = stabber->query_class_level("thief"); }
        }
// time to change things up now that stab is far more reliable. trying a formula akin to sourcebooks! N, 3/17.
// if this downgrade is too drastic, please fix below line.
        level = (level/2)+1; // parallels the d6 per odd level, though for now we are trying d8 to prevent too much nerfings.

        if(stabber->query_property("strong stab")) roll = CLASS_STAB_DIE;
        else roll = MULTI_STAB_DIE;

        damage += roll_dice(level,roll);

        if(sizeof(weapon) && objectp(weapon[0]) && weapon[0]->query_property("magic"))
        {
            magic = 1;
            stabber->set_property("magic",1);
        }

        if(sizeof(weapon))
        {
          damtype = weapon[0]->query_damage_type();
        }
        else{
          damtype = "piercing";
        }

        stabber->cause_typed_damage(victim,"torso",damage,damtype);
        // putting this here so if their weapon gets an execute_attack special they don't loose their stab -Ares
        if(sizeof(weapon) && objectp(weapon[0]))
        {
            stabber->cause_typed_damage(victim,"torso",(int)stabber->get_damage(weapon[0]),weapon[0]->query_damage_type());
        }

        if(magic)
        {
            stabber->set_property("magic",-1);
            magic = 0;
        }

        stabber->clean_up_attackers();

        if (objectp(victim))
            victim->continue_attack();
        if (objectp(victim))
        {
            //      stabber->execute_attack();
            //      victim->continue_attack();
        }
/*
    penalty = -1 * penalty;
    stabber->add_attack_bonus(penalty);
    stabber->clean_up_attackers();
    return -1;
*/
    }
    return 0;
}

varargs int get_stab_damage(object player,object target,object weapon)
{
	int thac0,ret,roll,level,size,damage,i;
	object *head;

	if(!objectp(player)) { return 0; }
	if(!objectp(target)) { return 0; }

	if(objectp(weapon)) { thac0 = player->Thaco(0,target,weapon,"thief"); }
	else { thac0 = player->Thaco(0,target,0,"thief"); }

    if(!target->query_limbs()) { return 0; }
	if ((member_array("head",target->query_limbs()) != -1 ) && pointerp( head = target->query_armour("head")))
    for (i = 0;i<sizeof(head);i++)
	{
		thac0 -= (int)head[i]->query_ac();
    }

	ret = BONUS_D->query_dex_bonus(target);
	ret-= BONUS_D->query_stance_bonus(target);
	thac0 += ret;
	roll = random(20)+1;

	if (player->is_class("thief"))
    {
        if(userp(player))
        {
            level = player->query_guild_level("thief");
            //If they're an arcane trickster, they gain +5 stab level (to be closer to SRD)
            if(FEATS_D->usable_feat(player, "invisible thief"))
                level += 5;
        }
        else { level = player->query_class_level("thief"); }
    }

      level = (level/2)+1; // parallels the d6 per odd level, though for now we are trying d8 to prevent too much nerfings.

	if (!objectp(target)) return 0;
	size = (int)target->query_size();
	if(objectp(weapon))
	{
    damage = weapon->query_damage();
  }
	else { damage = roll_dice(1,4); }

	if(FEATS_D->usable_feat(player,"weapon finesse")) damage += "/daemon/bonus_d"->damage_bonus(player->query_stats("dexterity"));
	else damage += "/daemon/bonus_d"->damage_bonus(player->query_stats("strength"));

// need to remove this. damage_bonus above already picks this up in the daemon!
//	damage += player->query_damage_bonus();

// no such thing as "singleclass" anymore, so we only really need to track strong stabs
  // property to give option of multi mobs with full stab damage, aka super solstice
//	if (player->is_singleClass("thief") || player->query_property("strong stab")) { roll = CLASS_STAB_DIE; }
      if(player->query_property("strong stab")) roll = CLASS_STAB_DIE;
      else roll = MULTI_STAB_DIE;

	damage += roll_dice(level,roll); // 1d8 per level for "strong stab" creatures, 1d6 for normal/players

    if(objectp(target))
    {
        if(target->query_property("weapon resistance"))
	    {
            int enchantment, resistance;
            enchantment = 0; //default 0
            resistance = (int) target->query_property("weapon resistance");
            if(!objectp(weapon)) {enchantment = (int) COMBAT_D->unarmed_enchantment(TP);}
            else if(objectp(weapon)) {enchantment = (int) weapon->query_property("enchantment");}
            if (enchantment < resistance) { damage = 0; }
        }
    }

	return damage;
}

int do_strike(object play, object vic)
{
    object *weapon, *head, *armor;
    int percent,damage,level,thac0,AC,vic_size,magic;
    int i,j;
    int dex,ret;

    // Important safety tip. In this function, 1 indicates a successful,
    // connecting stab. A 0 indicates no connection. This is passed up to
    // the do_stab function each time the function returns.
    // This is the big part of the cleanup in that the loop happens
    // within the stab command and not externally in the sheaths.
    // - Garrett.

    weapon = ({});
    if ( (!objectp(play)) || (!objectp(vic)) ) return 0;

    weapon = play->query_wielded();

    //"/daemon/killing_d"->check_actions(play,vic);

    if (((int)play->query_skill("stealth") + roll_dice(1,20)) > ((int)vic->query_skill("perception") + roll_dice(1,20)))
        vic->add_attacker(play);
    else
        play->kill_ob(vic,1);

    i = 26; // bonuses to defender
    if (vic->query_in_vehicle()) i += 2;
    if (vic->query_watched()) i += 5;
    vic->add_attacker(play);
    play->add_attacker(vic);
    if (((int)play->query_skill("stealth") + roll_dice(4,12)) < ((int)vic->query_skill("perception")+ i))
    {
        tell_object(play,"%^BOLD%^"+vic->QCN+" %^BOLD%^was obviously watching "+vic->QP+" back and catches you.");
        tell_object(vic,"%^BOLD%^You catch "+play->QCN+" %^BOLD%^trying to stab you.");
        tell_room(environment(play),"%^BOLD%^"+vic->QCN+" catches "+play->QCN+" %^BOLD%^trying to stab "+vic->QO+"!",({play,vic}));
        return 0;
    }

    if ((int)vic->query_watched() < 4*((int)vic->query_skill("perception") + roll_dice(1,20)))
        vic->set_watched(4*((int)vic->query_skill("perception") + roll_dice(1,20)));

    if(pointerp(weapon) && sizeof(weapon) > 0)
    {
        if(objectp(weapon[0])) damage = get_stab_damage(play,vic,weapon[0]);
    }
	else damage = get_stab_damage(play,vic);

    if (play->query_property("magic")) set_property("magic",1);

    armor = vic->query_armour("torso");
    j = sizeof(armor);

    for (i=0;i<j;i++)
    {
        if (!objectp(armor[i])) continue;
        if(random(3))
        {
	        if (!sizeof(weapon) || !objectp(weapon[0])) damage += armor[i]->do_struck(damage,0,play);
	        else damage += armor[i]->do_struck(damage,weapon[0],play);
        }
    }

    tell_room(environment(play),"%^BOLD%^%^RED%^You see "+play->QCN+" plunge a deep blow "
        "into "+vic->QCN+"'s back.",({play,vic}));
    tell_object(play,"%^BOLD%^%^RED%^You land a deep blow into your target's back.%^RESET%^");
    tell_object(vic,"%^BOLD%^%^RED%^"+play->QCN+" stabs you in the back!%^RESET%^");

    if(sizeof(weapon) && objectp(weapon[0]) && weapon[0]->query_property("magic"))
    {
        magic = 1;
        play->set_property("magic",1);
    }

    if(sizeof(weapon))
    {
      damtype = weapon[0]->query_damage_type();
    }
    else{
      damtype = "piercing";
    }

    play->cause_typed_damage(vic,"torso",damage,damtype);
    // putting this here so if their weapon gets an execute_attack special they don't loose their stab -Ares
    if(sizeof(weapon) && objectp(weapon[0]))
    {
        play->cause_typed_damage(vic,"torso",(int)play->get_damage(weapon[0]),weapon[0]->query_damage_type());
    }

    if(magic)
    {
        play->set_property("magic",-1);
        magic = 0;
    }

    if (objectp(vic) && !vic->query_deaths_door())
    {
        play->continue_attack();
        play->kill_ob(vic,1);
    }
    remove_property("magic");
    return 1;
}

int cmd_stab(string str)
{
    object victim, *weapon;

    weapon = ({});
    remove_property("magic");

    if (!TP->is_class("thief") && !TP->is_class("assassin"))
    {
        notify_fail("You are not allowed to do that.\n");
        return 0;
    }

    if (!str)
    {
        notify_fail("Who?\n");
        return 0;
    }

    if (TP->query_bound())
    {
        TP->send_paralyzed_message("info",TP);
        return 1;
    }

    str = lower_case(str);
    victim = present(str, environment(this_player()));

    if (!victim)
    {
        notify_fail("You don't see that here.\n");
        return 0;
    }

    if (victim->query_ghost())
    {
        notify_fail("You cannot stab a ghost!\n");
        return 0;
    }

    if (victim->query_deaths_door())
    {
        return notify_fail("That person is already on death's door step.\n");
    }

    if (victim == TP) return notify_fail("You can't reach your own back.\n");

    TP->clean_up_attackers();
    victim->clean_up_attackers();

    if ((object *)TP->query_attackers() != ({}) || (member_array(victim, (object*)TP->query_hunted()) != -1))
    {
        write("You can't do that while being attacked.");
        return 1;
    }
    else
    {
        if (!this_player()->ok_to_kill(victim))
        {
            notify_fail("Supernatural forces prevent your attack.\n");
            return 0;
        }
        if (ETP->query_property("no kill"))
        {
            notify_fail("Supernatural forces prevent your attack.\n");
            return 0;
        }
        if(!TP->is_ok_armour("thief"))
        {
            write("You cannot stab while wearing all that armor!");
            return 0;
        }

        if (member_array((string)victim->query_body_type(),VALID_BACKS) == -1 && !interactive(victim))
        {
            //notify_fail("You can't find the back.\n");
            //return 0;
            scramble_stab(TP, victim);
            TP->set_disable(25, victim);
            return 1;
        }

        weapon = TP->query_wielded();
        if (sizeof(weapon)) {
            scramble_stab(TP, victim);
            TP->set_disable(25, victim);
            return 1;
        }

        do_stab(TP, victim);
        TP->set_disable(25, victim);
        return 1;
    }
}

int help()
{
    write("Usage: stab <monster id>");
    return 1;
}
