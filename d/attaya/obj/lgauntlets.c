#include <std.h>;
inherit "/d/common/obj/armour/gauntlets.c";

#define SIGILS ({"%^BOLD%^%^RED%^phoenix%^RESET%^",\
"%^BOLD%^%^CYAN%^kraken%^RESET%^",\
"%^YELLOW%^lightning bolt%^RESET%^",\
"%^BOLD%^%^RED%^rose%^RESET%^",\
"%^BOLD%^%^GREEN%^laurel leaves%^RESET%^",\
"%^BOLD%^%^WHITE%^stallion%^RESET%^",\
"%^BOLD%^%^BLACK%^shadow%^RESET%^",\
"%^BOLD%^marid%^RESET%^",\
"%^BOLD%^%^WHITE%^snowflake%^RESET%^",\
"%^BOLD%^%^BLUE%^djinni%^RESET%^",\
"%^BOLD%^%^BLACK%^lunar eclipse%^RESET%^",\
"%^RESET%^%^ORANGE%^dao%^RESET%^",\
"%^RESET%^%^RED%^efreeti%^RESET%^",\
"%^RED%^fox%^RESET%^",\
"%^BOLD%^%^BLACK%^raven%^RESET%^",\
"%^BOLD%^%^BLACK%^nightmare%^RESET%^",\
"%^RESET%^%^CYAN%^hawk%^RESET%^",\
"%^BOLD%^%^BLUE%^rat%^RESET%^",\
"%^BOLD%^%^BLACK%^bat%^RESET%^",\
"%^RESET%^%^BLUE%^wolf%^RESET%^",\
"%^YELLOW%^lion%^RESET%^",\
"%^RESET%^%^ORANGE%^tiger%^RESET%^",\
"%RESET%^%^RED%^beholder%^RESET%^",\
"%^ORANGE%^massive owlbear%^RESET%^",\
"%^BLUE%^hydra%^RESET%^",\
"%^RED%^gorgon%^RESET%^",\
"%^YELLOW%^sphinx%^RESET%^",\
"%^GREEN%^serpent%^RESET%^",\
"%^BOLD%^%^BLACK%^spider%^RESET%^",\
"%^RESET%^%^ORANGE%^stag%^RESET%^",\
"%^YELLOW%^gold eagle%^RESET%^",\
"%^BLUE%^starburst%^RESET%^"})

int j;
string str, SIGIL;
void create(){
	::create();
	j = random(sizeof(SIGILS));
      SIGIL = SIGILS[j];
    set_name("mesh gauntlets");
    set_id(({"gauntlets","gloves","glove","mesh"}));
    set_obvious_short("%^BOLD%^%^BLACK%^A pair of black mesh gauntlets%^RESET%^");
    set_short("%^BOLD%^%^BLACK%^Black Mesh Gauntlets%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^Forged from a black alloy, these mesh "+
	"gauntlets seem lightweight and flexible.  The tightly woven mesh"+
	" has a %^BOLD%^s%^RESET%^e%^BOLD%^m%^RESET%^i%^BOLD%^-%^RESET%^s"+
	"%^BOLD%^h%^RESET%^e%^BOLD%^e%^RESET%^r%^BOLD%^%^BLACK%^ quality to"+
	" it, though the mesh seems as strong as steel.  Overlapping jointed"+
	" metal plates cover the top of each finger, giving further protection"+
	" to the wearer's hands.  Wicked looking caps top off each mesh finger "+
	"of each gauntlet, giving it an intimidating appearance.  Embossed on a "+
	"thin %^BLUE%^metal plate%^BLACK%^ on the back of each gauntlet is an "+
	"image of a "+SIGIL+"%^BOLD%^%^BLACK%^.\n%^RESET%^");
     set_lore("Because of the battle with the Black Dawn tower on Attaya,"+
	" the people of Seneca found a need to craft armor to help protect"+
	" themselves.  These gauntlets were made by the armorsmiths of Seneca"+
	" to aid those that came to their aid against the threat that broke out"+
	" on their island.  Because of the diverse number of people, a small metal"+
	" plate was attached to each gauntlet allowing each company, person, or "+
	"adventuring band to apply their sigils.  The battle against the Tower "+
	"of the Black Dawn and the forces within has been going on for ages with "+
	"no end in sight.");
    set_property("lore",13);
    set_property("enchantment",5);
    set_wear((:TO,"wearme":));
    set_value(4500);
}
int wearme(){
   if((int)ETO->query_level() < 25) {
       tell_object(TP,"You may not wear those yet. Only those who earn them may.");
       return 0;
    }
       if(!TP->is_class("cavalier") && !TP->is_class("paladin") && !TP->is_class("fighter") && !TP->is_class("cleric") && !TP->is_class("antipaladin")) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The magic of the gauntlets refuses to be worn by you.");
      return 0;
   }
     return 1;
}
