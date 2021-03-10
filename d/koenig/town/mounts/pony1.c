#include <std.h>
inherit "/std/riding_animal";

object ob;
object pony;


void create() {
   ::create();
   set_name("pony");
   set_id(({"pony"}));
   set_short("Pony");
   set_long("This little mount shouldn't be underestimated, he'll get you where you want to go.");
   set_race("equine");
   set_body_type("equine");
   set_alignment(5);
   set_hd(1,1);
   set_overall_ac(7);
   set_max_hp(50);
   set_hp(50);
   set_size(1);
   set_max_distance(24);
      set_riding_level(5);
   set_max_sp(25);
   set_sp(25);
   set_exp(35);
   set_value(50);
   set_enter_room(" rides in.");
   set_exit_room(" leaves riding a pony.");
   set_vehicle_short("Pony");
}

void init() {
   ::init();
   add_action("mount_test", "mount");
}
int mount_test(string str) {
   	if(!str) return 0;
   	if(str != "pony") return 0;
   	if((string)TP->query_level() > 5) {
      	if(ob=present("pony",environment(TP))) {
         		ob->force_me("say You are too %^RED%^advanced %^RESET%^to ride me!");
         		this_object()->buck_chance(100);
         		tell_room(environment(TO),"The Pony bucks "+TPQCN+" off.",TP);
         		write("The Pony bucks you off.");
         		return 1;
     		}
   	}
   	if((int)TP->query_size() > 2) {
      	if(ob=present("pony",environment(TP))) {
         		ob->force_me("say You are too %^RED%^BIG %^RESET%^to ride me!");
         		this_object()->buck_chance(100);
         		tell_room(environment(TO),"The Pony bucks "+TPQCN+" off.",TP);
         		write("The Pony bucks you off.");
         		return 1;
      	}
   	}
}
