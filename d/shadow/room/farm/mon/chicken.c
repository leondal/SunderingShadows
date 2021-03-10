#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

#define COLORS ({"%^BOLD%^%^WHITE%^white","%^BOLD%^%^BLACK%^mo%^RESET%^t%^BOLD%^%^BLACK%^tl%^WHITE%^e%^BLACK%^d black a%^RESET%^n%^BOLD%^%^BLACK%^d %^WHITE%^wh%^RESET%^i%^BOLD%^te","%^YELLOW%^yellow"})

void create() {
   string COLOR;
   int i;
    	::create();
      i = random(sizeof(COLORS));
      COLOR = COLORS[i];
    	set_name("chicken");
    	set_id(({"chicken","altered chicken","mechanical chicken","exploding chicken","fowl","rooster","farm_mon"}));
      switch(random(4)){
         case 0:  set_short("a rooster");
                  set_long("This rooster features lustrous feathers "+
                     "colored in deep mottled grays and browns.  His "+
                     "plump body indicates his healthy appetite, "+
                     "while the swagger in his step reveals his "+
                     "confidence.  His black eye seems to stare you "+
                     "down beneath the brilliant red comb atop "+
                     "his head, and strangely, you think this "+
                     "fowl could handle himself in a fight.");
                  set_gender("male");
                  break;
         default: set_short("a "+COLOR+" %^BOLD%^%^RED%^chicken%^RESET%^");
                  set_long("This chicken is covered in fluffy "+COLOR+" %^RESET%^%^CYAN%^"+
                     "feathers that she clearly keeps well-preened.  "+
                     "Her black eyes are beady and study her "+
                     "surroundings with an uncanny intelligence, "+
                     "quite unnerving in a chicken.  She scratches "+
                     "her wicked claws along the ground, almost "+
                     "as if she's looking for a fight.");
                  set_gender("female");
      }
    	set_hd(8,2);
    	set_class("fighter");
    	set_mlevel("fighter", 8);
      set_race("chicken");
      set_body_type("fowl");
    	set_stats("intelligence",6);
    	set_stats("wisdom",6);
    	set_stats("strength",15);  //yes, it's one strong bird :P
    	set_stats("charisma",3);
    	set_stats("dexterity",18);  //ninja chicken!
    	set_stats("constitution",13);
	set("aggressive",8);
    	set_alignment(5);
    	set_overall_ac(4);
    	set_exp(320);
    	set_max_hp((random(10)+78));
    	set_hp(query_max_hp());
    	set_achats(6,({
         "%^BOLD%^The chicken lowers its head and charges!!",
         "%^YELLOW%^The chicken scratches its claws on the ground menacingly.",
         "%^RED%^The chicken flaps its wings and squawks.",
         "%^BOLD%^%^RED%^The chicken runs in frightened circles!"
    	}));
    	set_emotes(3,({
         "The chicken pecks at something in the grass.",
         "The chicken flaps its wings briefly, twitching its head.",
         "The chicken clucks absently as it wanders around.",
         "The chicken tilts its head and you hear a strange clicking sound."
    	}),0);
      set_attack_limbs(({"right claw","left claw","beak","head"}));
      set_damage(1,4);
      set_attacks_num(2);
    	set_max_level(13);
      set_funcs(({"explode","peck"}));
      set_func_chance(15);
      set_property("swarm",1);
}

int explode(object *baddies){
   int i;
   baddies = TO->query_attackers();
   if(!baddies) return 0;
   if(!objectp(TO)) return 0;
   tell_room(ETO,"%^BOLD%^You hear a strange clicking sound and "+
      "the chicken stops, tilting its head.");
   tell_room(ETO,"%^BOLD%^%^RED%^Suddenly, the bird explodes, "+
      "sending feathers everywhere!");
   for(i=0;i<sizeof(baddies);i++){
      if(!objectp(baddies[i])) continue;
      if(!objectp(TO)) continue;
      tell_object(baddies[i],"%^RED%^You are hit with the blast!");
      baddies[i]->do_damage(baddies[i]->return_target_limb(),roll_dice(4,6));
      new(OBJ"feather_maker")->move(baddies[i]);
   }
   tell_room(ETO,"%^CYAN%^As the feathers settle, you catch "+
      "sight of something glittering on the ground.");
   new("/d/newbie/obj/misc/gem")->move(ETO);
   TO->remove();
   return 1;
}

int peck(object targ){
   tell_room(ETO,"%^BOLD%^The chicken lifts its rotund body into "+
      "the air, flapping its wings!");
   tell_object(targ,"%^BOLD%^%^BLUE%^Suddenly, the chicken kicks "+
      "out a leg and flies into you, ninja-style!");
   tell_room(ETO,"%^BOLD%^%^BLUE%^Suddenly, the chicken kicks out "+
      "a leg and flies into "+targ->QCN+"!",targ);
   targ->do_damage("torso",roll_dice(1,6));
   return 1;
}

void die(object obj){
   tell_room(ETO,"%^BOLD%^%^RED%^The chicken lets out a "+
      "haunting BWRAWK as it falls lifeless to the ground.");
   ::die(obj);
}