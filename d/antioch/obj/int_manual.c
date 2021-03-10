// raises intelligence 1 point

inherit "/std/Object.c";
#include <std.h>
#include "/d/antioch/areadefs.h"
object owner;

void create(){
  ::create();
  set_name("tome of clear thought");
  set_id(({"tome of clear thought","book","tome"}));
  set_short("Tome of Clear Thought");
  set_long("This book will help you improve your intelligence if you read it.");
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
	tell_object(env,"The book realizes you arent the one who retrieved and and vanishes!");
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
  if(!str||(str!="book"&&str!="tome"&&str!="tome of clear thought"))
    return 0;
  else{
    tell_object(TP,"Your %^BOLD%^intelligence %^RESET%^is growing with every word you read.");
    TP->set_stats("intelligence",1+TP->query_base_stats("intelligence"));
    TO->remove();
    return 1;
  }
}
