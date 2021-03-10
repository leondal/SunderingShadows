//raises dexterity 1 point

inherit "/std/Object.c";
#include <std.h>
#include "/d/antioch/areadefs.h"

object owner;
void create(){
  ::create();
  set_name("manual of quickness in action");
  set_id(({"manual of quickness in action","book","manual"}));
  set_short("Manual of Quickness in Action");
  set_long("This book will help you improve your dexterity if you read it.");
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
	tell_object(env,"The book realizes you arent the one who retrieved it and vanishes!");
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
  if(!str||(str!="book"&&str!="manual"&&str!="manual of quickness in action"))
    return 0;
  else{
    tell_object(TP,"Reading through the book, you feel your %^BOLD%^dexterity %^RESET%^improving.");
    TP->set_stats("dexterity",1+TP->query_base_stats("dexterity"));
    TO->remove();
    return 1;
  }
}
