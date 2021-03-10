// orders oath
#include <spell.h>
#include <daemons.h>

inherit SPELL;

void create()
{
    ::create();
    set_author("ares");
    set_spell_name("orders wrath");
    set_spell_level(([ "inquisitor" : 4, "oracle" : 4]));
    set_affixed_spell_level(8);
    set_spell_sphere("invocation_evocation");
    set_mystery("godclaw");
    set_syntax("cast CLASS orders wrath on TARGET");
    set_damage_desc("divine");
    set_description("You channel lawful power to smite enemies. The power takes the form of a three-dimensional grid of energy. Neutral and lawfulcreatures recieve half of the damage and Will save halves the damage. Lawful creatures are not affected.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    tell_object(caster,"%^BOLD%^You can feel a commanding pressence building inside, as you chant the enthralling words of the order.");
    tell_room(place,"%^BOLD%^"+caster->QCN+" strikes a commanding pose as "+caster->QS+" chants.",caster);
    return "display";
}

void spell_effect(int prof)
{
    int dam = sdamage;
    int align = target->query_alignment();

    if(align<4)
    {
        tell_room(place,"%^BOLD%^%^WHITE%^"+caster->QCN+" seem unaffected by the spell.");
        dest_effect();
        return;
    }
    if(align<7)
        dam/=2;
    if(do_save(target,0))
        dam/=2;

    tell_object(caster,"%^BOLD%^The power of your voice manifests into three-dimensional grid and it slams into "+target->QCN+"!");
    tell_object(target,"%^BOLD%^The power of "+caster->QCN+" voice manifests into three-dimensional grid and it slams into you!");
    tell_room(place,"%^BOLD%^The power of your voice manifests into three-dimensional grid and it slams into "+target->QCN+"!",({caster,target}));
    damage_targ(target, target->return_target_limb(), sdamage,"sonic" );
    dest_effect();
    return;
}
