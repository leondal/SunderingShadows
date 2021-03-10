//wonder.c for tharis people

#include "/d/islands/tonerra/areadefs.h"
#include <std.h>

inherit WEAPONLESS;

int count;

void create(){
   ::create();
   call_out("start_wander",2);
}

void start_wander(){
   if(objectp(ETO))
      environment(TO)->init();
}

int test_heart(){ return 1;}

void heart_beat(){
   string *exits, exitn;
   int i,j;

   ::heart_beat();
   if(!objectp(TO)) return;
   if(count > 20 && objectp(TO) && objectp(ETO)){
      if((mixed *)TO->query_attackers() == ({})){
         exits = environment(TO)->query_exits();
         i = sizeof(exits);
         if(exits && i){
            j = random(i);
            exitn = (string)(environment(TO)->query_exit(exits[j]));
            if(exitn != MONASTERY+"entrance.c")
              TO->force_me(exits[j]);
	 }
      }
      count = 0;
   }
   count++;
}
