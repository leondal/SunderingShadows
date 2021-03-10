//      /std/living/combat.c
//      from the Nightmare mudlib
//      code for combat
//      based upon the LOS combat by Buddha@TMI
//      created by Descartes of Borg september 1992
//      changed killers log entries to use query_name so invis. won't be "Someone" now that only immortals see the killers list  *Styx*  4/3/03
//      added set_pk_death_flag in check_death check for pkill *Styx* 9/24/06

#include <std.h>
#include <party.h>
#include <daemons.h>
#include <council.h>
#include <balance.h>
#include <security.h>

#define TEMP_HIT_BONUS "/realms/ares/temporary_hit.c"  // remove this when done

                    // this is the amount, per swing, that attack bonus is penalized with each subsequent attack of the main hand weapon in a round
#define BAB_SCALE 0 // I tried 5 to begin with, but it seemed like a bit too much.  We will have to play with this number until it seems right -Ares
                    // removing this for the moment, as it makes pkill a bit skewed at the moment.  We've got the ability to plug it back in whenever
                    // we figure out how we want to do it for sure.

#define MAX_MELEE_WC        20
#define MAX_ATTACK_BONUS    5
#define DEATH_EXP_MOD 1
#define KILL_RANGE 5
#define DEFAULT_PARALYZE_MESSAGE "You are stiff as stone."
#define DEFAULT_GAGGED_MESSAGE "You are gagged and can not speak."
#define DEFAULT_BOUND_MESSAGE "You are bound and can not move."
#define DEFAULT_TRIPPED_MESSAGE "You have fallen and are trying to get up."
#define DEFAULT_UNCONSCIOUS_MESSAGE "You are unconscious."
#define DEATHS_DOOR_MESSAGE "You are at %^BOLD%^Death's door%^RESET%^. Your body is slipping from you."
#define DEFAULT_ASLEEP_MESSAGE "You are fast asleep."
#define NEWBIE 6
#define BAD_LIMBS ({"torso","neck","waist","lower torso","tail"})
#define ADJUST (["thief":10,"fighter":0,"cleric":6,"assassin":10,"ranger":4,"paladin":2,"antipaladin":2,"cavalier":2,"mage":10,"bard":5,"psion":10])
inherit "/adm/failsafe/skills_failsafe.c";

static int paralyzed, lastHand;
static object current_weapon;
int toAttack;
static int hunting, attack, toattack, tripped_counter, attacking, attack_count,attack_loop;
private string *atnames;
int wimpy, wimped;
private string wimpydir;
private object *attackers;
int any_attack, casting, react, funcCast, castFunc;
private object *hunters;
private static string paralyze_message;
int swarm;
static int dead;
static int funcing;
mapping combat_vars, combat_messages, combat_counters;
static mapping combat_static_vars;

private static int critical_hit,critical_message;

void send_dodge(object att);
void add_attacker(object ob);
int ok_to_kill(object targ);
int do_i_win();
int query_initiative();
void miss(int magic, object target, string type, string target_thing);
void set_casting(int x);
void set_paralyzed(int x, string drow);
void remove_paralyzed();
int ok_to_attack();  // initiative, etc determines this
int query_paralyzed();
int query_casting();
int clean_up_attackers();
void run_away();
void send_messages(int magic, object current, string what, int x, object attacker, int fired, string ammo);
void set_wimpydir(string str);
void set_wimpy(int x);
string query_wimpydir();
int query_wimpy();
int kill_ob(object victim, int which);
int sight_adjustment();
void continue_attack();
void update_current_skill();
void cease_all_attacks();private string check_up(string limb);
void execute_attack();
void set_magic_protection(string limb, int x);
void add_magic_protection(mixed *info);
int query_magic_protection(string limb);
string query_paralyze_message();
void ok_to_wield();
int reaction_adj(); //just a big switch//
void thaco_messages(int thaco);
void remove_attacker(object attack);
void add_hunted(object hunt);
int reset_hunted();
int remove_hunted(object hunt);
int is_ok_armour(string str);
int damage_done(object weap, int damage, int isranged);
object doProtection(object player);
void setFuncing(int i);
int queryFuncing();
void setFuncCast(int i);
void setCastFunc(int i);
int isPkill();
int doPkill();
int query_unconscious();
int query_asleep();
int query_gagged();
int query_bound();
int query_tripped();
int query_deaths_door();
string query_gagged_message();
string query_bound_message();
string query_tripped_message();
string query_unconscious_message();
string query_asleep_message();
object set_current_weapon(object ob);
object query_current_weapon();
int get_block_chance(object obj);
static void internal_execute_attack();  // this is the renamed execute_attack, putting in recursion testing to prevent errors -Ares
mixed return_player_target(int flag); //should return a player target if flag is > roll_dice(1,100) - Saide


object *query_active_protectors(object obj); // different way to do protection

//  This function is used to initialize various variables
void init_attack() 
{
    init_complex_body();
    hunters = ({});
    attackers = ({});
    atnames = ({});
    wimpydir = "out";
    toattack = 4;
    attack = 0;
    toAttack = -1;
}

// Remove dead or non-existing objects out of the list of attackers
// Return true if there are still attackers around
int clean_up_attackers() 
{
    object *hunters_tmp=({}), *attackers_tmp=({}), *full_tmp, ob, *uncon_att=({});
    int i, tmp;
    string *pkillsatt, *pkillsvic;

    if (!objectp(TO)) return 0;
    if (!objectp(ETO)) return 0;

    full_tmp = attackers + hunters;

    if (interactive(TO)) 
    {
        pkillsatt = TO->query_pkilled();
        if (!pointerp(pkillsatt)) pkillsatt = ({});
    }

    for (i=0, tmp = sizeof(full_tmp); i<tmp; i++) 
    {
        if (full_tmp[i] == TO || !objectp(full_tmp[i])) continue;
        if (member_array(full_tmp[i], (attackers_tmp+hunters_tmp)) != -1) continue;
        if (!objectp(environment(full_tmp[i]))) continue;
        if (environment(full_tmp[i]) != environment(TO)) 
        {
            if (interactive(TO) && interactive(full_tmp[i])) continue;
            hunters_tmp += ({ full_tmp[i]});
            continue;
        }
        if (full_tmp[i]->query_ghost()) 
        {
            atnames-=({full_tmp[i]->query_name()});
            continue;
        }
        if (interactive(full_tmp[i]) && interactive(TO)) 
        {
            pkillsvic = full_tmp[i]->query_pkilled();
            if (!pointerp(pkillsvic)) pkillsvic = ({});
            if (member_array(full_tmp[i]->query_name(),pkillsatt) != -1)
                pkillsatt = pkillsatt + ({full_tmp[i]->query_name()});
            if (member_array(TO->query_name(),pkillsvic) != -1)
                pkillsvic = pkillsvic + ({TO->query_name()});
        }
        if (!full_tmp[i]->query_bound() && !full_tmp[i]->query_unconscious()) 
        {
            attackers_tmp += doProtection(full_tmp[i]);
        } 
        else 
        {
            uncon_att += ({full_tmp[i]});
        }
    }

    if (!userp(TO) && !ETO->query_property("arena"))
    {
        for (i=0, tmp = sizeof(atnames); i<tmp; i++) 
        {
            if (ob=present(atnames[i],ETO))
                attackers_tmp += ({ob});
        }
    }

    if (sizeof(attackers_tmp) == 0) 
    {
        for (i=0, tmp = sizeof(uncon_att); i<tmp; i++) 
        {
            attackers_tmp += doProtection(uncon_att[i]);
        }
    }

    attackers_tmp = distinct_array(attackers_tmp);
    attackers = attackers_tmp;
    hunters = hunters_tmp;
    any_attack = sizeof(attackers);
    hunting = sizeof(hunters);
    return any_attack;
}

string *query_atnames() 
{
    return atnames;
}

