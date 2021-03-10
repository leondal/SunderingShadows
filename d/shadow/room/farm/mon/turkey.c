#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

//flaring their fans, throwing their bodies, gobbling wildly

void create() {
    	::create();
    	set_name("turkey");
    	set_id(({"turkey","fowl","tom","tom turkey","hen","farm_mon"}));
      switch(random(2)){
         case 0:
            set_short("a tom turkey");
            set_long("This turkey is covered in deep bronze feathers, "+
               "with a beautiful fan accented with reds and greens.  "+
               "The tips of his tail feathers end in white, giving "+
               "a distinct scalloped appearance to his fan.  "+
               "Covering the turkey's neck is a deep red wattle, "+
               "rather warty in appearance, and a matching wattle at "+
               "the base of his bill.  His coarse chest feathers are "+
               "a deeper bronze, reaching black in places.");
            set_gender("male");
            break;
         default: 
            set_short("a turkey hen");
            set_long("This turkey is much less colorful than her "+
               "male counterpart.  Her feathers are a dusky gray, "+
               "lightening and darkening in various points.  Her "+
               "tail feathers are rather short and lack color, "+
               "instead being mostly deep brown or black.  The "+
               "hen's bill is small and narrow, allowing her to "+
               "collect insects or grain from the ground with ease.");
            set_gender("female");
      }
    	set_hd(8,2);
      set_size(1);
    	set_class("fighter");
    	set_mlevel("fighter",8);
      set_race("turkey");
      set_body_type("fowl");
    	set_stats("intelligence",6);
    	set_stats("wisdom",6);
    	set_stats("strength",15);  //yes, it's one strong bird :P
    	set_stats("charisma",3);
    	set_stats("dexterity",18);  //ninja turkey!
    	set_stats("constitution",13);
	set("aggressive",8);
    	set_alignment(5);
    	set_overall_ac(4);
    	set_exp(320);
    	set_max_hp((random(10)+78));
    	set_hp(query_max_hp());
    	set_achats(6,({
         "%^BOLD%^%^RED%^The turkey flares its fan and gobbles wildly!",
         "%^YELLOW%^The turkey throws its body at you!",
         "%^RED%^The turkey flaps its wings angrily, sending feathers everywhere!"
    	}));
      set_attack_limbs(({"right claw","left claw","beak","head"}));
      set_damage(1,4);
      set_attacks_num(2);
    	set_max_level(13);
      set_funcs(({"charge"}));
      set_func_chance(15);
      set_property("swarm",1);
}

int charge(object targ){
   tell_room(ETO,"%^BOLD%^%^RED%^The turkey gets a fierce look "+
      "in its eyes and takes to the air!");
   tell_object(targ,"%^BOLD%^%^WHITE%^The turkey comes barrelling "+
      "into you, knocking you back!");
   tell_room(ETO,"%^BOLD%^%^WHITE%^The turkey barrels into "+targ->QCN+", "+
      "knocking "+targ->QO+" back!",targ);
   targ->do_damage("torso",roll_dice(1,6));
   targ->set_paralyzed(2+random(4),"You are baffled by the turkey's attack!");
   return 1;
}

void die(object obj){
   if(!random(4)){
      new(OBJ"feather_head")->move(TO);
   }
   ::die(obj);
}