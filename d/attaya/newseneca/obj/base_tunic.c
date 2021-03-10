#include <std.h>

#define COLORS ({"%^BOLD%^%^CYAN%^aquamarine",\
"%^GREEN%^olive green",\
"%^BOLD%^%^CYAN%^azure",\
"%^BLUE%^indigo",\
"%^BOLD%^%^GREEN%^emerald green",\
"%^MAGENTA%^amethyst",\
"%^BOLD%^%^WHITE%^ivory",\
"%^BOLD%^%^BLUE%^ocean blue",\
"%^BOLD%^%^GREEN%^leaf green",\
"%^GREEN%^pine green",\
"%^BOLD%^%^BLUE%^cobalt blue",\
"%^BLUE%^navy blue",\
"%^GREEN%^forest green",\
"%^BOLD%^%^CYAN%^sky blue",\
"%^BOLD%^%^BLUE%^sapphire blue",\
"%^CYAN%^blue-green",\
"%^GREEN%^gray-green",\
"%^BOLD%^%^BLACK%^black",\
"%^ORANGE%^rich brown",\
"%^ORANGE%^dark brown",\
"%^ORANGE%^walnut brown",\
"%^RED%^brick red",\
"%^ORANGE%^peach",\
"%^BOLD%^%^GREEN%^lime green",\
"%^BOLD%^%^RED%^ruby red",\
"%^MAGENTA%^royal purple",\
"%^RED%^blood red",\
"%^MAGENTA%^violet",\
"%^ORANGE%^rusty orange",\
"%^BOLD%^%^RED%^rusty red",\
"%^BOLD%^%^RED%^reddish orange",\
"%^BOLD%^%^RED%^fiery red",\
"%^BOLD%^%^BLUE%^cornflower blue",\
"%^MAGENTA%^lavender",\
"%^BOLD%^%^MAGENTA%^carnation pink",\
"%^ORANGE%^light brown",\
"%^CYAN%^turquoise",\
"%^BOLD%^%^BLACK%^charcoal gray",\
"%^CYAN%^cyan blue",\
"%^BOLD%^%^WHITE%^rich cream",\
"%^BOLD%^%^WHITE%^cream",\
"%^BOLD%^%^WHITE%^white",\
"%^YELLOW%^saphron",\
"%^YELLOW%^lemon yellow",\
"%^ORANGE%^tangerine",\
"%^BOLD%^%^MAGENTA%^mauve",\
"%^RED%^crimson",\
"%^BOLD%^%^MAGENTA%^lilac",\
"%^YELLOW%^daffodil",\
"%^ORANGE%^beige",\
"%^ORANGE%^taupe",\
"%^BOLD%^%^BLACK%^sable",\
"%^ORANGE%^fawn",\
"%^BOLD%^%^BLACK%^pale gray",\
"%^BOLD%^%^BLACK%^stormy gray",\
"%^ORANGE%^dusty brown",\
"%^BOLD%^%^BLACK%^dark gray"\
})

inherit DAEMON;

int j, val;
string str, FABRIC;

void create_tunic(object obj){
   j = random(sizeof(COLORS));
   str = COLORS[j];
   val = (15+random(21));
   switch(val) {
      case 15..25:
         FABRIC = "cotton";
         obj->set_long("This "+str+" tunic%^RESET%^ is made of soft cotton that "+
            "retains its shape with matching "+str+" piping%^RESET%^ along the "+
            "edges.  The tunic is made to slip over the head and is "+
            "sleeveless to allow for any armor or other items the "+
            "wearer may need.  The neckline is cut into a simple "+
            "V that may be either left open or tied closed with a %^ORANGE%^leather "+
            "drawstring.%^RESET%^");
         break;
      case 26..30:
         FABRIC = "woolen";
         obj->set_long("This woolen tunic has been dyed a fetching "+
            "shade of "+str+"%^RESET%^.  The tunic is clearly meant to be "+
            "worn in cooler climates, as it features long sleeves, and "+
            "the bottom reaches to mid-thigh.  The tunic comes with a "+
            "fashionable leather belt with a %^ORANGE%^buckle%^RESET%^ that may be "+
            "fastened over the tunic around the waist.");
         break;
      case 31..33:
         FABRIC = "suede";
         obj->set_long("A simple, sleeveless tunic, this garment is "+
            "dressed up by the highest quality suede dyed "+str+"%^RESET%^.  "+
            "The rounded neckline has no collar but is instead decorated "+
            "with zigzag embroidery in slightly off-color "+str+"%^RESET%^.  The "+
            "coloring ensures that it catches the eye while making the "+
            "tunic seem well-made.");
         break;
      default:
         FABRIC = "silk";
         obj->set_long("The luxurious silk of this tunic has been dyed "+
           ""+str+"%^RESET%^.  Long-sleeved, this tunic features delicate "+
           "embroidery in swirling patterns all over its surface.  "+
           "The embroidery is done in matching "+str+" thread%^RESET%^, so as to "+
           "add subtle elegance to this beautiful piece.  The tunic "+
           "features a well-made, short collar that stands up just "+
           "around the wearer's neck.  Some choose to wear such a tunic "+
           "belted, while others let it flow freely.  Either way, it is "+
           "considered the height of fashion in many human lands.");
         break;
   }
   obj->set_value(val+1);
   obj->set_name("tunic");
   obj->set_type("clothing");
   obj->set_limbs(({"torso"}));
   obj->set_weight(3);
   obj->set_short("%^RESET%^"+str+" "+FABRIC+" tunic%^RESET%^");
   obj->set_id(({"clothing","tunic",""+FABRIC+" tunic","shirt",""+str+" tunic","Tunic","well-made tunic"}));
}
