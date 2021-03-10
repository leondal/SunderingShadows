// wander.c
// For Alliance Hall wanderers.
// Thorn - 000919

#include <std.h>

inherit NPC;

int counter;

void create(){
  ::create();
  call_out("start_wander",2);
}

void start_wander(){
  if(ETO && objectp(ETO))
  environment(TO)->init();
}

void heart_beat(){
  string *exits, *paths;
  int i,j;
  ::heart_beat();
  
  if(counter > 30 && objectp(TO) && objectp(ETO)){
    
    if((mixed *)TO->query_attackers() == ({})){
      exits = environment(TO)->query_exits();
      paths = ETO->query_destinations();
      
      i = sizeof(exits);
      if(exits && i){
        j = random(i);
        if(exits[j] != "enter" && exits[j] != "out" && exits[j] != "up" && exits[j] != "down")
        TO->force_me(exits[j]);
      }
    }
    counter = 0;
  }
  counter++;
}
