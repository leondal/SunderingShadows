// updated to 3e! Now grants martial & exotic weapon proficiencies. N, 6/15.
#include <std.h>
#include <daemons.h>
inherit ARMOUR;

int martialtrack, exotictrack;

void create() {
   ::create();
   set_name("steel hoop");
   set_id(({"hoop","thick hoop","steel hoop","thick steel hoop","ring","ring of weapon mastery"}));
   set_short("%^BOLD%^%^BLACK%^Ring of %^RESET%^%^ORANGE%^We%^RED%^ap%^ORANGE%^on Ma%^RED%^ste%^ORANGE%^ry%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^a plain st%^RESET%^ee%^BOLD%^%^BLACK%^l hoop%^RESET%^");
   set_long("%^RESET%^%^CYAN%^This %^BOLD%^%^BLACK%^st%^RESET%^ee%^BOLD%^%^BLACK%^l %^RESET%^%^CYAN%^ring is "
"rather plain in appearance, having no %^YELLOW%^orn%^CYAN%^a%^YELLOW%^menta%^WHITE%^t%^YELLOW%^ion %^RESET%^"
"%^CYAN%^or %^RED%^gem%^MAGENTA%^sto%^RED%^nes %^CYAN%^set within it to decorate its simple design.  It forms "
"a narrow band at one side, presumably the back, and widens to an oval-shaped panel that must be designed as "
"the front.  Oddly, the panel itself is entirely %^RESET%^unmarked%^CYAN%^, leaving you to wonder at the "
"purpose for it.  To all appearances, it doesn't seem particularly valuable or appealing as far as jewelry "
"goes.%^RESET%^\n");
   set_lore("Stories abound of powerful artifacts that summon great powers from the humblest of wearers and "
"none are more popular then the tale of Kepney of Tempus and the Raging Horde.  Kepney was a small man who "
"had found himself in service to the Battle Lord as little more then an errand runner.  Though he dreamed of "
"great battles, Kepney could barely hold a sword upright little alone fight with one.  One day, Kepney was "
"racing from one battle camp to the next with an important message when he had the misfortune to trip over an "
"ancient and forgotten grave which promptly gave way and ended with Kepney in what little was left of the "
"coffin unconscious.  While Kepney slept, the spirit of the grave was finally able to bestow the artifact it "
"had guarded onto a worthy person.  A follower of Tempus whose heart was ready for battle but whose body was "
"not.  When Kepney awoke he found the slender band upon one finger and felt the courage and strength well up "
"within him.  The tale goes on to tell of how Kepney took up an ancient sword and raced out into the battle "
"field where he slew a great number of the Raging Horde single handedly and was hailed as the hero of field "
"from that day forward.");
   set_property("lore difficulty",20);
   set_limbs(({"right hand","left hand"}));
   set_weight(1);
   set_value(7350);
   set_size(-1);
   set_ac(0);
   set_type("ring");
   set_wear((:TO,"wear_fun":));
   set_remove((:TO,"remove_fun":));
   set_property("magic nonstacking",1); // this is magical equipment for the non-rop ring slot!
}

int wear_fun() {
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if((int)ETO->query_level() < 35 && !avatarp(TP)) {
     tell_object(ETO,"The ring won't fit on your fingers!");
     return 0;
   }
   if(member_array("martial weapon proficiency",(string*)ETO->query_temporary_feats()) == -1) {
     ETO->add_temporary_feat("martial weapon proficiency");
     martialtrack = 1;
   }
   if(member_array("exotic weapon proficiency",(string*)ETO->query_temporary_feats()) == -1) {
     ETO->add_temporary_feat("exotic weapon proficiency");
     exotictrack = 1;
   }
   tell_object(ETO,"%^RESET%^%^CYAN%^You slip the ring over a finger, and you feel a sudden battle readiness fill you.%^RESET%^");
   return 1;
}

int remove_fun() {
   tell_room(EETO,"%^RESET%^%^CYAN%^The battle readiness fades, and you feel normal again.%^RESET%^");
   if(exotictrack) {
     ETO->remove_temporary_feat("exotic weapon proficiency");
     exotictrack = 0;
   }
   if(martialtrack) {
     ETO->remove_temporary_feat("martial weapon proficiency");
     martialtrack = 0;
   }
   return 1;
}

int isMagic(){ return 1; }
