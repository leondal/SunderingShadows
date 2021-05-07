/**
 * @file
 * @brief Various combat subroutines
 *
 * Daemon that handles Combat related stuff
 * Currently handling checks for shieldmiss/concealing amorpha
 * damage modifications from body.c - including stoneskin checks, typed damage modifications, etc.
 * my intention was to make all of this easier to modify on the fly - Saide
 */


#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <damage_types.h>
#include <security.h>

#define PO previous_object()
#define DAMAGE_TRACKER_OBJECT "/realms/saide/damage_tracking_saide"
#define BAD_LIMBS ({ "torso", "neck", "waist", "lower torso", "tail" })
#define TEMP_HIT_BONUS "/realms/ares/temporary_hit.c"  // remove this when done
#define DEATHS_DOOR_MESSAGE "You are at %^BOLD%^Death's door%^RESET%^. Your body is slipping from you."
#define PK_OB "/d/shadowgate/pkill_tracker"

mapping DAMAGE_TRACKING;

int critical_roll = 0;
int counter_damage = 0;

void save_damage_tracker()
{
    seteuid(UID_RESTORE);
    save_object(DAMAGE_TRACKER_OBJECT);
    seteuid(geteuid());
}

void restore_damage_tracker()
{
    seteuid(UID_RESTORE);
    restore_object(DAMAGE_TRACKER_OBJECT);
    seteuid(geteuid());
}

//this is called in internal_execute_attack in combat.c
//is also called in feat.c in the thaco() function can be ignored there for touch attack type feats
//can be called anywhere you want to check to see if a person successfully deflects or avoids an attack
//called when the dice roll is not 20 or not a miss - so
//only when attacker hits with a dice roll that is not 20
//I am treating 20s as automatic hits bypassing shields and concealing amorpha - Saide
//a return value of 1 will be processed as a hit
//a return value of 0 is a miss - tell the attacker and the victim - Saide

varargs int extra_hit_calcs(object attacker, object victim, object weapon, string limb)
{
    object env, rider, defender;
    int ShieldMissChance, MissChance, AttackerMissChance, mount;
    if (!objectp(attacker)) {
        return 1;
    }
    if (!objectp(victim)) {
        return 1;
    }
    if (victim->query_paralyzed()) {
        return 1;
    }
    if (victim->is_animal()) {
        rider = (object)victim->query_current_rider();
        if (objectp(rider)) {
            mount = 1;
        }
    }
    MissChance = (int)victim->query_missChance();
    
    if(attacker->query_blind() || attacker->light_blind())
    {
        if(FEATS_D->usable_feat(attacker, "blindfight"))
            MissChance += 25;
        else
            MissChance += 50;
    }
    
    if (mount && FEATS_D->usable_feat(rider, "mounted shield")) {
        ShieldMissChance = (int)rider->query_shieldMiss();
    }else {
        ShieldMissChance = (int)victim->query_shieldMiss();
    }
    AttackerMissChance = (int)attacker->query_property("noMissChance");
    //attacker has a property set so that they cannot miss - Saide
    
    //True seeing negates misschance
    if(attacker->true_seeing())
        MissChance = 0;
    
    if (AttackerMissChance) {
        return 1;
    }
    if (attacker == victim) {
        return 1;
    }
    if (!MissChance && !ShieldMissChance) {
        return 1;
    }
    if (attacker->is_spell()) {
        return 1;
    }

    env = environment(attacker);

    if (!ShieldMissChance || MissChance > ShieldMissChance) {
        if (MissChance >= roll_dice(1, 100)) {
            tell_object(victim, attacker->QCN + "%^BOLD%^%^WHITE%^ cannot see you and misses!");
            tell_object(attacker, "%^BOLD%^%^WHITE%^You cannot see " + victim->QCN + " and miss " + victim->QO + "!");
            attacker->delete("featMiss");
            attacker->set("featMiss", victim->QCN + " avoided your");
            if (objectp(env)) {
                tell_room(env, attacker->QCN + "%^BOLD%^%^WHITE%^ misses " + victim->QCN + "!%^RESET%^", ({ victim, attacker }));
            }
            return 0;
        }
        return 1;
    }else {
        if (victim->query_property("shapeshifted")) {
            return 1;
        }
        if (ShieldMissChance >= roll_dice(1, 100)) {
            if (mount) {
                defender = rider;
            }else {
                defender = victim;
            }
            if (living(attacker)) {
                tell_object(attacker, "%^RESET%^%^BOLD%^Your attack is deflected off of " + defender->QCN + "'s "
                            "shield!%^RESET%^");
                attacker->delete("featMiss");
                attacker->set("featMiss", victim->QCN + " deflected your");
                tell_object(victim, "%^RESET%^%^BOLD%^You deflect " + attacker->QCN + "'s attack with your "
                            "shield!%^RESET%^");

                if (objectp(env)) {
                    tell_room(env, "%^RESET%^%^BOLD%^" + defender->QCN + " deflects " + attacker->QCN + "'s attack with "
                              "" + defender->QP + " shield!%^RESET%^", ({ attacker, defender }));
                }
            }else {
                tell_object(victim, "%^RESET%^%^BOLD%^You deflect the attack with your shield!%^RESET%^");
                if (objectp(env)) {
                    tell_room(env, "%^RESET%^%^BOLD%^" + defender->QCN + " deflects the attack with " + defender->QP + " shield!%^RESET%^", ({ defender }));
                }
            }
            if (FEATS_D->usable_feat(victim, "counter")) {
                if (random(4)) {
                    counter_attack(victim);
                }
            }
            return 0;
        }
        return 1;
    }
    return 1;
}

//let us track damage - we can keep up with each time this function
//is called on a player - and then divide the overall amount / number
//of attacks to estimate an average and then go from there - Saide - September 2016

void track_damage(object attacker, object victim, int damage)
{
    string* being_tracked, tname;
    int myhits = 0, myignore = 0, isuser = 0, mylev = 0, maxdamage = 0;
    int mindamage = 0, avgdamage = 0;
    return;

    if (damage > 0) {
        myhits = 1;
    }else {
        myignore = 1;
    }
    if (!objectp(attacker)) {
        return;
    }
    //if(!objectp(victim)) return;
    if (!mapp(DAMAGE_TRACKING)) {
        restore_damage_tracker();
    }
    if (!mapp(DAMAGE_TRACKING)) {
        DAMAGE_TRACKING = ([]);
    }
    being_tracked = keys(DAMAGE_TRACKING);
    if (userp(attacker)) {
        isuser = 1;
    }
    mylev = attacker->query_level();
    tname = attacker->query_name() + " @ level " + mylev;
    if (!sizeof(being_tracked)) {
        DAMAGE_TRACKING = ([tname:(["damage" : damage, "hits" : myhits, "ignored" : myignore, "user" : isuser, "max damage" : damage, "min damage" :
                              damage, "average damage" : damage]) ]);
        save_damage_tracker();
        return;
    }else {
        if (member_array(tname, being_tracked) == -1) {
            DAMAGE_TRACKING += ([tname:(["damage" : damage, "hits" : myhits, "ignored" : myignore, "user" : isuser, "max damage" : damage, "min damage" : damage, "average damage" : damage]) ]);
        }else {
            DAMAGE_TRACKING[tname]["damage"] += damage;
            DAMAGE_TRACKING[tname]["hits"] += myhits;
            DAMAGE_TRACKING[tname]["ignored"] += myignore;
            maxdamage = DAMAGE_TRACKING[tname]["max damage"];
            mindamage = DAMAGE_TRACKING[tname]["min damage"];
            if (damage < mindamage) {
                DAMAGE_TRACKING[tname]["min damage"] = damage;
            }
            if (damage > maxdamage) {
                DAMAGE_TRACKING[tname]["max damage"] = damage;
            }
            if (DAMAGE_TRACKING[tname]["hits"] > 0) {
                avgdamage = DAMAGE_TRACKING[tname]["damage"] / DAMAGE_TRACKING[tname]["hits"];
            }
            DAMAGE_TRACKING[tname]["average damage"] = avgdamage;
        }
    }
    save_damage_tracker();
    return;
}

//moved a bunch of code from the do_damage function here - Saide

