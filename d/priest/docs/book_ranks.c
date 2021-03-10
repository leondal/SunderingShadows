// This is the Second book on Druids
// Pator@ShadowGate
// Mar 6 1996

#include <std.h>
#include <druids.h>

inherit BOOK;
inherit ABILITIES_DIR+"dlevel.c";

mapping filenames;

create()
{ int size;
  ::create();
  set_author("pator");
  set_id(({"book","rank_book"}));
  set_name("Book on the Druidic ranks");
  set_short("Book on Druidic ranks");
  set_long(
@PATOR
%^GREEN%^%^BOLD%^
 -=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-


	    This is the Book on the Druidic Ranks

        All you need to know about the ranks in the
        Druidic class can be found in here

 -=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-=0*0=-
PATOR
);  
  filenames = ([ 1 : "C_rankindex.help", 2 : "C_druidmaster.help",
		 3 : "C_arcanedruid.help", 4 : "C_circledruid.help", 
                 5 : "C_herbaldruid.help", 6 : "C_hierophant.help",  
                 7 : "C_druid.help" ]);
  set_pages(filenames);
  size = sizeof(keys(filenames));
  set_number(size);
  set_index(1);
  set_book_dir(DRUID_DIR+"docs/");
  set_book_title("Book on the druidic ranks");
}

init()
{ 
  ::init();
  if (RANKING[dlevel(this_player())] >= 2)
    { actions(); }
  else { destruct(this_object()); }
}
