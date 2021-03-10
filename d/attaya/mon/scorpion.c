//Octothorpe (12/21/09)
//Attaya, Warlock
//Original by Thundercracker

#include <std.h>
inherit WEAPONLESS;

create(){
   ::create();
   set_name("kinnesarudan warlock");
   set_id(({"warlock","hooded","apparition","hooded apparition"}));
   set_short("%^BOLD%^%^BLACK%^h%^RESET%^oo%^BOLD%^%^BLACK%^d%^RESET%^e"+
      "%^BOLD%^%^BLACK%^d %^RESET%^a%^BOLD%^pp%^RESET%^a%^BOLD%^r"+
	  "%^RESET%^i%^BOLD%^t%^RESET%^io%^BOLD%^n%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^This hooded apparition is a former "+
      "member of the cabal of spellcasters that served C'Taro, the last "+
	  "Kinnesarudan emperor.  It is cloaked in a long, ragged robe which "+
	  "completely hides the form of the apparition.  The hood of the "+
	  "robe is pulled down low over the head, and those parts not "+
	  "obscured by the hood are enveloped in complete darkness, "+
	  "making it completely impossible to determine if anything is "+
	  "actually there or not.%^RESET%^");
   set_race("undead");
   set_gender("male");
   set_body_type("human");
   set_hd(30,3);
   set_class("mage");
   set_level(30);
   set_mlevel("mage",30);
   set_property("swarm",1);
   set_spell_chance(90);
   set_guild_level("mage",30);
   set_mob_magic_resistance("average");
   set_property("spell penetration",15);
   set_stats("strength",12);
   set_stats("dexterity",16);
   set_stats("constitution",17);
   set_stats("intelligence",19);
   set_stats("wisdom",15);
   set_stats("charisma",3);
   set_overall_ac(-4);
   set_spells(({
	  "cone of cold",
	  "lightning bolt",
	  "meteor swarm",
	  "fireball",
	  "prismatic spray",
	  "magic missile",
	  "acid breath",
	  "static field",
	  "ray of enfeeblement",
	  "powerword stun",
	  "timestop",
	  "powerword kill"
   }));
   set_moving(1);
   set_speed(99);
   set_alignment(9);
   set_emotes(5,({
      "%^BOLD%^The apparition slowly scans the surrounding area.",
	  "%^BOLD%^The hooded apparition begins chuckling softly to itself."
   }),0);
   set_size(2);
   set_max_hp(300);
   set_hp(query_max_hp());
   set_exp(16000);
   set_max_level(36);
   command("message in enters silently.");
   command("message out silently leaves to the $D.");
}

void die(object ob){
   tell_room(ETO,"%^BOLD%^The apparition groans and the empty robe "+
      "falls to the ground, disintegrating instantly.");
   TO->move("/d/shadowgate/void");
   TO->remove();
}
