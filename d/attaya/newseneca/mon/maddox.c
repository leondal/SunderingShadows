//maddoz.c - A card dealer
//~Circe~ 11/19/07 for new Seneca - card dealers are all Lujke :)
#include <std.h>

inherit "/d/shadow/mon/dealer.c";

void create(){
   ::create();
   set_name("Maddox");
   set_id(({"maddox","dealer","card dealer","Maddox"}));
   set_short("Maddox, a card dealer");
   set_long("Maddox is a scruffy young man with short %^BOLD%^"+
      "%^BLACK%^black hair %^RESET%^worn in spikes.  He wears "+
      "a simple %^GREEN%^green shirt %^CYAN%^with %^ORANGE%^tan "+
      "trousers %^CYAN%^and %^ORANGE%^sandals%^CYAN%^.  His left "+
      "ear is %^BOLD%^pierced %^RESET%^%^CYAN%^several times, and "+
      "he wears an assortment of %^BOLD%^%^WHITE%^earrings%^RESET%^"+
      "%^CYAN%^, all in %^RESET%^silver%^CYAN%^.  His cool %^BOLD%^"+
      "powder blue eyes %^RESET%^%^CYAN%^show a shrewd intelligence, "+
      "but he is known far and wide as being honest.  Despite his "+
      "young age, he is an expert pokiir dealer, and through an "+
      "arrangement with Jericho, he works here often.");
   set_gender("male");
   set_race("human");
   set_hd(30,5);
   set_alignment(5);
   set_max_hp(300);
   set_hp(query_max_hp());
   set_overall_ac(-18);
   set_class("fighter");
   set_mlevel("fighter",30);
   set_level(30);
   set_stats("wisdom",19);
   set_stats("strength",18);
   set_stats("constitution",18);
   set_stats("intelligence",18);
   set_stats("charisma",16);
   set_stats("dexterity",18);
   set_exp(60);
   set("aggressive",0);
}

