#include <conf.h>
#include <security.h>
#include <objects.h>
#include <daemons.h>
#include <save.h>

#define WATCHIPDIR "watch/iplogs/"
#define BANISH_IP_LOG "player/ip_denied"

string *__Names, *__Sites, *__WatchNames, *__WatchSites, *__Block;
string *__Allowed, *__Guests, *__IllegalSubStrings, *__Retired;

void create() {
    seteuid(getuid());
    __Names = ({});
    __Sites = ({});
    __Block = ({});
    __Retired = ({});
    __WatchNames = ({});
    __WatchSites = ({});
    __Allowed = ({});
    __Guests = ({});
    __IllegalSubStrings = ({});
    if(file_exists(SAVE_BANISH+".o")) restore_banish();
}

protected int valid_access(object ob) {
    return (geteuid(ob) == UID_BANISH || geteuid(ob) == UID_ROOT);
}

void block_site(string str) {
    if(!valid_access(previous_object())) return;
    __Block = distinct_array(__Block + ({ str }));
    save_banish();
}

void unblock_site(string str) {
    if(!valid_access(previous_object())) return;
    __Block -= ({ str });
    save_banish();
}

string *query_blocked() {
    if(!valid_access(previous_object())) return ({});
    return __Block;
}
void register_site(string str) {
    if(!valid_access(previous_object())) return;
    __Sites = distinct_array(__Sites + ({ str }));
    save_banish();
}

void unregister_site(string str) {
    if(!valid_access(previous_object())) return;
    __Sites -= ({ str });
    save_banish();
}

string *query_registered() {
    if(!valid_access(previous_object())) return ({});
    return __Sites;
}

void banish_name(string str) {
    if(!valid_access(previous_object())) return;
    __Names = distinct_array(__Names + ({ lower_case(str) }));
    save_banish();
}

void unbanish_name(string str) {
    if(!valid_access(previous_object())) return;
    __Names -= ({ lower_case(str) });
    save_banish();
}

string *query_banished() {
    if(!valid_access(previous_object())) return ({});
    return __Names;
}

void retire_name(string str) {
    if(!valid_access(previous_object())) return;
    __Retired = distinct_array(__Retired + ({ lower_case(str) }));
    save_banish();
}

void unretire_name(string str) {
    if(!valid_access(previous_object())) return;
    __Retired -= ({ lower_case(str) });
    save_banish();
}

string *query_retired() {
    if(!valid_access(previous_object())) return ({});
    return __Retired;
}

void watch_site(string str) {
    if(!valid_access(previous_object())) return;
    __WatchSites = distinct_array(__WatchSites + ({ str }));
    save_banish();
}

void unwatch_site(string str) {
    if(!valid_access(previous_object())) return;
    __WatchSites -= ({ str });
    save_banish();
}

string *query_watched_sites() {
    if(!valid_access(previous_object())) return ({});
    return __WatchSites;
}

void watch_name(string str) {
    if(!valid_access(previous_object())) return;
    __WatchNames = distinct_array(__WatchNames + ({ lower_case(str) }));
    save_banish();
}

void unwatch_name(string str) {
    if(!valid_access(previous_object())) return;
    __WatchNames -= ({ lower_case(str) });
    save_banish();
}

string *query_watched_names() {
    if(!valid_access(previous_object())) return ({});
    return __WatchNames;
}

void allow_name(string str) {
    if(!valid_access(previous_object())) return;
    __Allowed = distinct_array(__Allowed + ({ lower_case(str) }));
    save_banish();
}

void unallow_name(string str) {
    if(!valid_access(previous_object())) return;
    __Allowed -= ({ lower_case(str) });
    save_banish();
}

string *query_allowed() {
    if(!valid_access(previous_object())) return ({});
    return __Allowed;
}

void set_illegal_substring(string str) {
    if(!valid_access(previous_object())) return;
    __IllegalSubStrings = distinct_array(__IllegalSubStrings +
      ({ lower_case(str) }));
    save_banish();
}

