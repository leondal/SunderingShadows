//cut exp. from 750 to 250 - was way too much comparing to difficulty  Styx 8/3/01
//updating the old files to use the new exp functions for standardized
//exp values. ~Circe~ 2/4/13
#include <std.h>
inherit MONSTER;

void create() {
    ::create();
	set_name("dwarf");
	set_id( ({ "dwarf","guard","mountain dwarf" }) );
	set_race("dwarf");
	set_gender("male");
      set_short("Mountain dwarf");
      set_long("This stout mountain dwarf is rather short at four feet "+
         "tall but broad.  His face is a deep, ruddy brown, and he has "+
         "bright blue eyes.  His long, black hair is pulled back and bounded "+
         "at the base of his neck by a spiralling silver clasp.  His matching "+
         "beard is well-groomed and worn in several thick braids.  He is dressed "+
      "in earth tones and wears several jewelled rings on his fingers.  He "+
         "is armed with a fearsome battleaxe.");
	set_level(8);
	set_body_type("human");
      remove_property("swarm");
  	set_alignment(1);
        set_size(2);
      set_hd(6,1);
      set_monster_feats(({"parry"}));
   	set_stats("intelligence",6);
   	set_stats("wisdom",4);
   	set_stats("strength",17);
   	set_stats("charisma",3);
      set_stats("dexterity", 15);
      //set_exp(250);
//      set_exp(500);
      set_new_exp(8,"low");
      set_hp(82);
   	set_stats("constitution",17);
   	set_max_mp(0);
   	set_mp(query_max_mp());
	set_max_hp(query_hp());
	set_max_sp(query_hp());
	set_sp(query_max_sp());
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        new("/d/common/obj/weapon/battle_axe")->move(TO);
        command("wield axe");
	add_money("silver",random(10));
	add_money("gold",random(50));
      set_emotes(2, ({"%^MAGENTA%^Dwarf says:%^RESET%^ Beware if you "+
         "adventure the caverns of Echoes Mountains.",
         "%^MAGENTA%^Dwarf says:%^RESET%^ A group of adventurers who "+
         "had bested the goblins in the strongold "+
         "ventured down below and returned victorious.",
         "%^MAGENTA%^Dwarf says%^RESET%^: Ogres and others have "+
         "invaded below, beware!",
         "The dwarf polishes his axe."
   }), 0);
   set_moving(1);
   set_speed(120);
   set_nogo(({"/d/shadow/room/mountain/road6"}));
   command("speak wizish");
}

void init() {
   string race;
   ::init();
   race = (string)TP->query_race();
   if(!TP->query_invis()){
      if(race == "ogre" || race == "hobgoblin" || race == "bugbear" || race == "troll") {
        force_me("say %^RED%^I'll kill ya or die tryin' ya foul overgrown beast!");
        force_me("kill "+race);
      }
      if(race == "drow" || race == "goblin" || race == "kobold") {
        force_me("say %^BOLD%^%^RED%^Get out or one of us dies ya foul evil invader!");
        force_me("kill "+race);
      }
   }
}
