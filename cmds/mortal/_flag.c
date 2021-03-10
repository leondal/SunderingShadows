/*=====================================================
flag command
    supports turning off exp - flag noexp - gain no exp at all
    supports modifying character improvement tax percent - flag ctp % flag ctp 100
    supports setting up a RPFlag for current environment that will remain as long as
    players are still there - flag rpflag
    rpflag will show up on rumors/a short description of the room on the who list
    pkflag
=====================================================*/
#include <daemons.h>
#include <std.h>
#include <security.h>

/**
 * @file
 */


#define SUPPORTEDFLAGS ({"roleplay flag", "player kill", "scaled level"})
inherit DAEMON;
void help();

varargs void do_flag_display(object who, object targ)
{
    int x, j, remaining;
    string *activeEvents, eventName, notification, eventMsg, *featureVoting, featureName;
    string yesVotes = "", noVotes = "", featureAuthor, ExpiresIn, ETA;

    if(!objectp(who)) return notify_fail("Something went wrong...");
    if(!objectp(targ) || !avatarp(targ)) targ = who;
    if(objectp(targ) && avatarp(targ) && targ != who)
    {
        tell_object(targ, "Flags for "+who->query_cap_name()+" as followed:\n");
    }
    tell_object(targ, "%^RESET%^--=%^BOLD%^< %^CYAN%^Flags%^WHITE%^ >%^RESET%^=--");
    for(x = 0;x < sizeof(SUPPORTEDFLAGS);x++)
    {
        j = 14 - strlen(SUPPORTEDFLAGS[x]);
        tell_object(targ, "%^BOLD%^%^WHITE%^"+capitalize(SUPPORTEDFLAGS[x]) + arrange_string(" ", j)+ "%^RESET%^"+ USER_D->get_flag(who, SUPPORTEDFLAGS[x]));
        continue;
    }
    if(pointerp(activeEvents = WORLD_EVENTS_D->parsable_world_events(who)))
    {
        tell_object(targ, "\n--=%^BOLD%^< %^CYAN%^Active world events%^WHITE%^ >%^RESET%^=--");

        for(x = 0;x < sizeof(activeEvents);x++)
        {
            eventName = activeEvents[x];
            j = 34 - strlen(eventName);
            if(!stringp(notification = WORLD_EVENTS_D->query_event_notification(eventName))) { notification = "Currently Active"; }
            if(!intp(remaining = WORLD_EVENTS_D->event_time_remaining(eventName))) { remaining = -1; }
            eventMsg = "%^BOLD%^%^WHITE%^"+eventName + arrange_string(" ", j);
            j = 18 - strlen(parse_time(remaining));//strlen(remaining + " mins");
            eventMsg += parse_time(remaining) + arrange_string(" ", j) + notification;
            tell_object(targ, eventMsg);
        }
    }
    if(pointerp(featureVoting = FEATURE_D->parsable_features(who)) && sizeof(featureVoting))
    {
        tell_object(targ, "\n%^BOLD%^%^CYAN%^Current features being voted on:%^RESET%^");
        tell_object(targ, "\n"+arrange_string("%^BOLD%^%^WHITE%^Feature Name ", 20) + arrange_string("Author", 10) + arrange_string("Yes", 4) + arrange_string("No", 4) + arrange_string("ETA", 10) + arrange_string("Expires In", 10)+"\n");
        for(x = 0;x < sizeof(featureVoting);x++)
        {
            featureName = featureVoting[x];
            j = 20 - strlen(featureName);
            eventMsg = "%^BOLD%^%^WHITE%^"+featureName + arrange_string(" ", j);
            featureAuthor = FEATURE_D->get_feature_information(featureName, "Feature Author");
            j = 10 - strlen(featureAuthor);
            eventMsg += featureAuthor + arrange_string(" ", j);
            yesVotes = "";
            yesVotes += FEATURE_D->get_feature_information(featureName, "Yes Votes");
            j = 4 - strlen(yesVotes);
            eventMsg += yesVotes + arrange_string(" ", j);
            noVotes = "";
            noVotes += FEATURE_D->get_feature_information(featureName, "No Votes");
            j = 4 - strlen(noVotes);
            eventMsg += noVotes + arrange_string(" ", j);
            ETA = "";
            ETA += FEATURE_D->get_feature_information(featureName, "ETA");
            j = 10 - strlen(ETA);
            eventMsg += ETA + arrange_string(" ", j);
            ExpiresIn = "";
            ExpiresIn = FEATURE_D->get_feature_information(featureName, "Voting Expires In");
            j = 10 - strlen(ExpiresIn);
            eventMsg += ExpiresIn + arrange_string(" ", j);
            tell_object(targ, eventMsg);
            continue;
        }
    }
    return 1;
}

