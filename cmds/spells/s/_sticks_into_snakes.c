//sticks to snakes ... Blatantly stolen from vashkar's monster summoning
// *Styx* 6/2002 - reduced numbers for lower levels and max # to cut spam
// and excesses due to ease of leveling here versus TT
// fixed the vape message to not put them back to sticks since it doesn't put sticks in the room to recast, also lowered the numbers a little more again *Styx*  11/14/04
// mon file moved to /d/magic/mon/ Ares/Styx 1/29/05
//changed so rangers cannot use it 3/16/05 -Tsera

#include <spell.h>
#include <magic.h>
#include <rooms.h>

#define MINE caster->QP

inherit SPELL;

int check(mixed* arg);
void defend(object caster, object* foes);

object* mons;

void create()
{
    ::create();
    set_spell_name("sticks into snakes"); // snakestaff
    set_spell_level(([ "cleric" : 5, "druid" : 5]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS sticks into snakes");
    set_description("This spell allows the caster to create snakes from sticks in the surrounding area. There must be sticks present for this spell to be successful.");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

int preSpell()
{
    if (place->query_property("no sticks")) {
        tell_object(caster, "There are no sticks in this area at all!");
        return 0;
    }

    if (present("snake 4", place)) {
        tell_object(caster, "There are no more sticks in this area, it's as if they have all been gathered away.");
        return 0;
    }
    return 1;
}

spell_effect(int prof)
{
    object mon, oldenv, * foes, * oldattackers, foe;
    int i, chooser, num, num2, numfoes, randnum, nummon, timestart;

    if (!objectp(caster)) {
        dest_effect();
        return;
    }

    oldenv = environment(caster);
    nummon = 8;
    numfoes = (sizeof(caster->query_attackers()));
    mons = allocate(nummon);

    for (num = 1; num <= nummon; num++) {
        chooser = random(100) + clevel;
        switch (chooser) {
        case 0..70:
            mon = new("/d/magic/mon/gen_snake");
            break;
        case 71..75:
            mon = new("/d/magic/mon/cottonmouth");
            break;
        case 76..82:
            mon = new("/d/magic/mon/copperhead");
            break;
        case 83..87:
            mon = new("/d/magic/mon/rattlesnake");
            break;
        case 88..91:
            mon = new("/d/magic/mon/boa");
            break;
        case 92..97:
            mon = new("/d/magic/mon/python");
            break;
        case 98..101:
            mon = new("/d/magic/mon/cobra");
            break;
        case 102..106:
            mon = new("/d/magic/mon/kcobra");
            break;
        case 107..110:
            mon = new("/d/magic/mon/grattlesnake");
            break;
        case 111..114:
            mon = new("/d/magic/mon/gboa");
            break;
        case 115..117:
            mon = new("/d/magic/mon/gpython");
            break;
        case 118:
            mon = new("/d/magic/mon/boalisk");
            break;
        default:
            mon = new("/d/magic/mon/amphisbaena");
            break;
        }
        mons[num - 1] = mon;
        if (!objectp(mon)) {
            continue;
        }
        mon->set("aggressive", 1);
        mon->remove_property("swarm");
        mon->set_max_hp(clevel * 6 + 30);
        mon->set_hp(clevel * 6 + 30);
        mon->set_property("spelled", ({ TO }));
        mon->set_property("spell_creature", TO);
        mon->set_property("spell", TO);
        mon->set_property("minion", caster);
        mon->add_id("summoned monster");
        mon->move(place);
        if (!objectp(mon)) {
            continue;
        }
        caster->add_follower(mon);
        caster->add_protector(mon);
        tell_room(place, "%^BOLD%^%^YELLOW%^A stick near " + caster->QCN +
                  " transforms into a " + mon->QCN + "!", caster);
        tell_object(caster, "%^BOLD%^A stick becomes a " + mon->QCN + ".");


        foes = caster->query_attackers();

        if (sizeof(foes)) {
            for (i = 0; i < sizeof(foes); i++) {
                if (!objectp(foes[i])) {
                    continue;
                }
                mon->kill_ob(foes[i], 1);
            }
        }
    }
    environment(caster)->set_property("used sticks", 1);
    addSpellToCaster();
    spell_successful();
    num = 0;
    call_out("check", 1, ({ num, (2 + clevel) * ROUND_LENGTH, caster, foes }));
}

int check(mixed* args)
{
    int num, num2, timetowait, wherefound;
    object* foes, * newfoes;
    num = args[0];
    timetowait = args[1];
    caster = args[2];
    foes = args[3];

    if (!sizeof(foes)) {
        foes = ({});
    }

    if (!caster || !objectp(caster)) {
        dest_effect();
        return 1;
    }
    newfoes = caster->query_attackers();
    //lets get rid of foes that were attacking
    //the caster already (foes variable)
    //tell_object(caster, "Newfoes = "+identify(newfoes));
    //tell_object(caster, "Foes = "+identify(foes));
    newfoes -= foes;
    newfoes = distinct_array(newfoes);
    //tell_object(caster, "Newfoes Now = "+identify(newfoes));


    if (sizeof(newfoes)) {
        // these messages are way too spammy in combat
        //tell_object(caster,"%^BOLD%^%^YELLOW%^Your minions "+
        //"come to your aid and attacks your enemies!");

        //tell_room(environment(caster),"%^BOLD%^%^YELLOW%^"+
        //caster->QCN+"'s minions come to "+
        //caster->QP+" aid and attacks "+
        //caster->QP+" enemies!", caster);

        foes = newfoes;
        defend(caster, foes);
    }


    /*for (num2=0;num2<=sizeof(newfoes)-1;num2++)
      {
      wherefound = member_array(newfoes[num2], foes, 0);
      if (wherefound == -1)
      {
      tell_object(caster,"%^BOLD%^%^YELLOW%^Your minions "+
      "come to your aid and attacks your enemies!");

      tell_room(environment(caster),"%^BOLD%^%^YELLOW%^"+
      caster->QCN+"'s minions come to "+
      caster->QP+" aid and attacks "+
      caster->QP+" enemies!", caster);

      foes=newfoes;
      defend(caster, foes);
      break;
      }
      }*/

    if (num++ < timetowait) {
        call_out("check", 1, ({ num, timetowait, caster, foes }));
    }else  {
        dest_effect();
    }
}
void defend(object caster, object* foes)
{
    int num, num2, randnum, numfoes;
    object mon;

    if (!objectp(caster)) {
        return;
    }

    if (!sizeof(foes)) {
        return;
    }

    //numfoes=sizeof(caster->query_attackers());
    numfoes = sizeof(foes);
    for (num2 = 1; num2 <= sizeof(mons); num2++) {
        mon = mons[num2 - 1];

        if (!objectp(mon)) {
            continue;
        }

        for (num = 1; num <= numfoes; num++) {
            if (!objectp(foes[num - 1])) {
                continue;
            }
            mon->kill_ob(foes[num - 1]);
        }
    }
    return;
}
void dest_effect()
{
    int num, nummon;
    object* wheretold = ({ });
    if (find_call_out("check") != -1) {
        remove_call_out("check");
    }

    nummon = sizeof(mons);
    for (num = 0; num <= (nummon - 1); num++) {
        if (mons[num] && objectp(mons[num])) {
            if (caster) {
                if (member_array(environment(mons[num]), wheretold) == -1) {
                    tell_room(environment(mons[num]), "The summoned snakes turn back into sticks and %^ORANGE%^crumble to dust%^RESET%^!");
                    wheretold = distinct_array(wheretold + ({ environment(mons[num]) }));
                }
                caster->remove_follower(mons[num]);
            }
            mons[num]->move("/d/shadowgate/void.c");
            if (objectp(mons[num])) {
                mons[num]->remove();
            }
        }
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}

string query_cast_string()
{
    return caster->QCN + " caresses " + caster->QP + " holy symbol gently as " + caster->QS + " mutters a small prayer to " + MINE + " god.\nSlowly " + caster->QS + " glances around and concentrates on the sticks that clutter the ground.";
}
