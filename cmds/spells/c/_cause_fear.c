#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

void create() {
	::create();
    set_spell_name("cause fear");
    set_spell_level(([ "mage" : 1, "bard" : 2, "cleric":1,"paladin":1,"inquisitor" : 1,"oracle":1 ]));
    set_spell_sphere("necromancy");
    set_mystery(({"dragon","bones"}));
    set_syntax("cast CLASS cause fear on TARGET");
    set_damage_desc("frightened, sickened on save");
    set_description("This power allows the caster to project an aura of fear toward a target, potentially sending him fleeing.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    mental_spell(1);
    set_save("will");
}

string query_cast_string(){
    return "%^RESET%^%^BLUE%^"+caster->QCN+"%^RESET%^%^BLUE%^'s eyes darken as dread emanates from "+caster->QO+".%^RESET%^";
}

void spell_effect(int prof){
    int i,j, percent, x, hits, bonus,mylevel;
    string *ids, MyType;
    object *weapons;
    if(!objectp(target))
        dest_effect();

    tell_object(caster,"%^RESET%^%^BLUE%^You project horrifying images directly into "+target->QCN+"'s mind.%^RESET%^");

    if(mind_immunity_damage(target))
    {
        spell_successful();
        dest_effect();
        return;
    }

    spell_successful();
    bonus = (int)caster->query_stats("intelligence");
    bonus = (bonus - 10) / 2;
    bonus = -bonus;

    if(do_save(target,bonus))
    {
        tell_object(target, "%^RESET%^%^BLUE%^You fight back some horrid images projected into your mind.%^RESET%^");
        tell_room(place,"%^RESET%^%^BLUE%^"+target->QCN+" grimmaces and shakes "+target->QP+" head, fighting off the mental attack.%^RESET%^",target);

        "/std/effect/status/sickened"->apply_effect(target,roll_dice(1,6));
    }
    else
    {
        tell_object(target,"%^BOLD%^%^BLACK%^Images from your worst nightmares spring to life, flooding your mind and shaking the foundation of your soul.%^RESET%^");
        tell_room(place, "%^BOLD%^%^BLACK%^Sheer horror contorts "+target->QCN+"'s face as "+target->QS+" breaks in fear and trembles.%^RESET%^",target);
      "/std/effect/status/frightened"->apply_effect(target,roll_dice(1,6));
    }

    dest_effect();
}

void dest_effect(){
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
