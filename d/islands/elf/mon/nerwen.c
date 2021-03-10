#include <std.h>
#include "../elf.h"
inherit NPC;

void create()
{
        ::create();
        set_name("Nerwen Anarion");
        set_short("Nerwen Anarion, gold elf healer");
        set_id(({"Nerwen Anarion","elf","nerwen","healer"}));
        set_long(
        "Nerwen is a middle-aged elf with golden hair "+
		"and matching amber eyes.  She has fair skin.  "+
		"She is middle aged but like her elven kin it "+
		"is almost impossible to tell.  She wears a "+
		"gold trimmed white robe.  " );
        set_gender("female");
        set_race("elf");
        set_body_type("human");
        set_alignment(1);
        set_hd(20,10);
        set_max_hp(150+random(100));
        set_overall_ac(-7);
        set_class("cleric");
        set_class("fighter");
        set_mlevel("cleric",20);
        set_mlevel("fighter",20);
        set_level(20);
        set_stats("intelligence",18);
        set_stats("strength",10);
        set_stats("charisma",18);
        set_stats("constitution",15);
        set_stats("dexterity",10);
        set_stats("wisdom",12);
        set_spells(({
        "holy orb",
        "thorn spray",
        "sunburst",
        "searing light",
        "moonbeam",
        "hold person",
        }));
        set_spell_chance(100);
        set("aggressive",0);
        add_money("copper",random(100));
	    set_languages( ({ "elven" }) );
        command("speak elven");
        force_me("speech talk softly");
		set_emotes(10,({
        "Nerwen tends to the garden.",
        "Nerwen prays quietly.",
        "Nerwen heals an injured elf, her prayers soft and gentle.",
        "Nerwen talks happily with some of the other elves in the area.",
        "Nerwen sorts through some potions.",
        "Nerwen mixes a healing salve.",
        }),0);
		set_new_exp(30,"very low");
        set_max_level(35);
}