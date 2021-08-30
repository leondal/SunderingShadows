#include <std.h>
#include "../seneca.h"

inherit VAULT;

#define NUMBERS ({"1","2","3","4","5"})

int myprice;

void create(){
   ::create();
   set_terrain(WOOD_BUILDING);
   set_travel(PAVED_ROAD);
   set_indoors(1);
   set_light(3);
   set_name("Gnomeworks Tattoos, Seneca");
   set_short("%^BOLD%^%^RED%^Gnomeworks Tattoos, Seneca%^RESET%^");
   set_long("%^BOLD%^%^RED%^Gnomeworks Tattoos, Seneca%^RESET%^\n"+
	"Though the walls are made of wood, everything else in this shop "+
	"seems to have been crafted from metal and riveted together. "+
	"Narrow %^BOLD%^metal counters %^RESET%^enameled %^BOLD%^%^RED%^"+
	"crimson%^RESET%^ run down the eastern and western walls, and a "+
	"matching %^BOLD%^%^RED%^ledge %^RESET%^runs beneath them, "+
	"sticking out a bit further to allow the pint-sized artists "+
	"to perform their work on much larger clients. The countertops "+
	"are covered with neat rows of %^CYAN%^jars%^RESET%^ containing "+
	"%^BOLD%^pigments %^RESET%^in %^BOLD%^%^MAGENTA%^m%^YELLOW%^y%^BLACK%^r"+
	"%^CYAN%^i%^GREEN%^a%^RED%^d %^MAGENTA%^c%^BLUE%^o%^RESET%^"+
	"%^ORANGE%^l%^BOLD%^o%^RESET%^%^MAGENTA%^r%^BOLD%^s %^RESET%^"+
	"spread among cylinders that hold sharpened %^BOLD%^implements "+
	"%^RESET%^made of %^GREEN%^bamboo%^RESET%^, %^BOLD%^bone%^RESET%^"+
	", and %^CYAN%^steel%^RESET%^. Little %^ORANGE%^glazed "+
	"bowls %^RESET%^are mingled among the jars, providing "+
	"places for the artists to create new inks. Comfortable "+
	"chairs ingeniously designed to recline and bend in all sorts "+
	"of ways are made of %^BOLD%^%^BLACK%^padded leather %^RESET%^"+
	"stretched across %^BOLD%^steel frames%^RESET%^ and placed "+
	"beside the counters. Rows of %^CYAN%^mirrors %^RESET%^"+
	"run along the walls, attesting to the wealth of the shopowners "+
	"and allowing visitors to watch as tattoos are completed. "+
	"A large %^BOLD%^%^RED%^red-bordered sign %^RESET%^stands "+
	"on an %^BOLD%^easel%^RESET%^ displaying important information "+
	"about the tattoos.\n");
   set_smell("default","The fragrance of metals and dyes fills the air.");
   set_listen("default","Groans and occasional screams deafen the sound of the ocean.");
   set_items(([
	({"counter","counters","metal counters","metal counter"}) : 
	"%^BOLD%^%^WHITE%^Running the length of the eastern and "+
	"western walls are narrow metal counters.  Their tops "+
	"have been enameled %^RED%^red%^WHITE%^ while the "+
	"sides are left a shiny %^RESET%^s%^BOLD%^i%^RESET%^l"+
	"%^BOLD%^v%^RESET%^e%^BOLD%^r.  The counter tops have "+
	"been scattered with various supplies.%^RESET%^",
	({"ledge","ledges"}) : "%^BOLD%^%^RED%^Looking like "+
	"nothing so much as an enameled red metal box, each "+
	"ledge runs along the wall beneath the counter, "+
	"sticking out just far enough to allow the gnomish "+
	"tattoo artists space to work on their larger patrons.%^RESET%^",
	({"jars","jar","pigment","pigments"}) : "%^RESET%^%^CYAN%^"+
	"Small %^BOLD%^glass jars %^RESET%^%^CYAN%^are "+
	"spread neatly along the countertops, each jar holding "+
	"a different %^BOLD%^%^MAGENTA%^c%^YELLOW%^o%^RED%^l"+
	"%^GREEN%^o%^BLUE%^r %^RESET%^%^CYAN%^of ink.  The "+
	"jars have all been stoppered, ensuring that the inks "+
	"stay fresh and vibrant.%^RESET%^",
	({"cylinders","cylinder","implements","bamboo","bone","steel"}) :
	"%^BOLD%^Needles %^RESET%^made of different sizes and "+
	"cut at different angles have been crafted from "+
	"bamboo, bone, and steel.  They are carefully "+
	"arranged in cylinders with the points up, always "+
	"within easy reach of the tattoo artists.",
	({"bowls","glazed bowls"}) : "%^ORANGE%^Ceramic bowls "+
	"that have been glazed are spaced along the counter, "+
	"giving the artists places to mix their inks.  It "+
	"seems the materials within the jars can sometimes "+
	"be poured into these and mixed, creating new colors.%^RESET%^",
	({"chair","chairs","reclining chairs","leather chairs"}) :
	"Each of the chairs is made from a %^BOLD%^steel "+
	"frame %^RESET%^of rounded tubes and an ingenious "+
	"system of levers, pulleys, latches, and all other "+
	"manner of gnomish engineering that allow the chairs "+
	"to recline and bend in countless ways.  The frames "+
	"have been fitted with %^BOLD%^%^BLACK%^padded black "+
	"leather %^RESET%^to provide comfortable seating to the "+
	"customers of %^BOLD%^%^RED%^Gnomeworks Tattoos%^RESET%^.",
	({"mirror","mirrors","rows of mirrors"}) : "Running "+
	"above the counters are rows of %^CYAN%^mirrors%^RESET%^ "+
	"that have been attached directly to the wall.  The "+
	"mirrors reveal minor imperfections, but they allow "+
	"for a wonderful view of the artist at work.",
	({"sign","red sign","red-bordered sign","easel"}) : 
	"Prominently displayed near the entrance on a "+
	"%^BOLD%^metal easel%^RESET%^ is a %^BOLD%^%^RED%^"+
	"red-bordered sign %^RESET%^with %^BOLD%^%^RED%^red "+
	"%^RESET%^and %^BOLD%^white %^RESET%^lettering that "+
	"you could read."
	]));
	set_exits(([
"north" : ROOMS"viento57"
	]));
	set_door("red door","/d/attaya/newseneca/rooms/viento57","north",0);
	set_door_description("red door","%^BOLD%^%^RED%^The wooden "+
	"to the north has been painted a fiery red and has a "+
	"%^RESET%^steel plate %^BOLD%^%^RED%^near the bottom, "+
	"possibly for protection - or quite possibly because "+
	"the shopowners seem to really like metal.%^RESET%^");
	}

