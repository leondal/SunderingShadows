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
#define NEWBIE 6
#define BAD_LIMBS ({"torso","neck","waist","lower torso","tail"})
#define ADJUST (["thief":10,"fighter":0,"cleric":6,"assassin":10,"ranger":4,"paladin":2,"antipaladin":2,"cavalier":2,"mage":10,"bard":5,"psion":10])
#define DEFAULT_PARALYZE_MESSAGE "You are stiff as stone."
#define DEFAULT_GAGGED_MESSAGE "You are gagged and can not speak."
#define DEFAULT_BOUND_MESSAGE "You are bound and can not move."
#define DEFAULT_TRIPPED_MESSAGE "You have fallen and are trying to get up."
#define DEFAULT_UNCONSCIOUS_MESSAGE "You are unconscious."
#define DEFAULT_ASLEEP_MESSAGE "You are fast asleep."
#define DEFAULT_MESSAGES (["asleep" : DEFAULT_ASLEEP_MESSAGE, "paralyzed" : DEFAULT_PARALYZE_MESSAGE, "gagged" : DEFAULT_GAGGED_MESSAGE,\
                           "bound" : DEFAULT_BOUND_MESSAGE, "tripped" : DEFAULT_TRIPPED_MESSAGE, "unconscious" : DEFAULT_UNCONSCIOUS_MESSAGE])
inherit SKILLS;
//Various Variables - working on consolidating them into mappings - Saide, January 2017
nosave object current_weapon;
string wimpydir;
//almost every pre-existing variable has been rolled into the following mappings - Saide, January 2017
mapping combat_vars, combat_messages, combat_counters;
nosave mapping combat_static_vars, combat_arrays;

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
void send_messages(int magic, object current, string what, int x, object attacker, int fired, string ammo, int cant_shot);
void set_wimpydir(string str);
void set_wimpy(int x);
string query_wimpydir();
int query_wimpy();
int query_wimped();
void set_wimped();
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
protected void internal_execute_attack();  // this is the renamed execute_attack, putting in recursion testing to prevent errors -Ares
mixed return_player_target(int flag); //should return a player target if flag is > roll_dice(1,100) - Saide
object *query_active_protectors(object obj); // different way to do protection

//  This function is used to initialize various variables
void init_attack()
{
    init_complex_body();
    adjust_combat_mapps("arrays", "hunters", ({}));
    adjust_combat_mapps("arrays", "attackers", ({}));
    adjust_combat_mapps("arrays", "atnames", ({}));
    wimpydir = "out";
    adjust_combat_mapps("static vars", "toattack", 4);
    adjust_combat_mapps("static vars", "attack", 0);
    adjust_combat_mapps("vars", "toAttack", -1);
}

int clean_up_attackers() { return COMBAT_D->clean_up_attackers(TO); }
string *query_atnames() { return query_combat_mapps("arrays", "atnames"); }

void set_atnames(string *attNames) { return adjust_combat_mapps("arrays", "atnames", attNames); }
int kill_ob(object victim, int which) { return COMBAT_D->kill_ob(TO, victim, which); }

void resetCombat()
{
    setFuncCast(0);
    setCastFunc(0);
}

void set_attackers(object *what)
{
    adjust_combat_mapps("arrays", "attackers", what);
    adjust_combat_mapps("vars", "any attack", 1);
    return;
}

void set_toattack(int x) { return adjust_combat_mapps("static vars", "toattack", x); }

int ok_to_attack() { return 1; }
int query_initiative() { return random(10); }

void doExp(object who, int how, int split) { return COMBAT_D->doExp(who, how, split); }
varargs int check_death(object pot) { return COMBAT_D->check_death(TO, pot); }
int doPkill() { return COMBAT_D->doPkill(TO); }
void continue_attack() { return COMBAT_D->continue_attack(TO); }
int isPlayerMonster(object ob) { return COMBAT_D->isPlayerMonster(ob); }
int isPkill() { return COMBAT_D->isPkill(TO); }

void setFuncCast(int i) { return adjust_combat_mapps("vars", "funcCast", i); }
void setCastFunc(int i) { return adjust_combat_mapps("vars", "castFunc", i); }
int queryfuncCast() { return query_combat_mapps("vars", "funcCast"); }

int do_i_win() { return 1; }

