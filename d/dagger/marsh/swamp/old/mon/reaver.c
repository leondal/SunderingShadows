#include <std.h>
#include "/d/dagger/marsh/tower/short.h"
#define DSOBJ "/d/dagger/marsh/tower/obj/dsobj.c"
inherit MONSTER;
#define SHDIR "/d/dagger/marsh/swamp/rooms/"+
int wander;
int xx;
int lev, roll;

void create() {
object ob;
    :: create();
    set_name("reaver");
    set_id(({
	"reaver","demon reaver"
      }));
    set_short("%^RESET%^%^RED%^Reaver%^RESET%^");
    set_long(
      "%^RESET%^%^RED%^"
      "The humanoid which stands before you is one of an extremly "
      "vile nature. Pure worshippers of evil and the (un)dead, the "
      "have adopted a cult like magical craft of immense power. This "
      "power has long often been sought after by users of magic across "
      "the land but only those willing to cross over to the vile side "
      "ever can tame it. Even then it is the power which controls the reaver, "
      "not the reaver who controls the craft. Loyal servants to demons, however "
      "they have been known to serve greater apparitions which dwell in "
      "the darkness of our lands. Their skin is rotted and matted in an array "
      "of scalding from unknown burns and festered with disease. The one "
      "before you wears a long robe stained with ancient blood of power."
      "%^RESET%^"
    );
    set_gender("male");
   set_property("add kits",10);
    set_property("magic", 1);
    set_hd(30,4);
    set_size(2);
    set_property("magic",1);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(-10);
    set_max_hp(400);
    set_hp(400);
    set_property("no bump",1);
    set_mob_magic_resistance("average");
    set_exp(28000);
    set_body_type("humanoid");
    set_race("human");
    set_class("fighter");
   set_max_level(33);
    set_alignment(9);
    set_stats("strength",24);
    set_stats("constitution",24);
    set_stats("dexterity",24);
    set_stats("wisdom",24);
    set_stats("intelligence",24);
    set_stats("charisma",-10);
    set("aggressive",50);
/*
    new( OPATH "scythe.c" )->move(TO);
    command("wield scythe in left hand");
    new( OPATH "scythe.c" )->move(TO);
    command("wield scythe in right hand");
*/
        ob = new(OPATH"greater_scythe");
    if(random(3)){
       ob->set_property("monsterweapon",1);
    }
    ob->move(TO);
    command("wield scythe");
    new( OPATH "robe" )->move(TO);
    command("wear robe");
    //ob = new("/d/common/obj/potion/extra_heal");
    //ob->set_uses(3);
    ob->move(TO);
    add_money("gold",random(2000)+400);
    set_funcs(({"moves"}));
    set_func_chance(50);
    remove_property("swarm");
    set_emotes(3, ({
	"%^RED%^Visions of bloodlust fill your mind!%^RESET%^",
	"%^RED%^The reaver attempts to possess you!%^RESET%^",
	"%^RED%^The reaver utters a guttural chant of abomination!%^RESET%^",
	"The reaver fails to gate.",
	"%^BOLD%^%^BLUE%^The reaver hurls a %^MAGENTA%^bolt%^BLUE%^ "
	"of pure evil at you!%^RESET%^",
      }),1);
}

/* this was part of the bolt of evil emote but prompted a bug report so I'm zapping it.
   Styx 4/5/03
%^RESET%^\nYour torso is severed!\nHp: -2560\n\n"
	"You die.\n%^BOLD%^%^GREEN%^Death hast taken Grazzt from our midsts!!!
*/


