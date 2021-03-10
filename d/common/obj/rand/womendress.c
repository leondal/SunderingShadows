#include <std.h>
inherit "/std/armour";
#define COLORS ({"%^BOLD%^%^WHITE%^snow white%^RESET%^",\
"%^BOLD%^%^RED%^cardinal red%^RESET%^",\
"%^RESET%^%^RED%^burgundy red%^RESET%^",\
"%^BOLD%^%^GREEN%^lime green%^RESET%^",\
"%^RESET%^%^GREEN%^forest green%^RESET%^",\
"%^BOLD%^%^BLACK%^onyx black%^RESET%^",\
"%^BOLD%^%^BLUE%^royal blue%^RESET%^",\
 "%^RESET%^%^BLUE%^indigo%^RESET%^",\
 "%^YELLOW%^desert yellow%^RESET%^",\
"%^RESET%^%^ORANGE%^chocolate brown%^RESET%^",\
"%^BOLD%^%^CYAN%^sky blue%^RESET%^",\
"%^RESET%^%^BOLD%^%^CYAN%^teal green%^RESET%^",\
"%^RESET%^%^MAGENTA%^dark violet%^RESET%^",\
"%^BOLD%^%^MAGENTA%^pale pink%^RESET%^",\
"%^BOLD%^%^BLACK%^charcoal gray%^RESET%^",\
"%^RESET%^%^CYAN%^sea-green%^RESET%^"})
void create(){
     	int j;
	string str, COLOR;
	::create();
	j = random(sizeof(COLORS));
      COLOR = COLORS[j];
	set_name("velvet dress");
      set_id(({ "dress", "velvet dress","cowled dress"}));
      set_short("%^RESET%^A "+COLOR+" velvet dress");
      set_obvious_short("%^RESET%^A "+COLOR+" velvet dress");
      set_long( "This loose fitting dress is made from soft high"+
		" quality velvet. The velvet has been dyed an eye pleasing s"+
		"hade of "+COLOR+".  The loose fit of the dress is popular with"+
		" many for it's comfort and variety.  By adding a belt "+
		"or sash the wearer could cinch in the dress around the hips,"+
		" or she may elect to keep it flowing about her form.  "+
		"The square neckline of the dress frames the wearer's "+
		"neck and collar bones. Long fitted sleeves help to keep"+
		" a lady warm, and from exposing to much flesh.  The "+
		"front panel of the dress is made from a heavily "+
		"%^BOLD%^%^BLACK%^b%^RESET%^r%^BOLD%^%^BLACK%^o%^RESET%^c"+
		"%^BOLD%^%^BLACK%^a%^RESET%^d%^BOLD%^%^BLACK%^e%^RESET%^"+
		" pattern, contrasting pleasantly with the velvet.  "+
		"%^BOLD%^%^BLACK%^Ribbon%^RESET%^ trim laces up this "+
		"front panel section, serving as an adornment.  "+
		"The hem of this long dress brushes the floor, "+
		"letting the wearer retain her modesty.\n");
     	set_weight(4);
     	set_value(100);
      set_lore( "A staple in any woman's wardrobe, these dresses are used by"+
		" common folk and noble born alike.  Though there may be some variation on "+
		"the fabrics used or color, the dresses are popular with everyone.  Any good"+
		" theater has a wide selection of these dresses on had in all colors.  The simp"+
		"listic design allows for a woman to accessorize it to her tastes and desires, m"+
		"aking no two dress the same.  Many priestesses seem to favor these dresses a"+
		"s well, accentuating them with gemstones sacred to their faith.  - Dress You "+
		"Up - A History of Clothing and Styles "+
		"in the Theater - Donetella Versaski");
   	set_property("lore difficulty",7);
    	set_type("clothing");
      set_limbs(({ "torso" }));
      set_size(random(2)+1);
      set_property("enchantment",2);
      set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
void init()
{
	::init();
      	add_action("laces","laces");
}
int wear_func(){
	if((string)ETO->query_gender() == "male") {
        	tell_object(ETO,"%^BOLD%^%^CYAN%^You rip the dress"+
			"to shreds as you try to squeeze into it.");
        	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETO->QCN+""+
        		" rips the dress to shreads as he tries to squeeze"+
			"into it.",ETO);
				TO->remove();
		return 0;
}
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" looks"+
		" demure as she smooths"+
		" out her velvet dress.",ETO);
     	tell_object(ETO,"%^BOLD%^%^CYAN%^You feel "+
		"demure as you smooth out the fine velvet of this dress.  Don't"+
		" forget to smooth out your %^BLACK%^laces%^CYAN%^.");
      return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" turns"+
		" her back to remove her dress.  Shame on"+
		" you for trying to peek!",ETO);
     	tell_object(ETO,"%^BOLD%^%^CYAN%^You turn your back and"+
		" remove your dress.  After all a lady never"+
		" reveals too much.");
     	return 1;
}
int laces(string str)
{
	if(ETO->query_bound() || ETO->query_unconcious() || ETO->query_paralyzed()|| ETO->query_tripped()) {TP->send_paralyzed_message("info",TP);
   	return 1;
}
	if(query_worn() && !str) {
        	tell_object(ETO,"%^BOLD%^%^BLACK%^You adjust the "+
			"laces on the dress, keeping them from tangling.");
        	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETO->QCN+""+
			" adjusts the ribbon laces on her dress, keeping them from tangling.",ETO);
           	return 1;
	}
}