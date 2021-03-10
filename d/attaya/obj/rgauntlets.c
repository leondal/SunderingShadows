#include <std.h>;

inherit "/d/common/obj/armour/gauntlets.c";

#define SIGILS ({"%^BOLD%^%^RED%^phoenix%^RESET%^",\
"%^BOLD%^%^CYAN%^crescent moon%^RESET%^",\
"%^YELLOW%^lightning bolt%^RESET%^",\
"%^BOLD%^%^RED%^rose%^RESET%^",\
"%^BOLD%^%^GREEN%^laurel leaves%^RESET%^",\
"%^RESET%^%^ORANGE%^stallion%^RESET%^",\
"%^BOLD%^marid%^RESET%^",\
"%^BOLD%^%^WHITE%^snowflake%^RESET%^",\
"%^BOLD%^%^BLUE%^djinni%^RESET%^",\
"%^RESET%^%^ORANGE%^dao%^RESET%^",\
"%^RESET%^%^RED%^efreeti%^RESET%^",\
"%^RED%^fox%^RESET%^",\
"%^RESET%^%^WHITE%^white owl%^RESET%^",\
"%^RESET%^%^CYAN%^hawk%^RESET%^",\
"%^YELLOW%^dove%^RESET%^",\
"%^BOLD%^%^BLACK%^bat%^RESET%^",\
"%^RESET%^%^BLUE%^wolf%^RESET%^",\
"%^YELLOW%^lion%^RESET%^",\
"%^RESET%^%^ORANGE%^tiger%^RESET%^",\
"%^RESET%^%^MAGENTA%^lyre%^RESET%^",\
"%^RED%^bull%^RESET%^",\
"%^BOLD%^%^MAGENTA%^faerie%^RESET%^",\
"%^BOLD%^%^CYAN%^dolphin%^RESET%^",\
"%^YELLOW%^sphinx%^RESET%^",\
"%^RESET%^%^GREEN%^serpent%^RESET%^",\
"%^RESET%^%^ORANGE%^stag%^RESET%^",\
"%^YELLOW%^gold eagle%^RESET%^",\
"%^BOLD%^%^WHITE%^rabbit%^RESET%^",\
"%^BOLD%^%^WHITE%^graceful unicorn%^RESET%^",\
"%^YELLOW%^sunburst%^RESET%^",\
"%^RESET%^%^BLUE%^starburst%^RESET%^"})

int j;
string str, SIGIL;
void create(){
	::create();
	j = random(sizeof(SIGILS));
      SIGIL = SIGILS[j];
    set_name("mesh gauntlets");
    set_id(({"gauntlets","gloves","glove","mesh"}));
    set_obvious_short("%^BOLD%^%^WHITE%^A pair of mithril mesh gauntlets%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^Mithril Mesh Gauntlets%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Forged from a mithril, these mesh "+
	"gauntlets seem lightweight and flexible.  The tightly woven mesh"+
	" has a %^BOLD%^s%^RESET%^e%^BOLD%^m%^RESET%^i%^BOLD%^-%^RESET%^s"+
	"%^BOLD%^h%^RESET%^e%^BOLD%^e%^RESET%^r%^BOLD%^%^WHITE%^ quality to"+
	" it, though the mesh seems as strong as steel.  Overlapping jointed"+
	" metal plates cover the top of each finger, giving further protection"+
	" to the wearer's hands.  Smooth rounded caps top off each mesh finger "+
	"of each gauntlet, giving it an attractive appearance.  Embossed on a "+
	"thin %^BLUE%^metal plate%^WHITE%^ on the back of each gauntlet is an "+
	"image of a "+SIGIL+"%^BOLD%^%^WHITE%^.\n%^RESET%^");
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
    set_property("enchantment",4);
    set_wear((:TO,"wearme":));
    set_value(4500);
}
int wearme(){
     if((int)TP->query_lowest_level() < 30) {
       tell_object(TP,"You may not wear those yet. Only those who earn them may.");
       return 0;
    }
     if(!TP->is_class("cavalier") && !TP->is_class("paladin") && !TP->is_class("fighter") && !TP->is_class("cleric") && !TP->is_class("antipaladin")) {
      tell_object(ETO,"%^BOLD%^%^BLACK%^The magic of the gauntlets refuses to be worn by you.");
      return 0;
   }
     return 1;
}