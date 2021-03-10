//stolen from my brother's absolutely brilliant /adm/daemon/user_age_d.c 
//modified to calculate a list of immortals, by positions immortal/builder - through creator
//who have been inactive for at least six months - Saide, December 2016

#include <std.h>
#include <security.h>
#include <daemons.h>
#include <objects.h>
#include <dontrid.h>

#define PATHS  ({ "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" })
#define DELAY 5 // 5 second delay between calculating each block of names for time

int SIX_MONTHS = 15552000; // number of seconds in six months
int SECS_DAY = 86400;

int LIST_BUILT,AVERAGE,FINISHED,STARTED; // keep a running tally of average, numbers are too big to add them all

string FILES = "/adm/save/users/";

string *APP, *BUILD, *CRE, *AVA, *LVL10, *LVL20, *LVL30, *LVL40, *ICE_LIST;

mapping PLAYER_LIST;
int IS_LIST;
object CURRENT_ICE_OBJECT;

int GET_AVERAGE_TIME();
void begin_calculation();
void build_player_list();
string *identify_inactive_imms(object who, string pos);
string *identify_inactive_mortals(object who, int lev);
int identify_inactive_immortals(object who, string pos);
int identify_inactive_players(object who, int lev);
int build_inactive_names(string user);
int inactive_six_months(string user);
void build_inactive_users_list(int letter);
int get_last_on(string user);
int ice_users(object who, string pos, string type, int days, int llev, int hlev, string ip, string email, object ob, string extra_arg);
void build_users_to_ice(int letter, string pos, string type, int days, object who, int llev, int hlev, string ip, string email);
int inactive_for_days(string user, int days);
int build_ice_list(string user, string pos, string type, int llev, int hlev, string ip, string email);
void remove_ice_object();

void create()
{
    seteuid(UID_ROOT);
    APP = ({});
    BUILD = ({});
    CRE = ({});
    AVA = ({});
    LVL10 = ({});
    LVL20 = ({});
    LVL30 = ({});
    LVL40 = ({});
    PLAYER_LIST = ([]);
    LIST_BUILT = 0;
    AVERAGE = 0;
    FINISHED = 0;
    STARTED = 0;
}

int BUILD_INACTIVE_LIST()
{
    if (!STARTED)
    {
        begin_calculation();
        return -1;
    }
    if (!FINISHED) { return -1; }

    return 1;
}

mixed my_ice_object() { return CURRENT_ICE_OBJECT; }

int ice_users(object who, string pos, string type, int days, int llev, int hlev, string ip, string email, object ob, string extra_arg)
{
    if(!objectp(who)) return 0;
    if(!member_group((string)who->query_true_name(), "law")) return 0;
    if(objectp(CURRENT_ICE_OBJECT))
    {
        tell_object(TP, "The daemon is currently running, please wait until it is finished before "+
        "using the command.");
        return 0;   
    }
    else 
    {
        if(objectp(ob)) CURRENT_ICE_OBJECT = ob;
    }   
    if(!stringp(type))
    {
        tell_object(who, "You must specify a type. Valid types are level, ip, or email.");
        return 0;
    }
    if(stringp(extra_arg)) 
    {
        if(extra_arg == "list") { IS_LIST = 1; }
        else { IS_LIST = 0; }
    }
    else IS_LIST = 0;
    switch(type)
    {
        case "level":
            if(!stringp(pos)) return 0;
            if(!intp(days)) return 0;
            tell_object(who, "Building list of users to ice who are position "+pos+", have "+
            "been inactive for at least "+days+" days, and are between level "+llev+" and "+hlev+".");
            break;
        case "ip":
            if(!stringp(ip)) return 0;
            tell_object(who, "Building list of users to ice who last logged in from the "+
            "ip address "+ip+".");
            break;
        case "email":
            if(!stringp(email)) return 0;
            tell_object(who, "Building list of users to ice who have the email address "+
            email+".");
            break;
    }
    PLAYER_LIST = ([]);
    if(!mapp(PLAYER_LIST)) build_player_list();
    else if(!sizeof(keys(PLAYER_LIST))) build_player_list();
    
    ICE_LIST = ({});
    build_users_to_ice(0, pos, type, days, who, llev, hlev, ip, email);
    return 1;    
}

