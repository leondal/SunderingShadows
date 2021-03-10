 //salamander.c - New monster for Koenig area.  Coded by Circe 11/21/03
#include <std.h>
inherit MONSTER;

int dlevel;

void create() {
    	::create();
	set_name("salamander");
	set_id(({"salamander","tiny salamander","monster","amphibian"}));
	set_race("salamander");
	set_gender("male");
	set_short("A tiny salamander");
	set_long(
         "This tiny salamander is a deep inky black in color.  He is only a few inches "+
         "in length, and his glossy skin shimmers in the light.  He seems perpetually "+
         "wet and spends most of his life crawling under and between rocks.  He looks "+
         "pretty harmless, but might be able to defend himself if threatened.");
	dlevel = random(3) + 2;
	set_level(dlevel);
	set_body_type("reptile");
  	set("aggressive",6);
  	set_alignment(5);
  	set_size(1);
	set_hd(dlevel,2);
   	//set_exp(dlevel * 30);
//    set_exp(dlevel * 100);
	set_new_exp(5,"normal");
   	set_max_hp(10+(dlevel * (random(10) + 1)));
   	set_hp(query_max_hp());
   	set_max_level(8);
	add_money("silver",random(5) * dlevel);
	add_money("copper",random(10) * dlevel);
    	set_emotes(1,({
         "The salamander darts under a rock.",
         "The salamander climbs out of the water onto a tall rock.",
         "The salamander flicks his tail."
    	}),0);
      set_achats(3, ({
         "The salamander tries to scurry under a rock.",
         "The salamander bites back as best he can.",
         "The salamander thumps his tail on a rock as he tries to defend himself."
      }) );
}

void die(mixed ob){
   switch(random(4)) {
      case 0..2:  new("/d/koenig/obj/salafood")->move(TO);
                  break;
      case 3:  new("/d/koenig/obj/salabelt")->move(TO);
               break;
   }
   ::die(ob);
}