void counter_attack(object ob) { return COMBAT_D->counter_attack(ob); }
void spring_attack(object ob) { return COMBAT_D->spring_attack(ob); }
int do_casting(object targ) { return COMBAT_D->do_casting(TO, targ); }
mixed return_player_target(int flag) { return COMBAT_D->return_player_target(TO, flag); }
int do_functions() { return COMBAT_D->do_functions(TO); }
void send_debug_crap(object ob, string str)
{
    if (ob->query_property("listen_debug"))
    {
        tell_object(ob, str + "\n");
    }
    return;
}
//neither SHOULD be used - retained by returning 0 in case - Saide, January 2017
varargs int Thaco(int attack_num, object targ, object current, string myclass) { return 0; }
int rangedTouchAC(object targ) { return 0; }
void struck(int damage, object weapon, object attacker, string limb)
{
    int x;
    if(damage > 0)  { x = do_damage(limb, damage); }
    else            { x = 0; }
    if(objectp(attacker)) { attacker->send_messages(0, weapon,limb, x, TO); }
}
void new_struck(int damage, object weapon, object attacker, string limb, object victim, int fired, string ammo, int cant_shot)
{
    return COMBAT_D->new_struck(damage, weapon, attacker, limb, victim, fired, ammo, query_combat_mapps("static vars", "critical hit"), cant_shot);
}

//use /daemon/combat_d.c->calculate_damage(attacker, target, weapon, target_thing, critical hit)
void do_hits(object targ, object current, string target_thing)
{
    return COMBAT_D->calculate_damage(TO, targ, current, target_thing, query_combat_mapps("static vars", "critical hit"));
}

// Will do fumbling
void do_fumble(object current) { return COMBAT_D->fumble(TO, current); }
int reactionAdj(int dex)
{
    if(dex == 10) { return 0; }
    else return (dex - 10) / 2;
}
void prepare_attack() { return adjust_combat_mapps("static vars", "attacking", 0); } //called in battle.c to ensure bugs don't fuck up attacks -Ares
int attack_count() { return query_combat_mapps("static vars", "attack count"); }
void set_for_attack() { return adjust_combat_mapps("static vars", "attacking", 1); }

// renamed the old execute_attack() to internal_execute_attack() down below.  We're going to track
// if execute_attack gets called from inside of do_attack here, and if it does we'll increment
// attack_count.  When the do_attack finishes, it'll set attacking = 0, and if there were any attacks
// that didn't get executed we'll execute them then.  Hopefully this will stop our recursion errors
// on attack from spamming the debug.log -Ares
void execute_attack()
{
    int i;
    if(!query_combat_mapps("static vars", "attacking"))
    {
        if(!query_combat_mapps("static vars", "attack count"))
        {
            internal_execute_attack();
            //call_out("internal_execute_attack",0.500);  // I think this might not work, call outs getting called at the time will fire at the same time.. need to consider a different way
            return;
        }
        for(i=0;i<query_combat_mapps("static vars", "attack count");i++)
        {
            adjust_combat_mapps("static vars", "attack loop", 1);
            //call_out("internal_execute_attack",0.500);
            internal_execute_attack();
        }
        adjust_combat_mapps("static vars", "attack loop", 0);
        adjust_combat_mapps("static vars", "attack count", 0);
    }
    else
    {
        adjust_combat_mapps("static vars", "attack count", 1, 1);
    }
    return;
}   

// this shouldn't get called by anything besides execute_attack.
protected void internal_execute_attack() { return COMBAT_D->internal_execute_attack(TO); }
void stop_hunting()
{
    adjust_combat_mapps("static vars", "hunting", 0);
    adjust_combat_mapps("arrays", "hunters", ({}));
}

void cease_all_attacks()
{
    adjust_combat_mapps("arrays", "attackers", ({}));
    adjust_combat_mapps("arrays", "atnames", ({}));
    adjust_combat_mapps("vars", "any attack", 0);
}
object query_current_attacker()
{
    if(!clean_up_attackers()) return 0;
    else return query_combat_mapps("arrays", "attackers")[0];
}

