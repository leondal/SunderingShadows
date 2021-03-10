//NPC priest for newbietown temples - describe & name thanks to HM Lliira's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Alamar Ruthgor");
	set_short("Alamar Ruthgor, Battle Leader of Tempus");
	set_id(({"npc cleric","cleric", "alamar", "Alamar", "priest"}));
	set_long(
@STYX
%^RESET%^Alamar Ruthgor is quite tall for a human.  Adorned in his armor and helm, he looks well-prepared for the next battle.  Atop his helm is a %^BOLD%^%^RED%^red scarlet plume%^RESET%^, marking his sect within the church.  Deep freckles cover what you can see of his cheeks through the faceplate of the helm.  He looks as though he has not shaven in a few days as well.  His armor was once fluted and of fine quality, though now it appears a bit distressed.  The dull breastplate that covers his torso especially appears to have been through quite a few battles.  A %^BOLD%^%^WHITE%^tunic of white %^RESET%^appears below the breastplate and is %^BOLD%^%^RED%^streaked with scarlet red%^RESET%^, the vestments of the Lord of Battle's clergy.  Huge metal gauntlets covered in spikes, adorn and protect his hands.

STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(2);
   set_diety("tempus");
   new("/d/magic/symbols/tempus_symbol")->move(TO);
	set_guild_level("cleric",25);
	set_class("cleric");
	add_search_path("/cmds/priest");
	set_spells( ({ "limb attack", "hold person", "cause critical wounds", "hold person" }) );
   set_spell_chance(50);
	set_hd(30,5);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_stats("strength", 14);
   set_stats("dexterity", 17);
   set_stats("constitution", 15);
   set_stats("intelligence", 14);
   set_stats("charisma", 15);
   set_stats("wisdom", 18);
	set_db("temple_cleric");
	remove_std_db();
}

