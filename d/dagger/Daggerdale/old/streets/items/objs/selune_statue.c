//coded by Styx for Armos for Selune's temple
// changing to inherit /d/common for consistency *Styx*  12/24/03, last change 4/20/02

#include <std.h>
// #include <daemons.h>
// inherit OBJECT;

inherit "/d/common/obj/misc/street_light.c";

// int original_light;

void create() {
    ::create();
    set_id( ({"statue"}) );
    set_name("statue");
    set_short("%^BOLD%^%^WHITE%^A magnificent m%^YELLOW%^a%^WHITE%^rb"
       "%^YELLOW%^l%^WHITE%^e statue");
    set_dayShort(query_short());
    set_nightShort(query_short());
//    set_weight(1000000);
//    set_property("no animate", 1);
    set_long("This is a magnificent, gleaming %^BOLD%^%^WHITE%^m%^YELLOW%^"
	"a%^WHITE%^rb%^YELLOW%^l%^WHITE%^e %^RESET%^statue.  It looks about "
	"fifteen feet tall and is mounted on a solid bronze base.  It is "
	"an intricately detailed carving of a beautiful woman standing with "
	"welcoming arms outstretched.  She is wearing a %^YELLOW%^long "
	"flowing robe %^RESET%^and a silver necklace.  A warm smile is seen "
	"upon her lips and her eyes are two crystals which glimmer a "
	"%^BOLD%^CYAN%^bright azure blue.  \n%^RESET%^Her %^YELLOW%^golden "
	"hair %^RESET%^is long and free-flowing, running down her back.  "
	"Even at night, the marble statue seems to almost glow as if it had "
	"an inner silver light, penetrating the darkness.  This glow is "
	"obviously created by some form of magic.  A %^YELLOW%^golden plaque "
	"%^RESET%^with an inscription is affixed to the base."
    );
    set_read("%^WHITE%^The gleaming plaque reads:\n"
     "%^B_YELLOW%^%^BOLD%^In loving tribute and dedicated to the Silver Lady "
     "as an expression of thanks for guiding me through all.\n"
     "- Jeffrey Kartan Armos");
    set_value(0);
//    original_light =  -9999;
}

/*
void init(){
   string tod;
   ::init();
   add_action("read_plaque","read");
   if(!interactive(TP)) return;
   tod = EVENTS_D->query_time_of_day();
   if((tod == "night") && !query_property("light")){ 
      set_property("light",3);
   }
   if((tod != "night") && query_property("light")){
      remove_property("light");
   }
}

int read_plaque(string str){
   if(str != "plaque") return 0;
   tell_object(TP,"%^WHITE%^The gleaming plaque reads:\n"
     "%^B_YELLOW%^%^BOLD%^In loving tribute and dedicated to the Silver Lady "
     "as an expression of thanks for guiding me through all.\n"
     "- Jeffrey Kartan Armos");
   return 1;
}
*/
