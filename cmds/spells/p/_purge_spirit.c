// Greater Shout
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

void dest_effect();

void create()
{
    ::create();
    set_spell_name("purge spirit");
    set_spell_level(([ "mage" : 4, "oracle" : 4 ]));
    set_spell_sphere("necromancy");
    set_mystery("reaper");
    set_damage_desc("divine, paralyzed");
    set_syntax("cast CLASS purge spirit on TARGET");
    set_description("This spell rips away at the target's spiritual substance, scattering it over a wide area and hampering the target's ability to reform. A successful save will prevent paralyzation.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^BOLD%^%^BLUE%^"+caster->QCN+" chants a rhythmic low undertones.";
}

void spell_effect()
{
    int num;
    string target_limb;
    spell_successful();

    target_limb = target->return_target_limb();
    tell_object(target,"%^BLUE%^%^BOLD%^"+caster->QCN+" makes a pass at you as if grabbing something out of the air and you feel a painful pull on your soul.");
    tell_room(place,"%^BLUE%^%^BOLD%^"+caster->QCN+" makes a pass at "+target->QCN+" as if grabbing something out of the air.", target);
    if(!do_save(target)) {
        tell_object(target,"%^MAGENTA%^%^BOLD%^You are staggered by the force pulling on your soul!");
        tell_room(environment(caster),"%^BLUE%^%^BOLD%^"+target->QCN+" staggered, unable to move.", ({ target}) );
        damage_targ(target, target_limb, sdamage,"divine");
        target->set_paralyzed(roll_dice(1,2)*8,"%^BOLD%^%^BLUE%^You are staggered by the force pulling on your soul!");
    }
    dest_effect();
}
