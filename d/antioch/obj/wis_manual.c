// raises wisdom 1 point

inherit "/std/Object.c";
#include <std.h>
#include "/d/antioch/areadefs.h"
object owner;

void create(){
  ::create();
  set_name("tome of understanding");
  set_id(({"tome of understanding","tome","book"}));
  set_short("Tome of Understanding");
    set_obvious_short("A large Tome");
    set_long("This is a large Tome covered in finely detailed images of wisdom and sense.");
  set_weight(5);
    //set_heart_beat(1);
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
  if(!str||(str!="book"&&str!="tome"&&str!="tome of understanding"))
    return 0;
  else{
    tell_object(TP,"As you read this book, you feel %^BOLD%^wiser%^RESET%^.");
    tell_room(TO,TPQCN+" looks wiser.",TP);
    TP->set_stats("wisdom",1+TP->query_base_stats("wisdom"));
    TO->remove();
    return 1;
  }
}
