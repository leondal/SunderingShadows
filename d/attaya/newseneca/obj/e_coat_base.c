//Random coats for Esteban's shop
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

int val;
string COLOR,ACCENT,TYPE;

//long vest, jerkin, doublet, greatcoat
void create_coat(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   if(COLOR == "%^BOLD%^%^BLACK%^black"){
      ACCENT = "%^BOLD%^%^WHITE%^white"; 
   }else{
      ACCENT = "%^BOLD%^%^BLACK%^black";
   }
   val = random(10)+1;
   switch(val) {
      case 0..3: TYPE = "long vest"; 
         obj->set_long("Meticulously tailored from "+COLOR+" brocade"+
            "%^RESET%^, this %^BOLD%^long vest %^RESET%^is perfect to "+
            "wear atop another shirt or tunic as well as beneath another "+
            "garment.  It has a rounded neckline that fits snug around "+
            "the neck and has been lightly embroidered with cross-hatching "+
            "in "+COLOR+" thread%^RESET%^.  Likewise, each button in the row "+
            "running all the way from the neck to the bottom of the garment "+
            "has been covered with matching brocade.  Twin narrow pockets "+
            "with triangular flaps are placed right at the waistline to "+
            "either side of the buttons, while the garment itself ends at "+
            "about mid-thigh.  The finishing touch to this long vest is "+
            "a discreet "+COLOR+" tie %^RESET%^in the back that blends in "+
            "with the fabric of the vest and allows for minor adjustments "+
            "for a better fit.");
         break;
      case 4..6: TYPE = "jerkin"; 
         obj->set_long("This tailored garment features contrasting colors, with "+
            "the central portion cut from "+COLOR+" velvet%^RESET%^.  "+
            "It forms a V-shaped panel that fastens down the middle with "+
            "a cleverly hidden hook-and-eye closure.  The wide panel is "+
            "bordered on both sides with "+ACCENT+" fabric %^RESET%^accented "+
            "with %^YELLOW%^gold embroidered ribbon %^RESET%^around the edges.  "+
            "The jerkin has short sleeves that end just at the shoulders and a "+
            "stiff "+COLOR+" collar %^RESET%^rising only an inch or two "+
            "along the neck.  The back of the jerkin is crafted entirely from "+
            ""+ACCENT+" material %^RESET%^with the %^YELLOW%^gold embroidered "+
            "ribbon %^RESET%^serving as edging along the bottom and around "+
            "the neck.  The garment ends just at the natural waist and is "+
            "typically worn over another slender shirt.");
         break;
      case 7..8:   TYPE = "doublet"; 
         obj->set_long("Beautifully crafted from thick "+COLOR+" brocade"+
            "%^RESET%^, this handsome doublet fits snugly and seems to "+
            "accent the wearer's physique - for the good or not.  "+
            "Wide shoulders aided by cap sleeves can help create the "+
            "illusion of bulk as the garment tapers down to a trim waist "+
            "before flaring out in a band over the hips.  "+
            "Hidden beneath the cap sleeves are ties with which the longer, "+
            "billowing sleeves are attached, allowing them to be removed "+
            "for comfort during warm weather.  The sleeves are cinched "+
            "around the wrist with narrow bands, allowing the extra fabric "+
            "to fall in graceful folds rather than getting in the wearer's "+ 
            "way.  The front of the doublet closes with a wide double row "+
            "of "+COLOR+" buttons %^RESET%^and matching laces that allow "+
            "for minute adjustments in the fit of the garment.");
         break;
      default:  TYPE = "greatcoat";
         obj->set_long("Truly an overcoat, this greatcoat is made from "+
            "many folds of soft "+COLOR+" wool %^RESET%^and is designed "+
            "to be worn over several layers of clothes.  The coat has a "+
            "wide collar that may be turned up to protect the wearer's "+
            "face against inclement weather, and a double cape across the "+
            "shoulders for added warmth.  The sleeves of the coat have "+
            "cuffs that are folded back and fastened with %^BOLD%^horn "+
            "buttons%^RESET%^, ready to be let down should the wearer's "+
            "hands be cold.  Two large, deep pockets with buttoned flaps "+
            "grace the front of the coat, adding not only decoration "+
            "but also functionality.  The finishing touch of this coat "+
            "is a row of large buttons made from %^BOLD%^horn%^RESET%^ "+
            "and a matching "+COLOR+" linen lining%^RESET%^.");
         break;
   }
   obj->set_value(val*20);
   obj->set_name("coat");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(6);
   obj->set_short("a well-tailored "+COLOR+" "+TYPE+"%^RESET%^");
   obj->set_id(({"coat","clothing",""+COLOR+" "+TYPE+"",""+TYPE+"",""+COLOR+" "+TYPE+" coat","regular coat","esteban_clothing"}));
}