// don't call this, call GET_AVERAGE_TIME instead
void begin_calculation()
{
    build_player_list();
    build_inactive_users_list(0);
    STARTED = 1;
    return;
}

// builds complete list of all players
void build_player_list()
{
    int i,j, count = 0;
    string *list, *names;

    for (i = 0;i < sizeof(PATHS);i++)
    {
        if (!pointerp(list = get_dir(FILES + PATHS[i] + "/"))) { continue; }

        names = ({});

        for (j = 0;j < sizeof(list);j++)
        {
            names += ({ replace_string(list[j],".o","") });
        }
        count += sizeof(names);
        PLAYER_LIST[PATHS[i]] = names;
    }
    //tell_object(find_player("saide"), "There are "+count+" total users.");
    LIST_BUILT = 1;
}

// steps through the letter blocks of users, one letter at a time 
// and builds a list of users who have been inactive for at least 
// six months of time
void build_inactive_users_list(int letter)
{
    int i,time;
    string *names;

    if (!LIST_BUILT) { return;  }

    // gets a list of the names starting with each letter, moves on to the next letter if there are no names starting with that letter
    if (!pointerp(names = PLAYER_LIST[PATHS[letter]]))
    {
        if (letter < sizeof(PATHS)-1)
        {
            letter++;
            call_out("build_inactive_users_list", DELAY, letter);
            return;
        }
        else // if we run out of letters, just stop
        {
            return;
        }
    }

    // all the work for averaging the online times is done in here
    for (i = 0;i < sizeof(names);i++)
    {
        if (!inactive_six_months(names[i])) { continue; } // skip if they have been on in six months
        build_inactive_names(names[i]);
        continue; 
    }

    // step to our next letter and keep calculating
    if (letter < sizeof(PATHS)-1)
    {
        letter++;
        call_out("build_inactive_users_list", DELAY, letter);
        return;
    }
    else // until we run out of letters, then let the program know that we're done
    {
        FINISHED = 1;
    }

    return;
}

/*====================================================================
 steps through the letter blocks of users, one letter at a time 
 and builds a list of users who have been inactive
 for x amount of days, between llev (low level) and hlevl (maximum level)
 OR builds a list based on a given email
 OR builds a list based on a given ip address
 NOTE - using the days llev/hlev will exclude 
 anyone who is a high mortal or has a high mortal 
 on their account. Ip/email does not afford this same luxury, it assumes
 that icing users by this method is for a purpose other than general clean up 
 IE - they did something to warrant a ridding. 
=====================================================================*/
void remove_ice_object()
{
    if(objectp(CURRENT_ICE_OBJECT))
    {
        if(!userp(CURRENT_ICE_OBJECT)) CURRENT_ICE_OBJECT->remove();
        CURRENT_ICE_OBJECT = 0;
    }
    return;
}

void build_users_to_ice(int letter, string pos, string type, int days, object who, int llev, int hlev, string ip, string email)
{
    int i,time;
    string *names;
    if (!LIST_BUILT) { return;  }
    switch(type)
    {
        case "level":        
            if(!stringp(pos)) { remove_ice_object(); return; }
            if(!intp(days)) { remove_ice_object(); return; }
            if(!intp(llev)) { llev = 1; }
            if(!intp(hlev)) { hlev = 6; }
            break;
        case "email":
            if(!stringp(email)) { remove_ice_object(); return; }
            break;
        case "ip":
            if(!stringp(ip)) { remove_ice_object(); return; }
            break;
    }
    if(!objectp(who)) return; 
    if(!member_group((string)who->query_true_name(), "law")) { return ; }
    if (!pointerp(names = PLAYER_LIST[PATHS[letter]]))
    {
        if (letter < sizeof(PATHS)-1)
        {
            letter++;
            call_out("build_users_to_ice", DELAY, letter, pos, type, days, who, llev, hlev, ip, email);
            return;
        }
        else // if we run out of letters, just stop
        {
            return;
        }
    }

    for (i = 0;i < sizeof(names);i++)
    {
        if (!inactive_for_days(names[i], days) && type == "level") { continue; } // skip if they have been online before the specified time
        build_ice_list(names[i], pos, type, llev, hlev, ip, email);
        continue; 
    }

    // step to our next letter and keep calculating
    if (letter < sizeof(PATHS)-1)
    {
        letter++;
        call_out("build_users_to_ice", DELAY, letter, pos, type, days, who, llev, hlev, ip, email);
        return;
    }
    else // until we run out of letters, then let the program know that we're done
    {      
        if(objectp(CURRENT_ICE_OBJECT) && !IS_LIST) { CURRENT_ICE_OBJECT->ice_list(ICE_LIST); }
        else if(IS_LIST) 
        {
            switch(type)
            {
                case "level":            
                    tell_object(who, "You would have iced "+sizeof(ICE_LIST)+ " users of position "+pos+", between level "+llev+
                    " and "+hlev+" who have been inactive for at least "+days+" days.");
                    break;
                case "email":
                    tell_object(who, "You would have iced "+sizeof(ICE_LIST)+" users with the email address "+email+".");
                    break;
                case "ip":
                    tell_object(who, "You would have iced "+sizeof(ICE_LIST)+" users with the ip address "+ip+".");
                    break;
            }
            who->more(ICE_LIST);
        }
        CURRENT_ICE_OBJECT = 0;
        //who->more(ICE_LIST);
        FINISHED = 1;
    }

    return;
}

