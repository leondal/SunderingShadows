//Updated with tp proof querying - Octothorpe 12/15/09
//added other IDs 9/7/03 - Circe
#include <std.h>
#include "/d/dagger/drow/temple/short.h"
inherit OBJECT;
void init() {
    ::init();
    add_action("dive_func","dive");
}
void create() {
    ::create();
   set_id(({"well","well of worlds","well of many worlds","fabric","piece of fabric","odd piece of fabric"}));
    set_name("Well of Many Worlds");
   set_obvious_short("An odd piece of fabric");
    set_short(
	"%^RED%^Well of many "
	"%^MAGENTA%^w"
	"%^CYAN%^o"
	"%^BLUE%^r"
	"%^GREEN%^l"
	"%^RESET%^d"
	"%^YELLOW%^s%^RESET%^"
);
    set_long(
	"%^RED%^This paradox of space slips in swirling colours and shapes."
	"It resembles a silk like piece of cloth and is known within "
   "legend of the elders to allow a person to dive into its inner "
	"folds within dimensional time. Upon "
   "diving into it, one will exist within its "
	"sub-space while retaining the fabric of which it is composed of. "
	"Only two things are known about it...one, it may allow a person "
	"to travel through times and dimensions while remaining fluid "
	"within reality. The second known fact is that it is very "
	"dangerous to attempt to enter back into the well "
   "while one is existing inside its "
	"sub-space."
	"%^RESET%^"
);
    set_weight(5);
    set_value(5000);
}
int dive_func(string str) {
    if(!str) {
        notify_fail("Dive where?\n");
	return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }

    if(str != "well") {
        notify_fail("Dive where?\n");
	return 0;
    }
    if((int)TP->query_level() < 15) {
	notify_fail("You may not enter the well!\n");
        return 0;
    }
    if(ETP->query_property("no teleport")){
      return notify_fail("Magical forces prevent you from doing that.\n");
    write("%^RED%^You %^BLUE%^DIVE%^RED%^ head first into the well!"
	"%^RESET%^");
	}
	if(ETP->query_property("teleport proof")){
	   if((int)ETP->query_property("teleport proof") > (random(10)+60)){
          notify_fail("Magical forces prevent you from doing that.\n");
          write("%^RED%^You %^BLUE%^DIVE%^RED%^ head first into the well!"
	"%^RESET%^");
	   return 0;
       }
	}   
    say(
	"%^RED%^"+TPQCN+" %^BLUE%^VANISHES%^RED%^ into a small piece "
	"of cloth!%^RESET%^"
    ,TP);
    TP->move_player(RPATH "well.c");
    if(random(10) < 5) {
        write("%^BLUE%^The well blinks out of existence!%^RESET%^");
	TO->remove();
    }
    return 1;
}
