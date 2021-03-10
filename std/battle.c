//std/battle.c , 13078 bytes:
#include <std.h>
#include <daemons.h>
#include <dirs.h>
#define SPEED ( __COMBAT_SPEED__ - 1 )

// garrett - I made the next two variables static because we now have
// savable rooms. Maybe they should ALL be static, but I'm not willing
// to mess with code that deeply.

nosave object * combatants= ({});
nosave mixed * round= ({});
nosave mapping lookAhead = ([]);

// end of statication.

object * nextRound;
object * untouchable;

int roundCount = 0;
int stage= 0;
int debug = 0;
int stagedebug=0;
int onoff = 0;

void pause();
void reset_scrambles();

int toggle_debug()
{
    if(debug) { return debug = 0; }
    return debug = 1;
}


void round_check()
{
    int i;
    if(debug) tell_object(TO, "round = "+identify(round) + " at start of round_check()");
    if(!pointerp(round) || sizeof(round) != 20)
    {
        round = allocate(20);
    }
    if(!round[0] || !pointerp(round[0]))
    {
        for(i=0;i<20;i++)
        {
            round[i] = ({});
        }
    }
    //return;
    if(debug) tell_room(TO, "round now = "+identify(round) + " at end of round_check()");
    return;
}


void create()
{
    int i;
    round = allocate(20);

    for (i=0;i<20;i++)
    {
        round[i] = ({});
    }

    nextRound = ({});
    untouchable = ({});
    reset_scrambles();
    return;
}

void end_heart()
{
    set_heart_beat(0);
    if(debug) tell_room(TO,"DEBUG: Ending Heart: "+onoff);
    return;
}

