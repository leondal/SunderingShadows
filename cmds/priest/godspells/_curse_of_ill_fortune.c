//_curse_of_ill_fortune.c - Based on Luckbolt Code - Cythera 8/05

#include <std.h>
#include <priest.h>
#define DELAY 1200

inherit SPELL;
int counter;
int mybonus, newhp;

void create() {
    ::create();

    set_spell_name("curse of ill fortune");
    set_spell_type("priest");
    set_spell_level(6);
    set_diety("beshaba");
    set_spell_sphere("combat");
    set_target_required(1);
    set_verbal_comp();
}

string query_cast_string() {
   return "%^BOLD%^%^RED%^"+caster->QCN+" tosses "+caster->QP+" head back"+
		" back as "+caster->QS+" invokes the power of Beshaba!";

}

int preSpell() {

    if (target->query_property("misfortuned")) {
      tell_object(caster,"Your target is already blessed with the luck of Tymora.");
        return 0;
    }
    if ((int)target->query_property("misfortune time")+DELAY > time()) {
        tell_object(caster,"%^BOLD%^%^RED%^Beshaba finds its better to spread her misfortunes around.");
        return 0;
    }
    return 1;
}


void spell_effect(int prof) {
    int clevel,mybonus;
    clevel = CLEVEL;
    mybonus = random(clevel/6)+1;
    if(target == caster){
       tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" is suddenly"+
		" surrounded by crackling aura!",target);
       tell_object(target, "%^BOLD%^%^BLACK%^You feel the misfortunes "+
		"of Beshaba invading your life!");
    }else{
       tell_room(place,"%^BOLD%^%^BLACK%^"+caster->QCN+" cackles wildly as"+
		" "+caster->QS+" surrounds "+target->QCN+" with a crackling"+
		" aura!",({target,caster}));
       tell_object(target,"%^BOLD%^%^BLACK%^"+caster->QCN+" cackles wildly "+
		"as "+caster->QS+" surrounds you with a crackling aura! \n"+
		" %^BOLD%^%^MAGENTA%^You feel the misfortunes of Beshaba"+
		" invading your life!");
       tell_object(caster,"%^BOLD%^%^BLACK%^You cackle wildly as you surround"+
		" "+target->QCN+" with a crackling aura!");
    }
    target->add_attack_bonus(-1 * mybonus);
    target->add_damage_bonus(-1 * mybonus);
    target->set_property("misfortuned",1);
    target->set_property("spelled", ({TO}) );
    target->set_property("misfortune time",time());
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
    tell_room(place,"%^BOLD%^%^BLUE%^"+target->QCN+" is surrounded by a surge of energy.", target);
    tell_object(target,"%^BOLD%^%^BLUE%^You are surrounded by iridescent energy.");
    target->add_attack_bonus(mybonus);
    target->add_damage_bonus(mybonus);
    mybonus = random(clevel/6)+1;
    target->add_attack_bonus(-1 * mybonus);
    target->add_damage_bonus(-1 * mybonus);
    counter++;
    if (counter > clevel) {
        dest_effect();
        return;
    }
    place->addObjectToCombatCycle(TO,1);
}

dest_effect(){
    if (objectp(target)) {
        target->add_attack_bonus(mybonus);
        target->add_damage_bonus(mybonus);
        target->remove_property("misfortuned");
        tell_object(target,"%^BOLD%^%^RED%^You feel the misfortunes of Beshaba leave you.");
        tell_room(place,"%^BOLD%^%^BLACK%^The crackling black aura around"+
		" "+target->QCN+" fades away.", target);
    }
    ::dest_effect();
    remove();
}

int help() {
    write(
@CYTHERA
Spell  : Curse of Ill Fortune
Level  : 6th Level
Sphere : Combat
Deity  : Beshaba
Syntax : chant curse of ill fortune on <target>

Cursing the target with the misfortunes of Beshaba,
this spell is a potent weapon used by the faith of
the Maid of Misfortune.  The caster will affect the
combat abilities of the recipient for a duration.
The effects of the spell depend on the caster's
level as well as Beshaba's whim.


CYTHERA
);
    return 1;
}
