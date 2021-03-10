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
  ::init();
  add_action("controls","controls");
  add_action("launch","launch");
  add_action("sail","sail");
  add_action("exit","exit");
  add_action("look","look");
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

void exit(string str) {
  if(environment(environment(this_object()))) {
    write("You climb out of the boat.");
    this_player()->move_player(environment(environment(this_object())));
    return 1;
  }
  write("You cannot exit here!");
  return 1;
}

void controls(string str) {
  write("%^BLUE%^%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^");
  write(SIDE+" COMMAND               EXAMPLE           DESCRIPTION          "+SIDE);
  write(SIDE+"                                                              "+SIDE);
  write(SIDE+"  sail <dir>            sail west         Moves the boat      "+SIDE);
  write(SIDE+"  peek <dir>            peek west         Look at a room afar "+SIDE);
  write("%^BLUE%^%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=%^RESET%^");  
  return 1;
}

void launch(string str) {
  object ob, src, dest;
  string temp;
  
  ob = environment(this_object()); // boat
  src = environment(ob);           // dock
  temp = src->query_launch_room();
  if(!temp) {
    write("This dock has no body of water attached!");
    return 1;
  }  
  dest = find_object_or_load(temp);
  if(!dest) {
    write("This dock has no body of water attached!");
    return 1;
  }
  ob->move(dest);
  write("You launch your ship from dock!");
  write("%^WHITE%^%^BOLD%^Outside the ship you see:%^RESET%^");
  describe_current_room(1);
  tell_room(src,capitalize(ob->query_name())+" launches from dock!");
  return 1;
}

void sail(string str) {
  object ob;
  object src, dest;
  
  ob = environment(this_object());  // ob is the boat itself
  src = environment(ob);            // src is the water
  if(!str) {
    write("Sail which way?");
    return 1;
  }
  if(!src->query_exit(str)) {
    write("You cannot sail that way!");
    return 1;
  }
  if(src->query_dock()) {
    write("You cannot move while in dock!");
    return 1;
  }
  dest = find_object_or_load((string)src->query_exit(str));
  if( (!dest->query_water()) && (!dest->query_dock()) ) {
    write("You cannot sail there!");
    return 1;
  }
  if(dest->query_water()) {
    ob->move(dest);
    write("You sail "+str+"!");
    if(!enclosed) {
      write("%^WHITE%^%^BOLD%^Outside the ship you see:%^RESET%^");
      describe_current_room(1);
      write("%^WHITE%^%^BOLD%^Inside the ship you see:%^RESET%^");
      this_player()->describe_current_room(1);
    }
    return 1;
  }
  if(dest->query_dock()) {
    write("You sail "+str+", into the dock and maneuver yourself to a stop.");
    ob->move(dest);
    write("%^WHITE%^%^BOLD%^Outside the ship you see:%^RESET%^");
    describe_current_room(1);
    write("%^WHITE%^%^BOLD%^Inside the ship you see:%^RESET%^");
    this_player()->describe_current_room(1);
    return 1;
  }
  write("There is land in that direction, but no dock to dock at.");
  return 1;
}