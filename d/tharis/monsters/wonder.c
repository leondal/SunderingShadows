//wonder.c for tharis people
//overloaded move_around per Garrett's suggestion to get rid of one of the
//layers of calling heart_beat & added checks for valid object & ETO-Styx 5/15/02

#include <std.h>
#define THDIR "/d/tharis/road/"

inherit MONSTER;

int moving;

void create() {
   ::create();
   set_moving(1);
   set_speed(80);
//   call_out("start_wonder",2);
}

void start_wonder() {
   if(objectp(ETO))
      environment(TO)->init();
}

int test_heart() {return 1;}

/*  Replacing this with over-loading move_around to cut down on bugs.
void heart_beat() {
   string *exits, exitn;
   int i,j;
   ::heart_beat();

   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if(count > 20 && objectp(TO) && objectp(ETO)) {
      if((mixed *)TO->query_attackers() == ({})) {
         exits = environment(TO)->query_exits();

         i = sizeof(exits);
         if(exits && i) {
            j = random(i);
            if(!objectp(TO)) return;
            if(ETO->invis_exit(exits[j])) return;
            exitn = (string)(environment(TO)->query_exit(exits[j]));
            if(exits[j] != "estair" && exits[j] != "wstair" && exitn  != THDIR+"road9.c" && exitn != THDIR+"wroad1" && exitn != THDIR+"eroad1" )
               TO->force_me(exits[j]);
         }
      }
      count = 0;
   }
   count++;
}
*/
void move_around() {
//   ::move_around();   don't think I need this but might
   string *exits;
   string exit, exitn;
   int i, j;

   if(!TO) return;
   if(!objectp(ETO) || !objectp(TO)) return;
   ETO->setupExits();
   if(query_current_attacker()) return;

   exits = environment(TO)->query_exits();
   i = sizeof(exits);
   if(exits && i) {
       j = random(i);
       if(ETO->invis_exit(exits[j])) return;
       exitn = (string)(environment(TO)->query_exit(exits[j]));
       if(exits[j] != "estair" && exits[j] != "wstair" && exitn  != THDIR+"road9.c" && exitn != THDIR+"wroad1" && exitn != THDIR+"eroad1" ) {
         (ETO->query_exit(exit))->init();
         command(exits[j]);
       }
   }
   moving=0;
}