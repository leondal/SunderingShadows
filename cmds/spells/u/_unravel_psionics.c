// Highest level psionic dispel
// Functions like greater dispel magic or break curse, depending on the target
// ~Circe~ 4/17/16
#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit "/cmds/spells/d/_dispel_magic";

object targ;
string arg;

void create() {
    ::create();
    set_spell_name("unravel psionics");
    set_spell_level(([ "psion" : 9 ]));
    set_spell_sphere("psychokinesis");
    set_syntax(
"cast CLASS unravel psionics [on TARGET]
        cast CLASS unravel psionics on break curse");
    set_description("Unravel psionics is the most potent disruptive "
       "power in the psion's arsenal. It can be used to destroy "
       "enchantments, summonings, and conjurations. Like its arcane "
       "counterpart, the chances of each dispelling depends on both "
       "the dispeller's casting level and the power level of the "
       "spellcaster that created whatever is being dispelled. If this "
       "power targets a particular item, it will attempt to remove "
       "any curses on the item, similar to the break curse spell.");
    set_verbal_comp();
    set_arg_needed();
    set_somatic_comp();
}

int preSpell() {
    if (!query_arg()) return 1;
    if(query_arg() == "break curse") return 1;

    targ = present(query_arg(),ETP);
    if (!objectp(targ)) {
        tell_object(TP, "That is not here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object *allinv, obj;
    int i, mylevel;

    caster = query_caster();
    place = query_place();
    mylevel = clevel + 10;
    arg = query_arg();

    spell_successful();
    tell_room(place, "%^RESET%^%^CYAN%^"+caster->QCN+" lifts a hand that "
       "begins to %^BOLD%^glow%^RESET%^%^CYAN%^ with energy.%^RESET%^",caster);

    tell_object(caster, "%^RESET%^%^CYAN%^You lift a hand that begins "
       "to %^BOLD%^glow%^RESET%^%^CYAN%^ with energy.%^RESET%^");
    if(arg == "break curse"){
       obj = new("/d/magic/obj/curse_breaker.c");
       obj->move(caster);
       obj->set_caster(caster);
       obj->set_spell(TO);
       return;
    }
    if (targ && !objectp(targ)){
        dest_effect();
        return;
    }
    if(targ && !caster->ok_to_kill(targ)){
        dest_effect();
        return;
    }
    if (!targ) {
        allinv = deep_inventory(place);
        allinv = target_filter(allinv);
        allinv += ({place});
    } else  {
        allinv = deep_inventory(targ);
        allinv += ({targ});
    }

    for (i = 0;i < sizeof(allinv);i++) {
        if (!objectp(allinv[i])) continue;
        if(!caster->ok_to_kill(allinv[i])) continue;
        if (allinv[i]->query_property("spelled"))
            dispel(allinv[i]);
    }
    dest_effect();
    return 1;
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
