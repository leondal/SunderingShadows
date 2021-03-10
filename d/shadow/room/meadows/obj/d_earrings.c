#include <std.h>

#define STONES ({"%^RESET%^%^MAGENTA%^amethyst%^RESET%^",\
"%^BOLD%^%^WHITE%^ivory%^RESET%^",\
"%^BOLD%^%^BLACK%^ebony%^RESET%^",\
"%^RESET%^%^GREEN%^agate%^RESET%^",\
"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx%^RESET%^",\
"%^RESET%^%^ORANGE%^amber%^RESET%^",\
"%^BOLD%^%^GREEN%^jade%^RESET%^",\
"%^BOLD%^%^WHITE%^crystal quartz%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose quartz%^RESET%^",\
"%^BOLD%^%^BLACK%^smokey quartz%^RESET%^",\
"%^RESET%^%^ORANGE%^tigers eye%^RESET%^",\
"%^BOLD%^%^RED%^fire agate%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^BOLD%^%^GREEN%^blo%^RED%^o%^GREEN%^dst%^RED%^o%^GREEN%^ne%^RESET%^",\
"%^GREEN%^jasper%^RESET%^",\
"%^RESET%^%^RED%^carnelian%^RESET%^",\
"%^YELLOW%^citrine%^RESET%^",\
"%^RESET%^%^BLUE%^lapis lazuli%^RESET%^",\
"%^RESET%^%^GREEN%^beryl%^RESET%^",\
"%^RESET%^%^ORANGE%^topaz%^RESET%^",\
"%^RESET%^%^GREEN%^malachite%^RESET%^",\
"%^BOLD%^%^BLUE%^blue spinel%^RESET%^",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l%^RESET%^",\
"%^BOLD%^%^BLACK%^bl%^GREEN%^a%^BLACK%^ck op%^GREEN%^a%^BLACK%^l%^RESET%^",\
"%^BOLD%^%^CYAN%^water opal%^RESET%^",\
"%^BOLD%^%^RED%^flamedance%^RESET%^",\
"%^RESET%^%^RED%^garnet%^RESET%^",\
"%^BOLD%^%^BLACK%^hematite%^RESET%^"})

inherit DAEMON;

int i, j, val;
string str, METAL;

void create()
{
   ::create();
}

