#include <std.h>
inherit "/d/common/obj/armour/fullplate";

void create(){
   ::create();
   set_name("fullplate");
   set_short("%^BOLD%^%^BLACK%^Fullplate of the %^RESET%^%^RED%^Et%^ORANGE%^er%^YELLOW%^na%^RED%^l B%^RESET%^%^RED%^la%^ORANGE%^ze%^RESET%^");
   set_obvious_short("%^RESET%^%^ORANGE%^fl%^RED%^am%^BOLD%^e-%^YELLOW%^sw%^RESET%^%^ORANGE%^ep%^RED%^t "
"%^BOLD%^%^BLACK%^fullplate armor%^RESET%^");
   set_id(({"plate","fullplate","armour","armor","full plate","flameswept armor","flame-swept armor","flame swept armor","fullplate armor","flame-swept fullplate armor"}));
   set_long("%^BOLD%^%^BLACK%^This fullplate is crafted in the impressive, high-gothic style of the "
"middle-ages, perfectly forged like none you've seen in your life.  For a creation this flawless, it is quite "
"probable that magic had a hand in its making.  The plates have been carefully fitted and angled to achieve "
"maximum protection for the wearer.  It must have been originally created from black steel, as there are still "
"traces of the %^RESET%^blackened metal %^BLACK%^%^BOLD%^that show upon its surface.  Most of it, however, has "
"been tinted in waves of brilliant color, through deeper %^RESET%^%^ORANGE%^copper %^BLACK%^%^BOLD%^and "
"%^RESET%^%^RED%^crimson%^BLACK%^%^BOLD%^, to brilliant %^RED%^scarlet %^BLACK%^and %^YELLOW%^gold%^BLACK%^.  "
"It's difficult to discern whether this tinting was formed by some unknown smithing technique to alter the "
"metal, or whether actual different metals such as gold and copper were used in its creation.  Beneath the "
"plates is a backing of %^RESET%^%^ORANGE%^padding %^BLACK%^%^BOLD%^and %^RESET%^%^WHITE%^chainmail%^BLACK%^"
"%^BOLD%^, to ensure both better protection and comfort for the wearer.%^RESET%^");
   set_lore("%^WHITE%^%^BOLD%^This plate resembles the one worn by the reknowned warrior Khash Annarlak.  "
"Beginning his life as a warrior in one of the many fighting pits of the southern Tsarven empire, he gathered "
"riches and repute through his skill in combat, particularly the trident as his weapon of choice.  Upon "
"purchasing his freedom, he was later taken into the fold of the Flamelord, as a defender of the church, and "
"was greatly feared as a scourge of Aurilian clergy wherever they could be found.%^RESET%^");
   set_property("lore",22);
   set_value(0);
   while ((int)TO->query_property("enchantment") != 3) {
     TO->remove_property("enchantment");
     TO->set_property("enchantment",3);
   }
   set_item_bonus("fortitude",2);
   set_size(-1);
   set_wear((:TO,"wearme":));
   set_remove("%^RED%^%^BOLD%^You reluctantly slip out of the flawless fullplate, feeling not quite as "
"self-assured as before.%^RESET%^");
   set_struck((:TO,"strikeme":));
   set_overallStatus(220);
   set_property("no disenchant",1);
}

int wearme(){
   if(ETO->query_level() < 20){
     tell_object(ETO,"You are not experienced enough to use this equipment.");
     tell_object(ETO,"%^RED%^%^BOLD%^As you touch the armor, it becomes intensely hot and burns you!%^RESET%^");
     tell_room(EETO,"%^RED%^%^BOLD%^"+ETO->QCN+" jerks away as if burnt when "+ETO->QS+" tries to wear the armor.",ETO);
     set_property("magic",1);
     ETO->cause_typed_damage(ETO, "torso", roll_dice(1, 20) + 29, "fire");
     ETO->add_attacker(TO);
     ETO->continue_attack();
     ETO->remove_attacker(TO);
     remove_property("magic");
     return 0;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^Confidence fills you as the fullplate encases your body.%^RESET%^");
   tell_room(EETO,"%^BOLD%^%^RED%^"+ETO->QCN+" holds "+ETO->QP+" head up high as "+ETO->QS+" slips "
"into the flawless fullplate.%^RESET%^",ETO);
   return 1;
}

int strikeme(int damage, object what, object who){
   if(random(2)) {
     tell_object(ETO,"%^BOLD%^%^BLACK%^Your fullplate takes on an inner %^RESET%^%^ORANGE%^h%^RED%^e%^BOLD%^a"
"%^YELLOW%^t%^BLACK%^, and absorbs the entire force of "+who->QCN+"'s attack.%^RESET%^");
     tell_object(who,"%^BOLD%^%^BLACK%^The air around "+ETO->QCN+" shimmers with %^RESET%^%^ORANGE%^h%^RED%^e"
"%^BOLD%^a%^YELLOW%^t%^BLACK%^, as the strength of your attack is harmlessly absorbed by "+ETO->QP+
"fullplate.%^RESET%^");
     tell_room(environment(query_worn()),"%^BOLD%^%^BLACK%^The air around "+ETO->QCN+" shimmers with "
"%^RESET%^%^ORANGE%^h%^RED%^e%^BOLD%^a%^YELLOW%^t%^BLACK%^, as the strength of "+who->QCN+"'s attack is "
"harmlessly absorbed by "+ETO->QP+" fullplate.%^RESET%^",({ETO,who}));
     return (-1)*(damage);
   }
   return 1;
}