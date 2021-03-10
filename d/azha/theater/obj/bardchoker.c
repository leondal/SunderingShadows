#include <std.h>
inherit ARMOUR;
int FLAG;
int SPEECHFLAG;

void create(){
   	::create();
	SPEECHFLAG=0;
     	set_name("dlarun choker");
     	set_id(({ "choker", "silvery choker","dlaran choker""+
		", "jewelry","jasmal choker","maestro's voice","+
		""diva's voice" }));
      set_short("%^BOLD%^%^WHITE%^Dl%^GREEN%^a%^WHITE%^r%^GREEN%^"+
		"a%^WHITE%^n Choker%^RESET%^");
      set_obvious_short("%^BOLD%^%^WHITE%^A silvery metal choker%^RESET%^");
      set_long( "%^BOLD%^Intricately shaped from a silvery metal is this"+
		" choker.  The smooth silvery choker curves around the neck,"+
		" fitting flush against the skin.  The silvery metal gives "+
		"off a %^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^een%^WHITE%^ sheen"+
		" in the light.  The two sections of the choker are joined"+
		" in the back with a tightly wound spring.  This allows for "+
		"the wearer to snap the choker open and closed when wearing "+
		"or removing it.  Vertical rectangles of the silvery metal "+
		"intersect three rows of thinly linked chains.  The slender "+
		"rectangles are unadorned.  Worked into the center of the choker "+
		"is a clear jasmal stone.  When the light reflects upon the "+
		"colorless stone haloes of %^YELLOW%^a%^RESET%^%^ORANGE%^mb"+
		"%^YELLOW%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^WHITE%^ shine."+
		"%^RESET%^\n");
      set_weight(3);
      set_value(1000);
      set_lore( "Dlarun is a rare metal often known as icesteel."+
		"  When polished it is often mistaked for ivory.  Dlarun ore"+
		" is found in clay dug from riverbanks and when refined "+
		"is soft and easily carved.  A second heating makes the ore"+
		" hard and durable.  It is during the second heating that"+
		" the silvery white metal gains it's famous green sheen in"+
		" light. - Ores and Metals - Loremaster Prenius Feldrom");
      set_property("lore difficulty",13);
      set_type("clothing");
      set_limbs(({ "neck" }));
      set_size(-1);
      set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
      set_remove((:TO,"remove_func":));
}
void init() {
     	::init();
      add_action("say_func","say");
      if(userp(ETO)) set_size(ETO->query_size());
}
int say_func(string str) {
	string msg;
   	msg = str;
	if(ETO->query_gagged() || ETO->query_paralyzed()) return 0;
   	if(!query_worn()) return 0;
   	if(SPEECHFLAG == 0) {
   		return 0;
}else {
   	if (!str) {
     	tell_object(ETO,"%^BOLD%^%^GREEN%^You sing a wordless song in"+
	" an enchanting voice.%^RESET%^");
      tell_room(environment(ETO),"%^BOLD%^%^GREEN%^"+ETOQCN+" "+
      "sings a wordless song in an enchanting voice.",ETO);
      	return 1;
}else switch(SPEECHFLAG){

case 1:
	if((string)ETO->query_name() != "cythera") {
           	msg = "daemon/language_d"->translate(msg,ETO->query_spoken(),ETO);
	}
         	message("say","%^CYAN%^You say in a mesmerizing rich"+
			" %^BLUE%^b%^CYAN%^a%^GREEN%^r%^MAGENTA%^i%^GREEN%^t"+
			"%^CYAN%^o%^BLUE%^n%^GREEN%^e%^RESET%^: "+msg,ETO);
	   	message("say","%^CYAN%^"+ETOQCN+" says in a mesmerizi"+
			"ng rich %^BLUE%^b%^CYAN%^a%^GREEN%^r%^MAGENTA%^i"+
			"%^GREEN%^t%^CYAN%^o%^BLUE%^n%^GREEN%^e%^RESET%^:"+
			" "+msg,environment(ETO),ETO);
            return 1;     	
break;
case 2:                
	if((string)ETO->query_name() != "cythera") {
          	msg = "daemon/language_d"->translate(msg,ETO->query_spoken(),ETO);
	}	
         	message("say","%^CYAN%^You say in an enchanting %^BOLD%^"+
			"%^MAGENTA%^s%^RESET%^%^MAGENTA%^o%^BLUE%^p%^BOLD%^r"+
			"%^MAGENTA%^a%^RESET%^%^MAGENTA%^n%^BLUE%^o%^RESET%^:"+
			" "+msg,ETO);
	   	message("say","%^CYAN%^"+ETOQCN+" says in an enchanting %^BOLD%^"+
			"%^MAGENTA%^s%^RESET%^%^MAGENTA%^o%^BLUE%^p%^BOLD%^r"+
			"%^MAGENTA%^a%^RESET%^%^MAGENTA%^n%^BLUE%^o%^RESET%^"+
			": "+msg,environment(ETO),ETO);
		return 1;
break;
		default:
		tell_object(ETO,"%^B_MAGENTA%^%^BOLD%^%^MAGENTA%^Oh dear!  "+
			"Something's wrong with your class or gender.  Please find "+
			"a wiz to have them look at it.");
		return 0;
}
}
}
int wear_func(){
	string gend = ETO->query_gender();
   	if(!ETO->is_class("bard")){
   		tell_object(ETO,"%^CYAN%^You open the choker and slip it "+
			"around your neck.");
   		tell_room(environment(ETO),"%^CYAN%^"+ETO->QCN+" opens the"+
			" silvery choker and slips it around "+ETO->QP+" neck.");
		set_item_bonus("armor bonus",0);
   		return 1;
}
		set_item_bonus("armor bonus",1);
      	switch(gend) {
case "male":
    	tell_object(ETO,"%^BOLD%^%^BLUE%^As you slip the choker "+
		"on the chains meld together creating a single thick cha"+
		"in.  As the jasmal stone changes to blue, a deep barito"+
		"ne song echoes through your mind.");
	 tell_room(environment(ETO),"%^BOLD%^%^BLUE%^As "+ETO->QCN+""+
		" slips the choker on the chains meld together creating a"+
		" single thick chain.  The colorless stone changes to an "+
		"azure blue shade!",ETO);
      set_obvious_short("%^BOLD%^%^WHITE%^A silvery metal choker"+
		" with an %^BLUE%^azure jasmal%^RESET%^");
	set_short("%^RESET%^%^CYAN%^M%^BLUE%^a%^MAGENTA%^e%^CYAN%^"+
		"s%^BOLD%^t%^RESET%^%^CYAN%^r%^BLUE%^o%^MAGENTA%^'%^CYAN%^"+
		"s %^GREEN%^Voice%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Shaped from Dlarun metal, this "+
		"choker takes the shape of a thick chain that circles around"+
		" the neck.  The silvery metal has a %^GREEN%^gr%^RESET%^"+
		"%^GREEN%^ee%^BOLD%^n sheen%^WHITE%^ in the light.  The two"+
		" sections of chain are joined together in the back with "+
		"a tightly wound spring.  This allows for the wearer to "+
		"snap the choker open and closed when removing or wearing it."+
		" Miniature vertical rectangles of silvery dlarun metal "+
		"intersect the chain.  Carved into each small rectangle "+
		"is a different %^RESET%^%^BLUE%^m%^CYAN%^u%^GREEN%^s"+
		"%^MAGENTA%^i%^BLUE%^c%^BOLD%^%^WHITE%^ note.  Worked "+
		"into the center of the chain is a %^RESET%^%^BLUE%^deep"+
		" blue%^BOLD%^%^WHITE%^%^ jasmal stone.  When the light"+
		" reflects upon the blue stone haloes of %^BOLD%^%^BLUE%^"+
		"azure%^WHITE%^ shine.%^RESET%^\n");
		FLAG=1;
	   	SPEECHFLAG=1;
      set_lore("The most famous virtuoso of The Desert Sun was"+
		" Maestro Daleric Pelgand, a dashing dark haired bard "+
		"from the Tsvarian Empire.  Daleric received first"+
		" pick of the male roles in all the performances, for his"+
		" skill as an actor equaled his singing ability.  Women "+
		"would often swoon and faint over him.  Whether it was his"+
		" good looks or his incredible voice is left up to argument"+
		".  -Fame and Fortune - Famous Bards in History- Retanlian Yorvesk.");
	//set_property("lore difficulty",16);
      	return 1;
case "female":
	tell_object(ETO,"%^MAGENTA%^As you slip the choker on the "+
		"chains drape lower creating flowing swags.  As the jasmal"+
		" stone changes to purple, a high soprano song echoes"+
		" through your mind.");
	tell_room(environment(ETO),"%^MAGENTA%^As "+ETO->QCN+" slips"+
		" the choker on the chains drape lower creating flowing swags.  "+
		"The colorless stone changes to rich purple shade!",ETO);
     	set_obvious_short("%^BOLD%^%^WHITE%^A silvery metal choker "+
		"with a %^RESET%^%^MAGENTA%^purple jasmal%^RESET%^");
	set_short("%^BOLD%^%^MAGENTA%^D%^RESET%^%^MAGENTA%^i%^BLUE%^v"+
		"%^BOLD%^a%^MAGENTA%^'%^RESET%^%^MAGENTA%^s %^CYAN%^Voice%^RESET%^");
	set_long("%^BOLD%^%^WHITE%^Shaped from Dlarun metal, this choker"+
		" takes the shape of a dainty swaggered choker that encircles the"+
		" neck.  The silvery metal has a %^GREEN%^gr%^RESET%^%^GREEN%^ee"+
		"%^BOLD%^n sheen%^WHITE%^ in the light.  The two sections of chain"+
		" are joined together in the back with a tightly wound spring.  "+
		"This allows for the wearer to snap the choker open and closed "+
		"when removing or wearing it.  Miniature vertical rectangles of"+
		" silvery dlarun metal intersect the chain.  Carved into each "+
		"small rectangle is a different %^RESET%^%^BLUE%^m%^CYAN%^u%^GREEN%^"+
		"s%^MAGENTA%^i%^BLUE%^c%^BOLD%^%^WHITE%^ notes.  Worked into the "+
		"center of the chain is a %^RESET%^%^MAGENTA%^rich purple"+
		"%^BOLD%^%^WHITE%^ jasmal stone.  When the light reflects upon "+
		"the purple stone haloes of %^RESET%^%^MAGENTA%^purple%^BOLD%^"+
		"%^WHITE%^ shine.%^RESET%^\n");
	   	FLAG=1;
	   	SPEECHFLAG=2;
      set_lore("Diva Zahara Rezbet was the most famous singer at The "+
		"Desert Sun Theater.  This comely woman from Azha was well celebrated for"+
		" her talent.  An accomplished actress and singer Zahara always got"+
		" first pick of roles from any new production.  It was said that she"+
		" had a gentle calmness about here that soothed any jealousy and "+
		"charmed everyone into seeking to befriend this diva.  -Fame and"+
		" Fortune - Famous Bards in History - Retanlian Yorvesk.");
	//set_property("lore difficulty",16);
       	return 1;
default:
	tell_object(ETO,"%^B_MAGENTA%^%^BOLD%^%^MAGENTA%^Oh dear!  Something's "+
		"wrong with your gender or class.  Please find a wiz to have them"+
		" look at it.");
			return 0;
	}
}

int remove_func(){
	if(FLAG == 1) {
		tell_room(environment(ETO),"%^BOLD%^%^WHITE%^As "+ETOQCN+" "+
			"pries "+ETO->QP+" choker off, it transforms into a silvery"+
			" white choker with a colorless stone.",ETO);
	tell_object(ETO,"%^BOLD%^%^WHITE%^A haunting tune runs through"+
		" your mind as you pry the choker off.  The color in your stone"+
		" fades away as the choker morphs back to its "+
		"original form.");	
      set_obvious_short("%^BOLD%^%^WHITE%^A silvery metal choker%^RESET%^");
	set_short("%^BOLD%^%^WHITE%^Dl%^GREEN%^a%^WHITE%^r%^GREEN%^a%^WHITE%^n Choker ");
	set_long("%^BOLD%^Intricately shaped from a silvery metal is this"+
		" choker.  The smooth silvery choker curves around the neck, fitting"+
		" flush against the skin.  The silvery metal gives off a "+
		"%^GREEN%^g%^RESET%^%^GREEN%^r%^BOLD%^een%^WHITE%^ sheen in the"+
		" light.  The two sections of the choker are joined in the back"+
		" with a tightly wound spring.  This allows for the wearer to snap"+
		" the choker open and closed when wearing or removing it.  Vertical"+
		" rectangles of the silvery metal intersect three rows of thinly "+
		"linked chains.  The slender rectangles are unadorned.  Worked into"+
		" the center of the choker is a clear jasmal stone.  When the light"+
		" reflects upon the colorless stone haloes of %^YELLOW%^a%^RESET%^"+
		"%^ORANGE%^mb%^YELLOW%^e%^RESET%^%^ORANGE%^r%^BOLD%^%^WHITE%^"+
		" shine.%^RESET%^"); 
	set_lore( "Dlarun is a rare metal often known as icesteel.  When "+
		"polished it is often mistaked for ivory.  Dlarun ore is found in "+
		"clay dug from riverbanks and when refined is soft and easily "+
		"carved.  A second heating makes the ore hard and durable.  It"+
		" is during the second heating that the silvery white metal "+
		"gains it's famous green sheen in light. - Ores and "+
		"Metals - Loremaster Prenius Feldrom");
     	//set_property("lore difficulty",13);
	set_ac(-1);
		FLAG = 0;
		SPEECHFLAG= 0;	
	    	return 1;
}
else{
	tell_room(environment(ETO),"%^GREEN%^"+ETOQCN+" pries the choker open"+
		" and slips it off.",ETO);
     	tell_object(ETO,"%^GREEN%^You pry the choker open and slip it off.");
 		return 1;
}
}