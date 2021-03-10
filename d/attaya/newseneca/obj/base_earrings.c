#include <std.h>

#define COLORS ({"sea-green","azure","violet","salmon","ivory","goldenrod","ebony","smoky gray","rich brown","lilac","cream"})

#define SHELLS ({"conch shell","cowry shell","scallop shell","clamshell"})

#define CRITTERS ({"%^BOLD%^%^BLACK%^shark tooth","%^ORANGE%^starfish","%^BOLD%^sand dollar"})

#define STONES ({"%^RESET%^%^MAGENTA%^amethyst",\
"%^BOLD%^%^WHITE%^ivory",\
"%^BOLD%^%^BLACK%^ebony",\
"%^RESET%^%^GREEN%^agate",\
"%^BOLD%^%^CYAN%^aquamarine",\
"%^BOLD%^%^BLACK%^onyx",\
"%^RESET%^%^ORANGE%^amber",\
"%^BOLD%^%^GREEN%^jade",\
"%^BOLD%^%^WHITE%^crystal quartz",\
"%^BOLD%^%^MAGENTA%^rose quartz",\
"%^BOLD%^%^BLACK%^smokey quartz",\
"%^RESET%^%^ORANGE%^tigers eye",\
"%^BOLD%^%^RED%^fire agate",\
"%^BOLD%^%^WHITE%^moonstone",\
"%^BOLD%^%^GREEN%^blo%^RED%^o%^GREEN%^dst%^RED%^o%^GREEN%^ne",\
"%^GREEN%^jasper",\
"%^RESET%^%^RED%^carnelian",\
"%^YELLOW%^citrine",\
"%^RESET%^%^BLUE%^lapis lazuli",\
"%^RESET%^%^GREEN%^beryl",\
"%^RESET%^%^ORANGE%^topaz",\
"%^RESET%^%^GREEN%^malachite",\
"%^BOLD%^%^BLUE%^blue spinel",\
"%^BOLD%^%^WHITE%^o%^CYAN%^p%^MAGENTA%^a%^WHITE%^l",\
"%^BOLD%^%^BLACK%^bl%^GREEN%^a%^BLACK%^ck op%^GREEN%^a%^BLACK%^l",\
"%^BOLD%^%^CYAN%^water opal",\
"%^BOLD%^%^RED%^flamedance",\
"%^RESET%^%^RED%^garnet",\
"%^BOLD%^%^BLACK%^hematite"})

inherit DAEMON;

int val;
string COLOR, mycolor, METAL, metal, SHELL, CRITTER, STONE;

void create(){
   ::create();
}

