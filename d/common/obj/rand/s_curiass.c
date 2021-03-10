#include <std.h>
inherit "/d/common/obj/armour/field.c";
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


	int j;
string str, TYPE;
void create(){
        ::create();
        j = random(sizeof(TYPES));
      TYPE = TYPES[j];
	set_name("steel cuirass");
     	set_id(({ "cuirass", "steel cuirass", "breastplate","armour","armor" }));
      set_short("%^RESET%^%^CYAN%^Steel cuirass of the "+TYPE+"");
      set_obvious_short("%^RESET%^%^CYAN%^A "+TYPE+"%^CYAN%^ crest steel cuirass%^RESET%^");
      set_long( "%^CYAN%^Forged from tempered steel, this cuirass "+
		"looks strong and steady.  The steel breastplate is"+
		" fashioned in a way to buckle at the sides, allowing"+
		" for a greater deal of flexibility in what body types"+
		" it can accommodate.  The front the cuirass has been"+
		" shaped to curve around the wearer's torso, giving a "+
		"smooth look to the breastplate.  On the front of the "+
		"breastplate is the bas relief image of a "+TYPE+".%^CYAN%^  A"+
		" shirt of steel chain mail underneath the cuirass adds"+
		" an additional layer of protection to the armor.  The "+
		"chain shirt offers protection to the arms, with its "+
		"short sleeves.  The tunic style shirt drops down till"+
		" about mid thigh, protecting the legs from blows.%^RESET%^\n");
      set_value(4000);
      set_lore("Crafted for the lesser known play, 'Five,Four,Three',"+
		" these suits of armor where crafted for the principal "+
		"characters in the play.  Within the play five dwarves,"+
		" four gnomes, and three halflings find themselves "+
		"thrusted in the middle of a battle between two human"+
		" kingdoms.  The play was a satire on human culture and"+
		" was filled with political messages that were relevent"+
		" for the time. - 12 Plays about Halflings - Lirelle "+
		"Springcheese");
      set_property("lore difficulty",7);
    set_property("enchantment",1);
	set_weight(40);
	set_size(1);
	set_value(2000);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
int wear_func(){
      tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" straps on"+
                " "+ETO->QP+" steel cuirass.",ETO);
      tell_object(ETO,"%^CYAN%^You strap on the steel cuirass,"+
		" looking over the image of the "+TYPE+".");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^CYAN%^"+ETOQCN+" unbuckles "+ETO->QP+" "+
                "steel cuirass to remove it.",ETO);
      tell_object(ETO,"%^CYAN%^You unbuckle the cuirass and stop to "+
		"look at the image of the "+TYPE+" for a second.");
      return 1;
}
