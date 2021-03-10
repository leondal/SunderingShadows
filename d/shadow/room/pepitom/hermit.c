

#include <std.h>
#include "Pepitom.h"

inherit MONSTER;

string thisfile;

void create(){
        ::create();
   set_name("Hermit");
   set_id( ({ "hermit"}) );
   set_short(
@MELNMARN
A Small Hermit.

MELNMARN
   );
   set_long(
@MELNMARN
You see before you, a small hermit. 
He wears rags, and smells like he hasn't had a bath in months.
He stands in the corner cowering.
MELNMARN
	);	
   set("aggressive", 0);
   set_level(19);
   
   set_gender("male");
   set_alignment(2);
   set("race", "human");
   add_money("gold", random(500));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_exp(10);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   set_mp(random(500));
   set_max_mp(query_mp());
   call_out("start_it",2);

}

void start_it(){
	if(objectp(ETO))
        environment(TO)->init();
}

int test_heart(){ return 1;}

void heart_beat(){

	::heart_beat();

   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   if((hour(time()) == 10) && (base_name(ETO) != ROOMS+"shack.c")) {
   	force_me("up");
}
   if((hour(time()) != 10) && (base_name(ETO) != ROOMS+"basement.c")) {
      force_me("down");
   }
}

