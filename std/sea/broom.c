#include <daemons.h>
#define TO this_object()

inherit "/std/room";

#define SIDE "%^BLUE%^%^BOLD%^|%^RESET%^"

int enclosed;
int move_ok() { return 1; }

create() {
  ::create();
  set_weight(1);
  set_enclosed(0);
}

init() {
  string str;
  string *e;
  int x;
  
  ::init();
  add_action("look","look");
  e = query_exits();
  for(x=0; x<sizeof(e); x++) {
    add_action("go_dir",e[x]);
  }  
}

void go_dir(string str) {
  string dir,temp;
  object ob;
  
  dir = query_verb();
  temp = query_exit(dir); 
  ob = environment(this_object())->query_room(temp);
  if(!ob) {  
    write("That room is not available!  Tell a wiz!"); 
    return 1;
  }  
  this_player()->move_player(ob);  
  return 1;
}

int receive_objects() { return 1; }

int query_enclosed() { return enclosed; }
void set_enclosed(int x) { enclosed = x; }

void describe_current_room(int verbose) {
    object env;
    string borg;
    mixed tmp;
    int light;

    env = environment(environment(this_object()));
    if(wizardp(this_player())) borg = file_name(env)+"\n";
    else borg = "";
    if((light=effective_light(this_player())) > 6 || light < 1) {
        if(light > 6) borg += "It is too bright to see.";
        else if(light > -2) borg += "It is dark.";
        else if(light > -4) borg += "It is quite dark.";
        else if(light > -6) borg += "It is very dark.";
        else borg += "It is completely dark.";
        message("room_description", borg, this_player());
        if(stringp(tmp=(string)env->query_smell("default")))
         message("smell", tmp, this_object());
        else if(functionp(tmp))
          message("smell",(string)((*tmp)("default")), this_object());
        if(stringp(tmp=(mixed)env->query_listen("default")))
          message("listen", tmp, this_object());
        else if(functionp(tmp)) message("listen", (string)((*tmp)("default")), this_object());
        if(stringp(tmp=(string)WEATHER_D->Check_Weather(TO)))
          message("weather", "%^MAGENTA%^"+tmp+"%^RESET%^", this_player());
       return;
    }
    else if(light > 3) borg += "It is really bright.\n";
    borg += (verbose ? (string)env->query_long(0)+" " :
      (string)env->query_short());
    message("room_description", borg, this_player());
    if(!verbose)
      message("room_exits", (string)env->query_short_exits(), this_player());
    if(verbose && stringp(tmp=(mixed)env->query_smell("default")))
      message("smell", tmp, this_player());
    else if(verbose && functionp(tmp))
      message("smell",(string)((*tmp)("default")), this_player());
    if(verbose && stringp(tmp=(mixed)env->query_listen("default")))
        message("listen", tmp, this_player());
    else if(verbose && functionp(tmp))
      message("listen", (string)((*tmp)("default")), this_player());
    if(stringp(tmp=(string)WEATHER_D->Check_Weather(TO)))
          message("weather", "%^MAGENTA%^"+tmp+"%^RESET%^", this_player());
    if(verbose && (tmp=(string)env->query_long_exits()) && tmp != "")
      message("room_exits", sprintf("\n%s\n", tmp), this_player());
    if((tmp=(string)env->describe_living_contents(({this_player()})))!="")
      message("living_item", tmp, this_player());
    if((tmp=(string)env->describe_item_contents(({})))!="")
      message("inanimate_item", tmp, this_player());
}

void look(string str) {
  object ob, src;
  
  if(str) return 0;
  if(!enclosed) {
    write("%^WHITE%^%^BOLD%^Outside the ship you see:%^RESET%^");
    describe_current_room(1);
    write("%^WHITE%^%^BOLD%^Inside the ship you see:%^RESET%^");
  }
  return 0;
}