void run_away() { return COMBAT_D->run_away(TO); }
void set_wimpydir(string str)
{
    if (!stringp(str)) return;
    wimpydir = str;
}
void set_wimpy(int x) { adjust_combat_mapps("vars", "wimpy", x); }
string query_wimpydir() { return wimpydir; }
int query_wimpy() { return query_combat_mapps("vars", "wimpy"); }
void set_wimped(int x) { adjust_combat_mapps("vars", "wimped", x); }
int query_wimped() { return query_combat_mapps("vars", "wimped"); }
void set_casting(int x) { adjust_combat_mapps("static vars", "casting", x); }
int query_casting() { return query_combat_mapps("static vars", "casting"); }
int valid_casting()
{
    if(query_casting() && objectp(TO->query_property("spell_casting"))) return 1;
    return 0;
}

void send_messages(int magic, object current, string what, int x, object attacker, int fired, string ammo, int cant_shot)
{
    return COMBAT_D->send_messages(TO, magic, current, what, x, attacker, fired, ammo, query_combat_mapps("static vars", "critical message"), cant_shot);
}
object *query_hunted() { return query_combat_mapps("arrays", "hunters"); }
object *query_attackers()
{
    if(!sizeof(query_combat_mapps("arrays", "attackers"))) COMBAT_D->clean_attacker_flags(TO);
    return query_combat_mapps("arrays", "attackers");
}
int sight_adjustment() { return COMBAT_D->sight_adjustment(TO); }
void miss(int magic, object target, string type, string target_thing)
{
    return COMBAT_D->miss(TO, magic, target, type, target_thing);
}
int ok_to_kill(object targ) { return COMBAT_D->ok_to_kill(TO, targ); }
int light_armor_filter(object ob) { return COMBAT_D->light_armor_filter(ob); }
void ok_to_wield() { return COMBAT_D->ok_to_wield(TO); }
void add_attacker(object ob) { return COMBAT_D->add_attacker(TO, ob); }
int reaction_adj() { return BONUS_D->query_stat_bonus(TO, "dexterity"); }
void thaco_messages(int thaco) { return COMBAT_D->thaco_message(TO, thaco); }
void remove_attacker(object attack)
{
    if(!objectp(attack)) { return; }
    adjust_combat_mapps("arrays", "attackers", attack, 1);
    adjust_combat_mapps("arrays", "atnames", attack->query_name(), 1);
    adjust_combat_mapps("arrays", "hunters", attack, 1);
    return;
}

void add_hunted(object hunt) { return adjust_combat_mapps("arrays", "hunters", hunt); }
int is_ok_armour(string myclass) { return COMBAT_D->is_ok_armour(TO, myclass); }
int is_ok_weapon(string myclass) { return COMBAT_D->is_ok_weapon(TO, myclass); }
void send_dodge(object att) { return COMBAT_D->send_dodge(TO, att); }

object *query_active_protectors(object obj) { return COMBAT_D->query_active_protectors(obj); }
object *doProtection(object player) { return COMBAT_D->doProtection(player); }

void add_reaction(int x) { return adjust_combat_mapps("vars", "react", x, 1); }
int query_reaction() { return query_combat_mapps("vars", "react"); }
int query_dead() { return query_combat_mapps("static vars", "dead"); }
int queryFuncing() { return query_combat_mapps("static vars", "funcing"); }
void setFuncing(int i) { return adjust_combat_mapps("static vars", "funcing", i); }
int ok_combat_vars() { return COMBAT_D->ok_combat_vars(TO); }
void initialize_combat_vars() { return COMBAT_D->ok_combat_vars(TO); }

void set_paralyzed(int x, string paralyze_msg) { return COMBAT_D->set_paralyzed(TO, x, paralyze_msg); }
void remove_paralyzed() { return COMBAT_D->remove_paralyzed(TO); }
void set_gagged(int x, string message) { return COMBAT_D->set_gagged(TO, x, message); }
void set_bound(int difficulty, string message) { return COMBAT_D->set_bound(TO, difficulty, message); }
varargs void set_temporary_blinded(int difficulty, string message) { return COMBAT_D->set_temporary_blinded(TO, difficulty, message); }
varargs void set_blind(int difficulty, string message)
{
    if(!intp(difficulty)) { return; }
    if(difficulty < 15) { difficulty *= 15; }
    return COMBAT_D->set_temporary_blinded(TO, difficulty, message);
}

