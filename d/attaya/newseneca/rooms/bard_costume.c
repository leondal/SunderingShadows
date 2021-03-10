//bard_costume.c - for new Seneca 12/20/07
//by ~Circe~
#include <std.h>
#include "../seneca.h"

inherit VAULT;

void create(){
   ::create();
   set_property("indoors",1);  
   set_property("light",0); 
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_name("Dreamland Costumes, Seneca");    
   set_short("%^BOLD%^%^CYAN%^Dreamland Costumes, Seneca%^RESET%^");
/*
   set_long("%^BOLD%^%^CYAN%^Dreamland Costumes, Seneca%^RESET%^\n"+
      "A sea of %^BOLD%^metal racks %^RESET%^displaying countless "+
      "%^CYAN%^costumes %^RESET%^of varying types crowd this small "+
      "shop, which seems equipped to turn anyone into nearly any "+
      "creature the imagination can conceive.  Each of the walls is "+
      "painted a different color and has been decorated with "+
      "stencils.  The northern wall is a deep %^MAGENTA%^violet "+
      "%^RESET%^with %^BOLD%^silver stars%^RESET%^ and %^YELLOW%^"+
      "golden swirls%^RESET%^, while the eastern wall is a %^GREEN%^"+
      "verdant green %^RESET%^with a few stenciled %^ORANGE%^bronze "+
      "leaves%^RESET%^.  The southern wall is %^RED%^maroon %^RESET%^"+
      "and decorated with images of %^ORANGE%^lions %^RESET%^slinking "+
      "through %^GREEN%^grasslands%^RESET%^.  A decorative border of "+
      "%^BOLD%^%^GREEN%^c%^MAGENTA%^o%^YELLOW%^l%^CYAN%^o%^RED%^r"+
      "%^BLUE%^f%^MAGENTA%^u%^YELLOW%^l %^RESET%^flowers surrounds "+
      "the archway in the western wall, which has been painted %^BOLD%^"+
      "white%^RESET%^.  A %^CYAN%^glass "+
      "case %^RESET%^near the northern end of the room is filled "+
      "with a wide array of %^MAGENTA%^make up %^RESET%^to create "+
      "just the right look, while the entire eastern wall has been "+
      "covered in a display of %^YELLOW%^m%^GREEN%^a%^RED%^s"+
      "%^CYAN%^k%^MAGENTA%^s%^RESET%^.  The %^ORANGE%^archway "+
      "%^RESET%^set within the western wall leads to the grand "+
      "%^BOLD%^marble entryhall %^RESET%^of the %^BOLD%^Bard "+
      "Academy%^RESET%^.\n");
Return to this description when the bard academy is ready to open.
*/
   set_long("%^BOLD%^%^CYAN%^Dreamland Costumes, Seneca%^RESET%^\n"+
      "A sea of %^BOLD%^metal racks %^RESET%^displaying countless "+
      "%^CYAN%^costumes %^RESET%^of varying types crowd this small "+
      "shop, which seems equipped to turn anyone into nearly any "+
      "creature the imagination can conceive.  Each of the walls is "+
      "painted a different color and has been decorated with "+
      "stencils.  The northern wall is a deep %^MAGENTA%^violet "+
      "%^RESET%^with %^BOLD%^silver stars%^RESET%^ and %^YELLOW%^"+
      "golden swirls%^RESET%^, while the eastern wall is a %^GREEN%^"+
      "verdant green %^RESET%^with a few stenciled %^ORANGE%^bronze "+
      "leaves%^RESET%^.  The southern wall is %^RED%^maroon %^RESET%^"+
      "and decorated with images of %^ORANGE%^lions %^RESET%^slinking "+
      "through %^GREEN%^grasslands%^RESET%^.  A decorative border of "+
      "%^BOLD%^%^GREEN%^c%^MAGENTA%^o%^YELLOW%^l%^CYAN%^o%^RED%^r"+
      "%^BLUE%^f%^MAGENTA%^u%^YELLOW%^l %^RESET%^flowers surrounds "+
      "the archway in the western wall, which has been painted %^BOLD%^"+
      "white%^RESET%^.  A %^CYAN%^glass "+
      "case %^RESET%^near the northern end of the room is filled "+
      "with a wide array of %^MAGENTA%^make up %^RESET%^to create "+
      "just the right look, while the entire eastern wall has been "+
      "covered in a display of %^YELLOW%^m%^GREEN%^a%^RED%^s"+
      "%^CYAN%^k%^MAGENTA%^s%^RESET%^.  The %^ORANGE%^archway "+
      "%^RESET%^set within the western wall leads to the grand "+
      "%^BOLD%^marble entryhall %^RESET%^of the %^BOLD%^Bard "+
      "Academy%^RESET%^, but it is currently closed off with a "+
      "simple %^ORANGE%^wooden panel%^RESET%^.\n");
   set_smell("default","The clean scent of the ocean rises on the breeze.");
   if(query_night() == 1){
      set_listen("default","You can faintly hear the crashing of "+
         "waves on the shore in the peace of night.");
   }else{
      set_listen("default","The faint humming of a busy day in Seneca can be heard.");
   }
   set_items(([
      ({"racks","metal racks","costumes"}) : "The metal racks are "+
         "covered with slender wooden hangers that hold costumes "+
         "in an array to dizzy the mind.",
      ({"case","glass case","make up"}) : "The %^CYAN%^glass case "+
         "%^RESET%^at the northern end of the room seems to serve "+
         "a dual purpose.  First, the shopkeeper tends to conduct "+
         "business from behind it, but it's most important role is "+
         "as the housing point for all the %^MAGENTA%^make up %^RESET%^"+
         "for sale here.  You see rows of %^BOLD%^%^MAGENTA%^rouge"+
         "%^RESET%^, cakes of %^BOLD%^powder%^RESET%^, tubes of "+
         "%^MAGENTA%^paint%^RESET%^, and countless other little "+
         "tools to help an actor become his character.",
      ({"masks","mask display","display","display of masks"}) : 
         "Rows of %^ORANGE%^wooden rods %^RESET%^set at intervals "+
         "with %^ORANGE%^pegs %^RESET%^support different styles of "+
         "%^YELLOW%^m%^GREEN%^a%^RED%^s%^CYAN%^k%^MAGENTA%^s%^RESET%^ "+
         "along the eastern wall.  Relatively cheap %^CYAN%^feathered "+
         "%^RESET%^constructions rest alongside much more extravagant "+
         "%^BOLD%^porcelain masks %^RESET%^in a variety of styles.",
      ({"archway","arch"}) : "The pointed archway in the western wall "+
         "reveals the smooth %^BOLD%^marble floors %^RESET%^of the "+
         "entryhall of the %^BOLD%^Bard Academy%^RESET%^.  The "+
         "archway is bounded by a thick border of %^BOLD%^"+
         "%^GREEN%^c%^MAGENTA%^o%^YELLOW%^l%^CYAN%^o%^RED%^r"+
         "%^BLUE%^f%^MAGENTA%^u%^YELLOW%^l %^RESET%^flowers that "+
         "has been stenciled on to the white walls."
   ]));
   set_door("costume door","/d/attaya/newseneca/rooms/viento52","south",0);
   set_door_description("costume door","This side of the door to the south "+
      "is varnished oak set with a small brass handle.");
   set_exits(([
      "south" : ROOMS"viento50",
//      "west" : ROOMS"bard_entry"
   ]));
}

void reset(){
   ::reset();
   if(!present("costume_designer"))
      find_object_or_load(MON"costume_designer")->move(TO);
}
