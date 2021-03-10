//Random valuable items for Lurue's plot to open new Seneca
//Descriptions by Lurue, coded by ~Circe~ 7/25/08
#include <std.h>

#define TYPES ({"bowl","goblet","candle stick","platter","statuette","frame","figurine","vase","urn","wooden carving","bottle","mirror","cup","glass","chalice","snuff box","quill","perfume bottle","crystal carving"})

#define LUSTERS ({"%^BOLD%^%^BLACK%^s%^WHITE%^i%^RESET%^l%^BOLD%^%^WHITE%^v%^BLACK%^er%^RESET%^",\
"%^YELLOW%^g%^WHITE%^o%^RESET%^l%^YELLOW%^d%^RESET%^",\
"%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^%^BLACK%^l%^YELLOW%^d%^RESET%^%^ORANGE%^e%^YELLOW%^n%^RESET%^",\
"%^BOLD%^%^BLACK%^s%^RESET%^%^BLUE%^i%^BOLD%^%^WHITE%^l%^RESET%^v%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^y%^RESET%^",\
"%^BOLD%^%^BLUE%^b%^RESET%^%^BLUE%^l%^CYAN%^u%^BLUE%^i%^BOLD%^sh%^RESET%^",\
"%^RESET%^%^ORANGE%^a%^BOLD%^%^BLACK%^m%^YELLOW%^b%^RESET%^%^ORANGE%^er%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^MAGENTA%^p%^WHITE%^al%^RESET%^e%^BOLD%^%^WHITE%^sc%^MAGENTA%^e%^WHITE%^nt%^RESET%^",\
"%^RESET%^%^CYAN%^i%^BOLD%^r%^RESET%^%^CYAN%^id%^RESET%^e%^CYAN%^sc%^BOLD%^e%^RESET%^n%^CYAN%^t%^RESET%^"})

#define JEWELS ({"%^RESET%^%^RED%^g%^MAGENTA%^a%^BOLD%^%^BLACK%^r%^RESET%^%^RED%^n%^MAGENTA%^e%^RED%^t%^RESET%^",\
"%^BOLD%^%^MAGENTA%^a%^RESET%^%^MAGENTA%^m%^RESET%^e%^BOLD%^%^MAGENTA%^th%^RESET%^%^MAGENTA%^y%^RESET%^s%^BOLD%^%^MAGENTA%^t%^RESET%^",\
"%^BOLD%^%^CYAN%^a%^WHITE%^q%^RESET%^u%^BOLD%^%^WHITE%^a%^CYAN%^ma%^WHITE%^r%^RESET%^i%^BOLD%^%^CYAN%^ne%^RESET%^",\
"%^RESET%^%^GREEN%^b%^BOLD%^%^BLACK%^l%^RESET%^%^RED%^o%^GREEN%^ods%^BOLD%^%^BLACK%^t%^RESET%^%^RED%^o%^GREEN%^ne%^RESET%^",\
"%^BOLD%^%^CYAN%^d%^WHITE%^i%^RESET%^a%^BOLD%^%^CYAN%^m%^WHITE%^o%^RESET%^n%^BOLD%^%^CYAN%^d%^RESET%^",\
"%^BOLD%^%^GREEN%^emerald%^RESET%^",\
"%^BOLD%^%^BLACK%^pearl%^RESET%^",\
"%^BOLD%^%^WHITE%^m%^RESET%^%^CYAN%^o%^BOLD%^%^WHITE%^ons%^RESET%^%^CYAN%^t%^BOLD%^%^WHITE%^one%^RESET%^",\
"%^BOLD%^%^MAGENTA%^al%^RESET%^%^MAGENTA%^ex%^RED%^an%^CYAN%^dr%^BOLD%^%^BLUE%^it%^CYAN%^e%^RESET%^",\
"%^BOLD%^%^RED%^ruby%^RESET%^",\
"%^RESET%^%^GREEN%^p%^RESET%^e%^BOLD%^%^GREEN%^r%^RESET%^%^GREEN%^id%^RESET%^o%^GREEN%^t%^RESET%^",\
"%^BOLD%^%^CYAN%^sapphire%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^MAGENTA%^p%^WHITE%^a%^MAGENTA%^l%^RESET%^",\
"%^BOLD%^%^GREEN%^to%^RESET%^%^ORANGE%^ur%^RED%^ma%^MAGENTA%^li%^BOLD%^ne%^RESET%^",\
"%^RESET%^%^ORANGE%^t%^YELLOW%^o%^BLACK%^p%^RESET%^%^ORANGE%^az%^RESET%^",\
"%^RESET%^%^ORANGE%^citrine%^RESET%^",\
"%^BOLD%^%^CYAN%^t%^BLACK%^u%^RESET%^r%^BOLD%^%^CYAN%^qu%^BLACK%^o%^RESET%^i%^BOLD%^%^CYAN%^se%^RESET%^",\
"%^BOLD%^%^BLUE%^l%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^p%^BLUE%^is l%^RESET%^%^CYAN%^a%^BOLD%^%^BLACK%^z%^BLUE%^ul%^RESET%^%^CYAN%^i%^RESET%^",\
"%^BOLD%^%^BLUE%^blue zircon%^RESET%^"})

