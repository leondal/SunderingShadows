//Random shirts for Esteban's shop
//~Circe~ 11/26/07 for new Seneca
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
string COLOR, FABRIC, LENGTH;

void create_shirt(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   val = random(10)+1;
   val2 = random(6)+1;
   switch(val2){
      case 0..2: LENGTH = "short-sleeved";
                 break;
      default: LENGTH = "long-sleeved";
               break;
   }
   switch(val) {
      case 0..3: FABRIC = "cotton"; 
         obj->set_long("Made of soft cotton, this "+LENGTH+" shirt is dyed "+
            "a rich shade of "+COLOR+"%^RESET%^.  The shirt tail is long "+
            "enough to be tucked into pants or worn loose, and it features "+
            "a single row of matching "+COLOR+" buttons%^RESET%^.  A "+
            "wide spread collar completes the shirt, giving it a polished look.");
         break;
      case 4..8: FABRIC = "linen"; 
         obj->set_long("This loose-fitting shirt is made of "+COLOR+" linen "+
            "%^RESET%^and is "+LENGTH+".  The material is light and cool, and "+
            "is is clearly meant to be worn loose.  A wide-spread row of "+
            ""+COLOR+" buttons %^RESET%^runs down the front of the shirt, but "+
            "it is often left open.  A relaxed collar that always seems to "+
            "have a slightly rumpled look finishes this very comfortable shirt.");
         break;
      default:   FABRIC = "silk"; 
         obj->set_long("This long-sleeved shirt is made from "+COLOR+" "+
            "silk %^RESET%^that is unbelievably soft and smooth.  The "+
            "shirt has a fashionable collar and a single row of "+
            ""+COLOR+" buttons%^RESET%^.  Upon closer inspection, you "+
            "realize that the buttons are made to be removed so that "+
            "other buttons - sometimes even gemstones - can replace them.  "+
            "Likewise, the wide cuffs have been prepared for %^BOLD%^"+
            "cufflinks %^RESET%^to further customize the shirt.  "+
            "Altogether, this is an exquisite garment.");
         break;
   }
   obj->set_value((val+val2)*5);
   obj->set_name("shirt");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(3);
   obj->set_short("A "+LENGTH+" "+COLOR+" "+FABRIC+" shirt%^RESET%^");
   obj->set_id(({"shirt","clothing",""+COLOR+" shirt",""+FABRIC+" shirt",""+COLOR+" "+FABRIC+" shirt","regular shirt","esteban_clothing"}));
}
