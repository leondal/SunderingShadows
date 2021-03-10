/*Adapted from Bane's Laerad commandos by Styx for the Shadow jail
- Should we set him to no dominate?
- Why won't he wield the key?  Made it wearable and that works, but still..
- Features > attacks people trying to unlock the door or pick the lock
-> Jails bound people & records their name in a list
-> Checks to be sure he's at the jail before taking them
-> Will call Shadow watch and has "shadow law" id so they won't attack him
by Styx - 3/31/02
-- Figure out how to make him yell shut up in there if someone yells?
*/

#include <std.h>
#include <daemons.h>
#define GUARD_D "/d/shadow/mon/guards/guard_d"

inherit WEAPONLESS;

int ask_em(object targ);
int jail_em(string str);
int give_key(string str);
int ok_to_open();
string *jailers;

void create(){
    ::create();
    set_id(({"jailer", "guard", "Shadow jailer", "shadow law"}));
    set_name("jailer");
    set_short("jailer");
    set_long("The jailer looks like he has slept in his clothes and gear
a few too many times.  He obviously hasn't shaved in a few days and his
dark hair is rather unkempt.  A heavy chain hangs from a wide, heavy
leather belt and the key in his hand is attached to the other end. 
Massive corded biceps bulge between the thick, rough leather vest he wears
and leather bracers on his lower arms.  Heavy leather boots come to his
knees and Altogether his appearance makes his surly attitude that much
more disconcerting.  Heavily scarred, he's obviously seen his share of
combat and probably knows how to handle himself.  He does, however, look
quite ready to jail about anyone and might even take a prisoner off your
hands."
    );
    set_body_type("human");
    set_race("human");
    set_gender("male");
    set_size(2);
    set_hd(30+(random(9)),6);
    set_hp(350+(random(50)));
    set_max_level(30);
    set_overall_ac(-15);
    set_exp(5000);
    set_alignment(2);
    set_class("fighter");
//    set_guild_level("fighter",24);
    set_stats("charisma",12);
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand","right foot","left
foot"}));
    set_attacks_num(5);
    set_damage(2,5);
    set_mob_magic_resistance("average");
    set_property("swarm",1);
    set_property("no bows", 1);  // added 2/8/03 
    set_property("no dominate", 1);  // added 2/8/03 
    set_funcs(({"headlock","key_swipe", "key_swipe"}));
    set_func_chance(70);
    new("/d/shadow/obj/special/jail_key")->move(TO);
    force_me("wear key");
}

void reset() {
   object ob;
   ::reset();
   if(ob = present("skeleton key", TO))
      if(!ob->query_worn())
	command("wear key");
}

void init() {
   ::init();
   if(base_name(ETO) == "/d/shadow/room/city/jail_main") {
      add_action("guard_check", "pick");
      add_action("guard_check", "unlock");
      if(TP->query_bound() || TP->query_unconscious())  
         call_out("ask_em", 3, TP);
   }
   add_action("no_way","rush");
   add_action("no_way","stab");
   add_action("jail_em","jail");
//   add_action("add_jailer","add");       // moved to the room
//   add_action("remove_jailer","remove"); // moved to the room
   add_action("give_key", "request");
}

int kill_ob(object ob, int i){
    int hold;
    hold = ::kill_ob(ob,i);
    if (hold) {
        GUARD_D->blow_horn(TO);
        GUARD_D->call_watch(TO, ob);
    }
    return hold;
}

void guard_check(string str) {
   jailers = SAVE_D->query_array("Shadow_jailers");
   if(str != "lock on cell door" && str != "cell door with key")  return 0;
   if(member_array(TPQN,jailers) != -1) 
      return 1;
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
   GUARD_D->blow_horn(TO);
   GUARD_D->call_watch(TO, TP);
   command("block south");
   return 0;
}

int ask_em(object targ) {
   if(targ->query_property("draggee")) {
      force_me("say You're gonna have to drop the criminal if ya want "
        "'em jailed.");
      call_out("jail_em", 5);
      call_out("jail_em", 5, targ->query_name());
      return 1;
   }
   jail_em((string)targ->query_name());
   return 1;
}

