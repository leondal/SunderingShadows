//ACTIVELY USED

#include <daemons.h>
#include <security.h>
#include <objects.h>
#include <clock.h>
#include <save.h>
#include <rooms.h>

private int __RebootInterval;
private mapping __Events;
private nosave int __InReboot;
private nosave string __TimeOfDay;
private nosave mapping __Almanac;

void create() {
    seteuid(UID_DAEMONSAVE);
    restore_object(SAVE_EVENTS);
    seteuid(getuid());
     if(!__RebootInterval) __RebootInterval = 7;
    if(!__Events) __Events = ([]);
    Save();
    configure_day();
    call_out("check_events", 60);
}

void set_reboot_interval(int x) {
    if(geteuid(previous_object()) != UID_SHUTDOWN) return;
    if(x > 0) __RebootInterval = x;
    Save();
}

varargs void add_events(object ob, string fun, int when, mixed *args, int reg) {
    if(file_name(previous_object()) != OB_SIMUL_EFUN) return;
    __Events[file_name(ob)] =
      (["time":time()+when, "function":fun, "regular":(reg?when:0),
      "args":(pointerp(args) ? args : ({})) ]);
    Save();
}
void interval(){
	write("interval -- : "+__RebootInterval+"  uptime -- : "+uptime());
	return;
}

int check_time() { return time(); }

protected void check_events() {
    string *events;
    int i, x;

    call_out("check_events", 60);
    x = time();
    i = sizeof(events = keys(__Events));
    while(i--) {
        if(__Events[events[i]]["time"] <= x) {
            catch(call_other(events[i], __Events[events[i]]["function"],
              __Events[events[i]]["args"]));
            if(__Events[events[i]]["regular"] > 3599)
              __Events[events[i]]["time"] = x + __Events[events[i]]["regular"];
            else if(events[i] != file_name(this_object()))
              map_delete(__Events, events[i]);
        }
    }
    if(uptime() > __RebootInterval*60*60*24 && !__InReboot) {
      __InReboot = 1;
        reboot();
    }
    Save();
}

protected void Save() {
    seteuid(UID_DAEMONSAVE);
    save_object(SAVE_EVENTS);
    seteuid(getuid());
}

protected void reboot() {
    shout("%^BOLD%^%^RED%^ATTENTION: %^YELLOW%^ Time for the weekly reboot!");
    shout("%^GREEN%^ShadowGate will be back up moments after the reboot.");
    seteuid(UID_SHUTDOWN);
    catch(SHUT_D->startShutdown(1,20));
    seteuid(getuid());
    map_delete(__Events, file_name(this_object()));
//    new(OB_SHUT)->move(ROOM_START);
    Save();
}

void configure_day() {
    int temps, x, y;

    __Almanac = almanac_data();
    y = query_minutes(temps = time());
    if((x=query_hour(temps)) < __Almanac["sunrise"][0]) __TimeOfDay = "night";
    else if(x==__Almanac["sunrise"][0]) {
        if(y < __Almanac["sunrise"][1]) __TimeOfDay = "night";
        else __TimeOfDay = "dawn";
    }
    else if(x < __Almanac["morning"][0]) __TimeOfDay = "dawn";
    else if(x == __Almanac["morning"][0]) {
        if(y < __Almanac["morning"][1]) __TimeOfDay = "dawn";
        else __TimeOfDay = "day";
    }
    else if(x < __Almanac["twilight"][0]) __TimeOfDay = "day";
    else if(x == __Almanac["twilight"][0]) {
        if(y < __Almanac["twilight"][1]) __TimeOfDay = "day";
        else __TimeOfDay = "twilight";
    }
    else if(x < __Almanac["sunset"][0]) __TimeOfDay = "twilight";
    else if(x == __Almanac["sunset"][0]) {
        if(y < __Almanac["sunset"][1]) __TimeOfDay = "twilight";
        else __TimeOfDay = "night";
    }
    else __TimeOfDay = "night";
    next_change();
}

