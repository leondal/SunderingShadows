#include <std.h>

#define COLORS ({"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^RESET%^%^GREEN%^olive green%^RESET%^",\
"%^RESET%^%^CYAN%^azure%^RESET%^",\
"%^RESET%^%^BLUE%^indigo%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald green%^RESET%^",\
"%^RESET%^%^MAGENTA%^amethyst%^RESET%^",\
"%^BOLD%^%^WHITE%^ivory%^RESET%^",\
"%^BOLD%^%^BLUE%^ocean blue%^RESET%^",\
"%^BOLD%^%^GREEN%^leaf green%^RESET%^",\
"%^RESET%^%^BLUE%^navy blue%^RESET%^",\
"%^BOLD%^%^CYAN%^sky blue%^RESET%^",\
"%^BOLD%^%^BLUE%^sapphire blue%^RESET%^",\
"%^BOLD%^%^BLACK%^gray-%^RESET%^%^GREEN%^green%^RESET%^",\
"%^BOLD%^%^BLACK%^ raven black%^RESET%^",\
"%^RESET%^%^ORANGE%^rich brown%^RESET%^",\
"%^RESET%^%^ORANGE%^dark brown%^RESET%^",\
"%^RESET%^%^RED%^brick red%^RESET%^",\
"%^BOLD%^%^RED%^ruby red%^RESET%^",\
"%^RESET%^%^MAGENTA%^royal purple%^RESET%^",\
"%^BOLD%^%^RED%^blood red%^RESET%^",\
"%^RESET%^%^MAGENTA%^violet%^RESET%^",\
"%^RESET%^%^ORANGE%^rusty orange%^RESET%^",\
"%^RESET%^%^ORANGE%^reddish orange%^RESET%^",\
"%^BOLD%^%^RED%^fiery red%^RESET%^",\
"%^BOLD%^%^CYAN%^cornflower blue%^RESET%^",\
"%^RESET%^%^MAGENTA%^lavander%^RESET%^",\
"%^BOLD%^%^MAGENTA%^carnation pink%^RESET%^",\
"%^BOLD%^%^BLACK%^charcoal gray%^RESET%^",\
"%^BOLD%^%^WHITE%^rich cream%^RESET%^",\
"%^YELLOW%^saphron%^RESET%^",\
"%^RESET%^%^ORANGE%^peach%^RESET%^",\
"%^YELLOW%^lemon yellow%^RESET%^",\
"%^BOLD%^%^MAGENTA%^brilliant pink%^RESET%^",\
"%^BOLD%^%^WHITE%^brilliant white%^RESET%^",\
"%^RESET%^light gray",\
"%^BOLD%^%^BLACK%^dark gray%^RESET%^",\
"%^BOLD%^%^BLACK%^stormy gray%^RESET%^",\
"%^RED%^crimson%^RESET%^",\
"%^YELLOW%^daffodil%^RESET%^",\
"%^RESET%^%^MAGENTA%^amethyst%^RESET%^",\
"%^RESET%^%^ORANGE%^beige%^RESET%^",\
"%^RESET%^%^ORANGE%^fawn%^RESET%^"\
})

inherit DAEMON;

int j, val;
string str, FABRIC, VAR;

void create()
{
   ::create();
}

void create_cloak(object obj)
{
   j = random(sizeof(COLORS));
   str = COLORS[j];
   VAR = "a";
   if(str == "amethyst" || str == "emerald" || str == "aquamarine" || str == "indigo" || str == "olive green" || str == "ivory" || str == "azure" || str == "ocean blue") {
      VAR = "an";
   }
   val = random(25);
   switch(val) {
      case 0..5:
         FABRIC = "burlap";
         obj->set_long("This burlap cloak is perhaps the ugliest cloak that"+
         " you've ever seen. It has been dyed "+VAR+" "+str+" color in a"+
         " desperate attempt to make it look better. It has been treated"+
         " to help keep the water off it, and it will protect you well from"+
         " the wind.");
         break;
      case 6..10:
         FABRIC = "leather";
         obj->set_long("This is a leather cloak that has been waterproofed in"+
         " order to keep you safe from the rain. It has been dyed "+VAR+""+
         " "+str+" color and is quite practical for rainy or snowy climates.");
         break;
      case 11..15:
         FABRIC = "suede";
         obj->set_long("This suede cloak has been treated to keep the water"+
         " from ruining it, but it is obviously more for fashion than"+
         " practicality, as it would be quickly ruined if subjected to the"+
         " elements too long. It has been dyed "+VAR+" "+str+" shade.");
         break;
      case 16..20:
         FABRIC = "velvet";
         obj->set_long("This velvet cloak is perhaps one of the most"+
         " unpractical things you've come across. It is rather pretty and"+
         " has been dyed "+VAR+" "+str+" shade, but wouldn't protect anyone"+
         " from the wind or rain.");
         break;
      case 21..25:
         FABRIC = "silk";
         obj->set_long("This silk cloak is absolutely lovely. It has been"+
         " dyed "+VAR+" "+str+" shade. It wouldn't help if you were outdoors"+
         " in any weather, except to make you look good if it happened to be"+
         " nice and sunny. It has been cut in the latest of fashions and is"+
         " something that nobility might wear.");
         break;
   }
   if(val < 3) {
      obj->set_value(3);
   }
   else {
      obj->set_value(val);
   }
   obj->set_name("cloak");
   obj->set_type("clothing");
   obj->set_limbs(({"neck"}));
   obj->set_weight(5);
   obj->set_short(capitalize(VAR)+" "+str+" "+FABRIC+" cloak");
   obj->set_id(({"cloak","clothing",""+str+" cloak",""+FABRIC+" cloak",""+str+" "+FABRIC+" cloak"}));
}