//  This is the kill command.  If the victim is not yet attacked
//  then it is entered first into the list of victims.  If it
//  is already in the list, then it becomes the first entry
int kill_ob(object victim, int which) 
{
    object *borg_people, *inven;
    int i, initiative, k, myinit;
    string *pkill;

    if(!objectp(TO)) { return 0; }
    if(!objectp(ETO)) { return 0; }
    if(!objectp(victim)) { return 0; }
    if (!objectp(environment(victim))) { return 0; }
    if ((base_name(ETO)=="/d/shadowgate/void") || (base_name(environment(victim)) =="/d/shadowgate/void")) { return 0; }
    if (victim == TO) return 0;
    if (!ok_to_kill(victim)) { return 0; }

    if (!pointerp(attackers)) { init_attack(); }
    pkill = ({});

    borg_people = (object *)victim->query_attackers();
    if (!borg_people) borg_people = ({});

    if(!(environment(victim)->query_property("arena")) && (!TO->query_property("safe arena") || !victim->query_property("safe arena"))) 
    {
        if(member_array(TO, borg_people) == -1) 
        {
            if (interactive(TO) && interactive(victim) || (victim->is_townsman()) || TO->is_townsman()) 
            {
	            if (!wizardp(TO) && !wizardp(victim)) 
                {
	                if(objectp(TP)) 
                    { 
	                    if(TO == TP) 
                        {
	                        log_file("killers","       ##"+capitalize(TPQN)+" attacked "
                                ""+capitalize(victim->query_name())+" at "+ctime(time())+".\n");
	                        if (!avatarp(TP))
		                        KILLING_D->check_actions(TP,victim);
	                    } 
                        else 
                        {
	                        if (PO->is_spell()) 
                            {
                                if(objectp(PO->query_caster()))
                                {
                                    if(member_array(PO->query_caster(), borg_people) == -1)
                                    {
		                                log_file("killers","       ##"+capitalize((PO->query_caster())->query_name())+" "
                                            "attacked "+capitalize(TO->query_name())+" at "+ctime(time())+".\n");
		                                if (!avatarp(PO->query_caster()))
		                                    KILLING_D->check_actions(PO->query_caster(),TO);
                                    }
                                }
	                        } 
                            else 
                            {
		                        log_file("killers","       ##"+capitalize(TPQN)+" attacked "
                                    ""+capitalize(TO->query_name())+" at "+ctime(time())+".\n");
		                        if (!avatarp(TP))
		                            KILLING_D->check_actions(TP,TO);
	                        }
	                    }
                    } 
                    else 
                    {
	                    log_file("killers","       ##"+capitalize(TO->query_name())+" attacked "
                            ""+capitalize(victim->query_name())+" at "+ctime(time())+".\n");
                        if (!avatarp(TO))
                            KILLING_D->check_actions(TO,victim);
	                }
                }
            }
        }
        //if ((victim->is_townsman() || interactive(victim)) && !interactive(TO)) KILLING_D->check_actions(TP,TO);
        //if ((TO->is_townsman() || interactive(TO)) && !interactive(victim)) KILLING_D->check_actions(TP,victim);
    }

    if(objectp(victim)) { victim->check_death(); }
  
    if(!swarm) 
    {
        if(TO == TP && interactive(TP)) 
        {
            swarm = 1;
            inven = all_inventory(ETO);
            inven = filter_array(inven,"classic_swarm",FILTERS_D);
            //inven->kill_ob(TP,0);
            for(i=0;i<sizeof(inven);i++)
            {
                if(!objectp(inven[i])) { continue; }
                inven[i]->add_attacker(TO);
                ETO->add_combatant(inven[i]);
            }
        }
    }

    /* changed from 0 to 1 to faciliate PK patch */
    if(TO->query_attacked()) { return 1; }

    i = member_array(victim, attackers);
    if ((i == -1) && (!which)) 
    {
        // roll surprise and stuff
        // assume we won
        myinit = query_initiative();
        if((string)TO->query_race() == "human" && (string)TO->query("subrace") == "tsarven") myinit -= 1;

        if (myinit < (int)victim->query_initiative()) 
        {
            toattack = 2;
            victim->set_toattack(4);
        }
        else 
        {
            toattack = 4;
            victim->set_toattack(2);
        }
        victim->add_attacker(TO);
        ETO->add_combatant(victim);
        //victim->kill_ob(TO, 1);
    }

    if (i > -1) 
    {
        notify_fail("You are already attacking "+capitalize(victim->query_name())+"!\n");
        return 1;
    }

    attackers += ({victim});
    ETO->add_combatant(TO);
    any_attack = 1;
    swarm = 0;
    return 1;
}

void resetCombat() 
{
    setFuncCast(0);
    setCastFunc(0);
}

void set_attackers(object *what) 
{
    int i, j;

    j = sizeof(what);
    for (i=0;i<j;i++)
    {
        add_attacker(what[i]);
    }
    any_attack = 1;
}

void set_toattack(int x) { toattack = x; }

int ok_to_attack() { return 1; }

int query_initiative() { return random(10); }

void doExp(object who,int how, int split) 
{
    int max,per;

    if(!objectp(who)) { return; }

    how = how/split;

    if (TO->query_max_level()) 
    {
        if(max = (int)TO->query_max_level()) 
        {
            if(max < (int)who->query_lowest_level()) 
            {
                // 5% if they are 5 levels higher than the max level
                if((int)who->query_lowest_level() - max > 4)
                {
                    per = 5;
                }
                else
                {
                    per = (int)who->query_lowest_level() - max;
                    switch(per)
                    {
                    case 4:  per = 20; break;
                    case 3:  per = 40; break;
                    case 2:  per = 60; break;
                    case 1:  per = 80; break;
                    default: per = 5;  break;
                    }
                }
                if(per == 0) { how = 0; }
                else { how = to_int(how * (per * 0.01)); }
            }
        }
    }
    who->add_exp(how);
}

