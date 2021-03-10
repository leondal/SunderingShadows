#include <std.h>
#include <daemons.h>
#include <objects.h>
#include <security.h>

#define HYBRID ({"psywarrior","druid","bard","warlock"})
inherit DAEMON;

void cmd_snipe(string str)
{
    object vic, *usrs;
    if(!objectp(TP)) return;
    if(!stringp(str))
    {
        tell_object(TP, "Who do you want to make into a bloody mess?");
        return 1;
    }
    if(!objectp(vic = find_player(str)))
    {
        tell_object(TP, "It would appear that "+str+" is beyond the range of your scope.");
        return 1;
    }
    
    usrs = users();
    usrs -= ({vic});
    message("info", "%^BOLD%^%^RED%^Suddenly.... you see a red dot on "+vic->QCN+"'s "+
    "forehead..\n\n%^BOLD%^%^GREEN%^You hear the insane laughter of a Troll???", usrs);
    
    message("info", vic->QCN+"%^RESET%^%^RED%^'s head is suddenly a mist of "+
    "%^BOLD%^'RED'%^RESET%^%^RED%^!\n\n%^BOLD%^%^GREEN%^A gruff troll says:%^RESET%^ That's one more headshot!", usrs);
    
    tell_object(vic, "%^BOLD%^%^RED%^You feel your head warming up rapidly.... and then "+
    "everything goes %^BOLD%^%^BLACK%^black%^BOLD%^%^RED%^...%^RESET%^");
    
    if(objectp(vic)) 
    {
        if(!vic->query_killable()) 
        {
            vic->set_killable(1);
            vic->die();
            vic->set_killable(0);
        }
        else vic->die();    
    }
    return 1;
}