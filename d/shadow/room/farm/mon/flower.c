#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

void create() {
    	::create();
    	set_name("blood lily");
    	set_id(({"lily","multi-colored lily","azure lily","blood lily","flower"}));
      set_short("a multi-colored lily");
      set_long("This beautiful lily puts forth a fantastic, if "+
         "frightening, face.  It stands on a stalk about three "+
         "feet tall.  Its leaves are long and barbed, looking "+
         "rather too vicious for a lily.  The flower itself is "+
         "made of %^BOLD%^%^CYAN%^azure petals %^RESET%^%^CYAN%^"+
         "that spiral out from a %^BOLD%^%^MAGENTA%^pink "+
         "center%^RESET%^%^CYAN%^, with matching %^BOLD%^"+
         "%^MAGENTA%^pink dots %^RESET%^%^CYAN%^covering the "+
         "length of the petals.  Unlike most flowers, this one "+
         "seems unlikely to simply spend its days basking in the "+
         "sunshine.");
      set_gender("neuter");
    	set_hd(14,2);
      set_size(1);
    	set_class("fighter");
    	set_mlevel("fighter",14);
      set_race("lily");
      set_body_type("snake");
      add_limb("barbed leaf 1","torso",0,0,0);
      add_limb("barbed leaf 2","torso",0,0,0);
    	set_stats("intelligence",12);
    	set_stats("wisdom",6);
    	set_stats("strength",16); 
    	set_stats("charisma",12);
    	set_stats("dexterity",19);  
    	set_stats("constitution",13);
	set("aggressive",20);
    	set_alignment(5);
    	set_overall_ac(0);
    	set_exp(950);
    	set_max_hp((random(25)+120));
    	set_hp(query_max_hp());
      set_attack_limbs(({"barbed leaf 1","barbed leaf 2"}));
      set_damage(1,6);
      set_attacks_num(2);
    	set_max_level(16);
      set_funcs(({"cut"}));
      set_func_chance(25);
      set_property("swarm",1);
}

int cut(object targ){
   tell_object(targ,"%^BOLD%^%^RED%^The serrated edge of the flower's "+
      "leaf tears your skin!");
   tell_room(ETO,"%^BOLD%^%^RED%^The serrated edge of the flower's "+
      "leaf tears "+targ->QCN+"'s skin!",targ);
   targ->do_damage(targ->return_target_limb(),roll_dice(2,8));
   return 1;
}

void die(object obj){
   if(!random(3)){
      new(OBJ"petal_buckler")->move(TO);
   }
   ::die(obj);
}