varargs int damage_adjustment(object attacker, object victim, int damage)
{
    int mod, num, layers;
    object env, myspl;
    mapping logdata;
    if (!objectp(attacker)) {
        return damage;
    }
    if (!objectp(victim)) {
        return damage;
    }
    if (!intp(damage)) {
        return damage;
    }
    env = environment(attacker);

    // adding a damage resistance property which will directly
    // reduce the damage by the amount.  We can probably do away
    // with this when the types and resistances go into place -Ares

    // adding in check for new feat 21+ thief/monk to reduce mass-damage blows. N, 4/13.
    if (FEATS_D->usable_feat(victim, "defensive roll")) {
        num = (int)victim->query_max_hp() / 4;
        if (damage > num) { // kicks in for any blow greater than 25% of hp.
            num = ((int)victim->query_level() / 2) + 18; // DC to be roughly 50% success for SC without feats/etc
            logdata = "/daemon/saving_throw_d.c"->debug_reflex_save(victim, ((-1) * num)); // logging success rate

            if (logdata["save_result"]) {
                damage = damage / 2;
                if (damage < 0) {
                    damage = 0;
                }
                if (living(attacker)) {
                    tell_object(attacker, victim->QCN + "%^RESET%^%^BOLD%^ rolls with your attack, lessening its force!%^RESET%^");
                    if (objectp(env)) {
                        tell_room(env, victim->QCN + "%^RESET%^%^BOLD%^ rolls with " + attacker->QCN + "%^RESET%^%^BOLD%^'s
attack, lessing its force!%^RESET%^");
                    }
                }
                tell_object(victim, "%^RESET%^%^BOLD%^You roll with the attack, lessening its force!%^RESET%^");
                if (damage <= 0) {
                    //track_damage(attacker, victim, damage);
                    return damage;
                }
            }
        }
    }

    return damage;
}

varargs int typed_damage_modification(object attacker, object targ, string limb, int damage, string type)
{
    object myEB;
    int resist_perc, resist, reduction, mod, amt, i;
    float percentage;
    string* alignments, * enemy_alignments;
    string target_align;

    if (!objectp(targ)) {
        return 0;
    }
    if (!stringp(limb)) {
        limb = targ->return_target_limb();
    }
    if (!damage) {
        return 0;
    }
    targ->set_magic_attack(0);
    targ->spell_attack(0);
    limb = targ->adjust_targeted_limb(attacker, limb);
    damage = targ->do_typed_damage_effects(attacker, limb, damage, type);
    if (!targ->initialized_resistances()) {
        targ->init_limb_data();
    }

    if (!stringp(type) || !targ->valid_resistance(type)) {
        if (objectp(attacker)) {
            log_file("errors/invalid_damage_types", "" + ctime(time()) + " " + base_name(attacker) + " tried to use an invalid damage type:
" + type + "\n");
        }
        return damage;
    }
    
    //Prismatic sphere prevents damage between combatants.
    if(targ->query_property("prismatic sphere") || attacker->query_property("prismatic sphere"))
        return 0;

    if (objectp(targ) && FEATS_D->usable_feat(targ, "kinetic conversion")) {
        if (member_array(type, PHYSICAL_DAMAGE_TYPES) > -1) {
            amt = damage / 4;
            if (amt > 3) {
                amt = 3;
            }
            if (amt < 1) {
                amt = 1;
            }
            targ->add_mp(amt);
        }
    }

    if (objectp(targ) && FEATS_D->usable_feat(targ, "way of the learned pupil")) {
        USER_D->regenerate_ki(targ, 1);
    }

    resist_perc = (int)targ->query_resistance_percent(type);

    resist = (int)targ->query_resistance(type);

    if (resist_perc > 500) {
        resist_perc = 500;
    }
    if (resist_perc < -500) {
        resist_perc = -500;
    }

    // resistance less than 0 equals more damage done
    // resistance between 0 and 100 equals reduced damage
    // resistance greater than 100 equals healing
    percentage = to_float((100 - resist_perc) / to_float(100));

    damage = to_int(damage * percentage);

    if (damage > 0) {
        damage = damage - resist;
        if (damage < 0) {
            damage = 0;
        }
    }


    if ((type == "negative energy" ||
        type == "positive energy") &&
        member_array(targ->query_race(), ({"soulforged", "golem", "construct"})) != -1) {
        return 0;
    }


    if (type == "negative energy") {
        if (targ->query_property("heart of darkness") ||
            FEATS_D->usable_feat(targ, "undead graft") ||
            member_array("undeath", targ->query_divine_domain()) >= 0 ||
            targ->query_property("negative energy affinity")) {
            damage = -abs(damage);
        }else {
            damage = abs(damage);
        }
    }

    if (type == "positive energy") {
        if (targ->query_property("negative energy affinity")) {
            damage = abs(damage);
        }else {
            damage = -abs(damage);
        }
    }


    if (damage > 0 && type != "force" && objectp(myEB = targ->query_property("empty body"))) {
        return 0;
    }

    if (damage > 0) {
        if (attacker->is_living()) {
            if (targ->query_property("shadowform")) {
                int sf_pwr = targ->query_property("shadowform");
                if (!"/daemon/saving_throw_d"->will_save(attacker, -sf_pwr)) {
                    damage /= 5;
                }
            }
            if (targ->query_property("shielded_by")) {
                object shielder = targ->query_property("shielded_by");
                if (objectp(targ->query_property("shielded_by")) &&
                    objectp(ENV(targ)) &&
                    objectp(ENV(shielder)) &&
                    ENV(shielder) == ENV(targ) &&
                    !shielder->query_property("shielded_by")) {
                        damage /= 2;
                        shielder->cause_typed_damage(shielder, shielder->return_target_limb(), damage, type);
                } else {
                    targ->remove_property("shielded_by");
                }
            }
        }
    }

    if (targ->query_verbose_combat()) {
        if (damage > 0) {
            tell_object(targ, "You are harmed by " + type + ".");
        } else {
            tell_object(targ, "You are healed by " + type + ".");
        }
    }

    if (objectp(attacker)) {
        if (attacker->query_property("noMissChance") ||
            attacker->query_property("magic") ||
            (objectp(attacker->query_current_weapon()) &&
             (attacker->query_current_weapon())->query_property("magic"))) {
            targ->set_magic_attack(1);
        }

        if (PO->is_spell()) {
            targ->set_spell_attack(1);
        }
    }

    //Healing effects reduction on typed damage
    if (targ->query_property("fester") && damage < 0) {
        damage += targ->query_property("fester");
        if (damage > 0) {
            damage = 0;
            return damage;
        }
    }

    if ((int)targ->query_property("damage resistance")) {
        if (member_array(type, PHYSICAL_DAMAGE_TYPES) != -1) {
            if (damage > 0) {
                target_align = (string)targ->query_true_align();
                if (targ->query_alignment()) {
                    if (arrayp(attacker->query_property("aligned_weapon"))) {
                        if (member_array(targ->query_alignment(), attacker->query_property("aligned_weapon")) != -1) {
                            return damage;
                        }
                    }
                    //alignments, enemy_alignments, target_align, i
                    alignments = ({ "alignment 147", "alignment 369", "alignment 123", "alignment 789" });
                    enemy_alignments = ({ "369", "147", "789", "123" });
                    if (attacker->query_property("weapon enhancement timer")) {
                        for (i = 0; i < sizeof(alignments); i++)
                        {
                            if (attacker->query_property(alignments[i]) &&
                                strsrch(enemy_alignments[i], target_align + "") + 1) {
                                return damage;
                            }
                        }
                    }
                }

                reduction = (int)targ->query_property("damage resistance");
                
                if(LIVING_D->check_aura(targ, "justification") == 2)
                {
                    if(LIVING_D->opposed_alignment(targ, attacker))
                    {
                        reduction += 5;
                        if(FEATS_D->usable_feat("champion"))
                            reduction += 5;
                    }
                }

                if(targ->is_class("cleric"))
                {
                    if(LIVING_D->opposed_alignment(targ, attacker))
                    {
                        if(member_array("good", targ->query_divine_domain()) >= 0)
                             reduction += 5;
                    }
                }

                if (attacker->query_property("magic")) {
                    mod = (int)attacker->query_property("magic") * 10;
                }
                else if (objectp(attacker->query_current_weapon()) && (attacker->query_current_weapon())->query_property("magic")) {
                    mod = (int)attacker->query_current_weapon()->query_property("magic") * 10;
                }

                reduction -= attacker->query_property("damage penetration");

                reduction -= mod;
                if (reduction < 0) {
                    reduction = 0;
                }
                damage -= reduction;
                if (damage < 0) {
                    damage = 0;
                    return damage;
                }
            }
        }
    }

    if ((int)targ->query_property("spell damage resistance")) {
        if (member_array(type, (VALID_DAMAGE_TYPES - PHYSICAL_DAMAGE_TYPES)) != -1) {
            if (damage > 0) {
                reduction = (int)targ->query_property("spell damage resistance");
                //if we want something to work through this property, it should be set here - Saide
                mod = 0;
                reduction -= mod;
                if (reduction < 0) {
                    reduction = 0;
                }
                damage -= reduction;
                if (damage < 0) {
                    damage = 0;
                    return damage;
                }
            }
        }
    }
    return damage;
}

void check_extra_abilities(object attacker, object target, object weapon, int crit_hit)
{
    string ename, pname, enhance_msg, target_align;
    int effect_chance, enhance_dmg, crit_mult, enhance_chance, is_main_hand, effective_level, i;
    object room, * weapons, *att;
    string* elements, * actions, * bursts, * colors, * alignments, * enemy_alignments, * align_text, * a_colors;

    if (!objectp(attacker)) {
        return;
    }
    if (!objectp(weapon)) {
        return;
    }

    pname = capitalize(attacker->query_name());
    ename = capitalize(target->query_name());
    room = environment(attacker);

    if (crit_hit) {
        if (
            !attacker->query_property("shapeshifted") &&
            objectp(weapon) &&
            !random(3) &&
            FEATS_D->usable_feat(attacker, "shadow master")) {
            tell_object(attacker, "%^BLUE%^You strike " + target->QCN + " with precision as you channel your command of the shadows, and " + target->QS + " blinks sightlessly!%^RESET%^");
            tell_object(target, "%^BLUE%^As " + attacker->QCN + " strikes you, your vision grows momentarily clouded!%^RESET%^");
            target->set_temporary_blinded(1, "Your vision is clouded!");
        }
        if (FEATS_D->usable_feat(attacker, "spell critical")) {
            tell_object(attacker, "%^CYAN%^You unleash wave of %^YELLOW%^w%^MAGENTA%^i%^WHITE%^l%^RED%^d %^GREEN%^m%^BLUE%^a%^WHITE%^g%^ORANGE%^i%^RED%^c%^RESET%^%^CYAN%^ at " + target->QCN + "!%^RESET%^");
            tell_object(target, "%^CYAN%^" + attacker->QCN + " unleashes a wave of %^YELLOW%^w%^MAGENTA%^i%^WHITE%^l%^RED%^d %^GREEN%^m%^BLUE%^a%^WHITE%^g%^ORANGE%^i%^RED%^c%^RESET%^%^CYAN%^ to burn through you!%^RESET%^");
            tell_room(environment(attacker), "%^CYAN%^" + attacker->QCN + " unleashes a wave of %^YELLOW%^w%^MAGENTA%^i%^WHITE%^l%^RED%^d %^GREEN%^m%^BLUE%^a%^WHITE%^g%^ORANGE%^i%^RED%^c%^RESET%^%^CYAN%^ at " + target->QCN + "!%^RESET%^", ({ target, attacker }));
            target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(attacker->query_character_level() / 15, 6), "untyped");
        }

        //Handles Crypststalker feat
        if (
            target &&
            target->is_undead() &&
            FEATS_D->usable_feat(attacker, "smite the lifeless")) {
            //Needs adjusting to not one-shot Vecna/intruder but also be effective against smaller bosses
            if (target->query_hp_percent() < 90) {
                if (!target->fort_save(max( ({ BONUS_D->query_stat_bonus(attacker, "strength"), BONUS_D->query_stat_bonus(attacker, "dexterity") }) )) && (userp(target) ? target->query_level() <= attacker->query_level() : target->query_level() < 56)) {
                    tell_object(attacker, "%^BOLD%^You unleash a flash of blinding white energy as you destroy " + target->QCN + "'s undead energy and end them!%^RESET%^");
                    tell_object(target, "%^BOLD%^" + attacker->QCN + " unleashes a flash of blinding white light that ends your undead existence!%^RESET%^");
                    tell_room(environment(attacker), "%^BOLD%^" + attacker->QCN + " unleashes a flash of blinding white light that ends " + target->QCN + "'s undead existence!%^RESET%^", ({ target, attacker }));
                    target->set_hp(-100);
                }
                else
                {
                    tell_object(attacker, "%^BOLD%^You unleash a flash of searing energy that burns " + target->QCN + "'s very essence!%^RESET%^");
                    tell_object(target, "%^BOLD%^" + attacker->QCN + " unleashes a flash of searing white light burns your very essence!RESET%^");
                    tell_room(environment(attacker), "%^BOLD%^" + attacker->QCN + " unleashes a flash of searing energy that burns " + target->QCN + "'s undead essence!%^RESET%^", ({ target, attacker }));
                    target->cause_typed_damage(target, target->return_target_limb(), 5 + roll_dice(attacker->query_guild_level("ranger") / 15, 6), "divine");
                }
            }
        }
        if (weapon->is_lrweapon() &&
            FEATS_D->usable_feat(attacker, "arcane arrows")) {
            string element;
            element = attacker->query_property("arcane arrows");
            switch (element) {
            case "acid":
                tell_room(environment(target), "%^GREEN%^The projectile explodes with ooze of acid all over " + target->QCN + "%^RESET%^", ({ target }));
                tell_object(target, "%^GREEN%^The missile explodes with ooze of acid all over you%^RESET%^");
                break;
            case "cold":
                tell_room(environment(target), "%^BLUE%^The projectile explodes with sharp shards of ice that pierce " + target->QCN + "%^RESET%^", ({ target }));
                tell_object(target, "%^GREEN%^The missile explodes with ooze of acid all over you%^RESET%^");
                break;
            case "sonic":
                tell_room(environment(target), "%^CYAN%^The projectile explodes sonic scream that shatters " + target->QCN + "%^RESET%^", ({ target }));
                tell_object(target, "%^GREEN%^The missile explodes with sonic scream that shatters you%^RESET%^");
                break;
            default:
                tell_room(environment(target), "%^RED%^The projectile explodes and scorches " + target->QCN + "%^RESET%^", ({ target }));
                tell_object(target, "%^GREEN%^The missile explodes and burns you!%^RESET%^");
                element = "fire";
                break;
            }
            //target->cause_typed_damage(target, target->return_target_limb(), roll_dice(attacker->query_character_level(), 8), element);
            //Above damage is way too insane. Tlaloc changed this 4.23.2021....probably is still too insane below
            target->cause_typed_damage(target, target->return_target_limb(), 10 + roll_dice(attacker->query_character_level() / 5, 6), element);
        }
    }

    if (objectp(weapon) && !attacker->query_property("shapeshifted")) {
        if (objectp(target) && (int)weapon->query("PoisonDoses")) {
            POISON_D->is_object_poisoned(weapon, target, "hit", 1);
        }
    }else if (attacker->query_property("natural poisoner")) {
        effect_chance = attacker->query_property("poison chance");
        if (!intp(effect_chance)) {
            effect_chance = 10;
        }
        if (effect_chance > roll_dice(1, 100)) {
            POISON_D->ApplyPoison(target, attacker->query_property("natural poison"), attacker, "injury");
        }
    }

    // magus arcane pool - paladin divine bond
    //weapon enhancements
    weapons = attacker->query_wielded();
    if (sizeof(weapons))
    {
        if (weapons[0] == weapon){ is_main_hand = 1; }
    }
    if (!attacker->query_property("shapeshifted") &&
        objectp(weapon) &&
        is_main_hand &&
        attacker->query_property("weapon enhancement timer")) {

        if (crit_hit) {
            crit_mult = (int)weapon->query_critical_hit_multiplier() - 1;
            if (FEATS_D->has_feat(attacker, "exploit weakness")) {
                crit_mult += 2;
            }
            else if (FEATS_D->has_feat(attacker, "weapon mastery")) {
                crit_mult += 1;
            }
        }
        //it can be optimized to mapping, any help appreciated
        elements = ({ "fire", "cold", "electricity", "sonic", "acid" });
        actions = ({ "a burst", "shards", "tendrils", "explosion", "splatter" });
        bursts = ({ "flames", "ice", "lightning", "sounds", "acid" });
        colors = ({ "fire red", "ice blue", "lightning yellow", "lightning yellow", "acid green" });

        effective_level = attacker->query_prestige_level("magus");
        effective_level += attacker->query_prestige_level("paladin");
        effective_level += (attacker->query_level() - effective_level) / 2;
        enhance_chance = 10 - effective_level / 7;

        for (i = 0; i < sizeof(elements); i++)
        {
            //Chance from 10% to 33% at max for each element, on crit is 100% if burst.
            effect_chance = !random(enhance_chance);
            if ((attacker->query_property(elements[i] + " en_dam") && effect_chance) ||
                (attacker->query_property(elements[i] + " en_dam burst") && crit_hit)) {
                enhance_msg = bursts[i];
                enhance_dmg = roll_dice(1 + effective_level / 10, 6);
                if (crit_hit && attacker->query_property(elements[i] + " en_dam burst")) {
                    enhance_msg = actions[i] + " of " + bursts[i];
                    enhance_dmg += roll_dice(crit_mult * (1 + effective_level / 10), 10);
                }
                tell_object(attacker, CRAYON_D->color_string("You release " + enhance_msg + " at " + target->QCN + "!", colors[i]));
                tell_object(target, CRAYON_D->color_string(attacker->QCN + " releases " + enhance_msg + "  through you!", colors[i]));
                tell_room(environment(attacker), CRAYON_D->color_string(attacker->QCN + " releases " + enhance_msg + " at " + target->QCN + "!", colors[i]), ({ target, attacker }));
                target->cause_typed_damage(target, target->return_target_limb(), enhance_dmg, elements[i]);
            }
        }
        alignments = ({ "alignment 147", "alignment 369", "alignment 123", "alignment 789" });
        enemy_alignments = ({ "369", "147", "789", "123" });
        align_text = ({ "holy wrath", "unholy fury", "righteous justice", "rebellious might" });
        a_colors = ({ "ice blue", "fire red", "lightning yellow", "lightning yellow" });
        target_align = (string)target->query_true_align();
        for (i = 0; i < sizeof(alignments); i++)
        {
            effect_chance = !random(enhance_chance);
            if (attacker->query_property(alignments[i]) &&
                effect_chance &&
                strsrch(enemy_alignments[i], target_align + "") + 1) {
                enhance_msg = align_text[i];
                enhance_dmg = weapon->query_wc() * (1 + effective_level / 10); //scaling as bane
                tell_object(attacker, CRAYON_D->color_string("You unleash your " + enhance_msg + " at " + target->QCN + "!", a_colors[i]));
                tell_object(target, CRAYON_D->color_string(attacker->QCN + " unleashes " + attacker->query_possessive() + " " + enhance_msg + " through you!", a_colors[i]));
                tell_room(environment(attacker), CRAYON_D->color_string(attacker->QCN + " unleashes " + attacker->query_possessive() + " " + enhance_msg + " at " + target->QCN + "!", a_colors[i]), ({ target, attacker }));
                target->cause_typed_damage(target, target->return_target_limb(), enhance_dmg, "divine");
            }
        }
    }

    //Inquisitor Bane Stuff
    if(attacker->query_guild_level("inquisitor") && weapon)
    {
        int glvl, bane_dmg, valid;
        string *ids = target->query_id();
        mixed *bane = attacker->query_property("bane weapon");

        if(sizeof(bane) == 2 && weapon == bane[0])
        {
            foreach(string id in ids)
            {
                if(USER_D->is_valid_enemy(id, bane[1]))
                valid = 1;
            }
        }

        glvl = attacker->query_guild_level("inquisitor");

        //Chance from 10% to 33% at max
        if(valid && !random(10 - glvl / 7))
        {
            //Damage scales from 1dWC + 2 to 6dWC + 2
            bane_dmg = (weapon->query_wc() + 2) * (1 + glvl / 10);

            switch(attacker->query_true_align())
            {
                case 1:
                case 4:
                case 7:
                tell_object(attacker, "%^BOLD%^WHITE%^Your weapon s%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^gs with r%^CYAN%^i%^RESET%^%^CYAN%^g%^BOLD%^%^WHITE%^ht%^CYAN%^e%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^us g%^CYAN%^l%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^ry as it cuts into your foe!%^RESET%^");
                tell_object(target, "%^BOLD%^WHITE%^" + pname + "'s weapon s%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^gs with r%^CYAN%^i%^RESET%^%^CYAN%^g%^BOLD%^%^WHITE%^ht%^CYAN%^e%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^us g%^CYAN%^l%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^ry as it cuts into you!%^RESET%^");
                tell_room(room, "%^BOLD%^WHITE%^" + pname + "'s weapon s%^CYAN%^i%^RESET%^%^CYAN%^n%^BOLD%^%^WHITE%^gs with r%^CYAN%^i%^RESET%^%^CYAN%^g%^BOLD%^%^WHITE%^ht%^CYAN%^e%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^us g%^CYAN%^l%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^ry as it cuts into " + ename + "!%^RESET%^", ({ attacker, target }));
                break;
                case 2:
                case 5:
                case 8:
                tell_object(attacker, "%^BOLD%^CYAN%^Your weapon c%^WHITE%^u%^RESET%^%^CYAN%^t%^BOLD%^s into your foe with t%^WHITE%^i%^RESET%^%^CYAN%^r%^BOLD%^el%^WHITE%^e%^RESET%^%^CYAN%^s%^BOLD%^s v%^WHITE%^i%^RESET%^%^CYAN%^g%^BOLD%^or!%^RESET%^");
                tell_object(target, "%^BOLD%^CYAN%^" + pname + "'s weapon c%^WHITE%^u%^RESET%^%^CYAN%^t%^BOLD%^s into you with t%^WHITE%^i%^RESET%^%^CYAN%^r%^BOLD%^el%^WHITE%^e%^RESET%^%^CYAN%^s%^BOLD%^s v%^WHITE%^i%^RESET%^%^CYAN%^g%^BOLD%^or!%^RESET%^");
                tell_room(room, "%^CYAN%^BOLD%^" + pname + "'s weapon c%^WHITE%^u%^RESET%^%^CYAN%^t%^BOLD%^s into " + ename + " with t%^WHITE%^i%^RESET%^%^CYAN%^r%^BOLD%^el%^WHITE%^e%^RESET%^%^CYAN%^s%^BOLD%^s v%^WHITE%^i%^RESET%^%^CYAN%^g%^BOLD%^or!%^RESET%^", ({ attacker, target }));
                break;
                case 3:
                case 6:
                case 9:
                tell_object(attacker, "%^BOLD%^BLACK%^Your weapon t%^RESET%^%^CYAN%^e%^BOLD%^a%^WHITE%^r%^BLACK%^s into your foe with r%^RESET%^%^CYAN%^e%^BOLD%^l%^WHITE%^e%^BLACK%^nt%^RESET%^%^CYAN%^l%^BOLD%^e%^WHITE%^s%^BLACK%^s h%^RESET%^%^CYAN%^u%^BOLD%^n%^WHITE%^g%^BLACK%^er!%^RESET%^");
                tell_object(target, "%^BLACK%^BOLD%^" + pname + "'s weapon t%^RESET%^%^CYAN%^e%^BOLD%^a%^WHITE%^r%^BLACK%^s into you with r%^RESET%^%^CYAN%^e%^BOLD%^l%^WHITE%^e%^BLACK%^nt%^RESET%^%^CYAN%^l%^BOLD%^e%^WHITE%^s%^BLACK%^s h%^RESET%^%^CYAN%^u%^BOLD%^n%^WHITE%^g%^BLACK%^er!%^RESET%^");
                tell_room(room, "%^BOLD%^BLACK%^" + pname + "'s weapon t%^RESET%^%^CYAN%^e%^BOLD%^a%^WHITE%^r%^BLACK%^s into " + ename + " with r%^RESET%^%^CYAN%^e%^BOLD%^l%^WHITE%^e%^BLACK%^nt%^RESET%^%^CYAN%^l%^BOLD%^e%^WHITE%^s%^BLACK%^s h%^RESET%^%^CYAN%^u%^BOLD%^n%^WHITE%^g%^BLACK%^er!%^RESET%^", ({ attacker, target }));
                break;
                default:
                return 0;
                break;
            }

            target->cause_typed_damage(target, target->return_target_limb(), bane_dmg, "divine");
        }
    }
    //END BANE SECTION
    
    if(!attacker)
        return;
    
    //CLEAVE SECTION
    if(FEATS_D->usable_feat(attacker, "cleave") && objectp(weapon))
    {
        int cleave_dmg, flvl;
        object first;
        
        att = attacker->query_attackers() - ({ target });
        att = shuffle(att);
        
        if(sizeof(att) && BONUS_D->process_hit(attacker, att[0], 0, weapon, 0, 0, 0));
        {
            flvl = attacker->query_player_level() / 2;
            flvl += (FEATS_D->usable_feat(attacker, "great cleave") * 2);
            cleave_dmg = roll_dice(flvl, weapon->query_wc());
            //cleave_dmg = (weapon->query_wc() + 2) * (1 + flvl / 10);
            
            //Cleave happens once per HB unless they have the improved cleave feat
            if(!attacker->query_property("cleaving") || (FEATS_D->usable_feat(attacker, "improved cleave") && attacker->query_property("cleaving") < 5))
            {               
                if(sizeof(att) && objectp(att[0]))
                {
                    //Can only cleave once per round
                    attacker->set_property("cleaving", 1);
                    tell_object(attacker, "%^BOLD%^Your attack cleaves through your opponent and hits " + att[0]->QCN + "!%^RESET%^");
                    tell_room(room, "%^BOLD%^" + attacker->QCN + "'s attack cleaves through and hits " + att[0]->QCN + "!%^RESET%^", ({ attacker }));
                    att[0] && attacker->cause_typed_damage(att[0], att[0]->return_target_limb(), cleave_dmg, weapon->query_damage_type());
                }
            }
            
            //In case a counter attack kills the attacker
            if(!attacker)
                return;
        
            if(FEATS_D->usable_feat(attacker, "cleaving finish") && sizeof(att))
            {
                if(!objectp(target) || target->query_hp() < 1)
                {
                    tell_object(attacker, "%^BOLD%^Your finishing attack cleaves through your opponent and hits " + att[0]->QCN + "!%^RESET%^");
                    tell_room(room, "%^BOLD%^" + attacker->QCN + "'s finishing attack cleaves through and hits " + att[0]->QCN + "!%^RESET%^", ({ attacker }));
                    att[0] && attacker->cause_typed_damage(att[0], att[0]->return_target_limb(), cleave_dmg, weapon->query_damage_type());
                }
            }
        }                  
    }        
    //END CLEAVE SECTION    

    //monster feat stuff
    if (attacker->query("combat_feats_enabled") &&
        !attacker->query_property("using instant feat")) {
        effect_chance = attacker->query_property("feat chance");
        if (!intp(effect_chance)) {
            effect_chance = 15;
        }
        if (effect_chance > roll_dice(1, 100)) {
            MONSTER_FEAT_D->execute_monster_feat(attacker, attacker->return_player_target(100));
        }
    }
    //disease stuff
    /* if (attacker->query_property("infects disease")) { */

    /* } */
    return;
}

//all melee damage calculations should be here now
//condensing the do_hits() function from /std/living/combat.c
//and the damage_done() function

int crit_damage(object attacker, object targ, object weapon, int size, int damage, int cant_shot)
{
    int mult, crit_dam, perc;
    string targRace;
    object* wielded;
    if (damage <= 0) {
        return 0;
    }
    mult = 2;
    if (objectp(weapon) && !attacker->query_property("shapeshifted") && weapon != attacker) {
        if(!cant_shot){ //Venger: swinging a ranged weapon with no ammo has x2 multiplier.
			mult = (int)weapon->query_critical_hit_multiplier();
		}
        if (objectp(targ) &&
            attacker->is_class("warmaster") &&
            FEATS_D->usable_feat(attacker, "skull collector") &&
            attacker->validate_combat_stance("two hander") &&
            targ->query_hp_percent() < roll_dice(3, 6) &&
            targ->query_hp_percent() > 0 &&
            !targ->query_property("no death") &&
            member_array("repose", targ->query_divine_domain()) < 0 &&
            !targ->fort_save(attacker->query_level())
            ) {
            tell_object(targ, "%^BOLD%^%^RED%^" + attacker->QCN + " swings " + attacker->QP + " " + weapon->query_short() + " in a brutal swipe, hitting you in the head!\nEverything goes black...");
            tell_object(attacker, "%^BOLD%^%^RED%^You swing your " + weapon->query_short() + " in a brutal swipe, hitting" + targ->QCN + " in the head with a certainly fatal strike!");
            tell_room(environment(targ), "%^BOLD%^%^RED%^" + attacker->QCN + " swings " + attacker->QP + " " + weapon->query_short() + " in a brutal swipe, hitting " + targ->QCN + " in the head with what must cetainly be a fatal strike!", ({ attacker, targ }));
            targ->set_hp(-100);
        }
    }else {
        // currently all unarmed attacks have x2 multiplier
        if (attacker->is_class("monk")) {
            mult += (int)"/std/class/monk.c"->critical_multiplier(attacker);

            if (objectp(targ) &&
                FEATS_D->usable_feat(attacker, "way of the merciful soul") &&
                targ->query_hp_percent() < roll_dice(6, 6) &&
                targ->query_hp_percent() > 0 &&
                !targ->query_property("no death") &&
                member_array("repose", targ->query_divine_domain()) < 0 &&
                !targ->fort_save(attacker->query_guild_level("monk"))
                ) {
                tell_object(targ, "%^BOLD%^%^BLUE%^" + attacker->QCN + " strikes you swiftly on the forehead and everthing goes black!%^RESET%^");
                tell_object(attacker, "%^BOLD%^%^BLUE%^You strike " + targ->QCN + " precisely on the forehead and release pure ki into " + targ->QP + " mind, granting " + targ->QO + " the mercy of a painless death.");
                tell_room(environment(targ), "" + attacker->QCN + " strikes " + targ->QCN + " swiftly on the head and " + targ->QS + " drops instantly to the ground!", ({ attacker, targ }));
                USER_D->spend_ki(attacker, 3);
                targ->set_hp(-100);
            }
        }
    }

    mult -= 1;
    //Odin's note that we already dealt normal damage and need to reduce multiplier by one

    if (!attacker->query_property("shapeshifted")) {
        if (FEATS_D->usable_feat(attacker, "exploit weakness")) {
            mult += 2;
        }else if (FEATS_D->usable_feat(attacker, "weapon mastery")) {
            mult += 1;
        }
    }
    crit_dam = 0;
    /*
    while (mult > 0) {
        mult--;
        crit_dam += damage;
    }*/
    //Venger: Why dont just multiply?
    crit_dam = mult * damage;

    if (objectp(targ)) {
        targRace = (string)targ->query_race();
        if (CRIT_DAMAGE_MODIFIER[targRace]) {
            crit_dam = crit_dam * CRIT_DAMAGE_MODIFIER[targRace];
        }
    }

    return crit_dam + damage;
}

int unarmed_enchantment(object who)
{
    int mod = 0;
    if (!objectp(who)) {
        return mod;
    }
    if (who->is_class("monk")) {
        mod += (int)"/std/class/monk.c"->effective_enchantment(who);
    }else {
        if (FEATS_D->usable_feat(who, "precise strikes") ||
            who->query_property("shapeshifted")) {
            mod += ((int)who->query_base_character_level() / 8);
        }
    }
    return mod;
}

varargs void calculate_damage(object attacker, object targ, object weapon, string target_thing, int critical_hit)
{
    int attacker_size, damage, mod;
    int res, eff_ench, ench;
    int i, j, mysize, sneak;
    int speed, enchantment, fired = 0, cant_shot=0, bonus_hit_damage = 0;// added for new stamina formula -Ares
    object* armor, shape, ammo, paladin;
    string ammoname;

    if (!objectp(attacker)) {
        return;
    }
    if (!objectp(targ)) {
        return;
    }
    attacker_size = (int)targ->query_size();
    if (objectp(weapon) && weapon != attacker && !attacker->query_property("shapeshifted")) {
        damage = (int)weapon->query_wc();
        if (weapon->is_lrweapon()) {
            ammoname = weapon->query_ammo();
            ammo = present(ammoname, attacker);
            if (FEATS_D->usable_feat(attacker, "point blank shot") && objectp(ammo) && ammo->use_shots()) {
                fired = 1;
                bonus_hit_damage = get_lrdamage(attacker, weapon, targ); //this is necessary so specials that return numbers are not multiplied in a critical hit.
                if (FEATS_D->usable_feat(attacker, "point blank shot")) {
                    damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("dexterity"));
                }
            }else {
				cant_shot = 1; //Venger: it has no ammo.
				tell_object(attacker, "Your " + weapon->query_name() + " has no ammo! You swing your "+ weapon->query_name() +".\n");
				damage = (int)weapon->query_size();
				damage = roll_dice(1, 2 + damage); //Venger: damage based on weapon size.
			}
        }
		if (!fired){
			if(!cant_shot){ //Venger: if not using the weapon as intended then dont use weapon specials.
				bonus_hit_damage += get_damage(attacker, weapon, targ); //this is necessary so specials that return numbers are not multiplied in a critical hit.
			}
            mysize = (int)attacker->query_size();
            if (mysize == 1) {
                mysize++;             //run small creatures as normal size please.
            }
            mysize -= (int)weapon->query_size();
            if (FEATS_D->usable_feat(attacker, "weapon finesse") && ((mysize >= 0) || weapon->query_property("finesse"))) { // if has-feat & weapon is smaller than / same size as user - Saide, November 23rd, 2017 or weapon has the property - Venger dec20
                damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("dexterity"));
            }else {
                damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("strength"));
            }
        }
        if (!targ->query_unconscious() && !targ->query_bound()) {
            enchantment = (int)weapon->query_property("enchantment");
            if (enchantment) {
                damage += enchantment;
            }
        }
    }else if (!weapon || weapon == attacker || attacker->query_property("shapeshifted")) {
        if (attacker->query_unarmed_damage()) {
            damage = get_hand_damage(attacker, (string)attacker->return_target_limb(), damage, targ);
            if (objectp(targ)) {
                if (targ->query_unconscious() || targ->query_bound()) {
                    damage = damage * 2;
                }
            }
        }else {
            if (targ->query_unconscious() || targ->query_bound()) {
                damage = 4;
            }else {
                damage = random(4);
            }
        }

        if (FEATS_D->usable_feat(attacker, "weapon finesse")) {
            damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("dexterity"));
        }else {
            damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("strength"));
        }
        damage += COMBAT_D->unarmed_enchantment(attacker);
    }
    
    targ && paladin = targ->query_property("paladin smite");
    
    if(objectp(paladin))
    {
        
        //Paladin smite target takes additional damage based on CHA mod
        //Smite debuff lasts a few rounds
        if(attacker->query_guild_level("paladin") && paladin == attacker)
            damage += BONUS_D->new_damage_bonus(attacker, attacker->query_stats("charisma"));
        
        //Aura of Fury adds smite bonus of +2 to rest of party for duration
        if(LIVING_D->check_aura(attacker, "fury") == 2)
            damage += 2;
    }
    
    damage = damage_done(attacker, weapon, damage, fired);
    if (!objectp(targ) || !objectp(attacker)) {
        return;
    }

    if (res = targ->query_property("weapon resistance") > 0) {
        if (!weapon || weapon == attacker) {
            eff_ench = (int)attacker->query_property("effective_enchantment");
            eff_ench += COMBAT_D->unarmed_enchantment(attacker);
            if (eff_ench < res) {
                damage = 0;                // no need for these to stack, greatest is sufficient to override.
            }
        }else {
            ench = (int)weapon->query_property("enchantment");
            eff_ench = (int)weapon->query_property("effective_enchantment");
            if ((ench + eff_ench) < res) {
                damage = 0;
            }
        }
    }
    if (objectp(weapon) && !attacker->query_property("shapeshifted")) {
        weapon->reaction_to_hit(targ, damage);
    }

    armor = targ->query_armour(target_thing);
    j = sizeof(armor);
    for (i = 0; i < j; i++) {
        if (targ->query_property("shapeshifted")) {
            continue;
        }
        if (!objectp(armor[i])) {
            continue;
        }
        mod = armor[i]->do_struck(damage, weapon, attacker);
        /**************************************
         Let's review this code in the future.
         Struck function should apply modifiers
         and return total damage at the end.
         -- Tlaloc --
        ***************************************/
        if (mod < 0) {
            damage += mod;
        }
        if (mod >= 0) {
            damage = mod;
        }
        /**************************************/
    }

    if (critical_hit) {
        damage = crit_damage(attacker, targ, weapon, attacker_size, damage, cant_shot);
    }
    
    sneak = 0;

    if(damage)
    {
        if(attacker->is_class("thief"))
        {
            //Sneak attack dice section
            sneak = attacker->query_prestige_level("thief") / 2;
            //Arcane trickster sneak attack progression
            //This makes arcane trickster equal to pure thief....can't be here
            //Needs to be a trade off for having spells.
            sneak += attacker->query_class_level("arcane_trickster") / 3;
    
            //Making this baseline and replacing combat reflexes with something else.
            /*
            if(!FEATS_D->usable_feat(attacker, "combat reflexes"))
                sneak = 0;
            */
    
            if(FEATS_D->usable_feat(targ, "mighty resilience"))
                sneak = 0;
        
            //Armor bond sneak attack resistance
            if(targ->query_property("fortification 75"))
                sneak /= 4;
            else if(targ->query_property("fortification 50"))
                sneak /= 2;
            else if(targ->query_property("fortification 25"))
                sneak = (sneak * 3) / 4;
    
            if(FEATS_D->usable_feat(targ, "undead graft"))
                sneak /= 2;
        
            //Barbarians/Thieves with danger sense gain resistance to sneak attacks
            if(FEATS_D->usable_feat(targ, "danger sense") && targ->query_level() + 4 > attacker->query_level())
                sneak /= 2;
    
            if(attacker->query_blind() || attacker->light_blind())
            {
                if(FEATS_D->usable_feat(attacker, "blindfight"))
                    sneak /= 2;
                else 
                    sneak = 0;
            }
        }
 /*   
        if(sneak)
        {
        
            if(targ->query_paralyzed() ||
            (targ->query_blind() && !FEATS_D->usable_feat(targ, "blindfight")) ||
            targ->query_current_attacker() != attacker)
            {              
                tell_room(environment(attacker), "%^RED%^BOLD%^SNEAK ATTACK!%^RESET%^");
                damage += roll_dice(sneak, 6);
            }
            else
                sneak = 0;
        }
*/
    }
        
    //target is blind, bound or paralyzed or is attacking another target
    if(sneak && targ->is_vulnerable_to(attacker))
        damage += roll_dice(sneak, 6);
    else
        sneak = 0;
        
    //Brutalize wounds causes victim to take extra damage from physical attacks.
    bonus_hit_damage += this_object()->query_property("brutalized");

    damage += bonus_hit_damage;
    
    new_struck(damage, weapon, attacker, target_thing, targ, fired, ammoname, critical_hit, cant_shot, sneak);

    if(!targ || !attacker)
        return;
    
    if (!objectp(weapon) || attacker->query_property("shapeshifted")) {
        attacker->increment_stamina(1);
    }else {
        speed = (int)weapon->query_weapon_speed();
        enchantment = (int)weapon->query_property("enchantment");

        i = speed - enchantment;

        if (i < 1) {
            i = 1;
        }
        if (i > 5) {
            i = 5;
        }
        attacker->increment_stamina(i);
    }
    check_extra_abilities(attacker, targ, weapon, critical_hit);

    // added only 1/3 chance to decay weapon on hit; weapons degrade super fast. N, 4/13.
    if ((damage > 0) && (weapon && !attacker->query_property("shapeshifted")) && !random(3)) {
        weapon->decay();
    }
    return;
}

