//Titania (6/29/19)
//Bard Hall
//Designed by Ivyes

#include <std.h>
#include "../defs.h"
inherit VAULT;

void create()
{
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_travel(PAVED_ROAD);
   set_terrain(CITY);
   set_climate("temperate");
   set_name("The Shadow Bard Guild");
   set_short("%^RESET%^%^MAGENTA%^The Shadow Bard Guild%^RESET%^");
   set_long("%^BOLD%^Welcome to the %^MAGENTA%^The Shadow Bard Guild%^WHITE%^! "+
   "Although you are quite certain you are beneath the ground, "+
   "and the only %^ORANGE%^sun %^WHITE%^in the sky "+
   "is painted there, entering this hallway is like turning "+ 
   "down a bright alleyway. %^BLACK%^Lampposts %^WHITE%^are "+ 
   "strung with "+ 
   "%^GREEN%^r%^MAGENTA%^i%^ORANGE%^b%^RED%^b%^MAGENTA%^o%^CYAN%^n%^GREEN%^s%^WHITE%^, "+ 
   "and %^GREEN%^v%^RESET%^%^GREEN%^i%^ORANGE%^b%^BOLD%^%^GREEN%^ra%^RESET%^%^GREEN%^n%^BOLD%^t "+ 
   "t%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^e%^RESET%^%^GREEN%^e%^BOLD%^s "+ 
   "%^WHITE%^line the indoor streets, adding %^GREEN%^life %^WHITE%^and "+ 
   "%^GREEN%^col%^RESET%^%^CYAN%^o%^BOLD%^%^GREEN%^r%^WHITE%^. "+ 
   "Some %^RESET%^%^ORANGE%^benches %^BOLD%^%^WHITE%^provide a "+ 
   "nice place to sit and relax. "+ 
   "%^MAGENTA%^M%^RESET%^%^MAGENTA%^u%^BOLD%^sic "+ 
   "%^WHITE%^drifts through the area, coming from an unseen source. "+ 
   "A %^MAGENTA%^c%^RESET%^%^MAGENTA%^h%^BOLD%^eerf%^RESET%^%^MAGENTA%^u%^BOLD%^l "+ 
   "fell%^RESET%^%^MAGENTA%^o%^BOLD%^w %^WHITE%^strides up and down "+ 
   "the %^BLACK%^c%^RESET%^%^GREEN%^o%^ORANGE%^b%^BOLD%^%^BLACK%^blest%^RESET%^%^ORANGE%^o%^GREEN%^n%^BOLD%^%^BLACK%^e %^RESET%^%^ORANGE%^s%^BOLD%^%^BLACK%^tr%^RESET%^%^ORANGE%^e%^GREEN%^e%^BOLD%^%^BLACK%^t%^WHITE%^, "+ 
   "peddling the %^CYAN%^instruments %^WHITE%^he carved himself.%^RESET%^\n");
   set_smell("default","%^BOLD%^%^GREEN%^It smells like nature.%^RESET%^");
   set_listen("default","%^BOLD%^%^CYAN%^Upbeat %^BLUE%^music %^CYAN%^fills the air.%^RESET%^");
   set_items(([
      ({"sun"}) : "%^RESET%^%^ORANGE%^High on the wall, "+  
	  "cast between painted white clouds, a "+  
	  "%^YELLOW%^metallic gold ball%^RESET%^%^ORANGE%^ "+  
	  "represents the shining sun. The fiery colors "+  
	  "whorl and glimmer, creating a mesmerizing "+  
	  "and magical display.%^RESET%^",
      ({"lampost","lampposts","ribbons"}) : "%^BOLD%^%^BLACK%^Not so "+  
	  "different than the ones found on the streets above, "+  
	  "the lamps glow with a soothing, magic light, creating "+  
	  "a pleasant atmosphere. The bases are entwined with "+  
	  "%^MAGENTA%^colorful ribbons%^BOLD%^%^BLACK%^ "+  
	  "to add a bit of vibrant color.%^RESET%^",
      ({"trees"}) : "%^RESET%^%^GREEN%^Always "+  
	  "%^BOLD%^vibrant%^RESET%^%^GREEN%^ no matter "+  
	  "the season, these trees somehow thrive without "+  
	  "the help of sun nor rain. They are spread about "+  
	  "at even intervals along the street, adding a bit of "+  
	  "%^BOLD%^freshness%^RESET%^%^GREEN%^ to the air.%^RESET%^",
	  ({"benches","bench"}) : "%^RESET%^%^ORANGE%^The benches "+  
	  "line the street and provide a pleasant place for "+  
	  "conversation, or perhaps a nap.%^RESET%^",
	  ({"path","street","cobblestones","cobblestone path"}) : "%^BOLD%^%^BLACK%^Stones "+ 
	  "ranging in hues from pale %^RESET%^grays%^BOLD%^%^BLACK%^, "+ 
      "%^RESET%^%^MAGENTA%^purples%^BOLD%^%^BLACK%^ and "+  
	  "%^BLUE%^blues%^BOLD%^%^BLACK%^ are perfectly cobbled "+  
	  "together to form a smooth street that cuts "+  
	  "through the middle of the curious room. There's a small grate in the middle of the street.",
	  ({"grate"}) : "%^BOLD%^%^BLACK%^It seems to lead down into the sewer system beneath the city. Ew.%^RESET%^",
   ]));
   set_exits(([
      "up" : ROOMS"backstage",
   ]));
}
   
   void reset(){
   ::reset();
   if(!present("clancy")){
      find_object_or_load(MON"clancy")->move(TO);
   }
}

void init() {
  	::init();
  	add_action("open","open");
	add_action("close","close");
}

int close(string str) {
 	if(!str) {
   	tell_object(TP,"Open what?");
      return 1;
   }
  	if(str == "grate"){
  		if(member_array("down",TO->query_exits()) != -1) {
     		tell_object(TP,"You slide the grate back into place.\n");
			remove_exit("down");
			if(member_array("up",ROOMS"sewer1"->query_exits()) != -1) {
     		tell_room(ROOMS"sewer1","The sewer falls into darkness as someone slides the grate shut from above.\n",TP);
     		ROOMS"sewer1"->remove_exit("up");
     		return 1;
     	}
     	tell_object(TP,"The grate is as closed as it can possibly be.");
		return 1;
	}
}
}

int open(string str) {
 	if(!str) {
   	tell_object(TP,"What are you trying to open?");
      return 1;
   }
  	if(str == "grate"){
    tell_object(TP,"%^BOLD%^%^WHITE%^You slowly move aside the heavy grate leading to the sewers.%^RESET%^");
    tell_room(ETP,"%^BOLD%^%^WHITE%^"+TPQCN+" slowly moves aside the heavy grate leading to the sewers.%^RESET%^",TP);
     add_exit(ROOMS"sewer1","down");
       tell_room(ROOMS"sewer1","%^BOLD%^%^WHITE%^Light suddenly floods the tunnel as the grate overhead opens.RESET%^");
       ROOMS"sewer1"->add_exit(ROOMS"bardguild","up");
	   return 1;
     }
   }