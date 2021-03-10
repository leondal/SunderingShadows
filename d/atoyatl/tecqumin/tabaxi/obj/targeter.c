//Coded by Lujke


#include <std.h>
#include "../../tecqumin.h"
inherit OBJECT;

string targ;
object who, here, targ_loc;

void create() {
    ::create();
    set_name("targetter");
    set_id( ({"xxtargetterxx"}) );
    set_short("");
    set_long("");
    set_weight(0);
    set_heart_beat(1);   
}

void init(){
  ::init();
}

object query_who(){ return who; }
string query_targ(){return targ;}
object query_here(){return here;}
object query_targ_loc(){return targ_loc;}
void set_who(object w){ who = w;}
void set_targ(string t){ targ = t;}
void set_here(object h){ here = h;}
void set_targ_loc(object t){ targ_loc = t;}



void heart_beat(){
  int i, flag;
  object * wielded, target;
  string * exits, newdir;
  if (!objectp(targ_loc)||!objectp(who)||!objectp(here)){
    remove();
    return;
  }
  if (!present(who, here)){
    tell_object (who, "You have moved, and given up your vantage point for shooting");
    remove();
    return;
  }
  wielded = who->query_wielded();
  if (sizeof(wielded)<1){
    tell_object(who, "You're not holding anything to shoot at your target with any more, so you give"
                    +" up.");
    TO->remove();
    return 1;
  }
  flag = 0;
  for (i=0;i<sizeof(wielded);i++){
    if (wielded[i]->id("bow")||wielded[i]->id("sling")){
       flag = 1;
       break;
    }
  }
  if (flag ==0){
    tell_object(who, "You're not holding anything to shoot at your target with any more, so you give"
                    +" up.");
    TO->remove();
    return 1;   
  }
  target = present(targ, targ_loc);
  if (objectp(target)){
/*    exits = targ_loc->query_exits();
    if (sizeof(exits)<1){
      who->force_me("say %^BOLD%^%^CYAN%^no exits in target room");
      return;
    }*/
    here->add_exit(file_name(targ_loc), "downwards");
    targ_loc->add_exit(file_name(here), "above");
    present(targ, targ_loc)->set_paralyzed(10, "You are stunned after being shot by an arrow");
    who->force_me("shoot " + targ + " downwards 1");
    here->remove_exit("downwards");
    targ_loc->remove_exit("above");
    wielded[0]->remove_call_out("move_monster");
    if (present(target, here)){
      target->move(targ_loc);
      tell_room(targ_loc, target->QCN + " can't find a way to reach " + target->QP + " attacker!");
    }
    present(targ, targ_loc)->remove_paralyzed();
  }
}