int damage_done(object attacker, object weap, int damage, int isranged)
{
    object* wielded;
    int prof;

    if (!objectp(attacker)) {
        return damage;
    }
    if (!userp(attacker)) {
        return damage;
    }
    if (!objectp(weap)) {
        return damage;
    }
    if (!weap->query_prof_type()) {
        return damage;
    }
    switch (weap->query_weapon_prof()) {
    case "simple":  if (FEATS_D->usable_feat(attacker, "simple weapon proficiency")) {
            prof = 100;
    }
        break;

    case "martial": if (FEATS_D->usable_feat(attacker, "martial weapon proficiency")) {
            prof = 100;
    }
        break;

    case "exotic":  if (FEATS_D->usable_feat(attacker, "exotic weapon proficiency")) {
            prof = 100;
    }
        break;

    default: prof = 30; break;
    }

    if (avatarp(attacker)) {
        prof = 100;
    }

    if (pointerp(wielded = (object*)attacker->query_wielded()) && !attacker->query_property("shapeshifted")) {
        if (isranged) {
            if (FEATS_D->usable_feat(attacker, "deadeye")) {
                prof = to_int(prof * 1.30);
            }
        }else if (attacker->validate_combat_stance("two hander")) {
            if (FEATS_D->usable_feat(attacker, "strength of arm")) {
                prof = to_int(prof * 1.30);
            }
        }else if (attacker->validate_combat_stance("weapon and shield")) {
            if (FEATS_D->usable_feat(attacker, "counter") && (int)attacker->query_shieldMiss()) {
                prof = to_int(prof * 1.30);
            }
        }else if (attacker->validate_combat_stance("one hander")) {
            if (FEATS_D->usable_feat(attacker, "opportunity strikes")) {
                prof = to_int(prof * 1.30);
            }
            if (FEATS_D->usable_feat(attacker, "artful precision")) {
                prof = to_int(prof * 1.20);
            }
        }
    }

    if (prof == 0) {
        return 0;
    }
    if (prof < 0) {
        damage = absolute_value((damage * prof) / 100 + 1);
        attacker->cause_typed_damage(attacker, "torso", damage, weap->query_damage_type());
        tell_object(attacker, "You hurt yourself with your weapon because of your inexperience.");
        tell_room(environment(attacker), attacker->QCN + " hurts " + attacker->QO + "self with " + attacker->QP + " weapon.", attacker);
        return 0;
    }else {
        damage = (damage * prof) / 100;
        if(counter_damage)
        {
            damage += counter_damage;
            counter_damage = 0;
        }
        return damage;
    }
}

/*The following two functions were moved from combat.c - in order to
   attempt to have everything related to damage calculations in combat_d.c - Saide - September 2016
 */
varargs int get_damage(object attacker, object weap, object targ)
{
    function f;
    string hold;
    int damage;
    if (!objectp(weap)) {
        return damage;
    }
    if (!(hold = weap->query_hit()) || WORLD_EVENTS_D->stacking_bonus_active(attacker, -1)) {
        return damage;
    }
    if (!objectp(attacker)) {
        return damage;
    }
    if (!weap->query_property("fhit")) {
        message("my_action", hold, attacker);
    }else {
        if (!objectp(targ)) {
            targ = (object)attacker->query_current_attacker();
        }
        damage += call_other(weap, hold, targ);
    }
    return damage;
}

varargs int get_lrdamage(object attacker, object weap, object targ)
{
    function f;
    string hold;
    int damage;
    if (!objectp(weap)) {
        return damage;
    }
    if (!(hold = weap->query_lrhit()) || WORLD_EVENTS_D->stacking_bonus_active(attacker, -1)) {
        return damage;
    }
    if (!objectp(attacker)) {
        return damage;
    }
    if (!weap->query_property("flrhit")) {
        message("my_action", hold, attacker);
    }else {
        if (!objectp(targ)) {
            targ = (object)attacker->query_current_attacker();
        }
        damage += call_other(weap, hold, targ);
    }
    return damage;
}

//END

//moved here from /std/weaponless_users.c - Saide, September 2016
int get_hand_damage(object attacker, string limb1, int damage, object attacked)
{
    string* attack_limbs = ({});
    mapping attack_funcs = ([]);

    if (!objectp(attacker)) {
        return 0;
    }

    attack_limbs = attacker->return_attack_limbs();
    attack_funcs = attacker->return_attack_funcs();

    if (!stringp(limb1) || (limb1 == "") || (limb1 == " ") || !sizeof(attack_limbs) || member_array(limb1, attack_limbs) == -1) {
        if (!sizeof(attack_limbs)) {
            return (damage + (int)attacker->query_unarmed_damage());
        }
        limb1 = attack_limbs[random(sizeof(attack_limbs))];
    }

    if (!attack_funcs || attack_funcs == ([]) || WORLD_EVENTS_D->stacking_bonus_active(attacker, -1)) {
        return (damage + (int)attacker->query_unarmed_damage());
    }

    if (!attack_funcs[limb1]) {
        return (damage + (int)attacker->query_unarmed_damage());
    }

    if (stringp(attack_funcs[limb1])) {
        tell_room(environment(attacker), attack_funcs[limb1], attacker);
        return (damage + (int)attacker->query_unarmed_damage());
    }

    if (functionp(attack_funcs[limb1]) && attacker->query_property("shapeshifted")) {
        damage += (int)attacker->query_unarmed_damage();
        seteuid(UID_SYSTEM);
        damage += call_other((object)attacker->query_property("shapeshifted"), (*attack_funcs[limb1])(1), attacker, attacked);
        seteuid(geteuid());
        return damage;
    }

    if (functionp(attack_funcs[limb1])) {
        damage += call_other(attacker, (*attack_funcs[limb1])(1), attacked);
        return damage;
    }
    return (damage + (int)attacker->query_unarmed_damage());
}

