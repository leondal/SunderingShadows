// This is the Second book on Druids
// Pator@ShadowGate
// Mar 6 1996

#include <std.h>
#include <druids.h>

inherit BOOK;

mapping filenames;

create()
{ int size;
  ::create();
  set_author("pator");
  set_id(({"book","newbie_book"}));
  set_name("Book for newbie Druids");
  set_short("Book for newbie Druids");
  set_long(
@PATOR
%^GREEN%^%^BOLD%^
 -=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-


	This is the Book for the newbie druid

	In this book you'll find all you wanna know 
	to start as a Druid within the ShadowGate realms.


 -=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-
PATOR
);  
  filenames = ([ 1 : "index.newbie", 2 : "C_mistletoe.newbie",
		 3 : "C_amulet.newbie", 4 : "C_reach_circle.newbie", 
5 : "C_circle_map.newbie", 6 : "C_spells.newbie" ]);
  set_pages(filenames);
  size = sizeof(keys(filenames));
  set_number(size);
  set_index(1);
  set_book_dir(DRUID_DIR+"docs/");
  set_book_title("Book for newbie Druids");
}

init()
{ 
  ::init();
  actions();
}
