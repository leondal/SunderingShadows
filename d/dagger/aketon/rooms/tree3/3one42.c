#include "/d/dagger/aketon/short.h"

inherit VAULT;

void create() {
   ::create();
   set_property("light",2);
   set_property("indoors",1);
   set_short("An elven home of Aketon");
   set_long("%^GREEN%^An elven home of Aketon%^RESET%^\n"+
   "This is a very luxurious bathing room. There is an enormous bath"+
   " tub along the entire south end of the room that is plated with"+
   " rose marble. There are expensive and exotic perfumes and soaps"+
   " surrounding the edges of the bath tub. On the west wall is a large"+
   " mirror with a matching marble counter in front of it as well as"+
   " a stool with a red velvet cushion. On the east is a wooden closet"+
   " that contains the wardrobe of a very rich elven female.");
   set_smell("default","The room smells of rich perfumes and soaps.");
   set_listen("default","The wind rustles through the leaves outside.");
   set_items(([
   ({"tub","bath tub"}) : "%^BOLD%^%^RED%^There is an enormous tub"+
   " that takes up the entire southern wall. It could probably hold"+
   " three people easily, yet is obviously designed for one. It is very"+
   " deep and has been plated with rose marble. There is a golden nozzle"+
   " and crystal handles that adjust the water flowing into the tub."+
   " It obviously operates by magic since there is no plumbing in the"+
   " room. Around the edges of the tub are several different soaps and"+
   " perfumes.",
   ({"soaps","perfumes"}) : "There are so many different perfumes and"+
   " soaps that it is almost impossible to sort through them all and"+
   " figure out what is what! For perfumes you recognize a rose one,"+
   " vanilla, and also gardenia. Some of the soaps are shaped like"+
   " small roses and also smell of rose, there are some sea shelled"+
   " shaped ones that smell misty, and some that smell of sandalwood,"+
   " orange, lavender, and many more.",
   "mirror" : "There is a large mirror on the west wall.",
   "stool" : "There is a stool in front of the mirror that is padded"+
   " with a thick red velvet cushion.",
   ({"closet","wooden closet"}) : "On the east is a wooden closet that"+
   " contains the wardrobe of a very rich elven female. The outside"+
   " of the closet is carved with a huge rose that takes up the entire"+
   " front.",
   "door" : "There is an oak door to the north that leads back to"+
   " the large entrance room.",
   ]));
   set_door("door",RPATH3+"3one40","north",0);
   set_exits( (["north":RPATH3+"3one40"]) );
}
