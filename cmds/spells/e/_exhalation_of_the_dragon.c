//single-target direct damage spell
//lower damage than lightning bolt because of the secondary effect
//Damage may need to be adjusted depending on results. ~Circe~ 11/2/15

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

#define MYTYPES ({ "white", "bronze", "red", "silver", "random" })

inherit SPELL;

int damage;
string target_limb, savetype;

void dest_effect();
void more_fire();


void create()
{
    ::create();
    set_spell_name("exhalation of the dragon");
    set_spell_sphere("psychokinesis");
    set_spell_level(([ "psywarrior" : 3 ]));
    set_syntax("cast CLASS exhalation of the dragon on TARGET as <type>");
    set_description("This power will allow the psionic character to manifest "
        "the energy of a chosen dragon type, dealing damage and producing a "
        "secondary effect. The valid types are: white, bronze, red, silver, and random.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
    set_components(([ "psywarrior" : ([ "clear quartz" : 1, ]), ]));
    set_save("reflex");
}


string query_cast_string()
{
        return caster->QCN+" inhales deeply, breathing in energy and air.";
}


void spell_effect(int prof)
{
    int mynum, mylevel;
    string thetarg, realname, args, mytype, mycolor, savetype;
    damage = 0;

    if (!arg)
    {
        tell_object(caster,"You need to specify a target and a type for this power!");
        dest_effect();
        return;
    }

    if (sscanf(arg,"%s as %s",thetarg,args) != 2)
    {
        tell_object(CASTER,"You need to specify both your target and the type of dragon.");
        dest_effect();
        return;
    }

    if(thetarg == "attacker")
    {
        target = caster->query_current_attacker();
        if(!objectp(target))
        {
            tell_object(caster,"You don't see an attacker here!");
            dest_effect();
            return;
        }
    }
    else
    {
        target = present(thetarg,environment(caster));
        if(!objectp(target))
        {
            if(userp(caster)) { realname = caster->realName(thetarg); }
            else { realname = thetarg; }
            if(avatarp(caster) && !objectp(target)) { realname = thetarg; } // it was screwing out on imms.
            target = present(realname,place);
            if(!objectp(target))
            {
                tell_object(caster,"You don't see "+thetarg+" here!");
                dest_effect();
                return;
            }
            dest_effect();
            return;
        }
    }

    if(environment(caster) != environment(target))
    {
        tell_object(caster,"Your target has left your range.\n");
        dest_effect();
        return;
    }

    if(member_array(args,MYTYPES) == -1)
    {
        tell_object(caster,"That is not a valid type!");
        dest_effect();
        return;
    }

    spell_successful();

    if(args == "random")
    {
        mynum = random(4);
        args = MYTYPES[mynum];
    }

    switch(args)
    {
    case "white":

        mytype = "%^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^te dr%^RESET%^a%^BOLD%^gon";
        mycolor = "%^BOLD%^%^WHITE%^wh%^RESET%^i%^BOLD%^te";
        savetype = "cold";
        break;

    case "bronze":

        mytype = "%^RESET%^%^ORANGE%^br%^YELLOW%^o%^RESET%^%^ORANGE%^nze d%^YELLOW%^r%^RESET%^%^ORANGE%^ag%^YELLOW%^o%^RESET%^%^ORANGE%^n";
        mycolor = "%^RESET%^%^ORANGE%^br%^YELLOW%^o%^RESET%^%^ORANGE%^nze";
        savetype = "electricity";
        break;

    case "red":

        mytype = "%^RESET%^%^RED%^r%^BOLD%^e%^RESET%^%^RED%^d d%^BOLD%^r%^RESET%^%^RED%^ag%^YELLOW%^o%^RESET%^%^RED%^n";
        mycolor = "%^RESET%^%^RED%^cr%^BOLD%^i%^RESET%^%^RED%^ms%^YELLOW%^o%^RESET%^%^RED%^n";
        savetype = "fire";
        break;

    default:

        mytype = "%^RESET%^si%^BOLD%^l%^RESET%^ve%^BOLD%^r %^RESET%^dr%^BOLD%^a%^RESET%^g%^BOLD%^o%^RESET%^n";
        mycolor = "%^RESET%^si%^BOLD%^l%^RESET%^ve%^BOLD%^r";
        savetype = "sonic";
        break;
    }

    mylevel = clevel;

    damage = sdamage;

    target_limb = target->return_target_limb();

    tell_object(caster,"%^RESET%^%^CYAN%^You channel the might of the "+mytype+" %^RESET%^%^CYAN%^"
        "and breathe forth a line of "+mycolor+" energy%^RESET%^%^CYAN%^ at "+target->QCN+"!%^RESET%^");
    tell_object(target,"%^RESET%^%^CYAN%^"+caster->QCN+"'s visage transforms into that of a "+mytype+" %^RESET%^%^CYAN%^"
        "as "+caster->QS+" breathes forth a line of "+mycolor+" energy%^RESET%^%^CYAN%^ at you!%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+"'s visage transforms into that of a "+mytype+" %^RESET%^%^CYAN%^"
        "as "+caster->QS+" breathes forth a line of "+mycolor+" energy%^RESET%^%^CYAN%^ at "+target->QCN+"!%^RESET%^",({caster, target}));

    if(do_save(target,0))
    {
        damage = damage/2;
        tell_object(caster,"%^RESET%^%^CYAN%^The "+mycolor+" energy %^RESET%^%^CYAN%^"
            "strikes "+target->QCN+", but "+target->QS+" resists the full force of its might!%^RESET%^");
        tell_object(target,"%^RESET%^%^CYAN%^The "+mycolor+" energy %^RESET%^%^CYAN%^"
            "strikes you, but you resist the full force of its might!%^RESET%^");
        tell_room(place,"%^RESET%^%^CYAN%^The "+mycolor+" energy %^RESET%^%^CYAN%^"
            "strikes "+target->QCN+", but "+target->QS+" resists the full force of its might!%^RESET%^",({target, caster}));
        damage_targ(target, target_limb, damage, savetype);
        dest_effect();
        return;
    }
    else
    {
        tell_object(caster,"%^BOLD%^%^CYAN%^The line of "+mycolor+" energy %^BOLD%^%^CYAN%^"
            "strikes "+target->QCN+" with an audible crack, unleashing the full force of "
            "your attack!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^The line of "+mycolor+" energy %^BOLD%^%^CYAN%^"
            "strikes you with an audible crack, unleashing the full force of "
            ""+caster->QCN+"'s attack!%^RESET%^");
        tell_room(place,"%^BOLD%^%^CYAN%^The line of "+mycolor+" energy %^BOLD%^%^CYAN%^"
            "strikes "+target->QCN+" with an audible crack, unleashing the full force of "
            ""+caster->QCN+"'s attack!%^RESET%^",({caster,target}));
        damage_targ(target, target_limb, damage, savetype);

        switch(args)
        {
        case "white":

            tell_object(target,"%^BOLD%^%^WHITE%^The wh%^RESET%^i%^BOLD%^te "
                "energy freezes the ground beneath you, causing you to slip!%^RESET%^");
            tell_room(place,"%^BOLD%^%^WHITE%^The wh%^RESET%^i%^BOLD%^te energy "
                "freezes the ground beneath "+target->QCN+", causing "+target->QCN+" "
                "to slip!%^RESET%^",target);
            target->set_tripped(1,"You are struggling to regain your footing!");
            break;

        case "bronze":

            tell_object(target,"%^RESET%^%^ORANGE%^The %^RESET%^%^ORANGE%^br"
                "%^YELLOW%^o%^RESET%^%^ORANGE%^nze energy erupts in a blinding "
                "%^YELLOW%^flash%^RESET%^%^ORANGE%^, leaving you blinking in panic!%^RESET%^");
            tell_room(place,"%^RESET%^%^ORANGE%^The %^RESET%^%^ORANGE%^br%^YELLOW%^o"
                "%^RESET%^%^ORANGE%^nze energy erupts in a blinding %^YELLOW%^flash"
                "%^RESET%^%^ORANGE%^, leaving "+target->QCN+" blinking in panic!%^RESET%^",target);
            if(target->query_blind() || target->query_temporary_blinded()) { break; }
            else { target->set_temporary_blinded(roll_dice(2,4)); }
            break;

        case "red":

            tell_object(target,"%^RESET%^%^RED%^The fi%^YELLOW%^e%^RESET%^%^RED%^ry "
            "ene%^BOLD%^r%^RESET%^%^RED%^gy scorches your flesh, leaving you "
            "writhing in pain!%^RESET%^");
            tell_room(place,"%^RESET%^%^RED%^The fi%^YELLOW%^e%^RESET%^%^RED%^ry "
            "ene%^BOLD%^r%^RESET%^%^RED%^gy scorches "+target->QCN+"'s flesh, "
            "leaving "+target->QO+" writhing in pain!%^RESET%^",target);
            call_out("more_fire",ROUND_LENGTH);
            break;

        //because the silver dragon's attack is technically a fear-based/mind-affecting spell, it requires extra checks
        default:

            if(race_immunity_check(target, "fear silent"))
            {
                if((string)target->query_race() == "human" && (string)target->query("subrace") == "attayan")
                {
                    tell_object(target,"%^BOLD%^%^WHITE%^You feel the energy of the "
                        "%^RESET%^%^si%^BOLD%^l%^RESET%^ve%^BOLD%^r "
                        "%^RESET%^dr%^BOLD%^a%^RESET%^gon %^BOLD%^breath trying to "
                        "take hold of your mind, but such is your fearless nature "
                        "that you manage to shake it off!%^RESET%^");
                    tell_room(place,"%BOLD%^%^WHITE%^You see "+target->QCN+" fight off the "
                        "secondary effects of the %^RESET%^%^si%^BOLD%^l%^RESET%^ve%^BOLD%^r "
                        "%^RESET%^dr%^BOLD%^a%^RESET%^gon %^BOLD%^breath!%^RESET%^",target);
                }
                else
                {
                    tell_object(target, "%^BOLD%^%^WHITE%^You fight off the secondary effects "
                        "of the %^RESET%^%^si%^BOLD%^l%^RESET%^ve%^BOLD%^r %^RESET%^dr%^BOLD%^a"
                        "%^RESET%^gon %^BOLD%^breath!%^RESET%^");
                    tell_room(place,"%BOLD%^%^WHITE%^You see "+target->QCN+" fight off the "
                        "secondary effects of the %^RESET%^%^si%^BOLD%^l%^RESET%^ve%^BOLD%^r "
                        "%^RESET%^dr%^BOLD%^a%^RESET%^gon %^BOLD%^breath!%^RESET%^",target);
                }
                target->add_attacker(caster);
                dest_effect();
                return;
            }

            if(mind_immunity_damage(target, "default"))
            {
                target->add_attacker(caster);
                damage_targ(target, target->return_target_limb(), sdamage/2,"untyped");
                spell_successful();
                dest_effect();
                return;
            }

            tell_object(target,"%^BOLD%^%^WHITE%^The breath of the "+mytype+" %^BOLD%^"
                "%^WHITE%^hits you with unexpected intensity, filling you with fear!%^RESET%^");
            tell_room(place,"%^BOLD%^%^WHITE%^As the breath of the "+mytype+" %^BOLD%^"
                "%^WHITE%^hits "+target->QCN+", "+target->QS+" shakes in terror!%^RESET%^");
            target->set_paralyzed((15+random(20)),"You cannot contain your fear to do that!");
            break;
       }
       dest_effect();
       return;
    }
}


void more_fire()
{
    death_check(target);
    if(!objectp(target))
    {
        dest_effect();
        return;
    }
    tell_object(target,"%^RESET%^%^RED%^The f%^BOLD%^i%^RESET%^%^RED%^re flares again, scorching your skin!%^RESET%^");
    tell_room(environment(target),"%^RESET%^%^RED%^F%^BOLD%^i%^RESET%^%^RED%^re flares on "
        ""+target->QCN+", scorching "+target->QP+" skin!%^RESET%^",target);
    define_base_damage(-2);
    damage_targ(target, target_limb, sdamage, savetype);
    if(!target && objectp(TO))
    {
        TO->remove();
        return;
    }
    dest_effect();
}


void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
