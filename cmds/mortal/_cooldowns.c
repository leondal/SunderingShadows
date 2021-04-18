/*
  cooldowns.c
  
  Shows your current cooldowns and time left.
  
  -- Tlaloc --
*/

#include <std.h>
#include <daemons.h>

//#define LINE sprintf("%s[ Cooldowns ]%s\n", "*=*=*=*=*=*", "*=*=*=*=*=*")
#define LINE "%^BOLD%^===========[ %^CYAN%^Cooldowns%^WHITE%^ ]===========%^RESET%^\n"

inherit DAEMON;

mixed cmd_cooldowns(string args)
{
    object who = this_player();
    mapping cooldowns;
    string *keys;
    int width;
    
    cooldowns = who->query_cooldowns();
    keys = keys(cooldowns);
    
    write("\n");
    write(LINE);
    
    if(sizeof(keys))
    {
        foreach(string str in keys)
        {
            tell_object(who, sprintf("   %-13s : %6ds\n",capitalize(str), (cooldowns[str] - time())));
        }
    }
    else
        write("               %^BOLD%^None%^RESET%^\n");
    
    write(LINE);
    return 1;
}
    
    
    