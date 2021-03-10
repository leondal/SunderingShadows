//Random pants for Esteban's shop
//~Circe~ 11/27/07 for new Seneca
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
string COLOR, FABRIC;

void create_pants(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   val = random(10)+1;
   switch(val) {
      case 0..3: FABRIC = "cotton"; 
         obj->set_long("This pair of "+COLOR+" cotton pants %^RESET%^features "+
            "simple, straight legs with folded cuffs at the bottom.  "+
            "They are soft and comfortable, perfect for most normal "+
            "activities.");
         break;
      case 4..6: FABRIC = "linen"; 
         obj->set_long("Expertly crafted from breathable "+COLOR+" "+
            "linen%^RESET%^, this pair of pants has wide legs that "+
            "are smoothly hemmed.  Slender pockets have been sewn "+
            "into the sides, and if you look closely, you can see "+
            "slight variations in the color, revealing the loose "+
            "weave of the fabric that makes this such a relaxing "+
            "pair of pants.");
         break;
      case 7..8: FABRIC = "twill";
         obj->set_long("Crafted of %^BOLD%^h%^RESET%^e%^BOLD%^r%^RESET%^r"+
            "%^BOLD%^i%^RESET%^n%^BOLD%^g%^RESET%^b%^BOLD%^o%^RESET%^n"+
            "%^BOLD%^e %^RESET%^twill, this pair of pants has been "+
            "dyed in shades of "+COLOR+"%^RESET%^.  They are soft "+
            "and thick, resisting wrinkles and granting the one "+
            "who wears them a sophisticated look.  The pants "+
            "have small pockets and end with narrow cuffs.");
         break;
      default:   FABRIC = "corduroy"; 
         obj->set_long("Made with wide legs, these "+COLOR+" corduroy "+
            "pants %^RESET%^are left longer than most other pants.  "+
            "The material is beautiful, made of twisted fibers that are "+
            "woven together to form the cords that give the fabric its "+
            "name.  The unique construction of the material causes "+
            "the pants to make a slight swishing noise when the wearer "+
            "walks.");
         break;
   }
   obj->set_value(val*7);
   obj->set_name("pants");
   obj->set_type("clothing");
   obj->set_limbs(({"right leg","left leg"}));
   obj->set_weight(5);
   obj->set_short("A pair of "+COLOR+" "+FABRIC+" pants%^RESET%^");
   obj->set_id(({"pants","clothing",""+COLOR+" pants",""+FABRIC+" pants",""+COLOR+" "+FABRIC+" pants","pair of pants","pair of "+FABRIC+" pants",""+FABRIC+" pants","regular pants","esteban_clothing"}));
}
