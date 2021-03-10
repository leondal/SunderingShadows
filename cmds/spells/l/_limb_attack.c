// Pator@ShadowGate
// Jan 10 1996

#include <priest.h>

inherit SPELL;

string pick(string *limbs,string *wielding, int which, int number);
int calc_damage(int clevel);
string d_string(int amount);
void damage_target(object priest, object victim, string limb_hit, int wound);

string query_cast_string() {
    string cast;

    if (interactive(CASTER)) {
      cast = YOU+" prays feverishly to "+caster->QP+" deity for power!!\n";
    } else {
      cast = YOU+" calls feverishly to "+caster->QP+" deity for power!!\n";
    }
    return cast;
}

void create() {
    ::create();
    set_author("pator");
    set_spell_name("limb attack");
    set_spell_level(([ "cleric" : 2 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS limb attack on TARGET");
    set_description("This spell will attack some random limb of the target.  You will try to tear that limb off, so your "
"strength is very important here as is your casting level for extra damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_immunities( ({ "spell_immunity"}) );
}

int preSpell() {
    object *armour;
    int j, i;
    if (environment(target)!=environment(caster)) {
        tell_object(caster,"%^BOLD%^Your target has escaped your grasp!");
        return 0;
    }

    armour = caster->query_armour("left hand");
    j = sizeof(armour);
    for (i=0;i<j;i++) {
        if ((string)armour[i]->query_type() == "shield"
        || (string)armour[i]->query_type() == "thiefshield") {
            tell_object(caster,"You need to use all your hands to limb attack, remove your shield.\n");
            return 0;
        }
    }
    armour = caster->query_armour("right hand");
    j = sizeof(armour);
    for (i=0;i<j;i++) {
        if ((string)armour[i]->query_type() == "shield"
        || (string)armour[i]->query_type() == "thiefshield") {
            tell_object(caster,"You need to use all your hands to limb attack, remove your shield.\n");
            return 0;
        }
    }
    if (!caster->ok_to_kill(target)) {
        tell_object(caster,"Supernatural forces prevent your attack.");
        return 0;
    }

    return 1;
}


spell_effect(int prof) {
    string *limbs,*wielders,limb,message;
    int which_limb,clevel,damage,number,i,j;

   // if ((caster->is_class("cleric")&&sizeof((string *)caster->query_classes())==1)?(int)caster->Thaco(0,target,0) <= roll_dice(1,20)+5:(int)caster->Thaco(0,target,0) <= roll_dice(1,20)) 
    
    if(thaco(target,5))
    {
        if (living(target)) 
        {
            limbs = target->query_limbs();
            wielders = target->query_wielding_limbs();
            number = sizeof(limbs);
            number -= sizeof(wielders);
            which_limb = random(number);
            limb = pick(limbs, wielders, which_limb, number);
            damage  = calc_damage(clevel);
            message = d_string(damage);
            tell_object(caster,"%^BOLD%^%^RED%^You hurt "+HIM+"'s "+limb+" "+message+"you jerk at it!%^RESET%^");
            tell_object(target,"%^BOLD%^%^RED%^"+YOU+" hurts your "+limb+" "+message+MY_PERS+" jerks at it!%^RESET%^");
              tell_room(HERE,"%^BOLD%^%^RED%^"+YOU+" hurts "+HIM+"!!\n"+capitalize(caster->QS)+" jerks at "+HIS+" "+limb+"!%^RESET%^",({ caster, target}) );
              damage_targ(target,limb,damage,"divine");
            spell_successful();
        } else {
            tell_object(caster,"%^CYAN%^You fail in attacking "+HIM+"!");
            tell_object(target,"%^CYAN%^"+YOU+" fails in attacking you!!");
            tell_room(HERE,"%^CYAN%^"+YOU+" fails in attacking "+HIM+"!!",({ caster, target}) );
        }
    } 
    else
    {
        tell_object(caster,"%^BOLD%^You fail to take hold of a limb.");
    }
    dest_effect();
}


void dest_effect() 
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

// Pick a limb from the array limbs and look if it isn't a wielding
// limb. If it is not, return it. If it is use another limb.
string pick(string *limbs,string *wielding, int which, int number) {
    string limb;

    if ( which > number )
        which = 0;
    limb = limbs[which];
    if (member_array(limb,wielding) == -1)
        return limb;
    else {
        which += 1;
        return pick(limbs, wielding, which,number);
    }
}

// Compute the damage to the limb
int calc_damage(int clevel) {
    int temp,power,damage;

    power = caster->query_stats("strength");
    temp = ( ( 100 - ((25-power)*4) ) - 1 );
    if (clevel < 6) clevel = 6;
    if (clevel > 40 && !wizardp(caster)) clevel = 40;
    temp = temp * clevel;
    temp = to_int( temp / 10 );
    switch (temp) {
    case  0..25 : damage = 15;
        break;
    case 26..40 : damage = 25;
        break;
    case 41..60 : damage = 35;
        break;
    case 61..75 : damage = 45;
        break;
    case 76..99 : damage = 55;
        break;
    case 100..124 : damage = 75;
        break;
    case 125..149 : damage = 85;
        break;
    case 150..174 : damage = 95;
        break;
    case 175..199 : damage = 115;
        break;
    default: damage = temp-15;
        break;
    }
    damage = (damage/2)+random(damage/2);
    return damage;
}

string d_string(int amount) {
    string damage;

    switch (amount) {
    case  0..25 : damage = "badly as ";
        break;
    case 26..40 : damage = "very badly as ";
        break;
    case 41..60 : damage = "severly as ";
        break;
    case 61..75 : damage = "heavily as ";
        break;
    case 76..99 : damage = "until it almost comes off as ";
        break;
    default     : damage = "so that it is useless as ";
        break;
    }
    return damage;
}

/*
void damage_target(object priest, object victim, string hit_limb, int wound) {
    int nokill;
    string *limbs;

    nokill=1;
    if (!victim||!objectp(victim))
        return 1;
    if (wound < 0) {
        victim->do_damage(hit_limb,wound);
        return;
    }
    if (!objectp(priest)) return;
    if (priest->ok_to_kill(victim))
        nokill=0;
    if (victim != priest && !nokill) {
        if (present( victim, environment(priest))) {
            spell_kill(victim, priest);
            victim->add_attacker(priest);
        } else {
            victim->add_attacker(TO);
            victim->check_death();
            victim->remove_attacker(TO);
        }
    }
    if (!nokill)
        victim->set_toattack(1);
    if (victim->query_property("magic resistance") || nokill)
        if ((victim->query_property("magic resistance") >= random(100) + 1) || nokill) {
            tell_object(victim,"%^BOLD%^%^YELLOW%^You partially resist "+priest->QCN+"'s magic.");
            if (present(priest,environment(victim)))
                tell_object(priest,"%^BOLD%^%^YELLOW%^"+victim->QCN+" partially resists your magic.");
              tell_room(environment(victim),"%^BOLD%^%^YELLOW%^"+priest->QCN+" is partially resisted by "+victim->QCN+".",({ victim, priest}) );
            wound = wound/2;
        }
    limbs=victim->query_limbs();
    if (member_array(hit_limb,limbs,0) > 0)
        victim->do_damage(hit_limb, wound);
    else
        victim->do_damage(limbs[random(sizeof(limbs))], wound);
    if (victim)
        victim->continue_attack();
    return 1;
}*/