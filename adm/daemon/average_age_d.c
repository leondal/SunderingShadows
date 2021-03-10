#include <std.h>
#include <security.h>
#include <daemons.h>

#define SAVE_FILE "/daemon/save/average_age"

//keeping a mapping of 40 players last on to be counted for the average - probably not needed to calculate
//anymore than this - Saide
mapping PLAYER_LIST;

int average, original_average;

nosave int TWO_WEEKS = 1209600;
//minimum age for them to count toward the average - should be 6 hours right now - Saide
nosave int MIN_AGE = 21600;
//minimum percent of age that a player needs in order to be able to engage in player kill situations - Saide
nosave int MIN_PERC = 40;


void check_average();
void save_average_age();
void restore_average_age();
void check_last_login();
void update_average();
varargs void register_player(object who);
int return_rolling_average();
int return_age_needed(int lev);

void save_average_age()
{
    seteuid(UID_ROOT);
    save_object(SAVE_FILE, 1);
    seteuid(geteuid());
}

void check_average()
{
    if(average == -1)
    {
        average = "/adm/daemon/user_age_d.c"->GET_AVERAGE_TIME();
        if(average == -1) call_out("check_average", 600);
        else
        {
            original_average = average;
            save_average_age();
        }
    }
}
void restore_average_age()
{
    if(!average)
    {
        seteuid(UID_ROOT);
        if(file_exists(SAVE_FILE +".o") || file_exists(SAVE_FILE))
        {
            seteuid(UID_RESTORE);
            restore_object(SAVE_FILE);
            seteuid(geteuid());
        }
        seteuid(geteuid());
    }
    if(!average) average = "/adm/daemon/user_age_d.c"->GET_AVERAGE_TIME();
    if(average == -1) call_out("check_average", 600);
    if(!mapp(PLAYER_LIST))
    {
        PLAYER_LIST = ([]);
        original_average = average;
        save_average_age();
    }
}

void create()
{
    restore_average_age();
}

void check_last_login()
{
    int x, flag;
    string *player_names;
    if(!mapp(PLAYER_LIST)) restore_average_age();
    if(!mapp(PLAYER_LIST)) return;
    for(x = 0;x < sizeof(player_names);x++)
    {
        //been greater than 2 weeks they no longer count for the average
        if(time() - PLAYER_LIST[player_names[x]]["last on"] > TWO_WEEKS || !user_exists(player_names[x]))
        {
            map_delete(PLAYER_LIST, player_names[x]);
            flag = 1;
            continue;
        }
    }
    if(flag) save_average_age();
}

void update_average()
{
    string *player_names;
    int x, y, tmp;
    if(average == -1)
    {
        //some reason it is trying to get it from the daemon and hasn't yet - Saide
        call_out("update_average", 600);
        return;
    }
    if(!mapp(PLAYER_LIST)) restore_average_age();
    if(!mapp(PLAYER_LIST)) return;
    player_names = keys(PLAYER_LIST);
    y = sizeof(player_names);
    if(y > 40) y = 40;
    if(y < 20)
    {
        //let's only update the average once 20 current characters have logged in - Saide
        if(average != original_average) average = original_average;
        return;
    }
    tmp = 0;
    for(x = 0;x < y;x++)
    {
        //tell_object(find_player("saide"), "Adding age for "+player_names[x]);
        if(tmp > 0)
        {
            tmp += PLAYER_LIST[player_names[x]]["age"];
            tmp /= 2;
        }
        else tmp += PLAYER_LIST[player_names[x]]["age"];
        continue;
    }
    if(tmp)
    {
        //original_average = average;
        average = tmp;
    }
    return;
}

varargs void register_player(object who)
{
    string player_name, *player_names;
    int player_age, player_last_on;
    if(!objectp(who)) return;
    if(!userp(who)) return;
    if(avatarp(who)) return;
    if(!mapp(PLAYER_LIST)) restore_average_age();
    if(!mapp(PLAYER_LIST)) return;
    //removes people from the mapping gone greater than two weeks - Saide
    check_last_login();
    player_name = who->query_name();
    player_names = keys(PLAYER_LIST);
    //there are no people who have been online in the past two weeks - restart
    if(!sizeof(player_names))
    {
        average = original_average;
        save_average_age();
    }
    if(sizeof(player_names) >= 40 && member_array(player_name, player_names) == -1) return;
    player_age = who->query_age();
    player_last_on = who->query_quit_time();
    if(player_age < MIN_AGE) return;
    if(mapp(PLAYER_LIST[player_name]))
    {
        PLAYER_LIST[player_name]["age"] = player_age;
        PLAYER_LIST[player_name]["last on"] = player_last_on;
    }
    else
    {
        PLAYER_LIST += ([player_name : (["age" : player_age, "last on" : player_last_on]),]);
    }
    update_average();
    save_average_age();
}

string *contributors() { return keys(PLAYER_LIST); }
int return_rolling_average() { return average; }
int return_age_needed(int lev)
{
    if(!intp(lev)) return (average * MIN_PERC) / 100;
    if(lev < 21) return 0;
    else if(lev >= 21 && lev < 26) return (average * (MIN_PERC/5)) / 100;
    else if(lev >= 26 && lev < 30) return (average * (MIN_PERC/4)) / 100;
    else if(lev >= 30 && lev < 36) return (average * (MIN_PERC/3)) / 100;
    else if(lev >= 36 && lev < 41) return (average * (MIN_PERC/2)) / 100;
    return (average * MIN_PERC) / 100;
}