int cmd_flag(string str)
{
    object target;
    string mycommand, myplayer;
    string targ, arg, subarg, myVote, *pieces;
    int perc, base, res;
    if(!str)
    {
        do_flag_display(TP);
        return 1;
    }
    if(sscanf(str, "%s as %s", targ, arg) == 2)
    {
        targ = lower_case(targ);
        if(member_array(targ, SUPPORTEDFLAGS) == -1)
        {
            tell_object(TP, "\n%^BOLD%^%^WHITE%^Supported flags are currently : \n\n\t"+implode(SUPPORTEDFLAGS, "\n\t")+"%^RESET%^");
            return 1;
        }
        switch(targ)
        {
            case "feature":
                if(arg == "add")
                {
                    if(!wizardp(TP)) return 0;
                    res = FEATURE_D->can_insert_feature(TP, "testcheckfeature");
                    if(res == -1)
                    {
                        tell_object(TP, "Error.");
                        return 1;
                    }
                    else if(res == -2)
                    {
                        tell_object(TP, "Only immortals above the apprentice rank are allowed to "+
                        "add features for voting.");
                        return 1;
                    }
                    else if(res == 1)
                    {
                        new("/cmds/mortal/obj/featureadd.c")->move(TP);
                        return 1;
                    }
                    tell_object(TP, "Error.");
                    return 1;
                }
                if(sscanf(arg, "%s %s", arg, subarg) != 2)
                {
                    tell_object(TP, help());
                    return 1;
                }
                if(arg == "view")
                {
                    FEATURE_D->view_feature(TP, subarg);
                    return 1;
                }
                if(arg == "remove")
                {
                    res = FEATURE_D->kill_feature(TP, subarg);
                    if(res == -1)
                    {
                        tell_object(TP, "Invalid object trying to remove a feature.");
                        return 1;
                    }
                    if(res == -4)
                    {
                        tell_object(TP, capitalize(subarg)+" is an invalid feature.");
                        return 1;
                    }
                    if(res == -7)
                    {
                        tell_object(TP, "Invalid access to remove feature "+subarg+".");
                        return 1;
                    }
                    if(res == 1)
                    {
                        tell_object(TP, "Voting for feature "+subarg+" has been removed. "+
                        "It will be cleared from the daemon on the next check. Or you can do "+
                        "eval FEATURE_D->check_features() to remove it now.");
                        return 1;
                    }
                }
                break;
            case "character improvement tax":
                perc = to_int(arg);
                if(perc < 50)
                {
                    tell_object(TP, "You cannot lower your character improvement tax below 50%.");
                    return 1;
                }
                if(perc > 100)
                {
                    tell_object(TP, "You cannot raise your character improvement tax above 100%.");
                    return 1;
                }
                USER_D->set_character_improvement_tax_percent(TP, perc);
                return 1;
            case "roleplay flag":
                if(arg != "on")
                {
                    tell_object(TP, "The only valid argument for a roleplay flag is on. If you "+
                    "decide that you need to log out or move on, just leave the area and the flag "+
                    "will adjust automatically.");
                    return 1;
                }
                if(!USER_D->setup_rp_flag(TP))
                {
                    tell_object(TP, "Something went wrong when setting up the roleplay flag.");
                    return 1;
                }
                tell_object(TP, "You are now flying a RP flag!");
                return 1;
            case "player kill":
                if(arg != "on")
                {
                    tell_object(TP, "You are only able to turn off your pkill protection.");
                    return 1;
                }
                if(!TP->query("no pk"))
                {
                    tell_object(TP, "Your PK immunity has already been dropped.");
                    return 1;
                }
                if(TP->query("pk_death_time") > time())
                {
                    tell_object(TP, "You are not yet able to remove your PK immunity.");
                    return 1;
                }
                TP->delete("no pk");
                tell_object(TP,"%^YELLOW%^You are no longer flagged for PK immunity.  You are welcome to engage in PK with any "+
                "other player who is not flagged for PK immunity.%^RESET%^");
                message("info","%^YELLOW%^"+capitalize(TP->query_name())+"'s %^MAGENTA%^PK immunity %^YELLOW%^has just been removed.%^RESET%^\n",users());
                "/cmds/avatar/_note.c"->cmd_note("ckpt "+capitalize(TP->query_name())+" %^BOLD%^%^CYAN%^chose to remove PK immunity.%^RESET%^");
                return 1;
                break;
            case "scaled level":

                tell_object(TP, "This is temporarily disabled.");
                return 1;

                if (!ETP->query_property("training")) {
                    tell_object(TP, "You must be in a place that allows you to advance in order to use " +
                                "level scaling.");
                    return 1;
                }
                base = TP->query_base_character_level();
                if (arg == "revert" || arg == "normal") {
                    USER_D->scale_level_to(TP, base);
                    return 1;
                }
                perc = to_int(arg);
                if (perc < 6) {
                    tell_object(TP, "You cannot currently scale your level below level 6.");
                    return 1;
                }
                if (perc > base) {
                    tell_object(TP, "You cannot currently scale your level above your total " +
                                "character level of " + base + " (please note: this does not include level adjusted " +
                                "races).");
                    return 1;
                }
                if (perc == base) {
                    USER_D->scale_level_to(TP, base);
                    return 1;
                }
                USER_D->scale_level_to(TP, perc);
                return 1;
        }
        return 1;
    }
    if(!avatarp(TP)) { help(); return 1;}
    if(!find_player(str))
    {
        tell_object(TP, "No such player "+str+" found.");
        return 1;
    }
    do_flag_display(find_player(str), TP);
    return 1;
}

