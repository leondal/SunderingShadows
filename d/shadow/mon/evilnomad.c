#include <std.h>
inherit NPC;

#define BODIES ({"slender","lithe","massive","thin","average","svelte","well-built","stocky"})
#define GENDER1 ({"female","male"})
#define GENDER2 ({"her","him"})
#define GENDER3 ({"she","he"})
#define GENDER4 ({"her","his"})
#define GENDER5 ({"Her","Him"})
#define GENDER6 ({"She","He"})
#define GENDER7 ({"Her","His"})

void create() {
   int i, j;
   ::create();
   i = random(sizeof(BODIES));
   j = random(2);
   set_id(({"psion","monk","portalpsion"}));
   set_name("nomad");
   set_short("%^RESET%^a "+BODIES[i]+" "+GENDER1[j]+" human in a %^BOLD%^%^BLACK%^dark robe%^RESET%^");
   set_long("%^RESET%^%^WHITE%^This "+BODIES[i]+" "+GENDER1[j]+" human is "
"dressed in a %^BOLD%^%^BLACK%^midnight-black robe %^RESET%^%^WHITE%^lined "
"with %^GREEN%^green%^WHITE%^, and is marked with the image of clenched fist, "
"giving "+GENDER2[j]+" an impression of %^RESET%^%^CYAN%^dangerous "
"power%^RESET%^%^WHITE%^. "+GENDER7[j]+" head is shaven and covered in a "
"series of %^RESET%^%^BOLD%^%^BLACK%^dark tattoos %^RESET%^%^WHITE%^from the "
"nape of "+GENDER4[j]+" neck to his forehead. "+GENDER6[j]+" is a member of an "
"order of banite psions charged with keeping the ways open between Tonovi and "
"its allies. "+GENDER6[j]+" carries nothing, and has only soft shoes on "
+GENDER4[j]+" feet. Yet, "+GENDER4[j]+" bearing suggests "+GENDER3[j]+" is "
"confident and assured. Around "+GENDER4[j]+" neck hangs a "
"%^RESET%^%^GREEN%^s%^RESET%^%^BOLD%^%^WHITE%^i%^RESET%^%^GREEN%^m"
"%^RESET%^%^BOLD%^%^GREEN%^p%^RESET%^%^GREEN%^le "
"c%^RESET%^%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^ys%^RESET%^%^BOLD%^"
"%^GREEN%^t%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^GREEN%^l "
"%^RESET%^%^WHITE%^on a %^RESET%^%^ORANGE%^leather thong %^RESET%^%^WHITE%^"
"that glows softly.%^RESET%^");
   set_alignment(5);
   set_race("human");
   set_body_type("human");
   set_class("psion");
   set_mlevel("psion",40);
   set_guild_level("psion",40);
   set_hd(25,1);
   set_max_hp(1200);
   set_hp(1200);
   set_gender(GENDER1[j]);
   add_search_path("/cmds/psionics");
   set_spells(({"energy bolt","energy bolt","mind thrust","mind thrust","mind thrust","breath of the black dragon","breath of the black dragon"}));
   set_spell_chance(90);
   set_exp(2);
   set_overall_ac(-10);
   set_mob_magic_resistance("average");
}
