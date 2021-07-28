#include <std.h>
inherit "/d/common/obj/armour/leather";

void create(){
   ::create();
   set_name("bodice");
   set_id(({"leather","bodice","gray bodice","leather bodice","shroud","shroud of the night stalker"}));
   set_short("%^BOLD%^%^BLACK%^Shroud of the Nig%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^t Sta%^RESET%^%^MAGENTA%^l%^BOLD%^%^BLACK%^ker%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a g%^RESET%^r%^BOLD%^%^BLACK%^ay leather bodice%^RESET%^");
   set_long("This %^ORANGE%^leather bodice %^RESET%^seems much more resilient "
"than others of its kind that are merely worn as decorative clothing. Coming "
"down over the wearer's shoulders in a v-neck, it leaves the arms and throat "
"uncovered. %^GREEN%^S%^CYAN%^t%^GREEN%^ur%^CYAN%^d%^GREEN%^y %^RESET%^laces "
"have been threaded through darkened studs fitted down the middle of the "
"garment, binding it together around the chest. It has obviously been "
"designed only to fit a %^MAGENTA%^wom%^RED%^a%^MAGENTA%^n%^RESET%^, judging "
"by the shape of the form-fitted garment. The leather that makes up the "
"bodice has been dyed a shifting shade of %^BOLD%^%^BLACK%^g%^RESET%^r"
"%^BOLD%^%^BLACK%^ay%^RESET%^, varying in hues across its surface like "
"mottled %^BLUE%^sh%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^dows%^RESET%^.\n");
   set_lore("Such garments as these are well prized among roguish women, for "
"their unremarkable appearance and ease of movement. They are often made with "
"stronger reinforcements to offer better protection in combat, and usually "
"dyed a dark blue or gray so as better to meld in with the shadows. They were "
"well favored among the faithful of Mask and Shar, with a few such pieces "
"known by greater reputation as special magical items. This piece is such a "
"one, once specifically made for a Sharran assassin known to most as only the "
"Night Stalker, for the way her victims were only found the next morning.");
   set_property("lore difficulty",27);
   set_size(-1);
   set_value(0);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_item_bonus("stealth",2);
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wear_fun() {
   if((string)ETO->query_gender() != "female") {
     tell_object(ETO,"The bodice would only fit a woman!");
     return 0;
   }
   tell_room(EETO,"%^MAGENTA%^The bodice fits perfectly to "+ETO->QCN+"'s "
"figure.%^RESET%^",ETO);
   tell_object(ETO,"%^MAGENTA%^The bodice fits perfectly to your "
"figure.%^RESET%^");
   ETO->setenv("MINVIS","%^BLUE%^$N disappears into the shadows.%^RESET%^");
   ETO->setenv("MVIS","%^BLUE%^$N appears from the shadows beside "
"you.%^RESET%^");
   return 1;
}

int remove_fun(){
   tell_room(EETO,"%^MAGENTA%^"+ETO->QCN+" removes the perfectly fitted "
"bodice.%^RESET%^",ETO);
   tell_object(ETO,"%^MAGENTA%^You remove the perfectly fitted "
"bodice.%^RESET%^");
   ETO->setenv("MINVIS","$N seems to disappear.");
   ETO->setenv("MVIS","$N appears out of the corner of your eye.");
   return 1;
}

void init() {
   ::init();
   add_action("stab_fun","stab");
}

int stab_fun(string str) {
   object ob;
   if(TP->query_bound() || TP->query_paralyzed() || TP->query_unconscious()) return 0;
   if(!str) return 0;
   if(!objectp(ETP)) return 0;
   if(!ob = present(str,ETP)) return 0;
   if(ob = TP) return 0;
   if(!TP->is_class("thief")) return 0;
   if(!str) return 0;
   if(member_array((string)ob->query_body_type(),VALID_BACKS) == -1) return 0;
   if(sizeof(TP->query_attackers())) return 0;
   if(!TO->query_worn()) return 0;
   if(!TP->query_invis()) return 0;
   if(random(15)) return 0;

   tell_room(ETP,"%^BLUE%^"+TP->QCN+" appears without warning from the "
"%^BOLD%^%^BLACK%^sh%^RESET%^a%^BOLD%^%^BLACK%^dows %^RESET%^%^BLUE%^to "
"strike!%^RESET%^",TP);
   tell_object(TP,"%^BLUE%^You slip through the %^BOLD%^%^BLACK%^sh%^RESET%^"
"a%^BOLD%^%^BLACK%^dows %^RESET%^%^BLUE%^to strike without warning at your "
"foe!%^RESET%^");
   return 0;
}
