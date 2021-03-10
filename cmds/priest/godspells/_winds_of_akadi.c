//altered to make it a little more viable (not hit non-hostile creatures) Circe 3/23/05
// Winds of Akadi

#include <std.h>
#include <daemons.h>

inherit SPELL;

int count;

void create() {
    ::create();
    set_spell_name("winds of akadi");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_sphere("elemental air");
    set_diety("akadi");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
}

string query_cast_string() {
    return "%^BLUE%^"+caster->query_cap_name()+" raises "+caster->query_possessive()+" hands up in front of "+caster->query_objective()+" and calls to Akadi!";
}

int preSpell() {
    if (place->query_property("underwater")) {
        tell_object(caster,"%^BOLD%^That spell can only be cast in the air, not underwater.");
        return 0;
    }
    if (caster->query_property("winds")) {
        tell_object(caster,"%^BOLD%^You cannot control a second mass of whirling wind.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    int i;
    object *who;

    if (!objectp(target) || !objectp(caster) || !objectp(place)) {
        dest_effect();
        return;
    }
    if (!present(target,place)) {
        tell_object(caster,"%^BOLD%^Your target has left the area.");
        dest_effect();
        return;
    }
    caster->set_property("winds",1);
    tell_object(place,"%^BOLD%^%^CYAN%^The wind begins to whirl around the area, picking up dust and small rocks.");
//    who = all_living(place);
    who = caster->query_attackers();
    who = filter_array(who, "is_non_immortal",FILTERS_D);

    for (i=0;i<sizeof(who);i++) {
        if (!objectp(who[i])) continue;
        if (who[i] == caster) continue;
	    if (!(SAVING_D->saving_throw(who[i], "spell",0))) {
            tell_object(who[i],"%^BOLD%^The air whirling around you causes some small objects to hit you.");
            damage_targ(who[i],"torso",roll_dice(1,4));
        }
    }
    count = 0;
    call_out("do_lightning",3);
}

void do_lightning() {
    int dam,i;

    if (!objectp(target) || !objectp(caster) || !objectp(environment(target))) {
        dest_effect();
        return;
    }
    if (target->query_ghost() || caster->query_ghost()) {
        dest_effect();
        return;
    }
    if (environment(target)->query_property("underwater")) {
        dest_effect();
        return;
    }
// moved up here from below *Styx*, 12/31/03
    if (environment(caster) != environment(target)) {
	tell_object(environment(target),"%^BOLD%^%^BLUE%^The swirling winds calm back to normal.");
        tell_object(caster,"%^BOLD%^%^BLUE%^The swirling winds calm back to normal.");
        dest_effect();
        return;
    }

    dam = 0;
    for (i=0;i<clevel;i++) {
        dam += roll_dice(1,4);
    }
    if (dam > 100) dam = 100;
    tell_object(target,"%^YELLOW%^A lightning bolt streaks toward you from the swirling mass of air!");
    tell_room(environment(target),"%^YELLOW%^A lightning bolt streaks toward "+target->query_cap_name()+" from the swirling mass of air!",({target}));
    if (!(SAVING_D->saving_throw(target, "spell",-4))) {
        damage_targ(target,"torso",dam);
    } else {
        damage_targ(target,"torso",dam/2);
    }
    count++;
     if(!objectp(target)) { 
          dest_effect();
          return;
     }
    if (count == 5) {
        tell_object(environment(target),"%^BOLD%^%^BLUE%^The swirling winds calm back to normal.");
/* this not kicking in here until too late, so I'm moving it up *Styx*, 12/31/03, last change 6/24/01
        if (environment(caster) != environment(target))
            tell_object(caster,"%^BOLD%^%^BLUE%^The swirling winds calm back to normal.");
*/
        dest_effect();
        return;
    } else {
        call_out("do_lightning",4);
    }
}

void dest_effect() {
    ::dest_effect();
    caster->remove_property("winds");
    remove_call_out("do_lightning");
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Winds of Akadi
Level  : 3rd Level
Sphere : Elemental Air
Deity  : Akadi
Syntax : chant winds of akadi on <target>

This spell causes a great sphere of swirling winds to appear
around the target. Lightning bolts come forth from the mass
of air to strike them.

HELP
);
    return 1;
}

