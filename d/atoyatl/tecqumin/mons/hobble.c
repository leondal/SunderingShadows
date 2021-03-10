//Coded by Lujke
#include <std.h>
#include "../tecqumin.h"
inherit MONSTER;

object followee;
int last_move;

void create()
{
    ::create();
      set_property("not random monster", 1);
    set_class("fighter");
    set_mlevel("fighter",350);
    set_level(350);
    set_guild_level("fighter",350);

    set_name("a leg tie that is hobbling its victim");
    set_property("no detect",1);
    set_id(({"xxhobblexx"}));
    set_short("");
    set_true_invis();
    add_limb("body","",0,0,0);
}

void init()
{
  ::init();

}

int move(mixed dest){
  object snag;
  int result;
  if (objectp(followee)){
    if (time()<last_move + 4){
      tell_object(followee, "Trying to run too fast with the "+query_short() 
                + " wrapped around your legs, you trip up!");
      tell_room(ETP, "%^ORANGE%^" +followee->QCN 
                   + "%^RESET%^%^ORANGE%^ trips and falls!%^RESET%^",
                     followee);
      followee->set_tripped(1,"You are trying to stand!");

    }
//    tell_object(followee, "Okay, you can move this time current time is:
// " + time() + "\nLast move time was: " + last_move);
  }
  result =  ::move(dest);
//  tell_object(followee, "Setting last move time to current time: " 
//                                                        + time());
  last_move = time();
  return result;
}

void set_followee(object ob){
  ob->add_follower(TO);
  followee = ob;
}

object query_followee(){
  return followee;
}

void heart_beat(){
  ::heart_beat();
  if (!objectp(followee)){
    remove();
  }
  if (!objectp(ETO)){
    return;
  }
  if (!present(followee, ETO)){
    if (!objectp(environment(followee))){
      return;
    }
    ::move(environment(followee));
    followee->add_follower(TO);
  }
}