int jail_em(string str){
   object jailwho;
   if(!str) return notify_fail("Jail whom?\n");
   jailwho = present(str);
   if(base_name(ETO) != "/d/shadow/room/city/jail_main") 
      return notify_fail("You need to be at the jail to do that!\n");
   if(!jailwho) return notify_fail("That person is not here!\n");
   if(jailwho->query_property("draggee")) {
      force_me("say Didn't I tell ya you're gonna have to drop the "
        "criminal if ya want 'em jailed.");
      TO->force_me("glare "+TPQN);
      call_out("jail_em", 3, jailwho);
      return 0;
   }
   if(!jailwho->query_bound() && !jailwho->query_unconscious())
       return notify_fail("You have to knock them out or bind them "
         "first.\n");
   tell_room(ETO,"The guard peers through the grating in the door and "
      "pulls a lever.  You hear something click inside the cell before "
      "he unlocks the door and quickly shoves "+jailwho->query_cap_name()+
      " inside.",jailwho);
   tell_object(jailwho,"The guard peers through the grating in the door "
       "and pulls a lever.  You hear something click inside the cell "
       "before he unlocks the door and quickly shoves you into the cell.");
   tell_room(ETO,"The cell door creaks as it swings on the hinges but "
       "shuts with an ominous, solid thud.\n");
   jailwho->move("/d/shadow/room/city/jail");
   jailwho->set("jailed_age",(int)jailwho->query_age());
   force_me("close cell door");
   force_me("lock cell door with key");
   jailwho->force_me("look");
   "/cmds/avatar/_note.c"->cmd_note("ckpt "+jailwho->query_name()+
      " was put into %^RED%^Shadow jail.");
   SAVE_D->set_value("Shadow_prisoners", jailwho->query_name());
   return 1;
}
/*
int remove_jailer(string str){
   jailers = SAVE_D->query_array("Shadow_jailers");
   if(!avatarp(TP))  return 0;
   if(!str) return notify_fail("Remove who?\n");
   if(base_name(ETO) != "/d/shadow/room/city/jail_main") 
       return notify_fail("You need to be at the jail to do that!\n");
   if(member_array(str,jailers) != -1) {
     SAVE_D->remove_name_from_array("Shadow_jailers", str);
     tell_object(TP,"You have removed "+str+" from being an authorized jailer.");
     "/cmds/avatar/_note.c"->cmd_note("ckpt "+str+" was removed from "
        "%^BOLD%^the list of Shadow jailers.");
     return 1;
   }
   notify_fail("You don't need to remove them, they weren't authorized.\n");
}

int add_jailer(string str){
   jailers = SAVE_D->query_array("Shadow_jailers");
   if(!avatarp(TP))  return 0;
   if(!str) return notify_fail("Add who?\n");
   if(base_name(ETO) != "/d/shadow/room/city/jail_main") 
       return notify_fail("You need to be at the jail to do that!\n");
   if(member_array(str,jailers) == -1) {
     SAVE_D->set_value("Shadow_jailers", str);
     tell_object(TP,"You have added "+str+" to be an authorized Shadow "
        "jailer.");
     "/cmds/avatar/_note.c"->cmd_note("ckpt "+str+" was added to the "
      "%^BOLD%^the list of Shadow jailers.");
     return 1;
   }
   notify_fail("You don't need to add them, they were already authorized.\n");
}
*/
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
	return 1;
    }
    tell_object(targ,"%^BOLD%^BLUE%^The jailer attempts to slip in "
       "behind you but you cut him off!");
    tell_room(ETO,"%^BOLD%^BLUE%^The jailer attempts to slip in behind "
      +targ->query_cap_name()+" but "+targ->query_subjective()+" cuts "
      "him off!",targ);
    return 1;
}

void key_swipe(object targ){
    if(!objectp(TO))  return;
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand")){
	tell_object(targ,"%^BOLD%^RED%^The jailer deftly swings the heavy "
	  "key across your throat, nearly crushing it!");
	tell_room(ETO,"%^BOLD%^RED%^The jailer deftly swings the heavy key "
	  "across "+targ->query_cap_name()+"'s throat, nearly crushing it!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(5,10)+10);
	return 1;
    }
    tell_object(targ,"%^GREEN%^The jailer swings the heavy key at your "
       "throat, barely missing it but still hitting and bruising you badly!");
    tell_room(ETO,"%^GREEN%^The jailer swings the heavy key at "
       +targ->query_cap_name()+"'s throat and "+targ->query_subjective()+
       " ducks but still gets badly bruised by it!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(3,5)+10);
    return 1;
}

int no_way(){
    write("The jailer easily catches you at your pitiful attempt in "
       "this small room.");
    return 1;
}

int give_key(string str){
   jailers = SAVE_D->query_array("Shadow_jailers");
   if(member_array(TP->query_name(),jailers) != -1 || avatarp(TP)) {  
     if(str != "key") {
        return notify_fail("Request what?\n");
        return 1;
     }
     tell_room(ETO,TPQCN+" whispers something to the jailer.", TP);
     tell_object(TP,"You whisper your request to the jailer.");
     force_me("say As you wish.");
     command("give key to "+TPQN);
     return 1;
   }
   notify_fail("I don't think you're authorized!\n");
}