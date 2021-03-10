#include <std.h>

inherit "/std/psion_vend.c";

void create(){
    ::create();
    set_name("hanif");
    set_id(({"hanif","clerk","shop keeper","human","mage","shopkeeper","emankumar"}));
    set_short("Hanif Emankumar, Human Psion");
    set("aggressive", 0);
    set_long(
       "Hanif Emankumar is an aging man with deep, woody brown "+
       "skin and kind eyes.  His face bears creases from his "+
       "soft, ready smile, and he seems to enjoy his life "+
       "spent among gems and their crafting.  Hanif is dressed "+
       "simply in wrapped robes of natural muslin, a lightweight "+
       "fabric that allows the skin to breathe while providing "+
       "warmth.  His feet are clad in simple sandals peeking out "+
       "from beneath his robe, and his head has been shaved bald, "+
       "though it looks as if there were little hair to begin with."
	);
    set_gender("male");
    set_alignment(5);
    set_race("human");
    set_class("psion");
    set_hd(30,2);
    set_level(30);
    set_guild_level("psion",30);
    set_property("no bump", 1);
    set_spell_chance(100);
    set_spells(({"mind thrust","mind thrust","mind thrust","microcosm",
       "energy bolt","energy bolt"}));
}
