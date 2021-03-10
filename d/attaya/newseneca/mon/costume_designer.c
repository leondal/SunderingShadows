//costume_designer.c - by ~Circe~ for new Seneca 12/20/07
#include <std.h>
#include "../seneca.h"

inherit VENDOR;

void create() {
   ::create();
   set_name("Hannah");
   set_id(({"designer","costume designer","Designer","Hannah","hannah","hannah lycinthe","Hannah Lycinthe"}));
   set_short("Hannah Lycinthe, Costume Designer");
   set_long("Short, sleek %^BOLD%^%^BLACK%^ebony hair%^RESET%^"+
      "%^CYAN%^ cut at an angle along her jawline frames this "+
      "young woman's delicate face.  A pert %^BOLD%^%^MAGENTA%^"+
      "cupid bow mouth %^RESET%^%^CYAN%^seems perpectually "+
      "pursed in thought, as she is ever contemplating her "+
      "latest design.  Her rather dull %^RESET%^blue-gray "+
      "eyes %^CYAN%^are brightened somewhat by the %^BOLD%^"+
      "%^WHITE%^sparkling %^RESET%^g%^BOLD%^l%^RESET%^i%^BOLD%^"+
      "t%^RESET%^t%^BOLD%^e%^RESET%^r %^CYAN%^she has sprinkled "+
      "around them.  She wears a close-fitting gown in %^BOLD%^"+
      "%^MAGENTA%^fuscia cotton %^RESET%^%^CYAN%^topped by a "+
      "molded %^BOLD%^%^BLACK%^bodice%^RESET%^%^CYAN%^ that "+
      "matches the deep %^BOLD%^%^BLACK%^black boots%^RESET%^"+
      "%^CYAN%^ on her feet.  She "+
      "listens with a rapt expression when a customer speaks, and "+
      "she always seems brimming with ideas for new costumes.%^RESET%^\n\n"+
      "%^RESET%^%^CYAN%^<%^RESET%^help shop%^CYAN%^> %^RESET%^"+
      "will get you a list of shop commands.\n");
   set_gender("female");
   set_alignment(2);
   set_race("human");
   add_money("gold", random(500));
   set_level(30);
   set_hd(30,20);
   set_hp(200+roll_dice(30,20));
   set_class("fighter");
   set_mlevel("fighter",30);
   set_guild_level("fighter",30);
   set_stats("strength",19);
   set_stats("dexterity",17);
   set_overall_ac(-21); 
   set_max_hp(query_hp());
   set_storage_room(STORAGE"costume_storage.c");
   force_me("speech sing brightly");
   set_items_allowed("clothing");
}