//Corin.c - psionic comps shop owner for new Seneca
//Circe 12/2/07
#include <std.h>
inherit "/std/comp_vend";

void create(){
   ::create();
   set_name("corin");
   set_short("Corin Chevalier, gemcutter extraordinaire");
   set_id(({"corin","Corin","Corin Chevalier","chevalier","Chevalier","gemcutter","shopkeeper"}));
   set_long("Dressed in a thick coat of soft %^MAGENTA%^purple velvet "+
      "%^CYAN%^edged in %^BOLD%^%^WHITE%^s%^BLACK%^n%^WHITE%^o%^BLACK%^"+
      "w %^WHITE%^l%^BLACK%^e%^WHITE%^o%^BLACK%^p%^WHITE%^a%^BLACK%^r"+
      "%^WHITE%^d %^BLACK%^f%^WHITE%^u%^BLACK%^r%^RESET%^%^CYAN%^, "+
      "Corin seems best described by the word flamboyant.  His "+
      "ruffled %^BOLD%^%^WHITE%^white silk shirt%^RESET%^%^CYAN%^ is spotless, "+
      "and his %^BOLD%^%^BLACK%^leather pants %^RESET%^%^CYAN%^"+
      "lace up the sides.  A foppish %^ORANGE%^golden hat %^CYAN%^"+
      "is perched jauntily atop his head, highlighting his thick "+
      "%^BOLD%^%^BLACK%^sable curls%^RESET%^%^CYAN%^.  Despite his "+
      "somewhat frivolous appearance, his %^BOLD%^azure eyes "+
      "%^RESET%^%^CYAN%^reveal intelligence, and his nimble fingers "+
      "are clearly up to the task of cutting gems exactly.\n"+
      "%^RESET%^<help shop> will give you details on how to use this store"
   );
   set_race("human");
   set_gender("male");
   set_hd(20,4);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_overall_ac(-12);
   set_alignment(4);
   set_class("psion");
   set_class("cleric");
   set_mlevel("psion",20);
   set_mlevel("cleric",20);
   set_guild_level("psion",20);
   set_guild_level("cleric",20);
   set_level(20);
   set_stats("intelligence",18);
   set_stats("wisdom",18);
   set_stats("charisma",16);
   set_stats("strength",14);
   set_stats("constitution",16);
   set_stats("dexterity",14);
   set_spells(({
      "mind thrust","mind thrust","mind thrust","breath of the black dragon","swarm of crystals"
   }));
   set_spell_chance(60);
   set_exp(100);
    set_shop_type("psion");
    set_components(100);
   set("aggressive",0);
   add_money("gold",random(50));
}