varargs int check_death(object pot)
{
    string attack_limb, lost_limb;
    string *nin;
    object *death, magi, *newattackers, *tempspell, killedBy;
    int n, xxx, fighter_attacks,exp;
    int i;
    object spellthing;

    if(dead) return 1;
    if(!objectp(TO)) { return 1; }

    if (query_hp() < 1 && !TO->query_ghost()) 
    {
        if(wizardp(TO) && !TO->query_killable()) 
        {
            TO->set_hp((int)TO->query_max_hp());
            tell_object(TO,"You are immortal and cannot die.");
        } 
        else 
        {
            if(objectp(pot)) { attackers += ({pot}); }
            if (attackers) 
            {
                if (sizeof(attackers) && objectp(attackers[0])) 
                {
                    if (!TO->is_player() && !TO->is_townsman()) 
                    {
                        newattackers = attackers;
                        for (i = 0;i < sizeof(attackers);i++) 
                        {
                            if(objectp(attackers[i]) && attackers[i]->query_property("spell") && !attackers[i]->query_property("keep exp")) 
                            {
                                newattackers -= ({ attackers[i]});
                                spellthing = attackers[i]->query_property("spell");
                                magi = spellthing->query_caster();
                                if (member_array(magi, newattackers) == -1)
                                {
                                    newattackers += ({magi});
                                }
                            } 
                            else if(objectp(attackers[i]) && attackers[i]->is_spell())
                            {
                                newattackers -= ({ attackers[i]});
                                spellthing = attackers[i];
                                magi = spellthing->query_caster();
                                if (member_array(magi, newattackers) == -1)
                                {
                                    newattackers += ({magi});
                                }
                            }
                        }

                        attackers = newattackers;

                        if(objectp(attackers[0])) 
                        {
                            attackers[0]->add_kill((string)TO->query_name());
                            if(avatarp(attackers[0]) && attackers[0]->query_disguised()) 
                            {
                                if(userp(attackers[0])) add_death((string)attackers[0]->getParsableName());
                                else add_death((string)attackers[0]->query_vis_name());
                            } 
			                else 
                            {  
                                if(userp(attackers[0])) add_death((string)attackers[0]->getParsableName());
                                else add_death((string)attackers[0]->query_name());
                            }
                        }

                        for(i = 0;i < sizeof(attackers);i++) 
                        {
                            if(!objectp(attackers[i])) { continue; }
                            if (!(ETO->query_property("arena"))) 
                            {
                                exp = TO->query_exp();
                                doExp(attackers[i],exp,sizeof(attackers));
                            }
                        }
                        killedBy = attackers[0];
				        TO->set("killedBy", killedBy);
                    }
                    else 
                    {
                        if (killedBy = isPkill()) 
                        {
				    TO->set("killedBy", killedBy);
                            if(doPkill()) { return 1; }
                        }
                    
                        newattackers = attackers;
                    
                        for (i = 0;i < sizeof(attackers);i++) 
                        {
                            if (objectp(attackers[i]) && attackers[i]->query_property("spell") && !attackers[i]->query_property("keep exp")) 
                            {
                                newattackers -= ({ attackers[i]});
                                spellthing = attackers[i]->query_property("spell");
                                magi= spellthing->query_caster();
                                if(member_array(magi, newattackers) == -1) { newattackers += ({magi}); }
                            }
                        }

                        attackers = newattackers;
                        attackers[0]->add_kill((string)TO->query_name());
                        
                        if (avatarp(attackers[0]) && attackers[0]->query_disguised()) 
                        {
                            if(userp(attackers[0])) add_death((string)attackers[0]->getParsableName());
                            else add_death((string)attackers[0]->query_vis_name());
                        }
                        else 
                        {
                            if(attackers[0]->is_spell()) 
                            { 
                                if(userp(attackers[0]->query_caster())) add_death((string)attackers[0]->query_caster()->getParsableName());
                                else add_death( (attackers[0]->query_caster())->QCN ); 
                            }
                            if(userp(attackers[0])) add_death((string)attackers[0]->getParsableName());
                            else add_death((string)attackers[0]->query_name());
                        }
                        
                        xxx = sizeof(death = all_inventory(attackers[0]));
                        while (xxx--)
                        {
                            death[xxx]->notify_kill(TO);
                        }

                        if(!objectp(killedBy) && attackers[0]->query_property("spell") && objectp(attackers[0]->query_property("spell"))) 
                        {
                            killedBy = attackers[0]->query_property("spell")->query_caster();
                        }
                        if(!objectp(killedBy)) 
                        {
                            killedBy = attackers[0];
				            TO->set("killedBy", killedBy);
                        }

                        if (TO->is_townsman()) 
                        {
                            for (i = 0;i < sizeof(attackers);i++) 
                            {
                                if (!objectp(attackers[i])) continue;
                                if (!(ETO->query_property("arena"))) 
                                {
                                    exp = TO->query_exp();
                                    doExp(attackers[i],exp,sizeof(attackers));
                                }
                            }
                        }

                        if (!ETO->query_property("arena") || (!TO->query_property("safe arena") || !killedBy->query_property("safe arena"))) 
                        {
                            log_file("kills",TO->query_name()+" ("+(int)TO->query_level()+") was killed by "+killedBy->query_name()+" ("+(int)killedBy->query_level()+"): "+ctime(time())+"\n");
                            log_file("kills","  "+file_name(killedBy)+"  (uid:"+getuid(killedBy)+") \n  (creator = "+killedBy->query_creator()+") ["+file_name(ETO)+"]\n");
                        }

                        if(isPkill() || killedBy->query_property("bounty hunter")) 
                        {
                            if (!(ETO->query_property("arena")) || (!TO->query_property("safe arena") || !killedBy->query_property("safe arena"))) 
                            {
                                if (!wizardp(TO) && !wizardp(killedBy)) 
                                {
                                    log_file("pkills",TO->query_name()+" ("+(int)TO->query_alignment()+") was killed by "+killedBy->query_name()+" ("+(int)killedBy->query_alignment()+"): "+ctime(time())+"\n");
                                    KILLING_D->do_bad_pkill(killedBy,TO);
                                }
                            }
                        }

                        if (isPkill()) 
                        {
                            log_file("killers","       "+capitalize(TO->query_name())+" was killed by "+capitalize(killedBy->query_name())+" at "+ctime(time())+"\n");
//                            tell_object(TO,"%^BOLD%^%^FLASH%^This would potentially be a permadeath");
                            TO->perma_death();
		                    TO->set_pk_death_flag();
                            TO->set("just_been_pkilled",1);
                            if (!random(100)) 
                            {
                                log_file("permaDeaths","     "+capitalize(TO->query_name())+" was perma killed by "+capitalize(killedBy->query_name())+" at "+ctime(time())+"\n");
                                tell_object(TO,"%^BOLD%^%^FLASH%^This really would have been be a permadeath had the code been in.");
                            }
                        }
                    }
                    dead = 1;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int doPkill() 
{
    int i,j;
    if(!objectp(TO)) { return 0; }
    if (query_property("to die")) { return 0; }
    if (query_hp() < (-2* query_max_hp())) { return 0; }
    j = sizeof(attackers);
    for (i=0;i<j;i++) 
    {
        if(!objectp(attackers[i])) { continue; }
        attackers[i]->remove_attacker(TO);
    }
    cease_all_attacks();
    set_hidden(0);
    set_magic_hidden(0);
    tell_object(TO,"%^BOLD%^%^RED%^You have fallen unconscious due to egregious wounds.");
    tell_room(ETO,"%^BOLD%^%^RED%^"+TO->QCN+" falls unconscious due to horrible wounds.",TO);
    return 1;
}

void continue_attack() 
{
    string attack_limb, lost_limb;
    string *nin;
    object *death, magi, *newattackers, *tempspell, killedBy;
    int n, xxx, fighter_attacks,exp;
    int i;
    object spellthing;

    if(!objectp(TO)) return;
    if(!objectp(ETO) || TO->query_ghost()) return;
    if(TO->is_player() && !interactive(TO) && !TO->query_property("bounty hunter")) { return; }

    check_death();
    if(dead) 
    {
        dead = 0;
        TO->die((attackers && killedBy ? killedBy : 0));
        attackers = ({});
        return;
    }

    if((0) && !any_attack) casting = 0; // ???

    if(!any_attack && !hunting && !sizeof(attackers) && (userp(TO) || !sizeof(atnames))) return; 

    if(!wimped || userp(TO))
    {
        if(!clean_up_attackers()) return;
    }

    if(((int)TO->query_hp()*100)/(int)TO->query_max_hp() < wimpy)
    {
        if(time() > (int)query_property("running_away_time"))
        {
            remove_property("running_away_time");
            set_property("running_away_time",time()+2);
            run_away();
            return;
        }
    }

    wimped = 0;
    attack++;

    if (attack > toattack-1) 
    {
        attack = 0;
        if (!query_paralyzed()) 
        {
            if (do_i_win()) 
            {
                ETO->add_combatant(TO);
            }
        }
        else 
        {
            if(objectp(TO)) { message("my_combat", query_paralyze_message(),TO); }
        }
    }
}

int isPlayerMonster(object ob) 
{
    object spell;
    if(!objectp(ob)) 
    {
        return 0;
    }
    if(spell = ob->query_property("spell")) 
    {
        if (!objectp(spell)) { return 0; }
        if (objectp(spell->query_caster())) 
        {
            return userp(spell->query_caster());
        }
    }
    return 0;
}

int isPkill() 
{
    int i,j;
    object killedBy;
       
    if(!userp(TO) && !TO->is_townsman()) { return 0; }
    if (!sizeof(attackers)) { return 0; }

    if(objectp(attackers[0])) 
    {
       if (attackers[0]->query_property("spell") && objectp(attackers[0]->query_property("spell")))
       {
          killedBy = (attackers[0]->query_property("spell"))->query_caster();
       }
       if(!objectp(killedBy)) { killedBy = attackers[0]; }
    }

    if(ETO->query_property("arena") && (TO->query_property("safe arena") && killedBy->query_property("safe arena"))) { return 0; }

    j = sizeof(attackers);
    for (i=0;i<j;i++) 
    {
        if(objectp(attackers[i])) 
        {
            if (userp(attackers[i]) || isPlayerMonster(attackers[i])) 
            {
                return attackers[i];
            }
            if (attackers[i]->is_townsman()) 
            {
                return attackers[i];
            }
            if (attackers[i]->query_property("knock unconscious")) 
            {
                return attackers[i];
            }
            if (attackers[i]->is_spell() && objectp(attackers[i]->query_caster()) && interactive(attackers[i]->query_caster())) 
            {
                return attackers[i]->query_caster();
            }
        }
    }
    return 0;
}

void setFuncCast(int i) {
    funcCast = i;
}

void setCastFunc(int i) {
    castFunc = i;
}

int queryfuncCast() {
    return funcCast;
}

int do_i_win() {
    return 1;
}

void counter_attack(object ob)
{
    object *attackers;
    if(!objectp(ob)) { return; }
    attackers = ob->query_attackers();
    attackers -= ({ 0 });
    if(!sizeof(attackers)) { return; }
    tell_object(ob,"%^RESET%^%^BOLD%^%^GREEN%^You take advantage of the opening and "
        "counter attack!%^RESET%^");
    tell_room(environment(ob),"%^RESET%^%^BOLD%^%^GREEN%^"+ob->QCN+" takes advantage "
        "of the opening and counter attacks!%^RESET%^",ob);
    ob->execute_attack();
    return;
}

void spring_attack(object ob){
    object *attackers;
    if(!objectp(ob)) { return; }
    attackers = ob->query_attackers();
    attackers -= ({ 0 });
    if(!sizeof(attackers)) { return; }
    tell_object(ob,"%^BOLD%^%^CYAN%^You use the momentum of your dodge to "
        "try and land another attack!");
    tell_room(environment(ob),"%^BOLD%^%^CYAN%^"+ob->QCN+" uses the momentum "
        "of "+ob->QP+" dodge to try and land another attack!",ob);
    ob->execute_attack();
    return;
}

//Does casting work then returns true if casting is being used
int do_casting(object targ) 
{
    string this_spell, spell_type, spell_file;
    object tempspell;
    targ = return_player_target(50);
    if (castFunc) return 0;
    if ((!objectp(TO)) || (!objectp(targ)) || (!present(targ)) ) return 0;
// Attempted fix of spellcasting monster problems. - Garrett.
    setCastFunc(1);
    if ((int)TO->query_spell_chance() > (random(100)+1)) {
        this_spell = (string)TO->get_random_spell();
        if (this_spell) {
            spell_file="/cmds/spells/"+this_spell[0..0]+"/_"+replace_string(this_spell," ","_")+".c";
            if (file_exists(spell_file)) {
                tempspell=new(spell_file);
                if ((int)tempspell->query_target_required() == 1) 
                {
                    tempspell->use_spell(TO,targ,TO->query_level());
                }
                else 
                {
                    tempspell->use_spell(TO,0,TO->query_level());
                }
            }
        }
        return 1;
    }
    return 0;
}

//Get a random player/interactive attacker from the list of attackers - Saide

mixed return_player_target(int flag)
{
    int x;
    object myTarg, *myTargets = ({});
    if(!clean_up_attackers()) { return 0; }
    if(!sizeof(attackers)) { return 0; }
    if(!intp(flag)) flag = 50;
    if(roll_dice(1,100) > flag) return attackers[random(sizeof(attackers))];
    for(x = 0;x < sizeof(attackers);x++)
    {
        if(!interactive(attackers[x])) continue;
        myTargets += ({attackers[x]});
        continue;
    }
    //if there are no interactive targets, get a random target - Saide
    if(sizeof(myTargets)) myTarg = myTargets[random(sizeof(myTargets))];
    else myTarg = attackers[random(sizeof(attackers))];
    return myTarg;
}

// Does the functions returns 1 if func is executed and 0 if not
int do_functions() 
{
    object random_targ;

    if(funcCast) return 0;
    if(!clean_up_attackers()) return 0; // Clean the attacker list off..
    if(!sizeof(attackers)) { return 0; }
    setFuncCast(1);
    if (TO->query_func_chance() > (random(100)+1)) 
    {
        random_targ = return_player_target(50);
        //random_targ = attackers[random(sizeof(attackers))];
        if ((!objectp(random_targ))) return 0;
        funcing = 1;
        call_other(TO, TO->get_random_func(), random_targ);
        return 1;
    }
    return 0;
}



void send_debug_crap(object ob,string str)
{
    if (ob->query_property("listen_debug"))
    {
        tell_object(ob, str + "\n");
    }
    return;
}



/*
 *Returns the thaco of the monster occording to number attacks the monster gets
 *The number of the attacks it's on if interactive and of course the target
 */
// if you mod this with something relevant to touch AC, please also add it to the function below!
varargs int Thaco(int attack_num, object targ, object current, string myclass) 
{
    
}

// here's the touch attack option! Adapting use for spells here. N, 10/15.
// note that this is bastardised compared to tabletop, since we have no distinction between 
// "deflection" bonuses, "natural AC", etc. The below grants dodge/mobility bonuses, racial 
// bonuses (even natural AC, yes) but to counterbalance, doesn't pick up items such as rops
// (which would usually be deflection). It does pick up all spell/magical bonuses as well.
int rangedTouchAC(object targ) 
{

}

void struck(int damage, object weapon, object attacker, string limb) 
{
    int x;
    if(damage > 0)  { x = do_damage(limb, damage); }    
    else            { x = 0; }
    if(objectp(attacker)) { attacker->send_messages(0, weapon,limb, x, TO); }
}


void new_struck(int damage, object weapon, object attacker, string limb, object victim, int fired, string ammo)
{
    "/daemon/combat_d.c"->new_struck(damage, weapon, attacker, limb, victim, fired, ammo, critical_hit);
}


// Will take care of doing any hits from TO, can be called if you want extra stuff
//is no longer used as of September 2016 - Saide
//instead use /daemon/combat_d.c->calculate_damage(attacker, target, weapon, target_thing, critical hit)
void do_hits(object targ, object current, string target_thing) 
{
    "/daemon/combat_d.c"->calculate_damage(TO, targ, current, target_thing, critical_hit);
}

// Will do fumbling
void do_fumble(object current) 
{
    "/daemon/combat_d.c"->fumble(TO, current);
}

int reactionAdj(int dex) 
{ 
    if(dex == 10) { return 0; }
    else return (dex - 10) / 2;
}

void prepare_attack() { attacking = 0; } //called in battle.c to ensure bugs don't fuck up attacks -Ares

int attack_count() { return attack_count; } 

// renamed the old execute_attack() to internal_execute_attack() down below.  We're going to track 
// if execute_attack gets called from inside of do_attack here, and if it does we'll increment 
// attack_count.  When the do_attack finishes, it'll set attacking = 0, and if there were any attacks 
// that didn't get executed we'll execute them then.  Hopefully this will stop our recursion errors 
// on attack from spamming the debug.log -Ares

void execute_attack()
{
    int i;
    if(!attacking)
    {
        if(!attack_count)
        {
            internal_execute_attack();
            return;
        }
        for(i=0;i<attack_count;i++)
        {
            attack_loop = 1;
            internal_execute_attack();
        }
        attack_count = 0;
        attack_loop = 0;
    }
    else
    {
        attack_count++;
    }
    return;
}

// this shouldn't get called by anything besides execute_attack.
static void internal_execute_attack() 
{
    int i, j, num_attacks, cur_ind, roll, fighter_attacks, temp1,temp2,rand,stat_mod, touch_attack = 0;
    object *weapons, current, attack2, victim, *temp_attackers, rider,*protectors;
    string target_thing,attack;

//  if (D_BUG_D->combat_hand()) tell_object(TO,"lastHand="+identify(lastHand));

    attacking = 1; // set this here, and don't let this function get called until attacking == 0

    if(objectp(TO)) // make sure the aren't flag for a critical hit on following attacks
    {
        critical_hit = 0;
        critical_message = 0;
    }
    if(!objectp(TO)) 
    {
        return;
    }
    if (!sizeof(attackers)) 
    {
        attacking = 0;
        if(attack_count && !attack_loop) { execute_attack(); }
        return;
    }

//    if (query_property("fleeing")) // the property from the <flee> command is actually "flee", not "fleeing". N, 10/15.
    if (query_property("flee")) 
    { 
        attacking = 0;
        if(attack_count && !attack_loop) { execute_attack(); }
        return; 
    }
    
    toAttack = random(sizeof(attackers));    
    while (!objectp(attackers[toAttack]) || !present(attackers[toAttack],ETO)) 
    {
        attackers -= ({attackers[toAttack]});
        if (!sizeof(attackers)) 
        {
            attacking = 0;
            if(attack_count && !attack_loop) { execute_attack(); }
            return;
        }
        toAttack = random(sizeof(attackers));
    }

    toattack = 4;

    victim=attackers[toAttack];

    protectors = query_active_protectors(victim);

    if(sizeof(protectors))
    {
        victim = protectors[random(sizeof(protectors))];
    }

    if(!living(victim) && !victim->query("not living")) 
    {
        attacking = 0;
        if(attack_count && !attack_loop) { execute_attack(); }
        return;
    }
    if(FEATS_D->usable_feat(TO, "perfect self")) 
    {
        if(!(int)TO->has_ki()) TO->regenerate_ki(4);
    }
    if (member_array(TO,(object *)victim->query_attackers()) == -1)
    {
        victim->add_attacker(TO);
        ETO->add_combatant(victim);
        clean_up_attackers();
    }

    if (!do_casting(victim) && !do_functions()) 
    {
        ok_to_wield();
        weapons = distinct_array(query_wielded());

        roll = random(20)+1;

        if(!victim->query_unconscious() && !victim->query_ghost() && !victim->query_bound()) 
        {
            if (victim->query_scrambling() && (victim->is_ok_armour("thief") || victim->query_property("shapeshifted")) ) 
            {
                if(!objectp(TO)) return;
                if(objectp(TO))
                {
                    temp1 = (int)TO->query_character_level();
                    stat_mod = (int)TO->query_stats("dexterity");
                }
                temp2 = (int)victim->query_skill("athletics");
                if(stat_mod == 10) { stat_mod = 0; }
                else { stat_mod = (stat_mod - 10) / 2; }

                if( (random(temp1*2) + stat_mod) < temp2) 
                {
                    //if(random((int)TO->query_character_level()) < random((int)victim->query_character_level())) 
                    //{
                        send_dodge(victim);
                        if(FEATS_D->usable_feat(victim,"spring attack")) 
                        {
                            if(!random(5)) spring_attack(victim);
                        }
                        if(!lastHand && objectp(TO)) { TO->set_property("bab_scale",BAB_SCALE); }
                        lastHand++; // This should be incremented for the next attack.
                        attacking = 0;
                        if(attack_count && !attack_loop) { execute_attack(); }
                        return;
                    //}
                }
            }

            // neither ride-by attack nor shot on the run should be effective against archers, as neither 
            // should carry the target out of range. So check to ensure they're not wielding a bow, or if 
            // they are, that they don't have the skill to use it in melee-range combat. N, 12/13.
            if((sizeof(weapons) && !weapons[0]->is_lrweapon()) || !FEATS_D->usable_feat(TO,"point blank shot"))
            {
                if(victim->query_in_vehicle() && FEATS_D->usable_feat(victim,"ride-by attack") && !random(5)) 
                {
                    temp1 = (int)TO->query_character_level();
                    temp2 = (int)victim->query_skill("athletics");

                    if((random(temp1*2) < temp2)) 
                    {
                        tell_object(TO,"%^RESET%^%^BOLD%^"+victim->QCN+" has already ridden past you and "
                            "is out of reach!%^RESET%^");
                        tell_object(victim,"%^RESET%^%^BOLD%^You deftly steer your steed and "+TO->QCN+
                            "'s blow falls short of hitting you!%^RESET%^");
                        tell_room(ETO,"%^RESET%^%^BOLD%^"+victim->QCN+" deftly steers "+victim->QP+
                            " steed and "+TO->QCN+"'s blow falls short of hitting "+victim->QO+
                            "!%^RESET%^",({TO,victim}));
                        if(!lastHand) { TO->set_property("bab_scale",BAB_SCALE); }
                        lastHand++;
                        attacking = 0;
                        if(attack_count && !attack_loop) { execute_attack(); }
                        return;
                    }
                }
                // setup for shot on the run. This should not stack with ride-by attack, as it's doing the same thing.
                // but a mounted archer without ride-by attack should still be able to use this.
                // this is triggered by the "shotontherun" temporary property, which requires an attack landed. N, 12/13.
                if(!FEATS_D->usable_feat(victim,"ride-by attack") && victim->query_property("shotontherun") && !random(5))
                {
                    temp1 = (int)TO->query_character_level();
                    temp2 = (int)victim->query_skill("athletics");

                    if((random(temp1*2) < temp2)) 
                    {
                        tell_object(TO,"%^RESET%^%^BOLD%^"+victim->QCN+" uses "+victim->QP+" own attack as "
                            "cover, and manages to move out of your reach!%^RESET%^");
                        tell_object(victim,"%^RESET%^%^BOLD%^You use your last shot as cover to get clear "
                            "of "+TO->QCN+"'s attack!%^RESET%^");
                        tell_room(ETO,"%^RESET%^%^BOLD%^"+victim->QCN+" uses "+victim->QP+" last shot as "
                            "cover to get clear of "+TO->QCN+"'s attack!%^RESET%^",({TO,victim}));
                        if(!lastHand) { TO->set_property("bab_scale",BAB_SCALE); }
                        lastHand++;
                        attacking = 0;
                        if(attack_count && !attack_loop) { execute_attack(); }
                        return;
                    }
                }
            }

            if(victim->is_animal() && !random(5)) 
            {
                rider = (object)victim->query_current_rider();
                if(objectp(rider)) 
                {
                    if(FEATS_D->usable_feat(rider,"mounted combat")) 
                    {
                        temp1 = (int)TO->query_character_level();
                        temp2 = (int)rider->query_skill("athletics");

                        if((random(temp1*2) < temp2)) 
                        {
                            tell_object(rider,"%^RESET%^%^BOLD%^You direct your steed out of harm's way!%^RESET%^");
                            tell_room(ETO,"%^RESET%^%^BOLD%^"+rider->QCN+" directs "+rider->QP+
                                "steed out of harm's way!%^RESET%^",rider);
                            if(!lastHand) { TO->set_property("bab_scale",BAB_SCALE); }
                            lastHand++;
                            attacking = 0;
                            if(attack_count && !attack_loop) { execute_attack(); }
                            return;
                        }
                    }
                }
            }
            if(sizeof(weapons)) 
            {
                if ((victim->query_parrying()) && (!victim->query_property("shapeshifted"))) 
                {
                   if(!random(2))
                   { //random chance added by ~Circe~ after discussions with other Imms 2/27/13
                       temp1 = (int)victim->query_character_level();
                       temp1 += ((int)victim->query_stats("strength") - 10) / 2;
   
                       temp2 = (int)TO->query_character_level();
                       temp2 += ((int)TO->query_stats("strength") - 10) / 2;

                       if(roll_dice(1,temp1) > roll_dice(1,temp2))
                       {
                           tell_object(TO,"Your attack is parried by your attacker!");
                           tell_player(victim,"You deftly parry your opponent's blow!\n");
                           //              victim->set_parrying(0);
                           tell_room(ETO,"You see "+TO->query_cap_name()+"'s attack parried by "+victim->query_cap_name()+".",({TO,victim}));
                           if(!lastHand) { TO->set_property("bab_scale",BAB_SCALE); }
                           lastHand++; // This should be incremented for the next attack.
                           attacking = 0;
                           if(attack_count && !attack_loop) { execute_attack(); }
                           return;
                       }
                   }
                }
            }
        }

        if ((current != 0) && (current->is_lrweapon())) 
        {
            tell_object(TO,"Your bow is useless in hand to hand combat.\n");
            attacking = 0;
            if(attack_count && !attack_loop) { execute_attack(); }
            return;
        }

        target_thing = (string)victim->return_target_limb();
        if (!sizeof(weapons) || lastHand > (sizeof(weapons)-1)) 
        {
            lastHand = 0;
            current = set_current_weapon(0);
//  if (D_BUG_D->combat_hand()) tell_object(TO,"Hand reset.");
        }
        if (sizeof(weapons)) current = set_current_weapon(weapons[lastHand]);


        
        //roll = random(20)+1;
        //should return 0 if a miss or the dice roll if it's a hit - a 20 is an automatic hit
        //0 is a miss - anything else is a hit - 20 is an automatic hit that ignores deflects/concealing amorpha
        //1 is no longer a miss but you will still poison yourself - Saide
        roll = BONUS_D->process_hit(TO, victim, i, current, 0, touch_attack);

        // crit stuff below here
        if(sizeof(weapons) && !TO->query_property("shapeshifted"))
        {
            temp1 = (int)current->query_critical_threat_range();
            if(FEATS_D->usable_feat(TO, "lethal strikes") && !TO->query_property("shapeshifted"))
            {
                if(sizeof(weapons) >= 2)
                {
                    if(weapons[0] != weapons[1]) temp1 += 1;
                    if((int)weapons[0]->query_size() == 1 && (int)weapons[1]->query_size() == 1) temp1 += 1;
                }
                else if(sizeof(weapons) == 1)
                {                  
                    temp1 += 1;
                    if((int)weapons[0]->query_size() == 1) temp1 += 1;
                }
            }
        }
        else // unarmed stuff here, we might have to adjust at some point.  Currently unarmed as a crit threat of 1, and a crit multiplier of 2
        {
            temp1 = 2;
        }

        if(roll > (20 - temp1)) // if threat range of weapon is 2, then we have a crit threat on a roll of 19 or 20
        {
            if(!victim->query_property("no crit") && ( !interactive(victim) || ((int)victim->query_level() > 5) ))
            {
                //temp2 = random(20)+1; // reroll to confirm crit
                temp2 = BONUS_D->process_hit(TO, victim, i, current);
                temp1 = (int)TO->query_property("bab_scale");
                TO->remove_property("bab_scale"); // going to try giving full bab to crit attempts, crits were fairly lacking before this

                if(temp2) // critical hit confirmed
                {
                    // damage is handled in "/daemon/combat_d.c"->calculate_damage()
                    // messages are handled in send_messages
                    critical_hit = 1;
                }

                TO->set_property("bab_scale",temp1); // give their penalty back after crit attempt

                // if critical is not confirmed, we do a normal hit
                if(critical_hit) critical_message = 1;
                if("/daemon/combat_d.c"->extra_hit_calcs(TO, victim, current, target_thing)) "/daemon/combat_d.c"->calculate_damage(TO, victim, current, target_thing, critical_hit);               
                if(!lastHand) { TO->set_property("bab_scale",BAB_SCALE); }
                /*lastHand++;
                attacking = 0;
                if(attack_count && !attack_loop) { execute_attack(); }
                return;*/
            }
        }
        // end crit stuff


        // if they fail to confirm a critical hit, still automatic hit on 20
        if (roll == 20 && !critical_hit) 
        {
            if("/daemon/combat_d.c"->extra_hit_calcs(TO, victim, current, target_thing)) "/daemon/combat_d.c"->calculate_damage(TO, victim, current, target_thing, critical_hit);
            if(!lastHand) { TO->set_property("bab_scale",BAB_SCALE); }
            lastHand++;
            attacking = 0;
            if(attack_count && !attack_loop) { execute_attack(); }
            return;
        }

        //Failure while using a poisoned weapon = reflex save DC 15 or poison 
	    //yourself - Saide
        if(roll == 1)
        {
            if(objectp(current)) 
            {
                if((int)current->query("PoisonDoses")) 
                {
                    if(TO->reflex_save(15)) 
                    {
                        POISON_D->is_object_poisoned(current, TO, "hit", 1);
                    }
                }
            }
        }
        //modifying this so that a 1 is no longer an automatic miss - Saide
        //if (roll && roll != -1) 
        if(roll && !critical_hit)
        {
            //if they don't miss or don't roll a 20 on the dice then check 
            //to see if the attack is blocked by a shield or concealing amorpha/timeless body - Saide
            //and touch attack is not 1 
            if("/daemon/combat_d.c"->extra_hit_calcs(TO, victim, current, target_thing)) "/daemon/combat_d.c"->calculate_damage(TO, victim, current, target_thing, critical_hit);
            //else if(touch_attack) "/daemon/combat_d.c"->calculate_damage(TO, victim, current, target_thing, critical_hit);
        }
        else if(!critical_hit)
        {
            if (!current || TO->query_property("shapeshifted")) miss(casting, victim, 0, target_thing);
            else miss(0, victim, (string)current->query_type(), target_thing);
        }

    }

    if(!objectp(TO)) 
    { 
        attacking = 0;
        if(attack_count && !attack_loop) { execute_attack(); }
        return; 
    }
    if(!objectp(victim)) 
    { 
        attacking = 0;
        if(attack_count && !attack_loop) { execute_attack(); }
        return; 
    }

/*    if(lastHand == 0) // stab will now proc only when the main hand weapon is being used.
    {
        if(FEATS_D->usable_feat(TO,"combat reflexes") && is_ok_armour("thief") && is_class("thief") && !TO->query_casting() && !TO->query_property("shapeshifted")) 
        {
            temp1 = (int)TO->query_skill("stealth") + roll_dice(1,20);
            temp2 = (int)victim->query_skill("perception") + roll_dice(1,20);

            if(temp2 < temp1) 
            {
                if(random(4*(int)victim->query_character_level()) < query_guild_level("thief")) 
                {
                    tell_object(TO,"You successfully move yourself into a position exposing "+victim->QCN+"'s back.");
                    tell_object(victim,"You suddenly notice that "+TOQCN+" has moved and your back is exposed.");
                    tell_room(ETO,""+TOQCN+" has positioned "+TO->QO+"self behind "+victim->QCN+"'s back.",({victim,TO}));
                    "/cmds/mortal/_stab"->scramble_stab(TO,victim);
                }
            }
        }
    }*/
    // major retune to stab chance. Now 1 stab/10 thief levels available per round, going on each consecutive attack.
    // now also works in shapeshift. Calls from battle.c to track how many stabs in that round. N, 12/16.
    // to change the rate please adjust battle.c & can_scramble_stab().
    if(FEATS_D->usable_feat(TO,"combat reflexes") && is_ok_armour("thief") && !TO->query_casting() && (int)TO->query_property("stabs_available") > 0) {
        TO->set_property("stabs_available",-1);
        tell_object(TO,"You successfully move yourself into a position exposing "+victim->QCN+"'s back.");
        tell_object(victim,"You suddenly notice that "+TOQCN+" has moved and your back is exposed.");
        tell_room(ETO,""+TOQCN+" has positioned "+TO->QO+"self behind "+victim->QCN+"'s back.",({victim,TO}));
        "/cmds/mortal/_stab"->scramble_stab(TO,victim);
    }

    if (((int)TO->query_scrambling() == 1)&& is_ok_armour("thief") && is_class("thief")) 
    {
        if(D_BUG_D->scramble_change()) TO->set_scrambling(2);
    }

    attacking = 0;
    if(attack_count && !attack_loop) { execute_attack(); }
    if(!lastHand) { TO->set_property("bab_scale",BAB_SCALE); }
    lastHand++;// Increment hand to next one.
    return;
}

void stop_hunting() 
{
    hunting = 0;
    hunters = ({});
}

void cease_all_attacks() 
{
    attackers = ({});
    atnames = ({});
    any_attack = 0;
}

object query_current_attacker() 
{
    if(!clean_up_attackers()) return 0;
    else return attackers[0];
}

void run_away()
{
    string *str;
    string dir;

    if(!objectp(TO) || !objectp(environment(TO))) return;
    str = (string*)environment(TO)->query_exits();
    if(!str || !sizeof(str)) 
    {
        tell_object(TO,"There is nowhere to run!!!");
        return;
    }
    tell_object(TO,"You run away.");
    if(member_array(wimpydir, str) != -1) 
    { 
        dir = wimpydir; 
    } 
    else if(wimpydir == "retreat") 
    { 
        dir = ETO->query_direction(base_name(TO->query_last_location())); 
    }
    if(!dir || dir == "/d/shadowgate/void")
    {
        dir = str[random(sizeof(str))];
    }
    TO->set_property("true moving",dir);
    TO->set_property("running away",1);
    TO->force_me(dir);
    TO->remove_property("running away");
    TO->remove_property("true moving");
    wimped = 1;
    return;
}

void set_wimpydir(string str) 
{
    if (!stringp(str)) return;
    wimpydir = str;
}

void set_wimpy(int x) { wimpy = x; }

string query_wimpydir() { return wimpydir; }

int query_wimpy() { return wimpy; }

void set_casting(int x) { casting = x; }

int query_casting() { return casting; }

int valid_casting() 
{
    if(query_casting() && objectp(TO->query_property("spell_casting"))) return 1;
    return 0;
}

void send_messages(int magic, object current, string what, int x, object attacker, int fired, string ammo) 
{
    "/daemon/combat_d.c"->send_messages(TO, magic, current, what, x, attacker, fired, ammo, critical_message);
}

object *query_hunted() { return hunters; }

object *query_attackers() 
{
    if(!attackers) return ({});
    attackers -= ({ 0 });
    if(!sizeof(attackers))
    {
	  if(objectp(TO)) 
	  {
        	TO->remove_property("using whirl");
        	TO->remove_property("using sweeping blow");
        	TO->remove_property("using manyshot");
            TO->remove_property("using spinning kick");
        	return ({});
	  }
    }
    if(!pointerp(attackers)) { attackers = ({}); }
    attackers = distinct_array(attackers);
    return attackers;
}

int sight_adjustment() 
{
    int elight, ret;
    ret = 0;
    elight = effective_light(TO);
    if(elight > 6 || elight < 1) { ret = random(5); }
    return ret;
}

void miss(int magic, object target, string type, string target_thing) 
{
    "/daemon/combat_d.c"->miss(TO, magic, target, type, target_thing);
}

void set_paralyzed(int x, string drow) 
{
    if(archp(TO)) 
    {
        message("my_action", "Your Archhood just saved you from being paralyzed.", TO);
        return;
    }
	if(TO->query_property("no paralyze"))
	{
		message("my_action","You are uneffected by the paralysis.",TO);
		return;
	}
    if(!drow) { paralyze_message = DEFAULT_PARALYZE_MESSAGE; }
    else { paralyze_message = drow; }
    paralyzed = 1;
    x = x/2 +1;
    call_out("remove_paralyzed", x);
}

string query_paralyze_message() 
{
    if(TO->adminBlock())        { return ""; }
    if (query_deaths_door())    { return DEATHS_DOOR_MESSAGE; }
    if (query_unconscious())    { return query_unconscious_message(); }
    if (query_paralyzed())      { return paralyze_message; }
    if (query_bound())          { return query_bound_message(); }
    if (query_tripped())        { return query_tripped_message(); }
}

int query_paralyzed() 
{
    if(TO->adminBlock()) { return 1; }
    return paralyzed || query_unconscious();
}

void remove_paralyzed() 
{
    if(!objectp(TO)) { return; }
    remove_call_out("remove_paralyzed");
    if(paralyzed != 1) return;
    paralyzed = 0;
    if(TO->query_tripped() || TO->query_bound() || TO->query_unconscious()) { return; }
    tell_object(TO,"You can move again.");
    if(!TO->query_invis()) 
    {
	    tell_room(ETO, "%^BOLD%^%^GREEN%^You see "+TOQCN+" is moving again.%^RESET%^", TO);
    }
    return;
}

int ok_to_kill(object targ) 
{
    int vic_level, pk_age_limit;
    string str, title;
    object hold;
// adding objectp checks to stop bugs (noticed w/spell targets in debug) *Styx* 1/16/04, last change 1/9/04
    if(!objectp(targ) || !objectp(TO))  return 0;
    if (targ->is_invincible()) {
/**  This tell more than it should when imms are around
        tell_object(TO,targ->QCN+"%^BLUE%^ is invincible and unable "+
        "to be attacked!%^RESET%^");
**/
        return 0;
    }
//   if(ETO->query_property("no kill") || ETO->query_property("no attack")) return 0;
    if (interactive(TO) && interactive(targ)) 
    {
//        if (newbiep(TO)) return 0;
//        if (newbiep(targ)) return 0;
        if (newbiep(TO) && (!avatarp(targ))) {
           if(TO == targ) return 1; //added to stop bugs with spells like 
//vampiric touch.  Circe 6/29/07
            tell_object(TO,"%^YELLOW%^You are currently under "+
            "%^CYAN%^newbie%^YELLOW%^ protection and unable to "+
            "be aggressive against "+targ->QCN+"%^YELLOW%^!%^RESET%^");
            return 0;
        }
        if (newbiep(targ) && (!avatarp(TO))) {
           if(TO == targ) return 1; //added to stop bugs with spells like 
//vampiric touch.  Circe 6/29/07
            tell_object(TO,targ->QCN+"%^YELLOW%^ is currently "+
            "under %^CYAN%^newbie%^YELLOW%^ protection and "+
            "cannot be attacked by you.%^RESET%^");
            return 0;
        }
        //pkill time restrictions - Saide
        pk_age_limit = "/adm/daemon/average_age_d.c"->return_age_needed((int)targ->query_character_level());
        if(targ == TO) return 1;
        if((int)targ->query_age() < pk_age_limit)
        {
            tell_object(TO, targ->QCN+"%^YELLOW%^ is currently "+
            "time barred from being involved in pkill interactions.%^RESET%^");
            return 0;
        }
        pk_age_limit = "/adm/daemon/average_age_d.c"->return_age_needed((int)TO->query_character_level());
        if((int)TO->query_age() < pk_age_limit)
        {
            tell_object(TO, "%^YELLOW%^You are currently time "+
            "barred from being involved in pkill interactions.%^RESET%^");
            return 0;
        }
        
        if (in_edit(targ) || in_input(targ) && interactive(TO)) {
            tell_object(TO,targ->QCN+"%^RED%^ is currently in "+
            "edit and cannot be attacked.%^RESET%^");
            return 0;
        }
    }
    if (!interactive(TO) || !interactive(targ)) return 1;
    return 1;
}

int light_armor_filter(object ob)
{
    if(!objectp(ob)) { return 0; }
    if((string)ob->query_armor_prof() == "heavy") { return 1; }
    if((string)ob->query_armor_prof() == "medium") { return 1; }
    return 0;
}

void ok_to_wield() {
    object *wielded,*worn;
    int Size;

    if (interactive(TO)) 
    {
        wielded = TO->query_wielded();
        worn    = TO->all_armour();
        worn    = distinct_array(worn);
        worn    = filter_array(worn,"light_armor_filter",TO);

        if (sizeof(wielded) > 1) 
        {
            Size = (int)TO->query_size() - 1;
            if(Size == 0) Size = 1;

            if((wielded[0]->query_size() > Size) && (wielded[1]->query_size() > Size) && (wielded[0] != wielded[1]))
            {
                if(FEATS_D->usable_feat(TO,"ambidexterity"))
                {
                    if(sizeof(worn))
                    {
                        tell_object(TO,"You scramble to hang on to your "+wielded[0]->query_name()+" and "
                            "your "+wielded[1]->query_name()+" but all that armor makes it impossible!");
                        tell_room(ETO,""+TO->QCN+" scrambles to hang on to "+TO->QP+" "+wielded[0]->query_name()+" "
                            "and "+TO->QP+" "+wielded[1]->query_name()+" but fumbles and drops them!",TO);
                        if (!wielded[0]->query_property("enchantment") || (int)wielded[0]->query_property("enchantment") > 0) wielded[0]->move(environment(TO));
                        if (!wielded[1]->query_property("enchantment") || (int)wielded[1]->query_property("enchantment") > 0) wielded[1]->move(environment(TO));
                    }
                }
                else
                {
                    tell_object(TO,"In your attempt to wield two such weapons, you fumble and drop them.");
                    tell_room(ETO,TO->QCN+" fumbles with "+TO->QP+" "+wielded[0]->query_name()+" and "
                        ""+TO->QP+" "+wielded[1]->query_name()+" and then drops them.",TO);
                    if (!wielded[0]->query_property("enchantment") || (int)wielded[0]->query_property("enchantment") > 0) wielded[0]->move(environment(TO));
                    if (!wielded[1]->query_property("enchantment") || (int)wielded[1]->query_property("enchantment") > 0) wielded[1]->move(environment(TO));
                }
            }
        }
    }
}

void add_attacker(object ob) {
    if (ob == TO) return;
    if (member_array(ob, attackers)!=-1) return;
    attackers += ({ob});
    if (PO == TO) return;
    if (objectp(ob) && userp(ob)) {
        if (member_array(ob->query_name(), atnames)!=-1) return;
        if (!objectp(ETO)) return;
        if (ETO->query_property("arena")) return;
        atnames += ({ob->query_name()});
    }
    any_attack = sizeof(attackers);
      check_death();
    clean_up_attackers();
}

int reaction_adj() 
{
    int dex;
    int adjust;

    dex = TO->query_stats("dexterity");
    adjust = (dex - 10) / 2;
    return adjust;
}

void thaco_messages(int thaco) 
{
    switch (thaco) {
    case 10:
    case 9:
    case 8: write("%^YELLOW%^Your pitiful attempt at wielding two weapons is just silly.%^RESET%^");
        break;
    case 7:
    case 6:
    case 5: write("%^ORANGE%^You look really silly trying to wield two weapons %^RESET%^");
        break;
    case 4: write("%^RED%^You awkwardly attack with two weapons %^RESET%^");
        break;
    case 3: write("%^YELLOW%^You have trouble attacking with two weapons.%^RESET%^");
        break;
    case 2: write("%^BLUE%^You find difficulty in wielding two weapons.%^RESET%^");
        break;
    case 1: write("%^GREEN%^Wielding two weapons is harder but still effective.%^RESET%^");
        break;
    default: break;
    }
}

void remove_attacker(object attack) {
    //tell_room(ETO," "+TPQN+" attackers b = "+identify(attackers));
    while (member_array(attack,attackers) != -1)
        attackers -= ({attack});
    while (member_array(attack,hunters) != -1)
        hunters -= ({attack});
    if (objectp(attack))
        atnames -= ({attack->query_name()});
    //tell_room(ETO," "+TPQN+" atnames b = "+identify(atnames));
    //tell_room(ETO," "+TPQN+" attackers a = "+identify(attackers));
    return;
}

void add_hunted(object hunt) {
    if (member_array(hunt, hunters) == -1)
        hunters += ({hunt});
    return;
}

int is_ok_armour(string myclass)
{
    return "/daemon/combat_d.c"->is_ok_armour(TO, myclass);
}

int is_ok_weapon(string myclass)
{
    return "/daemon/combat_d.c"->is_ok_weapon(TO, myclass);
}


void send_dodge(object att) 
{
    int i,j;
    string *verb,*adverb,v,a;

// adding objectp checks for bug prevention *Styx* 1/16/04, last change 1/9/04
    if(!objectp(att) || !objectp(TO))  return;

    verb = ({"flip","back flip","jump","dodge","roll","somersault","dance","spin","scramble"});
    adverb = ({"easily","quickly","barely","poorly","with agility","deftly"});
    v = verb[random(sizeof(verb))];
    a = adverb[random(sizeof(adverb))];
    tell_object(TO,att->query_cap_name()+" "+v+"s "+a+" from your blow.");
    tell_object(att,"You "+v+" "+a+" from "+TOQCN+"'s blow.");
    tell_room(ETO,att->query_cap_name()+" "+v+"s "+a+" from "+TOQCN+"'s blow.",({TO,att}));
}


object *query_active_protectors(object obj)
{
    object *protectors = ({}),*good_protectors=({});
    int i;

    if(!objectp(obj)) { return ({}); }

    protectors = (object *)obj->query_protectors();

    if(!pointerp(protectors)) { return ({}); }
    if(!sizeof(protectors)) { return ({}); }

    for(i=0;i<sizeof(protectors);i++)
    {
        if(!objectp(protectors[i])) { continue; }
        if(!protectors[i]->query("protecting")) { continue; }
        if(!present(protectors[i],environment(obj))) { continue; } 
//above line added to stop the bug where protectors not in the room still take hits ~Circe~ 3/24/13

        good_protectors += ({ protectors[i] });
    }

    if(!sizeof(good_protectors)) { return ({}); }

    return good_protectors;
}


object *doProtection(object player) 
{
    int i,j;
    object *pros, *tmp=({});

    if (!objectp(player)) { return ({ player }); }
    pros = player->query_protectors();

    j = sizeof(pros);
    if (!j) { return({player}); }

    for (i=0;i<j;i++) 
    {
        if(!objectp(pros[i])) continue;
        
        if(!present(pros[i], ETO) && (!pros[i]->query_following() || (object)pros[i]->query_following() != player))
        {
            player->remove_protector(pros[i]);
            continue;
        }
        
        if(pros[i] == TO) 
        {
            player->remove_protector(pros[i]);
            continue;
        }
        
        if(member_array(pros[i], query_attackers()) == -1) 
        {
            tmp+=({pros[i]});
        }
        
        if((int)pros[i]->query_hp_percent() < 30) 
        {
            player->remove_protector(pros[i]);
            tell_object(pros[i], "You are too weak to continue protecting "+player->QCN+".");
            set("protecting",0);
            continue;
        }

        //if(random(query_highest_level()*2) > random((int)pros[i]->query_highest_level() + (int)player->query_lowest_level())) 
        if(!random(7))
        {
            //tell_object(pros[i], "You are unable to defend "+player->query_cap_name()+" this attack.");
            set("protecting",0);
            continue;
        }

        //tell_object(pros[i], "You stand in defense of "+player->query_cap_name()+".");
        //tell_object(player,pros[i]->query_cap_name()+" stands in defense of you.");
        pros[i]->set("protecting",1);
        tmp += ({pros[i]});
    }

    //if (!sizeof(tmp)) tmp += ({player});
    tmp += ({player});
    tmp = distinct_array(tmp);
    return tmp;
}

void add_reaction(int x) {
    react += x;
}

int query_reaction() {
    return react;
}

int query_dead() {
    return dead;
}

int queryFuncing() {
    return funcing;
}

void setFuncing(int i) {
    funcing = i;
}


int ok_combat_vars() {
  if ( (!combat_vars) || (combat_vars == ([])) ||
       (!combat_messages) || (combat_messages == ([])) ||
       (!combat_counters) || (combat_counters == ([])) ||
       (!combat_static_vars) || (combat_static_vars == ([])) )
    return 0;
  else {
  if (!intp(combat_counters["gagged"])) return 0;
  if (!intp(combat_counters["bound"])) return 0;
  if (!intp(combat_counters["tripped"])) return 0;
  if (!intp(combat_counters["asleep"])) return 0;
  if (!intp(combat_counters["unconscious"])) return 0;
  if (!intp(combat_counters["healing"])) return 0;
  if (!intp(combat_counters["block_attack"])) return 0;
  else    return 1;
  }
}

void initialize_combat_vars() {
  if(!combat_vars || (combat_vars == ([]))) combat_vars = (["gagged":0,"bound":0,"tripped":0,"unconscious":0,"asleep":0,"blindfolded":0]);
  if(!combat_messages || (combat_messages == ([]))) combat_messages = (["gagged":0,"bound":0,"tripped":0,"unconscious":0,"asleep":0]);
  if(!combat_counters || (combat_counters == ([]))) combat_counters = (["gagged":0,"bound":0,"tripped":0,"unconscious":0,"asleep":0,"blindfolded":0,"blinded":0,"healing":0,"block_attack":0]);
  if (!intp(combat_counters["gagged"])) combat_counters["gagged"] = 0;
  if (!intp(combat_counters["bound"])) combat_counters["bound"] = 0;
  if (!intp(combat_counters["tripped"])) combat_counters["tripped"] = 0;
  if (!intp(combat_counters["asleep"])) combat_counters["asleep"] = 0;
  if (!intp(combat_counters["blindfolded"])) combat_counters["blindfolded"] = 0;
  if (!intp(combat_counters["blinded"])) combat_counters["blinded"] = 0;
  if (!intp(combat_counters["unconscious"])) combat_counters["unconscious"] = 0;
  if (!intp(combat_counters["healing"])) combat_counters["healing"] = 0;
  if (!intp(combat_counters["block_attack"])) combat_counters["block_attack"] = 0;
  if(!combat_static_vars || (combat_static_vars == ([]))) combat_static_vars = (["gagged":0,"bound":0,"tripped":0,"unconscious":0,"asleep":0,"blindfolded":0,"blinded":0]);

//  write("Initted combat vars.");
}

void set_gagged(int x, string message) {
  if (!ok_combat_vars()) initialize_combat_vars();
    combat_vars["gagged"] = x;
    combat_messages["gagged"] = message;
}

int query_gagged() {
  if (!ok_combat_vars()) initialize_combat_vars();
    return combat_vars["gagged"];
}

string query_gagged_message() {
    if (!combat_messages["gagged"]) {
        return DEFAULT_GAGGED_MESSAGE;
    }
    return combat_messages["gagged"];
}

void set_bound(int difficulty, string message) {
  if (!ok_combat_vars()) initialize_combat_vars();
    combat_vars["bound"] = difficulty;
    combat_messages["bound"] = message;
}

void set_temporary_blinded(int difficulty) {
  if (!ok_combat_vars()) initialize_combat_vars();
    combat_static_vars["blinded"] = difficulty;
}

void set_blindfolded(int difficulty) {
  if (!ok_combat_vars()) initialize_combat_vars();
  combat_vars["blindfolded"] = difficulty;
}                                   

int query_temporary_blinded() {
  if (!ok_combat_vars()) initialize_combat_vars();
  return combat_static_vars["blinded"];
}                                                                              
int query_blindfolded() {
  if (!ok_combat_vars()) initialize_combat_vars();
  return combat_vars["blindfolded"];
}

int query_blind() {
  if (!ok_combat_vars()) initialize_combat_vars();
  if (combat_static_vars["blinded"] || combat_vars["blindfolded"] || ::query_blind())
    return 1;
   else
    return 0;
}
int query_bound() {
  if (!ok_combat_vars()) initialize_combat_vars();
    return combat_vars["bound"];
}

string query_bound_message() {
    if (!combat_messages["bound"]) {
        return DEFAULT_BOUND_MESSAGE;
    }
    return combat_messages["bound"];
}

varargs void set_tripped(int severity, string message,int special)
{
    int chance;
	if (!ok_combat_vars()) { initialize_combat_vars(); }
    if(!objectp(TO)) return;
	if(TO->query_property("no tripped"))
	{ 
		if(objectp(TO)) tell_object(TO,"You cannot be tripped.");
		return; 
	}
    if(intp(chance = TO->query_property("untrippable")))
    {
        if(chance > roll_dice(1, 100))
        {
            tell_object(TO, "You avoid the attempt to trip you!");
            if(objectp(ETO)) { tell_room(ETO, TO->query_name()+" avoids the attempt to trip "+TO->query_objective()+"!", TO); }
            return;
        }
    }
    
    combat_vars["tripped"] = severity;
    combat_messages["tripped"] = message;
	if(special) { tripped_counter = special; } // Added to give better control over rush, could
}											   // be used for other things.  -Ares 12/26/06

int query_tripped() {
  if (!ok_combat_vars()) initialize_combat_vars();
    return combat_vars["tripped"];
}

string query_tripped_message() {
    if (!combat_messages["tripped"]) {
        return DEFAULT_TRIPPED_MESSAGE;
    }
    return combat_messages["tripped"];
}

void set_unconscious(int xxx, string message) {
  if (!ok_combat_vars()) initialize_combat_vars();
    combat_vars["unconscious"] = xxx;
    combat_messages["unconscious"] = message;
}

int query_unconscious() {
  if (!ok_combat_vars()) initialize_combat_vars();
    return(combat_vars["unconscious"] || (query_hp() < 1) || combat_vars["asleep"]);
}

int query_asleep(){

  if (!ok_combat_vars()) initialize_combat_vars();
    return(combat_vars["asleep"]);
}

void set_asleep(int xxx, string message) {
  if (!ok_combat_vars()) initialize_combat_vars();
    combat_vars["asleep"] = xxx;
    combat_messages["asleep"] = message;
}


string query_asleep_message() {
    if (!combat_messages["asleep"]) {
        return DEFAULT_ASLEEP_MESSAGE;
    }
    return combat_messages["asleep"];
}


string query_unconscious_message() {
    if (!combat_messages["unconscious"]) {
        return DEFAULT_UNCONSCIOUS_MESSAGE;
    }
    return combat_messages["unconscious"];
}

int query_deaths_door() {
    return query_hp() < 1;
}

void iterate_combat() {
     /// Note block_attack is not iterated here. It is iterated with each combat round.  -- garrett
  if (!ok_combat_vars()) initialize_combat_vars();
    if (combat_static_vars["blinded"]) {
      if (combat_counters["blinded"] > 7) {
            combat_static_vars["blinded"]=combat_static_vars["blinded"]-1;
            combat_counters["blinded"] = 0;
            if (!query_blind()) {
                message("combat","%^BOLD%^%^BLUE%^You can see again",TO);
            }
      }
      combat_counters["blinded"]=combat_counters["blinded"]+1;
    }

    if (combat_vars["blindfolded"]) {                                       
        if (combat_counters["blindfolded"] > (25 - (int)TO->query_stats("dexterity"))) {
            combat_vars["blindfolded"]=combat_vars["blindfolded"]-1;
            combat_counters["blindfolded"] = 0;
            if (!query_blind()) {
                message("combat","%^BOLD%^%^BLUE%^You can see again",TO);
        }
     }
        combat_counters["blindfolded"]=combat_counters["blindfolded"]+1;
    }

    if (combat_vars["gagged"]) {
        if (combat_counters["gagged"] > (25 - (int)TO->query_stats("dexterity"))) {
            combat_vars["gagged"]=combat_vars["gagged"]-1;
            combat_counters["gagged"] = 0;
            if (!combat_vars["gagged"]) {
                message("combat","%^BOLD%^%^BLUE%^You have struggled your gag off..",TO);
             }
        }
        combat_counters["gagged"]=combat_counters["gagged"]+1;
    }
    if (combat_vars["bound"]) {
        if (combat_counters["bound"] > (25 - (int)TO->query_stats("strength"))) {
            combat_vars["bound"]=combat_vars["bound"]-1;
            combat_counters["bound"] = 0;
            if (!combat_vars["bound"]) {
                message("combat","%^BOLD%^%^BLUE%^You have broken your bonds.",TO);
	      if(!TO->query_invis() && !random(3))
	         tell_room(ETO, "%^GREEN%^"+TOQCN+" breaks free of "+TO->QP+" bonds.%^RESET%^", TO);
            }
        }
        combat_counters["bound"]=combat_counters["bound"]+1;
    }
    if (combat_vars["tripped"]) {
		if(tripped_counter) 
        {  
            tripped_counter--; 
		    if(tripped_counter < 1 ) { tripped_counter = 0; combat_vars["tripped"] = 1; combat_counters["tripped"] = 100; }
        }
        //if (combat_counters["tripped"] > (20+random(5)-(int)TO->query_stats("dexterity"))) {
        // changed this to use the dex mod instead of raw dex since so many people have 20-25 dex now -Ares
        if (combat_counters["tripped"] > (7+random(5)-(((int)TO->query_stats("dexterity") - 10) / 2)  ) ) { 
            combat_vars["tripped"]=combat_vars["tripped"]-1;
            combat_counters["tripped"] = 0;
            if (!combat_vars["tripped"]) {
// if they are still disabled from something else, no message(s) needed *Styx*  11/22/04
    	      if(!TO->query_paralyzed() && !TO->query_bound() && 
		!TO->query_unconscious()) {
                message("combat","%^BOLD%^%^BLUE%^You have managed to stand again.",TO);
	        if(!TO->query_invis())  // added by *Styx*  11/19/04
		   tell_room(ETO, "%^BOLD%^%^GREEN%^You see "+TOQCN+" standing again.%^RESET%^", TO);
	      }
            }
        }		
        combat_counters["tripped"]=combat_counters["tripped"]+1;
    }
    if (combat_vars["unconscious"]) {
        if (sizeof(query_attackers()) > 0) {

            combat_vars["unconscious"]=0;
            combat_counters["unconscious"] = 0;
            message("combat","%^BOLD%^%^BLUE%^You have regained consciousness.",TO);
    	    if(!TO->query_invis())
    	       tell_room(ETO, "%^GREEN%^You notice "+TOQCN+" waking up.%^RESET%^", TO);
        }
        if (combat_counters["unconscious"] > (25 - (int)TO->query_stats("constitution")) ) {
            combat_vars["unconscious"]=combat_vars["unconscious"]-1;
            combat_counters["unconscious"] = 0;
            if (!combat_vars["unconscious"]) {
              message("combat","%^BOLD%^%^BLUE%^You have regained consciousness.",TO);
              if(!TO->query_invis())  // added by *Styx*  11/22/04
                  tell_room(ETO, "%^GREEN%^You notice "+TOQCN+" waking up.%^RESET%^", TO);
            }
        }
        combat_counters["unconscious"]=combat_counters["unconscious"]+1;
    }
    if (combat_vars["asleep"]) {
        if (combat_counters["asleep"] > (25 - (int)TO->query_stats("constitution")) ) {
            combat_vars["asleep"]=combat_vars["asleep"]-1;
            combat_counters["asleep"] = 0;
            if (!combat_vars["asleep"]) {
	      if(!TO->query_invis())  // added by *Styx*  11/22/04
	         tell_room(ETO, "%^GREEN%^You notice "+TOQCN+" waking up.%^RESET%^", TO);
              message("combat","%^BOLD%^%^BLUE%^You have awakened.",TO);
            }
        }
        combat_counters["asleep"]=combat_counters["asleep"]+1;
    }

    // Deaths door healing gonna say constitution relative.
/*  This has been bugging on moving NPC's to rooms so I'm going to put something into 
*   reset instead until/unless we can find something else to fix *Styx*  9/22/05
*    if ((TO->is_townsman() && query_hp() < query_max_hp())) {
*        
*        if (combat_counters["healing"] > (25 - (int)TO->query_stats("constitution")) ) {
*            heal(random(2)+1);
*        }
*    }
*/
    if (query_deaths_door() ){ 
        if (combat_counters["healing"] > (25 - (int)TO->query_stats("constitution")) ) {
            heal(random(2)+1);
//minor change from do_damage by Circe to hopefully stop bug with stoneskin that 
//you can't regain hp while unconscious.  2/6/04
            combat_counters["healing"]=0;
            if (!query_deaths_door()) {
                message("combat","%^BOLD%^%^BLUE%^You have healed sufficiently to regain consciousness.",TO);
        	if(!TO->query_invis())  // added by *Styx*  11/22/04
        	  tell_room(ETO, "%^GREEN%^You notice "+TOQCN+" waking up.%^RESET%^", TO);
            }
        }
        combat_counters["healing"]++;
    }
}

void send_paralyzed_message(string type,object who) {
    // adding objectp checks as bug prevention *Styx* 1/16/04, last change 1/9/04
    if(!objectp(who) || !objectp(TO))  return;

    if (query_deaths_door()) {
        message(type,DEATHS_DOOR_MESSAGE,who);
        return;
    }
    if (query_asleep()) {
        message(type,query_asleep_message(), who);
        return;
    }
    if (query_unconscious()) {
        message(type,query_unconscious_message(),who);
        return;
    }
    if (query_paralyzed()) {
        message(type,query_paralyze_message(),who);
        return;
    }
    if (query_bound()) {
        message(type,query_bound_message(),who);
        return;
    }
    if (query_tripped()) {
        message(type,query_tripped_message(),who);
        return;
    }
}

int reset_hunted() {
  hunters = ({ });
  return 1;
}

int remove_hunted(object hunt) {
  int i;
  object *htemp;
  if(member_array(hunt, hunters) == -1) {
    htemp = ({ });
    for(i=0;i<sizeof(htemp);i++) {
      if(hunt != hunters[i]) htemp += ({ hunters[i] });
    }
    hunters = htemp;
    return 1;
  }
  return 0;
}

string view_combat_vars() {
  string str;
  str = "";
  str += "vars"+identify(combat_vars)+"\n";
  str += "msgs"+identify(combat_messages)+"\n";
  str += "counters"+identify(combat_counters)+"\n";
  str += "svars"+identify(combat_static_vars)+"\n";
//  write(str);

  return str;
}

int is_in_combat() 
{
  return clean_up_attackers();
}

void set_offensive_bonus(int x){
    set("offensive",x);
}

void add_offensive_bonus(int x){
    set("offensive", query("offensive")+x);
}

void set_defensive_bonus(int x){
    set("defensive",x);
}

void add_defensive_bonus(int x){
    set("defensive", query("defensive")+x);
}

int query_defensive_bonus(){
    return query("defensive");
}


int query_offensive_bonus(){
    return query("offensive");
}

void slide_offensive_scale(int x){
    add_offensive_bonus(x);
    add_defensive_bonus(-1 * x);
}                         

void reset_offensive_scale(){
	set_offensive_bonus(0);
	set_defensive_bonus(0);
}

object set_current_weapon(object ob) {
  if (!objectp(ob)) ob = 0;
  return current_weapon = ob;
}

object query_current_weapon() {
  if (!objectp(current_weapon)) return TO;
  return current_weapon;
}

int get_block_chance(object obj)
{
    object shield,*equip;
    int i,chance;
    
    if(!objectp(obj)) { return 0; }
    if(!living(obj)) { return 0; }

    //if(!obj->is_wearing_type("shield") && !obj->is_wearing_type("thiefshield")) { return 0; }

    //equip = (object)obj->all_armour();
    //for(i=0;i<sizeof(equip);i++)
    //{
    //    if(!objectp(equip[i])) { continue; }
    //    if((string)equip[i]->query_type() != "shield" && (string)equip[i]->query_type() != "thiefshield") { continue; }
    //    shield = equip[i];
    //     break;
    //}

    //chance = (int)shield->query_block_chance();
    
    chance = (int)obj->query_shieldMiss();

    return chance;
}

void reset_critical()
{
    critical_hit = 0;
    critical_message = 0;
}





