#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

#define HOUND "/d/magic/mon/spectral_hound"
inherit SPELL;

object hound;

void create()
{
    ::create();
    set_spell_name("faithful hound");
    set_spell_level(([ "mage" : 5 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS faithful hound");
    set_damage_desc("piercing");
    set_description("With this spell you conjure up an invisible spectral dog. It will stay in the area for a while and bark telepathically if someone approaches. If attacked, it will defend itself, and if someone attacks you it will defend you as well.");
	set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^"+caster->QCN+" stretches "+caster->QP+" arms outward, chanting sonorously.";
}

void preSpell()
{
    if((int)caster->query_property("has_faithful_hound"))
    {
        tell_object(caster,"Your concentration fades. There must be another spectral hound of yours somewhere.");
        return 0;
    }
    return 1;
}

void spell_effect()
{
    tell_object(caster,"%^RESET%^%^CYAN%^You wave your hand and spectral hound appears, faithfully guarding the area.");
    tell_room(place,"%^RESET%^%^CYAN%^"+caster->QCN+"%^RESET%^%^CYAN%^ waves "+caster->QP+" hand, but nothing seems to happen",({caster}));
    hound = new(HOUND);
    hound->move(place);
    hound->setup(caster,clevel);

    hound->set_property("spell",TO);
    hound->set_property("spelled", ({TO}) );
    spell_successful();
    caster->set_property("has_faithful_hound",1);
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 4;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect()
{
    if(objectp(hound))
        hound->remove_hound();
    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