int moves() {
    object ob = this_object();
    object targ = ob->query_current_attacker();
    object rab;
    object Gob;
    int i;
    xx=random(4)+1;
    if((int)ob->query_hp() < 60) xx = 1;

    switch(xx) {
    case 1:
	tell_room(ETO, "%^BOLD%^%^BLUE%^The reaver invokes a spell of hatred to his masters!\n"
	  "%^RESET%^%^BLUE%^An Demonstorm brews in the area!%^RESET%^" );
	Gob = new(DSOBJ);
	Gob->move(ETO);
	Gob->start_obj();
	return 1;

    case 2:
	tell_room(environment(targ),
	  "%^BOLD%^%^RED%^"
	  "The earth opens and a host of demonic beings flow from the "
	  "depths below. "
	  ,targ); 
	tell_object(targ,
	  "%^BOLD%^%^RED%^"
	  "Cackling demons appear all around you! " 
	  "Before you can run, they dive into your body burning " 
	  "you to your soul!%^RESET%^"
	);
	tell_room(environment(targ), 
	  "%^CYAN%^%^BOLD%^"+
	  (string)targ->query_cap_name()+" screams "
	  "in agony as flaming spirits leap into "+
	  targ->query_possessive()+" body. "
	  ,targ);
	tell_object(targ,
	  "%^RESET%^%^RED%^" 
	  "You scream in terror as shadowy forms rip bits of "
	  "your essence from your soul!%^RESET%^"
	);
	for(i=0;i<10;i++) {
	    tell_room(environment(targ), 
	      "%^GREEN%^%^BOLD%^"+
	      (string)targ->query_cap_name()+" screams "
	      "in agony as "+targ->query_possessive()+
	      " soul is torn!"
	      ,targ);
	    tell_object(targ,
	      "%^RESET%^%^GREEN%^" 
	      "Your soul is %^RED%^burned%^GREEN%^ and "
	      "%^RED%^torn%^GREEN%^!%^RESET%^"
	    );
	    targ->do_damage("torso",random(5)+5);
	}
	return 1;

    case 3:
	if((int)TO->query_hp() < 30) return 1;
	for(i=0;i<10;i++) {
	    say(
	      "%^CYAN%^The reaver mutters a demonic plea for health!"
	      "%^RESET%^"
	    );
	    TO->add_hp(roll_dice(3,4));
	}
	tell_object(targ,
	  "%^BOLD%^%^BLUE%^The reaver hurls a %^MAGENTA%^bolt%^BLUE%^ "
	  "of pure evil "
	  "at you!%^RESET%^"
	);
	tell_room(environment(targ),
	  "%^BOLD%^%^BLUE%^The reaver hurls a %^MAGENTA%^bolt%^BLUE%^ "
	  "of pure evil "
	  "at "+targ->query_cap_name()+"!%^RESET%^"
	  ,targ);
	targ->do_damage("head",roll_dice(8,8));
	return 1;

    case 4:
	if(present("krykoth",ETO)) return 1;
	tell_object(targ,
	  "%^GREEN%^The reaver chants the ancient and demonic oath of the gate!%^RESET%^"
	);
	tell_room(environment(targ),
	  "%^GREEN%^ The reaver chants the ancient and demonic oath of the gate!%^RESET%^"
	  ,targ);
	say("%^BOLD%^%^RED%^A krykoth fades into view!%^RESET%^");
	new( MPATH "krykoth.c")->move(environment(TO));
	TO->add_exp(4500);
	if(rab = present("krykoth",environment(TO))) {
	    rab->force_me("kill "+targ->query_name());
	}
	return 1;
    }
}

void set_paralyzed(int time,string message){return 1;}
void heart_beat() {
    string *exits;
    string exitn;	
    int i,j;
    ::heart_beat();
    // Thanks to Tristan for example for this.
    if(!objectp(TO)) return;
    if(wander > 20 && query_attackers() == ({})){
	exits = environment(TO)->query_exits();
	i = sizeof(exits);
	if(!i) return;
	j = random(i);
	exitn = (string)environment(TO)->query_exit(exits[j]);
	  if(exitn != SHDIR "m44") {
	      TO->force_me(exits[j]);
		wander = 0;
		return;
	    } else {
		  return;
	      }
	  } else {
	      wander = wander + 1;
	      return;
	  }
      }
