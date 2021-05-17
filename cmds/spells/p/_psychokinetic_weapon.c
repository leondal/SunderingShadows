// psywarrior power based on seeking sword
#include <magic.h>
#include <std.h>
#include <spell.h>

inherit SPELL;

object *animated,*monsters, control;
string arg;
int amount,mylevel;

void make_sword();

void create() {
    ::create();
    set_spell_name("psychokinetic weapon");
    set_spell_level(([ "psywarrior" : 4, ]));
    set_syntax("cast CLASS psychokinetic weapon");
    set_spell_sphere("psychokinesis");
    set_description("When the psionic character uses this power, it creates an "
       "ectoplasmic sword that floats in the air near the manifester. The sword "
       "can be commanded and will automatically follow the manifester and attack "
       "her enemies. If the sword becomes lost somehow, simply go into the room "
       "with it and <command sword to follow>.");
    set_verbal_comp();
    set_somatic_comp();
}

int preSpell()
{
	if(caster->query_property("seeking_sword"))
	{ //keeping the same variable so it cannot stack
        tell_object(caster, "%^CYAN%^You are incapable of controlling two swords.%^RESET%^");
        return 0;
    }
    return 1;
}

void spell_effect(int prof){
	if(!objectp(environment(caster))){
		dest_effect();
		return;
	}
	place = environment(caster);
	make_sword();
    spell_successful();
}

void make_sword(){
    object ob, thing;
    int dam;

    mylevel = clevel;

    tell_object(caster,"%^RESET%^%^CYAN%^You fix the image of a "
       "sword in your mind and wave your hand, pulling together "
       "strands of e%^MAGENTA%^c%^CYAN%^to%^BOLD%^p%^RESET%^%^CYAN%^"
       "la%^BOLD%^%^MAGENTA%^s%^RESET%^%^CYAN%^m that form a floating "
       "weapon to protect you.%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^With a wave of "+caster->QP+" hand, "
       ""+caster->QCN+" wills a sword made of e%^MAGENTA%^c%^CYAN%^to%^BOLD%^p%^RESET%^%^CYAN%^"
       "la%^BOLD%^%^MAGENTA%^s%^RESET%^%^CYAN%^m into existence%^RESET%^",caster);
    control = new("/d/magic/obj/swordremote");
    control->set_caster(caster);
    control->move(caster);
    control->set_property("spell",TO);
    control->set_property("spelled", ({TO}) );
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 4;
    set_end_time();
    call_out("dest_effect",spell_duration);
    ob=new("/d/magic/mon/psychokinetic_weapon");
    control->set_sword(ob);
    caster->add_follower(ob);
    ob->set_stats("intelligence",1);
/*
Lowering attack stats based on feedback from players
    ob->set_attacks_num((clevel/7)+1);
    ob->set_damage(1,(clevel/2));
    ob->set_stats("strength",18+(clevel/6));
*/
    dam = mylevel/4;
    if(dam < 1) dam = 1;
    ob->set_attacks_num(clevel/8+1);
    ob->set_damage(1,dam); //1d13ish max damage - previously was twice this with many more attacks
    ob->set_stats("strength",12+(dam/2));
    ob->set_overall_ac(5-mylevel);
    ob->set_hd(mylevel);
    ob->set_hp(mylevel*10);
    ob->set_max_hp(ob->query_hp());
    ob->set_caster(caster);
    ob->set_property("spell",TO);
    ob->set_property("spell", ({TO}) );
    ob->set_property("spell_creature", TO);
    ob->set_property("effective_enchantment",dam);
    ob->move(environment(caster));
    caster->set_property("seeking_sword",ob);
    ob->set_property("minion", caster);
    return;
}

void dest_effect(){
    object sword;

    if (objectp(caster)) {
        tell_room(environment(caster),"%^RESET%^%^MAGENTA%^The e%^CYAN%^c"
           "%^MAGENTA%^to%^BOLD%^p%^RESET%^%^MAGENTA%^la%^BOLD%^%^CYAN%^s"
           "%^RESET%^%^MAGENTA%^mi%^CYAN%^c%^MAGENTA%^ sword in front of "
           ""+caster->QCN+" vanishes abruptly.%^RESET%^",caster);
        tell_object(caster,"%^RESET%^%^MAGENTA%^Your e%^CYAN%^c%^MAGENTA%^"
           "to%^BOLD%^p%^RESET%^%^MAGENTA%^la%^BOLD%^%^CYAN%^s%^RESET%^"
           "%^MAGENTA%^mi%^CYAN%^c%^MAGENTA%^ sword vanishes abruptly.%^RESET%^");
    }

	if(objectp(control))
	{
		if (objectp(sword = control->query_sword()))
		{
			sword->remove();
			destruct(control);
		}
	}
        if(objectp(caster)) { caster->remove_property("seeking_sword"); }
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}
