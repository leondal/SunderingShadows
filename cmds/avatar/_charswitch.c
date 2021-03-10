#include <std.h>
#include <security.h>
#include <objects.h>

inherit DAEMON;

int help();
int cmd_charswitch(string str)
{
    object user, ob, location;

    string posxxx; 
    if(!objectp(TP)) { return 0; }
    posxxx = lower_case((string)TP->query_position());
    if(posxxx == "builder" || posxxx == "apprentice")
    {
        tell_object(TP,"You cannot use this command as a builder or apprentice.");
        return 1;
    }

    if (!stringp(str)) 
    {
        return help();
    }
    if(!user_exists(str))
    {
        return notify_fail("The user "+capitalize(str)+" does not exist!\n");
    }

    if (objectp(ob = find_player(str)) && interactive(ob)) 
    {
        tell_object(TP,"That player is currently logged in and active");
        return 1;
    }
    if (!file_exists("/avatar/"+TPQN+"/"+str+".o"))
    {
        write("I think... not.");
        if(archp(TP))
        {
            write("This has been disabled for arches by Saide, there are "+
            "other ways to access an account if it's warranted. Use them.");
        }
        return 1;
    }
    location=ETP;
    user=new (OB_USER);
    ob=TP;
  
    seteuid(UID_ROOT);
    master()->load_player_from_file(str,user);
    seteuid(getuid());

    user->move("/d/dagger/avalounge");

    seteuid(UID_EXEC);
    tell_object(TP,"Good luck");
    exec(user,TP);
    seteuid(getuid());
  
    if (!interactive(user)) 
    {
        tell_object(TP,"The transition failed for some reason. The user was found but not loaded. Ensure that the Object wasn't already loaded.");

        seteuid(UID_ROOT);
        user->remove();
        seteuid(getuid());

        return 1;
    }

    seteuid(UID_ROOT);
    user->set_name(str);
    seteuid(getuid());
  
    user->setup();
    user->set_property("switched from",ob);
    user->set_property("switch location",location);
    user->move(location);
    ob->move("/d/dagger/ava_cold_storage");
    tell_object(user,"You are now "+capitalize(user->query_name())+".");
  
    return 1;
}

int help() {
  write(
@GARRETT
%^BLUE%^charswitch%^RESET%^ is a command that allows you to switch into another one of your NPC personas.  
If it is successful, it moves the NPC character to where you issued the command, and the old character is placed somewhere safe.
If it fails, it will give you a reason why. (Usually invalid user, you don't have permission to switch into that person, or they happen to be logged in.)

After you have issued this command, it waits for you to type %^RED%^switchback%^RESET%^,
which will place you back into your former body.  If, however, you
type %^RED%^switchback%^RESET%^ with something AFTER it, (any text will do, the code is
not picky at this point) then your primary avatar will be placed 
back where you originally used the %^BLUE%^charswitch%^RESET%^  command.  Otherwise,
you will be left where you typed %^RED%^switchback%^RED%^.

GARRETT
    );
   return 1;
}
