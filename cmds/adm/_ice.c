/*================================
New command that utilities a daemon
to remove inactive characters, characters by IP address, 
and characters by email - Saide, December 2016

Inactive character wipes will include those in dontrid.h
high mortal characters, or characters that are associated with 
high mortal accounts

the inactive portion of the command requires a player position 
also, which will behave differently depending on the position
"newbie" will just remove everything - base clean up 
"player" will move the player files to the /adm/save/users/rid folder 
(in case they should later need to be restored)

any immortal position will do a standard rid cleanup 
but will move the file to do /adm/save/users/icedimmortals
these include avatar, creator, builder, apprentice, developer, and overseer ranks
by default anyone above this rank - IE super user or law will not be included

this will display no messages to anyone on the game

the ip and email versions of the command function differently
when used this way it is assumed that the person using said 
ip address or email address did something drastic to warrant 
being rid - this will wipe out their existence - as if they were rid
and will query quiet rid to see if the RID messages should be delivered or 
not

because of using the daemon - most of the code
can be found in /cmds/adm/iceobject.c - 
some information will be set up based on the 
way that the command is used and then will receive a list of 
names from the daemon to remove as per the 
behavior defined above. 
=================================*/
#include <std.h>
#include <security.h>

inherit DAEMON;

int help();

int cmd_ice(string str)
{
    object iceOB;
    string pos, llev, hlev, days, type, arg, extra_arg;
    
    if(!objectp(TP)) return 0;
    if(!member_group((string)TP->query_true_name(), "law")) return 0;
    if(!str) return help();
   
    if(sscanf(str, "by rank %s between %s-%s | %s", pos, llev, hlev, days) == 4)
    {
        if(sscanf(days, "%s as list", days) == 1) extra_arg = "list";
        iceOB = new("/cmds/adm/iceobject");
        iceOB->set_ice_type("level");
        iceOB->set_ice_position(pos);
        iceOB->set_ice_owner(TP);
        iceOB->move(TP);
        if(!("/adm/daemon/inactive_users_d.c"->ice_users(TP, pos, "level", to_int(days), to_int(llev), to_int(hlev), 0, 0, iceOB, extra_arg)))
        {
            if(objectp(iceOB)) iceOB->remove();
            tell_object(TP, "Something went wrong.");
            return 1;
        }
        return 1;
    }
    if(sscanf(str, "by %s | %s", type, arg) == 2)
    {
        if(sscanf(arg, "%s as list", arg) == 1) extra_arg = "list";
        if(type != "email" && type != "ip")
        {
            tell_object(TP, "Valid types are email and ip. Syntax example ice by email | email@gmail.com");
            return 1;
        }
        iceOB = new("/cmds/adm/iceobject");
        iceOB->set_ice_type(type);
        iceOB->set_ice_owner(TP);
        iceOB->move(TP);
        switch(type)
        {
            case "email":
                if(!("/adm/daemon/inactive_users_d.c"->ice_users(TP, pos, type, 0, 0, 0, 0, arg, iceOB, extra_arg)))
                {
                    if(objectp(iceOB)) iceOB->remove();
                    tell_object(TP, "Something went wrong.");
                    return 1;
                }
                break;
            case "ip":
                if(!("/adm/daemon/inactive_users_d.c"->ice_users(TP, pos, type, 0, 0, 0, arg, 0, iceOB, extra_arg)))
                {
                    if(objectp(iceOB)) iceOB->remove();
                    tell_object(TP, "Something went wrong.");
                    return 1;
                }
                break;
        }
        return 1;
    }
    help();
    return 1;
}

int help()
{
   write(
@HELP
   Usage: ice by rank <position> between lowlevel-highlevel | days inactive
          example : ice by rank builder between 1-600 | 200
          ice by email | email@address
          example : ice by email | arnvorax@gmail.com
          ice by ip | ip address
          example : ice by ip | 127.0.0.1
          

   This command is used to delete/rid characters. 
   It uses a daemon and an object working together. 
   The daemon will build a list by the entered criteria and then pass the 
   list back to the object. 
   The object will be setup depending on the way that the command is issued. 
   
   For ice by rank <position> between low-level-highlevel | days inactive   
HELP
   );
   
write(
@HELP
   The daemon will not include anyone listed in 
   /adm/include/dontrid.h, 
   high mortals
   or anyone with a high mortal on their account. 
   
   position will determine the specifics of what the object
   does to the users on the list. 
   
   For position = newbie - the character will be completely 
   deleted, as if they were rid, with no backup of the 
   character file. 
   
   For position = player the character will be completely 
   deleted, as if they were rid, but with a backup 
   stored at /adm/save/users/rid/ 
   (of the player file only) in the event of 
   them needing to be restored later. 
   
   For any immortal position - the character file will 
   be moved to /adm/save/users/icedimmortals/
   /realms directories will not be touched, 
   but everything else cleaned when a player is 
   normally rid will be. 
   
   No rid messages will be displayed for any of 
   the rids completed this way. In order 
   to avoid spamming players with general cleanup. 
HELP
   );

write(
@HELP
   For ice by ip | ip address OR
   ice by email | email address
    
   any characters, except for law, or superusers 
   will be completely rid - as if the rid command 
   were used on them. This will query quiet rid 
   to determine if rid messages should be
   delivered or not. 
    
   NOTE: This command will take awhile, the 
   daemon takes awhile to build the list and 
   the object that the command interfaces with
   will go through a maximum of 50 users at a
   time, in order to minimize any associated lag. 
   
   NOTE: You may tack 'as list' on to the end of 
   any method of using the command in order to 
   create only a list of who would have been
   iced had the command been used regularly.
HELP
   );
   return 1;      
}
