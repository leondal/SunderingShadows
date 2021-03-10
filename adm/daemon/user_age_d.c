#include <std.h>
#include <security.h>
#include <daemons.h>

#define PATHS  ({ "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z" })
#define DELAY 5 // 5 second delay between calculating each block of names for time

int TWO_WEEKS = 1209600; // number of seconds in two weeks

int LIST_BUILT,AVERAGE,FINISHED,STARTED; // keep a running tally of average, numbers are too big to add them all

string FILES = "/adm/save/users/";

mapping PLAYER_LIST;


int GET_AVERAGE_TIME();
void begin_calculation();
void build_player_list();
void calculate_time_block(int letter);
int average_time(int time);
int on_lately(string user);
int get_age(string user);
int get_last_on(string user);
int get_immortal(string user);


void create()
{
    seteuid(UID_ROOT);

    PLAYER_LIST = ([]);
    LIST_BUILT = 0;
    AVERAGE = 0;
    FINISHED = 0;
    STARTED = 0;
}


// NOTE: this causes some very noticable lag, use sparingly -Ares
// please read and understand this before using, because of the delay in getting data, it requires some
// additional steps -Ares
// call this function to get the average time.  There is some delay for this to finish doing all of the work
// so you will need to use a callout any time that you need this on the first time during a reboot.
// duration of the callout should be approximately DELAY * 26 + about 10% just to make sure it has
// time to finish counting.   again, call_out("some_function_that_checks_GET_AVERAGE_TIME", (5(which is DELAY now) * 27))  
// the first call to GET_AVERAGE_TIME doesn't need a delay, it begins to process of checking the average time.
// GET_AVERAGE_TIME() will keep returning -1 until it finishes building an average, and then afterwards it will return
// that average for the rest of the reboot.
int GET_AVERAGE_TIME()
{
    if (!STARTED)
    {
        begin_calculation();
        return -1;
    }
    if (!FINISHED) { return -1; }

    return AVERAGE;
}



// don't call this, call GET_AVERAGE_TIME instead
void begin_calculation()
{
    build_player_list();
    calculate_time_block(0);
    STARTED = 1;
    return;
}

// builds complete list of all players
void build_player_list()
{
    int i,j;
    string *list, *names;

    for (i = 0;i < sizeof(PATHS);i++)
    {
        if (!pointerp(list = get_dir(FILES + PATHS[i] + "/"))) { continue; }

        names = ({});

        for (j = 0;j < sizeof(list);j++)
        {
            names += ({ replace_string(list[j],".o","") });
        }

        PLAYER_LIST[PATHS[i]] = names;
    }

    LIST_BUILT = 1;
}

// steps through the letter blocks of users, one letter at a time, and calculates how much ptime they have on average for the players that have been on in the last two weeks
void calculate_time_block(int letter)
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
            call_out("calculate_time_block", DELAY, letter);
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
        if (!on_lately(names[i])) { continue; } // skip if they haven't been on in two weeks
        if (get_immortal(names[i])) { continue; } // don't count immortals

        time = get_age(names[i]);
        if (time < 1) { time = 1; } // just in case somebody has negative ptime, somehow

        if (!AVERAGE) { AVERAGE = time; }
        AVERAGE = average_time(time);    
    }

    // step to our next letter and keep calculating
    if (letter < sizeof(PATHS)-1)
    {
        letter++;
        call_out("calculate_time_block", DELAY, letter);
        return;
    }
    else // until we run out of letters, then let the program know that we're done
    {
        FINISHED = 1;
    }

    return;
}

// mathz
int average_time(int time)
{
    return (AVERAGE + time) / 2;
}

// returns 1 if they've been on in the last 2 weeks, 0 otherwise
int on_lately(string user)
{
    int last_on = get_last_on(user);
    if ((time() - last_on) > TWO_WEEKS) { return 0; }
    return 1;
}

// returns their playtime in seconds
int get_age(string user)
{
    int age;
    age = (int)USERCALL->user_call(user, "query_player_age");
    return age;
}

// returns the last time they were online
int get_last_on(string user)
{
    int quit_time;
    quit_time = (int)USERCALL->user_call(user, "query_quit_time");
    return quit_time;
}

// returns 1 if they are an avatar, 0 otherwise
int get_immortal(string user)
{
    int imm;
    imm = (int)USERCALL->user_call(user, "is_avatar");
    return imm;
}