void reset(){
   ::reset();
   if(!present("tattoo artist")){
if(!random(2)){
   find_object_or_load(MON"elbert")->move(TO);
}else{
   find_object_or_load(MON"pilman")->move(TO);
}
   }
}

void init() {
  ::init();
  add_action("read_em","read");
  add_action("order_em","order");
  add_action("erase_em","erase");
}

int read_em(string str){
   if(!str) return 0;
   if(str == "sign" || str == "list"){
tell_object(TP,
@CIRCE
%^BOLD%^%^RED%^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-

  %^BOLD%^%^WHITE%^Welcome to Gnomeworks Tattoos!

%^BOLD%^%^WHITE%^The Home for All Your Tattoo Needs!

%^BOLD%^%^RED%^If you are interested in a tattoo,
    %^BOLD%^%^RED%^feel free to %^WHITE%^<%^RED%^order%^WHITE%^>%^RED%^ one.

%^WHITE%^     If, for some reason, you have decided
    %^BOLD%^you no longer like your tattoo, we will
    %^BOLD%^%^RED%^<%^WHITE%^erase%^RED%^>%^WHITE%^ it for a fee.

%^BOLD%^%^RED%^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-
CIRCE
);
tell_object(TP,
@CIRCE
     %^BOLD%^%^WHITE%^ Price List

\tTiny Tattoo\t%^YELLOW%^10,000 gold
%^BOLD%^%^WHITE%^\tSmall Tattoo\t%^YELLOW%^15,000 gold
%^BOLD%^%^WHITE%^\tMedium Tattoo\t%^YELLOW%^20,000 gold
%^BOLD%^%^WHITE%^\tLarge Tattoo\t%^YELLOW%^25,000 gold
%^BOLD%^%^WHITE%^\tHuge Tattoo\t%^YELLOW%^30,000 gold

     %^BOLD%^%^WHITE%^%^B_RED%^Tattoo Removals are Three Times the%^RESET%^
     %^BOLD%^%^WHITE%^%^B_RED%^Original Purchase Price%^RESET%^

%^RESET%^%^BOLD%^%^RED%^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-^-
CIRCE
);
if(!TP->query_invis()){
   tell_room(TO,""+TPQCN+" reads over the "+str+".",TP);
}
return 1;
   }
}

int erase_em(string str){
object mytat;
   if(!mytat = present(str,TP)){
tell_object(TP,"You do not have a "+str+"!");
return 1;
   }
   if(!mytat->is_tattoo()){
tell_object(TP,"You may remove only tattoos here!");
return 1;
   }
   tell_object(TP,""+present("tattoo artist")->QCN+" motions "+
"you to a seat and begins work removing your tattoo.");
   tell_room(TO,""+TPQCN+" takes a seat, and "+present("tattoo artist")->QCN+" "+
"begins removing a tattoo from "+TP->QO+".",TP);
   TP->set_paralyzed(60,"You cannot move while the tattoo is being removed.");
   call_out("done",30,mytat);
   return 1;
}

