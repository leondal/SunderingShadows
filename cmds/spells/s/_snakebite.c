#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit SPELL;

void create(){
    ::create();
    set_spell_name("snakebite");
    set_spell_level(([ "ranger" : 3 ]));
    set_spell_sphere("combat");
    set_syntax("cast CLASS snakebite on TARGET");
    set_description("This spell allows the ranger to draw forth the remaining living energy in an otherwise dead stick, "
"converting it into life.  It will become a serpent that strikes the target, with a chance to poison with its bite.");
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
    tell_object(caster,"%^ORANGE%^You snatch up a stick from the ground and "
"focus upon the remnants of natural energy within it.");
    tell_room(place,"%^ORANGE%^"+caster->QCN+" snatches up a stick from the "
"ground and focusses.",caster);
        return "display";
}

void spell_effect(int prof) {
    int effect;

    if(!objectp(caster) || !objectp(target)){
        dest_effect();
        return;
    }

    place = environment(caster);
    if (environment(target)!=place) {
        tell_object(caster,"Your target has left the area!");
        dest_effect();
        return;
    }
    spell_successful();
    effect = sdamage;
    tell_object(caster,"%^ORANGE%^Life stirs within the stick and it writhes in "
"your hand, as you cast a now-living snake towards "+target->QCN+"!\n");
    tell_object(target,"%^ORANGE%^The stick in "+caster->QCN+"'s hand writhes "
"as it comes to life, and "+caster->QS+" casts a now-living snake at you!");
    tell_room(place,"%^ORANGE%^The stick in "+caster->QCN+"'s hand writhes as "
"it comes to life, and "+caster->QS+" casts a now-living snake at "
+target->QCN+"!",({caster,target}));
    damage_targ(target,target->return_target_limb(),effect,"acid");
   if(!do_save(target))
      call_out("do_poison",ROUND_LENGTH);
    else
      dest_effect();
}

void do_poison() {
    int effect;
    if (!caster || !objectp(caster) || !target || !objectp(target)) {
        dest_effect();
        return;
    }
    tell_room(environment(target),"%^BOLD%^%^GREEN%^"+target->QCN+" writhes in pain!",target);
    tell_object(target,"%^BOLD%^%^GREEN%^Poison burns through your veins!");
    define_base_damage(0);
    damage_targ(target,target->return_target_limb(),sdamage/2,"acid");
    dest_effect();
    return;
}

void dest_effect() {
    if (find_call_out("next_zap") != -1)
        remove_call_out("next_zap");
    if (target && objectp(target)) {
        tell_room(place,"%^ORANGE%^The stick clatters to the ground again, lifeless.");
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
