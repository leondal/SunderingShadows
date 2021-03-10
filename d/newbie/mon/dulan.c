#include <std.h>
#include <move.h>
inherit SCRIBE;

int end_game(string str);
void long_desc(string str);

string long;
object ob;

void create() {
   ::create();
   set_name("dulan");
   set_id(({"scribe", "dulan", "Dulan", "occone"}));
   set_race("human");
   set_gender("male");
   set_short("Dulan Occone, Scribe of Offestry");
   set_long("Newly moved into the area, Dulan Occone has recently set up shop in Offestry. He is a young man trying to make a living with his skills at writing. Dulan smiles at you broadly, eagerly awaiting your request. He will be happy to <write> things down for you, for a small price.  "+
	"He will <translate [item] to [language] for you.  "+
	"He can also give you an estimate of how much it will cost to translate an "+
	"item, by using <estimate [item]>");
   set_level(1);
	set_scribe_name("dulan");
//        set_region("all");
   set_body_type("human");
   set_class("mage");
   set("aggressive", 0);
   set_alignment(5);
   set_size(2);
   set_stats("intelligence",6);
   set_stats("wisdom",4);
   set_stats("strength",13);
   set_stats("charisma",3);
   set_stats("dexterity",8);
   set_stats("constitution",7);
   set_max_mp(0);
   set_mp(query_max_mp());
   set_hd(1, 1);
   set_max_hp(query_hp());
   set_max_sp(query_hp());
   set_sp(query_max_sp());
   add_money("silver",random(10));
   add_money("gold",random(5));
   add_money("copper",random(20));
   set_exp(1);
   set_nwp("writing", 4);
   command("speech say cheerily");
        new("/d/newbie/obj/misc/lpouch.c")->move(TO); //added in on advice of Tristan that we need more stealable things in newbieland Ts
}

void init() {
   ::init();
   if(wizardp(TP) || (avatarp(TP) && TP->query_name() == TP->query_vis_name()))
      return;
   force_me("say Welcome! Welcome to my shop.");
   force_me("smile broadly");
   force_me("I am happy to put whatever you need into written form, for a small fee of course.");
}

