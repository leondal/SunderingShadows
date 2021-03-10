// configuring vendor to specifically sell crystals for L1-3 spells only. Nienne, 09/09.
#include <std.h>
inherit "/std/comp_vend";

void my_components();
#define WANTED_COMP ({ "aventurine", "bloodstone", "carnelian", "leopard agate",\
"apatite", "wemic tears", "adamite", "malachite",\
"mottled jasper", "unakite", "flowstone", "tektite", "yellow calcite", "dallyhanite" })

void create(){
    ::create();
    set_name("nasir");
    set_id(({"nasir","clerk","shop keeper","human","mage","shopkeeper","kothari"}));
    set_short("Nasir Kothari, Human Psion");
    set_long("%^RESET%^%^CYAN%^Nasir Kothari is a psion of some renown, famed for his keen eye for the gems needed by "
"psions to manifest some of their powers.  He is dressed in %^ORANGE%^flowing garb%^CYAN%^, reminiscent of desert dwellers"
".  His hair is covered by a beige turban, and a %^MAGENTA%^glowing amethyst %^CYAN%^rests in the center of his forehead"
".  A sash around his waist supports a well-made %^RESET%^scimitar%^CYAN%^, though it looks as if he could well defend "
"himself without it.\n"+
"%^RESET%^To get a list of shop commands, type %^YELLOW%^<help shop>%^RESET%^.");
    set_gender("male");
    set_alignment(5);
    set_race("human");
    set_class("psion");
    set_guild_level("psion",10);
    set_hd(10,4);
    set_max_hp(200);
    set_hp(200);
    set_exp(10);
    set_spell_chance(100);
    set_spells(({"mind thrust","mind thrust","mind thrust","energy bolt","energy bolt"}));
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
