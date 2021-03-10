#include <std.h>

#include "/d/darkwood/darcy/darcy.h"

inherit "/std/monster";

void init() {
  ::init();
  add_action("limb_fun","con");
  add_action("limb_fun","grin");
  add_action("limb_fun","pat");
  add_action("limb_fun","throw");
  add_action("limb_fun","bump");
  add_action("limb_fun","stab");
  add_action("limb_fun","rush");
  add_action("limb_fun","say");
  if(interactive(TP)){ 
    call_out("do_kill",10,TP);
  }
}

void create() {
  ::create();

  set_property("no_paralyze", 1);
  set_property( "no_scry", 1 );
  set_name("malgoroth");
  set_id( ({ "malgoroth", "guardian" }) );
  set_hd(32,7);
  set_short("Malgoroth, Guardian of the Pit");
  set_long(
  "  This is Malgoroth, Guardian of the Pit of Svilaz and minor demon\n"+
  "from an unknown lower plane. He has made his home in the pit to\n"+
  "usher sacrifices to that plane so they can be devoured by his\n"+
  "fellows and then have their spirits trapped in torment there\n"+
  "forever.\n"
  "\n"
  "  Malgoroth looks like a man, only 15 feet tall with 14 blood red\n"+
  "eyes arrayed all over his face. His mouth is a long steel hard beak\n"+
  "designed to catch and carry off victims while leaving his limbs free\n"+
  "to attack.\n"
   );
  set("race", "Demon" );
  set_gender( "male" );
  set_body_type("human");
  set_overall_ac(-12);
  set_alignment(9);
  set_stats("intelligence", 23);
  set_stats("wisdom", 25);
  set_stats("charisma",8);
  set_stats("strength", 25);
  set_stats("dexterity", 25);
  set_stats("constitution", 25);
  set_class("antipaladin");
  set_guild_level("fighter",24);
  set_guild_level("antipaladin",24);
  set_thief_skill("move silently",95);
  set_thief_skill("hide in shadows",95);
  add_search_path("cmds/thief");
  set_invis();
  set_max_hp(350);
  set_hp(350);
  set_exp(60000);
  set_mob_magic_resistance("average");
    set_emotes(19, ({
    "Malgoroth says: I will sacrifice your soul!",
    "Malgoroth cackles wildly.",
    "Malgoroth says: Even death cannot release you from our inevitable torments!",
    "Malgoroth seems to drool over the taste of your brains, served fresh and bloody. ",
		"Malgoroth whispers: There will be no rest for you until the end "+
		"of time!",
	    "Malgoroth screams: Y O U  W I L L  B U R N !!!!",
    "Malgoroth slices deep into your entrails!",
		"Malgoroth says: Stay right there, I've always wondered if I could "+
		"sever a mortal's head in one slice.",
	  "Malgoroth yells: DESTROY! DESTROY! DESTROY! ",
		"Malgoroth whispers to you: You think I'm bad...wait till you meet"+
		" Grimtooth!",
    }), 1);
  set_funcs(({
    "dart"  }
  ));
  set_func_chance(25); 
  set("aggressive","attack_fun");
  new( EQUIPDIR+"desecrator" )->move(TO);
  command("wield sword in left hand");
  new( EQUIPDIR+"desecrator" )->move(TO);
  command("wield sword in right hand");
}

void do_kill(object ob){
  string who;
  if(!TO->query_current_attacker()) return;
  if(objectp(ob) && present(ob,environment(TO))){
    who = ob->query_name();
    ("/cmds/spells/d/_dispel_magic.c")->use_spell(TO,who,10,100,"mage");
    call_out("do_kill",20,ob); 
  }
}

void dart(object targ) {
  command( "say Stop trying to resist your fate!");
  command( "say Surrender to me, "+targ->query_cap_name()+" or I will feast on your eyes.");
  targ->do_damage("head",roll_dice(6,8));
  targ->set_paralyzed(random(20)+10,"You are still reeling from the blow!");
  return 1;
}

int limb_fun(string str) {
  object targ;
  targ = this_player();
  if((string)targ->query_name() == "thorn") {
    command( "grin thorn" );
    return 1;
  }
  else {

    command( "say Have a taste...of your %^RED%^BLOOD, "+
      this_player()->query_cap_name()+". ");

    targ->do_damage("head",roll_dice(6,6));
    targ->set_paralyzed(random(20)+10,"You are still reeling from the blow!");
    return 1;
  }
}

int attack_fun() {
  object ob;
  if( !this_player() ) return 1;
  if( !userp(this_player()) ) return 1;
  if( (string)this_player()->query_name() == "thorn") return 1;
  if( this_player()->query_ghost() ) return 1;
  if( (int)this_player()->query_alignment() != 9 ) {
    say("It is the likes of you who bring ruin to my people!");
    say("Lords of the Pit, I have before me a sacrifice for thee, and it is called "+
      (string)this_player()->query_cap_name()+" by name!");
    call_out("slash",1,TP);
    write("%^RED%^BOLD%^Your blood spills out onto the ground!");
    set_invis();
    return 1;
  }
  else {
    say("%^RED%^You are now to become a treat for my bretheren's tea party!");
    call_out("sic_em",1,TP);
    return 1;
  }
}

void heart_beat() {
  ::heart_beat();

  if(present("corpse",environment(this_object())))
    if(!query_current_attacker() ) {
      command("get all from corpse");
      command("grin");
      command("get corpse");
      command("offer corpse");
      command("chuckle");
      set_invis();
    }
  return;
}

void slash(object targ) {
  int mod, i;
  mod = 5;
  if(TP->is_class("mage")) mod = 2;
	for(i=0;i<5;i++) {
	  write("%^RED%^Someone plunges his sword into your gut!");
	  say("%^RED%^Someone plunges his dagger into "+
	    targ->query_cap_name()+"!");
	  targ->do_damage("head",random(5)+mod);
	}
  command( "tell thorn Buahahahha...i just stabbed "+TPQCN+"! ;)");
  command( "kill "+targ->query_name() );
  TP->add_follower(TO);
}

void sic_em(object targ) {
  if((string)TO->query_current_attacker() != targ) {
    if(random(10) < 7) {
      command( "kill "+targ->query_name() );
    }
    else {
      say("Hmm...Wait here "+targ->query_cap_name()+".");
      say("I will return shortly to bring you to your torment!");
      command("east");
      command("north");
      command("west");
      command("south");
    }
  }
  else {
    command( "say You are mine, as surely as you draw your pathetic breaths now!" );
  }
}
void set_paralyzed(int time,string message){ 
  return 1; 
}

void die(object ob) {
  message("environment",
  "%^RED%^Malgoroth is banished to the Lower Planes...for now...."
    ""
    ,environment(ob));
  message("info", "%^BLUE%^"
  "The demons of the Lower Planes tear hungrily at the spirit of "
    "Malgoroth as he returns to his home in the Netherworld!"
    ,users());
  ::die();
}