void heart_beat()
{
    int i,j, x,roll, k,l,num_attacks,fighter_attacks,mod1,mod2,num, canfullattack;
    string file;
    object *weapons,*classes,ob,*tmp = ({}), *busy=({}),shape,ammo;
    //if(!objectp(TO)) { if(debug) { tell_object(find_player("saide"), "Room is invalid?");} return; }

    //  test = ({});

    if (debug) tell_room(TO,"DEBUG: Beat, Count: "+onoff);

    if (onoff)
    {
        onoff+=1;
        if (onoff >SPEED)
        {
            onoff = 0;
        }
        return;
    }

    j = sizeof(combatants);

    if(debug) tell_room(TO,"DEBUG: combatants "+identify(combatants));

    roundCount++;

    for (i=0;i<j;i++)
    {
        if(!objectp(combatants[i]))
        {
            if(debug) tell_room(TO, "BING REMOVED = "+identify(combatants[i]));
            tmp += ({combatants[i]});
        }
        else if((!present(combatants[i])) && living(combatants[i]))
        {
            if(debug) tell_room(TO, "BING REMOVED = "+identify(combatants[i]));
            tmp += ({combatants[i]});
        }
        else if(!sizeof(combatants[i]->query_attackers()) && living(combatants[i]))
        {
            if(debug) tell_room(TO, "BING REMOVED = "+identify(combatants[i]));
            tmp += ({combatants[i]});
        }
        else
        {
            if(debug) tell_room(TO, "NOT BING REMOVED = "+identify(combatants[i]));
            combatants[i]->setFuncing(0);
        }
    }

    if(combatants) { combatants -= tmp; }

    if((!combatants || !sizeof(combatants)) &&  (!lookAhead || !sizeof(lookAhead)))
    {
        if (debug)
        {
            if(debug) tell_room(TO,"DEBUG: stopping combat");
        }

        if(!TO->query_property("continue heartbeat"))
        {
            //set_heart_beat(0); //ultra slow heartbeat... instead of off until can fix the driver code for heart beats
            //remove_call_out("end_heart");
            remove_call_out("end_heart");
            call_out("end_heart",5);
        }
        onoff = 0;
        return;
    }

    j = sizeof(combatants);
    stage = 0;

    if (pointerp(nextRound))
    {
        round_check();
        round[0] = copy(nextRound);
        if(debug) tell_room(TO,"DEBUG: nextRound "+identify(nextRound));
    }
    else
    {
        round_check();
        round[0] = ({});
        if(debug) tell_room(TO,"DEBUG: no nextRound");
    }

    if (lookAhead[roundCount])
    {
        if(debug) tell_room(TO,"DEBUG: lookAhead "+identify(lookAhead));
        for (i=0;i<sizeof(lookAhead[roundCount]);i++)
        {
            round[lookAhead[roundCount][i][1]] += ({lookAhead[roundCount][i][0]});
        }
        map_delete(lookAhead,roundCount);
    }

    nextRound = ({});

    for (i=0;i<j;i++)
    {
        if (!objectp(combatants[i])) continue;
        if (!living(combatants[i])) continue;

        if(combatants[i]->query_hidden()) { combatants[i]->set_hidden(0); }
        // remove hidden from combatants...
        roll = random(10);

        if (!userp(combatants[i]))
        {
            roll -= ( random(14) - 7 ); // just giving them a random roll cause mobs default to high dex -Ares
        }
        else
        {
            roll -= combatants[i]->reactionAdj((int)combatants[i]->query_stats("dexterity"));
        }

        //----------------

        combatants[i]->resetCombat();

        combatants[i]->remove_property("bab_scale"); // resetting to default attack bonus at beginning of round -Ares

// process stomached kits here.
        if((combatants[i])->query_property("stomached_kits"))
           (combatants[i])->remove_property("stomached_kits");

        weapons = combatants[i]->query_wielded();
        weapons = distinct_array(weapons);

        if(sizeof(weapons)) {
            if (combatants[i]->validate_combat_stance("dual wield")) {//dual wield and double weapons
                num_attacks = 2;
            }else {
                num_attacks = sizeof(weapons);
            }
        }
        else { num_attacks = 2; }

        if (num_attacks < 1) { num_attacks = 1; }

        if(objectp(shape = combatants[i]->query_property("shapeshifted")))
        {
            num_attacks = shape->query_base_attack_num();
        }


        canfullattack = 0;
        if (combatants[i]->query_casting()) {
            if (combatants[i]->query_property("cast and attack")) {
                canfullattack = 1;
            }
            if (combatants[i]->query_property("magus cast") && combatants[i]->query_property("magus spell")) {
                canfullattack = 1;
            }
        }
        else {
            canfullattack = 1;
        }

        //if (combatants[i]->query_casting() && objectp(combatants[i]->query("spell_casting")) )
        if(!canfullattack)
        {
            busy+=({combatants[i]});
            if(debug) { tell_room(TO,"DEBUG: Busy: "+identify(combatants[i])); }
	    }
        else if((userp(combatants[i]) || combatants[i]->query_property("full attacks")))
        {
            if(userp(combatants[i]))
            {
                if(combatants[i]->validate_combat_stance("dual wield"))
                {
                    if(FEATS_D->usable_feat(combatants[i],"improved two weapon fighting"))
                        num_attacks += 2;
                    else
                        if(FEATS_D->usable_feat(combatants[i],"two weapon fighting"))
                            num_attacks += 1;
                }
                else // not that they can dualwield most ranged weps, but to avoid stacking anyway...
                {
                    if(sizeof(weapons) && weapons[0]->is_lrweapon())
                    {
                        ammo = present(weapons[0]->query_ammo(),combatants[i]);
                        if(FEATS_D->usable_feat(combatants[i],"rapid shot") && objectp(ammo) && ammo->query_shots())
                            num_attacks += 1;
                    }
                }
                if(!sizeof(weapons))
                {
                    if(FEATS_D->usable_feat(combatants[i], "improved rapid strikes")) num_attacks += 2;
                    else if(FEATS_D->usable_feat(combatants[i], "rapid strikes")) num_attacks += 1;
                }
            }

            classes = (string *)combatants[i]->query_classes();
            num = 0;

            if (combatants[i]->query_property("effect_staggered")) {
                num = 1;
            } else if (sizeof(classes)) {
                for (x = 0; x < sizeof(classes); x++) {
                    file = DIR_CLASSES + "/" + classes[x] + ".c";
                    if (!file_exists(file)) {
                        num = 0; continue;
                    }
                    if ((int)file->number_of_attacks(combatants[i]) > num) {
                        num = (int)file->number_of_attacks(combatants[i]);
                    }
                }
            }

            fighter_attacks = num;

            if(userp(combatants[i]))
            {
                if(FEATS_D->usable_feat(combatants[i],"shieldwall"))
                {
                    if(combatants[i]->query_property("shieldwall"))
                    {
                        if(!FEATS_D->usable_feat(combatants[i],"shield master"))
                        {
                            fighter_attacks -= (int)combatants[i]->query_property("shieldwall");
                        }
                    }

                    combatants[i]->remove_property("number_of_attacks");
                    combatants[i]->set_property("number_of_attacks",fighter_attacks);
                }
                else if(FEATS_D->has_feat(combatants[i],"shieldwall"))
                {
                    ob = new(DIR_FEATS+"/s/_shieldwall.c");
                    ob->end_feat(combatants[i]);
                    if(!FEATS_D->usable_feat(combatants[i],"shield master"))
                    {
                        fighter_attacks = num;
                    }
                }
            }

            if((int)combatants[i]->query_property("fighter_attacks_num") > 0)
            {
                fighter_attacks = (int)combatants[i]->query_property("fighter_attacks_num");
                if(combatants[i]->query_property("shieldwall"))
                {
                    if(!FEATS_D->usable_feat(combatants[i],"shield master"))
                    {
                        fighter_attacks -= (int)combatants[i]->query_property("shieldwall");
                    }
                }
            }

            if((int)combatants[i]->query_property("fighter_attacks_mod"))
            {
                fighter_attacks += (int)combatants[i]->query_property("fighter_attacks_mod");
            }

            if (fighter_attacks > 15) fighter_attacks = 15;
            num_attacks += fighter_attacks;
        }

        if (debug) { tell_room(TO,"DEBUG: num attacks = "+num_attacks); }

        if (combatants[i]->is_weaponless() && !userp(combatants[i]))
        {
            num_attacks = combatants[i]->query_attacks_num();
        }

        if (sizeof(weapons) >0)
        {
            if(objectp(weapons[0])) mod1 = weapons[0]->query_weapon_speed();
            if (sizeof(weapons) > 1)
            {
                if(objectp(weapons[1])) mod2 = weapons[1]->query_weapon_speed();
            }
        }

        //-------------------

        roll +=  mod1;

        if (roll > 19)
        {
            nextRound += ({combatants[i]});
            continue;
        }

        if (roll < 0) { roll = 0; }

        if (debug) { tell_room(TO,"DEBUG: "+file_name(combatants[i]) +" roll " + roll); }

        //    test = round[roll];

        if (combatants[i]->is_weaponless() && !userp(combatants[i]))
        {
            for (l=0;(l<combatants[i]->query_num_natural_attacks()) && num_attacks;l++)
            {
                round[roll] += ({combatants[i]});
                num_attacks--;
            }

        }
        else
        {
            round[roll] += ({combatants[i]});
            num_attacks--;
        }

        while(num_attacks > 0)
        {
            roll += 5;
            if (num_attacks%2)
            {
                roll += mod2;
            }
            else
            {
                roll += mod1;
            }
            if (roll > 19) roll = 19;
            round[roll] += ({combatants[i]});
            num_attacks--;
        }

        if (debug && stagedebug) { tell_room(TO,"DEBUG:"+identify(round)); }
    }

    if (debug) { tell_room(TO,"DEBUG: new round"); }
    if (debug) { tell_room(TO,"DEBUG:"); }

    for (i=0;i<20;i++)
    {
        for (k = 0;k<sizeof(round[i]);k++)
        {
            mod1 = 0;
            mod2 = 0;
            if(!objectp(round[i][k])) { continue; }
            if(round[i][k]->query_dead()) { continue; }

            if(round[i][k]->query_property("shotontherun")) //revoking shotontherun from previous round
            {
                round[i][k]->remove_property("shotontherun");
            }

            if(round[i][k]->query_blinking() && member_array(round[i][k],untouchable) == -1)
            {
                tell_room(TO,"%^YELLOW%^"+round[i][k]->QCN+" snaps "+round[i][k]->QP+" fingers and "
                    "blinks to the other side of the room.", round[i][k]);
                tell_object(round[i][k],"%^YELLOW%^With a snap of your fingers you appear 10 feet "
                    "from where you were before.");
                untouchable += ({round[i][k]});
            }

            for(l = 0;l<sizeof(untouchable);l++)
            {
                if(!objectp(untouchable[l])) { continue; }
                if(!pointerp(round[i][k]->query_attackers())) { continue; }
                if (member_array(untouchable[l],round[i][k]->query_attackers()) != -1)
                {
                    round[i][k]->remove_attacker(untouchable[l]);
                    round[i][k]->add_hunted(untouchable[l]);
                }
            }


            if(round[i][k]->check_death() || round[i][k]->query_ghost()) { continue; }
            if(round[i][k]->queryFuncing() && !round[i][k]->query_property("function and attack")) { continue; }

            if(round[i][k]->query_paralyzed() || round[i][k]->query_bound() || round[i][k]->query_tripped() || round[i][k]->query_unconscious())
            {
                round[i][k]->send_paralyzed_message("my_combat",round[i][k]);
                continue;
            }

            if(round[i][k]->query_property("memorizing"))
            {
                tell_object(round[i][k],"You are currently concentrating on a mental action and thus not swinging your weapon!");
                if (debug)
                if(debug) tell_room(TO,"DEBUG: Memorizing");
 		        continue;
	        }

	        if(member_array(round[i][k], busy) != -1)
            {
                // this message is a little bit too spamy
 		        //tell_object(round[i][k],"You are currently busy doing something other than focusing on swinging your weapon!");
                round[i][k]->set_casting(0); // hopefully this will fix the stuck casting bugs
                if (debug) tell_room(TO,"DEBUG: Casting");
		        continue;
            }

            if (debug && stagedebug)
            {
                tell_room(TO,"DEBUG: segment= "+i);
                tell_room(TO,"DEBUG: Who am i attacking "+file_name(round[i][k]));
            }

            if(!objectp(round[i][k])) continue;
            round[i][k]->prepare_attack(); // we want to set attacking to 0 in case a bug prevents it -Ares
            round[i][k]->execute_attack();

        }

        round[i] = ({});
    }

    untouchable = ({});
    busy = ({});
//    if (onoff<SPEED)
    onoff += 1;
//    else
//    onoff = 0;
    return;
}


