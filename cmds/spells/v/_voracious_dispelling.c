#include <spell.h>
#include <magic.h>
#include <daemons.h>
inherit "/cmds/spells/d/_dispel_magic";

string arg;
int theProf;
object caster, place, targ;

void create() {
    ::create();
    set_author("nienne");
    set_spell_name("voracious dispelling");
    set_spell_level(([ "warlock" : 2 ]));
    set_syntax("cast CLASS voracious dispelling (on TARGET)");
    set_description("This invocation will seek to unravel any spell enchantments, magical summonings, and conjurations. "
"The chances of each dispelling depends on both the dispeller's power, and that of the one who created whatever is being "
"dispelled. Such is the disruptive nature of the invocation, that successful dispel attempts will also harm their target.");
    set_arg_needed();
    set_verbal_comp();
    set_somatic_comp();
}

string query_cast_string() {
    tell_object(caster,"%^BOLD%^%^WHITE%^Your hands tremble with %^BOLD%^%^BLACK%^di%^RESET%^sr%^BOLD%^%^BLACK%^u%^RESET%^pt%^BOLD%^%^BLACK%^iv%^RESET%^e %^BOLD%^%^WHITE%^potential.%^RESET%^");
    tell_room(environment(caster),"%^BOLD%^%^WHITE%^"+caster->QCN+"'s hands tremble with %^BOLD%^%^BLACK%^di%^RESET%^sr%^BOLD%^%^BLACK%^u%^RESET%^pt%^BOLD%^%^BLACK%^iv%^RESET%^e %^BOLD%^%^WHITE%^potential.%^RESET%^",caster);
    return "display";
}

int preSpell() {
    if (!query_arg()) return 1;
    targ = present(query_arg(), query_place());
    if (!targ) {
        tell_object(query_caster(), "That is not here.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    object *allinv;
    int i;
    theProf = prof;

    caster = query_caster();
    place = query_place();
    arg = query_arg();

    tell_room(place, "%^BOLD%^%^WHITE%^"+caster->QCN+" releases the invocation in a burst of c%^YELLOW%^h%^BOLD%^%^GREEN%^a%^BOLD%^%^WHITE%^ot%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^c energy!%^RESET%^", caster);
    tell_object(caster, "%^BOLD%^%^WHITE%^You release the invocation in a burst of c%^YELLOW%^h%^BOLD%^%^GREEN%^a%^BOLD%^%^WHITE%^ot%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^c energy!%^RESET%^");

    if (targ && !objectp(targ)) {  // if there was a target set but it's gone, dispel
        dest_effect();
        return;
    }
    if(targ && !caster->ok_to_kill(targ)) {   // fixed from target *Styx* 1/25/05
        dest_effect();
        return;
    }
    if (!targ) {  // now, if there wasn't a target set, do the room
        allinv = deep_inventory(place);
        allinv = target_filter(allinv);
        allinv += ({place});
    }
    else {
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
}

void dispel(object ob) {
    object *spells;
    int i, dmg, mylvl;
    string mytype;

    if (!objectp(ob)) {
        return;
    }

    if (!ob->query_property("spelled")) {
        return;
    }
    if (ob->query_true_invis()) {
        return;
    }

    if (pointerp(ob->query_property("spelled"))) {
        spells = ob->query_property("spelled");
    }else {
        spells = ({ ob->query_property("spelled") });
    }

    if (!sizeof(spells)) {
        return;
    }

    shuffle(spells);

    dmg = 0;
    for (i = 0;i<sizeof(spells);i++) {
        if(!objectp(ob)) continue;
        if (!objectp(spells[i])) continue;
        if (!checkDispel(spells[i])) continue;
        tell_object(caster, "You dispel the "+spells[i]->query_spell_name());
        mytype = spells[i]->query_spell_type();
        mylvl = spells[i]->query_spell_level(mytype);
        if(mylvl < 1) mylvl = 1;
        dmg += (mylvl*2); // we're going to do 2 damage per spell level dispelled, to the target
        ob->remove_property_value("spelled", ({spells[i]}) );
        spells[i]->dest_effect();
    }
    if(dmg) {
      tell_object(ob,"%^BOLD%^%^WHITE%^The c%^YELLOW%^h%^BOLD%^%^GREEN%^a%^BOLD%^%^WHITE%^ot%^BOLD%^%^CYAN%^i%^BOLD%^%^WHITE%^c energies tear at your body!%^RESET%^");
      damage_targ(ob,"torso",dmg,"untyped");
    }
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
