#include <std.h>
inherit "/d/common/obj/weapon/hhlance";

int OWNED, state;
string *owners;
void set_mydesc(int myalign);

void create() {
   ::create();
   set_mydesc(0);
   set_lore("%^BOLD%^%^WHITE%^...Chazael the enchanter was ever a clever merchant, knowing full well that to appeal with "
"a unique product to the nobility, was to benefit from the riches of some of the richest in the realm.  None of his wares "
"were so readily embraced, however, than those he enchanted to proclaim the true intent of the wearer.  He crafted "
"tabards, armor and weaponry enchanted to blaze with the pure light of the righteous, or the fearsome glow of the tyrant, "
"whenever held and worn.  This is likely one of those items, which in the hands of a knight, will blaze forth with his "
"true intent.%^RESET%^");
   set_property("lore difficulty",35);
   set_property("id difficulty",35);
   set_value(10720);
   set_property("enchantment",5);
   while((int)TO->query_property("enchantment") != 5) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",5);
   }
   set_item_bonus("attack bonus",4);
   set_item_bonus("damage bonus",4);
   set_wield((:TO,"wield_func":));
   set_unwield((:TO,"unwield_func":));
   set_hit((:TO,"hit_func":));
   set_property("no alter",1);
   owners = ({});
}

void init() {
   ::init();
   if(!TO->query_wielded()) set_mydesc(0);
}

int wield_func(){
   if(member_array("%^BOLD%^%^BLACK%^Vanquished Arkhon Bloodscale, ancient dragon of the deep!%^RESET%^",ETO->query_mini_quests())== -1) {
     tell_object(ETO,"%^BOLD%^%^WHITE%^You have not earned the right to make use of this item.%^RESET%^");
     return 0;
   }
   if(ETO->query_level() < 35) {
     tell_object(ETO,"You are not experienced enough to use this weapon.");
     return 0;
   }
   tell_room(EETO,"%^BOLD%^%^WHITE%^The pennant secured at the lance's tip ripples as a blaze of color passes over it, "
"spreading down the length of the weapon!%^RESET%^");
   switch(ETO->query_alignment()) {
     case 1: case 4: case 7: set_mydesc(1); break;
     case 2: case 5: case 8: set_mydesc(2); break;
     case 3: case 6: case 9: set_mydesc(3); break;
     default: set_mydesc(0); break;
   }
   return 1;
}

int unwield_func(){
   tell_room(EETO,"%^ORANGE%^The lance visibly dulls as it is laid aside, resuming its mundane appearance.%^RESET%^");
   set_mydesc(0);
   return 1;
}

int hit_func(object targ){
   int skinned;
   ::check(targ);
   if(!objectp(TO)) return 1;
   if(!objectp(ETO)) return 1;
   if(!objectp(targ)) return 1;
   targ = ETO->query_current_attacker();
   if(random(1000) < 200){
     switch(random(6)){
       case 0..2:
         tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" delivers a jarring blow to "+targ->QCN+" with the blunted tip of "
+ETO->QP+" lance!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^BOLD%^%^WHITE%^You deliver a jarring blow to "+targ->QCN+" with the blunted tip of your "
"lance!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+" delivers a jarring blow to you with the blunted tip of "+ETO->QP+
" lance!%^RESET%^");
         return roll_dice(2,4);
       break;
       case 3..4:
         tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s lance impacts into "+targ->QCN+" with enough force to send "
+targ->QO+" sprawling!%^RESET%^",({ETO,targ}));
         tell_object(ETO,"%^BOLD%^%^WHITE%^You ride into "+targ->QCN+" with enough force from your lance to send "
+targ->QO+" sprawling!%^RESET%^");
         tell_object(targ,"%^BOLD%^%^WHITE%^"+ETOQCN+"'s lance impacts into you with brutal force, leaving you winded "
"and sprawled on the ground!%^RESET%^");
         targ->set_paralyzed(7,"%^BOLD%^%^CYAN%^You're still trying to regain your feet!%^RESET%^");
         skinned = (int)targ->query_stoneSkinned();
         if(skinned) {
           tell_room(EETO,"%^BOLD%^%^CYAN%^The force of the impact shatters layers of "+targ->QCN+"'s "
"defenses!%^RESET%^",targ);
           tell_object(targ,"%^BOLD%^%^CYAN%^The force of the blow shatters layers of your defenses!%^RESET%^");
           targ->set_stoneSkinned(0);
         }
       break;
       case 5:
         switch(state) {
           case 1:
           tell_room(EETO,"%^BOLD%^%^WHITE%^Brilliant %^YELLOW%^lig%^WHITE%^h%^YELLOW%^t %^WHITE%^spirals down the "
"etched length of "+ETOQCN+"'s lance, and "+ETO->QS+" looks invigorated!%^RESET%^",({ETO,targ}));
           tell_object(ETO,"%^BOLD%^%^WHITE%^Brilliant %^YELLOW%^lig%^WHITE%^h%^YELLOW%^t %^WHITE%^spirals down the "
"etched length of your lance, and you feel refreshed!%^RESET%^");
           break;
           case 3:
           tell_room(EETO,"%^BOLD%^%^WHITE%^Vivid %^GREEN%^lig%^BLACK%^h%^GREEN%^t %^WHITE%^spirals down the etched "
"length of "+ETOQCN+"'s lance, and "+ETO->QS+" looks invigorated!%^RESET%^",({ETO,targ}));
           tell_object(ETO,"%^BOLD%^%^WHITE%^Vivid %^GREEN%^lig%^BLACK%^h%^GREEN%^t %^WHITE%^spirals down the etched "
"length of your lance, and you feel refreshed!%^RESET%^");
           break;
           default:
           tell_room(EETO,"%^BOLD%^%^WHITE%^Incandescent %^RED%^lig%^RESET%^%^RED%^h%^BOLD%^t %^WHITE%^spirals down the "
"etched length of "+ETOQCN+"'s lance, and "+ETO->QS+" looks invigorated!%^RESET%^",({ETO,targ}));
           tell_object(ETO,"%^BOLD%^%^WHITE%^Incandescent %^RED%^lig%^RESET%^%^RED%^h%^BOLD%^t %^WHITE%^spirals down the "
"etched length of your lance, and you feel refreshed!%^RESET%^");
           break;
         }
         ETO->add_hp(100-random(40));
       break;
     }
   return 0;
   }
}

