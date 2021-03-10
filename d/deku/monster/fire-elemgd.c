#include <std.h>

inherit WEAPONLESS;
int step, given;

create() {
    ::create();
    set_name("giant fire elemental");
	set_id( ({ "fire elemental", "giant fire elemental", "giant elemental", "firealtarguard" }) );
    set_race("elemental");
	set_gender("neuter");
    set_short("A giant fire elemental");
	set_long( "This is a giant fire elemental probably summoned by some "
	  "dark force to guard this tower.  As you look into the inferno you see "
	  "it has almost what look like arms and maybe even a face.  This creature "
	  "is truly fearsome as you think of the pain that could be caused by the "
	  "pure fire it is made of.");
    set_hd(15,1);
  	set("aggressive",5);
  	set_alignment(6);
  	set_size(3);
    set_overall_ac(-2);
    set_hp(150+random(30));
	set_max_hp(query_hp());
    set_stats("strength",18);
    set_stats("intelligence",7);
    set_stats("dexterity",16);
    add_limb("torso","torso",50,0,2);
    add_limb("right flame","torso",50,0,2);
    add_limb("left flame","torso",50,0,2);
    add_limb("base","torso",50,0,2);
    set_attack_limbs(({"left flame", "right flame"}));
    set_damage(4,8);
    set_attacks_num(1);
    set_base_damage_type("bludgeoning");
	set_wielding_limbs( ({ "right hand", "left hand" }) );
    add_money("gold",175 + random(200));
	step = 0;
    set_funcs(({"grab"}));
    set_func_chance(50);
    //set_exp(3000);
	set_new_exp(20, "very low");
    set_max_level(20);
    command("speech boom loudly");
    command("speak wizish");
}

void grab(object targ) {
    string dmg;
    int dam, dam1;
    if(!objectp(targ)) return;
    if("/daemon/saving_d"->saving_throw(targ,"breath_weapon"))
        dmg="enveloped";
    else
        dmg="singed";
    tell_object(targ,"%^RED%^The fire elemental lunges forward, grabs you, and "
    "you are "+dmg+" by its flames!");
    tell_room(environment(targ),"%^RED%^The fire elemental lunges forward "
    "and "+targ->query_cap_name()+" is "+dmg+" by its flames!", targ);
    dam = roll_dice(4,6)+6;
    dam1 = (roll_dice(4,6)+6)/2;
    set_property("magic",1);
    if(dmg=="torches") targ->do_damage("torso", dam);
        targ->do_damage("torso", dam1);
    remove_property("magic");
    return 1;
}

void catch_tell(string str){
    if(TP == TO) return;
    if(strsrch(str,"altar") != -1) {
        call_out("reply_back",5,"You want to know about the altar of fire?");
        step = 1;
        return;
    }
    if((strsrch(str,"yes") != -1) && step == 1) {
        if(!given) {
            call_out("reply_back",5,"Very well... I can't tell you much.  "+
            "It is the gateway into the world of my previous "+
            "master and it was sealed by him some many years "+
            "ago.  He doesn't like visitors.  I alone have "+
            "the key to get in.  Bring me the staff that the "+
            "withered crone in this forest carries and I'll "+
            "grant you that key.");
            return;
        }
        if(given) {
            call_out("reply_back",5,"Very well... I can't tell you much.  "+
            "It is the gateway into the world of my previous "+
            "master and it was sealed by him some many years "+
            "ago. He doesn't like visitors.  I alone had the "+
            "key to enter it, but I've given it away already.");
            return;
        }
    }
	/*if((strsrch(str,"jarrow") != -1 || strsrch(str,"Jarrow") != -1) 
	  && (step == 0)){ 
		call_out("reply_back",2,"What is it and who are you?"); 
      call_out("reply_back",4,"Why do you want to talk to Jarrow?");
      call_out("reply_back",6,"Don't answer, just begone before I kill you.");
		step = 1;
		return;
	}
	if((strsrch(str,"stones") != -1) && (step == 1)){ 
		call_out("reply_back",2,"What about them?"); 
      call_out("reply_back",6,"You think you would like to solve the quest?");
      call_out("reply_back",8,"Ok, you may enter, but be warned.");
      call_out("go_enter",10);
		step = 0;
		return;	
	}*/
	return;
}

void reply_back(string str){
        tell_room(ETO,"%^MAGENTA%^Giant fire elemental booms loudly%^WHITE%^: "+str,TO);
}

void receive_given_item(object ob){
    string *nams;
    if(ob->id("graystaff")) {
        command("say Very well, you have brought the staff...");
        ob->remove();
        
        command("emote reaches into his chest and feels around "+
        "before eventually pulling out a glowing ember "+
        "and tossing it to the ground.");
        new("/d/deku/misc/ember_key")->move(ETO);

        command("say there is the key you need.  You must simply "+
        "carry it before the altar and speak the name 'Kinorda'.  "+
        "I must warn you, you're a fool to set off on this quest.");
        given = 1;
        return 1;
    }
    command("say I want the staff from the withered crone "+
    "that wanders these woods.");
    nams = ob->query_id();
    command("give "+nams[0]+" to "+TPQN);
    return 1;
}

void reset() {
    ::reset();
    if(!random(5)) {
        given = 0;
    }
}

/*void go_enter() {
  write("The elemental motions you into the tower.");
  say("The elemental motions for "+TPQCN+" to enter the tower.");
  say("The elemental stares back to you as "+TPQCN+" enters the tower.");
  TP->move_player("/d/deku/open/entrance");
}*/

