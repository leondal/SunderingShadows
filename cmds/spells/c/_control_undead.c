//      Domination
#include <daemons.h>
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit "/cmds/spells/d/_domination";

void create() {
    ::create();
    set_spell_name("control undead");
    set_spell_level(([ "mage" : 7,]));
    set_spell_sphere("necromancy");
    set_domains(({}));
    set_syntax("cast CLASS control undead on TARGET");
    set_description("By invoking this spell, a necromancer confirms its domain over the undead and takes control of the unliving. They can use the next commands to force the undead to serve:

%^ORANGE%^<command dominated to %^ORANGE%^%^ULINE%^ACTION%^RESET%^%^ORANGE%^>%^RESET%^
  Will force the dominated to perform an %^ORANGE%^%^ULINE%^ACTION%^RESET%^.

%^ORANGE%^<freedominated>%^RESET%^
  Will free the dominated undead.

If the will save suceeds or the target is not undead they will be outraged at your attempt and will attack immediately.

Intelligent undead creatures remember that you controlled them, and they may be slightly upset they were under your power.

%^BOLD%^%^RED%^N.B.%^RESET%^ If used on players this spell provide you with a limited subset of allowed commands.");
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
        !target->is_undead();
}

int is_proper_target(object targ)
{
    return !targ->query_property("no dominate") ||
        !present("clothesx999", targ);
}

void monster_fix(object targ)
{
    if(!userp(targ))
    {
        targ->set_property("spell", TO);
        targ->set_property("spell", ({ TO }));
        targ->set_property("spell_creature", TO);
        targ->set_property("minion", caster);
    }
    return;
}