varargs void set_blindfolded(int difficulty, string message) { return COMBAT_D->set_blindfolded(TO, difficulty, message); }
varargs void set_tripped(int severity, string message,int special) { return COMBAT_D->set_tripped(TO, severity, message, special); }
void set_unconscious(int xxx, string message) { return COMBAT_D->set_unconscious(TO, xxx, message); }
void set_asleep(int xxx, string message) { return COMBAT_D->set_asleep(TO, xxx, message); }

int query_unconscious() { return (query_combat_mapps("vars", "unconscious") || (query_hp() < 1) || query_combat_mapps("vars", "asleep")); }
int query_asleep() { return query_combat_mapps("vars", "asleep"); }
int query_tripped() { return query_combat_mapps("vars", "tripped"); }
int query_temporary_blinded() { return query_combat_mapps("static_vars", "blinded"); }
int query_blindfolded() { return query_combat_mapps("vars", "blindfolded"); }
int query_blind() { return (query_combat_mapps("static vars", "blinded") + query_combat_mapps("vars", "blindfolded")); }
int query_bound() { return query_combat_mapps("vars", "bound"); }
int query_paralyzed()
{
    if(TO->adminBlock()) { return 1; }
    return (query_combat_mapps("vars", "paralyzed") || query_unconscious());
}
int query_gagged() { return query_combat_mapps("vars", "gagged"); }

string query_gagged_message() { return query_combat_mapps("messages", "gagged"); }
string query_paralyze_message() { return COMBAT_D->query_paralyze_message(TO); }
string query_bound_message() { return query_combat_mapps("messages", "bound"); }
string query_tripped_message() { return query_combat_mapps("messages", "tripped"); }
string query_asleep_message() { return query_combat_mapps("messages", "asleep"); }
string query_unconscious_message() { return query_combat_mapps("messages", "unconscious"); }

int query_deaths_door() { return query_hp() < 1; }

void iterate_combat() { return COMBAT_D->iterate_combat(TO); }
void send_paralyzed_message(string type,object who) { return COMBAT_D->send_paralyzed_message(type, who); }

int reset_hunted() { adjust_combat_mapps("arrays", "hunters", ({})); return 1; }
int remove_hunted(object hunt) { adjust_combat_mapps("arrays", "hunters", hunt, 1); return 1; }

string view_combat_vars()
{
    string str;
    str = "";
    str += "vars"+identify(combat_vars)+"\n";
    str += "msgs"+identify(combat_messages)+"\n";
    str += "counters"+identify(combat_counters)+"\n";
    str += "svars"+identify(combat_static_vars)+"\n";
    return str;
}

int is_in_combat() { return clean_up_attackers(); }

void set_offensive_bonus(int x) { set("offensive",x); }
void add_offensive_bonus(int x) { set("offensive", query("offensive")+x); }
void set_defensive_bonus(int x) { set("defensive",x); }
void add_defensive_bonus(int x) { set("defensive", query("defensive")+x); }
int query_defensive_bonus() { return query("defensive"); }
int query_offensive_bonus() { return query("offensive"); }
void slide_offensive_scale(int x)
{
    add_offensive_bonus(x);
    add_defensive_bonus(-1 * x);
}
void reset_offensive_scale()
{
	set_offensive_bonus(0);
	set_defensive_bonus(0);
}
object set_current_weapon(object ob)
{
    if (!objectp(ob)) ob = 0;
    return current_weapon = ob;
}
object query_current_weapon()
{
    if (!objectp(current_weapon)) return TO;
    return current_weapon;
}
int get_block_chance(object obj)
{
    object shield,*equip;
    int i,chance;
    if(!objectp(obj)) { return 0; }
    if(!living(obj)) { return 0; }
    chance = (int)obj->query_shieldMiss();
    return chance;
}
void reset_critical() { adjust_combat_mapps("static vars", "critical hit", 0); adjust_combat_mapps("static vars", "critical message", 0); }

