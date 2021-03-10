//NPC cleric for Newbietown temples - name & describe thanks to HM Schatten's player

#include <std.h>

inherit NPC;

void create() {
	::create();
	set_name("Grace Pellicia");
	set_short("Grace Pellicia, Eternal Flame of Kossuth");
	set_id(({"npc cleric","cleric", "Grace", "grace", "priestess"}));
	set_long(
@STYX
%^RESET%^Grace is robed in %^BOLD%^%^BLACK%^black chemise %^RESET%^embroidered with flames of %^BOLD%^%^RED%^crimson, %^YELLOW%^gold %^RESET%^and orange that race from  hem to collar and down along the left sleeve, ending in a %^BOLD%^%^RED%^glove of velvety crimson leather%^RESET%^.  Her other hand is unadorned except for a single flamedance ring, which flickers with the very fires of Flame Lord.   Floor length, unbound hair, cascades along her back in a myriad of %^YELLOW%^golden curls%^RESET%^.  %^BOLD%^%^BLACK%^Sultry black eyes %^RESET%^are framed by delicate, almost elven features, but her ears show no trace of being pointed, which clearly gives away her human heritage.  Her youthful skin is fair but flushed from the fires of the Lord of Flame.
STYX
	);
	set_race("half-elf");
	set_body_type("human");
	set_gender("female");
	set_alignment(3);
   set_diety("kossuth");
   new("/d/magic/symbols/kossuth_symbol")->move(TO);
	set_guild_level("cleric",25);
	set_class("cleric");
	add_search_path("/cmds/priest");
	set_spells( ({ "limb attack", "hold person", "cause critical wounds", "hold person" }) );
   set_spell_chance(50);
	set_hd(30,5);
	set_max_hp(200);
	set_hp(200);
	set_exp(10);
	set_db("temple_cleric");
	remove_std_db();
}

