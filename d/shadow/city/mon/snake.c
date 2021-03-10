#include <std.h>
#include <daemons.h>
inherit WEAPONLESS;

void create() {
  ::create();
  set_name("snake");
  set_id(({"snake","constricter snake", "black snake"}));
  set_short("A giant black snake");
  set_long("%^BOLD%^%^BLACK%^This slithering serpent blends in with the dark shadows of the tunnel, its ominous hissssss echoing through the open space. Lines trace down its serpentine form, such a dark green in color they are hard to notice at first. Its sleek body is a little over two feet in length, and it has two alert, beady black eyes that follow your movements. \n");
  set_race("snake");
  set_body_type("snake");
  set_gender("female");
  set_size(1);
  set("aggressive");
  set_hd(1,2);
  set_level(10);
  set_class("thief");
  set_mlevel("thief",10);
  set_hp(random(90)+10);
  set_exp(10, "normal");
  set_damage(2,6);
  set_attacks_num(1);
  set_base_damage_type("bludgeoning");
  set_attack_limbs(({"mouth","tail","torso"}));
  set_ac(10);
  set_alignment(5);
  add_money("gold",random(10)+5);
  add_money("silver",random(20));
  add_search_path("/cmds/thief");
  set_thief_skill("move silently",95);
  set_thief_skill("hide in shadows",95);
  set_hidden(1);
  set_stats("intelligence",2);
  set_stats("wisdom",2);
  set_stats("strength",5);
  set_stats("charisma",2);
  set_stats("dexterity",14);
  set_stats("constitution",14);
  set_funcs(({"constrict"}));
  set_func_chance(50);
  set_emotes(50,"%^BOLD%^%^BLACK%^A loud hiss echoes through the tunnels.",0);
}


void constrict(object targ) {
	if(!targ->query_invis() && (int)targ->query_size() == 1){
	tell_room(ETO,"%^RESET%^%^ORANGE%^The snake wraps its body around "+targ->query_cap_name()+"%^RESET%^%^ORANGE%^ and begins "+
	"to %^BOLD%^%^BLACK%^squeeze %^RESET%^%^ORANGE%^"+targ->query_objective()+"%^RESET%^%^ORANGE%^!%^WHITE%^",targ);
	tell_object(targ, "%^ORANGE%^The snakes wraps around you and begins to squeeze!%^WHITE%^");
	targ->do_damage(targ->return_target_limb(), roll_dice(1,4));
    targ->set_paralyzed(5, "You are being crushed by the snake!");
	} else {
	tell_room(ETO,"%^RESET%^%^GREEN%^The snakes tries to constrict "+targ->query_cap_name()+"%^RESET%^%^GREEN%^"+
	" but can't get around "+targ->query_objective()+"%^RESET%^%^GREEN%^!%^WHITE%^",targ);
	tell_object(targ, "%^BOLD%^%^BLACK%^The snake tries to crush you in its grasp, but you're too big!%^RESET%^");
	}
	}
	
void init(){
   ::init();
   if(!TP->query_invis() && (int)TP->query_size() == 1){
	  tell_room(ETO,"%^BOLD%^%^BLACK%^The snake's beady black eyes seem to be sizing you up for a fight.");
     kill_ob(TP,1);
   }
   return;
}