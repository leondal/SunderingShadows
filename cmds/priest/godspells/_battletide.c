//_battletide.c
//Based on Luckbolt by Circe with some code borrowed from Aura of Healing by Garrett - Cythera 5/05\\
#include <std.h>
#include <priest.h>
#define DELAY 1200

inherit SPELL;
int counter;
int mybonus;
string * my_party;

void create() {
    ::create();

    set_spell_name("battletide");
    set_spell_type("priest");
    set_spell_level(5);
    set_diety("tempus");
    set_spell_sphere("combat");
    set_target_required(1);
    set_verbal_comp();
}

string query_cast_string() {
   return "%^RED%^"+caster->QCN+" chants rapidly, invoking the power of Tempus.";

}

int preSpell() {

    if (target->query_property("blessed")) {
      tell_object(caster,"Your target is already inspired with divine blessings.");
        return 0;
    }
    if ((int)target->query_property("blessed time")+DELAY > time()) {
        tell_object(caster,"%^RED%^Tempus would not be pleased with his blessings called upon so soon.");
        return 0;
    }
    if ((string)target->query_diety()=="bane") {
        tell_object(target,"Tempus Foehammer will not grant his blessings to you!");
        return 0;
    }
	if (target->query_property("berserked")) {
        tell_object(caster,"%^BOLD%^%^RED%^The frenzy of Tempus is already upon you.");
		tell_object(target,"%^BOLD%^%^RED%^The frenzy of Tempus is already upon you.");
        return 0;
        }
    if (target->query_property("raged")) {
        tell_object(caster,"Rage already affects that person.");
        return 0;
    }
    if (target->query_property("rally")) {
        tell_object(caster,"They are already rallied to fight.");
        return 0;
    }
    else{
    	return 1;
	}
}


void spell_effect(int prof) {
      int clevel,mybonus;
	object * obarr;
      clevel = CLEVEL;
      mybonus = (clevel/10)+1;
	obarr = PARTY_D->query_party_members(caster->query_party());
  	my_party = ({});
  	if (pointerp(obarr))
  	my_party = obarr->query_true_name();
  	if (!sizeof(my_party)) my_party = ({ CASTER });
  	addSpellToCaster();
  	spell_successful();
  	execute_attack();

    if(target == caster){
       tell_room(place,"%^RED%^"+caster->QCN+" invokes the blessings of Tempus.",target);
       tell_object(target, "%^RED%^You feel your battle senses"+
		" heighted by the blessings of Tempus!");
    }else{
       tell_room(place,"%^RED%^"+caster->QCN+" chants rhythmically while"+
		" beating "+caster->QP+" "+
		"hands against "+caster->QP+" chest.",({target,caster}));
       tell_object(target,"%^RED%^"+caster->QCN+" chants rhythmically while"+
		" beating "+caster->QP+" hands against "+caster->QP+" chest,"+
		" invoking the blessings of Tempus.");
       tell_object(caster,"%^RED%^You chant rhythmically while beating your"+
		" hands against your chest, invoking the blessings of Tempus upon"+
		" you and your allies.");
    }
    target->add_attack_bonus(mybonus);
    target->add_damage_bonus(mybonus);
    target->set_property("blessed",1);
    target->set_property("spelled", ({TO}) );
    target->set_property("blessed",time());
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
    tell_room(place,"%^RED%^"+target->QCN+" looks insipired for battle.", target);
    tell_object(target,"%^RED%^You feel the blessings of Tempus upon"+
		" you, increasing your battle senses.");
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
        target->remove_property("blessed");
	  target->use_stamina(10); 
     	  tell_room(place,"%^RED%^"+target->QCN+" exhales deeply as "+
		 ""+target->QP+" body relaxes.", target);
	  tell_object(target,"%^RED%^You feel the blessings of Tempus leave you.");
    }
    ::dest_effect();
    remove();
}

int help() {
    write(
@CYTHERA
Spell  : Battletide
Level  : 5th Level
Sphere : Combat
Deity  : Tempus
Syntax : chant battletide at (target)

This prayer allows the priest to 
bless his/her party mates with the
power of Tempus.  The blessing 
will increase the battle sense 
of the party members, aiding 
the aim and force of their blows.  

CYTHERA
);
    return 1;
}
