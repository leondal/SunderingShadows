//NPC priest for newbietown temples

#include <std.h>

inherit NPC;

void create() {
        ::create();
        set_name("Afzal Jayaram");
        set_short("Afzal Jayaram, Ascended Mind");
        set_id(({"npc cleric","cleric", "afzal", "Afzal", "priest","ascended mind"}));
        set_long(
@CIRCE
%^RESET%^%^ORANGE%^Afzal Jayaram wears flowing robes in shades of %^BOLD%^%^CYAN%^cyan%^RESET%^%^ORANGE%^.  The sleeveless robes are belted at the waist, much like a long tabard, and emblazoned with the %^BOLD%^eye of Auppenser %^RESET%^%^ORANGE%^worked in thread-of-bronze.  Matching bronze piping lines the edges of the robe, while a thin muslin shirt is worn underneath.  Voluminous linen pants shroud his legs, the ends gathered in simple wrappings that also cover his feet.  A thick %^BOLD%^%^BLACK%^band of prayer beads %^RESET%^%^ORANGE%^crosses his torso and over his right shoulder.  His head has been shaved clean, and he carries himself with the impeccable grace and deliberation that puts one in mind of a monk.
CIRCE
        );
        set_race("human");
        set_body_type("human");
        set_gender("male");
        set_alignment(5);
        set_diety("auppenser");
        new("/d/magic/symbols/auppenser_symbol")->move(TO);
        set_guild_level("cleric",25);
        set_class("cleric");
        add_search_path("/cmds/priest");
        set_spells( ({ "limb attack", "hold person", "cause critical wounds",
"hold person" }) );
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
