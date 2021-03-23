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
    set_spell_name("imprisonment");
    set_spell_level(([ "oracle" : 9, "mage" : 9, "cleric" : 9 ]));
    set_mystery("godclaw");
    set_domains("law");
    set_syntax("cast CLASS imprisonment on TARGET");
    set_spell_sphere("abjuration");
    set_description("This spell puts your target into extraplanar prison, temporary removing them from existence.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("will");
}

spell_effect(int prof) {
    int save, neededroll, power;
    string strength;

    tell_object(caster,"%^RESET%^%^CYAN%^You hold your hands out, palms "
                "forward, as you concentrate on "+target->QCN+".%^RESET%^");
    tell_object(target,"%^RESET%^%^CYAN%^With a look of intense concentration, "
                ""+caster->QCN+" faces you with "+caster->QP+" hands out, palms forward.%^RESET%^");
    tell_room(place,"%^RESET%^%^CYAN%^With a look of intense concentration, "+caster->QCN+" "
              "faces "+target->QCN+" with "+caster->QP+" hands out, palms forward.%^RESET%^", ({caster, target}) );
    waittime=clevel + 10;
    spell_successful();
    if ( do_save(target,-4) || target->query_property("no web")) {
        tell_object(caster,"%^BOLD%^%^CYAN%^"+target->QCN+"'s will is so strong "+target->QS+" shakes off your attempt to imprison "+target->QO+"!%^RESET%^");
        tell_object(target,"%^BOLD%^%^CYAN%^You feel a force push against your mind but manage to fight it off!%^RESET%^");
        tell_room(environment(caster),"%^BOLD%^%^CYAN%^"+target->QCN+" fights off the force of "+caster->QCN+"'s attack!%^RESET%^",({caster, target}) );
        dest_effect();
        return;
    } else {
        spell_successful();
        tell_object(caster,"%^BOLD%^%^WHITE%^Unable to withstand the force of your will, "+target->QCN+" winks out of existence in a flash of light!%^RESET%^");
        tell_object(target,"%^BOLD%^%^WHITE%^The world around you vanishes, leaving you in a haze!%^RESET%^");
        tell_room(place,"%^BOLD%^%^WHITE%^"+target->QCN+" winks out of existence in a flash of light!%^RESET%^", ({caster,target}) );
    }
    oldenv=environment(target);
    mass=new("/d/magic/obj/prison.c");
    mass->set_spell(TO);
    mass->move(oldenv);
    mass->set_property("spelled", ({ TO }));
    mass->set_long(target->query_long());
    web=new("/d/magic/room/in_prison.c");
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
            tell_object(target,"%^BOLD%^%^CYAN%^You reappear in normal space!%^RESET%^");
            tell_room(place,"%^BOLD%^"+target->QCN+" suddenly appears!%^RESET%^",target );
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