void send_messages(object attacker, int magic, object weapon, string what, int x, object victim, int fired, string ammo, int critical_message, int cant_shot, int sneak)
{
    string your_name, my_name, me, you, others, used, type, * verb, * adverb, * attack_limbs, * limbs;
    int i, verbose, num;
    object shape;

    if (!objectp(attacker) || !objectp(victim)) {
        return;
    }

    your_name = (string)victim->QCN;
    my_name = (string)attacker->QCN;
    verbose = 0;

    if (interactive(attacker)) {
        verbose = attacker->query_verbose_combat();
    }else if (interactive(victim)) {
        verbose = victim->query_verbose_combat();
    }


    if (verbose) {
        if (magic) {
            type = "magic";
        }
        if (fired) {
            type = "ranged";
        }else if (weapon) {
			if(cant_shot){ //Venger: swinging a ranged weapon with no ammo is used as a club.
				type = "bludgeon";
			}else{
				type = (string)weapon->query_type();
			}
        }else {
            type = "melee";
        }
        if (!type) {
            type = "bludgeon";
        }

        if (objectp(shape = attacker->query_property("shapeshifted"))) {
            type = shape->get_new_damage_type();
        }

        i = x / 2;
        if (i < 0) {
            i = 0;
        }
        if (i > 11) {
            i = 11;
        }

        if (magic) {
            used = "magic";
        }else if (fired) {
            used = ammo;
        }else if (weapon && !attacker->query_property("shapeshifted") && weapon != attacker) {
            used = (string)weapon->query_short();
        }else {
            if (attack_limbs = (string*)attacker->query_attack_limbs()) {
                used = attack_limbs[random(sizeof(attack_limbs))];
            }else {
                limbs = (string*)attacker->query_limbs();
                limbs = limbs - BAD_LIMBS;
                if (!sizeof(limbs)) {
                    used = "body";
                }else {
                    if (!used) {
                        used = limbs[random(sizeof(limbs))];
                        if (!used) {
                            used = "body";
                        }
                    }
                }
            }
        }
        if (x < 1) {
            me = "You hit " + your_name + " ineffectively in the " + what + ".";
            you = my_name + " hits you ineffectively in the " + what + ".";
            others = my_name + " hits " + your_name + " ineffectively in the " + what + ".";
        }else {
            if (used == "head") {
                if (x < 5) {
                    me = "You bonk " + your_name + " viciously in the head.";
                    you = my_name + " bonks you viciously in the head.";
                    others = my_name + " bonks " + your_name + " viciously in the head.";
                }else {
                    me = "You headbutt " + your_name + " furiously.";
                    you = my_name + " headbutts you furiously.";
                    others = my_name + " headbutts " + your_name + " furiously.";
                }
            }else {
                if (type == "slashing") {
                    verb = ({ "tap", "tickle", "sting", "slash", "cut", "slice", "slice", "shear", "strike", "mutilate", "dismember", "maim" });
                    adverb = ({ 0, 0, "sharply", 0, 0, 0, "horribly", "to pieces", "letting blood", 0, 0, "utterly" });
                }else if (type == "piercing" || type == "arrow" || type == "ranged") {
                    verb = ({ "tap", "poke", "sting", "pierce", "puncture", "penetrate", "perforate", "shear", "impale", "mutilate", "dismember", "maim" });
                    adverb = ({ 0, 0, "sharply", 0, 0, 0, "sharply", "to pieces", "letting blood", 0, 0, "utterly" });
                }else {
                    verb = ({ "tap", "hit", "whack", "bash", "strike", "strike", "send", "knock", "slam", "blast", "destroy", "maim" });
                    adverb = ({ "innocently", "lightly", "strongly", 0, "badly", 0, "a bone crushing blow", 0, "mercilessly", "powerfully", "utterly", "utterly" });
                }

                me = sprintf("You %s %s%sin the %s with your %s.", verb[i], your_name, (adverb[i] ? " " + adverb[i] + " " : " "), what, used);
                you = sprintf("%s %ss you%sin the %s with %s %s.", my_name, verb[i], (adverb[i] ? " " + adverb[i] + " " : " "), what, (string)attacker->QP, used);
                others = sprintf("%s %ss %s%sin the %s with %s %s.", my_name, verb[i], your_name, (adverb[i] ? " " + adverb[i] + " " : " "), what, (string)attacker->QP, used);
            }


            if (critical_message && x > 0) {
                switch (type) {
                case "slashing":
                    me = "%^RED%^You land a %^BOLD%^vicious %^RESET%^%^RED%^s%^BOLD%^l%^RESET%^%^RED%^a%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g %^RESET%^%^RED%^blow with %^BOLD%^%^BLACK%^" + used + " %^RESET%^%^RED%^and %^BOLD%^tear %^RESET%^%^RED%^your weapon free of %^BOLD%^%^BLACK%^" + your_name + "%^RESET%^%^RED%^!%^RESET%^";
                    you = "%^BOLD%^%^RED%^" + my_name + " %^RESET%^%^RED%^strikes you with a %^BOLD%^vicious %^RESET%^%^RED%^s%^BOLD%^l%^RESET%^%^RED%^a%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g %^RESET%^%^RED%^blow  with %^BOLD%^%^BLACK%^" + used + " %^RESET%^%^RED%^and tears %^BOLD%^%^BLACK%^" + attacker->QP + " %^RESET%^%^RED%^weapon free from you!%^WHITE%^";
                    others = "%^BOLD%^%^RED%^" + my_name + " %^RESET%^%^RED%^strikes %^BOLD%^" + your_name + " %^RESET%^%^RED%^with a %^BOLD%^vicious %^RESET%^%^RED%^s%^BOLD%^l%^RESET%^%^RED%^a%^BOLD%^s%^RESET%^%^RED%^h%^BOLD%^i%^RESET%^%^RED%^n%^BOLD%^g %^RESET%^%^RED%^blow with %^BOLD%^%^BLACK%^" + attacker->QP + " " + used + " and %^RESET%^%^RED%^tears %^BOLD%^%^BLACK%^" + attacker->QP + " %^RESET%^%^RED%^blade free from %^BOLD%^%^BLACK%^" + your_name + "%^RESET%^%^RED%^!%^WHITE%^";
                    break;

                case "piercing":
                case "arrow":
                case "ranged":
                    me = "%^CYAN%^You p%^BOLD%^%^i%^RESET%^%^CYAN%^erce through %^BOLD%^" + your_name + "'s%^RESET%^%^CYAN%^ defenses and drive your " + used + " into a %^BOLD%^vital%^RESET%^%^CYAN%^ spot!%^RESET%^";
                    you = "%^CYAN%^%^BOLD%^" + my_name + "%^RESET%^%^CYAN%^ pierces through your defences and drives %^BOLD%^" + attacker->QP + " " + used + "%^RESET%^ into a v%^BOLD%^i%^RESET%^%^CYAN%^tal spot!%^RESET%^";
                    others = "%^CYAN%^%^BOLD%^" + my_name + " p%^BOLD%^i%^RESET%^%^CYAN%^erces through %^BOLD%^" + your_name + "'s%^RESET%^ defenses and drives %^BOLD%^" + attacker->QP + " " + used + "%^RESET%^%^CYAN%^ into a v%^BOLD%^i%^RESET%^%^CYAN%^tal spot!%^RESET%^";
                    break;

                default:
                    me = "%^GREEN%^You unleash a %^BOLD%^crushing%^RESET%^%^GREEN%^ blow on %^BOLD%^" + your_name + "%^RESET%^%^GREEN%^ with your %^BOLD%^" + used + "%^RESET%^%^GREEN%^ with %^BOLD%^devastating%^RESET%^%^GREEN%^ force.";
                    you = "%^GREEN%^%^BOLD%^" + my_name + "%^RESET%^%^GREEN%^ staggers you with a %^BOLD%^crushing%^RESET%^%^GREEN%^ blow from " + attacker->QP + " %^BOLD%^" + used + "%^RESET%^%^GREEN%^ with %^BOLD%^devastating%^RESET%^%^GREEN%^ force.";
                    others = "%^GREEN%^%^BOLD%^" + my_name + "%^RESET%^%^GREEN%^ staggers %^BOLD%^" + your_name + "%^RESET%^%^GREEN%^ with a %^BOLD%^crushing%^RESET%^%^GREEN%^ blow from " + attacker->QP + " %^BOLD%^" + used + "%^RESET%^%^GREEN%^ with %^BOLD%^devastating%^RESET%^%^GREEN%^ force.";
                    break;
                }

                if (!objectp(weapon)) {
                    me = "%^BOLD%^%^BLACK%^You deliver " + your_name + " a %^BOLD%^%^WHITE%^punishing %^BOLD%^%^BLACK%^blow with
your " + used + "!%^RESET%^";

                    you = "%^BOLD%^%^RED%^" + my_name + " %^BOLD%^%^BLACK%^hits you with a %^BOLD%^%^WHITE%^punishing
%^BOLD%^%^BLACK%^blow from " + attacker->QP + " " + used + "!%^RESET%^";

                    others = "%^BOLD%^%^RED%^" + my_name + " %^BOLD%^%^BLACK%^delivers a %^BOLD%^%^WHITE%^punishing
%^BOLD%^%^BLACK%^blow to "
                             "%^BOLD%^%^RED%^" + your_name + " with " + attacker->QP + " " + used + "!%^RESET%^";
                }
            }
        }
    }else {
        if (x < 1) {
            me = "You hit " + your_name + " ineffectively.";
            you = my_name + " hits you ineffectively.";
            others = my_name + " hits " + your_name + " ineffectively.";
        }else {
            me = "You hit " + your_name + ".";
            you = my_name + " hits you.";
            others = my_name + " hits " + your_name + ".";
        }
    }


    if (critical_message && x > 0) {
        //me = "%^BOLD%^%^WHITE%^" + critical_roll + ": %^BOLD%^%^RED%^(Critical) %^RESET%^" + me; debug version
        me = "%^BOLD%^%^RED%^(Critical) %^RESET%^" + me;
        you = "%^BOLD%^%^RED%^(Critical) %^RESET%^" + you;
        others = "%^BOLD%^%^RED%^(Critical) %^RESET%^" + others;
        attacker->reset_critical();
    }
    
    if(sneak && x > 0)
    {
        me = me + "%^BOLD%^RED%^[%^BLACK%^Sneak%^RED%^]%^RESET%^";
        you = you + "%^BOLD%^RED%^[%^BLACK%^Sneak%^RED%^]%^RESET%^";
        others = others + "%^BOLD%^RED%^[%^BLACK%^Sneak%^RED%^]%^RESET%^";
    }
    
    if(victim->query_property("paladin smite") == attacker && x > 0)
    {
        if(attacker->query_true_align() == 3 ||
           attacker->query_true_align() == 6 ||
           attacker->query_true_align() == 9)
        {
            me = me + "%^BOLD%^CYAN%^[%^BLACK%^Smite%^CYAN%^]%^RESET%^";
            you = you + "%^BOLD%^CYAN%^[%^BLACK%^Smite%^CYAN%^]%^RESET%^";
            others = others + "%^BOLD%^CYAN%^[%^BLACK%^Smite%^CYAN%^]%^RESET%^";
        }
        else
        {
            me = me + "%^BOLD%^CYAN%^[%^WHITE%^Smite%^CYAN%^]%^RESET%^";
            you = you + "%^BOLD%^CYAN%^[%^WHITE%^Smite%^CYAN%^]%^RESET%^";
            others = others + "%^BOLD%^CYAN%^[%^WHITE%^Smite%^CYAN%^]%^RESET%^";
        }
    }

    if (objectp(attacker)) {
        tell_object(attacker, me);
        if (objectp(environment(attacker))) {
            tell_room(environment(attacker), others, ({ attacker, victim }));
        }
    }
    if (objectp(victim)) {
        tell_object(victim, you);
    }
}

void new_struck(int damage, object weapon, object attacker, string limb, object victim, int fired, string ammo, int critical_hit, int cant_shot, int sneak)
{
    string damage_type, tmp, type;
    object shape;
    int damage_num, dam;

    // putting this here so it already passes the various checks to make sure the weapon has hit -Ares
    if (!objectp(attacker)) {
        return;
    }
    if (!objectp(victim)) {
        return;
    }
    victim->set_property("beingDamagedBy", attacker);
    if (objectp(weapon) && weapon->query_property("oiled")) {
        tmp = (string)weapon->query_property("oiled");
        if (strsrch(tmp, "damage bonus") != -1) {
            if (sscanf(tmp, "damage bonus %s %d", type, dam) == 2) {
                if (objectp(victim)) {
                    victim->cause_typed_damage(victim, limb, dam, type);
                }
            }
        }
    }
//temp_oiled can be used by spells and abilities without overriding permanent oils
    if (objectp(weapon) && weapon->query_property("temp_oiled")) {
        tmp = (string)weapon->query_property("temp_oiled");
        if (strsrch(tmp, "damage bonus") != -1) {
            if (sscanf(tmp, "damage bonus %s %d", type, dam) == 2) {
                if (objectp(victim)) {
                    victim->cause_typed_damage(victim, limb, dam, type);
                }
            }
        }
    }

    if (objectp(weapon) && !attacker->query_property("shapeshifted") && attacker != weapon) {
		if(cant_shot){ //Venger: swinging a ranged weapon with no ammo is used as a club.
			damage_type = "bludgeoning";
		}else{
			damage_type = (string)weapon->query_damage_type();
		}
    }else if (objectp(attacker)) {
        damage_type = (string)attacker->query_base_damage_type();
    }

    if (!damage_type || damage_type == "untyped") {
        damage_type = "bludgeoning";
    }

    if (objectp(shape = attacker->query_property("shapeshifted"))) {
        damage_type = (string)shape->get_new_damage_type();
    }

    if (damage > 0) {
        damage_num = (int)victim->cause_typed_damage(victim, limb, damage, damage_type);
    }else {
        damage_num = 0;
    }

    if (objectp(attacker)) {
        send_messages(attacker, 0, weapon, limb, damage_num, victim, fired, ammo, critical_hit, cant_shot, sneak);
    }
    if (objectp(victim)) {
        victim->remove_property("beingDamagedBy");
    }
}

void do_fumble(object attacker, object weapon)
{
    int num;
    object* attackers, victim;
    if (!objectp(attacker)) {
        return;
    }
    if (!weapon || !objectp(weapon)) {
        tell_object(attacker, "You swing wildly at your target!");
        return;
    }

    num = random(20) + 1;
    attackers = attacker->query_attackers();
    if (!sizeof(attackers)) {
        tell_object(attacker, "You swing wildly at your target!");
        return;
    }
    victim = attackers[0];
    switch (num) {
    case 1..9:
        break;

    case 10:
        if (!weapon) {
            miss(attacker, (int)attacker->query_casting(), victim, 0, (string)victim->return_target_limb());
        }else {
            miss(attacker, 0, victim, (string)weapon->query_type(), (string)victim->return_target_limb());
        }
        break;

    case 11..13:
        break;

    case 14:
        if (objectp(victim)) {
            calculate_damage(attacker, victim, weapon, (string)victim->return_target_limb());
        }
        break;

    case 17:
        break;

    case 18:
        if (objectp(weapon)) {
            tell_object(attacker, "%^GREEN%^You fumble your weapon badly, dropping it!");
            tell_room(environment(attacker), "%^GREEN%^You see " + attacker->QCN + " fumble " + attacker->QP + " weapon.", attacker);
            attacker->force_me("drop " + ((string*)weapon->query_id())[0]);
        }else {
            tell_object(attacker, "%^GREEN%^You stumble as you wing at your opponent");
            tell_room(environment(attacker), "%^GREEN%^You see " + attacker->QCN + " stumble.", attacker);
            attacker->set_paralyzed(10, "You are recovering from having stumbled.");
        }
        break;

    case 19:
        break;

    default:
        if (objectp(weapon)) {
            calculate_damage(attacker, attacker, weapon, (string)attacker->return_target_limb());
        }
        break;
    }
    return;
}

void miss(object attacker, int magic, object target, string type, string target_thing)
{
    int verbose;

    if (!objectp(attacker)) {
        return;
    }
    if (!objectp(environment(attacker))) {
        return;
    }

    if (magic) {
        return;
    }
    if (interactive(attacker)) {
        verbose = attacker->query_verbose_combat();
    }

    if (objectp(target)) {
        if (interactive(target)) {
            verbose = target->query_verbose_combat();
        }

        if (verbose) {
            tell_object(attacker, "%^RESET%^%^YELLOW%^You miss your attack on " + target->QCN + "%^RESET%^");
            tell_room(environment(attacker), "" + attacker->QCN + " misses " + attacker->QP + " attack on " + target->QCN + "!", ({ attacker, target }));
            tell_object(target, "" + attacker->QCN + " missed you!");
        }else {
            tell_object(attacker, "%^YELLOW%^You miss.%^RESET%^");
            tell_object(target, "" + attacker->QCN + " missed you.");
            tell_room(environment(attacker), "" + attacker->QCN + " misses " + target->QCN + "", ({ target, attacker }));
        }
        return;
    }

    tell_object(attacker, "%^YELLOW%^You miss.%^RESET%^");
    tell_room(environment(attacker), "" + attacker->QCN + " misses " + attacker->QP + " target.", attacker);
    return;
}

int is_ok_armour(object who, string myclass)
{
    int i, j;
    object* armours;
    int isnotok = 0;
    if (!objectp(who)) {
        return 0;
    }
    armours = (object*)who->all_armour();
    j = sizeof(armours);
    switch (myclass) {
    case "thief":
        for (i = 0; i < j; i++) {
            if (!objectp(armours[i])) {
                continue;
            }
            if (member_array((string)armours[i]->query_type(), ({ "sheath", "leather", "bracer", "ring", "clothing", "thiefshield", "jewelry" })) == -1 && !armours[i]->query_property("magicarmor")) {
                isnotok = 1;
                break;
            }
        }
        break;

    /*Added barb type for barbarian unarmored defense feat - Octothorpe 1/14/16*/
    case "barb":
    case "barbarian":
        for (i = 0; i < j; i++) {
            if (!objectp(armours[i])) {
                continue;
            }
            if (member_array((string)armours[i]->query_type(), ({ "sheath", "bracer", "ring", "clothing", "thiefshield", "shield", "jewelry" })) == -1 && !armours[i]->query_property("magicarmor")) {
                isnotok = 1;
                break;
            }
        }
        break;

    case "mage":
        for (i = 0; i < j; i++) {
            if (!objectp(armours[i])) {
                continue;
            }
            if (member_array((string)armours[i]->query_type(), ({ "sheath", "ring", "bracer", "clothing", "jewelry" })) == -1 && !armours[i]->query_property("magicarmor")) {
                isnotok = 1;
                break;
            }
        }
        break;

    case "bard":
        for (i = 0; i < j; i++) {
            if (!objectp(armours[i])) {
                continue;
            }
            if (member_array((string)armours[i]->query_type(), ({ "sheath", "chain", "bracer", "leather", "ring", "clothing", "thiefshield", "jewelry" })) == -1 && !armours[i]->query_property("magicarmor")) {
                isnotok = 1;
                break;
            }
        }
        break;
    }
    if (isnotok) {
        return 0;
    }
    return 1;
}

int is_ok_weapon(object who, string myclass)
{
    if (!objectp(who)) {
        return 0;
    }
    return 1;
}

int calculate_unarmed_damage(object attacker)
{
    int amt;
    if (!objectp(attacker)) {
        return 0;
    }
    if (attacker->is_class("monk") && file_exists("/std/class/monk.c")) {
        return (int)"/std/class/monk.c"->unarmed_damage(attacker);
    }else if (FEATS_D->usable_feat(attacker, "unarmed combat")) {
        switch ((int)attacker->query_highest_level()) {
        case 0..20:
            return roll_dice(1, 6);

            break;

        case 21..30:
            return roll_dice(1, 8);

            break;

        case 31..40:
            return roll_dice(1, 10);

            break;

        case 41..50:
            return roll_dice(1, 12);

            break;
        }
    }
    return roll_dice(1, 4);
}

//Following functions were moved into here from /std/living/combat.c in January 2017 - Saide
void init_combat_vars(object who)
{
    mapping combat_vars;
    int flag;
    if (!objectp(who)) {
        return;
    }
    combat_vars = who->query_combat_vars();
    if (!combat_vars || (combat_vars == ([])) || !combat_vars["RNEW"]) {
        combat_vars = (["gagged" : 0, "bound" : 0, "tripped" : 0, "unconscious" : 0, "asleep" : 0, "blindfolded" : 0, "any attack" : 0,
                        "paralyzed" : 0, "toAttack" : 0, "wimpy" : 0, "any attack" : 0, "react" : 0, "funcCast" : 0, "castFunc" : 0,
                        "swarm" : 0, "RNEW" : 1]);
        flag = 1;
    }
    if (flag) {
        who->set_combat_vars(combat_vars);
    }
    return;
}

