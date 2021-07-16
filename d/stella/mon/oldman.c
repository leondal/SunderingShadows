inherit "/std/monster";
#include <std.h>

object player;

void create() {
  ::create();
  set_name("Old Man");
  set_id(({"man","old man","wizened old man"}));
  set("race", "human");
  set_gender("male");
  set_short("A wizened old man.");
  set_long("This is a wizened old man.  He is sitting just outside of the castle gates.  "
	   "He looks extremely depressed.  When he hears your footsteps, the old man looks "
	   "up hopefully and reaches out a hand to you beseechingly.");
  set_body_type("human");
  set_class("mage");
  set_guild_level("mage",60);
  set("aggressive", 0);
  set_size(2);
  set_overall_ac(-5);
  set_max_hp(500);
  set_hp(500);
    set_exp(25000);
  set_stats("strength",17);
  set_stats("constitution",16);
  set_stats("dexterity",18);
  set_stats("intelligence",20);
  set_stats("wisdom",20);
  set_stats("charisma",13);
  set_mob_magic_resistance("average");
  set_spell_chance(80);
  set_spells( ({"cone of cold","chain lightning","monster summoning vii","finger of death","ice storm"}) );
  set_emotes(5,({"The old man looks at you beseechingly.","The old man looks fearfully at the castle."}),0);
  enable_commands();
}

void init() {
      ::init();
      if(interactive(TP) && member_array("Stellar Quest",TP->query_quests()) == -1) {
        if(present("bootoken",TP)&&present("castoken",TP)&&
	   present("cygtoken",TP)&&present("pegtoken",TP)&&
	   present("scotoken",TP)&&present("leotoken",TP)&&
	   present("ursatoken",TP)&&present("dractoken",TP)){
	         call_out("complete_quest",1);
	         return;
	}
        add_action("quest_intro","nod");
        call_out("start_talk",1);
	call_out("start_talk2",10);
      }
}

void start_talk() {
    tell_object(TP,"Ahhh, finally someone has come! Do you think you could spare some time to help me?");
}
void start_talk2() {
    tell_object(TP,"Just nod if you wish to help me.");
}

void quest_intro(){
    tell_object(TP,"The old man smiles and says:  Excellent! Excellent!  Finally a brave "
		"adventurer willing to help me.\n\n"
		"I was once a great mage and astronomer.  I had created this fine castle "
		"to protect my most valued creation!  To protect my castle I had formed "
		"8 stellar guardians.  Alas, while I was distracted by my research, an "
		"evil Mage imprisoned my guardians.  Fortunately, he could not kill them or "
		"move them outside of my castle, because he did not know their true names!  "
		"With my guardians imprisoned, the evil mage found it easy to take over my "
		"castle.\n\n"
		"He's gone now, but he's left behind his own guardians ... the mundanoids.  "
		"I cannot seem to defeat them, and I'm now forced to wait outside my home "
		"in the hope that someone will come who can defeat them.\n\n"
		"If you survive the mundanoids, you must find my 8 guardians and free them.  "
		"The only way to free them is to \"summon\" them by using their true names.  "
		"I dare not tell you their true names for fear that they will be overheard.  "
		"You must find my Star Maze and learn their true names!\n\n"
		"Good Luck brave adventurer!");
}

void complete_quest() {
    object ob;

    if (member_array("Stellar Quest",TP->query_quests()) == -1){
        tell_object(TP,"You've done it!!!   I had almost ceased to hope!  "
		"You have my eternal gratitude!  I am now free to return "
		"to my research!  ");

  	TP->set_quest("Stellar Quest");
TP->fix_exp(2000000, TP);
   	present("bootoken",TP)->remove();
    	present("castoken",TP)->remove();
   	present("cygtoken",TP)->remove();
   	present("pegtoken",TP)->remove();
   	present("scotoken",TP)->remove();
  	present("leotoken",TP)->remove();
   	present("ursatoken",TP)->remove();
   	present("dractoken",TP)->remove();
  	tell_object(TP,"You feel some gain in experience.");
  	tell_object(TP,"%^BOLD%^You have completed the Stellar Quest!%^RESET%^");
  	remove();
     }
}







