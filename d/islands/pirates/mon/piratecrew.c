#include <std.h>
#include "../piratedefs.h"
inherit MONSTER;

void create() {
   ::create();
   set_name("Pirate crewman");
   set_id(({ "crewman","crew","pirate" }));
   set_short("Pirate crewman");
   set_long("This is one of the pirate ship's crewmen.  Wearing sturdy-looking leather armor that includes a "
"vest, breeches, cloak, and boots, it looks like he stays ready for a fight, even though he has tasks around "
"the boat to attend to.");
   set_hd(20,1);
   set_stats("strength",17);
   set_stats("dexterity",17);
   set_gender("male");
   set_alignment(6);
   switch(random(10)) {
     case 0..4:
     set_race("human");
     set_size(2);
     break;
     case 5..7:
     set_race("half-elf");
     set_size(2);
     break;
     case 8:
     set_race("halfling");
     set_size(1);
     break;
     case 9:
     set_race("half-orc");
     set_size(2);
     break;
   }
   set("aggressive",20);
   set_hp(130);
   set_max_hp(130);
   add_money("silver", random(200)+20);
   set_ac(0);
   set_scrambling(1);
   set_body_type("human");
   set_class("thief");
   set_mlevel("thief",18);
   set_guild_level("thief",18);
   add_search_path("/cmds/thief");
   set_thief_skill("move silently",100);
   set_thief_skill("hide in shadows",100);
   set_thief_skill("pick pockets",100);
   new(OBJ"longdagger")->move(TO);
   command("wield dagger in left hand");
   new(OBJ"longdagger")->move(TO);
   command("wield dagger in right hand");
   set_funcs(({"rocktheboat"}));
   set_func_chance(20);
   set_exp(1500);
   toggle_steal();
}

void rocktheboat(object target) {
   object *inven;
   int i;
   inven = all_living(ETO);
   for(i = 0;i < sizeof(inven); i++) {
     if(userp(inven[i]) && !inven[i]->query_true_invis()) {
       if((random(20)+6) > inven[i]->query_stats("dexterity")) {
         tell_object(inven[i],"%^GREEN%^%^BOLD%^The boat rocks on the waves and the deck shifts beneath your "
"feet.  You fail to keep your balance and stumble to the side!%^RESET%^");
         inven[i]->set_paralyzed((random(4)+1)*2,"You're still trying to regain your balance.");
         tell_room(environment(inven[i]),"%^GREEN%^%^BOLD%^"+inven[i]->QCN+" stumbles and loses "
+inven[i]->QP+" balance as the boat rocks on the waves.%^RESET%^",inven[i]);
       }
       else {
         tell_object(inven[i],"%^GREEN%^%^BOLD%^The boat rocks on the waves and the deck shifts beneath your "
"feet, though you manage to keep your footing.%^RESET%^");
       }
     }
   }
}