void init_combat_messages(object who)
{
    mapping combat_messages;
    int flag;
    if (!objectp(who)) {
        return;
    }
    combat_messages = who->query_combat_messages();
    if (!combat_messages || (combat_messages == ([])) || !combat_messages["NEW"]) {
        combat_messages = (["gagged" : 0, "bound" : 0, "tripped" : 0, "unconscious" : 0, "asleep" : 0, "paralyzed" : 0,
                            "blinded" : 0, "blindfolded" : 0, "NEW" : 1]);
        flag = 1;
    }
    if (flag) {
        who->set_combat_messages(combat_messages);
    }
    return;
}

void init_combat_counters(object who)
{
    mapping combat_counters;
    int flag;
    if (!objectp(who)) {
        return;
    }
    combat_counters = who->query_combat_counters();
    if (!combat_counters || (combat_counters == ([])) || !combat_counters["NEW"]) {
        combat_counters = (["gagged" : 0, "bound" : 0, "tripped" : 0, "unconscious" : 0, "asleep" : 0, "blindfolded" : 0,
                            "blinded" : 0, "healing" : 0, "block_attack" : 0, "NEW" : 1]);
        flag = 1;
    }
    if (!intp(combat_counters["gagged"])) {
        combat_counters["gagged"] = 0; flag = 1;
    }
    if (!intp(combat_counters["bound"])) {
        combat_counters["bound"] = 0; flag = 1;
    }
    if (!intp(combat_counters["tripped"])) {
        combat_counters["tripped"] = 0; flag = 1;
    }
    if (!intp(combat_counters["asleep"])) {
        combat_counters["asleep"] = 0; flag = 1;
    }
    if (!intp(combat_counters["blindfolded"])) {
        combat_counters["blindfolded"] = 0; flag = 1;
    }
    if (!intp(combat_counters["blinded"])) {
        combat_counters["blinded"] = 0; flag = 1;
    }
    if (!intp(combat_counters["unconscious"])) {
        combat_counters["unconscious"] = 0; flag = 1;
    }
    if (!intp(combat_counters["healing"])) {
        combat_counters["healing"] = 0; flag = 1;
    }
    if (!intp(combat_counters["block_attack"])) {
        combat_counters["block_attack"] = 0; flag = 1;
    }
    if (!intp(combat_counters["tripped counter"])) {
        combat_counters["tripped counter"] = 0; flag = 1;
    }
    if (!intp(combat_counters["paralyzed"])) {
        combat_counters["paralyzed"] = 0; flag = 1;
    }
    if (flag) {
        who->set_combat_counters(combat_counters);
    }
}

void init_combat_static_vars(object who)
{
    mapping combat_static_vars;
    int flag;
    if (!objectp(who)) {
        return;
    }
    combat_static_vars = who->query_combat_static_vars();
    if (!combat_static_vars || (combat_static_vars == ([]))) {
        combat_static_vars = (["gagged" : 0, "bound" : 0, "tripped" : 0, "unconscious" : 0, "asleep" : 0, "blindfolded" : 0,
                               "blinded" : 0, "critical hit" : 0, "attack count" : 0, "attack loop" : 0, "attacking" : 0,
                               "hunting" : 0, "dead" : 0, "funcing" : 0, "attack" : 0, "toattack" : 0, "lastHand" : 0,
                               "critical message" : 0, "casting" : 0]);
        flag = 1;
    }
    if (flag) {
        who->set_combat_static_vars(combat_static_vars);
    }
    return;
}

void init_combat_arrays(object who)
{
    mapping combat_arrays;
    int flag;
    if (!objectp(who)) {
        return;
    }
    combat_arrays = who->query_combat_arrays();
    if (!mapp(combat_arrays) || combat_arrays == ([])) {
        combat_arrays = (["attackers" : ({}), "hunters" : ({}), "atnames" : ({}), ]);
        flag = 1;
    }
    if (flag) {
        who->set_combat_arrays(combat_arrays);
    }
    return;
}

int ok_combat_vars(object who)
{
    if (!objectp(who)) {
        return 0;
    }
    init_combat_vars(who);
    init_combat_messages(who);
    init_combat_counters(who);
    init_combat_static_vars(who);
    init_combat_arrays(who);
    return 1;
}

void send_paralyzed_message(string type, object who)
{
    if (!objectp(who)) {
        return;
    }
    if (who->query_deaths_door()) {
        message(type, DEATHS_DOOR_MESSAGE, who);
        return;
    }
    if (who->query_asleep()) {
        message(type, who->query_asleep_message(), who);
        return;
    }
    if (who->query_unconscious()) {
        message(type, who->query_unconscious_message(), who);
        return;
    }
    if (who->query_paralyzed()) {
        message(type, who->query_combat_mapps("messages", "paralyzed"), who);
        return;
    }
    if (who->query_bound()) {
        message(type, who->query_bound_message(), who);
        return;
    }
    if (who->query_tripped()) {
        message(type, who->query_tripped_message(), who);
        return;
    }
}

void iterate_combat(object who)
{
    mapping combat_static_vars, combat_counters, combat_vars, combat_messages;
    object EWHO;
    int vars, counters, static_vars;
    if (!objectp(who)) {
        return;
    }
    EWHO = environment(who);
    //if (!who->ok_combat_vars()) who->initialize_combat_vars(); // there's a recursion error, not sure if it's caused here or not
    who->ok_combat_vars();
    combat_static_vars = who->query_combat_static_vars();
    combat_vars = who->query_combat_vars();
    combat_messages = who->query_combat_messages();
    combat_counters = who->query_combat_counters();

    if (combat_static_vars["blinded"]) {
        if (combat_counters["blinded"] > 7) {
            combat_static_vars["blinded"]--;
            static_vars = 1;
            combat_counters["blinded"] = 0;
            if (!who->query_blind()) {
                message("combat", "%^BOLD%^%^BLUE%^You can see again", who);
            }
        }
        combat_counters["blinded"]++;
        counters = 1;
    }

    if (combat_vars["blindfolded"]) {
        if (combat_counters["blindfolded"] > (25 - (int)who->query_stats("dexterity"))) {
            vars = 1;
            combat_vars["blindfolded"]--;
            combat_counters["blindfolded"] = 0;
            if (!who->query_blind()) {
                message("combat", "%^BOLD%^%^BLUE%^You can see again", who);
            }
        }
        combat_counters["blindfolded"]++;
        counters = 1;
    }

    if (combat_vars["gagged"]) {
        if (combat_counters["gagged"] > (25 - (int)who->query_stats("dexterity"))) {
            vars = 1;
            combat_vars["gagged"]--;
            combat_counters["gagged"] = 0;
            if (!combat_vars["gagged"]) {
                message("combat", "%^BOLD%^%^BLUE%^You have struggled your gag off..", who);
                if (!who->query_invis() && objectp(environment(who))) {
                    tell_room(environment(who), "%^GREEN%^" + who->QCN + " spits out " + who->QP + " gag.%^RESET%^", who);
                }
            }
        }
        combat_counters["gagged"]++;
        counters = 1;
    }

    if (combat_vars["bound"]) {
        if (combat_counters["bound"] > (25 - (int)who->query_stats("strength"))) {
            vars = 1;
            combat_vars["bound"]--;
            combat_counters["bound"] = 0;
            if (!combat_vars["bound"]) {
                message("combat", "%^BOLD%^%^BLUE%^You have broken your bonds.", who);
                if (!who->query_invis() && !random(3) && objectp(environment(who))) {
                    tell_room(environment(who), "%^GREEN%^" + who->QCN + " breaks free of " + who->QP + " bonds.%^RESET%^", who);
                }
            }
        }
        combat_counters["bound"]++;
        counters = 1;
    }

    if (combat_vars["paralyzed"]) {
        if (combat_counters["paralyzed"] > (1 + random(2))) {//-(((int)who->query_stats("dexterity") - 10) / 2)) )
            combat_vars["paralyzed"]--;
            combat_counters["paralyzed"] = 0;
            if (!combat_vars["paralyzed"]) {
                if (!who->query_tripped() && !who->query_bound() && !who->query_unconscious()) {
                    message("combat", "%^BOLD%^%^WHITE%^You can move again!", who);
                    if (!who->query_invis() && objectp(environment(who))) {
                        tell_room(environment(who), "%^BOLD%^%^WHITE%^You see " + who->QCN + " moving again.%^RESET%^", who);
                    }
                }
            }
            vars = 1;
        }
        combat_counters["paralyzed"]++;
        counters = 1;
    }

    if (combat_vars["tripped"]) {
        if (combat_counters["tripped counter"]) {
            combat_counters["tripped counter"]--;
            if (combat_counters["tripped counter"] < 1) {
                combat_counters["tripped counter"] = 0; combat_vars["tripped"] = 1;
                combat_counters["tripped"] = 100;
            }
        }
        if (combat_counters["tripped"] > (7 + random(5) - (((int)who->query_stats("dexterity") - 10) / 2))) {
            combat_vars["tripped"]--;
            vars = 1;
            combat_counters["tripped"] = 0;
            if (!combat_vars["tripped"]) {
                if (!who->query_paralyzed() && !who->query_bound() && !who->query_unconscious()) {
                    message("combat", "%^BOLD%^%^BLUE%^You have managed to stand again.", who);
                    if (!who->query_invis() && objectp(environment(who))) {
                        tell_room(environment(who), "%^BOLD%^%^GREEN%^You see " + who->QCN + " standing again.%^RESET%^", who);
                    }
                }
            }
        }
        combat_counters["tripped"]++;
        counters = 1;
    }

    if (combat_vars["unconscious"]) {
        if (combat_vars["unconscious"] > 180) {
            combat_vars["unconscious"] = 180;
        }

        combat_vars["unconscious"]--;;
        vars = 1;

        if (sizeof(who->query_attackers()) > 0) {
            combat_vars["unconscious"] = 0;
            combat_counters["unconscious"] = 0;
            message("combat", "%^BOLD%^%^BLUE%^You have regained consciousness.", who);
            if (!who->query_invis() && objectp(environment(who))) {
                tell_room(environment(who), "%^BLUE%^%^BOLD%^You notice " + who->QCN + " regained consciousness.%^RESET%^", who);
            }
        } else if (!combat_vars["unconscious"]) {
            message("combat", "%^BOLD%^%^BLUE%^You have regained consciousness.", who);
            if (!who->query_invis() && objectp(EWHO)) {
                tell_room(EWHO, "%^BLUE%^%^BOLD%^You notice " + who->QCN + " regained consciousness.%^RESET%^", who);
            }
        }

        combat_counters["unconscious"]++;
        counters = 1;
    }

    if (combat_vars["asleep"]) {
        if (combat_vars["asleep"] > 180) {
            combat_vars["asleep"] = 180;
        }

        combat_vars["asleep"]--;
        vars = 1;
        combat_counters["asleep"] = 0;

        if (sizeof(who->query_attackers()) > 0) {
            combat_vars["asleep"] = 0;
            if (!who->query_invis() && objectp(EWHO)) {
                tell_room(EWHO, "%^BOLD%^%^GREEN%^You notice " + who->QCN + " waking up.%^RESET%^", who);
            }
            message("combat", "\n%^BOLD%^%^GREEN%^You have awakened to the sounds of battle.\n", who);
        } else if (!combat_vars["asleep"]) {
            if (!who->query_invis() && objectp(EWHO)) {
                tell_room(EWHO, "%^BOLD%^%^GREEN%^You notice " + who->QCN + " waking up.%^RESET%^", who);
            }
            message("combat", "%^BOLD%^%^GREEN%^You have awakened.", who);
        }
        combat_counters["asleep"]++;
        counters = 1;
    }

    if (who->query_deaths_door()) {
        if (combat_counters["healing"] > (25 - (int)who->query_stats("constitution"))) {
            who->heal(random(2) + 1);
            combat_counters["healing"] = 0;
            if (!who->query_deaths_door()) {
                message("combat", "%^BOLD%^%^GREEN%^You have healed sufficiently to regain consciousness.", who);
                if (!who->query_invis() && objectp(EWHO)) {
                    tell_room(EWHO, "%^BOLD%^%^GREEN%^You notice " + who->QCN + " waking up.%^RESET%^", who);
                }
            }
        }
        combat_counters["healing"]++;
        counters = 1;
    }
    if (vars) {
        who->set_combat_vars(combat_vars);
    }
    if (counters) {
        who->set_combat_counters(combat_counters);
    }
    if (static_vars) {
        who->set_combat_static_vars(combat_static_vars);
    }
    return;
}

varargs void set_tripped(object who, int severity, string message, int special)
{
    int chance;
    if (!objectp(who)) {
        return;
    }
    if (who->query_property("no tripped")) {
        tell_object(who, "You cannot be tripped.");
        return;
    }
    if (intp(chance = who->query_property("untrippable"))) {
        if (chance > roll_dice(1, 100)) {
            tell_object(who, "You avoid the attempt to trip you!");
            if (objectp(environment(who))) {
                tell_room(environment(who), who->QCN + " avoids the attempt to trip " + who->QO + "!", who);
            }
            return;
        }
    }
    who->adjust_combat_mapps("vars", "tripped", severity);
    who->adjust_combat_mapps("messages", "tripped", message);
    if (special) {
        who->adjust_combat_mapps("counters", "tripped counter", special);
    }  // Added to give better control over rush, could
       // be used for other things.  -Ares 12/26/06
    return;
}

/**
 * Sets target asleep
 *
 * @param who target
 * @param xxx time in rounds
 * @param message Message displayed to sleeper
 */
void set_asleep(object who, int xxx, string message)
{
    if (!objectp(who)) {
        return;
    }
    who->adjust_combat_mapps("vars", "asleep", (xxx > 120 ? 120 : xxx));
    who->adjust_combat_mapps("messages", "asleep", message);
}

void set_unconscious(object who, int xxx, string message)
{
    if (!objectp(who)) {
        return;
    }
    who->adjust_combat_mapps("vars", "unconscious", xxx);
    who->adjust_combat_mapps("messages", "unconscious", message);
}

void set_gagged(object who, int x, string message)
{
    if (!objectp(who)) {
        return;
    }
    who->adjust_combat_mapps("vars", "gagged", x);
    who->adjust_combat_mapps("messages", "gagged", message);
}

void set_bound(object who, int difficulty, string message)
{
    if (!objectp(who)) {
        return;
    }
    who->adjust_combat_mapps("vars", "bound", difficulty);
    who->adjust_combat_mapps("messages", "bound", message);
}

void set_temporary_blinded(object who, int difficulty, string message)
{
    if (!objectp(who)) {
        return;
    }
    if (who->query_property("no blind")) {
        tell_object(who, "You are immune to blindness!");
        if (objectp(environment(who))) {
            tell_room(environment(who), who->QCN + " seems immune to the " +
                      "blindness attempt!", who);
        }
        return;
    }
    who->adjust_combat_mapps("static vars", "blinded", difficulty);
    if (stringp(message)) {
        who->adjust_combat_mapps("messages", "blinded", message);
    }
}

void set_blindfolded(object who, int difficulty, string message)
{
    if (!objectp(who)) {
        return;
    }
    who->adjust_combat_mapps("vars", "blindfolded", difficulty);
    if (stringp(message)) {
        who->adjust_combat_mapps("messages", "blindfolded", message);
    }
}

/**
 * Assigns paralyzed state, where 'x' is divisor of 8 rounds.
 * E.g. x = 16 will set paralyzed status for 2 rounds.
 */
void set_paralyzed(object who, int x, string paralyze_msg)
{
    if (!objectp(who) || !intp(x)) {
        return;
    }
    if (archp(who)) {
        message("my_action", "Your Archhood just saved you from being paralyzed.", who);
        return;
    }
    if (who->query_property("no paralyze")) {
        message("my_action", "You are uneffected by the paralysis.", who);
        if (objectp(environment(who)) && !who->query_invis()) {
            tell_room(environment(who), who->QCN + " %^BOLD%^%^GREEN%^is totally uneffected by " +
                      "the paralysis attempt!%^RESET%^");
        }
        return;
    }
    x /= 8;
    x = x < 1 ? 1 : x;
    x = x > 72 ? 72 : x;

    who->adjust_combat_mapps("vars", "paralyzed", x);
    who->adjust_combat_mapps("messages", "paralyzed", paralyze_msg);
    return;
}

/**
 * Removes paralyzed state
 */
void remove_paralyzed(object who)
{
    if (!objectp(who)) {
        return;
    }
    if (!who->query_paralyzed()) {
        return;
    }
    who->adjust_combat_mapps("vars", "paralyzed", 0);
    who->adjust_combat_mapps("messages", "paralyzed", 0);
    if (who->query_tripped() || who->query_bound() || who->query_unconscious()) {
        return;
    }
    tell_object(who, "You can move again.");
    if (!who->query_invis() && objectp(environment(who))) {
        tell_room(environment(who), "%^BOLD%^%^GREEN%^You see " + who->QCN + " is moving again.%^RESET%^", who);
    }
    return;
}

object* doProtection(object player)
{
    int i, j;
    object* pros, * tmp = ({});

    if (!objectp(player)) {
        return ({ player });
    }
    pros = player->query_protectors();

    j = sizeof(pros);
    if (!j) {
        return ({ player });
    }

    for (i = 0; i < j; i++) {
        if (!objectp(pros[i])) {
            continue;
        }
        if (!present(pros[i], player) && (!pros[i]->query_following() || (object)pros[i]->query_following() != player)) {
            player->remove_protector(pros[i]);
            continue;
        }
        if (pros[i] == player) {
            player->remove_protector(pros[i]);
            continue;
        }
        if (member_array(pros[i], player->query_attackers()) == -1) {
            tmp += ({ pros[i] });
        }
        if ((int)pros[i]->query_hp_percent() < 30) {
            player->remove_protector(pros[i]);
            tell_object(pros[i], "You are too weak to continue protecting " + player->QCN + ".");
            pros[i]->set("protecting", 0);
            continue;
        }
        //if(random(query_highest_level()*2) > random((int)pros[i]->query_highest_level() + (int)player->query_lowest_level()))
        if (!random(7) && pros[i]->query("protecting")) {
            tell_object(pros[i], "You are unable to defend " + player->QCN + " this attack.");
            pros[i]->set("protecting", 0);
            continue;
        }
        //tell_object(pros[i], "You stand in defense of "+player->QCN+".");
        //tell_object(player,pros[i]->QCN+" stands in defense of you.");
        pros[i]->set("protecting", 1);
        tmp += ({ pros[i] });
        continue;
    }
    //if (!sizeof(tmp)) tmp += ({player});
    tmp += ({ player });
    tmp = distinct_array(tmp);
    return tmp;
}

