// raises charisma 1 point

inherit "/std/Object.c";
#include <std.h>

object owner;
void create(){
  ::create();
  set_name("tome of leadership and influence");
  set_id(({"tome of leadership and influence","tome","book"}));
  set_short("Tome of Leadership and Influence");
  set_long("This book will help improve your charisma if you read it.");
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
	return ;
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
  if(!str||(str!="book"&&str!="tome"&&str!="tome of leadership and influence"))
    return 0;
  else{
    tell_object(TP,"You feel more %^BOLD%^charismatic %^RESET%^as you read the book.");
    TP->set_stats("charisma",1+TP->query_base_stats("charisma"));
    TO->remove();
    return 1;
  }
}
