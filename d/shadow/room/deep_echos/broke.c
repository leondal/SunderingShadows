//room with broken down gnomish machine
#include <std.h>
#include "deep_echo.h"
inherit ROOM;

void create(){  
    ::create();
	
    set_indoors(1);
    set_terrain(NAT_CAVE);
    set_travel(RUTTED_TRACK);
    set_property("light",1);
    set_name("Deep Echoes Mountains");
    set_short("Deep Echoes Mountains");
    set_long((:TO,"long_desc":));
    set_items(([
      (({"cavern","caverns","tunnel","cave"})) : "These tunnels "+
         "drilled out in %^BOLD%^ceilings%^RESET%^ "+
         "and %^BOLD%^walls%^RESET%^ "+
         "they were not created by anything but natural events "+
         ".  Chips and rocks are all around.  "+
         "The floors are full of dust and smashed rock"+
         ".  Several crates lay around."+
         "\n",
      (({"light","lights"})) : "Glowing rocks are hanging here.",
	  (({"parts"})) : "Broken parts indicate this place was"+
	    " ransackd.",
	   (({"crates"})) : "The crates are ransacked.",
      (({"wall","walls","ceiling"})) : "The walls are wet and "+
         "jagged from mining and "+
         "they are cold to the touch. "+
         "Although, several parts of the walls remain smooth.",  
        ]));
   set_listen("default","a simple buzz can be heard.");
   set_smell("default","it smells of oil.");

    set_exits(([
        "northeast" : ROOMS"29",
        ]));


}
void reset(){
  ::reset();
  if(!present("jumpsuit gnome"))
    new(MOBS"gnome")->move(TO);
  if(!present("machine"))
    new(OBJ"machine")->move(TO);
}
void poof(){
     if(!objectp(TO)) return; 
	 //if(!objectp(ETO)) return; 
	 if(present("machine",TO))
	 present("machine")->move("/d/shadowgate/void");
       
}
string long_desc() {
  int hasgnome =1; //switch off if gnome is gone
  if(!present("jumpsuit gnome")) hasgnome = 0;
  switch (hasgnome){
    case 1 : return ("%^CYAN%^Below Echoes Mountains%^RESET%^\n"+
      "The tunnel ends here but it looks different."+
	  "  Unlike the rest of the cave, this place appears "+
	  "drilled out.  The end of the tunnel is colapsed.  "+
	  "There are many parts "+
	  "sitting at the end of the shaft.  Most of the parts look "+
	  "broken."
      "\n"+
      "%^CYAN%^Several lights are set up.");
	  break;
	case 0 : return ("%^CYAN%^Below Echoes Mountains%^RESET%^\n"+
      "The tunnel ends here but it looks different."+
	  "  Unlike the rest of the cave, this place appears "+
	  "drilled out.  The end of the tunnel is colapsed."
      "\n"+
      "%^CYAN%^Several lights are set up.");
      break;
	  }  
}
