#include <std.h>

#define TYPES ({"%^BOLD%^%^RED%^phoenix%^RESET%^",\
"%^BOLD%^%^WHITE%^crescent moon%^RESET%^",\
"%^YELLOW%^lightning bolt%^RESET%^","%^BOLD%^%^RED%^rose%^RESET%^",\
"%^BOLD%^%^GREEN%^laurel leaves%^RESET%^",\
"%^BOLD%^%^WHITE%^stallion%^RESET%^",\
"%^BOLD%^%^BLACK%^shadow%^RESET%^",\
"%^BOLD%^marid%^RESET%^","%^BOLD%^%^WHITE%^snowflake%^RESET%^",\
"%^BOLD%^%^BLUE%^djinni%^RESET%^","%^BOLD%^%^BLACK%^lunar eclipse%^RESET%^",\
"%^ORANGE%^dao%^RESET%^","%^RED%^efreeti%^RESET%^",\
"%^RED%^fox%^RESET%^",\
"%^BOLD%^%^WHITE%^white owl%^RESET%^","%^BOLD%^%^BLACK%^raven%^RESET%^",\
"%^BOLD%^%^BLACK%^nightmare%^RESET%^","%^MAGENTA%^swan%^RESET%^",\
"%^YELLOW%^dove%^RESET%^","%^BOLD%^%^BLUE%^peacock%^RESET%^",\
"%^BOLD%^%^BLACK%^bat%^RESET%^",\
"%^ORANGE%^cornucopia%^RESET%^",\
"%^BOLD%^%^RED%^red poppy%^RESET%^",\
"%^BLUE%^wolf%^RESET%^","%^YELLOW%^lion%^RESET%^",\
"%^ORANGE%^tiger%^RESET%^",\
"%^MAGENTA%^lyre%^RESET%^","%^RED%^bull%^RESET%^",\
"%^ORANGE%^massive owlbear%^RESET%^",\
"%^BLUE%^hydra%^RESET%^","%^BOLD%^%^MAGENTA%^faerie%^RESET%^",\
"%^RED%^gorgon%^RESET%^","%^BOLD%^dolphin%^RESET%^",\
"%^YELLOW%^sphinx%^RESET%^","%^GREEN%^serpent%^RESET%^",\
"%^BOLD%^%^BLACK%^spider%^RESET%^","%^ORANGE%^stag%^RESET%^",\
"%^YELLOW%^gold eagle%^RESET%^","%^BOLD%^%^WHITE%^rabbit%^RESET%^",\
"%^BOLD%^%^WHITE%^graceful unicorn%^RESET%^","%^BLUE%^starburst%^RESET%^"})

inherit "/d/common/obj/armour/mshield.c";


int j;
string str, TYPE;
void create(){
	::create();
	j = random(sizeof(TYPES));
      TYPE = TYPES[j];
	set_name("steel shield");
     	set_id(({ "shield", "steel shield" }));
      set_short("%^RESET%^%^CYAN%^Steel shield of the "+TYPE+"");
      set_obvious_short("%^RESET%^%^CYAN%^A "+TYPE+"%^CYAN%^ crest steel shield%^RESET%^");
      set_long( "%^CYAN%^Forged from steel, this round shield is "+
		"solid and thick.  The convex shape of the shield causes it"+
		" to curve outwards, aiding in deflecting blows in combat."+
		"  The steel has become oxidized in time, taking on a darker"+
		" finish than normal steel carries.  Two %^ORANGE%^leather"+
		" straps%^CYAN%^ attached to the inside of the shield allow"+
		" of it to be buckled onto the arm.  Painted onto the front"+
		" of the shield in enameled colors is the image of a "+TYPE+".\n");
      set_value(150);
      set_lore("Since the dawn of warfare and armor, shields have "+
		"always served and important role.  Not only for personal "+
		"protection, but as a way to communicate without words.  "+
		"Symbols or crests painted or cast into the shields helped"+
		" to define one tribe from another, one Lord's men from "+
		"another's.  And with in the faiths and temples across "+
		"the lands to define religious beliefs and sects within "+
		"the faiths.  Crested shields have now days become a way "+
		"for the adventure or martial fighter to place a calling "+
		"card, to create their own personal symbol.  Look to "+
		"history and the books to hear of stories about Therdax the"+
		" Silver Hawk, Ormesva the Scarlet Lion, or Urmvestan the "+
		"Black Dragon.  These and many more carrier their personal "+
		"symbols throughout history now. - A Study of Heraldry and "+
		"Symbols - Lorekeeper Yatham Mardel");
      set_property("lore difficulty",7);
      set_property("enchantment",2);
	set_ac(0);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
      tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" straps on the"+
		" round shield to "+ETO->QP+" arm.",ETO);
      tell_object(ETO,"%^CYAN%^You strap on the shield to your arm,"+
		" looking over the image of the "+TYPE+".");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" unbuckles the "+
		"round shield to remove it.",ETO);
      tell_object(ETO,"%^CYAN%^You unbuckle the shield and stop to "+
		"look at the image of the "+TYPE+" for a second.");
      return 1;
}
