//updated by Circe 1/1/05 with new desc and lore
#include <std.h>
inherit "/d/common/obj/armour/helm";

void create() {
    ::create();
    set_name("helmet of the Black Dawn");
    set_id(({"helmet of the Black Dawn","helmet","helm","horned helmet"}));
    set_short("%^BOLD%^%^BLACK%^Horned Helmet of the Black Dawn%^RESET%^");
    set_obvious_short("A helmet with horns");
    set_long("%^BOLD%^%^BLACK%^Made of %^RESET%^cold black iron%^BOLD%^"+
       "%^BLACK%^, this helmet has a faceplate that leaves only the "+
       "wearer's mouth visible.  Protruding from the top of the "+
       "helmet are three %^WHITE%^pristine ivory horns%^BLACK%^ that "+
       "curve toward the center.  The base of each %^WHITE%^horn "+
       "%^BLACK%^is encircled with a %^YELLOW%^golden band%^BLACK%^.  "+
       "The helm itself glitters darkly %^RESET%^%^BLUE%^blue "+
       "%^BOLD%^%^BLACK%^with a surface that seems to soak up the "+
       "%^YELLOW%^light%^BLACK%^.  A mesh curtain covers the back of "+
       "the head and around the neck, providing protection for the "+
       "wearer's entired head.\n%^RESET%^A message has been carved inside "+
       "for you to read.");
   set_lore("Worn by the dread undead warriors Ashtar and Bishimon, "+
       "the helm radiates an evil all its own.  It was crafted by the "+
       "dark arts of an evil even more ancient than the Kinnesaruda, "+
       "a power which lingers still.  Ashtar was once a god who has "+
       "been doomed to follow the will of Intruder ever since the "+
       "Kinnesaruda took over the land now known as Attaya.  Both "+
       "Ashtar and Bishimon guard over the Crystalline Tower of the "+
       "Black Dawn with no hope of ever freeing their damned souls.");
    set_property("lore difficulty",20);
   set_value(4000);
   set_property("enchantment",5);
   set_wear((:TO,"wearit":));
   set_remove((:TO,"removeme":));
   set_read("Only in death, can power be assessed...  In life it can only be acquired..");
}

int wearit() {
   int align;
   if(living(ETO)) align = ETO->query_alignment();
    if((int)ETO->query_lowest_level() < 25) {
	tell_object(ETO,"This item is far too powerful for you, puny one!");
	return 0;
    }
    if(align == 1 || align == 4 || align == 7){
       tell_object(ETO,"%^BOLD%^%^BLACK%^A great weight settles on "+
          "your shoulders, and you feel your heart darken as you wear "+
          "the helm.");
    }
   if(ETO->query_property("good item")) {
      tell_object(ETO,"The helm refused to be worn while you are using such goodly items!");
      return 0;
   }
   
    tell_object(ETO,"%^BOLD%^%^BLUE%^You slip the evil helmet over "+
       "your head and quickly grow accustomed to its weight.");
    tell_room(EETO,"%^BOLD%^%^BLUE%^"+ETOQCN+"'s face disappears "+
       "beneath a gruesome horned helmet.",ETO);
     ETO->set_property("evil item",1);
     return 1;
}
int removeme()
{
   tell_object(ETO,"With great force, the ancient helmet is torn away,"+
    " leaving bruises under your eyes.");
   ETO->set_property("evil item",-1);
   return 1;
}
