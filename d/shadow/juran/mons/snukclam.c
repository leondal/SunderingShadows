#include <std.h>
#include "../juran.h"

inherit NPC;

void create() {
   	::create();
   	set_name("snukclam");
   	set_id( ({"monster","snukclam","healer"}) );
   	set_short("Snukclam, Shaman healer");
   	set("aggressive", 0);
   	set_level(19);
  	set_long(
  		"Snukclam moves around very slowly tending his bubbling potions "+
  		"and his ointments.  He has to be the oldest, dirtiest looking "+
  		"orc you have ever seen, but he is also the only healer in town."
  	);
   	set_gender("male");
   	set_alignment(6);
   	set("race", "orc");
   	set_hd(19,1);
   	add_money("gold",random(100));
   	set_body_type("humanoid");
   	set_property("no attack", 1);
   	set_size(2);
   	set_hp(100);
   	set_max_hp(100);
   	set_stabbed_func( (: TO,"stab_func" :) );
   	set_exp(1000);
   	remove_std_db();
     	set_spoken("wizish");
   	set_nwp("healing",15);
}
void stab_func() {
   if(query_hp() < query_max_hp()/6) set_hp(query_max_hp()/6);
}
