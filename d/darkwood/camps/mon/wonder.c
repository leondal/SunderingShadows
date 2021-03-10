#include <std.h>


#define NO "/d/shadow/room/meadows/meadow15"
#define NO2 "/d/shadow/room/meadows/meadow14"
#define NO3 "/d/shadow/room/meadows/plains9"
#define NOGO ({NO, NO2, NO3})

inherit MONSTER; 

void move_around() {
string *exits;
   string exitn;
   int j;
   if(!this_object()) return;
   if(!objectp(ETO)) return;
   ETO->setupExits();
   if(query_current_attacker()) return;
   if(environment(this_object()))
      exits = environment(TO)->query_exits();
   if(sizeof(exits)){
      j = random(sizeof(exits));
      exitn = (string)environment(TO)->query_exit(exits[j]);
      if(member_array(exitn,NOGO) == -1) {
         (ETO->query_exit(exits[j]) )->init();
         exitn->init(); 
         TO->force_me(exits[j]);
      }
   }
   moving=0;
}