varargs void adjust_combat_mapps(string type, string which, mixed val, mod)
{
    if(!objectp(TO)) return;
    ok_combat_vars();
    if(!stringp(which)) return;
    if(!stringp(type)) return;
    switch(type)
    {
        case "vars":
            if(!intp(val)) return;
            if(!member_array(which, keys(combat_vars)) == -1) return 0;
            if(!mod) combat_vars[which] = val;
            else
            {
//                if(which == "paralyzed" || which == "tripped") { combat_vars[which] = val; }
// adjustment to make sure shorter tripped/paralyzed settings aren't overwriting pre-existing long ones! N, 4/17.
                if(which == "paralyzed" || which == "tripped") {
                  if(val > combat_vars[which]) combat_vars[which] = val;
                }
                else { combat_vars[which]+= val; }
            }
            break;
        case "static vars":
            if(!intp(val)) return;
            if(!member_array(which, keys(combat_static_vars)) == -1) return 0;
            if(!mod) combat_static_vars[which] = val;
            else combat_static_vars[which]+= val;
            break;
        case "messages":
            if(!member_array(which, keys(combat_messages)) == -1) return 0;
            if(!stringp(val))
            {
                if(DEFAULT_MESSAGES[val]) val = DEFAULT_MESSAGES[val];
            }
            combat_messages[which] = val;
            break;
        case "counters":
            if(!intp(val)) return;
            if(!member_array(which, keys(combat_counters)) == -1) return 0;
            if(!mod) combat_counters[which] = val;
            else combat_counters[which] += val;
            break;
        case "arrays":
            if(!combat_arrays[which] || !pointerp(combat_arrays[which])) return ({});
            if(pointerp(val)) combat_arrays[which] = val;
            else
            {
                if(mod) combat_arrays[which] -= ({val});
                else combat_arrays[which] += ({val});
            }
            combat_arrays[which] -= ({0});
            if(which == "attackers" || which == "hunters")
            {
                combat_arrays[which] = distinct_array(combat_arrays[which]);
            }
            break;
    }
    return;
}

mixed query_combat_mapps(string type, string which)
{
    if(!objectp(TO)) return;
    if(!mapp(combat_vars) || !mapp(combat_static_vars)) { ok_combat_vars(); }
    if(!stringp(type)) return 0;
    if(!stringp(which)) return 0;
    switch(type)
    {
        case "vars":
            if(!member_array(which, keys(combat_vars)) == -1) return 0;
            return combat_vars[which];
            break;
        case "static vars":
            if(!member_array(which, keys(combat_static_vars)) == -1) return 0;
            return combat_static_vars[which];
            break;
        case "messages":
            if(!member_array(which, keys(combat_messages)) == -1) return 0;
            return combat_messages[which];
            break;
        case "counters":
            if(!member_array(which, keys(combat_counters)) == -1) return 0;
            return combat_counters[which];
            break;
        case "arrays":
            if(!combat_arrays[which] || !pointerp(combat_arrays[which])) return ({});
            combat_arrays[which] -= ({});
            return combat_arrays[which];
            break;
    }
    return 0;
}

//Vulnerability for things like sneak attack
int is_vulnerable_to(object source)
{
    object attacker;
    
    if(!source)
        return 0;
    
    if(environment(this_object()) != environment(source))
        return 0;
    
    if(this_object()->query_property("quarry") == source && FEATS_D->is_active(this_object(), "wild hunter"))
        return 0;
    
    if(this_object()->query_paralyzed() || this_object()->query_bound())
        return 1;
    
    if(this_object()->query_blind() && !FEATS_D->usable_feat(this_object(), "blindfight") && !this_object()->true_seeing())
        return 1;
    
    attacker = this_object()->query_current_attacker();
    
    if(attacker && attacker != source)
        return 1;
    
    return 0;
}    
    

mapping query_combat_vars() { return combat_vars; }
mapping query_combat_messages() { return combat_messages; }
mapping query_combat_counters() { return combat_counters; }
mapping query_combat_static_vars() { return combat_static_vars; }
mapping query_combat_arrays() { return combat_arrays; }

void set_combat_vars(mapping val) { if(!mapp(val)) { return; } else return combat_vars = val; }
void set_combat_messages(mapping val) { if(!mapp(val)) { return; } else return combat_messages = val; }
void set_combat_counters(mapping val) { if(!mapp(val)) { return; } else return combat_counters = val; }
void set_combat_static_vars(mapping val) { if(!mapp(val)) { return; } else return combat_static_vars = val; }
void set_combat_arrays(mapping val) { if(!mapp(val)) { return; } else return combat_arrays = val; }
