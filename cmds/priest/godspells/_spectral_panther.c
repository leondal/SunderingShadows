// Saide@ShadowGate
// April 10 2004

#include <priest.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("spectral panther");
    set_author("cythera");
    set_spell_level(4);
    set_spell_type("priest");
    set_spell_sphere("death");
	set_diety("kelemvor");
    set_target_required(1);
    set_somatic_comp();
    set_verbal_comp();
    set_immunities( ({ "spell_immunity"}) );
    set_xp_bonus(40);
}


spell_effect(int prof) {
    int clevel,effect, bonus;

    if(!objectp(caster) || !objectp(target)){
        dest_effect();
        return;
    }

    clevel = CLEVEL;
    place = environment(caster);
    tell_room(place, "%^GREEN%^A spectral panther takes"+
		" shape as "+caster->QCN+" chants in a low tone!",caster);
    
    tell_object(caster,"%^GREEN%^A spectral panther takes"+
		" shape as you chant in a low tone.%^RESET%^");

    if (environment(target)!=place) {
        tell_object(caster,"%^BOLD%^Your target has left the area!%^RESET%^");
        dest_effect();
        return;
    }
    if (roll_dice(1,20) < thaco(target,0)) {
	tell_object(caster,"%^BOLD%^%^WHITE%^The spectral panther misses its"+
		"lunge at "+target->QCN+" and fades away in"+
		" a hazy mist.%^RESET%^");
     	tell_room(place,"%^BOLD%^%^WHITE%^The spectral panther next to"+
		""+caster->QCN+" lunges at "+target->QCN+" and misses! \n The"+
		"panther fades away into a hazy mist.%^RESET%^",({target,caster}));
      tell_object(target,"%^BOLD%^%^WHITE%^The spectral panther next to"+
		""+caster->QCN+" lunges at you and misses! \n  The panther fades away"+
		" into a hazy mist.%^RESET%^");
        dest_effect();
        return;
    }

    spell_successful();
    	tell_room(place,"%^BOLD%^%^WHITE%^The spectral panther next to"+
		""+caster->QCN+" lunges at "+target->QCN+", slicing through"+
		" "+target->QO+" with its claws. \n The panther fades away into"+
		" a hazy mist.%^RESET%^",({caster,target}));
    tell_object(caster,"%^BOLD%^%^WHITE%^The spectral panther next to"+
		" you lunges at "+target->QCN+", slicing through "+target->QO+" "+
		"with its claws.\n The panther fades away into a hazy mist.%^RESET%^");
    effect = roll_dice(0+clevel,6);
    tell_object(target,"%^BOLD%^%^WHITE%^The spectral panther next to"+
		""+caster->QCN+" lunges at you, slicing through you with its"+
		" claws. \n The panther fades away into a hazy mist.%^RESET%^");
    if(target->query_property("undead") 
    || (string)target->query_race() == "undead") {
        effect = (roll_dice(1 + clevel,8));
    }
    else {
        effect = (roll_dice(1 + clevel,6));
    }
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
Spell  : Spectral Panther
Level  : 4th Level
Sphere : Necromantic
Deity  : Kelemvor
Syntax : chant spectral panther on <target>

With this prayer, the priest creates a spectral 
panther out of positive energy.  Once the panther 
has been formed the priest is able to give a 
mental command to it, directing it to strike.  
The panther gets one chance to attack before it fades
away.  Because the panther is composed of positive
engergy, its claws deal a greater damage to undead.


HELP
);
    return 1;
}
