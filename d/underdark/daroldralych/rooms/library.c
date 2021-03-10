#include <std.h>
#include "../defs.h"
#define AVA_D "/daemon/avatar_d.c"
inherit "/std/library.c";

void create(){ 
   ::create();
   set_public_library(1);
   set_deposit(20);
   set_library_name("daroldralych");
   set_property("light",-1);
   set_property("indoors",1);
   set_property("teleport proof",(25+roll_dice(1,20)));
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_name("Public library");
   set_short("%^BLUE%^Public library%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Public library%^RESET%^\n"
"%^BLUE%^This orderly room is actually larger than it first appears - at a second glance, you notice the many side-"
"sections and half-enclosed alcoves which greatly expand the seemingly restricted space here.  Shelves of %^ORANGE%^aged "
"t%^RED%^o%^ORANGE%^mes %^BLUE%^and %^WHITE%^parchment scrolls %^BLUE%^line the room, some along the walls and some "
"standing in neat lines.  You can see that the walls, where not covered in shelves of parchments, are bare and made of "
"%^BOLD%^%^BLACK%^dark st%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, and aside from the various shelves "
"there is only minimal furniture here - a handful of simple chairs, and what you could assume to be the librarian's desk, "
"all carved from fine %^RED%^zurk%^MAGENTA%^hw%^RED%^ood%^BLUE%^.  There are a few slaves scurrying to and fro arranging "
"and retrieving various documents.  A narrow doorway allows access to the street outside.  See %^RESET%^help library "
"%^BLUE%^for commands.%^RESET%^\n");
   set_smell("default","%^ORANGE%^The air carries the thick scent of %^WHITE%^ag%^ORANGE%^e%^WHITE%^d par%^ORANGE%^ch"
"%^WHITE%^ment%^ORANGE%^.");
   set_listen("default","%^GREEN%^It is particularly %^CYAN%^q%^GREEN%^ui%^CYAN%^et %^GREEN%^in here.");

   set_items(([
     ({"wall","walls","roof"}):"%^BLUE%^The walls and roof of this building are made of %^BOLD%^%^BLACK%^black st"
"%^RESET%^%^ORANGE%^on%^BOLD%^%^BLACK%^e%^RESET%^%^BLUE%^, a common sight in this city.  They are plain, but "
"immaculately clean, as is most else here.%^RESET%^",
     ({"shelves","books","parchments","scrolls"}):"%^BLUE%^The building is filled with shelves, placed against the walls "
"and in lines within the side alcoves.  They are all filled with an assortment of %^ORANGE%^boo%^RED%^k%^ORANGE%^s"
"%^BLUE%^ and %^WHITE%^parchment scrolls%^BLUE%^.%^RESET%^",
     "slaves":"%^BLUE%^Various goblin and kobold slaves scurry to and fro around the room, retrieving and rearranging "
"various %^WHITE%^scrolls %^BLUE%^and %^ORANGE%^b%^RED%^o%^ORANGE%^oks%^BLUE%^.  They are, however, surprisingly clean "
"compared to the rest of the slaves you've seen around the city, and their %^ORANGE%^a%^YELLOW%^g%^RESET%^%^ORANGE%^il"
"%^YELLOW%^e %^RESET%^%^BLUE%^nature seems never to show them taking a step wrong or mishandling an item.%^RESET%^",
   ]));
   set_exits(([
     "south":ROOMS"east2",
   ]));
}

void reset(){
   ::reset();
   if(!present("librarian")) {
       new(MON"zilvanna")->move(TO);
       tell_room(TO,"%^GREEN%^The librarian re-emerges from a side room, setting down a collection of books and parchment "
"upon her desk.%^RESET%^");
       return;
   }
   return;
}

void init(){
   ::init();
   add_action("get_background","research");
}

int get_background(string str){
   string bkgrnd, avat,name;
   int isava, ispl;
   if(!present("librarian"))
     return notify_fail("The librarian is not here to help you. You would never be able to find what you are "
"looking for without help.\n");
   if(!str){
     tell_room(TO, "%^RESET%^%^MAGENTA%^The librarian asks:%^RESET%^ Exactly who do you want to research?");
     return 1;
   }

   str=lower_case(str);
     if(!avatarp(TP)) {
       name = TP->realName(str);
       if (!stringp(name) || name == "") name = str;
       str = name;
   }
   if(user_exists(str)) ispl = 1;
   if(!ispl && AVA_D->is_persona(str)) isava = 1;
   if(!ispl && !isava) return notify_fail("That person does not exist in this reality.\n");
   
   if(ispl){
     if(!file_exists("/d/save/background/"+str+".htm")){
       tell_room(TO, "%^RESET%^%^MAGENTA%^The librarian says:%^RESET%^ That person does not have a background "
"on record here.");
       return 1;
     }
     tell_room(TO,"The librarian sends a slave off to look for the scroll.\n");
     write("The slave scurries away and returns quickly, and you are impressed with the organization.\n");
     write("The librarian hands you a scroll and you move to one of the empty chairs to start reading.\n");
     TP->force_me("pose sitting in a chair reading one of the library's scrolls.");

     bkgrnd = "daemon/converter"->convertToInput(read_file("/d/save/background/"+str+".htm",6));
     TP->more(explode(bkgrnd,"\n"));
     return 1;
   }

   if(isava){
     avat = ((string *)AVA_D->query_avatar_of_persona(str))[0];
     if(!file_exists("/avatar/"+avat+"/"+str+".htm")){
     tell_room(TO, "%^RESET%^%^MAGENTA%^The librarian says:%^RESET%^ That person does not have a background "
"on record here.");
     return 1;
   }
     tell_room(TO,"The librarian sends a slave off to look for the scroll.\n");
     write("The slave scurries away and returns quickly, and you are impressed with the organization.\n");
     write("The librarian hands you a scroll and you move to one of the empty chairs to start reading.\n");
     TP->force_me("pose sitting in a chair reading one of the library's scrolls.");

     bkgrnd = "daemon/converter"->convertToInput(read_file("/avatar/"+avat+"/"+str+".htm",6));
     TP->more(explode(bkgrnd,"\n"));
     return 1;
   }
   return notify_fail("Error.  Talk to Nienne (or do a bug report).\n");
}
