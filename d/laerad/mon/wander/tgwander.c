//wander code for laerad
//replacing the wandering in HB to use the std move function & just overload
//move_around() with exclusion for the exits to be ignored.  Styx 2/02

#include <std.h>
#define SYSDIR "/d/laerad/parnelli/systyquah/"
#define NOGOROOM ({SYSDIR+"sys001", SYSDIR+"sys021", })
inherit WEAPONLESS;

int count;

void create(){
        ::create();
        set_moving(1);
        set_speed(25);
}

void heart_beat(){
    ::heart_beat();
}

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
      if(member_array(exitn,NOGOROOM) == -1) {
         exitn->init();
         TO->force_me(exits[j]);
      }
   }
   moving=0;
}