#define ETCHINGS ({"%^RESET%^%^GREEN%^twisting vines%^RESET%^",\
"%^BOLD%^%^RED%^budding roses%^RESET%^",\
"%^YELLOW%^flowering blooms%^RESET%^",\
"%^RESET%^%^ORANGE%^galloping horses%^RESET%^",\
"%^RESET%^%^GREEN%^stylized lizards%^RESET%^",\
"%^RESET%^%^CYAN%^leaping fish%^RESET%^",\
"%^BOLD%^%^BLACK%^dragons in flight%^RESET%^",\
"%^BOLD%^%^BLACK%^c%^RESET%^e%^BOLD%^%^WHITE%^l%^BLACK%^e%^WHITE%^sti%^RESET%^a%^BOLD%^%^BLACK%^l %^BOLD%^%^WHITE%^objects%^RESET%^",\
"%^YELLOW%^i%^RESET%^%^ORANGE%^n%^RED%^t%^YELLOW%^rica%^RESET%^%^ORANGE%^t%^RESET%^%^RED%^e%^YELLOW%^ly%^WHITE%^ arranged %^YELLOW%^f%^RESET%^%^ORANGE%^e%^RED%^a%^YELLOW%^th%^RESET%^%^ORANGE%^e%^YELLOW%^rs%^RESET%^",\
"%^BOLD%^%^BLACK%^coiling smoke%^RESET%^",\
"%^GREEN%^%^BOLD%^curling ivy%^RESET%^",\
"%^RED%^%^BOLD%^swirling flames%^RESET%^",\
"%^RESET%^%^ORANGE%^f%^GREEN%^a%^ORANGE%^ll%^RED%^i%^ORANGE%^ng l%^YELLOW%^e%^RESET%^%^ORANGE%^av%^RESET%^e%^ORANGE%^s%^RESET%^",\
"%^RESET%^%^GREEN%^t%^BOLD%^%^BLACK%^a%^RESET%^%^GREEN%^n%^RESET%^g%^ORANGE%^l%^GREEN%^ed t%^BOLD%^%^BLACK%^h%^RESET%^o%^ORANGE%^r%^GREEN%^ns%^RESET%^"})

inherit DAEMON;

string MYTYPE,LUSTER,JEWEL,ETCHING;

void create_valuables(object obj){
   MYTYPE = TYPES[random(sizeof(TYPES))];
   LUSTER = LUSTERS[random(sizeof(LUSTERS))];
   JEWEL = JEWELS[random(sizeof(JEWELS))];
   ETCHING = ETCHINGS[random(sizeof(ETCHINGS))];
   obj->set_name("a valuable object");
   obj->set_short("a valuable-looking "+MYTYPE+"");
   obj->set_id(({"object","item","valuable object","art object",""+MYTYPE+""}));
   obj->set_long("%^BOLD%^%^WHITE%^The value of this "+MYTYPE+" "+
      "is very high and you're certain if you didn't %^BLACK%^break"+
      "%^BOLD%^%^WHITE%^ it that it would fetch a high price.  You "+
      "can tell this by the brilliant "+LUSTER+" %^BOLD%^%^WHITE%^"+
      "luster which catches the light and flickers a prism back at "+
      "you.  Delicate, the "+JEWEL+" %^BOLD%^%^WHITE%^covered "+MYTYPE+" "+
      "is likely a collector's piece, meant for display on a "+
      "%^BLACK%^velvet %^WHITE%^covered shelf, rather then to be "+
      "carried about and used.  Fine etchings of "+ETCHING+" "+
      "%^BOLD%^%^WHITE%^decorate the surface between the "+JEWEL+" "+
      "%^BOLD%^%^WHITE%^settings and give the "+MYTYPE+" a distinct "+
      "artistic appearance.%^RESET%^");
   obj->set_value((roll_dice(1,5)*1000)+random(101));
   obj->set_weight(roll_dice(1,6)+3);
}