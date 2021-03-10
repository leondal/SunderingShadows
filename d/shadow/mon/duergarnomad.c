#include <std.h>
inherit NPC;

#define BODIES ({"short","massive","wiry","average","hardy","well-built","stocky"})
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
   set_short("%^RESET%^a "+BODIES[i]+" "+GENDER1[j]+" duergar in a %^BOLD%^%^BLACK%^dark robe%^RESET%^");
   set_long("%^RESET%^%^WHITE%^This "+BODIES[i]+" "+GENDER1[j]+" duergar is "
"dressed in a %^BOLD%^%^BLACK%^midnight-black robe %^RESET%^%^WHITE%^lined "
"with %^ORANGE%^copper%^WHITE%^, and is marked with the image of an eye.  "
+GENDER7[j]+" gray skin and flinty eyes give "+GENDER2[j]+" an impression of "
"%^RESET%^%^CYAN%^dangerous power%^RESET%^%^WHITE%^. "+GENDER7[j]+" head is "
"completely bald and covered in a series of %^RESET%^%^BOLD%^%^BLACK%^dark "
"tattoos %^RESET%^%^WHITE%^from the nape of "+GENDER4[j]+" neck to "+GENDER4[j]+
"forehead. "+GENDER6[j]+" is a member of an order of duergar psions who seek "
"knowledge and allies to further their foothold upon the surface.  This one "
"seems to have been charged with keeping the way open between here and Tonovi.  "
+GENDER6[j]+" carries nothing, and has only soft shoes on "+GENDER4[j]+" feet. "
"Yet, "+GENDER4[j]+" bearing suggests "+GENDER3[j]+" is confident and assured.  "
"Around "+GENDER4[j]+" neck hangs a "
"%^RESET%^%^CYAN%^s%^RESET%^%^BOLD%^%^WHITE%^i%^RESET%^%^CYAN%^m"
"%^RESET%^%^BOLD%^%^CYAN%^p%^RESET%^%^CYAN%^le "
"c%^RESET%^%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^ys%^RESET%^%^BOLD%^"
"%^CYAN%^t%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^l "
"%^RESET%^%^WHITE%^on a %^RESET%^%^ORANGE%^leather thong %^RESET%^%^WHITE%^"
"that glows softly.%^RESET%^");
   set_alignment(6);
   set_race("duergar");
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
