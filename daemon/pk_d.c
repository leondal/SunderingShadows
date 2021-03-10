/*====================================================
  PK Daemon - let's automate most of the stuff related
  to player killing so that players do not need to file paperwork. 
  
  Should hopefully also be able to keep up with way more meaningful 
  information - such as damage caused by particular abilities. 
  
    Who (include witnesses, even NPC's you know might have seen something),
    What (mugging, kill, torture, outcome),
    When (mud time from the 'date' command, time of day IC and weather),
    Where (indoors or outdoors and as specific as meaningful, i.e. weapon shop in
    Shadow), and 
    Why (if you are the victim, this may be just relating what RP you recall that
    might have contributed or simply tell how you know the attacker, or if you even
    know who it was)
    Also include a brief 
    How, including relevant info. such as if you were invisible, they were blind
    the whole time, any special items used or other important details.  Again,
    please be reasonably concise.

see also:  avatarmail
  
=======================================================*/
#include <std.h>
#include <daemons.h>
#include <security.h>

#define CONFIG_FILE "/daemon/save/global_configuration"

mapping ACTIVE_CONFIGURATION;

void config_save()
{
    seteuid(UID_ROOT);
    save_object(CONFIG_FILE);
    seteuid(geteuid());    
}
void config_load()
{
    seteuid(UID_ROOT);
    restore_object(CONFIG_FILE);
    seteuid(geteuid());    
}


void pk_action_result_log()
{
    
}

void pk_action_log(object who, string arg)
{
    if(!objectp(who)) return;
    if(!who->query("pk_log")) return;
    if(!stringp(arg)) return;
    who->set("pk_action", arg);
    return;
}

void pk_log(object attacker, object victim)
{
    if(!objectp(attacker)) return;
    if(!objectp(victim)) return;
    if(attacker->query("pk_log") != victim->query("pk_log"))
    {
        if(attacker->query("pk_log")) 
        {
            save_pk_log(attacker->query("pk_log"));
        }
        if(victim->query("pk_log"))
        {
            save_pk_log(victim->query("pk_log"));
        }
        //attacker->")
    }    
}