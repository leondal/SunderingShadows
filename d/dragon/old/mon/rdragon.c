//MY red dragon ... age catagory 6 meaning a lot of leway to make a bigger
//bad boy

#include <std.h>
#include <daemons.h>
#define HOME "/d/dragon/mts/lair"

inherit MONSTER;

int breath_attacks, done;
int rake;

void do_rake(object target);
void breath(object target);

void create() {
	::create();
	set_id(({"cathardon","dragon","Dragon","red dragon","red"}));
  set_name("cathardon");
	set_body_type("dragon");
	set_race("dragon");
	set_gender("male");
	set("short","Cathardon, the adolescent red dragon");
	set("long",
@OLI
	This is the dragon that has been terrifying the surrounding 
realms. Cathardon is yet young for a Red, still eager to advance his 
treasure count.  His arrogance sickens you.  Yet you can clearly see
that it is well founded.  What really terrifies you that this dragon
isn't half grown, and that one day a full grown one could attack
your family!
OLI
	);
	set_hd(18,4);
	set_hp(350);
	set_exp(15000);
	set_overall_ac(-5);
	set("aggressive","runinto");
	set_guild_level("mage",9);
	set_spells(({"magic missile",
			"sleep",
			}));
	set_spell_chance(30);
	new("/d/dragon/old/mon/weapons/claw")->move(TO);
	set_wielding_limbs(({"right foreclaw","left foreclaw"}));
	command("wield claw in right foreclaw");
	new("/d/dragon/old/mon/weapons/claw")->move(TO);
	command("wield claw in left foreclaw");
	add_money("copper",random(6) * 6000);
	add_money("silver",random(10)* 2000);
	add_money("gold",random(10)*2000);
	}

void runinto() {
	if(TP->query_level() < 15 || TP->query_ac() > 2) {
    if(!done) {
       set_funcs(({"breath"}));
	  	 set_func_chance(20);
         }
	   }
	else{
	   set_funcs(({"breath"}));
	   set_func_chance(80);
	   done = 1;
	}
	kill_ob(TP,1);
}

void breath(object target) {
	int damage;

	if(((string)target->query_property("strength") == "breath weapon") ||( 
(string)target->query_property("strength") == "fire")) {
            tell_object(target,"%^RED%^%^BOLD%^ Cathardon belches a cone of fire at you!!");
		tell_object(target,"%^RED%^BOLD%^ The flames come to within inches of you and then seem to stop!");
      tell_room(ETO,"Cathardon sends a stream of flame towards "+target->query_cap_name()+", but it seems to stop short.",target);
		breath_attacks += 1;
		if(breath_attacks >= 3) {
			set_func_chance(0);
			call_out("try_again",60);
		}
	}
		else {
		tell_object(target,"%^BOLD%^%^RED%^Cathardon belches a cone of flame toward you!");
		tell_object(target,"%^BOLD%^%^GREEN%^You are burned harshly");
		tell_room(environment(TO),"%^BOLD%^%^RED%^Cathardon belches a cone of fire that overwhelms "+target->query_cap_name()+"!!",target);
		damage = (roll_dice(12,10)) + 6;
		if(SAVING_D->saving_throw(target,"breath weapon")) 
			damage /= 2;
		target->do_damage("torso",damage);
	}
}


void try_again() {
	breath_attacks -= 1;
	set_func_chance(100);
	}

void set_rake(object target) {
	rake += 1;
        if(rake == 2) {
		do_rake(target);
	}
}

void heart_beat() {

	rake = 0;
	::heart_beat();
	}

void do_rake(object target) {
	
	int damage;
    tell_object(target,"%^BOLD%^%^GREEN%^ Cathardon, having gotten both claws into you, rakes them down your body!!");
	tell_room(environment(TO),"%^BOLD%^%^RED%^Cathardon holds onto "+target->query_name()+" and rakes his claws down 
"+target->query_possessive()+" body!",target);
	damage = roll_dice(1,10);
	target->do_damage("torso",damage);
}

void init() {
	string *exits;
	int i;
	object *inven;

	exits = (string *)environment(TO)->query_exits();

	for(i = 0;i<sizeof(exits);i++) 
	    add_action("chase",exits[i]);
	if((object *)TO->query_attackers() != ({})){
		inven = all_inventory(environment(TO));
		for(i=0;i<sizeof(inven);i++){
			if(living(inven[i]) && inven[i] != TO) kill_ob(inven[i],1);
		}
 	}
	::init();
}

int chase() {
	string verb;
	verb = query_verb();
	if((object *)TO->query_attackers() != ({})) 
	call_out("go",1,verb);
	return 0;
}
void go(string verb){
	remove_call_out("home");
	command(verb);
	call_out("home",60);
}


void home() {
	if((object *)TO->query_attackers() == ({})){
		tell_room(environment(TO),"%^BOLD%^%^RED%^ Cathardon 
wings home worried about his hords!!");
		TO->move(find_object_or_load(HOME));
		 tell_room(environment(TO),"%^BOLD%^%^RED%^ Cathardon 
wings in to check on his hords!");
	} else call_out("home",30);
}
