#include <std.h>
inherit "/std/psi_comp_vend";

void create(){
   ::create();
   set_name("khaldar");
   set_short("Khaldar, a bald duergar merchant");
   set_id(({"khaldar","Khaldar","duergar","merchant"}));
   set_long("%^CYAN%^Khaldar is fairly short, even by the standards of his people, and bears a much less stocky frame "
"than his surface cousins.  His skin is %^RESET%^stone-gray%^CYAN%^, with an equally dusty-hued beard of short, wiry hair"
".  With a completely bald head, it is instead patterned with a series of %^BLUE%^dark tattoos %^CYAN%^that lead all the "
"way down to the nape of his neck.  He is garbed in a %^BOLD%^%^BLACK%^midnight-black robe %^RESET%^%^CYAN%^lined with "
"gleaming %^ORANGE%^copper%^CYAN%^, marked with the image of an eye on the back.  A similarly gleaming pendant of c"
"%^RESET%^%^BOLD%^%^CYAN%^r%^RESET%^%^CYAN%^ys%^RESET%^%^BOLD%^%^CYAN%^t%^RESET%^%^BOLD%^%^WHITE%^a%^RESET%^%^CYAN%^l is "
"bound at his throat with a leather thong.  His %^BOLD%^%^BLACK%^cold black eyes %^RESET%^%^CYAN%^survey each creature in "
"turn as they pass by, suspicious of all.%^RESET%^");
   set_race("duergar");
   set_gender("male");
   set_hd(20,4);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-12);
   set_alignment(5);
   set_class("psion");
   set_mlevel("psion",30);
   set_level(30);
   set_stats("intelligence",18);
   set_stats("wisdom",14);
   set_stats("charisma",16);
   set_stats("strength",9);
   set_stats("constitution",11);
   set_stats("dexterity",14);
   set_spells(({"mind thrust","mind thrust","call crystals","energy bolt","energy bolt","ultrablast"}));
   set_spell_chance(70);
   set_exp(1);
   set("aggressive",0);
   add_money("gold",random(50));
   set_components(100);
}
