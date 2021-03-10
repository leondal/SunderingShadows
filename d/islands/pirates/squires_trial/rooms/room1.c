#include <std.h>
#include "../squires_trial.h"

inherit BASEROOM;
void create(){
  ::create();
  set_name("Squire's Trial Room 1");
  set_short("A carved chamber");
  set_long( 
            "The collapsed stone wall allows you passage into an octagonal chamber.\n" +
            (string) TO->stonedesc() +
            "  At" +
            " each corner of the room, a " +
            "%^RED%^t%^BOLD%^%^YELLOW%^o%^RED%^r%^YELLOW%^c%^RESET%^%^RED%^h%^WHITE%^" +
            " is mounted in an iron bracket," +
            " burning with flames which do not seem to consume.  Standing in" +
            " the center of the room is a square %^BOLD%^%^WHITE%^monument" +
            " %^RESET%^%^WHITE%^of stone, the top" +
            " angled down toward the entryway so that the writing engraved" +
            " on it is plain to see.  Behind the monument is a large stone" +
            " %^BOLD%^%^WHITE%^tomb%^RESET%^%^WHITE%^." +
            "  The northwest and southeast walls are home to passageways.");
          
  add_item(
          "monument" , ({"This monument is a square if viewed from above," +
          " about four and a half feet tall.  The top plane is angled " +
          "toward the room's entryway, and skillful engravings depict " +
          "testament that you could try to read.  More chiseled writing " +
          "has been engraved below, on the front face of the monument.",
          "\n\n%^RESET%^%^CYAN%^Squire,\n\n" +
          "That you have arrived here indicates that you have proven" +
          " your dedication.  As well, permission has been given for" +
          " your trial to proceed.  Within, should you succeed, you will" +
          " find the means to prove your worth upon return to the" +
          " Order.\n\n" +
          "Know that it was my wish to be placed here when I found" +
          " my final rest, and the words before you are written to" +
          " ensure your understanding.  This place was my life's" +
          " work in service to the Order.\n\n" +
          "Embark with confidence and honor, for few make it this far.\n\n" +
          "Sir Segnor Tamalitrel\n",
          "common"
           }));
  add_item(
            "tomb" , "The tomb is of the same stone as the rest of" +
            " the chamber, grey with black veins, giving a dignified " +
            "appearance to the perfect carving.  The bottom portion of the" +
            " tomb seems to have been carved from the floor itself, and " +
            "only a faint seam betrays the lid as not being one piece with" +
            " the rest.  No writing is found, the only decoration being" +
            " a massive, raised image of a six foot sword, around which " +
            "the flat top was carved.");
            
  add_item(({"torch","torches"}),
          "The %^RED%^t%^BOLD%^%^YELLOW%^o%^RED%^rc%^YELLOW%^he%^RESET%^" +
      "%^RED%^s%^WHITE%^ burn intensely, but don't seem to consume their fuel.");
  set_property("light",4);
  
  set_search( "default","The room is free of any obstructions that" +
                        " would hide anything.");
  set_search( "tomb","The tomb is flawless and sealed shut.");
  set_search( "monument","This monument is perfectly smooth, hiding nothing.");
  
  set_exits(([
            "northwest" : SQUIREROOMS+"room2",
            "southeast" : CAVES+"cave13"
  ]));
}          


