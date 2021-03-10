#include <std.h>
#include "../koenig.h"

inherit MONSTER;

void create (){

::create ();
   set_name("kobold slave");
   set_id(({"kobold","slave","kobold slave"}));
   set_short("An ugly little kobold");
   set_long("%^RESET%^%^ORANGE%^This dirty little creature looks"
" like it is poorly taken care of. His tiny little horns are dirty"
" and chipped, his skin is loose and falling from his body, and"
" he has a very hungry glint in his eyes. His sharp little claws"
" look like they could still be pretty useful though.%^RESET%^");
   set_race("kobold");
   set_gender("male");
   set_body_type("human");
   set_overall_ac(0);
   set_hd(15,2);
   set_size(1);
   set_stats("intelligence",12);
   set_stats("strength",18);
   set_stats("wisdom",10);
   set_stats("dexterity",13);
   set_stats("constitution",15);
   set_stats("charisma",4);
   set_hp(random(50)+100);
   set_max_hp(query_hp());  
   //set_exp(75);
   set_exp(600);
   set_alignment(9);
   set("aggressive","aggfunc");
   set_achats(5, ({"%^RESET%^%^ORANGE%^The kobold looks desperate as it lunges for you again!%^RESET%^",
   "%^RESET%^Drool drips from the kobolds mouth as it thinks about its next meal.",
}) );
   RANDGEAR->armor_me(TO,"armorlt",40,1,20);
   RANDGEAR->arm_me(TO,"edgeds",20,1,50);
}
int aggfunc() {
   force_me("speech say excitedly");
   force_me("emoteat "+TPQN+ " turns to $N.");
   force_me("say %^ORANGE%^Food!");
   force_me("kill "+TPQN+ "");
}


