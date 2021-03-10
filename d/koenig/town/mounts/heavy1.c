#include <std.h>
inherit "/std/riding_animal";

object ob;
object heavy_warhorse;

void create() {
   ::create();
   set_name("horse");
   set_id( ({"heavy warhorse","horse","warhorse"}));
   set_short("Heavy Warhorse");
   set_long("This powerful animal is the most breath-taking of them all by far!");
   set_race("equine");
   set_gender("male");
   set_body_type("equine");
   set_alignment(5);
   set_hd(4,4);
   set_overall_ac(7);
   set_max_hp(35);
   set_hp(35);
   set_size(3);
   set_max_distance(28);
   set_riding_level(15);
   set_max_sp(30);
   set_sp(30);
   set_exp(120);
   set_value(400);
   set_enter_room(" rides in.");
   set_exit_room(" leaves riding a heavy warhorse!");
   set_vehicle_short("Heavy Warhorse");
}

void init() {
   ::init();
   add_action("mount_test", "mount");
}
int mount_test(string str) {
   	if(!str) return 0;
   	if(!id(str)) return 0;
   	if(((string)TP->query_level() < 10)) {
      	if(ob=present("heavy warhorse",environment(TP))) {
         		ob->force_me("say You are %^RED%^NOT %^RESET%^advanced enough to ride "+
         			"the likes of me!");
         		this_object()->buck_chance(100);
         		tell_room(environment(TO),"The Heavy Warhorse bucks "+TPQCN+" off.",TP);
         		write("The Heavy Warhorse bucks you off.");
         		return 1;
      	}
   	}
}