object* query_active_protectors(object obj)
{
    object* protectors = ({}), * good_protectors = ({});
    int i;

    if (!objectp(obj)) {
        return ({});
    }

    protectors = (object*)obj->query_protectors();

    if (!pointerp(protectors)) {
        return ({});
    }
    if (!sizeof(protectors)) {
        return ({});
    }

    for (i = 0; i < sizeof(protectors); i++) {
        if (!objectp(protectors[i])) {
            continue;
        }
        if (!protectors[i]->query("protecting")) {
            continue;
        }
        if (!present(protectors[i], environment(obj))) {
            continue;
        }
        good_protectors += ({ protectors[i] });
        continue;
    }
    if (!sizeof(good_protectors)) {
        return ({});
    }
    return good_protectors;
}

void send_dodge(object who, object att)
{
    int i, j;
    string* verb, * adverb, v, a;
    if (!objectp(att) || !objectp(who)) {
        return;
    }

    verb = ({ "flip", "back flip", "jump", "dodge", "roll", "somersault", "dance", "spin", "scramble" });
    adverb = ({ "easily", "quickly", "barely", "poorly", "with agility", "deftly" });
    v = verb[random(sizeof(verb))];
    a = adverb[random(sizeof(adverb))];
    tell_object(who, "%^BOLD%^%^WHITE%^" + att->QCN + " " + v + "s " + a + " from your blow.");
    tell_object(att, "%^BOLD%^%^WHITE%^You " + v + " " + a + " from " + who->QCN + "'s blow.");
    tell_room(environment(who), "%^BOLD%^%^WHITE%^" + att->QCN + " " + v + "s " + a + " from " + who->QCN + "'s blow.", ({ who, att }));
    return;
}

//is this even used? Saide - January 2017
void thaco_messages(object who, int thaco)
{
    if (!objectp(who)) {
        return;
    }
    switch (thaco) {
    case 8..10:
        tell_object(who, "%^YELLOW%^Your pitiful attempt at wielding two weapons is just silly.%^RESET%^");
        break;

    case 5..7:
        tell_object(who, "%^ORANGE%^You look really silly trying to wield two weapons %^RESET%^");
        break;

    case 4:
        tell_object(who, "%^RED%^You awkwardly attack with two weapons %^RESET%^");
        break;

    case 3:
        tell_object(who, "%^YELLOW%^You have trouble attacking with two weapons.%^RESET%^");
        break;

    case 2:
        tell_object(who, "%^BLUE%^You find difficulty in wielding two weapons.%^RESET%^");
        break;

    case 1:
        tell_object(who, "%^GREEN%^Wielding two weapons is harder but still effective.%^RESET%^");
        break;

    default: break;
    }
    return;
}

int ok_to_kill(object who, object targ)
{
    int vic_level, pk_age_limit;
    string str, title;
    object hold, pkob;
    if (!objectp(targ) || !objectp(who)) {
        return 0;
    }
    if (targ->is_invincible()) {
        return 0;
    }
    if (!interactive(who) && !interactive(targ)) {
        return 1;
    }
    if (who == targ) {
        return 1;
    }

    if (interactive(who) && interactive(targ)) {
        if (newbiep(who) && (!avatarp(targ))) {
            tell_object(who, "%^YELLOW%^You are currently under " +
                        "%^CYAN%^newbie%^YELLOW%^ protection and unable to " +
                        "be aggressive against " + targ->QCN + "%^YELLOW%^!%^RESET%^");
            return 0;
        }
        if (newbiep(targ) && (!avatarp(who))) {
            tell_object(who, targ->QCN + "%^YELLOW%^ is currently " +
                        "under %^CYAN%^newbie%^YELLOW%^ protection and " +
                        "cannot be attacked by you.%^RESET%^");
            return 0;
        }
        if (targ->query("no pk")) {
            tell_object(who, targ->QCN + "%^YELLOW%^ is currently protected " +
                        "from pkill interactions.%^RESET%^");
            return 0;
        }
        if (who->query("no pk")) {
            tell_object(who, "%^YELLOW%^You are currently protected from pkill " +
                        "interactions. See help flag in order to turn this off.%^RESET%^");
            return 0;
        }
        if (in_edit(targ) || in_input(targ) && userp(who)) {
            tell_object(who, "%^BOLD%^%^RED%^" + targ->QCN + " is currently daydreaming and cannot be attacked.%^RESET%^");
            return 0;
        }
        pkob = new(PK_OB);
        pkob->move(who);
        pkob->pkill_start(who, targ, 1);
        pkob = new(PK_OB);
        pkob->move(targ);
        pkob->pkill_start(targ, who, 0);
    }
    return 1;
}

void add_attacker(object who, object ob)
{
    object* attackers;
    string* atnames;
    if (!objectp(who) || !objectp(ob)) {
        return;
    }
    if (!objectp(environment(who)) || !objectp(environment(ob))) {
        return;
    }
    attackers = who->query_attackers();
    atnames = who->query_atnames();
    if (ob == who) {
        return;
    }
    if (member_array(ob, attackers) != -1) {
        return;
    }
    attackers += ({ ob });
    if (userp(ob)) {
        if (member_array(ob->query_name(), atnames) != -1) {
            return;
        }
        if (environment(who)->query_property("arena")) {
            return;
        }
        atnames += ({ ob->query_name() });
    }
    if (sizeof(attackers)) {
        who->set_attackers(attackers);
    }
    if (sizeof(atnames)) {
        who->set_atnames(atnames);
    }
    who->check_death();
    ob->check_death();
    who->clean_up_attackers();
    ob->clean_up_attackers();
    return;
}

int light_armor_filter(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ((string)ob->query_armor_prof() == "heavy") {
        return 1;
    }
    if ((string)ob->query_armor_prof() == "medium") {
        return 1;
    }
    return 0;
}

void ok_to_wield(object who)
{
    object* wielded, * worn;
    int Size;
    if (!objectp(who)) {
        return;
    }
    if (interactive(who)) {
        wielded = who->query_wielded();
        worn = who->all_armour();
        worn = distinct_array(worn);
        worn = filter_array(worn, "light_armor_filter", TO);
        if (sizeof(wielded) > 1) {
            Size = (int)who->query_size() - 1;
            if (Size == 0) {
                Size = 1;
            }

            if (((wielded[0]->query_size() > Size) &&
                    (wielded[1]->query_size() > Size) &&
                    who->validate_combat_stance("dual wield")) ||
                who->validate_combat_stance("double weapon")) {
                if (FEATS_D->usable_feat(who, "ambidexterity")) {
                    if (sizeof(worn)) {
                        tell_object(who, "You scramble to hang on to your " + wielded[0]->query_name() + " and "
                                    "your " + wielded[1]->query_name() + " but all that armor makes it impossible!");
                        tell_room(environment(who), "" + who->QCN + " scrambles to hang on to " + who->QP + " " + wielded[0]->query_name() + " "
                                  "and " + who->QP + " " + wielded[1]->query_name() + " but fumbles and drops them!", who);

                        if (!wielded[0]->query_property("enchantment") || (int)wielded[0]->query_property("enchantment") > 0) {
                            wielded[0]->move(environment(who));
                        }
                        if (!wielded[1]->query_property("enchantment") || (int)wielded[1]->query_property("enchantment") > 0) {
                            wielded[1]->move(environment(who));
                        }
                    }
                }else {
                    tell_object(who, "In your attempt to wield two such weapons, you fumble and drop them.");
                    tell_room(environment(who), who->QCN + " fumbles with " + who->QP + " " + wielded[0]->query_name() + " and "
                              "" + who->QP + " " + wielded[1]->query_name() + " and then drops them.", who);
                    if (!wielded[0]->query_property("enchantment") || (int)wielded[0]->query_property("enchantment") > 0) {
                        wielded[0]->move(environment(who));
                    }
                    if (!wielded[1]->query_property("enchantment") || (int)wielded[1]->query_property("enchantment") > 0) {
                        wielded[1]->move(environment(who));
                    }
                }
            }
        }
    }
}

void clean_attacker_flags(object who)
{
    if (!objectp(who)) {
        return;
    }
    who->remove_property("using whirl");
    who->remove_property("using sweeping blow");
    who->remove_property("using manyshot");
    who->remove_property("using spinning kick");
    who->remove_property("using smite");
    who->remove_property("messids"); //Feat messages tracking
}

int sight_adjustment(object who)
{
    int elight, ret;
    ret = 0;
    elight = effective_light(who);
    if (elight > 6 || elight < 1) {
        ret = random(5);
    }
    return ret;
}

void run_away(object who)
{
    string* str;
    string dir, wimpydir;

    if (!objectp(who) || !objectp(environment(who))) {
        return;
    }
    str = (string*)environment(who)->query_exits();
    if (!str || !sizeof(str)) {
        tell_object(who, "There is nowhere to run!!!");
        return;
    }

    tell_object(who, "You run away.");
    if (objectp(environment(who)) && !who->query_invis()) {
        tell_room(environment(who), who->QCN + " runs away!", who);
    }
    wimpydir = who->query_wimpydir();
    if (member_array(wimpydir, str) != -1) {
        dir = wimpydir;
    }else if (wimpydir == "retreat") {
        dir = environment(who)->query_direction(base_name(who->query_last_location()));
    }
    if (!dir || dir == "/d/shadowgate/void") {
        dir = str[random(sizeof(str))];
    }
    who->set_property("true moving", dir);
    who->set_property("running away", 1);
    who->force_me(dir);
    who->remove_property("running away");
    who->remove_property("true moving");
    who->set_wimped(1);
    return;
}

string query_paralyze_message(object who)
{
    if (!objectp(who)) {
        return "";
    }
    if (who->adminBlock()) {
        return "";
    }
    if (who->query_deaths_door()) {
        return DEATHS_DOOR_MESSAGE;
    }
    if (who->query_unconscious()) {
        return who->query_unconscious_message();
    }
    if (who->query_paralyzed()) {
        return who->query_combat_mapps("messages", "paralyzed");
    }
    if (who->query_bound()) {
        return who->query_bound_message();
    }
    if (who->query_tripped()) {
        return who->query_tripped_message();
    }
}

//altered to allow best avoidance type to process
//added ultra counter attack if both spring attack and masters parry process
//Yves - 11/02/2018
//Rewritten so remove multiple sequential avoidance rolls
//Uriel - 06/09/2020

int check_avoidance(object who, object victim)
{
    object EWHO, rider, *weapons = ({});
    int attack, defend, roll, chance;
    int parry = 0, scramble = 0, ride_by_attack = 0;
    int shot_on_the_run = 0, mount = 0;
    int whirling_steel = 0, combo = 0;
    int avoidance = 0, springAttack = 0, counterAttack = 0;
    float mod = 0;
    string *avoid = ({});
    string avoidanceType = "";

// Check for errors, paralysis, and automatic hits, adding tripped to unify avoidance
    if (   !objectp(who)
        || !objectp(victim)
        || !objectp(EWHO = environment(who))
        || victim->query_paralyzed()
        || who->query_property("noMissChance"))
        {
        return 0;
    }

// What kinds of avoidance are possible?
// 4 basic types: parry, scramble, ride-by attack, shot on the run
// 3 combos: parry+scramble, parry+ride-by attack, scramble+shot on the run
// 1 special case: mounts (rider has mounted combat feat)

    if (victim->query_parrying()) {
       //dependencies checked in living.c
       parry = 1;
       avoid += ({"TYPE_PARRY"});
       //check for counterattack
       if (FEATS_D->usable_feat(victim, "masters parry")
           && victim->validate_combat_stance("dual wield")) {
           if (random(4)) {
               // should happen frequently as it's a level 47 ability
               counterAttack = 1;
           }
       }
       if(FEATS_D->usable_feat(victim, "elaborate parry")
          && victim->validate_combat_stance("one hander") && random(4))
          counterAttack = 1;
    }
    if (victim->query_scrambling()) {
       //dependencies checked in living.c
       scramble = 1;
       avoid += ({"TYPE_SCRAMBLE"});
       //check for spring attack
       if (FEATS_D->usable_feat(victim, "spring attack") && !random(5)) {
            springAttack = 1;
       }
    }
    if (FEATS_D->usable_feat(victim, "ride-by attack")
       && victim->query_in_vehicle()) {
       ride_by_attack = 1;
       avoid += ({"TYPE_RIDDEN"});
    }
    if (FEATS_D->usable_feat(victim,"shot on the run")
       && sizeof(weapons = victim->query_wielded())) {
       if(weapons[0]->is_lrweapon())
       {
       shot_on_the_run = 1;
       avoid += ({"TYPE_SHOT"});
       }
    }
    if (victim->is_animal()) {
        rider = (object)victim->query_current_rider();
        if (objectp(rider)) {
            if (FEATS_D->usable_feat(rider, "mounted combat")) {
                mount = 1;
                avoid += ({"TYPE_MOUNT"});
            }
        }
    }
//  If avoidance is not possible then exit.
    if (!sizeof(avoid)) {
        return 0;
    }

//  Decide if there are multiple options for avoidance.
    if (   (parry && scramble)
        || (parry && ride_by_attack)
        || (scramble && shot_on_the_run)) {
        combo = 1;
    }

//  This is a fractional version that accomodates
//  large differences in levels, like L40 vs L100.
//  The math is very good but is less intuitive than
//  a d20.

// Add bonuses for specific feats or avoidance combos
    if (victim->query_property("shield_of_whirling_steel")) {
         whirling_steel = 1;
    }
    if (combo && whirling_steel) {
         mod = 1.50;
    }
    else if (combo || whirling_steel) {
         mod = 1.25;
    }
    else {
         mod = 1.00;
    }

//  Avoidance Roll
    attack = (int)who->query_highest_level(); //changed to highest level rather than BAB.  Doesn't nerf SC thieves.
    attack += (int)who->query_skill("athletics")/2; //athletics/2 to improve dex but not make it a god stat.
    defend = (int)victim->query_highest_level();
    defend += (int)victim->query_skill("athletics")/2;
    defend *= mod; // mod is a multiplier for fraction method
    chance = (int) 1.0*defend/(attack + defend) * 1000;
    roll = roll_dice(1,1000);
    if (roll <= chance) { //tie goes to defender
         avoidance = 1;
    }
/* Debug Code
    tell_room(EWHO, " attack "+ attack);
    tell_room(EWHO," defend "+ defend);
    tell_room(EWHO," chance "+ chance);
    tell_room(EWHO," roll   "+ roll);
    tell_room(EWHO," avoidance "+ avoidance);
*/

/* // This is the d20 version
   //
   // This version is very transparent but it is not
   // very good when level differences are large.
   // Basically D&D is designed for up to 20 levels
   // and the math starts to get bad after that. For example
   // the chance of a L40 hitting a L60 and a L80 are the same.
// Add bonuses for specific feats or avoidance combos
    if (combo) {
         mod += 2;
    }
    if (victim->query_property("shield_of_whirling_steel")) {
         mod += 3;
    }
//  Avoidance Roll
    attack = (int) BONUS_D->new_bab(1,who);
    attack += (int)who->query_skill("athletics")/10;
    attack += 10; // attacker gets 10 and defender gets 1d20
    defend = (int) BONUS_D->new_bab(1,victim);
    defend += (int)victim->query_skill("athletics")/10;
    defend += mod;
    roll   =  roll_dice(1,20);
    if (roll == 20) {
         avoidance = 1;
    }
    else if (roll == 1) {
         avoidance = 0;
    }
    else if (roll + defend >= attack) {
         avoidance = 1;
    }
    else {
         avoidance = 0;
    }
*/
//  If avoidance failed, exit.
    if (!avoidance) {
        return 0;
    }
    //choose the avoidance message
    avoidanceType = avoid[random(sizeof(avoid))];
    //ensure the correct avoidance message fires
    if (counterAttack && springAttack) {
        avoidanceType = "TYPE_COMBINED";
    }else if (counterAttack) {
        avoidanceType = "TYPE_PARRY";
    }else if (springAttack) {
        avoidanceType = "TYPE_SCRAMBLE";
    }

    switch (avoidanceType) {
    case "TYPE_COMBINED":
        tell_object(who, "%^BOLD%^%^WHITE%^Your opponent anticipates your attack and maneuvers into perfect position!%^RESET%^");
        tell_object(victim, "%^BOLD%^%^WHITE%^You anticipate your opponent's attack and maneuver into perfect position!%^RESET%^");
        tell_room(EWHO, "%^BOLD%^%^WHITE%^You see " + who->QCN + "'s attack expertly avoided by " + victim->QCN + "!%^RESET%^", ({ who, victim }));
        combined_attack(who, victim);
        break;

    case "TYPE_SCRAMBLE":
        who->send_dodge(victim);
        if (springAttack) {
            victim->spring_attack(victim);
        }
        break;

    case "TYPE_PARRY":
        tell_object(who, "%^BOLD%^%^WHITE%^Your attack is parried by your attacker!%^RESET%^");
        tell_object(victim, "%^BOLD%^%^WHITE%^You deftly parry your opponent's blow!%^RESET%^");
        tell_room(EWHO, "%^BOLD%^%^WHITE%^You see " + who->QCN + "'s attack parried by " + victim->QCN + ".%^RESET%^", ({ who, victim }));
        if (counterAttack) {
            counter_attack(victim);
        }
        break;

    case "TYPE_RIDDEN":
        tell_object(who, "%^%^RESET%^%^BOLD%^" + victim->QCN + " has already ridden past you and "
                    "is out of reach!%^RESET%^");

        tell_object(victim, "%^RESET%^%^BOLD%^You deftly steer your steed and " + who->QCN +
                    "'s blow falls short of hitting you!%^RESET%^");

        tell_room(EWHO, "%^RESET%^%^BOLD%^" + victim->QCN + " deftly steers " + victim->QP +
                  " steed and " + who->QCN + "'s blow falls short of hitting " + victim->QO +
                  "!%^RESET%^", ({ who, victim }));
        break;

    case "TYPE_SHOT":
        tell_object(who, "%^RESET%^%^BOLD%^" + victim->QCN + " uses " + victim->QP + " own attack as "
                    "cover, and manages to move out of your reach!%^RESET%^");

        tell_object(victim, "%^RESET%^%^BOLD%^You use your last shot as cover to get clear "
                    "of " + who->QCN + "'s attack!%^RESET%^");

        tell_room(EWHO, "%^RESET%^%^BOLD%^" + victim->QCN + " uses " + victim->QP + " last shot as "
                  "cover to get clear of " + who->QCN + "'s attack!%^RESET%^", ({ who, victim }));
        break;

    case "TYPE_MOUNT":
        tell_object(rider, "%^RESET%^%^BOLD%^You direct your steed out of harm's way!%^RESET%^");

        tell_room(EWHO, "%^RESET%^%^BOLD%^" + rider->QCN + " directs " + rider->QP +
                  "steed out of harm's way!%^RESET%^", rider);
        break;

    default: break;
    }

    return avoidance;
}

