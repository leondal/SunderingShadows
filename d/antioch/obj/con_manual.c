// raises constitution 1 point

inherit "/std/Object.c";
#include <std.h>
object owner;
void create(){
  ::create();
  set_name("manual of bodily health");
  set_id(({"manual of bodily health","book","manual"}));
  set_short("Manual of Bodily Health");
  set_long("This book will help you improve your constitution if you read it.");
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
	tell_object(env,"The book realizes you are not the one who retrieve it and vanishes!");
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
  if(!str||(str!="book"&&str!="manual"&&str!="manual of bodily health"))
    return 0;
  else{
    tell_object(TP,"You feel your %^BOLD%^constitution %^RESET%^improving as you read.");
    TP->set_stats("constitution",1+TP->query_base_stats("constitution"));
    TO->remove();
    return 1;
  }
}
