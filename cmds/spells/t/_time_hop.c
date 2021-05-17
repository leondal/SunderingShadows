//Psionic web, based on will save
#include <spell.h>
#include <magic.h>

inherit SPELL;

object oldenv, web, mass;
int waittime;

void dest_effect();
void waiter(int num);

void create() {
    ::create();
    set_spell_name("time hop");
    set_spell_level(([ "psion" : 3 ]));
    set_syntax("cast CLASS time hop on TARGET");
    set_spell_sphere("psychoportation");
    set_description("The target of this power hops forward in time, "
       "disappearing in a flash of silver energy. When the duration "
       "expires, the target reappears, feeling as if no time has passed "
       "at all. Victims with a strong enough will are able to resist the "
       "power's strength and either avoid it altogether or end the power early.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_property("keywords", ({ "offensive", "targeted", }));
    set_save("will");
}

spell_effect(int prof) {
    int save, neededroll, power;
    string strength;

    if (!present(target,environment(caster))) {
        tell_object(caster,"%^BOLD%^Your target is not in this area.\n");
        TO->remove();
        return;
    }
    if(!caster->ok_to_kill(target)) {
        dest_effect();
        return 0;
    }
    tell_object(caster,"%^RESET%^%^CYAN%^You hold your hands out, palms "
       "forward, as you concentrate on "+target->QCN+".%^RESET%^");
    tell_object(target,"%^RESET%^%^CYAN%^With a look of intense concentration, "
       ""+caster->QCN+" faces you with "+caster->QP+" hands out, palms forward.%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^With a look of intense concentration, "+caster->QCN+" "
       "faces "+target->QCN+" with "+caster->QP+" hands out, palms forward.%^RESET%^", ({caster, target}) );
    waittime=10;
    power=target->query_stats("wisdom");
    if (power > 17) {
        waittime=to_int(waittime/2);
    }
    if (power <= 13 && power >= 9) {
        waittime=waittime*2;
    }
    if (power < 9) {
        waittime=waittime*4;
    }
    spell_successful();
    if ( do_save(target,-2) || target->query_property("no web") || prof < random(100)) {
        tell_object(caster,"%^BOLD%^%^CYAN%^"+target->QCN+"'s will is so strong "+target->QS+" "
           "shakes off your attempt to send "+target->QO+" forward in time!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^You feel a force push against your mind "
           "but manage to fight it off!%^RESET%^");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+target->QCN+" fights off "
           "the force of "+caster->QCN+"'s attack!%^RESET%^",({caster, target}) );
        dest_effect();
        return;
    } else {
        spell_successful();
        tell_object(caster,"%^BOLD%^%^WHITE%^Unable to withstand the force of your "
           "mental onslaught, "+target->QCN+" winks out of existence in a flash of "
           "%^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^light!%^RESET%^");
        tell_object(target,"%^BOLD%^%^WHITE%^The world around you vanishes, "
           "leaving you in a %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^"
           "r%^RESET%^y %^BOLD%^haze!%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^"+target->QCN+" winks out of existence in "
           "a flash of %^RESET%^s%^BOLD%^i%^RESET%^l%^BOLD%^v%^RESET%^e%^BOLD%^r"
           "%^RESET%^y %^BOLD%^light!%^RESET%^", ({caster,target}) );
    }
    oldenv=environment(target);
    mass=new("/d/magic/obj/timemass.c");
    mass->set_spell(TO);
    mass->move(oldenv);
    web=new("/d/magic/room/in_time.c");
    target->move(web);
    addSpellToCaster();
    call_out("waiter",ROUND_LENGTH,1);
}

void waiter(int num) {
    object *tempinv;
    if(!target || !objectp(web)){
        dest_effect();
        return;
    }
    if (!present(target,web)) {
        mass->remove();
        web->move("/d/shadowgate/void.c");
        while ( tempinv=(object *)web->all_inventory() ) {
            tempinv[0]->move(oldenv);
            return;
        }
    }
    if ( (num%2) )
        tell_object(target,"You feel a twinge of something "
           "tugging at your memory before it slips away again.");
    if (num < waittime)
        call_out("waiter",ROUND_LENGTH,num+1);
    else
        dest_effect();
    return;
}

void dest_effect() {
    int i;
    object *tempinv;


    if (objectp(mass))
        mass->remove();
    if (objectp(target) && objectp(web))
        if (present(target,web)) {
            tell_object(target,"%^BOLD%^%^CYAN%^You lurge forward into time once more!%^RESET%^");
            tell_room(place,"%^BOLD%^%^CYAN%^The %^RESET%^s%^BOLD%^i%^RESET%^l"
               "%^BOLD%^v%^RESET%^e%^BOLD%^r%^RESET%^y %^BOLD%^%^CYAN%^haze dissipates "
               "as "+target->QCN+" suddenly appears!%^RESET%^",target );
            target->move(oldenv);
            tempinv=all_inventory(web);
            for (i=0;i++;i<sizeof(tempinv)) {
                if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
            }
        }
    if (objectp(target) && objectp(web)) {
        if (!present(target,web)) {
            tempinv=all_inventory(web);
            for (i=0;i++;i<sizeof(tempinv)) {
                if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
            }
            TO->remove();
        }
    } else if(objectp(web)) {
        tempinv=all_inventory(web);
        for (i=0;i++;i<sizeof(tempinv)) {
            if (objectp(tempinv[i])) tempinv[i]->move(oldenv);
        }
        TO->remove();
        web->remove();
    } else {
        TO->remove();
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
    return;
}
