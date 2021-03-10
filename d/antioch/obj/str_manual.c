// raises wisdom 1 point

inherit "/std/Object.c";
#include <std.h>
#include "/d/antioch/areadefs.h"
object owner;
void create(){
  ::create();
  set_name("manual of gainful exercise");
  set_id(({"manual of gainful exercise","book","manual"}));
  set_short("Manual of Gainful Exercise");
  set_long("This book will help you improve your strength if you read it.");
  set_weight(5);
    set_heart_beat(1);
}
void heart_beat(){
    object holder, env;
    env = ETO;
    if(!objectp(ETO)) return;
    if(objectp(env) && living(env) && interactive(env)){
	holder = env->query_name();
	} else {
	return;
    }
    if(holder != owner){
	tell_object(env,"The book realizes that you arent the one who retrieved it and vanishes!");
	TO->remove();
	} else {
	return;
    }
}
void init(){
  ::init();
    if(interactive(TP) && !owner) owner = TPQN;
  add_action("read_book","read");
}

int read_book(string str){
  int estr;
  if(!str||(str!="book"&&str!="manual"&&str!="manual of gainful exercise"))
    return 0;
  else{
    tell_object(TP,"You feel %^BOLD%^stronger %^RESET%^as you turn the pages.");
    tell_room(environment(TP),TPQCN+" looks stronger.",TP);
    if((int)TP->query_base_stats("strength")!=18)
      TP->set_stats("strength",1+TP->query_base_stats("strength"));
    else{
      estr=(int)TP->query_base_stats("exceptional_strength");
      if(estr==-1)
        TP->set_stats("exceptional_strength",1+random(50));
      if(estr==0)
        TP->set_stats("strength",1+TP->query_base_stats("strength"));
      if((estr>0)&&(estr<=50))
        TP->set_stats("exceptional_strength",51+random(25));
      if((estr>90)&&(estr<=99))
        TP->set_stats("exceptional_strength",00);
      if((estr>75)&&(estr<=90))
        TP->set_stats("exceptional_strength",91+random(9));
      if((estr>50)&&(estr<=75))
        TP->set_stats("exceptional_strength",76+random(15));
    }
    TO->remove();
    return 1;
  }
}
