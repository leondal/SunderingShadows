// Aqueous Column - Istishian spell
//8/05

#include <std.h>
#include <daemons.h>

inherit SPELL;

object whip;

create() {
    	::create();
    	set_spell_name("aqueous column");
	set_author("cythera");
    	set_spell_level(4);
    	set_spell_type("priest");
    	set_spell_sphere("elemental water");
    	set_diety("istishia");
    	set_verbal_comp();
    	set_somatic_comp();
    	set_target_required(1);
	set_xp_bonus(40);
}

string query_cast_string() {
    return "%^CYAN%^"+caster->QCN+" opens a small portal up to the Plane of Water"+
		" and creates a column of water as "+caster->QS+" calls for Istishia's favor!";
}

void spell_effect(int prof) {
    int dam,i;
    string *ids;
    object *weapons;

    if (!objectp(target) || !objectp(caster)) {
        dest_effect();
        return;
    }
    dam = 0;
    for (i=0;i<clevel;i++)
        dam += 1+random(4);
    tell_object(caster,"%^CYAN%^You open your hand, releasing your control of the"+
		" aqueous column.\n%^BOLD%^%^CYAN%^The water crashes down onto "+target->QCN+".");
    if (!(SAVING_D->saving_throw(target, "spell",0))) {
        tell_object(target,"%^CYAN%^"+caster->QCN+" opens "+caster->QP+" hand, "+
		"releasing "+caster->QP+" control of the aqueous column.\n"+
		"%^BOLD%^%^CYAN%^The water crashes down onto you!");
        tell_room(environment(target),"%^BOLD%^%^CYAN%^"+target->QCN+" is knocked flat"+
		" with the surging water that falls on "+target->QO+".",target);
        damage_targ(target,"torso",dam);
        if (!random(2)) {
            weapons = target->query_wielded();
            if (sizeof(weapons)) tell_object(target,"%^BOLD%^%^GREEN%^The surging water hits"+
			" you so hard that you cannot keep hold of your weapons!");
            for (i=0;i<sizeof(weapons);i++) {
                ids = weapons[i]->query_id();
                target->force_me("drop "+ids[0]);
            }
        }
    } else {
        dam = dam/2;
        damage_targ(target,"torso",dam);
        tell_object(target,"%^CYAN%^The surging water from "+caster->QCN+"'s aqueous column"+
		" grazes you.");
        tell_room(environment(target),"%^CYAN%^"+target->QCN+" narrowly avoids the crashing"+
		" water from "+caster->QCN+"'s aqueous column.",({target,caster}));
    }
    dest_effect();
    return;
}

void dest_effect() {
    ::dest_effect();
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Aqueous Column
Level  : 4th level
Sphere : Elemental Water
Deity  : Istishia
Syntax : chant aqueous column on <target>

This spell allows the caster to open a brief portal to the Plane of Water and create a column of pure water.  The caster can position the column above the head of anyone in the area.  When the caster releases control of the column, the surging waters crash down onto the target.  As the caster grows more powerful, she is able to draw more water into the column, thus allowing her aqueous column to do more damage.
HELP
);
    return 1;
}
