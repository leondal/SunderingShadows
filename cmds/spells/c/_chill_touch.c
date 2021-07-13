//      Chill Touch
//fixed switch so versatile arcanist actually manipulates element.
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

string target_limb, element;


create()
{
    ::create();
    set_spell_name("chill touch");
    set_spell_level(([ "mage" : 1, "oracle" : 1, "magus" : 1 ]));
    set_spell_sphere("necromancy");
    set_mystery("reaper");
    set_syntax("cast CLASS chill touch on TARGET");
    set_description("By casting this spell, your hand will flare up with a blue aura.  You can touch your enemy with that "
        "hand and, if the target doesn't make his save and avoid your touch, you will inflict a small amount of damage.  "
        "Furthermore, the target will be slightly weakened until a certain length of time runs out. A versatile arcanist can "
        "manipulate the base element of this spell.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}


string query_cast_string() { return caster->QCN+" utters a deathly chant."; }


spell_effect(int prof)
{
    string mycolor, myhue, myhue2, myfeeling, damtype;
    int bonus, roll;

    if(!objectp(caster) || !objectp(target))
    {
        target = 0;
        dest_effect();
        return;
    }

    target_limb = target->return_target_limb();

    bonus = 0;

    if (!present(target,environment(caster)))
    {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        target = 0;
        dest_effect();
        return;
    }

    element = (string)caster->query("elementalist");

    switch(element)
    {
    case "acid":
        mycolor = "%^GREEN%^";
        myhue = "sickly green";
        myhue2 = "sickly green glow";
        myfeeling = "burning pain";
        damtype = "acid";
        break;
    case "electricity":
        mycolor = "%^ORANGE%^";
        myhue = "static-charged";
        myhue2 = "charge of static";
        myfeeling = "sudden jolt";
        damtype = "electricity";
        break;
    case "fire":
        mycolor = "%^RED%^";
        myhue = "radiantly glowing";
        myhue2 = "radiant glow";
        myfeeling = "blazing pain";
        damtype = "fire";
        break;
    case "sonic":
        mycolor = "%^MAGENTA%^";
        myhue = "pulsing";
        myhue2 = "pulsing aura";
        myfeeling = "horrible throbbing";
        damtype = "sonic";
        break;
    default:
        element = "cold";
        mycolor = "%^CYAN%^";
        myhue = "bluish glowing";
        myhue2 = "bluish glow";
        myfeeling = "ghastly chill";
        damtype = "cold";
        break;
    }

    tell_object(caster,"%^BOLD%^"+mycolor+"Your hand starts to develop a "+myhue2+".");
    tell_room(place,"%^BOLD%^"+mycolor+caster->QCN+"'s hand starts to develop a "+myhue2+".",caster );

    /*===================================================================================
                                      FUNCTION EXPLAINATIONS
       for any touch attack spell the following will likely work

       roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);
       roll will be a 0 for a miss, a -1 for a dice roll of 1 which is a miss
       a 20 for a dice roll of 20 or the actual dice roll

       if(roll == -1 || !roll) {
            ...set what happens when the touch attack fails
       }
       else {
           ... set what happens when it lands
       }
       ARGUMENT descriptions =
       caster = person casting spell
       target = target of the spell
       1 = the attack number they are using for the hit bonus - for players there is a -2 bonus when dual wielding, though this is
       negated if they have the feats - otherwise it is -2 x this number to a max of -10 (I know not how tabletop works) - technically
       could set this number at anything, though anything more than 5 will have the same impact as 5 or anything less than 1 will be counted as 1

       bonus = a bonus to hit or a weapon - if it's an integer it gets added as a bonus to hit - if it is an object it adds the enchantment to the hit bonus

       0 = the debug object if this is set to someone it will show the dice roll, attack bonus, and AC + Ac Bonuses

       1 = a flag that designates this as a touch attack - the real difference is that it does not include
       AC from equipment - only dodge bonuses/dex bonuses

       PLEASE NOTE: This spell now checks for deflection - see explaination below.

       Though beyond the scope of this spell - it is possible to allow a deflection attempt - so that they deflect
       with their shield or with something like concealing amorpha
       this would be as simple as "/daemon/combat_d.c"->extra_hit_calcs(caster, target, weapon, limb)
       at present weapon && limb have no impact and are not required - will likely remain optional
       as the code adapts
       the function call to extra_hit_calcs() will return 0 if the deflect is
       successful or 1 if it fails - in the event of a 0 it will
       also tell the caster and the target that the spell/attack was deflected
       so in this case if we wanted to allow for a deflection attempt also
       after the following check we do simply do
       if(!"/daemon/combat_d.c"->extra_hit_calcs(caster, target) {
       TO->remove();
          return;
       }

       both the caster, target, and room will be notified that it was a deflection or miss
       based on concealing amorpha - there is currently no seperating the two, it checks
       for both - this could also be easily modified to allow for a flag that specifics which to check for
                                    END SAIDE'S ATTEMPT AT EXPLAINING
     ==================================================================================*/

    roll = BONUS_D->process_hit(caster, target, 1, bonus, 0, 1);

    if(!roll || roll == -1 && ! caster->query_property("spectral_hand"))
    {
        tell_object(caster,""+mycolor+"You try and touch "+target->QCN+"'s "+target_limb+" with a "+myhue+" hand, but miss!");
        tell_object(target,""+mycolor+caster->QCN+"'s "+myhue+" hand gropes for your "+target_limb+" unsuccessfully.");
        tell_room(place,""+mycolor+caster->QCN+" reaches out for "+target->QCN+"'s "+target_limb+" with a "+myhue+" hand and misses!", ({ caster, target}) );
        target = 0;
        dest_effect();
        return;
    }

    // I am adding in the chance to deflect - after reading touch
    // attacks allow for deflection attempts, size modifiers, and
    // dexterity bonuses not a perfect setup since in our world
    // shields deflect, in D&D they add to AC I believe - but close
    // enough IMHO and unique to us :D

    //Who is "I am"?.. That comment is not helfpful.  -- Il

    if(!"/daemon/combat_d.c"->extra_hit_calcs(caster, target))
    {
        target = 0;
        dest_effect();
        return;
    }

    tell_object(caster,"%^BOLD%^"+mycolor+"You reach out and touch "+target->QCN+"'s "+target_limb+" with your "+myhue+" hand.");
    tell_object(target,"%^BOLD%^"+mycolor+caster->QCN+" touches your "+target_limb+" with a "+myhue+" hand.\n%^WHITE%^A "+myfeeling+" runs through you, sapping your strength!");
    tell_room(place,"%^BOLD%^"+mycolor+caster->QCN+" reaches out and touches "+target->QCN+"'s "+target_limb+" with a "+myhue+" hand!\n%^WHITE%^All life and color seems drawn out of the limb!",({ caster, target}) );
    spell_successful();

    damage_targ(target, target_limb, sdamage , damtype );
    if (objectp(target))
    {
        stat_change(target,"strength",-1);
        target->set_property("spelled", ({TO}) );
        spell_duration = (clevel + roll_dice(1, 20) + bonus) * ROUND_LENGTH;
        set_end_time();
        call_out("dest_effect",spell_duration);
    }
    else
    {
        target = 0;
        dest_effect();
        return;
    }
}


void dest_effect()
{
    if(find_call_out("dest_effect") != -1) { remove_call_out("dest_effect"); }
    if(objectp(target))
    {
        stat_change(target,"strength",1);
        target->remove_property_value("spelled", ({TO}) );
        tell_room(environment(target),"%^ORANGE%^"+target->QCN+" loses "+target->QP+" pale complexion.", target);
        tell_object(target,"%^ORANGE%^The skeletal white color in your "+target_limb+" fades away.");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
