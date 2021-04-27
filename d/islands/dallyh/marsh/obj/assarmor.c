//updated by Circe to current code, new desc, etc.  4/15/04
//was AC 4, enchantment 2, made it inherit leather and 
//enchantment 4 instead for ease in upkeep - Circe
// armor worn by the ancient assassins
// commented out the return on damage - was doubling damage taken by wearer. Nienne, 06/09.

#include <std.h>

inherit "/d/common/obj/armour/leather";

void create(){
     ::create();
     set_name("ancient leather");
     set_id(({"armour","armor","leather","ancient leather","leather armor","ancient armor"}));
     set_obvious_short("aged leather armor");
     set_short("%^BOLD%^%^BLACK%^Ancient Leather%^RESET%^");
     set_long("%^BOLD%^%^BLACK%^This ancient suit of leather armor "+
        "has dark creases marring its surface, a sign "+
        "of its age.  A faded %^RESET%^%^ORANGE%^crest %^BOLD%^"+
        "%^BLACK%^is barely visible on the shoulders of the armor, "+
        "a pair of crossed %^RESET%^%^BLUE%^spears %^BOLD%^%^BLACK%^"+
        "upon a simple %^RESET%^%^GREEN%^green diamond%^BOLD%^%^BLACK%^."+
        "  It looks as though there may have been more to the crest, "+
        "but it has faded with the passing years.  The darkened armor "+
        "is fitted with deep gray cloth within the folds.%^RESET%^");
     set_lore("This armor is said to reach its truest potential "+
        "when worn by the dark mercenaries known as assassins.  "+
        "The armor was enchanted ages ago by a powerful shaman "+
        "on the island of Dallyh to provide the castle's guard "+
        "with exquisite protection, but the enchantment was warped "+
        "by the evil that invaded the island.  Some now say "+
        "that the armor has a will of its own.");
     set_weight(10);
     set_property("enchantment",4);
     set_item_bonus("attack bonus",1);
     set_item_bonus("damage bonus",1);
     set_value(2000);
     set_wear((:TO,"wearme":));
     set_remove((:TO,"unwearme":));
     set_struck((:TO,"strikeme":));
}

int wearme(){
   int align;
   align = ETO->query_alignment();
   if(!ETO->query_property("assassin") && !ETO->is_class("assassin") && !ETO->query("is_assassin") && !ETO->is_class("thief")){
      tell_object(ETO,"%^ORANGE%^The ancient leather feels "+
         "decrepit as you step into it.");
      tell_room(EETO,"%^ORANGE%^"+ETOQCN+"'s armor creaks like "+
         "an old man's bones as he wears it.",ETO);
   }
   if(align == 1 || align == 4 || align == 7){
      tell_object(ETO,"%^BOLD%^%^RED%^The ancient armor tells "+
      "you%^RESET%^:  What?! One of your persuasian seeking "+
      "my talents?  Hmm...very well.  In time, you will follow "+
      "my will!\n"+
      "You feel a strange change taking place over the armor!");
   } else {
      tell_object(ETO,"%^BOLD%^%^RED%^The ancient armor tells "+
         "you%^RESET%^:  Ahh yes...let us seek out the target!\n"+
         "You feel a strange change taking place over the armor!");
   }
   tell_room(EETO,"%^ORANGE%^Miraculously, "+ETOQCN+"'s decrepit-"+
      "looking armor begins to transform as "+ETO->QS+" wears it!",ETO);
   set_long("%^BOLD%^%^BLACK%^This pristine leather armor "+
      "seems ageless and flawless.  The deep gray cloth "+
      "blends well with the darkened %^RESET%^%^ORANGE%^"+
      "leather%^BOLD%^%^BLACK%^, making the wearer meld "+
      "into the shadows without even a thought.  The crest "+
      "upon the shoulders is quite a vivid image - what "+
      "once were spears are now %^RED%^"+
      "bloody %^BLACK%^scythes crossed upon a diamond of "+
      "%^RESET%^%^GREEN%^muted green%^BOLD%^%^BLACK%^.  "+
      "Just visible behind the scythes is a depiction of a "+
      "%^BLUE%^blue-black raven %^BLACK%^in mid-flight.  "+
      "No sign of age remains in the armor, and it seems "+
      "to fit the wearer perfectly.%^RESET%^");
   return 1;
}

