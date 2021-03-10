//   inhertable townsman
//   just like a monster, only has a list of timed events.
//   so that shop keepers can wander from their house to their shop
//   etc.

//   mapping.. indexed by time, returns a string

//   So set_event("6:30","say Hi!");  
//     will make the object say Hi! at 6:30.  
//   And set_event("6:31","fun my_function");
//     will make the object call the function my_function at 6:31.
//   And set_event("6:31",(: this_player(), "my_function" :));
//     will make the object call the function my_function at 6:31.

#include <std.h>
#include <move.h>
#include <objects.h>
#include <daemons.h>

inherit WEAPONLESS;

mapping events;      // events["2:15"]
string *path;
int do_path,path_current,path_dest;
int path_speed,path_temp;
int oldtime;
string *locations;
string location;


void set_path_speed(int x);
int query_path_speed();
void set_event(string time, string event);
string query_event(string time);
int is_evil(string name);
int is_good(string name);
int is_unlawful(string name);

void create() {
   ::create();
   set_property("bounty hunter",1);
    set_use_monster_flag(1);
   events = ([ ]);
}

void init() {
   ::init();
}

void set_path_speed(int x) {path_speed = x;}
int query_path_speed() {return path_speed;}

void check_events() {
   int time,time2;
   int tmp;
   string times,fun;
   object o;

   tmp = EVENTS_D->check_time();
   time = EVENTS_D->query_hour( tmp );
   time2 = EVENTS_D->query_minutes(tmp);
   times = sprintf("%d:%d",time,time2);
   if(!events[times]) {
      return 1;
   }
   if(functionp(events[times])) {
      message("event",(string)((* events[times])(times)),ETO);
      return 1;
   }
   if(pointerp(events[times])) {
      // process path
      path = events[times];
      do_path = 1;
      path_current = 0;
      path_temp = 1;
      path_dest = sizeof(path);
      return 1;
   }
   if(stringp(events[times])) {
      if(sscanf(events[times],"fun %s",fun)) {
         call_other(this_object(),fun);
         return 1;
      }
      command(events[times]);
   }
}

void do_path() {
   if(!do_path) return 1;
   path_temp++;
   if(path_temp > path_speed) {
      if(path_current < sizeof(path)) {
         command(path[path_current]);
         path_current++;
         path_temp = 1;
      } else {
         do_path = 0;
         path_current = 0;
      }
   }
}

string query_event(string time) {
   return events[time];
}

void set_event(string time, mixed str) {

   events[time] = str;
}

void heart_beat() {

   string lang, pre;
   string fname, s1, s2;
   int time,tmp;

   ::heart_beat();
   if(!objectp(TO)) return;
   fname = file_name(this_object());
   if(!sscanf(fname,"%s#%s",s1,s2)) {
      return 1;
   }
   do_path();
   tmp = EVENTS_D->check_time();
   time = EVENTS_D->query_minutes(tmp);
   if(time != oldtime) {
      check_events();
   }
   oldtime = time;
   player_age +=2;
   ok_to_heal ++;
}

void set_locations(string * locs){
   locations = locs;
}

string * query_locations(){
   return locations;
}

string query_location(){
   return location;               
}

void setupStart(){
   location = locations[random(sizeof(locations))];
   "daemon/monster_d"->place_mon_at(location,base_name(TO));
}

int is_townsman(){
   return 1;
}

int should_interact(object ob){
   int align;
   string name;
   
   string *evil, * good,*personal,*legal;

   if(!ob->is_player() && member_array(ob->query_race(),RACE_D->query_races()) == -1){
      force_me("say We don't serve your kind around here.");
      return 0;
   }

   if(TO->query_property("always interact"))
      return 1;

   return 1; // putting this in to disable mycause reactions until the faction system is done properly. N, 12/12.
/*   name = ob->query_name();
   align = TO->query_alignment();
   if (align == 0) {
      align = 5;
   }
   evil = KILLING_D->query_evil_bounties();
   good = KILLING_D->query_good_bounties();
   personal = KILLING_D->query_personals();
   legal = KILLING_D->query_bounties();
   switch (align) {
   case 1:
      return !(is_evil(name) || is_unlawful(name));
      break;

   case 2:

      return !(is_evil(name) || is_unlawful(name) || is_good(name));
      break;

   case 3:
      return !(is_good(name) || is_unlawful(name));
      break;
   case 4:
      return !(is_evil(name));
      break;
   case 5:
      return !(is_evil(name) || is_unlawful(name) || is_good(name));
      break;
   case 6:
      return !(is_good(name));
      break;
   case 7:
      return !(is_evil(name));
      break;
   case 8:
      return !(is_evil(name) || is_evil(name));
      break;
   case 9:
      return !(is_good(name));
      break;
   }*/
}


int is_evil(string name){
      
   return (member_array(name, KILLING_D->query_evil_bounties()) != -1);
}

int is_good(string name){
   
   return (member_array(name, KILLING_D->query_good_bounties()) != -1);
}

int is_unlawful(string name){

   return (member_array(name, KILLING_D->query_bounties()) != -1);
}