// returns 1 if they have not been online in six months
int inactive_six_months(string user)
{
    int last_on = get_last_on(user);
    if ((time() - last_on) > SIX_MONTHS) { return 1; }
    return 0;
}

// returns 1 if they have not been online in days * SECS_DAYS 
int inactive_for_days(string user, int days)
{
    int inactive_days;
    int last_on = get_last_on(user);
    inactive_days = (days * SECS_DAY);
    if ((time() - last_on) > inactive_days) { return 1; }
    return 0;
}

/*==============================================
The following four functions simply return 
lists of inactive mortals or immortals, who are 
particular ranks/levels, who have not logged in for at 
least six months of RL time
==============================================*/

string *identify_inactive_imms(object who, string pos)
{
    if(!objectp(who)) return 0;
    if(!stringp(pos)) pos = "all";
    if(!member_group((string)who->query_true_name(), "law")) return 0;
    switch(pos)
    {
        case "all":
            return (BUILD+APP+CRE+AVA);
        case "avatar":
            return AVA;
        case "apprentice":
            return APP;
        case "creator":
            return CRE;
        case "builder":
            return BUILD;
    }
    return ({});
}

string *identify_inactive_mortals(object who, int lev)
{
    if(!objectp(who)) return 0;
    if(!intp(lev)) lev = 10;
    if(!member_group((string)who->query_true_name(), "law")) return 0;
    switch(lev)
    {
        case 10:
            return LVL10;
        case 20:
            return LVL20;
        case 30:
            return LVL30;
        case 40:
            return LVL40;
        default:
            return (LVL10+LVL20+LVL30+LVL40);
    }
    return ({});
}

int identify_inactive_immortals(object who, string pos)
{
    if(!objectp(who)) return 0;
    if(!stringp(pos)) pos = "all";
    if(!member_group((string)who->query_true_name(), "law")) return 0;
    switch(pos)
    {
        case "all":
            tell_object(TP, "There are "+sizeof(BUILD)+" inactive builders.\n");            
            tell_object(TP, "There are "+sizeof(APP)+ " inactive apprentices.\n");
            tell_object(TP, "There are "+sizeof(CRE) + " inactive creators.\n");
            tell_object(TP, "There are "+sizeof(AVA)+ " inactive avatars.\n");
            who->more((BUILD+APP+CRE+AVA));
            break;
        case "avatar":
            tell_object(TP, "There are "+sizeof(AVA)+" inactive avatars.\n");
            who->more(AVA);
            break;
        case "apprentice":
            tell_object(TP, "There are "+sizeof(APP)+" inactive apprentices.\n");
            who->more(APP);
            break;
        case "creator":
            tell_object(TP, "There are "+sizeof(CRE)+" inactive creators.\n");
            who->more(CRE);
            break;
        case "builder":
            tell_object(TP, "There are "+sizeof(BUILD)+" inactive builders.\n");
            who->more(BUILD);
            break;
    }
    return 1;
}