void create_earrings(object obj)
{
   j = random(sizeof(STONES));
   str = STONES[j];
   val = random(20)+5;
   switch(val) {
      case 0..3:
         METAL = "%^RESET%^%^ORANGE%^brass%^RESET%^";
         break;
      case 4..6:
         METAL = "%^YELLOW%^bronze%^RESET%^";
         break;
      case 7..10:
         METAL = "%^BOLD%^%^WHITE%^silver%^RESET%^";
         break;
      case 11..14:
         METAL = "%^BOLD%^%^CYAN%^mithril%^RESET%^";
         break;
      case 15..20:
         METAL = "%^YELLOW%^gold%^RESET%^";
         break;
      case 21..22:
         METAL = "%^BOLD%^%^MAGENTA%^rose gold%^RESET%^";
         break;
      case 23..25:
         METAL = "%^BOLD%^%^WHITE%^white gold%^RESET%^";
         break;
   }
   obj->set_value(val+1);
   obj->set_type("ring");
   obj->set_limbs(({"head"}));
   obj->set_weight(1);
   obj->set_name("earrings");
   switch(random(6)) {
      case 0:
         obj->set_short("A pair of "+str+" earrings");
         obj->set_id(({"earrings","r_earrings","pair of earrings",""+METAL+" "+str+" earrings",""+METAL+" earrings",""+str+" earrings","pair of "+METAL+" "+str+" earrings","pair of "+str+" earrings","pair of "+METAL+" earrings","hook earrings"}));
         obj->set_long("This is a delicate pair of "+METAL+" earrings that"+
         " have a string of several polished "+str+" beads hanging down."+
         " Each earring has a slender hook that slips through a hole in"+
         " your ear, letting the "+str+" beads dangle down.");
         obj->set_wear("You slip the "+METAL+" hooks through your ears.");
         obj->set_remove("You slip the "+METAL+" "+str+" earrings out of your ears.");
         break;
      case 1:
         obj->set_short("A pair of "+str+" earrings");
         obj->set_id(({"earrings","r_earrings","pair of earrings",""+METAL+" "+str+" earrings",""+METAL+" earrings",""+str+" earrings","pair of "+METAL+" "+str+" earrings","pair of "+str+" earrings","pair of "+METAL+" earrings","stud earrings"}));
         obj->set_long("These earrings consist of "+METAL+" studs that have"+
         " a polished piece of "+str+" set in the center of each earring."+
         " There are backings to the studs that are put in place behind your"+
         " ears to keep the earrings on.");
         obj->set_wear("You carefully fasten the studs in place.");
         obj->set_remove("You take the backings off and remove the "+METAL+" "+str+" earrings.");
         break;
      case 2:
         obj->set_short("A single "+METAL+" earring");
         obj->set_id(({"earring","r_earrings","single earring",""+METAL+" "+str+" earring",""+METAL+" earring",""+str+" earring","single "+METAL+" "+str+" earring","single "+str+" earring","single "+METAL+" earring","hook earring"}));
         obj->set_long("This is a single "+METAL+" earring that has a slender"+
         " bent hook that is placed through a hole in your ear. There are"+
         " several polished "+str+" beads that dangle down from the top.");
         obj->set_wear("You slip the "+METAL+" hook through your ear.");
         obj->set_remove("You slip the "+METAL+" "+str+" earring out of your ear.");
         break;
      case 3:
         obj->set_short("A single "+METAL+" stud");
         obj->set_id(({"earring","r_earrings","single earring",""+METAL+" "+str+" earring",""+METAL+" earring",""+str+" earring","single "+METAL+" "+str+" earring","single "+str+" earring","single "+METAL+" earring","stud earring","stud"}));
         obj->set_long("This is a single "+METAL+" stud earring with a"+
         " backing that will keep the earring in place. In the center is a"+
         " large piece of polished "+str+".");
         obj->set_wear("You fasten the "+METAL+" backing behind your ear.");
         obj->set_remove("You unfasten and remove the "+METAL+" "+str+" earring.");
         break;
      case 4:
         obj->set_short("A single "+METAL+" earring");
         obj->set_id(({"earring","r_earrings","single earring",""+METAL+" "+str+" earring",""+METAL+" earring",""+str+" earring","single "+METAL+" "+str+" earring","single "+str+" earring","single "+METAL+" earring","clip on earring","clipon earring","clip-on earring"}));
         obj->set_long("This is a single "+METAL+" earring that clips onto"+
         " the ear instead of having to be placed through a hole. The back"+
         " screws on tightly to keep it in place. There is a polished"+
         " piece of "+str+" in the center.");
         obj->set_wear("You screw the earring into place, it pinches a bit.");
         obj->set_remove("You unscrew the back and feel the blood flow back into your ear.");
         break;
      case 5:
         obj->set_short("A pair of "+str+" earrings");
         obj->set_id(({"earrings","r_earrings","pair of earrings",""+METAL+" "+str+" earrings",""+METAL+" earrings",""+str+" earrings","pair of "+METAL+" "+str+" earrings","pair of "+str+" earrings","pair of "+METAL+" earrings","clip on earrings","clipon earrings","clip-on earrings"}));
         obj->set_long("These "+METAL+" earrings actually clip onto your"+
         " ears and the back screws together to pinch your ears between the"+
         " two sides. You can wear these earrings without having to have"+
         " your ears pierced. There is a polished piece of "+str+" in the"+
         " center of each earring.");
         obj->set_wear("You screw the earrings into place, feeling them pinch.");
         obj->set_remove("You unscrew the earrings and feel the blood flow back into your ears.");
         break;
   }
}
