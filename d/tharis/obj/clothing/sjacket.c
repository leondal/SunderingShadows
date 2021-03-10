//updated by Circe 9/7/04 with new desc
#include <std.h>;
inherit ARMOUR;

#define COLORS ({"%^BOLD%^white","%^RESET%^%^ORANGE%^brown","%^RESET%^%^ORANGE%^t%^YELLOW%^a%^RESET%^%^ORANGE%^n","%^BOLD%^%^BLUE%^blue","%^RESET%^%^BLUE%^navy","%^GREEN%^green","gray","%^RED%^red","%^RESET%^%^ORANGE%^orange","%^BOLD%^%^BLACK%^black","%^RESET%^%^MAGENTA%^pu%^BOLD%^r%^RESET%^%^MAGENTA%^ple"})

void create(){
   int i;
   string COLOR, str;
   ::create();
   i = random(sizeof(COLORS));
   COLOR = COLORS[i];
   if(!random(2)){
      str = "%^BOLD%^silver";
   }else{
      str = "%^YELLOW%^gold";
   }
   set_name("silk jacket");
   set_id(({"silk jacket","jacket","fine jacket","fine silk jacket","brocade jacket"}));
   set_short("fine "+COLOR+" silk jacket%^RESET%^");  
   set_long("This fine jacket is made of high quality "+COLOR+" "+
      "brocade%^RESET%^, a type of heavy silk decorated with "+
      "light patterned embroidery.  The embroidery is mostly "+
      "scrollwork done in thread of "+str+"%^RESET%^, which helps "+
      "to pad the fabric as well as provide stunning ornamentation.  "+
      "The jacket has a low, stiff collar that has been more heavily "+
      "embroidered, and it may be worn open to reveal the wearer's "+
      "shirt - always matching, of course.  Rather than ending at "+
      "the hips, the jacket continues down nearly to the wearer's "+
      "knees, making the coat a little more formal than it might "+
      "otherwise be.");
   set_type("clothing");
   set_limbs(({"torso"}));
   set_weight(3);
   set_size(random(3)+1);
   set_value(80);
}
