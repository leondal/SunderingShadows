#include <std.h>
#include "../outpost.h"
inherit TOWNSMAN;

void create() {
   ::create();   
  set_name("alexandia");
  set_id(({"alexandia","healer",}));
  set_short("Alexandia, healer of the outpost");
  set("aggressive", 0);
  set_level(25);
  set_long("%^CYAN%^Alexandia is a women in her middle forties. She carries herself with "+
  "a certain pride that only comes with experience. Her mild %^BOLD%^blue eyes %^RESET%^%^CYAN%^is "+
  "set in a weather-worn face which despite her rugged appearance is still beautiful. She "+
  "always have a friendly smile and a calming word to anyone who visits her shop.");
   set_alignment(5);
  set_emotes(5,({
  "Alexandia smiles softly to the newcomers in her shop.",
  "Even busy with a critical wounded guardsman, Alexandia hums softly",
  "Alexandia rearranges some herbs and vials on the shelves behind the counter of her shop",
  }),0);
  set_race("human");
  set_gender("female");
  add_money("gold", random(20));
   set_body_type("human");
   set_property("no attack", 1);
   set_hd(19,3);
   set_max_hp(query_hp());
   set_mp(random(500));
  set_stats("strength", 17);
  set_stats("intelligence", 14);
  set_stats("wisdom", 18);
  set_stats("dexterity", 18);
  set_stats("constitution", 19);
  set_exp(10);
  set_hp(149);
}
