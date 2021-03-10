//updated to current code ~Circe~ 10/5/19
//removed references to old gods ~Circe~ 7/30/19
#include <std.h>
inherit "/d/common/obj/clothing/magerobe.c";

void create(){
   ::create();
   set_name("robe of moonlight");
   set_id(({"robe","robe of moonlight","silver robe"}));
   set_short("%^BOLD%^%^WHITE%^Robe of M%^RESET%^o%^BOLD%^o%^RESET%^n%^BOLD%^l%^RESET%^i%^BOLD%^g%^RESET%^h%^BOLD%^t%^RESET%^");
   set_obvious_short("%^BOLD%^%^WHITE%^A loose fitting silver robe%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^Shimmering like molten %^CYAN%^s%^WHITE%^ilv%^CYAN%^e%^WHITE%^r, this loose fitting robe carries an almost %^RESET%^%^MAGENTA%^ethereal%^BOLD%^%^WHITE%^ quality to it.  The soft milky white cloth of the robe is cut full, giving little shape to the garment. The rounded scoop collar of the robe bears an uncanny resemblance to a %^CYAN%^crescent moon%^BOLD%^%^WHITE%^.  The thin cloth of the robe flows in gentle folds and pleats as it pools on the floor.  A belt of %^RESET%^silver%^BOLD%^ chains with moonstone charms serves as the only way to secure this ethereal robe to one's body.  The moonstone charms cycle through the phases of the %^YELLOW%^moon%^WHITE%^, each one made with a delicate precision.%^RESET%^");
   set_value(1500);
   set_lore("The Robe of Moonlight was crafted by a human sorceress named Moiraine devoted to Lysara. Moriane was one of those rare types of wizards who did not lock herself away in a tower. Instead, she travelled from village to village looking for how she could help others.  Noted for her cool, seriene nature, Moriaine was trusted by many rulers and common folk alike.  One of her greatest foes was an adherent of The Faceless One who liked to infest others' dreams.");
   set_property("lore difficulty",16);
   set_property("enchantment",3);
   set_wear((:TO,"wear_func":));
   set_remove((:TO,"remove_func":));
   set_struck((:TO,"strike_func":));
}

int wear_func(){
     if(member_array("%^BOLD%^%^CYAN%^Lucid Dreams%^RESET%^",ETO->query_mini_quests())== -1) {
      tell_object(ETO,"You have not earned the right to make use of this item.");
      return 0;
   }
   if((int)ETO->query_highest_level() < 20) {
    tell_object(ETO,"The robe refuses to be worn by one as weak as you.");
        return 0;
   }
   if((string)ETO->query_diety() == "lysara"){
      tell_object(ETO,"%^BOLD%^%^WHITE%^Sliding into the milky white robe, you feel a soothing serenity.%^RESET%^");
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" slides into "+ETO->QP+" milky white robe, the moonstone charms around "+ETO->QP+" waist glow softly.%^RESET%^",ETO);
      set_item_bonus("magic resistance",1);
      set_item_bonus("sight bonus",5);
      return 1;
   }else{
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" slips in a milky white robe.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^You slip on the milky white robe, you can almost a calm serenity wash over you.%^RESET%^");
      set_item_bonus("magic resistance",1);
      set_item_bonus("sight bonus",2);
      return 1;
   }
}

int remove_func(){
   if((string)ETO->query_diety() == "lysara"){
      tell_object(ETO,"%^BOLD%^%^WHITE%^Sliding out of the milky white robe, the soothing serenity fades away gently.%^RESET%^");
      tell_room(EETO,"%^BOLD%^%^WHITE%^"+ETOQCN+" slides out of "+ETO->QP+" milky white robe, the moonstone charms around "+ETO->QP+" waist cease to glow.%^RESET%^",ETO);
      return 1;
   }else{
      tell_room(EETO,"%^BOLD%^"+ETOQCN+" slips out of the milky white robe.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^You slip out of the milky white robe.%^RESET%^");
      return 1;
   }
}

int strike_func(int damage, object what, object who){
   if(random(1000) < 125){
      tell_room(environment(query_worn()),"%^BOLD%^%^WHITE%^Motes of silver light flash around "+ETOQCN+"'s robe, jolting  "+who->QCN+" in the process.%^RESET%^",({ETO,who}));
      tell_object(ETO,"%^BOLD%^%^WHITE%^Motes of silver light rise off the robe in your defense, jolting "+who->QCN+".%^RESET%^");
      tell_object(who,"%^BOLD%^%^WHITE%^Motes of silver light rise off of "+ETOQCN+"'s robe, slamming into you with a jolt.%^RESET%^");
      who->do_damage(who->return_limb(),random(4)+6);
   }
}

