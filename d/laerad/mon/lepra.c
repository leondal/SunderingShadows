//Coded by Bane//
#include <std.h>
inherit WEAPONLESS;
void create(){
    ::create();
    set_id(({"leprachaun","Leprachaun"}));
    set_name("Leprachaun");
    set_short("A little Leprachaun");
    set_long(
	"A small green man stands before you.  Dressed in a green "+
	"suit covered in clovers he hops merrily around the room.  "+
	"A dark green top hat covers his head.  There was an old "+
	"fable that if you could capture one of these creatures it "+
	"would grant you a wish."
    );
    set_body_type("human");
    set_race("leprachaun");
    set_gender("male");
    set_size(1);
    set_alignment(5);
    set_hd(20,20);
    set_hp(230);
    set_overall_ac(-9);
    set_exp(10000);
    set("aggressive",0);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_max_level(15);
    set_stats("strength",20);
    set_stats("dexterity",22);
    set_stats("charisma",21);
    set_stats("constitution",16);
    set_stats("wisdom",24);
    set_stats("intelligence",23);
    add_money("gold",3000+random(1000));
    add_money("silver",2000+random(500));
    add_money("platinum",random(50)+50);
    if(random(20) < 1){
	new("/d/laerad/obj/ring_stars")->move(this_object());
        command("wear ring");
    }
    set_base_damage_type("bludgeoning");
    set_attack_limbs(({"right hand","left hand"}));
    set_attacks_num(2);
    set_damage(1,6);
    set_hit_funcs((["right hand":(:TO,"confetti":),"left hand":(:TO,"confetti":)]));
    set_funcs(({"twinkle","toast","seizure","dance","arrow"}));
    set_func_chance(70);
}
void confetti(object targ){
    if(!interactive(targ)){
	tell_room(ETO,""+targ->query_cap_name()+" explodes into confetti as the Leprachaun hits it!");
	force_me("cackle");
	targ->set_hp(-1);
	return 1;
    }
}
void twinkle(object targ){
    tell_room(ETO,"%^BOLD%^CYAN%^The Leprachaun twitches his nose.");
    if(!"daemon/saving_d"->saving_throw(targ,"rod_staff_wand")){
	call_out("move_me",1,targ);
	return 1;
    }
    tell_room(ETO,"%^BOLD%^The room darkens momentarily.");
    return 1;
}
void move_me(object targ){
    switch(random(4)){
	case(0):
	    tell_object(targ,"%^BOLD%^A dimensional gate appears and swallows you up!");
	    tell_room(ETO,"%^BOLD%^A dimensional gate appears and swallows "+targ->query_cap_name()+" up!",targ);
	    targ->move("/d/shadow/room/city/forkroad");
	    targ->describe_current_room(1);
	    break;
	case(1):
	    tell_object(targ,"%^BOLD%^A dimensional gate appears and swallows you up!");
	    tell_room(ETO,"%^BOLD%^A dimensional gate appears and swallows "+targ->query_cap_name()+" up!",targ);
	    targ->move("/d/deku/town/road5");
	    targ->describe_current_room(1);
	    break;
	case(2):
	    tell_object(targ,"%^BOLD%^A dimensional gate appears and swallows you up!");
	    tell_room(ETO,"%^BOLD%^A dimensional gate appears and swallows "+targ->query_cap_name()+" up!",targ);
	    targ->move("/d/tharis/road/eroad10");
	    targ->describe_current_room(1);
	    break;
	case(3):
	    tell_object(targ,"%^BOLD%^A dimensional gate appears and swallows you up!");
	    tell_room(ETO,"%^BOLD%^A dimensional gate appears and swallows "+targ->query_cap_name()+" up!",targ);
	    targ->move("/d/deku/dark/stair2");
	    targ->describe_current_room(1);
	    break;
    }
}
void arrow(object targ){
    tell_object(targ,"%^BOLD%^The Leprachaun pulls out a bow and fires an arrow at you!");
    tell_room(ETO,"%^BOLD%^The Leprachaun pulls out a bow and fires an arrow at "+targ->query_cap_name()+"!",targ);
    if(!"daemon/saving_d"->saving_throw(targ,"spell")){
	tell_object(targ,"%^BOLD%^YELLOW%^The arrow hits you in the chest and you collapse to the ground unconscious.");
	tell_room(ETO,"%^BOLD%^YELLOW%^The arrow hits "+targ->query_cap_name()+" in the chest and "+targ->query_subjective()+" collapses to the ground.",targ);
	targ->set_paralyzed(50,"You are in a deep slumber.");
	return 1;
    }
    tell_object(targ,"%^BOLD%^YELLOW%^The arrow misses you.");
    tell_room(ETO,"%^BOLD%^YELLOW%^The arrow misses "+targ->query_cap_name()+".",targ);
    return 1;
}
void dance(object targ){
    object ob;
    if(targ->query_property("transfixed")) return;
    if(!"daemon/saving_d"->saving_throw(targ,"spell")){
	tell_object(targ,"%^BOLD%^GREEN%^The Leprachaun does a crazy dance....you feel like joining him!");
	tell_room(ETO,"%^BOLD%^GREEN%^The Leprachaun does a crazy dance..."+targ->query_cap_name()+" starts to join in!",targ);
	targ->set_property("transfixed",1);
	ob = new("/d/laerad/mon/obj/dance");
	ob->move(targ);
	ob->start_dance();
	targ->cease_all_attacks();
	TO->remove_attacker(targ);
	call_out("dancing",5,targ,ob);
	return 1;
    }
    tell_object(targ,"%^BOLD%^GREEN%^The Leprachaun does a crazy dance...you stand baffled for a second.");
    tell_room(ETO,"%^BOLD%^GREEN%^The Leprachaun does a crazy dance..."+targ->query_cap_name()+" stands baffled for a second.",targ);
    return 1;
}
void dancing(object targ, object ob){
    if(!objectp(targ)) return;
    if(!targ->query_property("transfixed")) return;
	ob->disable_me(1);
//added the next 2 lines here too to stop him from attacking again and auto-combat
//from running if a spell hits after the dance has started.  *Styx*  5/10/02
	targ->cease_all_attacks();
	TO->remove_attacker(targ);
	switch(random(30)){
	    case(0):
		tell_object(targ,"%^BOLD%^You dance along happily with the Leprachaun.");
		tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" dances along happily with the Leprachaun.",targ);
		break;
	    case(1):
		targ->force_me("laugh");
		targ->force_me("hug leprachaun");
		break;
	    case(2):
		tell_object(targ,"%^BOLD%^You sing a merry Irish song and watch the Leprachaun dance away.");
		tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" sings a merry Irish song and watches the Leprachaun dance away.",targ);
		break;
	    case(3):
		targ->force_me("chuckle");
		break;
	    case(4):
		targ->force_me("smile happily");
		break;
	    case(5):
		tell_object(targ,"%^BOLD%^You clap and dance with pure delight!");
		tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" claps and dances with pure delight!",targ);
		break;
	    case(6):
		targ->force_me("laugh merrily");
		break;
	    case(7):
		targ->force_me("cheer");
		break;
	    case(8):
		tell_object(targ,"%^BOLD%^You laugh and sing as the Leprachaun pipes a tune on his flute.");
		tell_room(ETO,"%^BOLD%^"+targ->query_cap_name()+" laughs and sings as the Leprachaun pipes a tune on his flute.",targ);
		break;
	    case(9):
		targ->force_me("giggle happily");
		break;
	}
	ob->disable_me(0);
	call_out("dancing",5,targ,ob);
}
void toast(object targ){
    tell_room(ETO,"The Leprachaun closes his eyes and raises his hands up into the air.");
    if(!"daemon/saving_d"->saving_throw(targ,"breath_weapon")){
	tell_object(targ,"%^BOLD%^RED%^A pillar of flame tears from the ground beneath you engulfing your body in fire!");
	tell_room(ETO,"%^BOLD%^RED%^A pillar of flame tears from the ground beneath "+targ->query_cap_name()+" engulfing "+targ->query_possessive()+" body in fire!",targ);
	targ->do_damage(targ->return_target_limb(),roll_dice(8,8)+10);
	return 1;
    }
    tell_object(targ,"%^BOLD%^RED%^A pillar of flame tears from the ground beneath you knocking you aside!");
    tell_room(ETO,"%^BOLD%^RED%^A pillar of flame tears from the ground beneath "+targ->query_cap_name()+" knocking "+targ->query_objective()+" aside!",targ);
    targ->do_damage(2,10);
    return 1;
}