int unwearme(){
   if(!ETO->query_property("assassin") && !ETO->is_class("assassin") && !ETO->query("is_assassin") && !ETO->is_class("thief")){
      tell_object(ETO,"You gratefully remove the decrepit "+
         "leather, thankful it held on for so long.");
      tell_room(EETO,""+ETOQCN+" carefully removes the "+
         "ancient-looking leather, seemingly surprised it's "+
         "still in one piece.",ETO);
      return 1;
   }
   tell_object(ETO,"%^BOLD%^%^RED%^The ancient armor tells "+
      "you%^RESET%^:  Tired already??  Hmmph.  Let's "+
      "find another mark!");
   tell_room(EETO,"%^ORANGE%^"+ETOQCN+"'s leather armor "+
      "seems to degrade before your eyes as "+
      ""+ETO->QS+" removes it.",ETO);
     set_long("%^BOLD%^%^BLACK%^This ancient suit of leather armor "+
        "has dark creases marring its surface, a sign "+
        "of its age.  A faded %^RESET%^%^ORANGE%^crest %^BOLD%^"+
        "%^BLACK%^is barely visible on the shoulders of the armor, "+
        "a pair of crossed %^RESET%^%^BLUE%^spears %^BOLD%^%^BLACK%^"+
        "upon a simple %^RESET%^%^GREEN%^green diamond%^BOLD%^%^BLACK%^."+
        "  It looks as though there may have been more to the crest, "+
        "but it has faded with the passing years.  The darkened armor "+
        "is fitted with deep gray cloth within the folds.%^RESET%^");
   return 1;
}

int strikeme(int damage, object what, object who){
   if(!ETO->query_property("assassin") && !ETO->is_class("assassin") && !ETO->query("is_assassin") && !ETO->is_class("thief")){
      tell_object(ETO,"%^ORANGE%^You curse to yourself "+
         "as yet another piece of the decrepit armor falls off!");
      tell_room(EETO,"%^ORANGE%^"+ETOQCN+" curses aloud as a "+
         "small chunk of "+ETO->QP+" armor falls off!",ETO);
      return 1;
   }
   if(random(1000) < 500){
      tell_room(environment(query_worn()),"%^BLUE%^"+ETOQCN+"'s "+
         "eyes %^BOLD%^flash %^RESET%^%^BLUE%^as a strange aura "+
         "pours out from "+ETO->QP+" armor toward "+
         ""+who->QCN+"!",({ETO,who}));
      tell_object(who,"%^RESET%^%^BLUE%^You watch in horror as "+
         "a malevolent spirit flies forth from "+ETOQCN+"'s "+
         "armor, striking you!");
      switch(random(5)){
         case 0:  tell_object(ETO,"%^BOLD%^%^RED%^The ancient armor tells "+
                   "you%^RESET%^:  My turn!!\n%^RESET%^%^BLUE%^A vaporous "+
                   "spirit flies out from the armor, striking "+who->QCN+"!");
                   break;
         case 1:  tell_object(ETO,"%^BOLD%^%^RED%^The ancient armor tells "+
                   "you%^RESET%^:  You know I can't let you "+
                   "have all the fun!!\n%^RESET%^%^BLUE%^A vaporous "+
                   "spirit flies out from the armor, striking "+who->QCN+"!");
                   break;
         case 2:  tell_object(ETO,"%^BOLD%^%^RED%^The ancient armor tells "+
                   "you%^RESET%^:  Hey, watch this!!\n%^RESET%^%^BLUE%^A vaporous "+
                   "spirit flies out from the armor, striking "+who->QCN+"!");
                   break;
         case 3:  tell_object(ETO,"%^BOLD%^%^RED%^The ancient armor tells "+
                   "you%^RESET%^:  Ooo, this'll hurt!!\n%^RESET%^%^BLUE%^A vaporous "+
                   "spirit flies out from the armor, striking "+who->QCN+"!");
                   break;
         case 4:  tell_object(ETO,"%^BOLD%^%^RED%^The ancient armor tells "+
                   "you%^RESET%^:  Think I'll just take being hit like "+
                   "that?!\n%^RESET%^%^BLUE%^A vaporous "+
                   "spirit flies out from the armor, striking "+who->QCN+"!");
                   break;
      }
      who->do_damage("torso",roll_dice(1, 10) + 5);
  }
  return damage;
}