void next_change() {
    int now, next, tot;
    string str;

    now = query_hour(time())*60 + query_minutes(time());
    switch(__TimeOfDay) {
        case "night":
            str = "sunrise";
            break;
        case "dawn":
            str = "morning";
            break;
        case "day":
            str = "twilight";
            break;
        case "twilight":
            str = "sunset";
            break;
    }
    next = (60*__Almanac[str][0]) + __Almanac[str][1];
    if(next > now) tot = next-now;
    else {
        now = (1200)-now;
        tot = next + now;
    }
    __Events[file_name(this_object())] =
      (["time":time()+(20*tot),"function":"change_sky","args":({}),"regular":0]);
}

void change_sky() {
    string msg;
    object *who;
    int i;

    switch(__TimeOfDay) {
        case "night":
            __TimeOfDay = "dawn";
            msg = "%^ORANGE%^The sun appears over the horizon of our reality.%^RESET%^";
            break;
        case "dawn":
            __TimeOfDay = "day";
            msg = "%^YELLOW%^The sun now shines completely on a new day.%^RESET%^";
            break;
        case "day":
            __TimeOfDay = "twilight";
           msg = "%^BOLD%^CYAN%^The sun begins to fall away into twilight.%^RESET%^";
            break;
        case "twilight":
            __TimeOfDay = "night";
            msg = "%^BOLD%^BLUE%^Night darkens the whole of our reality.%^RESET%^";
            break;
    }
    message("environment", msg, users());
    if(__TimeOfDay == "night") __Almanac = almanac_data();
    ASTRONOMY_D->set_moon_light();
    next_change();
}

mapping almanac_data() {
    int temps, days, x, morn, even, tmp, hour, min;
    mapping ret;

    if((days= ((query_month(temps = time())*20) + query_day(temps))) ==
      LONGEST_DAY)
        return (["sunrise":({4,0}),"morning":({5,0}),"sunset":({18,0}),
          "twilight":({17,0}) ]);
    else if(days == SHORTEST_DAY)
      return (["sunrise":({6,0}),"morning":({7,0}),"sunset":({16,0}),
        "twilight":({15,0}) ]);
    else if(days > LONGEST_DAY) x = days-LONGEST_DAY;
    else x = days;
    tmp = 2*to_int(percent(x, LONGEST_DAY));
    if(days > LONGEST_DAY) {
        morn = 400+tmp;
        even = 1800-tmp;
    }
    else {
        morn = 600-tmp;
        even = 1600+tmp;
    }
    hour = atoi(("0"+morn)[0..1]);
    min = (atoi(("0"+morn)[2..3])*60)/100;
    ret = ([]);
    ret["sunrise"] = ({ hour, min });
    ret["morning"] = ({ hour+1, min });
    hour = atoi((even+"")[0..1]);
    min = (atoi((even+"")[2..3])*60)/100;
    ret["sunset"] = ({ hour, min });
    ret["twilight"] = ({ hour-1, min });
    return ret;
}

int query_minutes(int x) { return CURRENT_MINUTE(x); }

int query_day(int x) { return CURRENT_DAY(x)+1; }

string query_day_name(int x) { return DAYS[CURRENT_DAY(x)]; }

int query_hour(int x) { return CURRENT_HOUR(x); }

int query_year(int x) { return CURRENT_YEAR(x); }

int query_month(int x) { return CURRENT_MONTH(x)+1; }

string query_month_name(int x) { return MONTHS[(CURRENT_MONTH(x))]; }

int query_now() { return NOW(time()); }

int query_week(int x) { return CURRENT_WEEK(x)+1; }

string query_time_of_day() { return __TimeOfDay; }

int *query_sunrise() { return __Almanac["sunrise"]; }

int *query_sunset() { return __Almanac["sunset"]; }

int query_next_reboot() { return (time()-uptime())+(__RebootInterval*3600); }

int query_midnight_time(int mod)
{
	int x;
	x = (HOUR * 20) - (((int)EVENTS_D->query_hour(time()) + 1) * HOUR);
	x += (60 - (int)EVENTS_D->query_minutes(time()) + 1) * MINUTE;
	x += (18 - CURRENT_SECOND(time())) * SECOND;
	x += time();
	if(mod)
	{
		x += (HOUR * 20) * mod;
	}
	return x;
}


mapping query_events() { return __Events; }

int clean_up()
{
  return 0;
}
