#include <std.h>
#include <magic.h>
#include <daemons.h>
#define PK_MINS 2700; //45 minutes in seconds
#define PKLOGHEAD "**************************************************"
inherit OBJECT;

mapping PKILL_LOG;
int cur_act, timer, cur_loc;
string PKOwner;

void create()
{
    ::create();
    set_property("no animate", 1);
    set_property("no drop", 1);
    set_property("soulbound", 1);
    set_property("temporary_item", 1);
    set_id(({"pkill_tracking_object"}));
    PKILL_LOG = (["combatants" : ({}), "actions" : allocate(20), "locations" : allocate(20)]);  
    cur_act = 0;
    cur_loc = 0;
    timer = time() + PK_MINS;
}

void write_out_pk_log()
{
    string msg = "\n", *actions;
    object *locs, *combs;
    int x;    
    if(!objectp(TO)) return;
    if(!stringp(PKOwner)) return;
    actions = PKILL_LOG["actions"];
    actions -= ({0});
    if(sizeof(actions)) msg = "\nLast "+sizeof(actions)+" actions :\n";
    for(x = 0;x < sizeof(actions);x++)
    {
        msg += "\t "+actions[x]+"\n";
        continue;
    }
    locs = PKILL_LOG["locations"];
    locs -= ({0});
    locs = distinct_array(locs);
    if(sizeof(locs)) msg += "Last "+sizeof(locs)+" locations :\n\t " + identify(locs)+"\n";
    msg += PKLOGHEAD+"\n";
    combs = PKILL_LOG["combatants"];
    combs -= ({0});
    combs = distinct_array(combs);
    if(sizeof(combs)) msg += "Current combatants = "+identify(combs) + "\n";
    msg += PKLOGHEAD+"\n";    
    PKILL_LOG["actions"] = allocate(20);
    PKILL_LOG["locations"] = allocate(20);
    PKILL_LOG["combatants"] = combs;
    cur_act = 0;
    cur_loc = 0;
    log_file("pkill/"+PKOwner, msg);
    return;
}

void remove()
{
    string msg;
    if(!objectp(TO)) return;
    write_out_pk_log();
    if(stringp(PKOwner))
    {
        msg = "\n"+PKLOGHEAD+"\n";
        msg += " **PK ENDED**\n";
        msg += PKLOGHEAD+"\n";
        log_file("pkill/"+PKOwner, msg);
    }
    return ::remove();    
}

void log_pkill_input(mixed arg)
{
    if(!objectp(TO)) return;    
    PKILL_LOG["actions"][cur_act] = arg;
    PKILL_LOG["locations"][cur_loc] = EETO;
    if(cur_act < 19) cur_act++;
    if(cur_loc < 19) cur_loc++;
    if(time() > timer) 
    {
        TO->remove();
        return;
    }
    else if(cur_loc >= 19 || cur_act >= 19) write_out_pk_log();
    return;
}

void add_combatants(object attacker, object victim, int attacked)
{
    string msg;
    int joined;
    object *cur_combats;
    if(!objectp(TO)) return;
    if(!objectp(attacker) || !objectp(victim)) return;
    cur_combats = PKILL_LOG["combatants"];
    if(!pointerp(cur_combats)) cur_combats = ({});
    if(member_array(attacker, cur_combats) == -1) { cur_combats += ({attacker});}
    if(member_array(victim, cur_combats) == -1) { cur_combats += ({victim});}
    timer = time() + PK_MINS;
    PKILL_LOG["combatants"] = cur_combats;
    msg = "\n**PK ADDITION**\n";
    if(!attacked) msg += "\t"+attacker->query_true_name() + " was attacked by "+victim->query_true_name()+"!\n";
    else msg += "\t"+attacker->query_true_name() + " attacked "+victim->query_true_name()+"!\n";
    log_file("pkill/"+PKOwner, msg);
    if(cur_loc < 9) cur_loc++;
    PKILL_LOG["locations"][cur_loc] = environment(attacker);
    if(cur_loc >= 9) write_out_pk_log();
    return;  
}

void pkill_start(object attacker, object victim, int attacked)
{
    object PK_OB;
    string msg;
    if(!objectp(TO)) return;
    if(!objectp(attacker) || !objectp(victim)) { TO->remove(); return; }
    if(objectp(PK_OB = present("pkill_tracking_object 2", attacker)))
    {
        if(PK_OB != TO) 
        {            
            PK_OB->add_combatants(attacker, victim, attacked);
            TO->remove();
            return;
        }
    }
    PKILL_LOG["combatants"] += ({attacker, victim});
    PKILL_LOG["locations"][0] = environment(attacker);
    PKOwner = attacker->query_true_name();
    cur_act = 0;
    cur_loc = 0;
    msg = "\n"+PKLOGHEAD+"\n";
    msg += " **PK INITIALIZED** \n";
    if(attacked) { msg += attacker->query_true_name() + " attacked "+victim->query_true_name()+"!\n"; }
    else { msg += attacker->query_true_name() + " was attacked by "+victim->query_true_name()+"!\n"; }
    msg += PKLOGHEAD+"\n";
    log_file("pkill/"+PKOwner, msg);
    timer = time() + PK_MINS;
    return;
}
  