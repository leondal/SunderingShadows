#include <std.h>

#define PAGES ({"page_1","page_2","page_3","page_4","page_5","page_6","page_7","page_8", "page_9"})

inherit OBJECT;

void create(){
   int j;
   string str;
   ::create();
   j=random(sizeof(PAGES));
   str= PAGES[j];
   set_name("journal page");
   set_long("This appears to be "+str+" from a journal.  It's on fine parchment that's almost as durable as good cloth and has stood up to the elements amazingly well.  It's written in a beautiful flowing script, most likely by an elven adventurer.  You might learn something if you read it.");
   set_lore("The pages of this journal were taken from a wandering "+
      "elf who lost his way.  No one yet knows his fate, and you "+
      "have been unable to learn anything more, though you do know "+
      "that at least one elf was sent to look for him.");
   set_property("lore difficulty",1);
   set_short(str+" from a journal");
   set_property("pagex", str);
   set_id(({"page",str,capitalize(str)}));
   set_weight(1);
   set_value(0);
}

void init(){
   	object ob;
   	::init();
   	add_action("read_func","read");
	if ( (present(TO->query_property("pagex")+" 2",ETO)) && living(ETO) ){
		call_out("dest_dup",1,TP);
	}
}

int read_func(string str2){
   if(!str2) return notify_fail("Read what?\n");
   if( (str2 == "page") || (str2 == "journal") ) {
   		write("Read page_1 or page_2 or which page?");
   		return 1;
   	}
   if(str2 == query_property("pagex")) { 
   		TP->more("/d/newbie/rooms/forest/stuff/"+TO->query_property("pagex")+"");
	   	return 1;
   }
}

void dest_dup(){
    if (present(TO->query_property("pagex")+" 2"),ETO){
       	tell_object(ETO,"The piece of paper falls apart in your hands.");
     	tell_room(environment(ETO),"The piece of paper falls apart in "+ETO->query_cap_name()+"'s hand.",ETO);
		TO->remove();
	}
}