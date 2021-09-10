#include <priest.h>
inherit SPELL;


void create()
{
    ::create();
    set_spell_name("body adjustment");
    set_affixed_spell_level(6); // alternative to heal
    set_spell_level(([ "psywarrior" : 2, "psion" : 3 ]));
    set_spell_sphere("psychometabolism");
    set_syntax("cast CLASS body adjustment");
    set_description("When using this power, the psionic character takes "
        "control of his own healing process and makes minor adjustments "
        "throughout his body, restoring hit points. This power has the "
        "same limitations as a cleric's heal spell and cannot regrow lost "
        "limbs or heal substantial damage.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


int preSpell()
{
    if(sizeof(caster->query_attackers()) > 0)
    {
        if((int)caster->query_property("using bodyadjustment") > time())
        {
            tell_object(caster,"Your mind must recover before you can use such a power again!");
            dest_effect();
            return 0;
        }
       return 1;
    }
    if(((int)caster->query_property("using bodyadjustment") > time()) && (sizeof(caster->query_attackers()) == 0))
    {
        caster->remove_property("using bodyadjustment");
        return 1;
    }
    return 1;
}

void spell_effect(int prof)
{
    int rnd;

    tell_object(caster, "%^BOLD%^%^WHITE%^You focus your attention inward, " "making minute changes to your body that help heal your injuries.%^RESET%^");
    tell_room(place, "%^BOLD%^%^As you watch, " + caster->QCN + "%^BOLD%^%^WHITE%^'s " "injuries begin to knit together as " + caster->QS + " heals " + caster->QO + "self " "from within!%^RESET%^", caster);

    rnd = sdamage * 7 / 6;

    damage_targ(caster, caster->return_target_limb(), -rnd, "untyped");

    spell_successful();
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
