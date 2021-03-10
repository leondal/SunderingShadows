#include <std.h>
inherit "/std/riding_animal";

object ob;
object steppe_pony;

void create() {
   ::create();
   set_name("pony");
   set_id(({"steppe pony","steppe","pony"}));
   set_short("Steppe Pony");
   set_long("This little guy may be ugly but he is tough as nails and has excellent endurance.");
   set_race("equine");
   set_body_type("equine");
   set_alignment(5);
   set_size(1);
   set_hd(3,3);
   set_overall_ac(6);
   set_max_hp(80);
   set_hp(80);
   set_max_distance(36);
   set_max_sp(40);
    set_riding_level(8);
   set_sp(40);
   set_exp(65);
   set_value(200);
   set_enter_room(" rides in.");
   set_exit_room(" leaves riding a steppe pony.");
   set_vehicle_short("Steppe Pony");
}

void init() {
   ::init();
   add_action("mount_test", "mount");
}
int mount_test(string str) {
   	if(!str) return 0;
   	if(!id(str)) return 0;
   	if((string)TP->query_level() < 10) {
      	if(ob=present("steppe pony",environment(TP))) {
         		ob->force_me("say You are too %^RED%^advanced %^RESET%^to ride me!");
         		this_object()->buck_chance(100);
         		tell_room(environment(TO),"The Steppe Pony bucks "+TPQCN+" off.",TP);
         		write("The Steppe Pony bucks you off.");
         		return 1;
      	}
   	}
   	if((int)TP->query_size() > 2) {
      	if(ob=present("steppe pony",environment(TP))) {
         		ob->force_me("say You are too %^RED%^BIG %^RESET%^to ride me!");
         		this_object()->buck_chance(100);
         		tell_room(environment(TO),"The Steppe Pony bucks "+TPQCN+" off.",TP);
         		write("The Steppe Pony bucks you off.");
         		return 1;
      	}
   	}
}
