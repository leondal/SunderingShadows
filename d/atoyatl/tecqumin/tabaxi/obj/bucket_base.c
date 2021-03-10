#include <std.h>
#include <daemons.h>
#include <magic.h>
#include "../../tecqumin.h"

inherit ROOM;

object catapult;

void create(){
  ::create();
  set_short("In the bucket of a catapult");
  set_long( (: TO, "long_desc" :) );
  set_exits( (["out": TABAXROOM + "southeast_corner" ]) );
  set_search("default", "You can see a small inscription scratched into the bood of the bucket. You"
                       +" could read the inscription.");
}

void init(){
  ::init();
  add_action("read_me", "read");
  add_action("launch_me", "launch");
}

string long_desc(){
  object env;
  string desc;
  desc = "You are in the bucket of a catapult. This may not be your greatest idea yet. ";
  if (objectp(catapult)){
    env = environment(catapult);
    if (objectp(env)){
      desc += "Outside, you can see:\n";
      desc += env->query_long();
    }
  }
  desc += "If you wanted, you could %^BOLD%^%^YELLOW%^<launch>%^RESET%^ yourself, by releasing the"
         +" catapult.\n";
  return desc;
}

object query_catapult(){
  return catapult;
}

void set_catapult(object cat){
  catapult = cat;
}

int read_me(string str){
  if (str != "inscription" && str != "the inscription"){
    return 0;
  }
  tell_object(TP,  "The manufacturer accepts no responsibility for the health and wellbeing of people"
                 +" or creatures fired from this catapult");
  return 1;
}

int launch_me(string str){
  if (!objectp(catapult)){
    tell_room(TO, "There seems to be a problem with the catapult this room is linked to. Please tell a"
                 +" wiz or a draconian, or send a bug report.");
  }
  catapult->fire_me("catapult");
}