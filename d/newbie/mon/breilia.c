// configuring vendor to specifically sell components for L1-3 spells only. Nienne, 09/09.
#include "../newbie.h"
inherit "/std/comp_vend.c";

void my_components();
#define WANTED_COMP ({ "pearl","owlfeather","blessed leather","colored sand","phosphorescent moss","carbon","rose petals","charcoal","incense stick","ivory portal",\
"dart","powdered rhubarb leaf","adders stomach","powdered silver","talc","minute tarts","feather","eyelash","gum arabic","parchment","corn extract","spider web",\
"aluminum chaff","powdered chalk","sulfur","bat guano","clay model ziggurat","piece of iron","firefly","tiny bag","small candle","citric acid","beeswax","crystal","magnets","small drum","piece of reed","exotic feather","clear crystal" })

void create() {
   ::create();
   set_name("Breilia");
   set_short("Breilia, owner of the Wizard's Hat");
   set_id(({"Breilia","breilia","shop keeper","shopkeeper","owner","witch"}));
   set_long("%^RESET%^%^CYAN%^Breilia is a very tall, thin woman. She has %^BOLD%^%^BLACK%^long black hair %^RESET%^"
"%^CYAN%^that nearly reaches the floor and rather %^BOLD%^%^BLUE%^cold blue eyes%^RESET%^%^CYAN%^.  She is wearing a "
"large, black hat with a pointed top and some %^RESET%^charcoal gray robes%^CYAN%^.  The entire effect makes her look "
"like the typical witch that parents are always telling their children about.  You have the feeling that she does this on "
"purpose.  She seems like the eccentric type, but then again, most component shopkeepers are.\n"
"%^RESET%^To get a list of shop commands, type %^YELLOW%^<help shop>%^RESET%^.");
   set_race("human");
   set_gender("female");
   set_alignment(2);
   set_class("mage");
   set_guild_level("mage",10);
   set_hd(10,4);
   set_max_hp(200);
   set_hp(200);
   set_exp(10);
   set_spell_chance(100);
   set_spells(({"magic missile","magic missile","magic missile","lightning bolt","lightning bolt"}));
   remove_std_db();
   my_components();
}

void reset() {
   ::reset();
   my_components();
}

void my_components() {
   int i;
   Available = allocate(sizeof(WANTED_COMP));
   for(i=0;i<sizeof(WANTED_COMP);i++) {
     Available[i] = WANTED_COMP[i];
     Amount[WANTED_COMP[i]] = roll_dice(5,10);
   }
}