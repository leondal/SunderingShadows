#include <std.h>
inherit "/std/riding_animal";

object ob;
object light_warhorse;

void create() {
   ::create();
   set_name("horse");
   set_id(({"light warhorse","warhorse","horse"}));
   set_short("a Light Warhorse");
   set_long("This mount is of light build and good training.");
   set_race("equine");
   set_body_type("equine");
   set_alignment(5);
   set_hd(2,2);
   set_overall_ac(7);
   set_size(3);
   set_max_hp(100);
   set_hp(100);
   set_max_distance(48);
   set_max_sp(50);
    set_riding_level(10);
   set_sp(50);
   set_exp(35);
   set_value(150);
   set_enter_room(" rides in.");
   set_exit_room(" leaves riding a light warhorse.");
   set_vehicle_short("Light Warhorse");
}
void init() {
   ::init();
   add_action("mount_test", "mount");
}
int mount_test(string str) {
   	if(!str) return 0;
   	if(!id(str)) return 0;
   	if(((string)TP->query_level() < 5) || (TP->query_level() > 10)) {
      	if(ob=present("light warhorse",environment(TP))) {
         		ob->force_me("say You may %^RED%^NOT %^RESET%^ride me!");
         		this_object()->buck_chance(100);
         		tell_room(environment(TO),"The Light Warhorse bucks "+TPQCN+" off.",TP);
         		write("The Light Warhorse bucks you off.");
         		return 1;
      	}
   	}
}
