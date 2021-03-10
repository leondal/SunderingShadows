#include <std.h>
inherit "/std/psion_vend.c";

void create(){
    ::create();
    set_name("salha");
    set_id(({"salha","clerk","shop keeper","human","mage","shopkeeper","manjari"}));
    set_short("Salha Manjari, Human Psion");
    set_long("%^RESET%^%^CYAN%^Salha Manjari wears her %^BOLD%^%^BLACK%^long black hair %^RESET%^%^CYAN%^coiled into a "
"small bun at the base of her neck.  Her skin is a deep maple brown, highlighted by the %^ORANGE%^velvety chestnut "
"%^CYAN%^of her eyes.  A small %^BOLD%^%^MAGENTA%^rose quartz crystal %^RESET%^%^CYAN%^rests in the center of her "
"forehead, and her ears are studded with rows of glittering stones and golden hoops, making her jingle as she walks.  "
"She is dressed in diaphonous fabrics in all shades of red and pink, all blending together to look rather like the "
"%^YELLOW%^setting sun %^RESET%^%^CYAN%^in the desert sky.  Her slender feet are bare, and the only sound when she moves "
"is the tinkle of tiny gems.\n"
"%^RESET%^To get a list of shop commands, type %^YELLOW%^<help shop>%^RESET%^.");
    set_gender("female");
    set_alignment(5);
    set_race("human");
    set_class("psion");
    set_guild_level("psion",10);
    set_hd(10,4);
    set_spell_chance(100);
    set_spells(({"mind thrust","mind thrust","mind thrust","energy bolt","energy bolt"}));
}
