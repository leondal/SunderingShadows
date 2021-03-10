#include <std.h>
#include <daemons.h>

inherit DAEMON;

object current;
int amt, count;

void help();
int do_lp(string str);


int cmd_peer(string str)
{
    int y;
    if (!str)
    {
        help();
        return 1;
    }


    sscanf(str, "%s %d",str,amt);
    if (!str)
    {
        help();
        return 1;
    }
    if(ETP->query_property("peer limit"))
    {
        amt = ETP->query_property("peer limit");
    }
    //above added by Circe to allow limiting of peer on a room level. 12/19/04

    if (TP->query_bound())
    {  // was from peer
    /*       TP->send_paralyzed_message("info",TP);
        return 1;
    changing to allow after a bug report questioning it but limiting to one
    room (they aren't blind but might have limited mobility) *Styx* 11/17/04
    */
        write("Your mobility is limited but you may manage to see a room or two away.");
        amt = 1 + random(2);
    }

    if (!amt || !intp(amt)) amt = 5;
    else if (amt > 20) amt = 20;  // peer was 20 so we'll use that now
    current = ETP;

    if(TP->query_race()=="squole")
        amt = 1;

    y = 1;

    while (amt-- && y != 0)
    {
        y = do_lp(str);
    }
    count = 0;
    amt = 0;
    TO->remove();
    return 1;
}


int do_lp(string str)
{
    string *dirlist, *destlist,*exits,*doors=({});
    string ret, tmp, l;
    string path;
    string *y;
    object who,room, dest;
    int i, x;

    if(!objectp(TP)) return 0;
    if(TP->query_blind())
    {
        tell_object(TP, "You are blind.");
        return 0;
    }

    if((x=TP->light_blind(0)))
    {
        tell_object(TP, TP->light_blind_fail_message(x));
        return 0;
    }

    if(!sizeof(dirlist = (string *)current->query_exits()))
    {
        tell_object(TP, "There appears to be no way out of here.");
        return 0;
    }

    if((i = member_array(str, dirlist)) == -1)
    {
        str = (string)current->query_full_direction(str);
    }

    if(i == -1 && (i=member_array(str,dirlist)) == -1)
    {
        tell_object(TP, "You cannot see far in that direction.");
        return 0;
    }

    if(!objectp(dest = find_object_or_load(current->query_exit(dirlist[i]))))
    {
        tell_object(TP, "You cannot see much in that direction.");
        return 0;
    }

    if( (tmp = (string)current->query_door(dirlist[i])) && !current->query_open(tmp))
    {
        tell_object(TP, "The "+tmp+" blocks your view.");
        return 0;
    }

    if(ETP->query_property("no peer"))
    {
        if(ETP->query_peer_message() == 0)
        {
            tell_object(TP, "You cannot see out of this room.");
            return 0;
        }
        else
        {
            tell_object(TP,""+ETP->query_peer_message()+"");
            return 0;
        }
    }

    if(ETP->is_ship_room())
    {
        dest = present(dest,environment(environment(this_player())));
    }
    /*if (TP->light_blind_remote(0,dest,amt))
    {
        message("my_action",TP->light_blind_fail_message(TP->light_blind_remote(0,dest,amt)),TP);
    } */
    else if(dest->query_property("no peer"))
    {
        if(dest->query_peer_message() == 0)
        {
            tell_object(TP, "You can not see into that room.");
            return 0;
        }
        else
        {
            tell_object(TP,""+dest->query_peer_message()+"");
            return 0;
        }
    }
    else if(TP->query("alternative world") && ALT_WORLD_D->alt_world_border(dest, TP->query("alternative world")))
    {
        ALT_WORLD_D->alt_world_border_messages(TP, dest);
        return 0;
    }
    else
    {
        if(!objectp(dest))
        {
            tell_object(TP,"There is a problem with the room, please notify a wiz.");
            return 0;
        }
        if(!objectp(find_object_or_load(dest)))
        {
            tell_object(TP,"There is a problem with the room, please notify a wiz.");
            return 0;
        }
        catch(dest->set_had_players()); // used to set the clean_up counter on rooms a person peers into
        exits = dest->query_exits();
        for(i=0,sizeof(exits)>0;i<sizeof(exits);i++)
        {
            if(!dest->query_door(exits[i])) { continue; }
            doors += ({ exits[i] });
        }
        for(i=0,sizeof(doors)>0;i<sizeof(doors);i++)
        {
            tmp = dest->query_exit(doors[i]);
            room = find_object_or_load(tmp);
            if(objectp(room)) { room->set_had_players(); }
        }

        count++;

        message("room_description", (string)dest->query_short(0) + "%^RESET%^ - %^MAGENTA%^"+count+"%^RESET%^" || "Unknown" ,this_player());
        message("room_exits", (string)dest->query_short_exits(), this_player());
        message("room_effects", (string)dest->query_effects(), this_player());
        message("Nliving_item", (string)dest->describe_living_contents(({})), this_player());
        message("Ninanimate_item", (string)dest->describe_item_contents(({})), this_player());
    }
/*
    message("other_action", this_player()->query_cap_name()+
      " peers "+dirlist[i]+".", current, ({this_player()}));
*/
    current = dest;
    return 1;
}


void help()
{
    write("
%^CYAN%^NAME%^RESET%^

peer - peer through multiple rooms

%^CYAN%^SYNOPSIS%^RESET%^

peer %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^ [%^ULINE%^%^ORANGE%^DISTANCE%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

This command will allow you to peer into %^ORANGE%^%^ULINE%^DIRECTION%^RESET%^, showing you brief description of %^ORANGE%^%^ULINE%^DISTANCE%^RESET%^ rooms. You will see entities that are in these rooms, and short descriptions of these rooms. The %^ORANGE%^%^ULINE%^DISTANCE%^RESET%^ defaults at 5 and is set to be maximum of 20.

%^CYAN%^SEE ALSO%^RESET%^

look, glance, brief, mmap
");
}
