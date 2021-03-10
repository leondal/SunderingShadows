// Monster Summoning 1 - Coded by Vashkar@shadowgate

#include <spell.h>
#include <magic.h>
#include <rooms.h>

inherit SPELL;
int check(mixed *arg);
void dest_effect();
void defend(object caster, object *foes);

object *mons;

create()
{
    ::create();
    set_spell_name("monster summoning i");
    set_spell_level(3);
    set_spell_type("wizard");
    set_spell_sphere("conjuration_summoning");
    set_components(([
        "tiny bag" : 1,
        "small candle" : 1
//        "small candle" : 1,
    ]));
    set_verbal_comp();
    set_somatic_comp();
    set_xp_bonus(5);
}

spell_effect()
{
    object
	mon,
	caster,
	oldenv,
	*foes,
	*oldattackers;
    int
	clevel,
	chooser,
	num,
	num2,
	numfoes,
	randnum,
	nummon,
	timestart;
    caster = CASTER;
    place = PLACE;
    clevel = CLEVEL;
    spell_successful();
    oldenv=environment(caster);
    nummon=(random(4)+random(4)+2);
    numfoes=(sizeof(caster->query_attackers()));
    mons=allocate(nummon);
    foes=caster->query_attackers();
    for(num=1;num<=nummon;num++)
    {
	chooser=random(10);
	switch(chooser)
        {
	    case(1):
		mon=new("/d/shadow/mon/kobold.c");
	    break;
	    case(2):
		mon=new("/d/shadow/mon/gnoll.c");
	    break;
	    case(3):
		mon=new("/d/shadow/mon/goblin.c");
	    break;
	    case(4):
		mon=new("/d/shadow/mon/orc.c");
	    break;
	    case(5):
		mon=new("/d/shadow/mon/hobgoblin.c");
	    break;
	    case(6):
		mon=new("/d/shadow/mon/giantrat.c");
	    break;
	    case(7):
		mon=new("/d/shadow/mon/giantbat.c");
	    break;
	    case(8):
		mon=new("/d/shadow/mon/rat.c");
	    break;
	    case(9):
		mon=new("/d/shadow/mon/bat.c");
	    break;
	    case(0):
		mon=new("/d/shadow/mon/bandits.c");
	    break;
	}
	mons[num-1] = mon;
	if(!objectp(mon)) continue;
	mon->set("aggressive", 1);
	mon->remove_property("swarm");
        mon->set_property("spell", TO );
        mon->move(place);
	caster->add_follower(mon);
        tell_room(place,
            mon->query_short()+" appears near "+
	    caster->query_cap_name()+".", caster);
        tell_object(caster, mon->query_short()+
	    " appears near you.");
	if(foes != ({ }))
        {
            for(num2=1;num2<=numfoes;num2++)
            {
				mon->kill_ob(foes[num2-1]);
	    	}
            if(present(foes[randnum], environment(caster)))
            {
		randnum=(random(numfoes));
		mon->kill_ob(foes[randnum]);
		tell_object(foes[randnum], "%^BOLD%^%^YELLOW%^"+
		    "...and it attacks you!");
	    }
	}
    }
    num=0;
    call_out("check", 1, ({num, (2 + clevel) * ROUND_LENGTH,
	      caster, foes}) );
}

int check(mixed *args)
{
    int num, num2, timetowait, wherefound, num3, j;
    object caster, *foes, *newfoes;
    num = args[0];
    timetowait = args[1];
    caster = args[2];
    foes = args[3];
    num3 = 0;
    if(!caster || !objectp(caster))
        dest_effect();
    j = sizeof(newfoes=caster->query_attackers());
    for(num2=0;num2<j;num2++){
		wherefound = member_array(newfoes[num2], foes, 0);
		if(wherefound == -1){
            if(num3==0) {
                tell_object(caster,"%^BOLD%^%^YELLOW%^Your minions "+
                    "come to your aid and attacks your enemies!");
                tell_room(place,"%^BOLD%^%^YELLOW%^"+
                    caster->query_cap_name()+"'s minions come to "+
                    caster->query_possessive()+" aid and attacks "+
                    caster->query_possessive()+" enemies!", caster);
            num3=1;
            }
		}
    }
    if(num3==1){
		foes=newfoes;
		defend(caster, foes);
    }
    if(num++ < timetowait) {
		call_out("check", 1, ({num, timetowait, caster,foes}) );
    }
    else
	dest_effect();
}

void defend(object caster, object *foes){
    int num, num2, randnum, numfoes, j;
    object mon, *tmp;
    
    tmp = ({});
    numfoes=sizeof(caster->query_attackers());
    j = sizeof(mons);
    for(num2=0;num2<j;num2++)
    	if(!objectp(mons[num2]))
    		tmp += ({mons[num2]});
    mons -= ({tmp});
    
    j = sizeof(mons);

    for(num2=1;num2<=sizeof(mons);num2++){
		mon=mons[num2-1];
		if(mon && objectp(mon))	{
	    	if(foes != ({ })){
				for(num=1;num<=numfoes;num++)
		    		mon->kill_ob(foes[num-1]);
				
				
	    	}
		}
    }
    return;
}

void dest_effect()
{
    int num, firstflag, nummon;
    ::dest_effect();
    if(find_call_out("check") != -1)
        remove_call_out("check");
    firstflag=0;
    nummon=sizeof(mons);
    for(num=0;num<=(nummon-1);num++)
    {
	if(mons[num] && objectp(mons[num]))
        {
            if(caster && objectp(caster))
            {
                if(firstflag==0)
                {
                    tell_object(CASTER, "%^BOLD%^%^YELLOW%^Your summoned "+
                        "monsters vanish!");
                    tell_room(place, "%^BOLD%^%^YELLOW%^"+
                        CASTER->query_cap_name()+"'s summoned monsters "+
                        "vanish!", CASTER);
                    firstflag=1;
                }
                caster->remove_follower(mons[num]);
            }
	    mons[num]->move("/d/shadowgate/void.c");
	    mons[num]->remove();
	}
    }
    destruct(TO);
}

string query_cast_string()
{
    return caster->query_cap_name()+" chants loudly towards the "+
        "sky as "+caster->query_subjective()+" pulls a small "+
        "candle out of a tiny bag and lights it.";
}

int help()
{
    write(
@HELP
      Syntax: cast monster summoning i

	This spell will summon 2d4 relatively weak monsters.  After
appearing, the monsters will immediately attack all of the spell
caster's foes, and then randomly choose a first target out of them.
They will fight till slain, and when the casting time is up, the
monsters will vanish.

Material components:

A tiny bag
A small candle

HELP
    );
    return 1;
}