void seizure(object targ){
    if(!"daemon/saving_d"->saving_throw(targ,"paralyzation_poison_death")){
	tell_object(targ,"%^BOLD%^BLUE%^The Leprachaun reaches out and touches you on the cheek.");
	tell_room(ETO,"%^BOLD%^BLUE%^The Leprachaun reaches out and touches "+targ->query_cap_name()+" on the cheek.",targ);
	call_out("wrack",5,targ);
	return 1;
    }
    tell_object(targ,"%^BOLD%^BLUE%^The Leprachaun reaches for you but misses.");
    tell_room(ETO,"%^BOLD%^BLUE%^The Leprachaun reaches for "+targ->query_cap_name()+" but misses.",targ);
    return 1;
}
void wrack(object targ,int num){
   if(objectp(targ)) return;
    switch(num){
	case(1):
	    tell_object(targ,"You are wracked by an incredible pain!");
	    tell_room(ETO,""+targ->query_cap_name()+" screams out in pain!",targ);
	    targ->do_damage(targ->return_target_limb(),roll_dice(1,10));
	    break;
	case(2):
	    tell_object(targ,"The seizure tears through your body!");
	    tell_room(ETO,""+targ->query_cap_name()+" screams out in pain!",targ);
	    targ->do_damage(targ->return_target_limb(),roll_dice(2,8));
	    break;
	case(3):
	    tell_object(targ,"You scream out in pain as the seizure burns through your body like fire!");
	    tell_room(ETO,""+targ->query_cap_name()+" screams out in pain!",targ);
	    targ->do_damage(targ->return_target_limb(),roll_dice(3,6));
	    break;
	case(4):
	    tell_object(targ,"You drop to the ground in exhaustion as the seizures disappear.");
	    tell_room(ETO,""+targ->query_cap_name()+" drops to the ground.",targ);
	    targ->set_paralyzed(20,"You are too exhausted to move.");
	    return;
	    break;
    }
    num++;
    call_out("wrack",5,targ,num);
    return;
}
void init(){
    ::init();
    add_action("slow","rush");
    add_action("slow","stab");
    add_action("slow","rebuke");
    add_action("slow","demonbolt");
    add_action("slow","slam");
}
int slow(){
    write("The Leprachaun giggles as he easily dodges aside your pitiful attack.");
    return 1;
}
void heart_beat(){
    ::heart_beat();
    if(!objectp(TO)) return;
    if(query_hp() < 198)
        add_hp(1);
}
void die(object targ){
    force_me("scream out in pain");
    ::die(targ);
}
void paralyzed(int time,string message){return 1;}
