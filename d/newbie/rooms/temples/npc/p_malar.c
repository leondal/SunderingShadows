//NPC priest for newbietown temples - describe & name thanks to avatar Malar

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Welmar ClawHand");
	set_short("Welmar ClawHand, Malar's Hunter");
	set_id(({"npc cleric","cleric", "welmar", "Welmar", "priest"}));
	set_long(
@STYX
%^RESET%^Welmar is a fairly muscular man.  He has no shirt on and his pants are made
from the %^RED%^hide of a red dragon%^RESET%^.  You can see a great many scars criss-crossing his body, from battles fought in his past.  His arms are solid and crossed over his chest.  His head is shaven and covered in tattoos of snakes and wild beasts.  His right ear seems to have been chewed off but obviously he made it through and you can only guess what happened to the beast that did it.  You can see that a lot of his teeth are missing but, oddly enough, his incisors look enlongated, almost as if they've been sharpened by filing.  All in all, you can tell he has been to hell and back, and probably enjoyed every minute of it.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(9);
   set_diety("malar");
   new("/d/magic/symbols/malar_symbol")->move(TO);
	set_guild_level("cleric",25);
	set_class("cleric");
	add_search_path("/cmds/priest");
	set_spells( ({ "limb attack", "hold person", "cause critical wounds", "hold person" }) );
   set_spell_chance(80);
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