void done(object mytat){
   if(!objectp(mytat)){
tell_object(TP,"Hmm...there seems to be a problem.");
return;
   }
   tell_object(TP,""+present("tattoo artist")->QCN+" finishes "+
"removing your tattoo, leaving you feeling somewhat disoriented.");
   tell_room(TO,""+present("tattoo artist")->QCN+" finishes "+
"removing "+TPQCN+"'s tattoo.",TP);
   mytat->remove();
   return;
}

int order_em(string str){
object ob;
string file;
int i;
   if(!present("tattoo artist")){
tell_object(TP,"The shopkeeper is not here to take your order!");
return 1;
   }
   if(!str || str != "tattoo"){
tell_object(TP,"You may order tattoos here.  Please "+
   "try <order tattoo>.");
return 1;
   }
   tell_object(TP,"Enter a one-word file name for your tattoo.");
   tell_object(TP,"Do not use spaces.  For example, a good file name "+
"would be 'purpledragon'.");
   input_to("myfile");
   return 1;
}

void myfile(string str){
string file,myname;
   str=replace_string(str," ","_");
   str=replace_string(str,".","");
   str=replace_string(str,"\\","");
   str=replace_string(str,"/","");
   str=replace_string(str,"*","");
   str=replace_string(str,"?","");
   str=replace_string(str,"~","");
   myname = TP->query_name();
   myname += "_";
   myname += str;
   file = "/d/save/tattoos/"+myname+".c";
   if(file_exists(file)){
tell_object(TP,"That file already exists!  Try ordering "+
   "again with a different file name.");
return 1;
   }
   tell_object(TP,"What size tattoo would you like to make?  Enter "+
"a number 1-5.");
   write("%^BOLD%^%^RED%^------------------------- %^WHITE%^Sizes %^RED%^-------------------------");
   write("\n"
"\t%^BOLD%^1 %^RESET%^- %^BOLD%^Tiny %^RESET%^- one inch\n"
"\t%^BOLD%^2 %^RESET%^- %^BOLD%^Small%^RESET%^ - two inches\n"
"\t%^BOLD%^3 %^RESET%^- %^BOLD%^Medium%^RESET%^ - three to four inches\n"
"\t%^BOLD%^4 %^RESET%^- %^BOLD%^Large%^RESET%^ - five to six inches\n"
"\t%^BOLD%^5 %^RESET%^- %^BOLD%^Huge%^RESET%^- seven inches and larger\n"
   );
   input_to("mytattoo",0,file);
   return 1;
}

void mytattoo(string str,string file){
string mysize;
object ob;
   if(!str){
tell_object(TP,"You have failed to enter a size.  "+
   "Try to order a tattoo again.");
return 1;
   }
   if(member_array(str,NUMBERS) == -1){
write("%^BOLD%^%^RED%^That is not a valid choice!\n");
tell_object(TP,"That is not a valid choice.  Please try "+
   "to order your tattoo again.");
return 1;
   }
   switch(str){
case "1":  myprice = 10000; break;
case "2":  myprice = 15000; break;
case "3":  myprice = 20000; break;
case "4":  myprice = 25000; break;
case "5":  myprice = 30000; break;
default: 
   tell_object(TP,"That is not a valid choice.  Please try "+
"to order your tattoo again.");
   break;
   }
   tell_object(TP,"%^RESET%^%^MAGENTA%^"+present("tattoo artist")->query_cap_name()+" says%^RESET%^: Your tattoo will cost "+myprice+" gold.\n");
   if(!TP->query_funds("gold",myprice)){
tell_room(TO,"%^MAGENTA%^"+present("tattoo artist")->query_cap_name()+" says%^RESET%^: "+
   "I'm sorry, but you don't have enough money.  It "+
   "will cost you "+myprice+" gold.");
return 1;
   }
   TP->use_funds("gold",myprice);
   tell_object(TP,"%^BOLD%^"+present("tattoo artist")->query_cap_name()+" takes your %^YELLOW%^money %^WHITE%^and sets to work on your tattoo.%^RESET%^\n\n");
   tell_room(TO,""+TPQCN+" places an order for a tattoo and takes a seat in one of the chairs.",TP);
   ob = new("/d/attaya/newseneca/obj/tattoos/tattoo_base"+str+"");
   ob->set_file_name(file);
   ob->set_name("tattoo");
   ob->move(TP);
   return 1;
}
