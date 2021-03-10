//_righteous_fury.c
//Based on Luckbolt by Circe - Cythera 5/05\\
#include <std.h>
#include <priest.h>
#define DELAY 1200

inherit SPELL;
int counter;
int mybonus;

void create() {
    ::create();

    set_spell_name("righteous fury");
    set_spell_type("priest");
    set_spell_level(6);
    set_diety("tyr");
    set_spell_sphere("combat");
    set_target_required(1);
    set_verbal_comp();
}

string query_cast_string() {
   return "%^MAGENTA%^"+caster->QCN+" invokes the power of Tyr.";

}

int preSpell() {

    if (target->query_property("furied")) {
      tell_object(caster,"Your target is already blessed with the righteous fury of Tyr.");
        return 0;
    }
    if ((int)target->query_property("fury time")+DELAY > time()) {
        tell_object(caster,"%^MAGENTA%^Tyr would not be to happy if you invoked his righteous fury so soon.");
        return 0;
    }
    if (!((string)target->query_diety()=="tyr")) {
        tell_object(caster,"Only the faithful may receive righteous fury of Tyr.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof) {
    int clevel,mybonus;
    clevel = CLEVEL;
    mybonus = (clevel/7)+1;
    if(target == caster){
       tell_room(place,"%^MAGENTA%^"+caster->QCN+" calls upon the power of Tyr.",target);
       tell_object(target, "%^MAGENTA%^You feel the righteous fury of Tyr fall upon you!");
    }else{
       tell_room(place,"%^MAGENTA%^"+caster->QCN+" motions "+caster->QP+" "+
		"hand at "+target->QCN+".",({target,caster}));
       tell_object(target,"%^MAGENTA%^"+caster->QCN+" motions "+caster->QP+""+
		" hand at you, filling you with the righteous fury of Tyr!");
       tell_object(caster,"%^MAGENTA%^You motions your hand at "+target->QCN+""+
		" filling "+target->QS+" with the rigtheous fury of Tyr.");
    }
    target->add_attack_bonus(mybonus);
    target->add_damage_bonus(mybonus);
    target->set_property("furied",1);
    target->set_property("spelled", ({TO}) );
    target->set_property("fury time",time());
}

int flag;

void execute_attack(){
    if (!flag) {
        ::execute_attack();
        flag = 1;
        return;
    }
    if (!objectp(target)) {
        dest_effect();
        return;
    }
    tell_room(place,"%^MAGENTA%^"+target->QCN+" has a determined"+
		" look in "+target->QP+" eyes.", target);
    tell_object(target,"%^MAGENTA%^You feel the righteous fury of"+
		" Tyr coursing through your body.");
      counter++;
    if (counter > clevel) {
        dest_effect();
        return;
    }
    place->addObjectToCombatCycle(TO,1);
}

dest_effect(){
    if (objectp(target)) {
        target->add_attack_bonus(-1 * mybonus);
        target->add_damage_bonus(-1 * mybonus);
        target->remove_property("furied");
	  target->use_stamina(25); 
     	  tell_room(place,"%^MAGENTA%^"+target->QCN+" gives an exhausted"+
		" sigh as "+target->QP+" shoulders slump.", target);
	  tell_object(target,"%^MAGENTA%^You feel the righteous fury of Tyr leave you.");
    }
    ::dest_effect();
    remove();
}

int help() {
    write(
@CYTHERA
Spell  : Righteous Fury
Level  : 6th Level
Sphere : Combat
Deity  : Tyr
Syntax : chant righteous fury on <target>

Calling upon the righteous fury of Tyr, this spell
will allow a priest to bless himself or a faithful
with heightened battle senses, allowing them to 
aid in bringing justice to the lands.  The 
spell can only be cast on a follower of Tyr, and
will leave the target physically drained afterwards.

CYTHERA
);
    return 1;
}