void create_earrings(object obj){
   COLOR = COLORS[random(sizeof(COLORS))];
   SHELL = SHELLS[random(sizeof(SHELLS))];
   CRITTER = CRITTERS[random(sizeof(CRITTERS))];
   STONE = STONES[random(sizeof(STONES))];
   switch(COLOR){
      case "sea-green" : mycolor = "%^GREEN%^s%^CYAN%^e%^GREEN%^a"+
         "%^CYAN%^-%^GREEN%^g%^CYAN%^r%^GREEN%^e%^CYAN%^e%^GREEN%^n";
         break;
      case "azure" : mycolor = "%^CYAN%^a%^BOLD%^z%^RESET%^%^CYAN%^u"+
         "%^BOLD%^r%^RESET%^%^CYAN%^e";
         break;
      case "violet" : mycolor = "%^MAGENTA%^violet";
         break;
      case "salmon" : mycolor = "%^BOLD%^%^MAGENTA%^salmon";
         break;
      case "ivory" : mycolor = "%^BOLD%^ivory";
         break;
      case "goldenrod" : mycolor = "%^YELLOW%^goldenrod";
         break;
      case "ebony" : mycolor = "%^BOLD%^%^BLACK%^ebony";
         break;
      case "smoky gray" : mycolor = "%^BOLD%^%^BLACK%^smo%^RESET%^k"+
         "%^BOLD%^%^BLACK%^y gray";
         break;
      case "rich brown" : mycolor = "%^ORANGE%^rich brown";
         break;
      case "lilac" : mycolor = "%^BOLD%^%^MAGENTA%^lilac";
         break;
      case "cream" : mycolor = "%^BOLD%^cr%^YELLOW%^e%^WHITE%^am";
         break;
      default: mycolor = "%^B_BLUE%^%^BOLD%^%^GREEN%^Ack, something's wrong!%^RESET%^";
         break;
   }
   val = random(26);
   switch(val) {
      case 0..3:
         METAL = "%^RESET%^%^ORANGE%^brass";
         metal = "brass";
         break;
      case 4..6:
         METAL = "%^YELLOW%^bronze";
         metal = "bronze";
         break;
      case 7..10:
         METAL = "%^BOLD%^%^WHITE%^silver";
         metal = "silver";
         break;
      case 11..14:
         METAL = "%^BOLD%^%^CYAN%^mithril";
         metal = "mithril";
         break;
      case 15..20:
         METAL = "%^YELLOW%^gold";
         metal = "gold";
         break;
      case 21..22:
         METAL = "%^BOLD%^%^MAGENTA%^rose gold";
         metal = "rose gold";
         break;
      case 23..25:
         METAL = "%^BOLD%^%^WHITE%^pla%^CYAN%^t%^WHITE%^in%^CYAN%^u%^WHITE%^m";
         metal = "platinum";
         break;
   }
   obj->set_value(val+125);
   obj->set_type("ring");
   obj->set_limbs(({"head"}));
   obj->set_weight(1);
   obj->set_name("earrings");
   switch(random(12)) {
      case 0..2:
         obj->set_short("a pair of "+mycolor+" "+SHELL+" %^RESET%^earrings");
         obj->set_id(({"earrings","pair of earrings",""+metal+" "+SHELL+" earrings",""+metal+" earrings",""+SHELL+" earrings","pair of "+metal+" "+SHELL+" earrings","pair of "+SHELL+" earrings","pair of "+metal+" earrings","hook earrings"}));
         obj->set_long("This delicate pair of earrings features finely "+
            "matched "+mycolor+" "+SHELL+"s %^RESET%^that dangle from a slender "+
            ""+METAL+" rod%^RESET%^.  The edges of the "+SHELL+"s have "+
            "been lightly brushed with "+METAL+"%^RESET%^, giving them a "+
            "faint %^BOLD%^s%^RESET%^h%^BOLD%^i%^RESET%^m%^BOLD%^m%^RESET%^e"+
            "%^BOLD%^r%^RESET%^.  Slender "+METAL+" hooks %^RESET%^are "+
            "designed to be place through holes in your ears, giving "+
            "center stage to the pretty "+mycolor+" shells%^RESET%^.");
         obj->set_wear("You slip the "+METAL+" hooks through your ears.");
         obj->set_remove("You slip the "+mycolor+" "+SHELL+" %^RESET%^"+
            "earrings out of your ears.");
         break;
      case 3..4:
         obj->set_short("a single "+mycolor+" "+SHELL+" %^RESET%^earring");
         obj->set_id(({"earring",""+metal+" "+SHELL+" earring",""+metal+" earring",""+SHELL+" earring","hook earring"}));
         obj->set_long("This single earring is created from a lone "+
            ""+mycolor+" "+SHELL+" %^RESET%^that dangles from a slender "+
            ""+METAL+" rod%^RESET%^.  The edges of the "+SHELL+" has "+
            "been lightly brushed with "+METAL+"%^RESET%^, giving it a "+
            "faint %^BOLD%^s%^RESET%^h%^BOLD%^i%^RESET%^m%^BOLD%^m%^RESET%^e"+
            "%^BOLD%^r%^RESET%^.  A slender "+METAL+" hook %^RESET%^is "+
            "designed to be place through a hole in your ear, putting "+
            "the "+mycolor+" shell%^RESET%^ on display.");
         obj->set_wear("You slip the "+METAL+" hook through your ear.");
         obj->set_remove("You slip the "+mycolor+" "+SHELL+" %^RESET%^"+
            "earring out of your ear.");
         break;
      case 5..7:
         obj->set_short("a pair of "+CRITTER+" %^RESET%^earrings");
         obj->set_id(({"earrings","pair of earrings",""+metal+" "+CRITTER+" earrings",""+metal+" earrings",""+CRITTER+" earrings","pair of "+metal+" "+CRITTER+" earrings","pair of "+CRITTER+" earrings","pair of "+metal+" earrings","hook earrings"}));
         obj->set_long("This simple pair of earrings is crafted of "+METAL+" "+
            "hooks%^RESET%^, each designed to slip through a hole in "+
            "your ear.  Dangling from each hook without further ornamentation "+
            "is a natural "+CRITTER+"%^RESET%^, bringing to mind "+
            "images of the %^CYAN%^pure sea%^RESET%^.");
         obj->set_wear("You slip the "+METAL+" hooks through your ears.");
         obj->set_remove("You slip the "+CRITTER+" %^RESET%^"+
            "earrings out of your ears.");
         break;
      case 8:
         obj->set_short("a pair of "+mycolor+" cowry shell %^RESET%^earrings");
         obj->set_id(({"earrings","pair of earrings",""+metal+" cowry shell earrings",""+metal+" earrings","cowry shell earrings","pair of "+metal+" cowry shell earrings","pair of cowry shell earrings","pair of "+metal+" earrings","hook earrings"}));
         obj->set_long("Three "+mycolor+" cowry shells %^RESET%^"+
            "feature prominently in each of these unconventional earrings.  "+
            "The "+mycolor+" shells %^RESET%^have been gathered at "+
            "the points, forming an inverted fleur-de-lis that dangles "+
            "prettily from a "+METAL+" hook %^RESET%^that can be "+
            "inserted through a hole in the ear.");
         obj->set_wear("You slip the "+METAL+" hooks through your ears.");
         obj->set_remove("You slip the "+mycolor+" cowry shell %^RESET%^"+
            "earrings out of your ears.");
         break;
      case 9..10:
         obj->set_short("a single "+CRITTER+" %^RESET%^earring");
         obj->set_id(({"earring",""+metal+" "+CRITTER+" earring",""+metal+" earring",""+CRITTER+" earring","hook earring"}));
         obj->set_long("This simple pair earring is crafted of a "+METAL+" "+
            "hook%^RESET%^ designed to slip through a hole in "+
            "your ear.  Dangling from the hook without further ornamentation "+
            "is a natural "+CRITTER+"%^RESET%^, bringing to mind "+
            "images of the %^CYAN%^pure sea%^RESET%^.");
         obj->set_wear("You slip the "+METAL+" hook through your ear.");
         obj->set_remove("You slip the "+CRITTER+" %^RESET%^"+
            "earring out of your ear.");
         break;
      default:
         obj->set_short("a pair of "+STONE+" %^RESET%^and "+mycolor+" shell %^RESET%^earrings");
         obj->set_id(({"earrings","pair of earrings",""+metal+" shell earrings",""+metal+" earrings",""+STONE+" earrings","pair of "+metal+" "+STONE+" earrings","pair of "+STONE+" earrings","pair of "+metal+" earrings","hook earrings"}));
         obj->set_long("These earrings dangle about an inch and a half, "+
            "constructed in a most interesting way.  Small disks of "+
            ""+mycolor+" puka shell %^RESET%^are stacked between "+
            "similar disks of "+STONE+"%^RESET%^.  The disks "+
            "narrow as they climb up a hook of "+METAL+"%^RESET%^.  Each hook "+
            "is slender, designed to slip through a hole in your ear.");
         obj->set_wear("You slip the "+METAL+" hooks through your ears.");
         obj->set_remove("You slip the "+STONE+" %^RESET%^"+
            "earrings out of your ears.");
         break;
   }
}
