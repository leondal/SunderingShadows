#include <std.h>
#include "../farm.h"
inherit WEAPONLESS;

void create() {
    	::create();
    	set_name("steam mephit");
    	set_id(({"grinning mephit","grinning steam mephit","steam mephit","mephit"}));
      set_short("a grinning steam mephit");
      set_long("This tiny humanoid seems made entirely of steam, "+
         "almost as if one small gust of wind would blow him "+
         "away.  He bears faint, wispy wings of steam, and he "+
         "pale skin.  Insubstantial trails of vapor rise and "+
         "swirl around his nose, mouth, and ears.  Anytime it "+
         "moves, droplets of steaming water are left behind.  "+
         "The most disturbing thing about this creature, though, "+
         "is the undeniably wicked grin on his face and the "+
         "malicious gleam in his eyes.");
      set_gender("male");
    	set_hd(12,2);
      set_size(1);
    	set_class("fighter");
    	set_mlevel("fighter",12);
      set_race("mephit");
      set_body_type("human");
    	set_stats("intelligence",12);
    	set_stats("wisdom",6);
    	set_stats("strength",16); 
    	set_stats("charisma",12);
    	set_stats("dexterity",19);  
    	set_stats("constitution",13);
	set("aggressive",20);
    	set_alignment(9);
    	set_overall_ac(-1);
    	set_exp(800);
    	set_max_hp((random(10)+75));
    	set_hp(query_max_hp());
      add_limb("right claw","right hand",0,0,0);
      add_limb("left claw","left hand",0,0,0);
      set_attack_limbs(({"right claw","left claw"}));
      set_damage(1,4);
      set_attacks_num(2);
    	set_max_level(14);
      set_funcs(({"scald"}));
      set_func_chance(8);
      set_property("swarm",1);
      add_money("gold",random(100)+350);
}

int scald(object *baddies){
   int i;
   baddies = TO->query_attackers();
   if(!baddies) return 0;
   if(!objectp(TO)) return 0;
   tell_room(ETO,"%^BOLD%^The steam mephit takes a few deep "+
      "breaths, his eyes gleaming maliciously!");
   tell_room(ETO,"%^BOLD%^%^CYAN%^Steam pours from the mephit's "+
      "mouth, scalding all in its path!");
   for(i=0;i<sizeof(baddies);i++){
      if(!objectp(baddies[i])) continue;
      if(!objectp(TO)) continue;
      tell_object(baddies[i],"%^BOLD%^%^RED%^The steam scalds your "+
         "flesh!");
      baddies[i]->do_damage(baddies[i]->return_target_limb(),roll_dice(4,6));
   }
   return 1;
}