void set_mydesc(int myalign) {
   switch(myalign) {
     case 1:
     TO->set_name("white-oak lance");
     TO->set_id(({"lance","oak lance","sturdy lance","sturdy oak lance","standard","standard of the valorous champion","Standard of the Valorous Champion","white oak lance","white-oak lance","emblazoned lance"}));
     TO->set_short("%^BOLD%^%^WHITE%^Sta%^YELLOW%^n%^WHITE%^dard of the Valo%^YELLOW%^r%^WHITE%^ous Champion%^RESET%^");
     TO->set_obvious_short("%^BOLD%^%^WHITE%^em%^YELLOW%^b%^WHITE%^lazo%^YELLOW%^n%^WHITE%^ed white-oak lance%^RESET%^");
     TO->set_long("%^RESET%^This lance is crafted of pristine %^BOLD%^%^WHITE%^white oak%^RESET%^, ensuring it is solid "
"enough not to bend or shatter under pressure.  At least twelve feet long, its narrow tip is slightly %^CYAN%^bl"
"%^MAGENTA%^unt%^CYAN%^ed %^RESET%^so as to cause forceful damage to foes without directly impaling them.  The weapon "
"follows a notched spiral along its length until it abruptly broadens, sweeping up towards the end to form a conical "
"barrier over the top of the wielder's hand.  Beneath this, a ridged wooden hilt offers a more secure grip, and enough "
"length to couch it under the arm for better %^GREEN%^st%^CYAN%^ab%^GREEN%^i%^CYAN%^li%^GREEN%^ty %^RESET%^in combat.  "
"The weapon has been carefully crafted so that the balance point is much closer to the hilt, allowing for ease of use in "
"one hand.  At the very tip of the lance, a %^BOLD%^%^WHITE%^twin-pointed pennant %^RESET%^flies proudly, displaying the "
"crest of a %^YELLOW%^regal go%^RESET%^%^ORANGE%^ld%^YELLOW%^en dragon%^RESET%^.\n");
     state = 1;
     break;

     case 2:
     TO->set_name("red-oak lance");
     TO->set_id(({"lance","oak lance","sturdy lance","sturdy oak lance","standard","standard of the valorous champion","Standard of the Valorous Champion","red oak lance","red-oak lance","emblazoned lance"}));
     TO->set_short("%^RESET%^%^RED%^Sta%^BOLD%^n%^RESET%^%^RED%^dard of the Valo%^BOLD%^r%^RESET%^%^RED%^ous Champion%^RESET%^");
     TO->set_obvious_short("%^RESET%^%^RED%^em%^BOLD%^b%^RESET%^%^RED%^lazo%^BOLD%^n%^RESET%^%^RED%^ed red-oak lance%^RESET%^");
     TO->set_long("%^RESET%^This lance is crafted of pristine %^RED%^red oak%^RESET%^, ensuring it is solid "
"enough not to bend or shatter under pressure.  At least twelve feet long, its narrow tip is slightly %^CYAN%^bl"
"%^MAGENTA%^unt%^CYAN%^ed %^RESET%^so as to cause forceful damage to foes without directly impaling them.  The weapon "
"follows a notched spiral along its length until it abruptly broadens, sweeping up towards the end to form a conical "
"barrier over the top of the wielder's hand.  Beneath this, a ridged wooden hilt offers a more secure grip, and enough "
"length to couch it under the arm for better %^GREEN%^st%^CYAN%^ab%^GREEN%^i%^CYAN%^li%^GREEN%^ty %^RESET%^in combat.  "
"The weapon has been carefully crafted so that the balance point is much closer to the hilt, allowing for ease of use in "
"one hand.  At the very tip of the lance, a %^BOLD%^%^WHITE%^twin-pointed pennant %^RESET%^flies proudly, displaying the "
"crest of a %^RED%^fierce red dr%^BOLD%^a%^RESET%^%^RED%^gon%^RESET%^.\n");
     state = 2;
     break;

     case 3:
     TO->set_name("black-oak lance");
     TO->set_id(({"lance","oak lance","sturdy lance","sturdy oak lance","standard","standard of the valorous champion","Standard of the Valorous Champion","black oak lance","black-oak lance","emblazoned lance"}));
     TO->set_short("%^BOLD%^%^BLACK%^Sta%^RESET%^n%^BOLD%^%^BLACK%^dard of the Valo%^RESET%^r%^BOLD%^%^BLACK%^ous Champion%^RESET%^");
     TO->set_obvious_short("%^BOLD%^%^BLACK%^em%^RESET%^b%^BOLD%^%^BLACK%^lazo%^RESET%^n%^BOLD%^%^BLACK%^ed black-oak lance%^RESET%^");
     TO->set_long("%^RESET%^This lance is crafted of pristine %^BOLD%^%^BLACK%^black oak%^RESET%^, ensuring it is solid "
"enough not to bend or shatter under pressure.  At least twelve feet long, its narrow tip is slightly %^CYAN%^bl"
"%^MAGENTA%^unt%^CYAN%^ed %^RESET%^so as to cause forceful damage to foes without directly impaling them.  The weapon "
"follows a notched spiral along its length until it abruptly broadens, sweeping up towards the end to form a conical "
"barrier over the top of the wielder's hand.  Beneath this, a ridged wooden hilt offers a more secure grip, and enough "
"length to couch it under the arm for better %^GREEN%^st%^CYAN%^ab%^GREEN%^i%^CYAN%^li%^GREEN%^ty %^RESET%^in combat.  "
"The weapon has been carefully crafted so that the balance point is much closer to the hilt, allowing for ease of use in "
"one hand.  At the very tip of the lance, a %^BOLD%^%^WHITE%^twin-pointed pennant %^RESET%^flies proudly, displaying the "
"crest of a %^BOLD%^%^BLACK%^snarling b%^RESET%^l%^BOLD%^%^BLACK%^ack dragon%^RESET%^.\n");
     state = 3;
     break;

     default:
     TO->set_name("oak lance");
     TO->set_id(({"lance","oak lance","sturdy lance","sturdy oak lance","standard","standard of the valorous champion","Standard of the Valorous Champion"}));
     TO->set_short("%^RESET%^%^ORANGE%^Sta%^RED%^n%^ORANGE%^dard of the Valo%^RED%^r%^ORANGE%^ous Champion%^RESET%^");
     TO->set_obvious_short("%^RESET%^%^ORANGE%^stu%^RED%^r%^ORANGE%^dy oak lance%^RESET%^");
     TO->set_long("%^RESET%^This lance is crafted of %^ORANGE%^he%^RED%^av%^ORANGE%^y oak%^RESET%^, ensuring it is solid "
"enough not to bend or shatter under pressure.  At least twelve feet long, its narrow tip is slightly %^CYAN%^bl"
"%^MAGENTA%^unt%^CYAN%^ed %^RESET%^so as to cause forceful damage to foes without directly impaling them.  The weapon "
"follows a notched spiral along its length until it abruptly broadens, sweeping up towards the end to form a conical "
"barrier over the top of the wielder's hand.  Beneath this, a ridged wooden hilt offers a more secure grip, and enough "
"length to couch it under the arm for better %^GREEN%^st%^CYAN%^ab%^GREEN%^i%^CYAN%^li%^GREEN%^ty %^RESET%^in combat.  "
"The weapon has been carefully crafted so that the balance point is much closer to the hilt, allowing for ease of use in "
"one hand.  At the very tip of the lance, a %^BOLD%^%^WHITE%^twin-pointed pennant %^RESET%^flies proudly, although it "
"bears no crest or image.\n");
     state = 0;
     break;
   }
}

void bind_me(string *pplz) {
   owners += pplz;
   OWNED = 1;
}

string * bound_to() {
   if(sizeof(owners)) return owners;
   return 0;
}
