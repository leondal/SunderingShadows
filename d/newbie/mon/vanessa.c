// configuring vendor to specifically sell comps for L1-2 spells only. Nienne, 09/09.
#include <std.h>
inherit "/std/comp_vend";

void my_components();
#define WANTED_COMP ({ "trill", "epithet", "soliloquy", "lullaby", "limerick", "dialogue", "conceit", "metaphor", "elegy", "whisper" })

void create(){
    ::create();
    set_name("vanessa");
    set_id(({"vanessa","clerk","shop keeper","human","bard","shopkeeper","kothari"}));
    set_short("Vanessa Ingmar, Human Poet");
    set_long("%^RESET%^%^CYAN%^Vanessa Ingmar is considered the local artist of Offestry, known for her talent with the "
"written and spoken word.  Once a regular %^MAGENTA%^performer%^CYAN%^, she has since retired from the limelight to "
"settle her own store where she sells excerpts from her compositions to travellers that come and go.  She usually has a "
"%^RESET%^quill %^CYAN%^in hand and %^BLUE%^ink smudges %^CYAN%^on her fingertips, suddenly pausing to write upon the "
"nearest sheet of parchment as inspiration strikes her.\n"+
"%^RESET%^To get a list of shop commands, type %^YELLOW%^<help shop>%^RESET%^.");
    set_gender("female");
    set_alignment(5);
    set_race("human");
    set_class("bard");
    set_guild_level("bard",10);
    set_hd(10,4);
    set_max_hp(200);
    set_hp(200);
    set_exp(10);
    set_spell_chance(100);
    set_spells(({"sound burst","sound burst","sound burst","flare"}));
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
