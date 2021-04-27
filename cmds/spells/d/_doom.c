#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create() {
	::create();
    set_spell_name("doom");
    set_spell_level(([ "cleric":1,"paladin":1,"inquisitor" : 1, "bard" : 1 ]));
    set_spell_sphere("necromancy");
    set_syntax("cast CLASS doom on TARGET");
    set_damage_desc("shaken");
    set_description("This spell fills a single subject with a feeling of horrible dread that causes it to become shaken. Will save will negate the effect.

%^BOLD%^%^RED%^See also:%^RESET%^ status effects");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    mental_spell(1);
    set_save("will");
    set_feats_required(([ "bard" : "epic tales" ]));
}

string query_cast_string(){
    return "%^RESET%^%^RED%^"+caster->QCN+"%^RESET%^%^RED%^'s eyes darken as dread emanates from "+caster->QO+".%^RESET%^";
}

void spell_effect(int prof){
    int i,j, percent, x, hits, bonus,mylevel;
    string *ids, MyType;
    object *weapons;
    if(!objectp(target))
        dest_effect();

    tell_object(caster,"%^RESET%^%^RED%^You project horrifying images directly into "+target->QCN+"'s mind.%^RESET%^");

    if(mind_immunity_damage(target))
    {
        spell_successful();
        dest_effect();
        return;
    }

    spell_successful();
    if(do_save(target,-2))
    {
        tell_object(target, "%^RESET%^%^RED%^You fight back some horrid images projected into your mind.%^RESET%^");
        tell_room(place,"%^RESET%^%^RED%^"+target->QCN+" grimmaces and shakes "+target->QP+" head, fighting off the mental attack.%^RESET%^",target);
    }
    else
    {
        tell_object(target,"%^BOLD%^%^BLACK%^Images from your worst nightmares spring to life, flooding your mind and shaking the foundation of your soul.%^RESET%^");
        tell_room(place, "%^BOLD%^%^BLACK%^Sheer horror contorts "+target->QCN+"'s face as "+target->QS+" breaks in fear and trembles.%^RESET%^",target);
      "/std/effect/status/shaken"->apply_effect(target,roll_dice(4,6));
    }

    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
