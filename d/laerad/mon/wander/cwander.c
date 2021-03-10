//wander code for laerad
//replacing the wandering in HB to use the std move function & just overload
//move_around() with exclusion for the exits to be ignored.

#include <std.h>
#define ASDIR "/d/laerad/parnelli/asgard/"
#define NOGODIR ({"northwest", "northeast"})
#define NOGOROOM ({ASDIR+"as56", ASDIR+"as57", "/d/shadow/room/city/adventure.c","/d/dagger/avalounge" })

inherit WEAPONLESS;

int moving;

void create(){
   ::create();
//	call_out("start_wonder",1);
}

void start_wonder(){
    if(objectp(ETO))
        environment(TO)->init();
}
/*
void heart_beat(){
    ::heart_beat();
}
*/
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
//      if(exitn != ASDIR+"as56" && exitn != ASDIR+"as57")  {
      if(member_array(exitn,NOGOROOM) == -1) {
//         (environment(this_object())->query_exit(exits[j]))->init();
         exitn->init();
         TO->force_me(exits[j]);
      }
   }
   moving=0;
}