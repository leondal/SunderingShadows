#include <std.h>

#define SHAPES ({"aarakocra","aboleth","air elemental","ankheg",\
"antelope","ape","aurumvorax","badger","banshee","basilisk","bat",\
"bear","bee","beetle","behir","beholder","blinkdog","brownie",\
"buffalo","bugbear","bulette","bullywug","carrion crawler","centaur",\
"cheetah","chimera","cloaker","cockatrice","couatl","crypt thing",\
"cyclops","dinosaur","displacer beast","djinn","dolphin","dragon",\
"dragonfly","dragonne","drider","dryad","eagle","earth elemental","eel",\
"efreeti","elephant","ettercap","eyewing","faerie","faerie dragon",\
"feyr","fire elemental","firedrake","fox","gargantua","ghost",\
"gibberling","gloomwing moth","grell","griffon","grimlock","hawk",\
"hippogriff","hook horror","horse","hydra","illithid","imp","jackal",\
"jackalwere","jaguar","kingfisher","kirre","leopard","leprechaun",\
"leucrotta","lich","lion","manta ray","medusa","mephit","mermaid",\
"merman","minotaur","monkey","naga","nereid","nixie","nymph",\
"octopus","owl","owlbear","pegasus","peryton","phoenix","pig",\
"pixie","porcupine","praying mantis","pseudodragon","rabbit","rakshasa",\
"rat","raven","remorhaz","roc","roper","rust monster","satyr","scorpion",\
"selkie","shedu","sheep","sirine","snake","sphinx","spider",\
"sprite","squirrel","stag","swan","sylph","tiger","treant",\
"troglodyte","umber hulk","unicorn","vulture","water elemental",\
"water weird","weasel","wemic","werewolf","whale","will o'whisp",\
"wolf","wyvern","yuan-ti"})

#define GEMS ({"%^BOLD%^%^WHITE%^sno%^BLACK%^w%^WHITE%^flake %^BLACK%^obs%^WHITE%^i%^BLACK%^dian","%^RESET%^%^ORANGE%^tig%^YELLOW%^e%^RESET%^%^ORANGE%^r's eye","%^RESET%^%^RED%^carn%^BOLD%^e%^RESET%^%^RED%^lian","%^BOLD%^%^RED%^red jasper","%^YELLOW%^citrine","%^RESET%^%^ORANGE%^py%^YELLOW%^ri%^RESET%^%^ORANGE%^te","%^GREEN%^aventurine","%^BOLD%^%^MAGENTA%^rose quartz","%^MAGENTA%^am%^BOLD%^e%^RESET%^%^MAGENTA%^thy%^BOLD%^s%^RESET%^%^MAGENTA%^t","%^CYAN%^aquamarine","%^CYAN%^turq%^BOLD%^uo%^RESET%^%^CYAN%^ise","%^BOLD%^%^WHITE%^clear calcite"})

inherit ARMOUR;

int i,j;
string str, SHAPE, GEM;

void create()
{
   ::create();
	j = random(sizeof(SHAPES));
	SHAPE = SHAPES[j];
	i = random(sizeof(GEMS));
	GEM = GEMS[i];
	set_value(random(10)+100);
      str = "a";
      if(SHAPE == "aarakocra" || SHAPE == "aboleth" || SHAPE == "air elemental" || SHAPE == "ankheg" || SHAPE == "antelope" || SHAPE == "ape" || SHAPE == "aurumvorax" || SHAPE == "eagle" || SHAPE == "earth elemental" || SHAPE == "eel" || SHAPE == "efreeti" || SHAPE == "elephant" || SHAPE == "ettercap" || SHAPE == "eyewing" || SHAPE == "illithid" || SHAPE == "imp" || SHAPE == "octopus" || SHAPE == "owl" || SHAPE == "owlbear" || SHAPE == "umber hulk"){
         str = "an";
      }
	set_name(""+SHAPE+" pendant");
	set_short(""+SHAPE+" pendant");
	set_id(({"pendant",""+SHAPE+" pendant","wooden pendant"}));
	set_long("This simple %^ORANGE%^wooden pendant %^RESET%^"+
         "has been carved in the likeness of "+str+" %^BOLD%^"+
         ""+SHAPE+"%^RESET%^ and threaded onto a braided "+
         "%^ORANGE%^leather cord %^RESET%^interspersed with "+
         "tiny chips of "+GEM+"%^RESET%^.  It is a simple, "+
         "natural-looking piece of jewelry though the carving "+
         "is rather lifelike and seems to have been made by "+
         "a master.");
      set_lore("Made by Edric, the firbolg jeweler in the village "+
         "of Lothwaite, wooden pendants such as this are said "+
         "to bear some measure of the spirit of the item portrayed.  "+
         "Uses for the pendant differ from person to person.  Some "+
         "wear them simply for decoration, while others use them "+
         "in conjunction with simple magics to either attract "+
         "or repel the being portrayed.  Wood carving is a favorite "+
         "activity among firbolgs, and this seems to be one of "+
         "their most extraordinary pieces.");
      set_property("lore difficulty",12);
	set_weight(1);
	set_type("ring");
	set_limbs(({"neck"}));
	set_ac(0);
}
