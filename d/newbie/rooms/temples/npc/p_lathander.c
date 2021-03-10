//NPC priest for newbietown temples - describe & name thanks to HM Kaarell's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Andreas Lestrand");
	set_short("Andreas Lestrand, High Priest of the Morninglord");
	set_id(({"npc cleric","cleric", "andreas", "Andreas", "priest"}));
	set_long(
@STYX
%^RESET%^Andreas stands just a little over six feet tall and is dressed in full length, %^BOLD%^%^YELLOW%^yellowy%^RESET%^-%^BOLD%^%^RED%^red%^RESET%^ satin robes. The long sleeves, hem and neck are bordered with ornately crafted %^BOLD%^%^YELLOW%^gold%^RESET%^ ribbons, while his back is adorned with a fiery %^BOLD%^%^YELLOW%^gold%^RESET%^ and %^BOLD%^%^MAGENTA%^pink%^RESET%^ sun whose rays reach up toward the sky. A %^BOLD%^%^YELLOW%^golden%^RESET%^-%^BOLD%^%^RED%^red%^RESET%^ satin sash ties through a %^BOLD%^%^MAGENTA%^rose quartz clasp%^RESET%^ at the waist, its long tongues hanging down to tassel an inch before the hem in front of the robes.  Deep %^BOLD%^%^BLUE%^sapphire-blue%^RESET%^ eyes twinkle warmly in welcome from a richly sun-bronzed face with full smiling lips.  Shoulder length %^YELLOW%^blonde locks%^RESET%^ ripple down and curl about his broad shoulders.  A %^BOLD%^%^MAGENTA%^rose quartz disk%^RESET%^ hangs on a %^BOLD%^%^YELLOW%^golden chain%^RESET%^ around his neck.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("male");
	set_alignment(4);
   set_diety("lathander");
   new("/d/magic/symbols/lathander_symbol")->move(TO);
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

