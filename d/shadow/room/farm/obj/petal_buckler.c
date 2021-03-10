#include <std.h>
inherit "/d/common/obj/armour/buckler";

void create() {
    ::create();
    set_name("petal buckler");
    set_id(({"shield","buckler shield","buckler","petal buckler","buckler of the lilies"}));
    set_obvious_short("a strange buckler shield");
    set_short("%^BOLD%^%^CYAN%^Buckler of the %^MAGENTA%^Lilies%^RESET%^");
    set_long("This shield is made from the petals of a most unusual "+
       "lily.  The petals themselves give very little, providing a "+
       "strong protection that naturally wraps around the shield-"+
       "bearer's forearm.  The shield is colored a vibrant %^BOLD%^"+
       "%^CYAN%^azure %^RESET%^dotted with %^BOLD%^%^MAGENTA%^pink"+
       "%^RESET%^, making it somewhat unusual compared to most "+
       "shields made of leather.  %^GREEN%^Leafy protrusions "+
       "%^RESET%^are fitted around the shield, each fitted with "+
       "tiny barbs.  Despite its most unique construction, the "+
       "shield would likely offer some amount of protection.");
   set_lore("This strange shield is actually made of the petals of "+
       "a little known flower called the Death Lily.  This lily "+
       "was cultivated by Piaf Huffelmuffin, a member of the "+
       "Gnomish Experimenters' League who tried his hand at "+
       "horticulture before he realized that the field was not "+
       "for him.  He all but forgot the Death Lily, which has "+
       "a way of sprouting up even in the most adverse conditions.  "+
       "Strangely, the petals themselves seem to form this "+
       "unusual shield, with little actual crafting going into "+
       "the shields construction.  An Observation of Piaf - "+
       "Theadora Illonium.");
   set_property("lore difficulty",8);
   set_property("enchantment",1);
   set_wear("%^BOLD%^%^MAGENTA%^The shield molds itself to your forearm.");
   set_remove("%^BOLD%^%^MAGENTA%^You pry the shield off your arm.");
   set_struck((:TO,"strikeme":));
}

int strikeme(int damage, object what, object who){
  if(random(1000) < 150){
        tell_room(environment(query_worn()),"%^GREEN%^The barbs on "+
           ""+ETOQCN+"'s shield pull at "+who->QCN+", cutting "+
           ""+who->QO+"!",({ETO,who}));
        tell_object(ETO,"%^GREEN%^You hear a ripping sound as the "+
           "barbs on your shield tear at "+who->QCN+"!");
        tell_object(who,"%^GREEN%^You feel your flesh rip as the "+
           "barbs on "+ETOQCN+"'s shield cut you!");
        who->do_damage("left arm",roll_dice(1,8));
        return damage;
  }
}

int isMagic(){
   int magicshield;
   magicshield = ::isMagic();
   magicshield = magicshield+1;
   return magicshield;
}