void pause() { return; }


void add_combatant(object combatant)
{
    if (!objectp(combatant)) { return; }

    set_heart_beat(1);

    if(!combatants) { combatants = ({}); }
    if(member_array(combatant,combatants) == -1)
    {
        combatants += ({combatant});
    }
    return;
}


void remove_combatant(object combatant)
{
    if(!combatants) { combatants = ({}); }
    if(member_array(combatant,combatants) != -1)
    {
        combatants -= ({combatant});
    }
    return;
}

void set_round(object what, int which)
{
    if(!objectp(what)) { return; }
    if (!combatants) { combatants = ({}); }
    combatants += ({what});
    // onoff = 0;
    if(which < 0)  { which = 0; }
    if(which > 19) { which = 19; }
    if(stage > which)
    {
        if(stage == 19)
        {
            nextRound += ({what});
        }
        else
        {
            which = stage;
        }
    }
    remove_call_out("end_heart");
    set_heart_beat(1);
    if(!query_heart_beat(TO))
    {
        if(debug) tell_room(TO, "Heart beat was not set, resetting it.");
        remove_call_out("end_heart");
        set_heart_beat(1);
    }
    else
    {
        if(debug) tell_room(TO, "Heart beat was set.");
    }
    round_check();

    if(debug) tell_room(TO,"DEBUG: which: "+which);
    if(debug) tell_room(TO,"DEBUG: what" +identify(what));

    round[which] += ({what});
    if(debug) tell_room(TO,"DEBUG: round after which/what: "+identify(round));
    return;
}


