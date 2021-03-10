// wander.c for for the Azha type people
// Changed to make it so that wanderers 
// Won't end up in trainer areas.
// Thorn - 000919

#include <std.h>

inherit MONSTER;

int counter;

void create(){
  ::create();
  call_out("start_wonder",2);
}

void start_wonder(){
  if(ETO && objectp(ETO))
  environment(TO)->init();
}

void heart_beat(){
  string *exits;
  int i,j;
  ::heart_beat();
  
  if(counter > 30 && objectp(TO) && objectp(ETO)){
    
    if((mixed *)TO->query_attackers() == ({})){
      exits = environment(TO)->query_exits();
      
      i = sizeof(exits);
      if(exits && i){
        j = random(i);
        if(exits[j] != "enter" && exits[j] != "out" && exits[j] != "up" && exits[j] != "trainer")
        TO->force_me(exits[j]);
      }
    }
    counter = 0;
  }
  counter++;
}
