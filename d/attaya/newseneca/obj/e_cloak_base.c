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
string COLOR, FABRIC, TYPE;

void create_cloak(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   val = random(5)+1;
   val2 = random(8)+1;
   switch(val2){
      case 0..2: FABRIC = "cotton";
                 break;
      case 3..4: FABRIC = "wool";
                 break;
      case 5..6: FABRIC = "velvet";
                 break;
      default:   FABRIC = "satin";
                 break;
   }
   switch(val) {
      case 0..2: TYPE = "cape"; 
         obj->set_long("A creation made purely for fashion rather "+
            "than funciton, this cape is made of "+COLOR+" "+FABRIC+""+
            "%^RESET%^.  It is made from a half circle of fabric that "+
            "lets it fall in folds to the hips.  The dashing cape has "+
            "draw strings that can tie around the neck or be secured "+
            "to ornamental armor, and the entire cape has been edged "+
            "in shiny "+COLOR+" satin%^RESET%^.");
         break;
      case 3: TYPE = "cloak"; 
         obj->set_long("This cloak is made from supple "+COLOR+" "+
            ""+FABRIC+" %^RESET%^and reaches all the way to the "+
            "wearer's shins in loose folds.  Crafted from ample "+
            "material, the cloak is wide enough to be pulled over the "+
            "shoulders and features three coordinating "+COLOR+" wooden "+
            "toggles %^RESET%^to secure it closed.  The garment has a "+
            "wide hood that may be pulled forward to cover the head "+
            "in case of wind or rain.");
         break;
      case 4: TYPE = "mantle";
         obj->set_long("Differing from a cloak, this mantle features arm "+
            "slits and covers more of the body, reaching all the way to "+
            "the wearer's ankles.  It is crafted from soft "+COLOR+" "+
            ""+FABRIC+" %^RESET%^and is decorated with a row of twelve "+COLOR+" "+
            "silken ties %^RESET%^that are used to close the garment.  "+
            "Though it has no hood, the garment has a wide, rolled collar "+
            "that fastens with a %^YELLOW%^golden chain%^RESET%^.  "+
            "Small, half-circle pockets have even been sewn into the "+
            "mantle, showing that attention has been paid to every "+
            "little detail.");
         break;
      default:   TYPE = "tiered cloak"; 
         obj->set_long("This exquisite cloak is arranged in three tiers "+
            "of "+COLOR+" "+FABRIC+"%^RESET%^, each of which has been "+
            "lined with soft "+COLOR+" cashmere%^RESET%^.  The "+
            "tiered cloak is incredibly warm and considered the height "+
            "of fashion in many lands.  The top and bottom layers have "+
            "been edged with a wide band of contrasting fabric, "+
            "adding definition to the garment.  The last layer falls "+
            "in folds to the wearer's ankles, and "+COLOR+" gemstones "+
            "%^RESET%^running in a single row from the neckline to beyond "+
            "the hips provide secure closure to help keep the wearer "+
            "warm.  Completing the cloak is a wide hood, which lies perfectly "+
            "flat when not pulled forward.");
         break;
   }
   obj->set_value((val+val2)*10);
   obj->set_name("cloak");
   obj->set_type("clothing");
   obj->set_limbs(({"neck"}));
   obj->set_weight(3);
   obj->set_short(""+COLOR+" "+FABRIC+" "+TYPE+"%^RESET%^");
   obj->set_id(({"cloak","clothing",""+TYPE+"",""+COLOR+" "+TYPE+"",""+FABRIC+" "+TYPE+"",""+COLOR+" "+FABRIC+" "+TYPE+"","regular cloak","esteban_clothing"}));
}