object *query_combatants() { return combatants; }


mixed *query_round() { return round; }


int query_stage() { return stage; }


mapping queryLookAhead() { return lookAhead; }


mapping query_lookAhead() { return lookAhead;}


void addObjectToCombatCycle(object ob, int delay, int turn)
{
    if(!objectp(ob)) { return; }

    if(!lookAhead[roundCount+delay])
    {
        lookAhead[roundCount+delay] = ({});
    }
    lookAhead[roundCount+delay] += ({({ob,turn})});
    remove_call_out("end_heart");
    set_heart_beat(1);
}

int removeObjectFromCombatCycle(object ob)
{
    int *rounds,i,j;
    mixed *data=({}),*tmp=({});
    object tmp_obj;

    rounds = keys(lookAhead);

    if(!sizeof(rounds)) { return 0; }

    for(i=0;i<sizeof(rounds);i++)
    {
        data = lookAhead[rounds[i]];

        if(!sizeof(data)) { continue; }

        for(j=0;j<sizeof(data);j++)
        {
            if(!sizeof(data[j])) { continue; }
            if(!objectp(data[j][0])) { continue; }
            tmp_obj = data[j][0];

            if(tmp_obj == ob)
            {
                lookAhead[rounds[i]] -= ({ data[j] });
            }
        }
    }
    return 1;
}

int queryCurrentRound() { return roundCount; }

void reset_scrambles()
{
    int iteration;
    object ob;

    iteration == sizeof(combatants);

    while (iteration--)
    {
        if(!objectp(ob=combatants[iteration])) { continue; }
        if((int)ob->query_scrambling() > 1)    { ob->set_scrambling(1); }
    }
    return;
}
