#include <std.h>

inherit "/std/comp_vend.c";

void create(){
    ::create();
    set_name("adilah");
    set_id(({"adilah","Adilah","clerk","shop keeper","shopkeeper"}));
    set_short("%^BOLD%^%^RED%^Adilah%^RESET%^%^ORANGE%^ the Gypsy%^RESET%^");
    set("aggressive",0);
    set_long("%^RED%^Adilah %^ORANGE%^is a plump %^RED%^gypsy woman"+
       "%^ORANGE%^.  Her large frame is made even more impressive "+
       "due to the layer upon layer of clothing she is wearing.  "+
       "Her %^BOLD%^%^MAGENTA%^co%^YELLOW%^lo%^GREEN%^rf%^RED%^ul"+
       "%^RESET%^ %^ORANGE%^garments are %^YELLOW%^horribly mismatched"+
       "%^RESET%^ %^ORANGE%^in the manner most %^RED%^gypsies "+
       "%^ORANGE%^favor, and the loose folds bulge here and there, "+
       "as if there are stolen goods hidden underneath them.  The "+
       "makeup on her face is %^BOLD%^%^MAGENTA%^gaudy%^RESET%^"+
       "%^ORANGE%^, competing with the %^BOLD%^%^BLUE%^pe%^GREEN%^"+
       "aco%^BLUE%^ck fe%^GREEN%^athe%^BLUE%^rs%^RESET%^ %^ORANGE%^"+
       "around her for brightness.  The creases on her dark skin "+
       "shine with a pungent pomade, and a double line of thin "+
       "%^YELLOW%^golden chains%^RESET%^ %^ORANGE%^from which "+
       "%^YELLOW%^gold coins%^RESET%^ %^ORANGE%^hang, adorns her "+
       "forehead.  As she catches you looking at her getup with "+
       "such fascination, she leers at you longingly before "+
       "winking.%^RESET%^\n"+
       "<help shop> will get you a list of shop commands.\n");
    set_gender("female");
    set_alignment(5);
    set_race("human");
    set_class("mage");
    set_hd(20,2);
    set_level(20);
    set_guild_level("mage",20);
    set_property("no bump", 1);
    set_emotes(4,({
       "Adilah leans forward and pinches your cheek.",
       "Adilah sneezes loudly as a cloud of dust raises from "+
       "the mortar and pestle before her.",
       "%^RESET%^%^MAGENTA%^Adilah says%^RESET%^: Och, yavrum, what can Adilah do for you?",
       "%^RESET%^%^MAGENTA%^Adilah says%^RESET%^: Come drink a cup "+
       "of chai with Adilah.  She'll read the leaves for you!  Yes?"
    }), 0);
    set_components(100);
    set_spell_chance(100);
    set_spells(({"fireball","lightning bolt","acid arrow",
        "cone of cold"}));
}