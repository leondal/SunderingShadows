// Monster Summoning 1 - Coded by Vashkar@shadowgate
#include <spell.h>
#include <magic.h>
#include <rooms.h>
inherit SPELL;

int check(mixed *arg);
void dest_effect();
void defend(object caster, object *foes);

object *mons;

void create() {
    ::create();
    set_spell_sphere("conjuration_summoning");
    set_description("This spell will summon monsters of equivalent power to protect the caster.  They will react "
"aggressively to anyone attempting to harm the caster. They will fight till slain, and when the casting time is up, the "
"monsters will vanish.");
    set_verbal_comp();
    set_somatic_comp();
    set_components(([
      "mage" : ([ "tiny bag" : 1, "small candle" : 1, ]),
    ]));
    set_helpful_spell(1);
}

string query_cast_string() {
    return caster->QCN+" chants loudly towards the "+
    "sky as "+caster->QS+" pulls a small "+
    "candle out of a tiny bag and lights it.";
}

int preSpell() {
    if (present(caster->query_name()+" summoned", place)) {
        tell_object(caster,"You have monsters under your control already.");
        return 0;
    }
    return 1;
}

int getNumMon(){
    return roll_dice(2,query_spell_level(spell_type));
}

object createMon(){
    error("Called function that never meant to be called.");
}

spell_effect(int prof) {
    object mon,oldenv,*foes,*oldattackers;
    int chooser,num,num2,numfoes,randnum,nummon,timestart;

    spell_successful();
    oldenv=environment(caster);
    nummon=getNumMon()*prof/100;
    numfoes=(sizeof(caster->query_attackers()));
    mons=allocate(nummon);
    foes=caster->query_attackers();
    for (num=1;num<=nummon;num++) 
    {
        mon = createMon();
        mons[num-1] = mon;
        if (!objectp(mon)) continue;
        mon->set("aggressive", 1);
        mon->add_id(caster->query_name()+" summoned");
        mon->add_id("monster");
        mon->add_id("summoned monster");
        mon->set_short("monster");
        if (interactive(caster)) mon->set_exp(0);
        mon->remove_property("swarm");
        mon->set_property("spelled", ({TO}) );
        mon->set_property("spell", TO);
        mon->set_property("spell_creature", TO);
        mon->set_property("minion", caster);
        caster->add_protector(mon);
        mon->move(place);
        caster->add_follower(mon);
        tell_room(place,mon->query_short()+" appears near "+caster->QCN+".", caster);
        tell_object(caster, mon->query_short()+" appears near you.");
        if (foes != ({}) && target != caster) {
            for (num2=0;num2<numfoes;num2++) {
                spell_kill(mon, foes[num2]);
                tell_object(foes[num2], "%^BOLD%^%^YELLOW%^...and it attacks you!");
            }
        }
        if (target == caster) {

            spell_kill(mon, caster);
            tell_object(caster, "%^BOLD%^%^YELLOW%^...and it attacks you!");
        }
    }
    num=0;
    if (target != caster) {
        call_out("check", 1, ({num, (2 + clevel + query_spell_level()) * ROUND_LENGTH,caster, foes}) );
    }
    addSpellToCaster();
}

int check(mixed *args) {
    int num, num2, timetowait, wherefound, num3, j;
    object caster, *foes, *newfoes;

    num = args[0];
    timetowait = args[1];
    caster = args[2];
    foes = args[3];
    num3 = 0;
    if (!caster || !objectp(caster)){
        dest_effect();
        return 1;
    }
    j = sizeof(newfoes=caster->query_attackers());
    for (num2=0;num2<j;num2++) {
        wherefound = member_array(newfoes[num2], foes, 0);
        if (wherefound == -1) {
            if (num3==0) {
                tell_object(caster,"%^BOLD%^%^YELLOW%^Your minions come to your aid and attack your enemies!");
                tell_room(place,"%^BOLD%^%^YELLOW%^"+caster->QCN+"'s minions come to "+
                          caster->QP+" aid and attacks "+caster->QP+" enemies!", caster);
                num3=1;
            }
        }
    }
    if (num3==1) {
        foes=newfoes;
        defend(caster, foes);
    }
    if (num++ < timetowait) {
        call_out("check", 1, ({num, timetowait, caster,foes}) );
    } else
        dest_effect();
}

void defend(object caster, object *foes) {
    int num, num2, randnum, numfoes, j;
    object mon, *tmp;

    tmp = ({});
    numfoes=sizeof(caster->query_attackers());
    j = sizeof(mons);
    for (num2=0;num2<j;num2++)
        if (!objectp(mons[num2]))
            tmp += ({mons[num2]});
    mons -= ({tmp});
    j = sizeof(mons);
    for (num2=1;num2<=sizeof(mons);num2++) {
        mon=mons[num2-1];
        if (mon && objectp(mon)) {
            if (foes != ({})) {
                for (num=1;num<=numfoes;num++)
                    spell_kill(mon, foes[num-1]);
            }
        }
    }
    return;
}

void dest_effect() {
    int num, firstflag, nummon;
    object * wheretold= ({ }) ;
     if (find_call_out("check") != -1) remove_call_out("check");
    firstflag=0;
    nummon=sizeof(mons);
    for (num=0;num<=(nummon-1);num++) {
        if (mons[num] && objectp(mons[num])) {
            if (caster && objectp(caster)) {
                if (member_array(environment(mons[num]),wheretold)==-1 ) {
                    tell_room(environment(mons[num]), "%^BOLD%^%^YELLOW%^The summoned monsters vanish!");
                    wheretold= distinct_array(wheretold + ({ environment(mons[num]) }));
                }
                caster->remove_follower(mons[num]);
            }
            mons[num]->move("/d/shadowgate/void.c");
            mons[num]->remove();
        }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}