void combined_attack(object who, object victim)
{
    object* attackers, EWHO;

    if (!objectp(who) || !objectp(victim)) {
        return;
    }
    attackers = victim->query_attackers();
    attackers -= ({ 0 });
    if (!sizeof(attackers)) {
        return;
    }
    EWHO = environment(who);

    //special effect on top of an extra attack since they springed AND countered
    switch (random(50)) {
    case 0..29:   //damage
        tell_object(who, "%^BOLD%^%^RED%^" + victim->QCN + " takes advantage of " + victim->QP +
                    " position and delivers a devastating blow while your guard is down!%^RESET%^");
        tell_object(victim, "%^BOLD%^%^RED%^You take advantage of your position "
                    "and deliver a devastating blow to " + who->QCN + " while " + who->QP + " guard is down!%^RESET%^");
        tell_room(EWHO, "%^BOLD%^%^RED%^" + victim->QCN + " takes advantage of " + victim->QP +
                  " position and delivers a devastating blow to " + who->QCN + " while " + who->QP +
                  " guard is down!%^RESET%^", ({ who, victim }));
        who->do_damage(who->return_limb(), roll_dice(5, 12) + 25);
        break;

    case 30..39:   //stun
        tell_object(victim, "%^BOLD%^%^WHITE%^You take advantage of your position "
                    "and connect with a strike that leaves " + who->QCN + " staggered!%^RESET%^");
        tell_object(who, "%^BOLD%^%^WHITE%^" + victim->QCN + " takes advantage of " + victim->QP +
                    " position and connects with a strike that leaves you staggered!%^RESET%^");
        tell_room(EWHO, "%^BOLD%^%^WHITE%^" + victim->QCN + " takes advantage of " + victim->QP +
                  " position and connects with a strike that leaves " + who->QCN +
                  " staggered!%^RESET%^", ({ who, victim }));
        who->set_paralyzed(roll_dice(1, 10) + 10, "%^BOLD%^%^WHITE%^You are staggered "
                           "by the unexpected blow!%^RESET%^");
        break;

    case 40..49:   //trip
        tell_object(victim, "%^BOLD%^%^BLUE%^You take advantage of your position "
                    "and sweep through " + who->QCN + "'s lower limbs causing " + who->QO +
                    " to fall prone!%^RESET%^");
        tell_object(who, "%^BOLD%^%^BLUE%^" + victim->QCN + " takes advantage of " + victim->QP +
                    " position and sweeps through your lower limbs causing you to fall prone!%^RESET%^");
        tell_room(EWHO, "%^BOLD%^%^BLUE%^" + victim->QCN + " takes advantage of " + victim->QP +
                  " position and sweeps through " + who->QCN + "'s lower limbs causing " + who->QO +
                  " to fall prone!%^RESET%^", ({ who, victim }));
        who->set_tripped(random(2) + 1, "%^BOLD%^%^BLUE%^You are scrambling to your feet!%^RESET%^");
        break;

    default: break;
    }
    victim->execute_attack();

    return;
}

//FUNCTIONS BELOW STILL NEED CONVERTING
void internal_execute_attack(object who)
{
    int toAttack, toattack, lastHand, critical_hit, fortification;
    int i, roll, temp1, temp2, touch_attack = 0, fumble = 0;
    object* weapons, current, victim, * protectors, * attackers, EWHO;
    string target_thing;

    if (!objectp(who)) {
        return;
    }
    who->set_for_attack(); //sets attacking to 0 - this function will not get called until it is 0
    EWHO = environment(who);
    if (!objectp(EWHO)) {
        return;
    }
    if (objectp(who)) {
        who->reset_critical();
    }
    attackers = who->query_attackers();
    if (!sizeof(attackers)) {
        who->prepare_attack();
        if (who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
            who->execute_attack();
        }
        return;
    }
    if (who->query_property("flee")) {
        who->prepare_attack();
        if (who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
            who->execute_attack();
        }
        return;
    }

    toAttack = random(sizeof(attackers));
    while (!objectp(attackers[toAttack]) || !present(attackers[toAttack], EWHO)) {
        attackers -= ({ attackers[toAttack] });
        who->set_attackers(attackers);
        if (!sizeof(attackers)) {
            who->prepare_attack();
            if (who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
                who->execute_attack();
            }
            return;
        }
        toAttack = random(sizeof(attackers));
    }
    who->adjust_combat_mapps("vars", "toAttack", toAttack);

    toattack = 4;
    who->adjust_combat_mapps("static vars", "toattack", toattack);

    victim = attackers[toAttack];
    protectors = victim->query_active_protectors(victim);
    if (sizeof(protectors)) {
        victim = protectors[random(sizeof(protectors))];
    }
    if (!living(victim) && !victim->query("not living")) {
        who->prepare_attack();
        if (who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
            who->execute_attack();
        }
        return;
    }

    if (FEATS_D->usable_feat(who, "perfect self")) {
        if (!(int)who->has_ki()) {
            who->regenerate_ki(4);
        }
    }

    if (member_array(who, (object*)victim->query_attackers()) == -1) {
        victim->add_attacker(who);
        EWHO->add_combatant(victim);
        who->clean_up_attackers();
    }
    if ((!who->do_casting(victim) && !who->query_property("temp_perfect_caster")) && !who->do_functions()) {
        who->ok_to_wield();
        weapons = distinct_array(who->query_wielded());
        lastHand = who->query_combat_mapps("static vars", "lastHand");
        if (pointerp(weapons) && lastHand < sizeof(weapons)) {
            current = weapons[lastHand];
        }else if (pointerp(weapons) && lastHand > (sizeof(weapons) - 1)) {
            who->adjust_combat_mapps("static vars", "lastHand", 0);
            lastHand = 0;
            if (lastHand < sizeof(weapons)) {
                current = weapons[lastHand];
            }else {
                current = who;
            }
        }else {
            current = who;
        }

        if (current->is_lrweapon() && !FEATS_D->usable_feat(who, "point blank shot") && !who->query_property("shapeshifted")) {
            tell_object(who, "Your bow is useless in hand to hand combat.\n");
            who->prepare_attack();
            if (who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
                who->execute_attack();
            }
            return;
        }
        roll = random(20) + 1;

        //Touch of Chaos gives disadvantage
        if(who->query_property("touch of chaos"))
            roll = min( ({ roll, random(20) + 1 }) );

        //Touch of Law makes the roll 11
        if(who->query_property("touch of law"))
            roll = 11;

        if (roll == 1) { //automatic miss on rolls of a one
            fumble = 1;
        }else {
            fumble = 0;
        }


        target_thing = (string)victim->return_target_limb();
        roll = BONUS_D->process_hit(who, victim, i, current, 0, touch_attack);
        //crit stuff
        if (sizeof(weapons)) {
            temp1 = (int)current->query_critical_threat_range();
        }

        if (!temp1) {
            temp1 = 1;
        }

        if (FEATS_D->usable_feat(who, "lethal strikes")) {
            temp1 *= 2;
        }

        if (victim->query_property("fortification 75")) {
            fortification = 75;
        }
        else if (victim->query_property("fortification 50")) {
            fortification = 50;
        }
        else if (victim->query_property("fortification 25")) {
            fortification = 25;
        }
        else {
            fortification = 0;
        }

        if (roll >= (21 - temp1)) { // if threat range of weapon is 2, then we have a crit threat on a roll of 19 or 20
            if (!(roll_dice(1, 100) > fortification) && victim->query_property("armor enhancement timer")) { // fortification chance to avoid critical
                tell_object(who, "%^BOLD%^%^YELLOW%^You successfully position yourself to strike where " + victim->QCN + " is vulnerable, but " + victim->QS + "'s armor produces a magical force that protects " + victim->QP + " vital areas.%^RESET%^");
                tell_object(victim, "%^BOLD%^%^YELLOW%^You suddenly notice that " + who->QCN + " has moved to strike where you are vulnerable, but your armor produces a magical force that protects your vital areas.%^RESET%^");
                tell_room(EWHO, "%^BOLD%^%^YELLOW%^" + who->QCN + " has positioned " + who->QO + "self to strike where " + victim->QCN + " is vulnerable, but " + victim->QS + "'s armor produces a magical force that protects " + victim->QP + " vital areas.%^RESET%^", ({ victim, who }));
            }
            else {
                critical_roll = roll;
                if (!victim->query_property("no crit") && (!interactive(victim) || ((int)victim->query_level() > 5))) {
                    temp2 = BONUS_D->process_hit(who, victim, i, current);
                    if (temp2) {
                        who->adjust_combat_mapps("static vars", "critical hit", 1);
                        who->adjust_combat_mapps("static vars", "critical message", 1);
                        critical_hit = 1;
                    }
                }
            }
        }
        // end crit stuff
        if (roll && fumble == 0) {
            if (!victim->query_unconscious() && !victim->query_ghost() && !victim->query_bound()) {
                if (!extra_hit_calcs(who, victim, current, target_thing) || check_avoidance(who, victim)) {
                    if (!objectp(who)) {
                        return;
                    }
                    who->adjust_combat_mapps("static vars", "lastHand", 1, 1);
                    who->adjust_combat_mapps("static vars", "attacking", 0);
                    if (who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
                        who->execute_attack();
                    }
                    return;
                }else {
                    calculate_damage(who, victim, current, target_thing, critical_hit);
                }
            }else {
                calculate_damage(who, victim, current, target_thing, critical_hit);
            }
        }
        if (roll == 1) {
            //if(find_player("saide") && userp(who)) tell_object(find_player("saide"), identify(who) + " rolled a 1 against "+identify(victim));
            if (objectp(current)) {
                if ((int)current->query("PoisonDoses")) {
                    if (who->reflex_save(15)) {
                        POISON_D->is_object_poisoned(current, who, "hit", 1);
                    }
                }
            }
        }
        if (!roll || fumble == 1) {
            //if(find_player("saide") && userp(who)) tell_object(find_player("saide"), identify(who) + " missed "+identify(victim));
            if (!current || who->query_property("shapeshifted")) {
                who->miss(who->query_casting(), victim, 0, target_thing);
            }else {
                who->miss(0, victim, (string)current->query_type(), target_thing);
            }
        }
    }

    if (!objectp(who)) {
        return;
    }
    if (!objectp(victim)) {
        who->adjust_combat_mapps("static vars", "lastHand", 1, 1);
        who->adjust_combat_mapps("static vars", "attacking", 0);
        if (who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
            who->execute_attack();
        }
        return;
    }

    /*
    if (FEATS_D->usable_feat(who, "combat reflexes") &&
        who->is_ok_armour("thief") &&
        !who->query_casting() &&
        (int)who->query_property("stabs_available") > 0 &&
        !who->query_paralyzed() && !who->query_tripped()) {
        who->set_property("stabs_available", -1);
        /*
        if (victim->query_property("stab_resilience")) {
            victim->set_property("stab_resilience", -1);
            tell_object(who, "%^BOLD%^%^YELLOW%^You successfully position yourself to strike where " + victim->QCN + " is vulnerable, but " + victim->QS + " seems unaffected.%^RESET%^");
            tell_object(victim, "%^BOLD%^%^YELLOW%^You suddenly notice that " + who->QCN + " has moved to strike where you are vulnerable, but you are resilient against the worst of the attack.%^RESET%^");
            tell_room(EWHO, "%^BOLD%^%^YELLOW%^" + who->QCN + " has positioned " + who->QO + "self to strike where " + victim->QCN + " is vulnerable, but " + victim->QS + " seems unaffected.%^RESET%^", ({ victim, who }));
        }
        else if (!(roll_dice(1, 100) > fortification) && victim->query_property("armor enhancement timer")) {// fortification chance to avoid stab
            tell_object(who, "%^BOLD%^%^YELLOW%^You successfully position yourself to strike where " + victim->QCN + " is vulnerable, but " + victim->QS + "'s armor produces a magical force that protects " + victim->QP + " vital areas.%^RESET%^");
            tell_object(victim, "You suddenly notice that " + who->QCN + " has moved to strike where you are vulnerable, but your armor produces a magical force that protects your vital areas.%^RESET%^");
            tell_room(EWHO, "%^BOLD%^%^YELLOW%^" + who->QCN + " has positioned " + who->QO + "self to strike where " + victim->QCN + " is vulnerable, but " + victim->QS + "'s armor produces a magical force that protects " + victim->QP + " vital areas.%^RESET%^", ({ victim, who }));
        }
        else {
            tell_object(who, "%^BOLD%^%^YELLOW%^You successfully position yourself to strike where " + victim->QCN + " is vulnerable.%^RESET%^");
            tell_object(victim, "%^BOLD%^%^YELLOW%^You suddenly notice that " + who->QCN + " has moved to strike where you are vulnerable.%^RESET%^");
            tell_room(EWHO, "%^BOLD%^%^YELLOW%^" + who->QCN + " has positioned " + who->QO + "self to strike where " + victim->QCN + " is vulnerable.%^RESET%^", ({ victim, who }));
            "/cmds/mortal/_stab"->scramble_stab(who, victim);
        }
    }
    */
    
    if (((int)who->query_scrambling() == 1) && who->is_ok_armour("thief") && who->is_class("thief")) {
        if (D_BUG_D->scramble_change()) {
            who->set_scrambling(2);
        }
    }

    who->adjust_combat_mapps("static vars", "lastHand", 1, 1);
    who->adjust_combat_mapps("static vars", "attacking", 0);
    if (who->query_combat_mapps("static vars", "attack count") && !who->query_combat_mapps("static vars", "attack loop")) {
        who->execute_attack();
    }
    return;
}

// Does the functions returns 1 if func is executed and 0 if not
int do_functions(object who)
{
    object random_targ;
    if (!objectp(who)) {
        return 0;
    }
    if (who->query_combat_mapps("vars", "funcCast")) {
        return 0;
    }
    if (!who->clean_up_attackers()) {
        return 0;
    }
    who->setFuncCast(1);
    if (who->query_func_chance() > (random(100) + 1)) {
        random_targ = who->return_player_target(50);
        if ((!objectp(random_targ))) {
            return 0;
        }
        who->setFuncing(1);
        call_other(who, who->get_random_func(), random_targ);
        return 1;
    }
    return 0;
}

mixed return_player_target(object who, int flag)
{
    int x;
    object* myTargets = ({}), attackers;
    if (!objectp(who)) {
        return 0;
    }
    if (!who->clean_up_attackers()) {
        return 0;
    }
    attackers = who->query_attackers();
    if (!intp(flag)) {
        flag = 50;
    }
    if (roll_dice(1, 100) > flag) {
        return attackers[random(sizeof(attackers))];
    }
    for (x = 0; x < sizeof(attackers); x++) {
        if (!interactive(attackers[x])) {
            continue;
        }
        myTargets += ({ attackers[x] });
        continue;
    }
    if (sizeof(myTargets)) {
        return myTargets[random(sizeof(myTargets))];
    }else {
        return attackers[random(sizeof(attackers))];
    }
}

int do_casting(object who, object targ)
{
    string this_spell, spell_type, spell_file;
    object tempspell;
    if (!objectp(who) || !objectp(environment(who))) {
        return 0;
    }
    if (!objectp(targ)) {
        targ = who->return_player_target(50);
    }
    if (!objectp(targ) || !present(targ, environment(who))) {
        return 0;
    }
    if (who->query_combat_mapps("vars", "castFunc")) {
        return 0;
    }
    who->setCastFunc(1);
    if ((int)who->query_spell_chance() > (random(100) + 1)) {
        this_spell = (string)who->get_random_spell();
        if (this_spell) {
            spell_file = "/cmds/spells/" + this_spell[0..0] + "/_" + replace_string(this_spell, " ", "_") + ".c";
            if (file_exists(spell_file)) {
                tempspell = new(spell_file);
                if (!objectp(tempspell)) {
                    who->setCastFunc(0);
                    return 0;
                }
                if ((int)tempspell->query_target_required() == 1) {
                    tempspell->use_spell(who, targ, who->query_level());
                }else {
                    tempspell->use_spell(who, 0, who->query_level());
                }
            }
        }
        return 1;
    }
    return 0;
}

void spring_attack(object ob)
{
    object* attackers;
    if (!objectp(ob)) {
        return;
    }
    attackers = ob->query_attackers();
    attackers -= ({ 0 });
    if (!sizeof(attackers)) {
        return;
    }
    tell_object(ob, "%^BOLD%^%^CYAN%^You use the momentum of your dodge to "
                "try and land another attack!");
    tell_room(environment(ob), "%^BOLD%^%^CYAN%^" + ob->QCN + " uses the momentum "
              "of " + ob->QP + " dodge to try and land another attack!", ob);
    ob->execute_attack();
    return;
}

void counter_attack(object ob)
{
    object* attackers;
    if (!objectp(ob)) {
        return;
    }
    attackers = ob->query_attackers();
    attackers -= ({ 0 });
    if (!sizeof(attackers)) {
        return;
    }
    tell_object(ob, "%^RESET%^%^BOLD%^%^GREEN%^You take advantage of the opening and "
                "counter attack!%^RESET%^");
    tell_room(environment(ob), "%^RESET%^%^BOLD%^%^GREEN%^" + ob->QCN + " takes advantage "
              "of the opening and counter attacks!%^RESET%^", ob);
              
    counter_damage = ob->query_property("shieldwall") * 10;
        
    if(FEATS_D->usable_feat(ob, "elaborate parry"))
        counter_damage = ob->query_property("combat_expertise") * 10;
    
    ob->execute_attack();
    counter_damage = 0;
    return;
}

int isPkill(object who)
{
    int i, j;
    object killedBy, * attackers, EWHO;
    if (!objectp(who)) {
        return 0;
    }
    if (!objectp(EWHO = environment(who))) {
        return 0;
    }
    if (!userp(who) && !who->is_townsman()) {
        return 0;
    }
    attackers = who->query_attackers();
    if (!sizeof(attackers)) {
        return 0;
    }

    if (objectp(attackers[0])) {
        if (attackers[0]->query_property("spell") && objectp(attackers[0]->query_property("spell"))) {
            killedBy = (attackers[0]->query_property("spell"))->query_caster();
        }
        if (!objectp(killedBy)) {
            killedBy = attackers[0];
        }
    }

    if (EWHO->query_property("arena") && (who->query_property("safe arena") && killedBy->query_property("safe arena"))) {
        return 0;
    }

    j = sizeof(attackers);
    for (i = 0; i < j; i++) {
        if (objectp(attackers[i])) {
            if (userp(attackers[i]) || isPlayerMonster(attackers[i])) {
                return attackers[i];
            }
            if (attackers[i]->is_townsman()) {
                return attackers[i];
            }
            if (attackers[i]->query_property("knock unconscious")) {
                return attackers[i];
            }
            if (attackers[i]->is_spell() && objectp(attackers[i]->query_caster()) && interactive(attackers[i]->query_caster())) {
                return attackers[i]->query_caster();
            }
        }
    }
    return 0;
}

