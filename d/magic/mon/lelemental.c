//aelemental.c

#include <std.h>

inherit WEAPONLESS;

void create(){
   int num;
  
   ::create();
    set_name("lightning elemental");
    set_id(({"elemental","lightning elemental","lelemental"}));
    set("short","Lightning Elemental");
    set("long",
@PEG
This appears to be a large hazy cloud filled with energy. However
you think you can make out the outline of a face in the mist. You
have heard the stories of the battle skills of these elementals, and
their ability to do massive damage to their enemies.
PEG
	);
	num = random(100);
	switch(num){
	    case 0..59: set_hd(15,1);
	                break;
	    case 60..89: set_hd(20,1);
	                 break;
	    case 90..99: set_hd(25,1);
	                 break;
        default: set_hd(15,1);
                 break;
	}
    set_hp(query_hd()*8);
   set_exp(1);
    set_stats("strength",10);
    set_stats("intelligence",7);
    set_stats("dexterity",25);
    set_race("elemental");
    add_limb("torso","torso",50,0,2);
    add_limb("right bolt","torso",50,0,2);
    add_limb("left bolt","torso",50,0,2);
    add_limb("base","torso",50,0,2);
    set_attack_limbs(({"right bolt", "left bolt"}));
    set_hit_funcs((["right bolt":(:TO,"do_bolt":), "left bolt":(:TO,"do_bolt":)]));
    set_damage(1,1);
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
    set_gender("sexless");
    set_overall_ac(0);
}

int do_bolt(object ob){
   if(objectp(ob))
      if(!random(3)){
         new("/cmds/spells/l/_lightning_bolt")->use_spell(TO,ob,4,100,"mage");
         return 0;
      }
   return roll_dice(3,4);
}
int isMagic() {return 5;}
