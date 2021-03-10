//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

object who;

void create() {
    ::create();
    set_name("fender");
    set_id( ({"xxfenderxx"}) );
    set_short("");
    set_long("");
    set_weight(0);
    set_heart_beat(1);   
}

void init(){
  ::init();
}

object query_who(){ return who; }
void set_who(object w){ who = w;}


void heart_beat(){
  int i, flag, len, count;
  object * wielded;
  string where, command, * ids;
  if (!objectp(who)){
    remove();
    return;
  }
  where = file_name(environment(who));
  len = strlen(TABAXROOM + "battlement")-1;
  if (TABAXROOM + "battlement" != where[0..len]){
    tell_object (who, "You have moved, and given up your vantage point for fending off ladders");
    remove();
    return;
  }
  wielded = who->query_wielded();
  if (sizeof(wielded)<1){
    tell_object(who, "You're not holding anything to fend ladders off with any more, so you give"
                    +" up.");
    TO->remove();
    return 1;
  }
  flag = 0;
  for (i=0;i<sizeof(wielded);i++){
    if (wielded[i]->id("pole")||wielded[i]->id("staff")||wielded[i]->id("polearm")){
       flag = 1;
       break;
    }
  }
  if (flag ==0){
    tell_object(who, "You're not holding anything to fend ladders off with any more, so you give"
                    +" up.");
    TO->remove();
    return 1;   
  }
  count = 0;
  switch((string)environment(who)->query_ladders()){
  case "a ladder":
    count  =1;
    break;
  case "two ladders":
    count  =2;
    break;
  case "three ladders":
    count  =3;
    break;
  case "several ladders":
    count  =4;
    break;
  }
  if (count == 0){
    return;
  }
  count = random(count)+1;
  ids = wielded[i]->query_id();
  command = "push ladder " + count + " with " + ids[0];
  who ->force_me("say I am going to '" + command +"'");
  who ->force_me(command);
}
