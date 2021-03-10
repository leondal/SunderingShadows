//Thanks to Shar for the idea for this update :)
//Circe 4/25/04
// took brief lore from the old desc. Nienne, 08/07.
#include <std.h>

#define DRAGONS ({"%^RESET%^%^MAGENTA%^Am%^BOLD%^e%^WHITE%^t%^MAGENTA%^h%^RESET%^%^MAGENTA%^yst","%^RESET%^%^BLUE%^Sap%^BOLD%^p%^CYAN%^h%^BLUE%^i%^RESET%^%^BLUE%^re","%^YELLOW%^To%^RESET%^%^ORANGE%^p%^YELLOW%^az","%^RESET%^%^ORANGE%^Bra%^YELLOW%^s%^RESET%^%^ORANGE%^s","%^RESET%^%^ORANGE%^Br%^BOLD%^%^WHITE%^o%^RESET%^%^ORANGE%^nze","%^BOLD%^%^WHITE%^Si%^RESET%^l%^BOLD%^ver",\
"%^YELLOW%^G%^RESET%^%^ORANGE%^o%^YELLOW%^l%^RESET%^%^ORANGE%^d%^YELLOW%^","%^RESET%^St%^BOLD%^e%^RESET%^el","%^RESET%^%^ORANGE%^C%^GREEN%^o%^ORANGE%^p%^GREEN%^p%^ORANGE%^e%^GREEN%^r"})

inherit ARMOUR;

void create()
{
   int j;
   string str, VAR;
   ::create();
   j = random(9);
   str = DRAGONS[j];
   VAR = "a";
   if(str == "%^RESET%^%^MAGENTA%^Am%^BOLD%^e%^WHITE%^t%^MAGENTA%^h%^RESET%^%^MAGENTA%^yst") {
   VAR = "an";
   }
   set_name("monk's robe");
   set_short("%^RESET%^%^ORANGE%^Robe of the "+str+" Dragon%^RESET%^");
   set_obvious_short("an embroidered robe");
   set_id(({"robe","monk robe","monk's robe","dragon robe","robe of the dragon"}));
   set_long(
      "%^RESET%^%^ORANGE%^This long, flowing robe is made of a blend of "+
      "cotton and linen left a natural shade of tan.  It is extremely "+
      "comfortable and lightweight, as if "+
      "it was made to be worn in a %^MAGENTA%^sultry, humid region"+
      "%^ORANGE%^.  The long robes are loose in fit, perhaps to allow "+
      "a %^CYAN%^cooling breeze %^ORANGE%^"+
      "through the fabric's loose weave.  The robes have short sleeves, "+
      "stopping just above the elbows, most likely for comfort and ease "+
      "of movement.  The robes appear plain and almost monastic in "+
      "design, with nothing ornate or special about them.  That is, "+
      "until you see the detailed image of "+VAR+" "+str+" dragon %^RESET%^"+
      "%^ORANGE%^in flight that covers the back of the robes.  The "+
      "craftmanship on this embroidered image is extremely detailed - "+
      "you can make out each individual scale on the dragon!  Something "+
      "this fine and ornate must have taken years to create.%^RESET%^");
/*
@OLI
   This long flowing robe is the traditional garb of the
monks who have newly repopulated the monastery on tonerra.
Very few monks get to possess this robe, as it is a religious
robe. The depiction of a dragon on the back indicates that
only a master of understanding is wearing this.
OLI
old description
*/
     set_lore("This long flowing robe is the traditional garb of the "
"monks who have newly repopulated the monastery on tonerra. Very few "
"monks get to possess this robe, as it is a religious robe. The depiction "
"of a dragon on the back indicates that only a master of understanding "
"should be entitled to wear it. The emblem of the dragon is highly "
"revered among their number, who worship the great power and grace of "
"dragonkind.");
     set_property("lore",14);
   set_weight(5);
   set_value(2500);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_property("enchantment",4);
   set_wear((:TO,"wearme":));
}

int wearme(){
   if((int)TP->query_highest_level() < 20){
      tell_object(TP,"You feel horrible pain flow through you as you try to usurp what cannot be yours.");
      TP->do_damage("torso",roll_dice(3,10));
      return 0;
   }
   tell_object(TP,"You feel at peace with the world.");
   return 1;
}
