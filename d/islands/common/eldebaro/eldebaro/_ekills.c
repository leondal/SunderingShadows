//	/cmds/hm/_wizfollow.c
//	from the Nightmare mudlib
//	allows players to follow one another
//	created by Descartes of Borg 15 february 1993
//      modified /cmds/mortal/follow.c by Aragorn 10-21-94 
#include <std.h>

inherit DAEMON;

int cmd_ekills(string str)
{
	mapping tmp;
    string *names, *tmp2 = ({}), highname, midname, lowname;
    int high = 0, mid = 0, low = 0, x;
    tmp = "/d/islands/common/eldebaro/kill_tracker_d.c"->query_eldebaro_killers();
    
    if(!sizeof(keys(tmp))) 
    {
        tell_object(TP, "No one has killed an undead monster on Eldebaro yet.");
    }
   	else
    {
        names = keys(tmp);
        
        tmp2 = ({"%^BOLD%^%^CYAN%^==================================================================\n%^RESET%^"});
        tmp2 += ({arrange_string("%^BOLD%^%^WHITE%^Name", 35) + "%^BOLD%^%^WHITE%^Kills%^RESET%^\n"});
        for(x = 0;x < sizeof(names);x++)
        {
            tmp2 += ({arrange_string(capitalize(names[x]), 35) + "%^BOLD%^%^BLACK%^"+tmp[names[x]]+"\n" });
            if(high < tmp[names[x]])
            {
                if(!midname || mid < high)
                {
                    midname = highname;
                    mid = high;
                    highname = names[x];
                    high = tmp[names[x]];
                }
                else
                {
                    if(mid < tmp[names[x]])
                    {
                        if(!lowname || low < mid)
                        {
                                lowname = midname;
                                low = mid;
                                midname = names[x];
                                mid = tmp[names[x]];
                        }
                        else
                        {
                            if(low < tmp[names[x]])
                            {
                                lowname = names[x];
                                low = tmp[names[x]];
                            }
                    
                        }
                    }
                }
            }
            else if(mid < tmp[names[x]])
            {
                if(!lowname || low < mid)
                {
                    lowname = midname;
                    low = mid;
                    midname = names[x];
                    mid = tmp[names[x]];
                }
                else
                {
                    if(low < tmp[names[x]])
                    {
                        lowname = names[x];
                        low = tmp[names[x]];
                    }
                }
            }
            else if(low < tmp[names[x]])
            {
                lowname = names[x];
                low = tmp[names[x]];                    
            }
            continue;            
        }
        if(stringp(highname))
        {
            tmp2 += ({"1st Place: "+arrange_string(capitalize(highname), 20)+" %^BOLD%^%^RED%^"+high+"\n"});
        }
        if(stringp(midname))
        {
            tmp2 += ({"2nd Place: "+arrange_string(capitalize(midname), 20)+" %^BOLD%^%^RED%^"+mid+"\n"});
        }
        if(stringp(lowname))
        {
            tmp2 += ({"3rd Place: "+arrange_string(capitalize(lowname), 20)+" %^BOLD%^%^RED%^"+low+"\n"});
        }
        if(sizeof(tmp2)) TP->more(tmp2);
        else tell_object(TP, "Something broke with the tmp variable!");        
        
    }
	
	return 1;	
}


void help()
{
    write("Syntax: <wizfollow [name]>\n\
        <wizfollow off>\n\n\
<wizfollow off> allows to stop following a player.\n\
<wizfollow> allows you to follow a player.\n"
);
}
