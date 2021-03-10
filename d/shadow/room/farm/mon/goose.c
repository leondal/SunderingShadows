#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

void create() {
object obj;
    	::create();
    	set_name("goose");
    	set_id(({"goose","altered goose","mechanical goose","dive-bombing goose","fowl","farm_mon"}));
      set_short("a goose");
      set_long("This graceful goose has a soft white underbelly "+
         "while gray feathers cover her back.  She has a slender "+
         "black neck and a small head featuring a long black beak and "+
         "intelligent black eyes.  Strangely, she is wearing a "+
         "metal helmet fitted with a chin strap.  The helmet is "+
         "dented as if from much use, but...what could this bird "+
         "possibly be beating her head against?");
      set_gender("female");
      set_size(1);
    	set_hd(10,2);
    	set_class("fighter");
    	set_mlevel("fighter",10);
      set_race("goose");
      set_body_type("fowl");
    	set_stats("intelligence",6);
    	set_stats("wisdom",6);
    	set_stats("strength",15);  //yes, it's one strong bird :P
    	set_stats("charisma",3);
    	set_stats("dexterity",18);  //ninja goose!
    	set_stats("constitution",13);
	set("aggressive",9);
    	set_alignment(5);
    	set_overall_ac(5);
    	set_exp(300);
    	set_max_hp((random(10)+65));
    	set_hp(query_max_hp());
    	set_emotes(3,({
         "The goose takes to the air in a flurry of feathers.",
         "The goose lands gracefully on the water.",
         "The goose shakes, sending water into the air."
    	}),0);
      set_attack_limbs(({"right claw","left claw","beak","head"}));
      set_damage(1,4);
      set_attacks_num(2);
    	set_max_level(13);
      set_funcs(({"bomb"}));
      set_func_chance(15);
      set_property("swarm",1);
      add_money("gold",random(16)+15);
      obj = new(OBJ"goose_helm");
      if(random(3)) obj->set_property("monsterweapon",1);
      obj->move(TO);
      force_me("wear helm");
}

int bomb(object targ){
   tell_room(ETO,"%^BOLD%^The goose's eyes %^RED%^flash %^WHITE%^"+
      "as she stiffens!");
   tell_object(targ,"%^BOLD%^%^RED%^She suddenly takes a nose-dive "+
      "straight into you!");
   tell_room(ETO,"%^BOLD%^%^RED%^She takes a nose-dive straight "+
      "into "+targ->QCN+"!",targ);
   targ->do_damage("torso",roll_dice(1,6));
   return 1;
}