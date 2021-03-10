// _kiss_of_beshaba.c - 8/05

#include <priest.h>
#include <std.h>
#include <daemons.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("kiss of beshaba");
    set_author("cythera");
    set_spell_level(3);
    set_spell_type("priest");
    set_spell_sphere("combat");
	set_diety("beshaba");
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
    tell_room(place, "%^BOLD%^%^MAGENTA%^%^"+caster->QCN+" rakes "+caster->QP+" "+
		"right hand through the air while calling out to Beshaba.",caster);
    
    tell_object(caster,"%^CYAN%^You rake your right hand through the air "+
		"while calling out to Beshaba. %^RESET%^");

    if (environment(target)!=place) {
        tell_object(caster,"%^BOLD%^Your target has left the area!%^RESET%^");
        dest_effect();
        return;
    }

    spell_successful();
	switch(random(5)){
	{	
	case 0:
    	tell_room(place,"%^BOLD%^%^BLACK%^A black cat moves under "+target->QCN+"'s"+
		" feet, sending "+target->QO+" falling to the "+
		"ground.%^RESET%^",({caster,target}));
    	tell_object(caster,"%^BOLD%^%^BLACK%^A black cat moves under "+target->QCN+"'s"+
		" feet, sending "+target->QO+" falling to the ground.%^RESET%^");
    	tell_object(target,"%^BOLD%^%^BLACK%^A black cat moves under your feet,"+
		" sending you falling to the ground.%^RESET%^");
      break;
	case 1:
	tell_room(place,"%^BOLD%^%^MAGENTA%^In a puff of black smoke a mirror"+
		" appears in the path of "+target->QCN+", causing "+target->QO+" "+
		"to smash it into pieces!%^RESET%^",({caster,target}));
    	tell_object(caster,"%^BOLD%^%^MAGENTA%^You create a mirror in the path"+
		" of "+target->QCN+", causing "+target->QO+" to smash it into"+
		" pieces.%^RESET%^");
    	tell_object(target,"%^BOLD%^%^MAGENTA%^In a puff of black smoke a mirror"+
		" appear in your path, causing you to smash it into pieces and slice"+
		" yourself up!%^RESET%^");
     	break;
	case 2:
	tell_room(place,"%^BOLD%^%^RED%^A large bird keels over in mid-flight "+
		"and falls onto "+target->QCN+"'s head.%^RESET%^",({caster,target}));
    	tell_object(caster,"%^BOLD%^%^RED%^A large bird keels over in mid-flight"+
		" and falls onto "+target->QCN+"'s head.%^RESET%^");
    	tell_object(target,"%^BOLD%^%^RED%^A large bird keels over in mid-flight"+
		" and falls onto your head!%^RESET%^");
	break;
	case 3:
	tell_room(place,"%^BOLD%^%^WHITE%^A stray arrow ricochets off the ground"+
		" and pierces "+target->QCN+"'s leg!%^RESET%^",({caster,target}));
    	tell_object(caster,"%^BOLD%^%^WHITE%^A stray arrow ricochets off the "+
		"ground and pierces "+target->QCN+"'s leg.%^RESET%^");
    	tell_object(target,"%^BOLD%^%^WHITE%^A stray arrow ricochets off the"+
		" ground and pierces your leg!%^RESET%^");
  	break;
	default:
	tell_room(place,"%^MAGENTA%^A flaming rock whistles through the sky and"+
		" conks "+target->QCN+" on the head!%^RESET%^",({caster,target}));
    	tell_object(caster,"%^MAGENTA%^A flaming rock whistles through the sky"+
		" and conks "+target->QCN+" on the head.%^RESET%^");
    	tell_object(target,"%^MAGENTA%^A flaming rock whistles through the "+
		"sky and conks you on the head!%^RESET%^");
      break;
		return 1;
	}
	}
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
Spell  : Kiss of Beshaba
Level  : 3rd Level
Sphere : Combat
Deity  : Beshaba
Syntax : chant kiss of beshaba on <target>

Invoking the misfortunes of Beshaba, this prayer allows the caster to curse the target with some calamity.  The effects of the spell are random, though the target will suffer some kind of unfortunate event.

HELP
);
    return 1;
}
