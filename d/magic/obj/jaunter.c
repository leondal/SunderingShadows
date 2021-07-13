#include <rooms.h>
#include <security.h>
#include <daemons.h>
#include <move.h>
#include <objects.h>
#include <user.h>
#include <std.h>
inherit OBJECT;

object caster, *targets;

void create(){
    set_name("jaunter999");
    set_id(({"jaunter999"}));
    set_short(0);
    set_invis();
    set_property("no detect",1);
}

int is_detectable(){ return 0;}

int id(string str){
    if(objectp(TP) && !avatarp(TP)) return 0;
    else return ::id(str);
}

void set_invis() {
    if (TO->query_invis()) return;
    else ::set_invis();
    return;
}

void init(){
   ::init();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   caster = ETO;
   input_to("jaunt");
}

void set_targs(object *targs) {
    targets = targs;
}

void jaunt(string str) {
    object targ, destination;
    int index;
    if(!regexp(str, "[0-9]+")) {
        tell_object(caster,"%^RED%^You decide not to take a cruel jaunt.%^RESET%^");
        if(objectp(TO)) TO->remove();
        return;
    }
    index = to_int(str);
    if(!intp(index) || index > (sizeof(targets) - 1) || index < 0) {
        tell_object(caster,"%^RED%^You decide not to take a cruel jaunt.%^RESET%^");
        if(objectp(TO)) TO->remove();
        return;
    }
    if(!objectp(targ = targets[index]) || !objectp(destination = environment(targ))) {
        tell_object(caster,"%^RED%^Your target has escaped.%^RESET%^");
        if(objectp(TO)) TO->remove();
        return;
    }

    tell_object(caster,"%^BOLD%^%^BLACK%^You reach out towards the tendrils of fear and feel yourself being pulled!%^RESET%^");
    caster->move(destination);
    caster->force_me("look");
    tell_object(caster,"%^BOLD%^%^BLACK%^Your cruel jaunt is complete!%^RESET%^");

    if(objectp(TO)) TO->remove();
}
