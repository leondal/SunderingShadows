// Shout

#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;

void dest_effect();

create() {
    ::create();
    set_author("cythera");
    set_spell_name("shout");
    set_spell_level(([ "mage" : 4, "bard" : 4, "magus" : 4 ]));
    set_spell_sphere("invocation_evocation");
    set_syntax("cast CLASS shout on TARGET");
    set_description("This spell allows for the mage to magically enchant and enhance their voice to deliver a strong sonic attack against one target.  The amplified voice can knock some targets off balance for a moment, forcing them to spend some time for the ringing in their ears to pass.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
    set_immunities(({"sonic"}));
}

string query_cast_string() {
    return "%^BOLD%^%^CYAN%^"+caster->QCN+" chants a rhythmic phrase and then takes a deep breath.";
}

spell_effect(int prof) {
    int num;
    string target_limb;
    spell_successful();

    if (environment(caster) != environment(target)) {
        tell_object(caster,"Your target has left your range.\n");
        dest_effect();
        return;
    }

    target_limb = target->return_target_limb();
    if (interactive(caster)) {
        tell_object(caster,"%^BOLD%^%^MAGENTA%^Your voice is magically amplified as you shout at "+
        	""+target->QCN+".");
        tell_object(target,"%^MAGENTA%^%^BOLD%^"+caster->QCN+"'s voice is magically"+
		" amplified as "+caster->QS+" shouts at you!\n%^CYAN%^The force of the"+
		" sonic attack sends your ears ringing for a moment, leaving you"+
		" disoriented.");
        tell_room(place,"%^MAGENTA%^%^BOLD%^"+caster->QCN+"'s voice"+
			" is magically amplified as "+caster->QS+" shouts at"+
			" "+target->QCN+"!",({ caster, target}) );

    } else {
        tell_object(target,"%^MAGENTA%^%^BOLD%^"+caster->QCN+"'s voice"+
		" is magically amplified as "+caster->QS+" shouts at you!"+
		"\n%^CYAN%^The force of the sonic attack sends your ears "+
		"ringing for a moment, leaving you disoriented.");
        tell_room(place,"%^MAGENTA%^%^BOLD%^"+caster->QCN+"'s voice is "+
		"magically amplified as "+caster->QS+" shouts at "+
            ""+target->QCN+"!", target);
    }
/*
    if (!do_saving_throw(target, "spell", (4-prof/25))) {
*/
    if(!do_save(target)) {
        tell_object(target,"%^CYAN%^%^BOLD%^You are blasted with"+
		" the sonic force of "+caster->QCN+"'s shout.");
        tell_room(environment(caster),"%^CYAN%^%^BOLD%^"+target->QCN+" is "+
		"blasted with the sonic waves of "+caster->QCN+"'s "+
		"shout.", ({ target}) );
        		damage_targ(target, target_limb, sdamage,"sonic");
			target->set_paralyzed(random(7)+5,"%^BOLD%^%^CYAN%^Your ears are ringing!");

    } else {
        tell_object(target,"%^BOLD%^%^CYAN%^You are blasted by the sonic"+
		" waves of "+caster->QCN+"'s shout.");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+target->QCN+" is"+
		" blasted with the sonic force of "+caster->QCN+"'s "+
		"shout!",({ target}) );
        		damage_targ(target, target_limb, to_int(sdamage / 2),"sonic" );
    }
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
