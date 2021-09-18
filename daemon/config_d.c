//ACTIVELY USED

/*====================================================
  Configuration Daemon - I think we can modify some functions
  so that they can be easily configured. Sort of like global variables
  that determine how things like death work, for example. 
  
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

void check_configuration()
{
    if(!mapp(ACTIVE_CONFIGURATION)) 
    {
        config_load();
    }
    if(!mapp(ACTIVE_CONFIGURATION)) ACTIVE_CONFIGURATION = ([]);
}

int check_config(string which)
{
    if(!stringp(which)) return 0;
    if(!mapp(ACTIVE_CONFIGURATION)) 
    {
        check_configuration();
        if(!mapp(ACTIVE_CONFIGURATION)) return 0;
    }
    if(member_array(which, keys(ACTIVE_CONFIGURATION)) == -1) return 0;
    return ACTIVE_CONFIGURATION[which];
}

void adjust_configuration(object who, string which, int state)
{
    if(!objectp(who)) return;
    if(!stringp(which)) return;
    if(!intp(state)) return;
    if(!member_group(who->query_name(), "superuser")) 
    {
        tell_object(who, "You are unable to adjust configurations for the game. Only superusers are able to do so.\n");
        return;
    }
    if(!mapp(ACTIVE_CONFIGURATION))
    {
        check_configuration();
        if(!mapp(ACTIVE_CONFIGURATION))
        {
            tell_object(who, "Something is wrong with the configuration file. Alert Saide to this message.");
            return;
        }
    }
    if(member_array(which, keys(ACTIVE_CONFIGURATION)) == -1)
    {
        ACTIVE_CONFIGURATION += ([which : state]);
    }
    else
    {
        ACTIVE_CONFIGURATION[which] = state;
    }
    config_save();
    tell_object(who, "The configuration for %^BOLD%^%^RED%^"+which+"%^RESET%^ has been changed "+
    "to %^BOLD%^%^CYAN%^"+state+"%^RESET%^.");
    if(check_config("user notify") == 1 && which != "user notify")
    {
        tell_object(users(), "%^B_CYAN%^%^YELLOW%^Game Configuration for "+which+" has been modified. Please see the "+
        "announcement board for information about what this change means for you.%^RESET%^");
    }
    return;
}