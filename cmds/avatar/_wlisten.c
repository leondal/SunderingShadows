#include <std.h>
int help(string str);

int cmd_wlisten(string str)
{   
    string targ, state, *mine;
    object target;
    if(!stringp(str))
    {
        help("");
        return 1;
    }
    if(sscanf(str, "%s %s", targ, state) == 2)
    {
        target = find_player(targ);
        if(!objectp(target)) 
        {
            tell_object(TP, "You cannot find "+targ+" to remotely listen to.");
            return 1;
        }
        if(state != "on" && state != "off" && state != "check")
        {
            help("");
            return 1;
        }
        mine = TP->query("listening_to_whispers");
        if(!pointerp(mine)) mine = ({});
        //mine = filter_array(mine, "is_valid_object", TO);
        if(state == "on")
        {
            if(member_array(targ, mine) != -1)
            {
                tell_object(TP, "You are already listening to "+targ+"'s whispers.");
                return 1;
            }
            mine += ({targ});
            tell_object(TP, "Now attempting to listen to whispers from or to "+targ+".");
            TP->delete("listening_to_whispers");
            TP->set("listening_to_whispers", mine);
            return 1;
        }
        if(state == "off")
        {
            if(member_array(targ, mine) == -1)
            {
                tell_object(TP, "You are not currently listening to "+targ+"'s whispers.");
                return 1;
            }
            mine -= ({targ});
            tell_object(TP, "Now stopping listening to whispers from or to "+targ+".");
            TP->delete("listening_to_whispers");
            if(sizeof(mine)) TP->set("listening_to_whispers", mine);
            return 1;
        }
    }
    
    if(str == "check")
    {
        mine = TP->query("listening_to_whispers");
        if(!pointerp(mine)) mine = ({});
        //mine = filter_array(mine, "is_valid_object", TO);
        if(!sizeof(mine))
        {
            tell_object(TP, "You are currently not listening to any remote whispers.");
            return 1;
        }
        tell_object(TP, "You are currently listening to whispers to or from the following players: ");
        tell_object(TP, implode(mine,"\n"));
        return 1;
    }
    
    
    if(str == "off") 
    {
        tell_object(TP,"No longer listening to whispers.\n");
        TP->delete("listen_to_whispers");
        TP->delete("listening_to_whispers");
        return 1;
    }
    if(str == "on")
    {
        tell_object(TP,"You will now hear all whispers in the room.\n");
        TP->set("listen_to_whispers",1);
        return 1;
    }
    return 0;
}

int help(string str) 
{
    write(
@HELP
Syntax:  wlisten on | wlisten off
         wlisten <player name> on | off
         wlisten check 
         
This toggles on and off listening to all whispers in the room.
It will not use up an eavesdropping slot and will hear all of
the whispers from all of the players without needing to target
anyone.

If you specify a <player name> then it will add them to 
remote whispers that you can hear regardless of where you are. 
Please note that this will not work for listening to whispers from 
other immortals or to other immortals.

wlisten check will show you the remote whispers you are currently listening to.

HELP
);
return 1;
}