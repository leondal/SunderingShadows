#include <std.h>
inherit "/std/riding_animal";

object ob;
object draft;

void create() {
   ::create();
   set_name("horse");
   set_id( ({"horse", "draft horse" , "draft"}) );
   set_short("Draft Horse");
   set_long("This large mount is just what you needed, he'll get you there and back again.");
   set_race("equine");
   set_body_type("equine");
   set_alignment(5);
   set_hd(3,2);
   set_overall_ac(7);
   set_max_hp(50);
   set_hp(50);
   set_size(3);
   set_max_distance(24);
   set_max_sp(25);
   set_riding_level(5);
   set_sp(25);
   set_exp(65);
   set_value(200);
   set_enter_room(" rides in.");
   set_exit_room(" leaves riding a draft.");
   set_vehicle_short("Draft Horse");
}

void init() {
   ::init();
   add_action("mount_test", "mount");
}
int mount_test(string str) {
   	if(!str) return 0;
   	if(!id(str)) return 0;
   	if((TP->query_level()<5) || (TP->query_level()>10)) {
      	if(ob=present("draft",environment(TP))) {
         		ob->force_me("say You are %^RED%^unworthy %^RESET%^of me at your level!");
         		this_object()->buck_chance(100);
         		tell_room(environment(TO),"The Draft bucks "+TPQCN+" off.",TP);
         		tell_object(this_object(),"The Draft bucks you off.");
         		return 1;
      	}
   	}
}
