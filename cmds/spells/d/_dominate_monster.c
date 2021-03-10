//      Domination
#include <daemons.h>
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit "/cmds/spells/d/_domination";

void create()
{
    ::create();
    set_spell_name("dominate monster");
    set_spell_level(([ "mage" : 9,]));
    set_domains(({ "charm", "law" }));
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS dominate monster on TARGET");
    set_description("This spell works exactly as domination, except it works on all creatures.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

string query_cast_string()
{
    return "%^BLUE%^" + caster->QCN + " glides " + caster->QP + " hand from side to side while " + "chanting hypnotically.";
}

int query_domination_duration(object targ)
{
    int duration;
    if (!userp(targ)) {
        return 0;
    }
    duration = 60 + clevel * 60;
    duration = duration > 360 ? 360 : duration;
    return duration;
}

int cant_be_dominated(targ)
{
    return do_save(target, -2) ||
           mind_immunity_damage(targ, "default");
}

int is_proper_target(object targ)
{
    return !targ->query_property("no dominate") ||
           !present("clothesx999", targ);
}

void monster_fix(object targ)
{
    if (!userp(targ)) {
        targ->set_property("spell", TO);
        targ->set_property("spell", ({ TO }));
        targ->set_property("spell_creature", TO);
        targ->set_property("minion", caster);
    }
    return;
}
