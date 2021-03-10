//grove
/*
The room description here just reads a little
awkwardly. Maybe...In the autumn, this elven meadow changes to shades of
orange and red as trees prepare for the winter and tendrils of cool mist
blanket it.  Many beautiful and mystical plants shed their leaves, falling
near several trees with in which huts can be seen. The grace of the Elven
people echoes in every aspect of this place and from the north comes a soft
crashing of water falling down from a steep cliff.  Beautiful streams flow
through the groves their water warming the grove.
 suggestion from aash

*/

#include <std.h>
#include "../elf.h"
inherit CROOM;


void create(){
 if(base_name(TO) != "/d/islands/elf/inher/grove")
 switch  (random(10)){
  case 0:set_monsters(({MON"guard"}),({roll_dice(1,3)}));
         break;
  case 1:set_monsters(({MON"guard2"}),({roll_dice(1,3)}));
         break;
  case 2: 
  set_monsters(({MON"guard2",MON"guard"}),({roll_dice(1,3),roll_dice(1,3)}));
         break;
  case 3:set_monsters(({MON"citizen"}),({roll_dice(1,2)}));
         break;
  case 4:set_monsters(({MON"child"}),({1}));
         break;
  case 5:set_monsters(({MON"citizen2"}),({1}));
         break;
  case 6:set_monsters(({MON"citizen3"}),({1}));
         break;
  }
    ::create();
    set_terrain(GRASSLANDS);
    set_travel(GAME_TRACK);
    set_repop(40);
    set_climate("mountain");
    set_name("Grove");
    set_short("%^BOLD%^%^GREEN%^Ashta'Rathai Grove%^RESET%^");
    set_long((:TO,"long_desc":));
        set("night long",(:TO,"night_desc":));
        set_items(([
      (({"meadow"})) :
        "It is a beautiful mist-shrouded meadow.",
          (({"huts"})) :
        "High in the trees, concealed amongst the lush "+
        "leaves, are small huts that almost appear to be"+
                " natural extensions of the trees. Upon closer "+
                "inspection, the woodwork is actually quite "+
                "intricate and beautiful, a telltale sign of "+
                "the exquisite craftsmanship of the elves.",
          (({"water","streams","waterfall"})) :
        "From the north comes the sound of water gently "+
        "falling down steep cliffs. Beautiful streams, "+
                "formed by the waterfall, flow through the grove.",
      (({"plants"})) : "The plant life here is quite exotic.",
      (({"tree","trees"})) : "Elves make their homes in "+
          "the trees.",
          (({"cliff","cliffs"})) : "Steep cliffs surround "+
          "most of the grove.",
           ]));
 
   set_listen("default",
   "Birds chirp softly, and sounds of soft winds blowing can be heard.");
   set_smell("default",
   "The lush smell of grasses and plants fill your senses.");

}

string long_desc(){
  if (season(time()) == "winter") 
   return(query_short() + "\n"+
   "%^CYAN%^In the winter this elven meadow has"+
   " a %^BOLD%^chill breeze%^RESET%^.  %^CYAN%^The grove is "+
   "filled with a thick mist%^RESET%^.%^CYAN%^  Many "+
   "%^RESET%^beautiful plants%^CYAN%^ adorn the grove "+
   "but few bloom%^RESET%^. %^CYAN%^ Several trees with"+
   " huts can be seen about%^RESET%^.%^CYAN%^  Everything"+
   " appears profondly elven%^RESET%^.%^CYAN%^  From the "+
   "north%^RESET%^,%^CYAN%^ comes a soft crashing of water"+
   " falling down a steep cliff from which"+
   " beautiful streams flow throught the "+
   "grove%^RESET%^.%^CYAN%^  This water warms the grove%^RESET%^.%^CYAN%^  "+
   "Sometimes there is snow but it never sticks%^RESET%^."+
"\n");
   
   if (season(time()) == "autumn") 
     return(query_short() + "\n"+
     "%^ORANGE%^In the autumn%^GREEN%^,%^ORANGE%^ this elven meadow changes"+
         " to shades of orange and red as trees prepare "+
         "for the winter%^GREEN%^.%^ORANGE%^  It is filled with a %^CYAN%^cool mist%^GREEN%^."+
         "  %^ORANGE%^Many beautiful and mystical plants shed their "+
         "leaves%^GREEN%^.  %^ORANGE%^Several trees with huts can be seen about"+
         "%^GREEN%^.%^ORANGE%^  Everything seems profoundly elven%^GREEN%^. %^ORANGE%^ "+
         "From the north%^GREEN%^,%^ORANGE%^ comes a soft crashing of "+
         "%^CYAN%^water%^ORANGE%^ falling down from a steep cliff%^GREEN%^.  "+
         "%^ORANGE%^Beautiful streams flow through the groves%^GREEN%^."+
         "  %^ORANGE%^The water warms the grove.");
  return (query_short() + "\n"+
  "%^GREEN%^"+
    "This %^BOLD%^elven meadow%^RESET%^%^GREEN%^ is lush and filled with a pleasantly cool "+
        "mist%^BOLD%^%^BLUE%^.  %^RESET%^%^GREEN%^Many beautiful and %^CYAN%^mystical plants%^GREEN%^ adorn the grove%^BLUE%^%^BOLD%^."+
        "  %^RESET%^%^GREEN%^Several huts can be seen high in the trees%^BOLD%^%^BLUE%^.  "+
        "%^RESET%^%^GREEN%^The magic here has shaped the trees into pleasant forms%^BOLD%^%^BLUE%^.%^RESET%^%^GREEN%^"+
		"  Everything appears "+
        "profoundly elven%^BOLD%^%^BLUE%^.%^RESET%^%^GREEN%^  From the north comes a soft crashing "+
    "of %^BOLD%^water%^RESET%^%^GREEN%^ falling down steep cliffs from which beautiful "+
        "streams flow through the grove%^BOLD%^%^BLUE%^.%^RESET%^%^GREEN%^  This water warms the grove%^BOLD%^%^BLUE%^.\n");
        


}
string night_desc() {
  return (query_short() + "\n"+
  "%^BLUE%^At night%^CYAN%^, the elven grove is quite dark%^CYAN%^."+
  "%^BLUE%^  It is cool and %^CYAN%^mist%^BLUE%^ fills the area%^CYAN%^.%^BLUE%^  Many beautiful"+
  " and %^CYAN%^mystical plants%^BLUE%^ adorn the grove%^CYAN%^.%^BLUE%^  Several trees "+
  "cast shadows from the limited starlight and moonlight "+
  "that makes its way through the clouds%^CYAN%^.%^BLUE%^  "+
  "Everything appears quiet and peaceful%^CYAN%^.%^BLUE%^  "+
  "From the north%^CYAN%^,%^BLUE%^ sounds of %^CYAN%^crashing water"+
  " %^BLUE%^can be heard%^CYAN%^.%^BLUE%^  Streams of warm water "+
  "flow through the grove%^CYAN%^.\n");
}
string query_weather(){ return "%^BOLD%^%^WHITE%^A mist covers the area."; }
void reset(){
 ::reset();

 
}
