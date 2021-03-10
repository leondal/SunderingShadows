//Some descriptions taken from /d/common/obj/rand/r_shoes.c
//Adapted by ~Circe~ for new Seneca 11/29/07
#include <std.h>

#define COLORS ({"%^RESET%^%^ORANGE%^amber",\
"%^RESET%^%^MAGENTA%^ame%^BOLD%^t%^RESET%^%^MAGENTA%^hyst",\
"%^BOLD%^%^MAGENTA%^ap%^YELLOW%^r%^MAGENTA%^ic%^YELLOW%^o%^MAGENTA%^t",\
"%^BOLD%^%^CYAN%^aqua",\
"%^RESET%^%^RED%^au%^ORANGE%^b%^RED%^urn",\
"%^RESET%^%^CYAN%^azure",\
"%^BOLD%^%^BLACK%^black",\
"%^RESET%^%^ORANGE%^bronze",\
"%^RESET%^%^ORANGE%^brown",\
"%^RESET%^%^RED%^burgandy",\
"%^BOLD%^%^RED%^cardinal",\
"%^RESET%^%^ORANGE%^c%^BOLD%^%^BLACK%^o%^RESET%^%^ORANGE%^f%^BOLD%^%^BLACK%^f%^RESET%^%^ORANGE%^e%^BOLD%^%^BLACK%^e",\
"%^BOLD%^%^BLUE%^cobalt",\
"%^RESET%^%^GREEN%^forest green",\
"%^RESET%^%^ORANGE%^goldenrod",\
"%^BOLD%^%^BLACK%^gray",\
"%^RESET%^%^BLUE%^indigo",\
"%^RESET%^%^GREEN%^j%^BOLD%^a%^RESET%^%^GREEN%^d%^BOLD%^e",\
"%^RESET%^%^MAGENTA%^purple",\
"%^RESET%^%^ORANGE%^russet",\
"%^RESET%^%^RED%^rust",\
"%^RESET%^%^CYAN%^s%^GREEN%^e%^CYAN%^a%^GREEN%^-%^CYAN%^g%^GREEN%^r%^CYAN%^e%^GREEN%^e%^CYAN%^n",\
"%^BOLD%^%^BLACK%^s%^RESET%^l%^BOLD%^%^BLACK%^a%^RESET%^t%^BOLD%^%^BLACK%^e%^RESET%^ g%^BOLD%^%^BLACK%^r%^RESET%^a%^BOLD%^%^BLACK%^y",\
"%^RESET%^%^CYAN%^steel blue",\
"%^BOLD%^%^WHITE%^white"})

inherit DAEMON;

int val,val2;
string COLOR, TYPE;

void create_shoes(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   val = random(10)+1;
   switch(val) {
      case 0..3: TYPE = "shoes"; 
         obj->set_long("Crafted from suede, these shoes have been dyed "+
            ""+COLOR+"%^RESET%^.  The padded leather soles of the shoes "+
            "help to ensure the feet are kept safe from harm.  Pieced "+
            "together in sections, the seams of the shoes help to offer "+
            "a perfect, tight fit.  The pointed-toed shoes lace up the "+
            "front, letting the wearer determine just how tight to lace "+
            "them.");  
         break;
      case 4..8: TYPE = "boots"; 
         obj->set_long("Crafted from suede, these high boots have been "+
            "dyed "+COLOR+"%^RESET%^.  The padded leather soles of these "+
            "boots help to ensure the feet are kept safe from harm.  "+
            "Running down the back seams are a series of laces, allowing "+
            "for the wearer to slip into these knee high boots.  The "+
            "suede is soft enough that movement is not compromised, while "+
            "offering some protection to one's feet.");
         break;
      default:   TYPE = "riding boots"; 
         obj->set_long("Crafted from hard suede, these riding boots have "+
            "been dyed "+COLOR+"%^RESET%^.  The hard leather soles of the "+
            "boots help to ensure the feet are kept safe from harm.  The "+
            "square-toed boots rise to mid-shin, the stiff suede offering "+
            "protection.  Without any laces, one's feet have to be gently forced "+
            "into these boots, creating a tight fit.");
         break;
   }
   obj->set_value((val*3)+45);
   obj->set_name("shoes");
   obj->set_type("clothing");
   obj->set_limbs(({"right foot","left foot"}));
   obj->set_weight(2);
   obj->set_short("a pair of "+COLOR+" "+TYPE+"%^RESET%^");
   obj->set_id(({"shoes","clothing",""+COLOR+" shoes",""+TYPE+"",""+COLOR+" "+TYPE+"","regular shoes","pair of shoes","pair of "+TYPE+"","pair of "+COLOR+" "+TYPE+"","esteban_clothing"}));
}
