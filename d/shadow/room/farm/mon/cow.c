#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

void create() {
    	::create();
    	set_name("cow");
    	set_id(({"cow","bovine","black and white","farm_mon"}));
      set_short("a black and white cow");
      set_long("This black and white cow seems docile and somewhat "+
         "unaware.  She chews her cud, leaving green stains around "+
         "her mouth while her tail swishes away flies.  Her fur is "+
         "mostly white with large black splatches scattered here "+
         "and there.");
      set_gender("female");
      set_size(2);
    	set_hd(10,2);
    	set_class("fighter");
    	set_mlevel("fighter",10);
      set_race("cow");
      set_body_type("equine");
    	set_stats("intelligence",6);
    	set_stats("wisdom",6);
    	set_stats("strength",16); 
    	set_stats("charisma",3);
    	set_stats("dexterity",10);  
    	set_stats("constitution",13);
	set("aggressive",8);
    	set_alignment(5);
    	set_overall_ac(2);
    	set_exp(400);
    	set_max_hp((random(10)+90));
    	set_hp(query_max_hp());
      set_attack_limbs(({"right fore hoof","left fore hoof","head"}));
      set_damage(1,4);
      set_attacks_num(2);
    	set_max_level(12);
      set_property("swarm",1);
      add_money("gold",random(16)+15);
      set_emotes(3,({
         "The cow swishes her tail, batting away a fly.",
         "The cow's large eyes peer around slowly.",
         "The cow chews her cud lazily."
      }),0);
}