int isPlayerMonster(object ob)
{
    object spell;
    if (!objectp(ob)) {
        return 0;
    }
    if (spell = ob->query_property("spell")) {
        if (!objectp(spell)) {
            return 0;
        }
        if (objectp(spell->query_caster())) {
            return userp(spell->query_caster());
        }
    }
    return 0;
}

void continue_attack(object who)
{
    object killedBy;
    int attack, toattack;
    object EWHO, * attackers;

    if (!objectp(who)) {
        return;
    }
    if (!objectp(EWHO = environment(who)) || who->query_ghost()) {
        return;
    }
    if (who->is_player() && !interactive(who) && !who->query_property("bounty hunter")) {
        return;
    }
    attackers = who->query_attackers();
    who->check_death();
    if (who->query_dead()) {
        who->adjust_combat_mapps("static vars", "dead", 0);
        who->die((attackers && killedBy ? killedBy : 0));
        if (objectp(who)) {
            who->cease_all_attacks();
        }
        return;
    }
    //if((0) && !any_attack) casting = 0; // ???
    if (!who->query_combat_mapps("vars", "any attack") && !who->query_combat_mapps("static vars") &&
        !sizeof(attackers) && (userp(who) || !sizeof(who->query_combat_mapps("arrays", "atnames")))) {
        return;
    }

    if (!who->query_wimped() || userp(who)) {
        if (!who->clean_up_attackers()) {
            return;
        }
    }

    if (((int)who->query_hp() * 100) / (int)who->query_max_hp() < who->query_wimpy()) {
        if (time() > (int)who->query_property("running_away_time")) {
            who->remove_property("running_away_time");
            who->set_property("running_away_time", time() + 2);
            who->run_away();
            return;
        }
    }
    who->set_wimped(0);
    attack = who->query_combat_mapps("static vars", "attack");
    toattack = who->query_combat_mapps("static vars", "toattack");
    attack++;
    if (attack > toattack - 1) {
        attack = 0;
        if (!who->query_paralyzed()) {
            if (who->do_i_win()) {
                EWHO->add_combatant(who);
            }
        }else {
            if (objectp(who)) {
                message("my_combat", who->query_paralyze_message(), who);
            }
        }
    }
    who->adjust_combat_mapps("static vars", "attack", attack);
    return;
}

int doPkill(object who)
{
    int i, j;
    object* attackers;
    if (!objectp(who)) {
        return 0;
    }
    if (who->query_property("to die")) {
        return 0;
    }
    if (who->query_hp() < (-20 * who->query_max_hp())) {
        return 0;
    }
    attackers = who->query_attackers();
    j = sizeof(attackers);
    for (i = 0; i < j; i++) {
        if (!objectp(attackers[i])) {
            continue;
        }
        attackers[i]->remove_attacker(who);
    }
    who->cease_all_attacks();
    who->set_hidden(0);
    who->set_magic_hidden(0);
    tell_object(who, "%^BOLD%^%^RED%^You have fallen unconscious due to egregious wounds.");
    if (objectp(environment(who))) {
        tell_room(environment(who), "%^BOLD%^%^RED%^" + who->QCN + " falls unconscious due to horrible wounds.", who);
    }
    return 1;
}

varargs int check_death(object who, object pot)
{
    object* death, magi, * newattackers, killedBy;
    int xxx, exp, i, minions, falling;
    object spellthing, * attackers;
    if (!objectp(who)) {
        return 0;
    }
    if (who->query_combat_mapps("static vars", "dead")) {
        return 1;
    }
    falling = who->query_property("falling");                                 // These lines added by
    if (userp(who) && who->query_hp() < 1 && (falling < time() - (__COMBAT_SPEED__ * 3) + 4)) { // Lujke to stop people
        // dying while
        // waiting for kits to hit
        who->set_property("falling", time());                             //
        return 0;                                                          //
    }                                                                      //
    if (who->query_hp() < 1 && !who->query_ghost()) {
        who->remove_property("falling");        // This also added by Lujke as above
        if (wizardp(who) && !who->query_killable()) {
            who->set_hp((int)who->query_max_hp());
            tell_object(who, "You are immortal and cannot die.");
            return 0;
        }
        attackers = who->query_attackers();
        if (objectp(pot)) {
            attackers += ({ pot });
        }
        if (sizeof(attackers)) {
            if (!who->is_player() && !who->is_townsman()) {
                newattackers = attackers;
                for (i = 0; i < sizeof(attackers); i++) {
                    if (!objectp(attackers[i])) {
                        newattackers -= ({ attackers[i] }); continue;
                    }
                    if (attackers[i]->query_property("minion")) {
                        newattackers -= ({ attackers[i] }); minions = 1; continue;
                    }
                    if (attackers[i]->query_property("spell") && !attackers[i]->query_property("keep exp")) {
                        newattackers -= ({ attackers[i] });
                        spellthing = attackers[i]->query_property("spell");
                        if (!objectp(spellthing)) {
                            continue;
                        }
                        magi = spellthing->query_caster();
                        if (member_array(magi, newattackers) == -1 && objectp(magi)) {
                            newattackers += ({ magi });
                        }
                        continue;
                    }else if (attackers[i]->is_spell()) {
                        newattackers -= ({ attackers[i] });
                        spellthing = attackers[i];
                        magi = spellthing->query_caster();
                        if (member_array(magi, newattackers) == -1 && objectp(magi)) {
                            newattackers += ({ magi });
                        }
                    }
                    continue;
                }
                attackers = newattackers;
                who->adjust_combat_mapps("arrays", "attackers", attackers);
                if (sizeof(attackers) && objectp(attackers[0])) {
                    attackers[0]->add_kill((string)who->query_name());
                    if (avatarp(attackers[0]) && attackers[0]->query_disguised()) {
                        if (userp(attackers[0])) {
                            who->add_death((string)attackers[0]->getParsableName());
                        }else {
                            who->add_death((string)attackers[0]->query_vis_name());
                        }
                    }           else {
                        if (userp(attackers[0])) {
                            who->add_death((string)attackers[0]->getParsableName());
                        }else {
                            who->add_death((string)attackers[0]->query_name());
                        }
                    }
                }
                for (i = 0; i < sizeof(attackers); i++) {
                    if (!objectp(attackers[i])) {
                        continue;
                    }
                    if (!objectp(environment(who)) || environment(who)->query_property("arena")) {
                        continue;
                    }
                    exp = who->query_exp();
                    attackers[i]->set_property("GainedExpFrom", who);
                    attackers[i]->doExp(attackers[i], exp, sizeof(attackers) + minions);
                    attackers[i]->remove_property("GainedExpFrom");
                    continue;
                }
                if (!sizeof(attackers)) {
                    return 1;
                }
                killedBy = attackers[0];
                who->set("killedBy", killedBy);
                who->adjust_combat_mapps("static vars", "dead", 1);
                return 1;
            }
            if (killedBy = who->isPkill()) {
                who->set("killedBy", killedBy);
                if (who->doPkill()) {
                    return 1;
                }
            }
            newattackers = attackers;
            for (i = 0; i < sizeof(attackers); i++) {
                if (!objectp(attackers[i])) {
                    newattackers -= ({ attackers[i] }); continue;
                }
                if (attackers[i]->query_property("minion")) {
                    newattackers -= ({ attackers[i] }); minions = 1; continue;
                }
                if (attackers[i]->query_property("spell") && !attackers[i]->query_property("keep exp")) {
                    newattackers -= ({ attackers[i] });
                    spellthing = attackers[i]->query_property("spell");
                    if (!objectp(spellthing)) {
                        continue;
                    }
                    magi = spellthing->query_caster();
                    if (member_array(magi, newattackers) == -1) {
                        newattackers += ({ magi });
                    }
                }
                continue;
            }
            attackers = newattackers;
            who->adjust_combat_mapps("arrays", "attackers", attackers);
            if (sizeof(attackers) && objectp(attackers[0])) {
                attackers[0]->add_kill((string)who->query_name());
                if (avatarp(attackers[0]) && attackers[0]->query_disguised()) {
                    if (userp(attackers[0])) {
                        who->add_death((string)attackers[0]->getParsableName());
                    }else {
                        who->add_death((string)attackers[0]->query_vis_name());
                    }
                }else {
                    if (attackers[0]->is_spell()) {
                        if (userp(attackers[0]->query_caster())) {
                            who->add_death((string)attackers[0]->query_caster()->getParsableName());
                        }else {
                            who->add_death((attackers[0]->query_caster())->QCN);
                        }
                    }
                    if (userp(attackers[0])) {
                        who->add_death((string)attackers[0]->getParsableName());
                    }else {
                        who->add_death((string)attackers[0]->query_name());
                    }
                }
                xxx = sizeof(death = all_inventory(attackers[0]));
                while (xxx--) {
                    death[xxx]->notify_kill(TO);
                }
                if (!objectp(killedBy) && attackers[0]->query_property("spell") && objectp(attackers[0]->query_property("spell"))) {
                    killedBy = attackers[0]->query_property("spell")->query_caster();
                }
                if (!objectp(killedBy)) {
                    killedBy = attackers[0];
                    who->set("killedBy", killedBy);
                }
            }

            if (who->is_townsman()) {
                for (i = 0; i < sizeof(attackers); i++) {
                    if (!objectp(attackers[i])) {
                        continue;
                    }
                    if (objectp(environment(who)) && environment(who)->query_property("arena")) {
                        continue;
                    }
                    exp = who->query_exp();
                    attackers[i]->set_property("GainedExpFrom", who);
                    attackers[i]->doExp(attackers[i], exp, sizeof(attackers) + minions);
                    attackers[i]->set_property("GainedExpFrom", who);
                    continue;
                }
            }
            if (who->isPkill()) {
                log_file("player/kills", "       " + capitalize(who->query_name()) + " was killed by " + capitalize(killedBy->query_name()) + "\n");
                who->set("no pk", 1);
                who->set("just_been_pkilled", 1);
                who->set_pk_death_flag();
                who->perma_death();
                who->remove_property("to die");
            }
            who->adjust_combat_mapps("static vars", "dead", 1);
            return 1;
        }
    }
    return 0;
}

void doExp(object who, int how, int split)
{
    int max, per;
    if (!objectp(who)) {
        return;
    }

    //how = how/split; // already getting split in the party daemon, so was getting split again

    if (who->query_max_level()) {
        if (max = (int)who->query_max_level()) {
            if (max < (int)who->query_lowest_level()) {
                // 5% if they are 5 levels higher than the max level
                if ((int)who->query_lowest_level() - max > 4) {
                    per = 5;
                }else {
                    per = (int)who->query_lowest_level() - max;
                    switch (per) {
                    case 4:  per = 20; break;

                    case 3:  per = 40; break;

                    case 2:  per = 60; break;

                    case 1:  per = 80; break;

                    default: per = 5;  break;
                    }
                }
                if (per == 0) {
                    how = 0;
                }else {
                    how = to_int(how * (per * 0.01));
                }
            }
        }
    }
    who->add_exp(how);
    return;
}

int kill_ob(object who, object victim, int which)
{
    object* borg_people, * inven, EWHO, * attackers;
    int i, initiative, k, myinit;
    string* pkill;

    if (!objectp(who)) {
        return 0;
    }
    if (!objectp(EWHO = environment(who))) {
        return 0;
    }
    if (!objectp(victim)) {
        return 0;
    }
    if (!objectp(environment(victim))) {
        return 0;
    }
    if ((base_name(EWHO) == "/d/shadowgate/void") || (base_name(environment(victim)) == "/d/shadowgate/void")) {
        return 0;
    }
    if (victim == who) {
        return 0;
    }
    if (!who->ok_to_kill(victim)) {
        return 0;
    }

    if (!sizeof(who->query_attackers())) {
        who->init_attack();
    }
    pkill = ({});
    borg_people = (object*)victim->query_attackers();
    if (!borg_people) {
        borg_people = ({});
    }
    if (!(environment(victim)->query_property("arena")) && (!who->query_property("safe arena") || !victim->query_property("safe arena"))) {
        if (member_array(who, borg_people) == -1) {
            if (interactive(who) && interactive(victim) || (victim->is_townsman()) || who->is_townsman()) {
                if (!wizardp(who) && !wizardp(victim)) {
                    if (PO->is_spell()) {
                        if (objectp(PO->query_caster())) {
                            if (member_array(PO->query_caster(), borg_people) == -1) {
                                log_file("killers", " ##" + capitalize((PO->query_caster())->query_name()) + " "
                                         "attacked " + capitalize(who->query_name()) + " at " + ctime(time()) + ".\n");
                                if (!avatarp(PO->query_caster())) {
                                    KILLING_D->check_actions(PO->query_caster(), who);
                                }
                            }
                        }else {
                            log_file("killers", " ##" + capitalize(who->query_name()) + " attacked "
                                     "" + capitalize(victim->query_name()) + ".\n");
                            if (!avatarp(who)) {
                                KILLING_D->check_actions(who, victim);
                            }
                        }
                    }else {
                        log_file("killers", "  ##" + capitalize(who->query_name()) + " attacked "
                                 "" + capitalize(victim->query_name()) + ".\n");
                        if (!avatarp(who)) {
                            KILLING_D->check_actions(who, victim);
                        }
                    }
                }
            }
        }
    }
    if (objectp(victim)) {
        victim->check_death();
    }
    if (interactive(who) && !userp(victim)) {
        inven = all_inventory(EWHO);
        inven = filter_array(inven, "classic_swarm", FILTERS_D);
        for (i = 0; i < sizeof(inven); i++) {
            if (!objectp(inven[i])) {
                continue;
            }
            inven[i]->add_attacker(who);
            EWHO->add_combatant(inven[i]);
            continue;
        }
    }

    /* changed from 0 to 1 to faciliate PK patch */
    if (who->query_attacked()) {
        return 1;
    }
    attackers = who->query_attackers();
    i = member_array(victim, attackers);
    if ((i == -1) && (!which)) {
        // roll surprise and stuff
        // assume we won
        myinit = who->query_initiative();
        if ((string)who->query_race() == "human" && (string)who->query("subrace") == "tsarven") {
            myinit -= 1;
        }
        if (myinit < (int)victim->query_initiative()) {
            who->set_toattack(2);
            victim->set_toattack(4);
        }else {
            who->set_attack(4);
            victim->set_toattack(2);
        }
        victim->add_attacker(who);
        EWHO->add_combatant(victim);
    }
    if (i > -1) {
        //tell_object(who, "You are already attacking "+victim->QCN+"!\n"); // don't really need this, it looks funny when some feats use it.
        return 1;
    }
    who->add_attacker(victim);
    EWHO->add_combatant(who);
    who->adjust_combat_mapps("vars", "any attack", 1);
    return 1;
}

int valid_object(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    return 1;
}

int clean_up_attackers(object who)
{
    object* hunters_tmp = ({}), * attackers_tmp = ({}), * full_tmp, ob, * uncon_att = ({}), EWHO;
    int i, tmp;
    string* pkillsatt, * pkillsvic, * atnames;

    if (!objectp(who)) {
        return 0;
    }
    if (!objectp(EWHO = environment(who))) {
        return 0;
    }

    full_tmp = who->query_combat_mapps("arrays", "hunters") + who->query_combat_mapps("arrays", "attackers");
    atnames = who->query_combat_mapps("arrays", "atnames");

    if (interactive(who)) {
        pkillsatt = who->query_pkilled();
        if (!pointerp(pkillsatt)) {
            pkillsatt = ({});
        }
    }
    for (i = 0, tmp = sizeof(full_tmp); i < tmp; i++) {
        if (full_tmp[i] == who || !objectp(full_tmp[i])) {
            continue;
        }
        if (member_array(full_tmp[i], (attackers_tmp + hunters_tmp)) != -1) {
            continue;
        }
        if (!objectp(environment(full_tmp[i]))) {
            continue;
        }
        if (environment(full_tmp[i]) != EWHO) {
            if (interactive(who) && interactive(full_tmp[i])) {
                continue;
            }
            hunters_tmp += ({ full_tmp[i] });
            continue;
        }
        if (full_tmp[i]->query_ghost()) {
            atnames -= ({ full_tmp[i]->query_name() });
            continue;
        }
        if (interactive(full_tmp[i]) && interactive(who)) {
            pkillsvic = full_tmp[i]->query_pkilled();
            if (!pointerp(pkillsvic)) {
                pkillsvic = ({});
            }
            if (member_array(full_tmp[i]->query_name(), pkillsatt) != -1) {
                pkillsatt = pkillsatt + ({ full_tmp[i]->query_name() });
            }
            if (member_array(who->query_name(), pkillsvic) != -1) {
                pkillsvic = pkillsvic + ({ who->query_name() });
            }
        }
        if (!full_tmp[i]->query_bound() && !full_tmp[i]->query_unconscious()) {
            attackers_tmp += who->doProtection(full_tmp[i]);
        }else {
            uncon_att += ({ full_tmp[i] });
        }
    }

    if (!userp(who) && !EWHO->query_property("arena")) {
        for (i = 0, tmp = sizeof(atnames); i < tmp; i++) {
            if (ob = present(atnames[i], EWHO)) {
                attackers_tmp += ({ ob });
            }
            continue;
        }
    }

    if (sizeof(attackers_tmp) == 0) {
        for (i = 0, tmp = sizeof(uncon_att); i < tmp; i++) {
            attackers_tmp += who->doProtection(uncon_att[i]);
        }
    }
    attackers_tmp = distinct_array(attackers_tmp);

    attackers_tmp -= ({ 0 });
    attackers_tmp = filter_array(attackers_tmp, "valid_object", TO);
    hunters_tmp -= ({ 0 });
    for (i = 0; i < sizeof(attackers_tmp); i++) {
    }
    who->adjust_combat_mapps("arrays", "attackers", attackers_tmp);
    who->adjust_combat_mapps("arrays", "hunters", hunters_tmp);
    who->adjust_combat_mapps("vars", "any attack", sizeof(attackers_tmp));
    who->adjust_combat_mapps("static vars", "hunting", sizeof(hunters_tmp));
    return who->query_combat_mapps("vars", "any attack");
}
