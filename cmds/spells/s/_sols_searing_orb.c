//_sols searing orb
#include <std.h>
inherit SPELL;

void create()
{
    ::create();
    set_spell_name("sols searing orb");
    set_spell_level(([ "classless" : 7 ]));
    set_spell_sphere("sun");
    set_syntax("cast CLASS sols searing orb");
    set_description("This spell turns a gem of value into a searing orb of light and magical fire. When the gem is "
                    "turned into the orb, the caster must <throw orb at target> or throw orb <direction> before it explodes.");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell()
{
    if (!present("gem", caster)) {
        tell_object(caster, "You fail to have the gem needed to complete this spell.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof)
{
    object gem, orb;

    if (!objectp(caster)) {
        return;
    }

    if (!gem = present("gem", caster)) {
        tell_player(caster, "You fail to have the gem needed to complete this spell.\n");
        dest_effect();
        return;
    }

    orb = new("/d/magic/obj/sols_orb");
    orb->set_caster(caster);
    if (caster->is_player()) {
        orb->set_level(caster->query_class_level("cleric"));
    }else {
        orb->set_level(caster->query_highest_level());
    }

    gem->remove();
    orb->move(caster);
    tell_object(caster, "%^YELLOW%^The gem you cradle in your hands starts to glow and warm.");
    tell_room(place, "%^YELLOW%^The gem held high by " + caster->QCN + ", begins to glow brightly,", caster);
    tell_object(caster, "Careful, it's gonna get hot.");
    dest_effect();
    return 1;
}

string query_casting_string()
{
    return "%^YELLOW%^" + caster->QCN + " raises a gem toward " + caster->QP + " god and request that " + caster->QS + " be granted the power of the sun.";
}

void dest_effect()
{
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
