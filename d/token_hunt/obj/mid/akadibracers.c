#include <std.h>
inherit "/d/common/obj/armour/bracers";

void create(){
   ::create();
   set_name("bracers");
   set_id(({"bracers","silver bracers","swirling bracers","swirling silver bracers","bracers of the maelstrom","bracers of the swirling maelstrom"}));
   set_short("%^WHITE%^%^BOLD%^Br%^CYAN%^ac%^WHITE%^ers of the Wh%^RESET%^%^WHITE%^ir%^BOLD%^ling Mae%^CYAN%^ls%^WHITE%^trom%^RESET%^");
   set_obvious_short("%^WHITE%^%^BOLD%^sw%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^r%^RESET%^%^WHITE%^l%^BOLD%^ing si%^RESET%^%^WHITE%^l%^BOLD%^ver br%^RESET%^%^WHITE%^a%^BLACK%^%^BOLD%^c%^RESET%^%^WHITE%^e%^BOLD%^rs%^RESET%^");
   set_long("%^CYAN%^These are one of the most exotic-styled bracers you have ever laid eyes on.  They are "
"crafted in a particularly unique pattern that seems to have no symmetry or balance whatsoever.  Whorls of "
"%^WHITE%^%^BOLD%^s%^RESET%^%^WHITE%^i%^BLACK%^%^BOLD%^lv%^RESET%^%^WHITE%^e%^BOLD%^r%^RESET%^%^CYAN%^ metal "
"form arcs and tendrils that would snake up and down the forearm, leaving spaces of bare skin between.  "
"Despite the chaotic patterning, they are quite beautiful, and pleasing to the eye.  Along the upper surface "
"of the metal, swirls have been etched that run alongside the edges of the bracers.  Within these "
"engravings, a %^BLUE%^%^BOLD%^gl%^CYAN%^i%^BLUE%^tt%^RESET%^%^BLUE%^e%^BOLD%^ri%^WHITE%^n%^BLUE%^g "
"%^RESET%^%^CYAN%^trail of dust has been infused, making them sparkle in a myriad of%^BLUE%^%^BOLD%^ "
"bl%^RESET%^%^BLUE%^u%^BOLD%^e%^RESET%^%^CYAN%^ and %^BOLD%^az%^WHITE%^u%^CYAN%^re%^RESET%^%^CYAN%^ "
"hues.%^RESET%^\n");
   set_lore("%^WHITE%^%^BOLD%^A dispute exists over the creator of these exotic bracers. Most attribute their crafting to "
"a request made to Elderthanal Silverspring, by a young researcher living in the elven village of Synoria. Certainly, "
"given his renowned skill with jewelry, it would be no surprise if their creation was his own work. However, the claims "
"of a flamboyant tsarven trader, a half-elf by the name of Rrondath, would encourage any listener to believe that they "
"were his work and his gift to the same researcher. The researcher herself, known only by name as Mnela, seems to have "
"been too difficult to track down to confirm either rumor, so the matter remains yet unsettled...%^RESET%^\n");
   set_property("lore difficulty",25);
   set_weight(8);
   set_size(-1);
   set_value(0); 
   while ((int)TO->query_property("enchantment") != 4) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",4);
   }
   set_item_bonus("reflex",2);
   set_wear((:TO,"check":));
   set_remove((:TO,"remove_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int check() {
   ::check();
   tell_room(EETO,"%^WHITE%^%^BOLD%^A light %^CYAN%^breeze %^WHITE%^picks up around "+ETO->QCN+", as "
+ETO->QS+" slides the bracers over "+ETO->QP+" arms.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^A light %^CYAN%^breeze %^WHITE%^picks up around you, as you slide the "
"bracers over your arms.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^WHITE%^%^BOLD%^The breeze around "+ETOQCN+" fades to a soft whisper.%^RESET%^",ETO);
   tell_object(ETO,"%^WHITE%^%^BOLD%^The breeze around you fades to a soft whisper.%^RESET%^");
   return 1;
}

void init() {
   ::init();
   add_action("whirl_fun","whirl");
}

int whirl_fun() {
   object *weapon,ob;
   if((int)TP->query_class_level("ranger") < 5) return 0;
   if(random(15)) return 0;

   weapon = TP->query_wielded();
   if((weapon == ({}))) return notify_fail("You should wield your weapons for this!\n");

   if (TP->query_bound() || TP->query_tripped() || TP->query_paralyzed()){
      TP->send_paralyzed_message("info",TP);
      return 1;
   }
   if(!(ob = (object)TP->query_current_attacker())) {
      notify_fail("You are not in battle.\n");
      return 0;
   }
   if(TP->query_property("whirled")) return notify_fail("You can't do that again yet");
   if(!TO->query_worn()) return 0;
   tell_room(ETP,"%^WHITE%^%^BOLD%^A great %^BLACK%^ma%^RESET%^%^WHITE%^e%^BLACK%^%^BOLD%^lst%^RESET%^"
"%^WHITE%^r%^BLACK%^%^BOLD%^om%^WHITE%^ picks up around "+TP->QCN+", as "+TP->QS+" spins "+TP->QP+" weapons "
"in a blinding whirlwind of attacks!%^RESET%^",TP);
   tell_object(TP,"%^WHITE%^%^BOLD%^A great %^BLACK%^ma%^RESET%^%^WHITE%^e%^BLACK%^%^BOLD%^lst%^RESET%^"
"%^WHITE%^r%^BLACK%^%^BOLD%^om%^WHITE%^ picks up around you, as you spin your weapons in a blinding "
"whirlwind of attacks!%^RESET%^");
   return 0;
}