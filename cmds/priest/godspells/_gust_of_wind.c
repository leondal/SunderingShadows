// _gust_of_wind.c - 8/05

#include <priest.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("gust of wind");
    set_author("cythera");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_sphere("elemental air");
	set_diety("shaundakul");
    set_target_required(1);
    set_somatic_comp();
    set_verbal_comp();
    set_immunities( ({ "spell_immunity"}) );
    set_xp_bonus(30);
}


spell_effect(int prof) {
    int clevel,effect, bonus;

    if(!objectp(caster) || !objectp(target)){
        dest_effect();
        return;
    }

    clevel = CLEVEL;
    place = environment(caster);
    tell_room(place, "%^CYAN%^"+caster->QCN+" holds out "+caster->QP+" "+
		"left hand and calls for Shaundakul's aid.",caster);
    
    tell_object(caster,"%^CYAN%^You hold out your left hand and call"+
		" for Shaundakul's aid. %^RESET%^");

    if (environment(target)!=place) {
        tell_object(caster,"%^BOLD%^Your target has left the area!%^RESET%^");
        dest_effect();
        return;
    }

    spell_successful();
    	tell_room(place,"%^CYAN%^A gust of intense winds issues forth "+
		"from "+caster->QCN+"'s left hand and slams into"+
		" "+target->QCN+".%^RESET%^",({caster,target}));
    	tell_object(caster,"%^CYAN%^A gust of intense winds issues forth from "+
		"your left hand and slams into "+target->QCN+".%^RESET%^");
    //effect = roll_dice(0+clevel,3);
    	tell_object(target,"%^CYAN%^A gust of intense winds issues forth from"+
		" "+caster->QCN+"'s left hand and slams into you.%^RESET%^");
            effect = (roll_dice(1 + (clevel / 2),6));
   
    if(SAVING_D->saving_throw(target,"spell")) { 
        effect = effect / 2;
    }
    damage_targ(target,target->return_target_limb(),effect);
    dest_effect();   

}

void dest_effect() {
    ::dest_effect();
    TO->remove();
}

int help(string str) {
    write(
@HELP
Spell  : Gust of Wind
Level  : 3rd Level
Sphere : Elemental Air
Deity  : Shaundakul
Syntax : chant gust of wind on <target>

Calling out to Shaundakul, the caster is able to generate
a brief but intense gust of wind.  Using his left hand the
caster directs the damaging winds into their target.  The
power of the gust of wind is dependant on the level of the caster.
HELP
);
    return 1;
}
