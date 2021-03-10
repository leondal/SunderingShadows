#include <std.h>
#include "../tormdefs.h"
#define AVA_D "/daemon/avatar_d.c"
inherit TOWN;

  //Taken straight from the one done in shadow.
void create(){
   ::create();
  set_short("Torm City Library");
   set_long(
@DESC
This is the newly commissioned Torm City Library.  There
are a few tables and desks just inside the door and there 
is a large wooden counter running the width of the room.
Behind the counter you see rows and rows of shelves filled 
with many scrolls. If the librarian is here, she may allow
you to do some research.
DESC
   );
   set_light(2);
   set_indoors(1);
   set_smell("default","You smell something that must be used to preserve the scrolls.");
   set_listen("default","It's a library, it's supposed to be quiet.");
   set_items(([
      "shelves":"They are filled with scrolls.",
      "scrolls":"These contain the background information on various adventurers of the realm."
   ]));
   set_exits(([
  "west":"/d/dagger/Torm/city/c133",
   ]));
}

void reset(){
   if(!present("librarian")) 
  new("/d/dagger/Torm/mon/librarian")->move(TO);
}

void init(){
   ::init();
   add_action("get_background","research");
//   add_action("set_background","submit");
}

int get_background(string str){
   string bkgrnd, avat;
   int isava, ispl;

  if(!present("erane"))
      return notify_fail("The librarian is not here to help you. You would never be able to find what you are looking for without help.\n");
   if(!str){
      write("%^MAGENTA%^Erane says: %^RESET%^Whose background do you want to research?");
      return 1;
   }

   str=lower_case(str);
   if(user_exists(str))
       ispl = 1;
   if(!ispl && AVA_D->is_persona(str))
       isava = 1;

   if(!ispl && !isava)
       return notify_fail("That person does not exist in this reality.\n");

   
   if(ispl){
       if(!file_exists("/d/save/background/"+str+".htm")){
          write("%^MAGENTA%^Erane says: %^RESET%^That person does not have a background on record yet.");
          return 1;
       }
       write("Erane sends a page off to look for the scroll.");
       write("The page returns quickly, and you are impressed with the organization.");
       write("%^MAGENTA%^Erane says: %^RESET%^Here is the information you requested.");
       write("Erane hands you a scroll and you move to one of the empty chairs to start reading.\n");
       write("%^BOLD%^"+capitalize(str)+"'s Background Information%^RESET%^\n");
       bkgrnd = "daemon/converter"->convertToInput(read_file("/d/save/background/"+str+".htm",6));
       TP->more(explode(bkgrnd,"\n"));
       return 1;
   }

   if(isava){
       avat = ((string *)AVA_D->query_avatar_of_persona(str))[0];
           if(!file_exists("/avatar/"+avat+"/"+str+".htm")){
           write("%^MAGENTA%^Erane says: %^RESET%^That person does not have a background on record yet.");
           return 1;
       }
       write("Erane sends a page off to look for the scroll.");
       write("The page returns quickly, and you are impressed with the organization.");
       write("%^MAGENTA%^Erane says: %^RESET%^Here is the information you requested.");
       write("Erane hands you a scroll and you move to one of the empty chairs to start reading.\n");
       write("%^BOLD%^"+capitalize(str)+"'s Background Information%^RESET%^\n");
       bkgrnd = "daemon/converter"->convertToInput(read_file("/avatar/"+avat+"/"+str+".htm",6));
       TP->more(explode(bkgrnd,"\n"));
       return 1;
   }
   return notify_fail("Error.  Talk to grendel.");
}
