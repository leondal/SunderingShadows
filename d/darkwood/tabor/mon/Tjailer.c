// Adapted from Bane's Laerad commandos by Styx for the Tabor jail

/* *************
* Notes to those creating new ones or to follow up to handle here
* Need to have a proper ID of JailLoc_guard set or added from a callout in create
* Have a set_key also ?? 
*   - would have to use a callout to load it so do that with the add_id??
* !! or, have an is_law(JailLoc) function and a variable setting them for that?
* Leave the attack special function but let it be overridden?
*/

#include <std.h>
#include <daemons.h>

inherit "/std/jailer.c";
int summonhelp;


void create(){
    ::create();
    set_jail_location("Tabor");
    set_property("official", "Tabor");
    set_jail("/d/darkwood/tabor/room/jail_main");
    set_cell("/d/darkwood/tabor/room/jail_cell");
    set_property("knock unconscious",1);
    set_id(({"jailer", "Tabor jailer"}));
    set_name("jailer");
    set_short("Tabor's jailer");
    set_long("Judging from his scars, this male human looks to have seen many years of guard duty.  Judging from the belly that hangs over his belt, you also suspect he's been doing desk duty somewhere for a while.  However, he still looks ready for a fight if needed and keeps a close eye on the cell and the prisoners." );
    set_race("human");
    set_gender("male");
    set_hd(30+(random(9)),6);
    set_hp(350+(random(50)));
    set_max_level(30);
    set_overall_ac(-15);
    set_exp(100);
    set_alignment(2);
    set_class("fighter");
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand","right foot","left foot"}));
    set_attacks_num(5);
    set_damage(2,5);
    set_property("magic resistance",40);
    set_property("no bows", 1);  	
    set_property("no dominate", 1);  	
    set_funcs(({"headlock","key_swipe", "key_swipe"}));
    set_func_chance(70);
    set_property("swarm",1);
    new("/d/darkwood/tabor/obj/jail_key")->move(TO);
    force_me("wear key");
}

void reset() {
   object ob;
   ::reset();
   summonhelp = 0;
   if(ob = present("skeleton key"))
      if(!ob->query_worn())
        command("wear key");
}

void init() {
   ::init();
   if(base_name(ETO) == JailFile) {
      add_action("guard_check", "pick");
      add_action("guard_check", "unlock");
   }
   add_action("no_way","rush");
   add_action("no_way","stab");
}

int kill_ob(object ob, int i){
    int hold;
    hold = ::kill_ob(ob,i);
    if (hold) {
	if(!summonhelp) {
          tell_room(ETO, "The guard screams loudly for help.");
          new("/d/darkwood/tabor/mon/guard")->move(ETO);
	  new("/d/darkwood/tabor/mon/guard")->move(ETO);
	  new("/d/darkwood/tabor/mon/guard")->move(ETO);
	  summonhelp = 1;
        }
    }
    return hold;
}


void guard_check(string str) {
   string *jailers;
   jailers = AREALISTS_D->query_jailer_names(JailLoc);
   if(str != "lock on cell door" && str != "cell door with key")  
      return;
   if(member_array(TPQN,jailers) != -1) 
      return;
   if(str == "lock on cell door") { 
      tell_room(ETP,"%^YELLOW%^The jailer catches "+TPQCN+" trying to pick "
         "the lock to the cell door!", TP);
      tell_object(TP,"%^YELLOW%^The jailer catches you trying to pick the "
         "lock and attacks!");
   }
   if(str == "cell door with key" || str == "cell door with skeleton key") {
      if(TP->query_true_invis())   return 0;
      tell_room(ETP,"%^YELLOW%^The jailer catches "+TPQCN+" trying to unlock "
         "the cell door!", TP);
      tell_object(TP,"%^YELLOW%^The jailer catches you trying to unlock "
         "the cell door and attacks!");
   }
   force_me("kill "+TPQN);
   command("block south");
   return;
}

void headlock(object targ){
    if(!objectp(TO))  return;
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^%^BLUE%^The jailer slips in behind you "
	  "and puts you in a painful headlock, suffocating you!");
	tell_room(ETO,"%^BOLD%^BLUE%^The jailer slips in behind "
	  +targ->query_cap_name()+" and puts "+targ->query_objective()+" in "
	  "a headlock!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(3,5)+10);
	targ->set_paralyzed(50,"You are in a headlock.");
	return;
    }
    tell_object(targ,"%^BOLD%^BLUE%^The jailer attempts to slip in "
       "behind you but you cut him off!");
    tell_room(ETO,"%^BOLD%^BLUE%^The jailer attempts to slip in behind "
      +targ->QCN+" but "+targ->query_subjective()+" cuts "
      "him off!",targ);
    return;
}

void key_swipe(object targ){
    if(!objectp(TO))  return;
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand")){
	tell_object(targ,"%^BOLD%^RED%^The jailer deftly swings the heavy "
	  "key across your throat, nearly crushing it!");
	tell_room(ETO,"%^BOLD%^RED%^The jailer deftly swings the heavy key "
	  "across "+targ->QCN+"'s throat, nearly crushing it!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(5,10)+10);
	return;
    }
    tell_object(targ,"%^GREEN%^The jailer swings the heavy key at your "
       "throat, barely missing it but still hitting and bruising you badly!");
    tell_room(ETO,"%^GREEN%^The jailer swings the heavy key at "
       +targ->QCN+"'s throat and "+targ->query_subjective()+
       " ducks but still gets badly bruised by it!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(3,5)+10);
    return;
}

int no_way(){
    write("The jailer easily catches you at your pitiful attempt in "
       "this small room.");
    return 1;
}
