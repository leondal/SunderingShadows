//      /bin/user/_biography.c
//      from the Nightmare mudlib
//      gives a player's biography
//      created by Descartes of Borg 30 march 1993

#include <daemons.h>
#include <clock.h>
#include <std.h>
#define SHOW_KILL (string)PLAYER_D->query_monster
#define VALID_ARGS ({"deaths", "kills", "quests"})
inherit DAEMON;

string safe_cap(string str)
{
    if(stringp(str)) return capitalize(str);
    else return capitalize(identify(str));
}

int check_permission(object ob,object player)
{
    string pos,name;
    if(!objectp(player)) { return 1; }
    name = (string)ob->query_true_name();
    pos = lower_case((string)player->query_position());
    if(pos == "builder" || pos == "apprentice")
    {
        if(lower_case(name) != lower_case((string)player->query_true_name()))
        {
            tell_object(player,"You can only use this on yourself.");
            return 0;
        }
    }
    return 1;
}

int display_kills(string who)
{
    string *kills,*display=({});
    object ob;
    int x, amt,num,num2;

    if(!who)
        ob=this_player();
    else
    {
        if(!wizardp(this_player())) ob = TP;
        if(!ob=find_player(who))
            return notify_fail("No such person!\n");
    }
    kills = ob->query_kills();
    if(!amt=sizeof(kills))
    {
        tell_object(ob, "You haven't killed anything yet!\n");
        return 1;
    }
    for(x=0;x<amt;)
    {
        if(x+2 < amt)
        {
            display += ({ "%^BOLD%^%^RED%^"+arrange_string(SHOW_KILL(kills[x]),26)+""+arrange_string(SHOW_KILL(kills[x+1]),26)+""+arrange_string(SHOW_KILL(kills[x+2]),22)+""});
            x += 3;
        }
        else if(x+1 < amt && x+2 > amt)
        {
            display += ({"%^BOLD%^%^RED%^"+arrange_string(SHOW_KILL(kills[x]),26)+""+arrange_string(SHOW_KILL(kills[x+1]),26)+""});
            x += 2;
        }
        else if(x+1 > amt)
        {
            display += ({"%^BOLD%^%^RED%^"+arrange_string(SHOW_KILL(kills[x]),26)+""});
            x++;
        }
        else { x++; }
    }
    tell_object(TP, sprintf("%%^BOLD%%^%%^GREEN%%^You have killed %%^WHITE%%^%d %%^GREEN%%^monsters.",amt),);
    TP->more(display);
    return 1;
}


int display_deaths(string str)
{
    int i, max, flag;
    mixed *deaths;
    string borg, tmp;
    object ob;

    if(!objectp(TP)) return "";
    if(objectp(ob = find_player(str))) { deaths = (mixed *) ob->query_deaths(); flag = 1; }
    else deaths = (mixed *) TP->query_deaths();

    if(!(deaths) || !(max = sizeof(deaths)))
    {
        if(!flag) borg = "\n%^CYAN%^You have never experienced the pain of death.\n\n";
        else borg = "\n%^CYAN%^"+capitalize(str)+" has never experienced the pain of death.\n\n";
    }
    else
    {
        if(!flag) borg = "%^BOLD%^%^GREEN%^You have died %^RESET%^%^BOLD%^"+max+" %^GREEN%^times.\n";
        else borg = "%^BOLD%^%^GREEN%^"+capitalize(str)+" has died %^RESET%^%^BOLD%^"+max+"%^GREEN%^ times.\n";
        borg += "You have been brought into the grasp of death by:\n";
        borg += sprintf("%-20s%-24s%-26s\n","Enemy","IC Date","RL DateTime");
        write(borg);
        borg = "";

        for(i=0; i<max; i++)
        {
            borg += "%^BOLD%^%^RED%^"+arrange_string(safe_cap(deaths[i][0]), 20);
            tmp = "%^MAGENTA%^"+date(deaths[i][1])+" "+month(deaths[i][1])+
              " "+year(deaths[i][1])+" SG";
            borg += arrange_string(tmp, 24);
            borg += arrange_string(ctime(deaths[i][1]),26);
            write(borg);
            borg = "";
        }
    }
    this_player()->more(explode(borg, "\n"));
    return 1;
}

