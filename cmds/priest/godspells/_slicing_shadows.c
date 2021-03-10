#include <std.h>

inherit SPELL;

object shadows;

void create() {
    ::create();
	set_author("cythera");
    	set_spell_name("slicing shadows");
    	set_spell_type("priest");
    	set_spell_sphere("evocation");
    	set_spell_level(4);
    	set_verbal_comp();
    	set_somatic_comp();
    	set_diety("mask");
}
string query_cast_string() {
    return "%^BLUE%^"+caster->QCN+" smirks as "+caster->QS+" "+
		"draws upon the shadows for aid!";
}

int preSpell() {
    if (!sizeof(caster->query_attackers())) {
        tell_object(caster,"You must be in the midst of showing the power
of your god to use this power, kill them all, and I will help.");
        return 0;
    }

    if (present(caster->query_name()+"shadows",place)) {
        tell_room(place,"%^BOLD%^%^BLACK%^You hear a cold "+
		"laughter from the shadows as "+caster->QCN+" "+
		"tries to demand more aid.",caster);
        tell_object(caster,"%^BOLD%^%^BLACK%^You hear a cold laughter"+
		" from the shadows as you try to demand more aid from Mask.");
        return 0;
    }
    return 1;
}

void spell_effect(int prof) {
    tell_room(place,"%^BOLD%^%^BLACK%^The shadows roll and bubble, "+
		"creating a cloud of darkness.  Whiplike whorls can be seen"+
		" within the dark cloud.");

    shadows = new("/d/magic/obj/slicing_shadows");
    shadows->set_damage(2,clevel/3);
    shadows->set_hd(clevel,100);
    shadows->set_attackers(caster->query_attackers());
    shadows->add_id(caster->query_name()+"shadows");
    shadows->move(place);
    place->add_combatant(shadows);
    shadows->set_property("spelled",({TO}));
    shadows->set_property("spell",TO);
    shadows->set_property("spell_creature", TO);
    caster->add_follower(shadows);
    call_out("dest_effect",10);

}

void dest_effect() {
    ::dest_effect();
    if (objectp(shadows)) {
        tell_room(environment(shadows),"%^BOLD%^%^BLACK%^The cloud of shadows melts away.");
        shadows->remove();

    }
    TO->remove();
}


int help() {
    write(
@CYTHERA
Spell  : Slicing Shadows
Level  : 4th Level
Sphere : Evocation
Deity  : Mask
Syntax : chant slicing shadows

This spell created a smoky cloud in which black whiplike
whorls of deeper darkness appear and disappear.  The 
slicing shadows will aid the priest in battle, 
cutting as if they were unbreakable, razor-sharp 
ribbons of steel. 
CYTHERA
);
    return 1;
}
