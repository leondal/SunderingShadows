#include <std.h>
inherit "/std/comp_vend";

void create(){
   ::create();
   set_name("thella");
   set_short("Thella, a delicate human woman");
   set_id(({"thella","Thella","woman"}));
   set_long("%^CYAN%^Thella is an older woman with a delicate, almost fragile "
"figure and fine-boned hands. Her %^WHITE%^steely-gray hair %^CYAN%^is pulled "
"back from her face in a bun, leaving whisps to trail about her face like a "
"pale aura. Her clear %^BOLD%^a%^RESET%^%^CYAN%^z%^BOLD%^u%^RESET%^%^CYAN%^r"
"%^BOLD%^e %^RESET%^%^CYAN%^eyes reflect the %^BOLD%^%^RED%^m%^MAGENTA%^y"
"%^CYAN%^r%^GREEN%^i%^YELLOW%^a%^RESET%^%^ORANGE%^d %^CYAN%^colors of the "
"crystals that surround her shop, and adorn the many pieces of%^YELLOW%^ "
"jewelry %^RESET%^%^CYAN%^she wears; indeed, she seems particularly fond of "
"the bright and colorful reflections. She holds a %^MAGENTA%^calm %^CYAN%^and "
"sedate demeanor, walking about her store in no particular hurry as she "
"gathers various crystals for her customers.%^RESET%^");
   set_race("human");
   set_gender("female");
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
    set_shop_type("psion");
    set_components(100);
}
