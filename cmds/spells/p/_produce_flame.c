//Produce Flame for Druids
//Coded by ~Circe~ 3/19/13
//Based on burning hands

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>
inherit SPELL;

void dest_effect();
void damage(object mytarg, int bonus);

void create() {
    ::create();
    set_spell_name("produce flame");
    set_spell_level(([ "druid" : 1, "cleric":2]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS produce flame on TARGET");
    set_description("The druid opens his hand, palm up, and a flame as "
       "bright as a torch appears there.  The flame will not harm "
       "the druid or his equipment, but when the druid hurls the "
       "flame at an enemy, it explodes, fanning out to damage those "
       "around him.  Although the druid will try to control the spell "
       "so as not to damage allies, this may not always be possible.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("reflex");
    splash_spell(1);
}

string query_cast_string() {
   return caster->QCN+" opens "+caster->QP+" hand palm up and a flame appears.";
}

void spell_effect(int prof) {
    int counter;
    int bonus = prof/10 - 10;
    int x;
    object * allies;
    object * targets;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        dest_effect();
        return;
    }

    targets = target_selector();

    targets -= ({target});
    targets -= ({caster});

    tell_object(target,"%^YELLOW%^"+caster->QCN+" flings the %^RED%^flame "
       "%^YELLOW%^straight at you!%^RESET%^");
    tell_object(caster,"%^YELLOW%^With a flick of your wrist, you fling the "
       "ball of %^RED%^flame %^YELLOW%^straight at "+target->QCN+"!%^RESET%^");
    tell_room(place,"%^YELLOW%^"+caster->QCN+" flicks "+caster->QP+" wrist, "
       "sending the ball of %^RED%^flame%^YELLOW%^ straight "
       "at "+target->QCN+"!%^RESET%^",({ caster, target}) );
    damage(target, bonus);
    for (x=0;x < sizeof(targets);x++){
        if(!objectp(targets[x])) { continue; }
        if (!random(3)){
            damage(targets[x], bonus-random(5));//5 for the 5 feet spread
        }
    }
    dest_effect();
}

void damage(object mytarg, int bonus) {
    string before, after, *immunities;
    int i;

    if(do_save(mytarg,0)) {
        tell_room(place,"%^RESET%^%^ORANGE%^"+mytarg->QCN+" ducks away from the ball of flames!%^RESET%^", mytarg);
        tell_object(mytarg,"%^RESET%^%^ORANGE%^You feel a whoosh of heat as you are only singed by the flames!%^RESET%^");
        damage_targ(mytarg, "torso", to_int(sdamage / 2),"fire" );
    } else {
        tell_room(place,"%^BOLD%^%^RED%^The flames slam into "+mytarg->QCN+", burning "+mytarg->QO+" badly!", mytarg);
        tell_object(mytarg,"%^BOLD%^%^RED%^You feel agony as the flames threaten to consume you!%^RESET%^");
        damage_targ(mytarg, "torso", sdamage,"fire");
    }
    return;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
