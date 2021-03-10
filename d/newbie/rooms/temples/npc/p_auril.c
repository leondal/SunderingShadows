//NPC priest for newbietown temples - describe & name thanks to HM Vivian's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Serena Dalanthera");
	set_short("Serena Dalanthera, High Hand of Ice");
	set_id(({"npc cleric","cleric", "serena", "Serena", "priestess"}));
	set_long(
@STYX
Standing regally in an %^BOLD%^%^WHITE%^ice-white ceremonial robe made of a delicate silk%^RESET%^%^CYAN%^, Serena radiates a cold beauty.  The high priestess holds her chin high, a haughty expression on her face as she looks over the temple examining the petitioners before her.  Her creamy skin is a %^RESET%^milky white %^CYAN%^without a hint of a wrinkle, giving her young form the look of porcelain.  Her %^BOLD%^%^BLUE%^deep blue eyes %^RESET%^%^CYAN%^stare coldly at you before she seems to decide you are unworthy of her gaze and turns to look back at the temple.  %^YELLOW%^Silken blonde hair %^RESET%^%^CYAN%^falls in gentle curves to her tiny waist, which is accented by a %^RESET%^wide silver belt %^CYAN%^cinched tightly to support the %^RESET%^small silver-bladed axe %^CYAN%^tucked carefully behind it.  A %^RESET%^silver circlet %^CYAN%^intricately worked with %^BOLD%^%^WHITE%^snowflakes %^RESET%^%^CYAN%^rests atop the high priestess's head, the crowning touch to her stunning appearance.
STYX
	);
	set_race("human");
	set_body_type("human");
	set_gender("female");
	set_alignment(6);
   set_diety("auril");
   new("/d/magic/symbols/auril_symbol")->move(TO);
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

