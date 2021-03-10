//updated by Circe 9/7/04 with new desc, etc.
#include <std.h>
inherit ARMOUR;

#define FABRICS ({"cotton","linen","wool","silk","brocade"})
#define COLORS ({"%^BOLD%^white","%^RESET%^%^ORANGE%^brown","%^RESET%^%^ORANGE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^n","%^BOLD%^%^BLUE%^blue","%^RESET%^%^BLUE%^navy","%^GREEN%^green","gray","%^RED%^red","%^RESET%^%^ORANGE%^orange","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple"})

void create(){
   int i,j;
   string FABRIC, COLOR, str;
   ::create();
   i = random(sizeof(FABRICS));
   FABRIC = FABRICS[i];
   j = random(sizeof(COLORS));
   COLOR = COLORS[j];
   if(!random(2)){
      str = "%^BOLD%^silver";
   }else{
      str = "%^YELLOW%^gold";
   }
   set_name("embroidered robe");
   set_id(({"embroidered robe","robe"}));
   set_short("finely embroidered "+COLOR+" "+FABRIC+" robe%^RESET%^");
   set_long("This exquisite robe is made from "+COLOR+" "+FABRIC+" "+
      "%^RESET%^that has been heavily embroidered in thread of "+
      ""+str+"%^RESET%^.  The pattern is little more than a "+
      "subtle addition to the already fine robe.  The robe has "+
      "wide bands of thicker embroidery around the wrists and "+
      "hem, giving the overall impression of wealth to anyone "+
      "who wears it - and carries it well.");
   set_weight(8);
   set_ac(1);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_size(random(3)+1);
   if(FABRIC == "brocade" || FABRIC == "silk"){
      set_value(60);
   }else{
      set_value(25);
   }
}
