#include <std.h>
inherit "/std/riding_animal";

object ob;
object riding_horse;

void create() {
   ::create();
   set_name("horse");
   set_id(({"riding horse","riding","horse"}));
   set_short("Riding Horse");
   set_long("This mount looks to be very sleek and quick, a very good choice.");
   set_race("equine");
   set_body_type("equine");
   set_alignment(5);
   set_hd(3,2);
   set_overall_ac(7);
   set_size(3);
   set_max_hp(80);
   set_hp(80);
   set_max_distance(48);
   set_max_sp(50);
    set_riding_level(8);
   set_sp(50);
   set_exp(65);
   set_value(75);
   set_enter_room(" rides in.");
   set_exit_room(" leaves riding a Horse.");
   set_vehicle_short("Riding Horse");
}
void init() {
   ::init();
   add_action("mount_test", "mount");
}
int mount_test(string str) {
   	if(!str) return 0;
   	if(!id(str)) return 0;
   	if(((string)TP->query_level() < 5) ||(TP->query_level() > 10)) {
      	if(ob=present("riding horse",environment(TP))) {
         		ob->force_me("say You may %^RED%^NOT %^RESET%^ride me!");
         		this_object()->buck_chance(100);
         		tell_room(environment(TO),"The Riding Horse bucks "+TPQCN+" off.",TP);
         		write("The Riding Horse bucks you off.");
         		return 1;
      	}
   	}
}