int identify_inactive_players(object who, int lev)
{
    if(!objectp(who)) return 0;
    if(!intp(lev)) lev = 10;
    if(!member_group((string)who->query_true_name(), "law")) return 0;
    switch(lev)
    {
        case 10:
            tell_object(TP, "There are "+sizeof(LVL10)+" inactive players level 10 and under.\n");            
            who->more(LVL10);
            break;
        case 20:
            tell_object(TP, "There are "+sizeof(LVL20)+" inactive players between level 11 and 20.\n");            
            who->more(LVL20);
            break;
        case 30:
            tell_object(TP, "There are "+sizeof(LVL30)+" inactive players between level 21 and 30.\n");            
            who->more(LVL30);
            break;
        case 40:
            tell_object(TP, "There are "+sizeof(LVL40)+" inactive players between level 31 and 40.\n");            
            who->more(LVL40);
            break;
        default:
            tell_object(TP, "There are "+sizeof(LVL40)+sizeof(LVL10)+sizeof(LVL20)+sizeof(LVL30)+" inactive players between level 1 and 40.\n");            
            who->more((LVL10+LVL20+LVL30+LVL40));
            break;
    }
    return 1;
}
//END OF list functions

//Function return last online time
int get_last_on(string user)
{
    int quit_time;
    quit_time = (int)USERCALL->user_call(user, "query_quit_time");
    return quit_time;
}

//Function that builds list of names of 
//immortals/mortals who have not been online 
//in six months 
int build_inactive_names(string user)
{
    string pos;
    int x;
    pos = (string)USERCALL->user_call(user, "query_position");
    if(pos == "builder")
    {
        BUILD += ({user});
        return 1;
    }
    else if(pos == "apprentice")
    {
        APP += ({user});
        return 1;
    }
    else if(pos == "avatar")
    {
        AVA += ({user});
        return 1;
    }
    else if(pos == "creator")
    {
        CRE += ({user});
        return 1;
    }
    //don't count high mortals
    else if(pos == "high mortal") 
    {
        return 0;
    }
    else if(pos == "player")
    {
        //don't count users on a high mortal account
        if(OB_ACCOUNT->is_high_mortal(user)) return 0;
        x = (int)USERCALL->user_call(user, "query_level");
        switch(x)
        {
            case 0..10: 
                LVL10 += ({user});
                break;
            case 11..20:
                LVL20 += ({user});
                break;
            case 21..30: 
                LVL30 += ({user});
                break;
            case 31..40:
                LVL40 += ({user});
                break;
            default:
                LVL40 += ({user});
                break;            
        }
        return 1;
    }
    return 0;
}

/*===========================================================
Funtion that builds list of users to ice based on either 
 llev - hlevl (low - high level) && position
 IP address
 email address 
 level method excludes high mortals 
 all methods exclude law/superuser
=============================================================*/

int build_ice_list(string user, string pos, string type, int llev, int hlev, string ip, string email)
{
    string cpos, cip, cemail;
    int mlev;
    if(!stringp(user)) return 0;   
    if(!stringp(type)) return 0;
    if(member_group(user, "law")) return 0;
    if(member_group(user, "superuser")) return 0;
    switch(type) 
    {
        case "level":      
            if(!stringp(pos)) return 0;
            cpos = (string)USERCALL->user_call(user, "query_position");
            if(pos == "high mortal") return 0; //don't ice high mortals
            if(OB_ACCOUNT->is_high_mortal(user)) return 0;
            //including /adm/include/dontrid.h here also
            if(member_array(user, EXCLUDE) != -1) return 0;
            if(cpos != pos) return 0;
            mlev = (int)USERCALL->user_call(user, "query_level");
            if(mlev > hlev) return 0;
            if(mlev < llev) return 0;
            ICE_LIST += ({user});
            return 1;    
            break;
        case "ip":            
            cip = (string)USERCALL->user_call(user, "query_ip");
            if(cip != ip) return 0;
            ICE_LIST += ({user});
            return 1;
            break;
        
        case "email":        
            cemail = (string)USERCALL->user_call(user, "query_email");
            if(cemail != email) return 0;
            ICE_LIST += ({user});
            return 1;
            break;
    }
    return 0;          
}