#include <std.h>
#include <priest.h>

inherit SPELL;

object mywpn;

void create()
{
    ::create();
    set_spell_name("whip of spiders");
    set_spell_level(([ "bard" : 2, "druid" : 2, "mage" : 2, "magus" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS whip of spiders");
    set_description("You summon hundreds of tiny spiders that form into a whip that extends from your hand.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}


string query_cast_string()
{
    return "%^BOLD%^%^WHITE%^" + caster->QCN + " extends  " + caster->QP + " arm, and an army of tiny spiders starts crawling out of " +caster->QP+" sleeves.";
}


void spell_effect(int prof)
{
    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    if (interactive(caster)) {
        tell_object(caster, "%^BOLD%^%^WHITE%^The spiders attach to each other, forming a whip that extends from your hand.");
    }

    tell_room(place, "%^BOLD%^%^WHITE%^The spiders on " + caster->QCN + "'s hand attaches to each other, forming a whip!", caster);

    mywpn = new("/d/magic/obj/whip_of_spiders");
    mywpn->make_me(TO);
    mywpn->move(caster);

    caster->remove_paralyzed();
    caster->force_me("wield weapon");
    addSpellToCaster();
    spell_successful();
}


void dest_effect()
{
    if (objectp(mywpn) && objectp(caster)) {
        mywpn->remove();
        tell_room(ENV(caster), "%^BOLD%^%^WHITE%^The spiders fall to the ground and quickly disperse...");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
