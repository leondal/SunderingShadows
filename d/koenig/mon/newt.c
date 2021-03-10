 //newt.c - New monster for Koenig area.  Coded by Circe 11/21/03
#include <std.h>
inherit MONSTER;

int dlevel;

void create() {
    	::create();
	set_name("newt");
	set_id(({"newt","tiny newt","monster","amphibian"}));
	set_race("newt");
	set_gender("male");
	set_short("A tiny newt");
	set_long(
         "%^GREEN%^Much like a salamander, this tiny newt is a deep green in "+
         "color and has vibrant %^BOLD%^green spots %^RESET%^%^GREEN%^running along his back.  "+
         "He is very shiny and slick, and he can hide in cracks and under "+
         "rocks very well.  He is rather harmless but would probably try to "+
         "defend himself if provoked."
      );
	dlevel = random(3) + 3;
	set_level(dlevel);
	set_body_type("reptile");
  	set("aggressive",6);
  	set_alignment(5);
  	set_size(1);
	set_hd(dlevel,2);
   	//set_exp(dlevel * 10);
//   	set_exp(dlevel * 100);
	set_new_exp(6,"normal");
   	set_max_hp(15+(dlevel * (random(3) + 1)));
   	set_hp(query_max_hp());
   	set_max_level(8);
	add_money("silver",random(5) * dlevel);
	add_money("copper",random(10) * dlevel);
    	set_emotes(1,({
         "The newt darts under a rock.",
         "The newt climbs out of the water onto a tall rock.",
         "The newt flicks his tail."
    	}),0);
      set_achats(3, ({
         "The newt tries to scurry under a rock.",
         "The newt bites back as best he can.",
         "The newt thumps his tail on a rock as he tries to defend himself."
      }) );
}

void die(mixed ob){
   switch(random(4)) {
      case 0..2:   break;
      case 3:  new("/d/koenig/obj/newteye")->move(TO);
               break;
   }
   ::die(ob);
}