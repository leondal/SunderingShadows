//Insect plague reskin for warlock

#include <spell.h>
#include <magic.h>
#include <rooms.h>
#include <daemons.h>

inherit SPELL;

void fail();

object *mons;
object swarm;
int num;

create() {
    ::create();
    set_spell_name("tenacious plague");
    set_spell_level(([ "warlock" : 3 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS tenacious plague");
    set_description("This invocation of a conjuration/summoning nature calls forth all the stinging, flying, crawling, "
"creeping and biting insects within a one mile radius to swarm together within the immediate surroundings of the caster. "
"The swarm will then annoy and harm everything in the area except the one who summoned it. If cast within the presence "
"of other beings, the caster may find that the swarm annoys its victims so much that they attack the caster out of anger "
"and fear. At anytime the caster may send the swarm away by: <disperse swarm>.");
    set_verbal_comp();
    set_somatic_comp();
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

int preSpell() {
    if (present("swarm", place)) {
        tell_object(caster, "%^BOLD%^%^GREEN%^Enough insects plague this region already!%^RESET%^");
        return 0;
    }
    return 1;
}

spell_effect(int prof) {
    if (target) {
        fail();
    } else {
        mons=all_inventory(environment(caster));
        if(FEATS_D->usable_feat(caster,"perfect caster"))
        {
            mons = filter_array(mons,"perfect_filter",TO);
        }
        for (num=0;num<sizeof(mons);num++) {
            if (living(mons[num]) && mons[num] != caster && !userp(mons[num])) {
                tell_object(caster,"%^BOLD%^%^WHITE%^"+mons[num]->QCN+" is angered that you summoned the swarm of insects and attacks you!%^RESET%^");
                if (objectp(caster->query_in_vehicle()) && mons[num] == caster->query_in_vehicle()) continue;
                if (!spell_kill(caster, mons[num])) return 1;
            }
        }
        swarm=new("/d/magic/mon/swarm.c");
        swarm->setup_swarm(caster,clevel);
        swarm->move(environment(caster));
        caster->set_property("swarm",1);
        tell_object(caster,"%^BOLD%^%^GREEN%^The swarm begins to bite and sting everything in the area but you!%^RESET%^");
         tell_room(place,"%^BOLD%^%^GREEN%^The swarm fills the area stinging and biting everything in its path but "+caster->QCN+"!%^RESET%^",caster);
        dest_effect();
    }
}

void fail() {
    tell_object(caster,"%^CYAN%^Your invocation utterly fails!");
    tell_room(environment(caster),"%^CYAN%^"+caster->QCN+" seems disappointed.", caster);
    TO->remove();
    return;
}

void dest_effect() {
//    CASTER->remove_property("swarm");
//    swarm->remove();
//    tell_room(environment(CASTER), "%^RESET%^%^GREEN%^The swarm suddenly scatters completely and disperses in numerous directions!");
    ::dest_effect();
    if(objectp(TO)) TO->remove();

}

string query_cast_string() {
    return "%^BOLD%^%^BLACK%^"+caster->QCN+" puts their hands together where e%^RESET%^%^GREEN%^l%^BOLD%^d%^RESET%^r%^BOLD%^i%^BLACK%^tch e%^RESET%^%^GREEN%^n%^BOLD%^e%^RESET%^r%^BOLD%^g%^BLACK%^y f%^RESET%^%^GREEN%^o%^BOLD%^r%^RESET%^m%^BOLD%^s%^BLACK%^.";
}