void remove_illegal_substring(string str) {
    if(!valid_access(previous_object())) return;
    __IllegalSubStrings -= ({ lower_case(str) });
    save_banish();
}

string *query_illegal_substrings() {
    if(!valid_access(previous_object())) return ({});
    else return __IllegalSubStrings;
}

void add_guest(string str) {
    if(!valid_access(previous_object())) return;
    __Guests = distinct_array(__Guests + ({ lower_case(str) }));
    save_banish();
}

void remove_guest(string str) {
    if(!valid_access(previous_object())) return;
    __Guests -= ({ lower_case(str) });
    save_banish();
}

string *query_guests() {
    if(!valid_access(previous_object())) return ({});
    else return __Guests;
}

protected void save_banish() {
    seteuid(UID_SECURE_DAEMONSAVE);
    save_object(SAVE_BANISH);
    seteuid(getuid());
}

protected void restore_banish() {
    seteuid(UID_SECURE_DAEMONSAVE);
    restore_object(SAVE_BANISH);
    seteuid(getuid());
}

int is_guest(string str) {
    if(base_name(previous_object()) != OB_LOGIN) return 0;
    else return (member_array(lower_case(str), __Guests) != -1);
}

int valid_name(string str) {
    int i, x;

    if(base_name(previous_object()) != OB_LOGIN) return 0;
    if(member_array(str, __Names) != -1) return 0;
    i = sizeof(__IllegalSubStrings);
    while(i--) if(strsrch(str, __IllegalSubStrings[i]) != -1) return 0;
    if((x = strlen(str)) > MAX_USER_NAME_LENGTH) return 0;
    if(x < MIN_USER_NAME_LENGTH) return 0;
    for(i=0; i<x; i++)
      if(str[i] < 'a' || str[i] > 'z') return 0;
    return 1;
}
int block_access(string ip) {
  if(match_ip(ip, __Block)) {
    seteuid(UID_LOG);
    log_file(BANISH_IP_LOG, sprintf("Discarded luser (block via IP) from from %s at %s.\n", ip, ctime(time())));
    seteuid(getuid());
    return 0;
  } else {
    return 1;
  }
}
int allow_logon(string nom, string ip) {
    if(base_name(previous_object()) != OB_LOGIN) return 0;
    if(member_array(nom, __WatchNames) != -1) {
        seteuid(UID_LOG);
        log_file("watch/names", sprintf("%s from %s at %s.\n", nom, ip,
          ctime(time())));
        seteuid(getuid());
    }
    if(match_ip(ip, __WatchSites)) {
        seteuid(UID_LOG);
        log_file(WATCHIPDIR +ip, sprintf("%s at %s.\n", nom, ctime(time())));
        seteuid(getuid());
    }
    if(member_array(nom, __Allowed) != -1) {
        seteuid(UID_LOG);
        log_file("watch/allowed", sprintf("%s from %s at %s.\n", nom, ip,
          ctime(time())));
        save_banish();
        return 1;
    }
    if(match_ip(ip, __Sites)) {
        if(user_exists(nom)) {
            seteuid(UID_LOG);
            log_file(WATCHIPDIR+ip, sprintf("%s allowed in from %s at %s.\n", nom, ip,
              ctime(time())));
            seteuid(getuid());
            return 1;
// Changed from 0 to 1 to allow players with existing characters to keep playing... - garrett
        }
        else {
            seteuid(UID_LOG);
            log_file(WATCHIPDIR+ip, sprintf("%s failed from %s at %s.\n", nom, ip,
              ctime(time())));
            seteuid(getuid());
            return 0;
        }
    }
    return 1;
}


protected int match_ip(string ip, string *sites) {
    string a, b;
    int i;

    if(!(i = sizeof(sites))) return 0;
    while(i--) {
        if(sites[i] == ip) return 1;
        if(sscanf(sites[i], "%s.*", a) && sscanf(ip, a+"%s", b))
          return 1;
    }
    return 0;
}
