//_boon_of_lathander.c
//Based on Luckbolt by Circe - Cythera 5/05\\
#include <std.h>
#include <priest.h>
#define DELAY 1200

inherit SPELL;
int counter;
int mybonus;

void create() {
    ::create();

    set_spell_name("boon of lathander");
    set_spell_type("priest");
    set_spell_level(6);
    set_diety("lathander");
    set_spell_sphere("combat");
    set_target_required(1);
    set_verbal_comp();
}

string query_cast_string() {
   return "%^BOLD%^%^MAGENTA%^"+caster->QCN+" calls for the power of Lathander.";

}

int preSpell() {

    if (target->query_property("booned")) {
      tell_object(caster,"Your target is already blessed with the boon of Lathander.");
        return 0;
    }
    if ((int)target->query_property("boon time")+DELAY > time()) {
        tell_object(caster,"%^BOLD%^%^MAGENTA%^Lathander would not"+
		" be happy to have his boon invoked so soon.");
        return 0;
    }
    if (!((string)target->query_diety()=="lathander")) {
        tell_object(caster,"Only the faithful may receive the boon of Lathander.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof) {
    int clevel,mybonus;
    clevel = CLEVEL;
    mybonus = (clevel/7)+1;
    if(target == caster){
       tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" is surrounded by a rose-red aura.",target);
       tell_object(target, "%^BOLD%^%^MAGENTA%^A rose-red aura surrounds"+
		" you as you feel the boon of Lathander bless you!");
    }else{
       tell_room(place,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" spreads "+caster->QP+" "+
		"hand and outlines "+target->QCN+" with a rose-red aura.",({target,caster}));
       tell_object(target,"%^BOLD%^%^MAGENTA%^"+caster->QCN+" spreads "+caster->QP+""+
		" hand and outlines you with a rose-red aura, blessing you with"+
		" the boon of Lathander.");
       tell_object(caster,"%^BOLD%^%^MAGENTA%^You spread your hand and point"+
		" to "+target->QCN+""+
		" outlining "+target->QS+" with a rose-red aura.");
    }
    target->add_attack_bonus(mybonus);
    target->add_saving_bonus("all",(mybonus));
    target->set_property("booned",1);
    target->set_property("spelled", ({TO}) );
    target->set_property("booned time",time());
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
    tell_room(place,"%^BOLD%^%^MAGENTA%^A rose-red aura surrounds "+target->QCN+".", target);
    tell_object(target,"%^BOLD%^%^MAGENTA%^You feel the boon of Lathander aiding you.");
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
        target->add_saving_bonus("all",(-1 * mybonus));
        target->remove_property("booned");
     	  tell_room(place,"%^BOLD%^%^MAGENTA%^The rose-red aura around"+
		" "+target->QCN+" fades away into a shower of golden motes of light.", target);
	  tell_object(target,"%^BOLD%^%^MAGENTA%^The rose-red aura around"+
		" you fades away into a shower of golden motes of light.");
    }
    ::dest_effect();
    remove();
}

int help() {
    write(
@CYTHERA
Spell  : Boon of Lathander
Level  : 6th Level
Sphere : Combat
Deity  : Lathander
Syntax : chant boon of lathander on <target>

Invoking the blessings of Lathander, this
spell will grant the target a heightened 
sense in battle and a blessing on resisting
some attacks (saving throws).  The target 
is outlined in a rose-red glow while the
spell is in effect.  Only those who follow
Lathander can recieve this blessing.

CYTHERA
);
    return 1;
}
