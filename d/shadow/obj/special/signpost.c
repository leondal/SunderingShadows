//signpost.c
// changed to get rid of the conflict with actual exits using "enter"
/* we should probably get rid of the read action too so it doesn't mess with other
   signs in the room but since we're making most signs something you read I wasn't 
   sure yet if that was a good idea  *Styx*  11/18/04
*/


#include <std.h>

inherit OBJECT;

object dest;
string player,place;

string trainer_short()
{
    if(!objectp(TP)) return "";
    if(!stringp(player)) return "";
    if((string)TP->query_name() != lower_case(player) && !avatarp(TP)) return "";
    return "Sign post";
}

string trainer_long()
{
    if(!objectp(TP)) return "";
    if(!stringp(player)) return "";
    if((string)TP->query_name() != lower_case(player) && !avatarp(TP)) return "";
    return "This signpost marks the entrance to the camp of someone's trainer.  "
	"If it is for yours, you will be able to %^BOLD%^<camp> %^RESET%^here "
	"and visit your trainer.";
}
string query_player(){
  return player;
}

void create(){
	::create();
	
	set_name("signpost");
	set_id(({"sign","sign post","signpost","post"}));
	set_short((:TO, "trainer_short":));//"Sign post");
    set_long((:TO, "trainer_long":));
	set_weight(100000);
	set_property("no animate",1);
}

void init(){
	::init();
	
/*	add_action("enter","enter");
quick fix to avoid the conflict with exits using "enter" since this causes follow to break and generally creates confusion when there is a real exit called enter in the room with one of these.  *Styx*
*/
    add_action("camp", "camp");
	add_action("read","read");
}

//int enter(string str){
int camp(string str){
	if(str) return 0;
	
	if(!objectp(dest)) dest = new(place);
	
	dest->set_player(player);
	dest->add_exit(base_name(ETO),"out");
    if((string)TP->query_name() != lower_case(player)) return 0;
    if(!avatarp(TP) && (string)TP->query_name() != lower_case(player))
    {
      write("The trainer is busy preparing for "+capitalize(player)+"'s visit.");
      return 1;
    }
	TP->move_player(dest);
	return 1;
}

set_player(string str){player = str;}

set_dest(string str){place = str;}

int read(string str)
{
	if(!id(str)) return 0;
    if(!objectp(TP)) return 0;
    if((string)TP->query_name() != lower_case(player)) return 0;
	write("If the trainer is yours you will be able to %^BOLD%^<camp> %^RESET%^here.");
	return 1;
}
