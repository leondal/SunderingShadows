//NPC priest for newbietown temples - describe & name thanks to HM Schatten's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Litha Jurmar");
	set_short("Litha Jurmar, Vigilant of Torm");
	set_id(({"npc cleric","cleric", "litha", "Litha", "vigilant", "priestess"}));
	set_long(
@STYX
Litha presents a striking figure in her regal standards and %^BOLD%^%^WHITE%^brilliantly polished full plate armor%^RESET%^%^CYAN%^.  A cloak of brilliant orange silk is secured at her neck with a %^YELLOW%^golden clasp in the shape of a mighty lion's head%^RESET%^%^CYAN%^.  %^RESET%^Stormy gray eyes %^CYAN%^look out from the visor of her great helm that is adorned with %^YELLOW%^saffron colored ostrich %^RESET%^%^CYAN%^and %^BOLD%^%^GREEN%^emerald peacock %^RESET%^%^CYAN%^plumes.  The holy symbol of Torm, a right-handed gauntlet with %^BOLD%^%^BLACK%^three black arrows %^RESET%^%^CYAN%^surrounding it, has been carefully etched into the breast armor as well as her %^RESET%^shield of pure silver%^CYAN%^.  Imposing at well over six feet tall, Litha seems more than capable of standing fast in protection of this fortress like temple.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("female");
	set_alignment(4);
   set_diety("torm");
   new("/d/magic/symbols/torm_symbol")->move(TO);
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