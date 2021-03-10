//Octothorpe (8/8/09)
//Laerad, Wild Magic effect generator
//Based on Seneca Beach wave generator mob by Circe
///d/attaya/newseneca/mon/wave_maker.c

#include <std.h>
#include <daemons.h>
inherit MONSTER;

int count;

void create(){
   ::create();
   set_name("wild magic generator");
   set_property("no detect",1);
   set_property("no bows",1);
   set_id(({"wild_gen"}));
   set_short(0);
   set_invis();
   add_limb("body","",0,0,0);
   count = 0;
}

void die(object ob){
}

void heart_beat(){
   string tod;
   ::heart_beat();
   tod = EVENTS_D->query_time_of_day();
   if(!objectp(TO)) return;
   if(!objectp(ETO)) return;
   count++;
   if(count == 20){
      switch(random(8)){
         case 0: tell_room(ETO,"%^RED%^Blood begins to seep out of "+
		            "cracks in the ground.  It quickly floods the "+
					"area, and then disappears back into the "+
					"ground.%^RESET%^");
                 break;
         case 1: tell_room(ETO,"%^YELLOW%^A bolt of lightning strikes "+
		            "the ground in the distance.%^RESET%^");
                 break;
         case 2: tell_room(ETO,"%^BOLD%^%^BLACK%^The ground shakes "+
		            "violently from the rumbling clouds "+
					"overhead.%^RESET%^");
                 break;
         case 3: tell_room(ETO,"%^BOLD%^A torrent of sn%^CYAN%^o"+
		            "%^WHITE%^wflak%^CYAN%^e%^WHITE%^s assaults the "+
					"area, briefly causing whiteout conditions, before "+
					"quickly melting away in the oppressive heat.%^RESET%^");
                 break;
         case 4: tell_room(ETO,"%^BOLD%^A %^CYAN%^l%^WHITE%^one white "+
		            "clo%^CYAN%^u%^WHITE%^d stands out against the "+
					"%^BOLD%^%^BLACK%^darkened cl%^RESET%^ou%^BOLD%^"+
					"%^BLACK%^ds %^WHITE%^ove%^CYAN%^r%^WHITE%^head, "+
					"leaving yo%^CYAN%^u %^WHITE%^with a feeling of "+
					"melancholy as it quickly floats out of vi%^CYAN%^e"+
					"%^WHITE%^w.%^RESET%^");
                 break;
	     case 5: if(tod == "night"){
		            tell_room(ETO,"%^BOLD%^The %^YELLOW%^moon %^WHITE%^"+
					   "momentarily vanishes from the sky, but after a "+
					   "few seconds it reappears elsewhere in the sky "+
					   "with a %^RESET%^%^RED%^blood-red %^BOLD%^"+
					   "%^WHITE%^hue.%^RESET%^");
			     }
				 else{
				 tell_room(ETO,"%^YELLOW%^A second sun rises from the "+
				    "western horizon.%^RESET%^");
				 }	
                 break;
		 case 6: tell_room(ETO,"%^BOLD%^%^BLACK%^A group of vultures "+
		            "begin circling omniously overhead.%^RESET%^");	
				 break;
		 case 7: tell_room(ETO,"%^BOLD%^%^WHITE%^An ancient, ghostly "+
		            "army marches past in parade formation.%^RESET%^");
                  break;					
         default: tell_room(ETO,"%^BOLD%^%^BLACK%^A group of vultures "+
		             "begin circling omniously overhead.%^RESET%^");
                  break;
      }
      count = 0;
   }
}

int do_damage(string str, int i){
    return 0;
}

int is_invincible(){ return 1;}
int is_detectable(){ return 0;}

int id(string str){
   if(objectp(TP) && !avatarp(TP)) return 0;
   else return ::id(str);
}

void set_invis(){
   if(TO->query_invis()) return;
   else ::set_invis();
   return;
}
