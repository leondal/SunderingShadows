// Disintegrate
#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void damage_stuff(object target);
int object_save(object obj);

void create() {
    ::create();
    set_author("ares");
    set_spell_name("disintegrate");
    set_spell_level(([ "mage" : 6, "magus" : 6, "cleric" : 6 ]));
    set_spell_sphere("invocation_evocation");
    set_domains(({"destruction"}));
    set_syntax("cast CLASS disintegrate on TARGET");
    set_damage_desc("force");
    set_description("This spell sends a powerful line of destructive energy at the target.  If the target resists, then "
"they are able to avoid most of the damage, but if the spell hits successfully, then the target suffers great damage and "
"the objects in his or her inventory may also be damaged.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_components(([
      "mage" : ([ "ruby dust" : 1, "powdered amber" : 2, ]),
    ]));
    set_save("fort");
}

string query_cast_string()
{
    tell_object(caster,"%^RED%^The world around you takes on a crimson"+
        " tone as you shout out your incantation.");
    tell_room(place,"%^BOLD%^%^RED%^"+caster->QCN+"'s eyes begin to glow crimson"+
        " as "+caster->QS+" shouts out an incantation.",caster);
    return "display";
}

void spell_effect(int prof)
{
    int check;

    if(!present(target,place))
    {
        tell_object(caster,""+target->QCN+" has left the area!");
        dest_effect();
        return;
    }

    tell_object(caster,"%^RED%^You growl with fury as you unleash a beam of pure destruction "
        "straight at "+target->QCN+"!");
    tell_object(target,"%^RED%^"+caster->QCN+" growls with fury as "+caster->QS+" unleashes "
        "a beam of pure destruction from "+caster->QP+" eyes at you!");
    tell_room(place,"%^RED%^"+caster->QCN+" growls with fury as "+caster->QS+" unleashes a beam "
        "of pure destruction from "+caster->QP+" eyes at "+target->QCN+"!",({caster,target}));

    if(random((int)target->query_stats("dexterity") + 1) < roll_dice(1,20)) { check = 1; }
    else { check = 0; }

/*
    if(!SAVING_D->saving_throw(target,"spell",0) && check)
*/
    if(!do_save(target))
    {
        tell_object(caster,"%^BOLD%^%^RED%^"+target->QCN+" fails to escape the path of your "
            "terrible spell and is hit by the full force of its destructive power!");
        tell_object(target,"%^BOLD%^%^RED%^You are unable to avoid the spell cast by "+caster->QCN+" "
            "and are hit with the full force of it's destructive power!");
        tell_room(place,""+target->QCN+" is unable to move in time, and is hit with the "
            "full destructive power of "+caster->QCN+"'s spell!",({target,caster}));
        damage_stuff(target);
    }
    else
    {
        tell_object(caster,"%^ORANGE%^"+target->QCN+" manages to dodge to the side at the last "
            "second, narrowly avoiding the full power of the destructive spell!");
        tell_object(target,"%^ORANGE%^You manage to dodge aside at the last instant, dodging the "
            "full power of the destructive spell!");
        tell_room(place,"%^ORANGE%^"+target->QCN+" manages to dodge aside at the last instant, "
            "avoiding the full power of the destructive spell!",({target,caster}));
        sdamage/=2;
    }
    damage_targ(target,target->return_target_limb(),sdamage,"force");
    spell_kill(target,caster);
    spell_successful();
    dest_effect();
}

void damage_stuff(object target)
{
    object *stuff;
    int i;

    if(!objectp(target)) { return; }
    stuff = all_inventory(target);
    if(!sizeof(stuff)) { return; }

    for(i=0;i<sizeof(stuff);i++)
    {
        if(object_save(stuff[i])) { continue; }
        tell_object(target,"%^RED%^"+(string)stuff[i]->query_short()+" is struck by the "
            "destructive magic of the spell!");
        stuff[i]->repairMe(-roll_dice(1,6));
    }
}

// gives the stuff in inventory a save based on enchantment
int object_save(object obj)
{
    int enchantment;
    if(!objectp(obj)) { return 1; }
    enchantment = (int)obj->query_property("enchantment");
    if(!enchantment) { enchantment = obj->isMagic(); }
    if((roll_dice(1,20) + enchantment) < roll_dice(1,20)) { return 0;}
    return 1;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