void help()
{
    write("
%^CYAN%^NAME%^RESET%^

flag - manipulate player flags

%^CYAN%^SYNOPSIS%^RESET%^

flag
flag scaled level as %^ORANGE%^%^ULINE%^LEVEL%^RESET%^|normal
flag roleplay flag as on
flag player kill as on

%^CYAN%^DESCRIPTION%^RESET%^

This command lets you adjust some various flags about your character. %^ORANGE%^<flag>%^RESET%^ by itself will show all flags and their current settings.

%^CYAN%^scaled level%^RESET%^
  Will allow you to scale your level down to the specified %^ORANGE%^<level>%^RESET%^in order to adventure with or take part in plots with lower level characters. Use at your own risk. You cannot go below level 6 or above your own base character level. Using%^ORANGE%^<normal>%^RESET%^ instead of a level will revert you back to your normal non scaled level.

%^CYAN%^roleplay flag %^RESET%^
  Will fly a RP flag in your current environment. This will causeyour current room to show up on the who list as a RP FLAG and will show up in the rumorscommand.

%^CYAN%^player kill %^RESET%^
  Will disable your pk immunity and allow you to take part in player kill interactions. Once you are killed out of player kill this flag will automatically turn back on and have a delay before it can be turned back off again, currently the delay is one week of real life time.

%^CYAN%^SEE ALSO%^RESET%^

set, chfn, score, pkilling, rules, death
");
}
