#include <std.h>

inherit DAEMON;
int do_remove(string str, object who);
int help();

mixed MakeTimeDisplay(int MyTime)
{
    string MyHour, MyMin, MySec;
    MyTime;
    MyHour = ""+ MyTime / 3600;
    MyTime -=  (to_int(MyHour) * 3600);
    if(strlen(MyHour) < 2) MyHour = "0"+MyHour;
    MyMin = ""+(MyTime / 60);
    if(strlen(MyMin) < 2) MyMin = "0"+MyMin;
    MyTime -= (to_int(MyMin) * 60);
    MySec = ""+(MyTime / 1);
    if(strlen(MySec) < 2) MySec = "0"+MySec;
    return MyHour +":"+ MyMin +"."+MySec;
} 

int cmd_tax(string str)
{
    object who;
    int amount, duration, arguments, taxno, i;
    string type, name, holder,*args;
    mapping taxes, types;

    taxes = ([]); 
    if (!str)
    {
        help();
        return 1;
    } 

    args = explode(str," ");
    name=args[0];
    who = find_player(name);
    if (!objectp(who))
    {
        notify_fail(name + " is not online.\n");
        return 0;
    }

    taxes = who->query_XP_tax(); 

    arguments = sscanf (str, "%s %s", name, holder);

//  tell_player(TP, "Arguments found: "+arguments);

    if (arguments < 2)
    {  
        tell_object(TP, "%^BOLD%^%^BLUE%^Tax type\tAmount\tDuration%^RESET%^");
        types = (mapping)taxes["timed"];
        if(mapp(types)) 
        {
            tell_object(TP, "Timed\t\t" + types["percent"] + "\t" + 
            MakeTimeDisplay(types["fall off"]) + " left.");
        }
        types = (mapping)taxes["death"];
        if(mapp(types))
        {
            tell_object(TP, "Death\t\t "+ types["percent"] + "\t" +
            MakeTimeDisplay(types["fall off"]) + " left.");
        }
        types = (mapping)taxes["improvement"];
        if(mapp(types))
        {
            tell_object(TP, "Improvement\t "+types["amount"]);
        }
        who->delete("autotax");
        //tell_object(TP,"autotax\t"+who->query("autotax") + "\t" + "ptime linked");
        return 1;
    }

    if (args[1] == "remove")
    {
        return do_remove("all", who);
    }
    arguments = sscanf(holder,"%d %d", amount, duration);
    if (arguments < 2 )
    {
        help();
        return 1;
    }
    tell_object(TP, "About to set xp tax on " + name);
    who->set_XP_tax(amount, duration);
    tell_object(TP, "Finished setting xp tax on " + name);
    return 1;
}

int do_remove(string str, object who)
{
    string name;
//  string name, type;
//  int arguments;
//  arguments = sscanf(str,"%s, %s",name, type); 

   if (!stringp(str))
   { 
        help();
        return 1;
    }
    switch(str)
    {
        case "all":
            break;
        case "level":
            break;
        case "general":
            break;
        case "metered":
            break;
        default:
            help();
            return 1;
    }
//  who=find_player(name);

    if (objectp(who))
    {
        name=who->query_true_name();
        write("About to clear tax ("+str+") on player: "+name+".\n");
        who->remove_XP_tax(str);
        write("Tax removal complete.");
        return 1;
    } 
    else 
    {
        write("No such player found online: "+name+".\n");
        return 1;
    }
}

int help()
{
   write(
@OLI
   Tax   
          Usage: tax <player>
                 tax <player> <amount> <duration>
                 tax <player> remove
          
   tax <player> 

   With no arguments, this will return a list of all current xp taxes
   applied to the player.
   
   tax <player> <amount> <duration>
  
   This will apply a tax in the <amount> for <duration>. This will 
   auto count down while the player is online. A duration of -1 will apply
   a permenant tax until removed.
   
   %^BOLD%^%^RED%^In the vast Majority of cases this should be used to reward RP.%^RESET%^
   
   A %^BOLD%^%^CYAN%^negative%^RESET%^ number should be used to %^BOLD%^%^CYAN%^reward%^RESET%^. 
   A %^BOLD%^%^RED%^positive%^RESET%^ number can be a %^BOLD%^%^RED%^penalty%^RESET%^. 
   
   A player who has a tax of 40 will lose 40% of any xp they earn.
   A player who has a tax of -40(a negative tax) will gain a bonus of 40%
   on top of any xp they earn.
OLI
    );
    
write(
@LUJKE
   %^BOLD%^%^RED%^ NOTE: Other than in exceptional circumstances, level taxes
    %^BOLD%^%^RED%^       should be not be set lower than -100 or greater than 60.%^RESET%^
    
    tax <player> remove - removes all timed xp taxes from <player>.
LUJKE
    );
    return 1;
}
