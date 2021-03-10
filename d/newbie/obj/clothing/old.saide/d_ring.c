#include <std.h>

#define STONES ({"%^MAGENTA%^amethyst%^RESET%^",\
"%^BOLD%^%^WHITE%^ivory%^RESET%^",\
"%^BOLD%^%^BLACK%^ebony%^RESET%^",\
"%^GREEN%^agate%^RESET%^",\
"%^BOLD%^%^CYAN%^aquamarine%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx%^RESET%^",\
"%^ORANGE%^amber%^RESET%^",\
"%^BOLD%^%^GREEN%^jade%^RESET%^",\
"%^BOLD%^%^WHITE%^crystal quartz%^RESET%^",\
"%^BOLD%^%^MAGENTA%^rose quartz%^RESET%^",\
"%^BOLD%^%^BLACK%^smokey quartz%^RESET%^",\
"%^ORANGE%^tigers eye%^RESET%^",\
"%^RED%^fire agate%^RESET%^",\
"%^BOLD%^%^WHITE%^moonstone%^RESET%^",\
"%^GREEN%^bloodstone%^RESET%^",\
"%^MAGENTA%^jasper%^RESET%^",\
"%^BOLD%^%^RED%^carnelian%^RESET%^",\
"%^YELLOW%^citrine%^RESET%^",\
"%^BLUE%^lapis lazuli%^RESET%^",\
"%^CYAN%^beryl%^RESET%^",\
"%^ORANGE%^topaz%^RESET%^",\
"%^CYAN%^malachite%^RESET%^",\
"%^BOLD%^%^BLUE%^blue spinel%^RESET%^",\
"%^RED%^red spinel%^RESET%^",\
"%^BOLD%^%^RED%^red jasper%^RESET%^",\
"%^GREEN%^moss agate%^RESET%^",\
"%^BOLD%^%^GREEN%^peridot%^RESET%^",\
"%^RED%^garnet%^RESET%^",\
"%^BOLD%^%^BLACK%^hematite%^RESET%^"})

      
inherit DAEMON;

int i, j, val;
string STONE, METAL;

void create_ring(object obj)
{
   j = random(sizeof(STONES));
   STONE = STONES[j];
   val = random(25)+5;
   switch(val) {
      case 5..7:
         METAL = "%^ORANGE%^brass%^RESET%^";
         break;
      case 8..11:
         METAL = "%^YELLOW%^bronze%^RESET%^";
         break;
      case 12..16:
         METAL = "%^BOLD%^%^WHITE%^silver%^RESET%^";
         break;
      case 17..21:
         METAL = "%^BOLD%^%^CYAN%^mithril%^RESET%^";
         break;
      case 22..25:
         METAL = "%^YELLOW%^gold%^RESET%^";
         break;
      case 26..27:
         METAL = "%^BOLD%^%^MAGENTA%^rose gold%^RESET%^";
         break;
      case 28..29:
         METAL = "%^BOLD%^%^WHITE%^white gold%^RESET%^";
         break;
   }
   obj->set_value(val+1);
   obj->set_cointype("silver");
   obj->set_type("ring");
   obj->set_limbs(({"right hand"}));
   obj->set_weight(1);
   obj->set_name("ring");
   obj->set_id(({"ring",""+STONE+" ring",""+METAL+" ring",""+STONE+" "+METAL+" ring",""+METAL+" "+STONE+" ring"}));
   obj->set_short("%^RESET%^"+STONE+" ring%^RESET%^");
   obj->set_long("The ring consists of a "+METAL+" band that has a"+
   " cut and polished "+STONE+" set in the very center. It is a"+
   " pretty little trinket.");
}