int display_quests(string mtarg, string str)
{
    object targ;
    string *quests, borg, tmp;
    mapping minis;
    int i;
    if(mtarg && avatarp(TP))
    {
        if(!(mtarg = find_player(str)) || targ->query_highest_level() > TP->query_highest_level())
        {
            tell_object(TP, "That person is not online.\n");
            return 1;
        }
    }
    else { targ = TP; }
    if(targ == TP && !avatarp(TP) && strsrch(str, "request") != -1)
    {
        tell_object(TP,"%^BOLD%^Find a gnome and look at his wagon.%^RESET%^");
        return 1;
    }
    if(!check_permission(targ,TP)) { return 1; }
    if(targ == TP) { tmp = "You have"; }
    else { tmp = capitalize(targ->query_name()) + " has"; }
    borg = "%^YELLOW%^" + (string)targ->query_short()+"\n\n";
    minis = (mapping)targ->query_mini_quest_map();
    if(!sizeof(minis))
        borg += "%^CYAN%^" + tmp+" no meaningful accomplishments.\n";
    else
    {
        string mquest, qname;
        borg += "%^CYAN%^" + tmp + " been rewarded for the following great deeds:\n";

        foreach(mquest in keys(minis))
        {
            qname = minis[mquest][1];
            if (!stringp(qname))
                qname = "%^BLUE%^"+mquest+"%^RESET%^";
            borg += "%^RED%^"+sprintf("%2d",date(minis[mquest][0]))+" "+sprintf("%.3s",month(minis[mquest][0]))+" "+year(minis[mquest][0])+" SG: %^RESET%^"+qname+"\n";
        }
        borg += "\n";
    }
    if(!sizeof(quests = targ->query_quests())) borg += "%^CYAN%^" + tmp + " not completed any quests.\n";
    else
    {
        borg += "%^CYAN%^" + tmp+ " completed the following quests:\n";
        i = sizeof(quests);
        while(i--) { borg += sprintf("%-16s\n",quests[i]); }
        borg += "\n%^YELLOW%^";
    }
    TP->more(explode(borg, "\n"));
    return 1;
}



int cmd_biography(string str)
{
    int birth, birth2, byear;
    mixed *oh;
    string borg, tmp, arg, target;
    if(stringp(str))
    {
        sscanf(str, "%s %s", arg, str);
        if(stringp(arg))
        {
            if(user_exists(arg) && avatarp(TP))
            {
                target = arg;
                arg = str;
            }
        }
        else arg = str;
    }
    if(!stringp(str) || member_array(arg, VALID_ARGS) == -1)
    {
        borg = "%^RESET%^%^BLUE%^-=%^BOLD%^< %^GREEN%^" + (string)this_player()->query_short() +" %^BLUE%^>%^RESET%^%^BLUE%^=-";
        birth = (int)TP->query_birthday();
        birth2 = birth - (int)TP->query_start_age() * YEAR;
        byear = year(birth2);
        borg += "\n%^RESET%^%^CYAN%^You were born %^MAGENTA%^"+day(birth)+",%^GREEN%^ "+date(birth)+" %^MAGENTA%^"+month(birth)+
           " %^GREEN%^"+(byear ? (byear<0 ? (-byear)+" %^MAGENTA%^SG.\n" : byear+" %^MAGENTA%^SG.\n") : " of the null year.\n");
        borg += "%^RESET%^%^CYAN%^Character created on "+ctime(TP->query_birthday())+".\n";
        if(!(oh = (mixed *)this_player()->query_current_marriage()))
            borg += "%^CYAN%^You are currently single.\n";
        else if(!oh[1])
            borg += "%^CYAN%^You married %^GREEN%^"+capitalize(oh[0])+"%^CYAN%^ on a forgotten date.\n";
        else
            borg += "%^CYAN%^You married %^GREEN%^"+capitalize(oh[0])+"%^CYAN%^ on "+month(oh[1])+" "+
            date(oh[1])+", "+year(oh[1])+".\n";

        borg += "\n%^MAGENTA%^You have brought %^BOLD%^%^CYAN%^"+sizeof(TP->query_kills())+"%^RESET%^%^MAGENTA%^ creatures to their deaths.%^RESET%^\n";
        borg += "%^MAGENTA%^You have accomplished %^BOLD%^%^CYAN%^"+sizeof(TP->query_mini_quests())+"%^RESET%^%^MAGENTA%^ deeds.%^RESET%^\n";
        borg += "%^MAGENTA%^You have completed %^BOLD%^%^CYAN%^"+sizeof(TP->query_quests())+"%^RESET%^%^MAGENTA%^ quests.%^RESET%^\n";
        borg += "%^MAGENTA%^You have %^BOLD%^CYAN%^"+TP->query_quest_points()+"%^RESET%^MAGENTA%^ quest points.%^RESET%^\n";
        borg += "%^MAGENTA%^You have entered the realm of death %^BOLD%^%^CYAN%^"+sizeof(TP->query_deaths())+"%^RESET%^%^MAGENTA%^ times.%^RESET%^\n";
        this_player()->more(explode(borg, "\n"));
        return 1;
    }
    if(arg == "kills") { display_kills(target); }
    else if(arg == "quests") { display_quests(target, str); }
    else if(arg == "deaths") { display_deaths(target); }
    return 1;
}

int help() {
   write(
"
%^CYAN%^NAME%^RESET%^

biography - display your life

%^CYAN%^SYNOPSIS%^RESET%^

biography [kills|deaths|quests]

%^CYAN%^DESCRIPTION%^RESET%^

Without an argument briefly displays some numeric data about your character.

There are optional arguments:

%^ORANGE%^<biography kills>%^RESET%^

    Will display names of entities you have ended.

%^ORANGE%^<biography death>%^RESET%^

    Will display names of entities that have ended you.

%^ORANGE%^<biography quests>%^RESET%^

    Will show you quests you have completed.

%^CYAN%^SEE ALSO%^RESET%^

score, finger, flag, set
"
   );
   return 1;
}
