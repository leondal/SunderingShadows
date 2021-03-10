// --==** /cmds/priest/_heroes_feast.c **==--
// Modified by Pator@ShadowGate
// August 25 1995, 11/2/95
// Ganked for Heroes' Feast -Ares
#include <priest.h>
#include <magic.h>

object banquet;

create()
{
    ::create();
    set_author("ares");
    set_spell_name("heroes feast");
    set_spell_level(([ "cleric" : 6, "bard" : 6, "inquisitor" : 6 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS heroes feast");
    set_description("This spell will allow the caster to create a huge table, filled with delectable treats and succulent "
                    "dishes.  The feast created by this prayer will alleviate hunger and thirst, and tastes far better than the what is "
                    "provided with the create food prayer. ");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
    if (present("heroes feast", place)) {
        tell_object(caster, "There is already a banquet table here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    int duration;

    tell_object(caster, "%^YELLOW%^You call on the power of " + capitalize((string)caster->query_diety()) + "" +
                " and an elegant table of enormous proportions begins to materialize " +
                "out of thin air before you!");
    tell_room(place, "%^YELLOW%^" + caster->QCN + " calls on the power of " + caster->QP + " patron and an elaborate banquet "
              "table appears out of thin air!", caster);
    banquet = new("/cmds/priest/obj/feast_obj.c");
    banquet->move(place);
    // should only vanish if the caster leaves the room for this many rounds
    duration = (20 * ROUND_LENGTH) * clevel;
    banquet->set_duration(duration);
    banquet->set_caster(caster);
    banquet->set_casting_spell(TO);
    place->set_property("fill waterskin", 1);
    spell_successful();
}

void dest_effect()
{
    if (objectp(banquet)) {
        banquet->remove();
    }
    if (objectp(place)) {
        place->set_property("fill waterskin", -1);
    }

    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
