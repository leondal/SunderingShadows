#include <std.h>
#include <daemons.h>
#include "../../defs.h"
inherit ARMOUR;

int tracker;

void create() {
   ::create();
   set_name("golden ring");
   set_id(({"ring","golden ring","gold ring","amethyst ring","ring of arachnid control"}));
   set_short("%^BOLD%^%^WHITE%^Ring of %^RESET%^%^ORANGE%^Ar%^YELLOW%^a%^RESET%^%^ORANGE%^ch%^YELLOW%^n%^RESET%^%^ORANGE%^id %^BOLD%^%^WHITE%^Control%^RESET%^");
   set_obvious_short("%^YELLOW%^gol%^RESET%^%^ORANGE%^d%^YELLOW%^en ring set with %^RESET%^%^MAGENTA%^ame%^BOLD%^t%^RESET%^%^MAGENTA%^hysts%^RESET%^");
   set_long("This ring has been crafted from a polished band of %^YELLOW%^"
"go%^RESET%^%^ORANGE%^l%^YELLOW%^d%^RESET%^, decorated and shaped to "
"create a beautiful trinket.  Tiny figures of %^BOLD%^%^BLACK%^s%^RESET%^p"
"%^BOLD%^%^BLACK%^id%^RESET%^%^RED%^e%^BOLD%^%^BLACK%^rs%^RESET%^ have "
"been cut into the wide band, scurrying around its web-etched surface.  "
"Each is completed by a sparkling facet-cut %^RESET%^%^MAGENTA%^ame"
"%^BOLD%^t%^RESET%^%^MAGENTA%^hyst%^RESET%^, that forms the body of the "
"arachnid.  Upon the underside, graceful yet chaotic-looking %^GREEN%^r"
"%^BOLD%^u%^CYAN%^n%^RESET%^%^CYAN%^e%^MAGENTA%^s %^RESET%^run the length "
"of the band.\n");
   set_lore("These lesser rings of conjuration are prized by drowkind, "
"particularly their priestesses. They summon nearby %^YELLOW%^spiders "
"%^RESET%^to the wearer, and compel them to protect their master. Such "
"rings are usually quite weak in power though, and can be used only once "
"each day.\n");
   set_property("lore difficulty",6);
   set_limbs(({"right hand","left hand"}));
   set_weight(0);
   set_value(650);
   set_ac(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   tracker = 0;
}

void init(){
   ::init();
   add_action("summon_me","spiders");
}

int wear_fun() {
   if((int)ETO->query_lowest_level() < 10) {
     tell_object(ETO,"You cannot use this item yet.");
     return 0;
   }
   return 1;
}

int summon_me(string str) {
   int i, j;
   object ob;
   if(!objectp(TO)) return 0;
   if(!objectp(TP)) return 0;
   if(str) {
     notify_fail("What?\n");
     return 0;
   }
   if(!TO->query_worn()) {
     notify_fail("You have to wear the ring first.\n");
     return 0;
   }
   if(tracker > time()) {
     notify_fail("The ring is still recharging.\n");
     return 0;
   }
   tracker = time() + 28800;
   tell_object(TP,"Your invoke the enchantments within the ring.");
   j = random(4)+1;
   for(i = 0; i < j; i++) {
     ob=new(OBJ"magic/spider.c");
     ob->move(EETO);
     ob->force_me("protect "+ETO->query_name());
     ETO->add_follower(ob);
   }
   return 1;
}

int resetme() {
   tracker = 0;
   return 1;
}
