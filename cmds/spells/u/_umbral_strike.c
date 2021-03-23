#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("umbral strike");
    set_spell_level(([ "druid" : 7, "mage" : 7,"inquisitor":6, "magus" : 6, "oracle":7, "cleric" : 7]));
    set_mystery("shadow");
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS umbral strike on TARGET");
    set_damage_desc("half cold, half negative energy");
    set_description("This spell will hurl a bolt of pure darkness at a target, harming them.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

int preSpell(){
    if(!objectp(target)){
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster,"%^BOLD%^%^BLACK%^%^You chant in a secretive whisper,"+
		" and the darkness swirls around you, congregating in your palms.");
    tell_room(place,"%^BOLD%^%^BLACK%^The darkness swirls around "+caster->QCN+","+
		" congregating in "+caster->QP+" palms.",({ caster }) );
    return "display";
}

void spell_effect(int prof){
    int damage, i;
    object *attackers;

    if(!present(target,place))
    {
        tell_object(caster,"Your target has left.");
        dest_effect();
        return;
    }
    damage = sdamage / 2;
    tell_object(caster,"%^BOLD%^%^BLACK%^You hurl your fist towards "+target->QCN+" and a beam of "
        "darkness flows forth towards "+target->QO+".");
    tell_object(target,"%^BOLD%^%^BLACK%^A beam of darkness flows forth from "+caster->QCN+"'s "
        "hand towards you!");
    tell_room(place,"%^BOLD%^%^BLACK%^"+ caster->QCN+" hurls "+caster->QP+" fist forth and a beam "
        "of darkness flows towards "+target->QCN+"!",({ caster, target}) );
    if (!do_save(target, -2))
    {
        tell_object(target, "%^BLUE%^The beam of darkness strikes you, ravaging your mind.");
        tell_room(environment(target), "%^BLUE%^The beam of darkness strikes " + target->QCN + ".", target);
        target->set_temporary_blinded(roll_dice(2, 4));
    }
    else
    {
        tell_object(target, "%^BLUE%^The beam grazes you.");
        tell_room(environment(caster), "%^BLUE%^The beam almost misses " + target->QCN + ".", target);
        damage /= 2;
    }
    damage_targ(target, "torso", damage, "negative energy");
    damage_targ(target, "torso", damage, "cold");
    spell_kill(target, caster);
    spell_successful();
    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
