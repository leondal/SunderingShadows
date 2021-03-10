/*Unique Item Daemon - Saide, November 2017
 
Simple Premise - when an item has init called on it check if it's unique

If not then do nothing. 

If So - check held copies/saved copies. 

        Saved copies = file_names and time - if file name no longer exists or time > remove
        Held copies are copies currently in a players inventory - is the player still holding it? in inventory or container? If so, count it as a unique item. If not, do not count it. 
        (this means that if for some reason bob drops an item, then Fred could pick it up somewhere else to gain possession - I don't think this is much of an issue)
        
If there are free copies of the item left then register it as held 

        On save - register it as saved - with a file name and time for this to expire (2 weeks RL time)
        
        On Load - check if it's registered, if so remove it as a saved copy and convert to a held copy. 
        
*/
#include <std.h>
#include <security.h>

// DEBUG mode enabled on 1, 0 is off.  Make sure and set DEBUGGER
// to yourself if you are testing this.

#define LEASE_DELAY 1209600 //how long before a file saved to disk is cleared
#define TEMP_LEASE_DELAY 3600 //how long before an item with a still valid registered enviroment goes before it is cleared
#define DEBUG 1
#define DEBUGGER "thorn"

#define SAVE_FILE "/daemon/save/unique_items"

// The default lease period is 15 days
#define DEFAULT_LEASE 1296000
#define OWNER 0
#define LEASE_END 1
#define EMPTY_LEASE ({ "no owner", 0 })

#define RQCN capitalize(requestor->query_name())

inherit DAEMON;

mapping item_data;

mixed check_unique(object ob);

void create() 
{
    ::create();
    item_data = ([]);
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_FILE);
    seteuid(getuid());
}

void SAVE() 
{
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_FILE);
    seteuid(getuid());
}

int can_posses(string file, int amt)
{
    return 0;
}

mixed check_unique(object ob)
{
    if(!objectp(ob) || living(ob)) return ob;
    if(!ob->query_unique()) return ob;
    if(!objectp(environment(ob))) return ob;
    if(!environment(ob)->is_player()) 
    {   
        if(!objectp(environment(environment(ob)))) return ob;
        if(!environment(environment(ob))->is_player()) return ob;
    }
    if(!can_posses(base_name(ob), ob->query_unique()))
    {
        tell_object(environment(ob), ob->QCN+"%^BOLD%^%^WHITE%^ simply fades from existence!%^RESET%^");
        ob->remove();
        return;
    }
        
        
}
