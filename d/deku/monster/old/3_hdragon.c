
//     Created by Grayhawk@Shadowgate
//    This monster guards the tower where Jarrow resides.
//    This 3 headed dragon, wont let anyone pass unless they
//      say who they are going talk too.  What are they going
//      to talk about.  If the player persists in tring to
//      enter the tower, the dragon will attack.
//    Created by Grayhawk@ShadowGate

#include <std.h>

inherit "/std/monster";
int step;

create() {
    ::create();
	set_name("dragon");
	set_id( ({ "dragon","feywing" }) );
	set("race", "dragon");
	set_gender("male");
        set_short("Feywing, the mighty dragon");
	set_long(
          "Feywing, is a mighty 3 headed dragon.  He is Jarrow's doorman\n"+
          "and is responsible for who goes into the tower and disturbs his\n"+
"master.  He is an extremely powerful dragon, and should be\n"+
"treated with caution.\n"
	);
	set_level(20);
	enable_commands();   
	set_body_type("dragon");
  	set("aggressive",5);
  	set_alignment(9);
  	set_size(3);
        set_hd(10,5);
        set_overall_ac(-2);
   	set_stats("intelligence",18);
   	set_stats("wisdom",18);
   	set_stats("strength",18);
   	set_stats("charisma",9);
   	set_stats("dexterity",16);
   	set_stats("constitution",13);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_class("fighter");
        set_hp(230);
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
	add_money("silver",random(300));
	add_money("copper",random(200));
        add_money("gold",400 + random(400));
	step = 0;
        set_funcs(({"breath","spits"}));
        set_func_chance(50);
 set_exp(6000);
   set_max_level(15);
}

void breath(object targ) {
  string damaging;
  int dam, dam1;

   if(!objectp(targ)) return;
  if("/daemon/saving_d"->saving_throw(targ,"breath_weapon"))
    damaging="torches";
  else
    damaging="scorches";
  tell_object(targ,"%^RED%^The dragon "+damaging+" you with a stream of fire!");
  tell_room(environment(targ),"%^BOLD%^The dragon "+damaging+" "+targ->query_cap_name()+" with a stream of fire!", targ);
  dam = roll_dice(3,4)+6;
  dam1 = (roll_dice(3,4)+6)/2;
  if(damaging=="soaks"){
    set_property("magic",1);
    targ->do_damage("torso", dam);
    remove_property("magic");
  }
  else{
    set_property("magic",1);
    targ->do_damage("torso", dam1);
    remove_property("magic");
  }
  return 1;
}

void spits(object targ) {
  string damaging;
  int dam, dam1;
  if("/daemon/saving_d"->saving_throw(targ, "breath_weapon"))
    damaging="splashes";
  else
    damaging="soaks";
  tell_object(targ, "%^GREEN%^The dragon "+damaging+" you with a stream of acid!");
tell_room(environment(targ), "%^BOLD%^The dragon "+damaging+" "+targ->query_cap_name()+" with a stream of acid", targ);

  dam = roll_dice(3,4)+6;
  dam1 = (roll_dice(3,4)+6)/2;
  if(damaging=="soaks")
    targ->do_damage("torso", dam);
  else
    targ->do_damage("torso", dam1);
  return 1;
}

void catch_tell(string str){
	if((strsrch(str,"jarrow") != -1) && (step == 0)){ 
		call_out("reply_back",2,"What is it!"); 
		call_out("reply_back",4,"Who are you?"); 
                call_out("reply_back",6,"Why do you want to talk to Jarrow?");
                call_out("reply_back",8,"Don't answer, just begone before I kill you.");
		step = 1;
		return;
	}
	if((strsrch(str,"stones") != -1) && (step == 1)){ 
		call_out("reply_back",2,"What about them!"); 
                call_out("reply_back",4,"So you would like to solve the quest.");
                call_out("reply_back",6,"Ok, you may enter, but be warned.");
                call_out("go_enter",8);
		step = 0;
		return;	
	}
	return;

}

void reply_back(string str){
        tell_room(environment(this_object()),
        "%^MAGENTA%^The Dragon says%^WHITE%^:  "+str,this_object());
}


void go_enter() {
  write("\n");
write("The dragon motions for you to enter the tower.");
say("The mighty dragon motions for "+this_player()->query_cap_name()+" to enter the tower.");
  say("The dragon stares back to you as "+this_player()->query_cap_name()+" enters the tower.");
  this_player()->move_player("/d/deku/open/entrance");
}
void reset(){
	object ob;
	::reset();
    if(!present("scroll")){
  ob = new("/d/magic/scroll");
   ob->set_spell(2);
	ob->move(this_object());
   }
}
