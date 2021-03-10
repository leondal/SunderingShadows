//all types of gems for the common file
//with the way it is set up, you should be able to add other types 
//with no problems.  Try to set a GEM value for it to make it 
//colorful, but it is not necessary.  NOTE: increasing the number 
//of gems will increase the value of all the ones after it because
//of the way value is calculated.
//Circe 12/30/04
#include <std.h>

#define NAMES ({"jasper","turquoise","azurite","black quartz","white quartz","citrine","hematite","amethyst","green tourmaline","aquamarine","beryl","orange agate","topaz","moonstone","garnet","snowflake obsidian","onyx","emerald","ruby","sapphire","diamond","blue diamond"})

inherit OBJECT;

void create(){
   int j, val;
   string str, GEM, *strs;
   ::create();
   j = random(sizeof(NAMES));
   val = ((j+1)*10)+random(25);
   str = NAMES[j];
   switch(str){
      case "jasper":  GEM = "%^RED%^jasper";
                break;
      case "turquoise":  GEM = "%^CYAN%^tur%^BOLD%^qu%^RESET%^%^CYAN%^oise";
                break;
      case "azurite":  GEM = "%^BOLD%^%^CYAN%^azurite";
                break;
      case "black quartz":  GEM = "%^BOLD%^%^BLACK%^black quartz";
                break;
      case "white quartz":  GEM = "%^BOLD%^white quartz";
                break;
      case "citrine":  GEM = "%^YELLOW%^citrine";
                break;
      case "hematite":  GEM = "%^BOLD%^%^BLACK%^hematite";
                break;
      case "amethyst":  GEM = "%^MAGENTA%^am%^BOLD%^e%^RESET%^"+
                        "%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t";
                break;
      case "green tourmaline":  GEM = "%^GREEN%^green tourmaline";
                break;
      case "aquamarine":  GEM = "%^CYAN%^aquamarine";
                break;
      case "beryl":  GEM = "%^GREEN%^be%^BOLD%^%^BLACK%^r%^RESET%^%^GREEN%^yl";
                break;
      case "orange agate":  GEM = "%^ORANGE%^orange agate";
                break;
      case "topaz":  GEM = "%^YELLOW%^topaz";
                break;
      case "moonstone":  GEM = "%^BOLD%^moonstone";
                break;
      case "garnet":  GEM = "%^RED%^garnet";
                break;
      case "snowflake obsidian":  GEM = "%^BOLD%^%^WHITE%^sno"+
             "%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian";
                break;
      case "onyx":  GEM = "%^BOLD%^%^BLACK%^onyx";
                break;
      case "emerald":  GEM = "%^BOLD%^%^GREEN%^emerald";
                break;
      case "ruby":  GEM = "%^BOLD%^%^RED%^ruby";
                break;
      case "sapphire":  GEM = "%^BOLD%^%^BLUE%^sapphire";
                break;
      case "diamond":  GEM = "%^BOLD%^dia%^CYAN%^m%^WHITE%^ond";
                break;
      case "blue diamond":  GEM = "%^BOLD%^%^BLUE%^blue dia%^CYAN%^m%^BLUE%^ond";
                break;
      default:  GEM = str;
   }
   set_name("gem");
   set_long("This is a polished piece of "+GEM+"%^RESET%^.  It sparkles "+
      "prettily in the light, and it would probably fetch a good price.");
   set_short("A piece of "+GEM+"%^RESET%^");
   strs = explode(str," ");
   strs = strs + ({"gem",str,capitalize(str)});
   set_id(strs);
   set_weight(4);
   set_value(val);
}

int is_gem(){return 1;}
