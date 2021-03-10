//     /adm/simul_efun/time.c
//      from the Nightmare mudlib
//      simul_efuns for the Nightmare mudlib time setup
//      created by Descartes of Borg 04 April 1993

#include <daemons.h>
#include <clock.h>

/**
 * @file
 * @brief Various time related functions
 */

int query_night() {
    return ((string)EVENTS_D->query_time_of_day() == "night");
}

string day(int x) { return (string)EVENTS_D->query_day_name(x); }

int date(int x) {
    int week, datum;

    week = (int)EVENTS_D->query_week(x);
    datum = (int)EVENTS_D->query_day(x);
    return (sizeof(DAYS)*(week-1)+datum);
}

string month(int x) { return (string)EVENTS_D->query_month_name(x); }

int year(int x) { return (int)EVENTS_D->query_year(x); }

int minutes(int x) { return (int)EVENTS_D->query_minutes(x); }

string season(int x) {
    int mon;

    mon = (int)EVENTS_D->query_month(x);
    switch(mon) {
        case 1: return "winter";
        case 2: if(date(x) < 16) return "winter"; else return "spring";
        case 3:
        case 4: return "spring";
        case 5: if(date(x) < 6) return "spring"; else return "summer";
        case 6: return "summer";
        case 7: if(date(x) < 16) return "summer"; else return "autumn";
        case 8:
        case 9: return "autumn";
        case 10: return (date(x) < 6 ? "autumn" : "winter");
        default: return "error";
    }
}

int hour(int x) { return (int)EVENTS_D->query_hour(x); }
