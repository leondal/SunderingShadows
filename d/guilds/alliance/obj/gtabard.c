//

#include <std.h>

inherit ARMOUR;

object owner;

void create(){
   ::create();
   set_name("key");
   set_id(({"tabard","white tabard" }));
   set_short("%^WHITE%^BOLD%^Tabard of the White Guard%^RESET%^GREEN%^");

   set_long(
@OLI
This is a white overgarment that is worn over armor and displays the 
crest of the army that the wearer owes alligence to.  This is pure 
white with a sign of two shaking gauntlets, the symbol of the Alliance 
of Light's White Guard.
OLI
   );
   set_type("clothing");
   set_limbs(({"torso"}));

   set_weight(1);
}

void set_owner(object ob) {
  owner = ob;
}

void init(){
    ::init();
    add_action("standdown", "standdown");
    add_action("makereport", "makereport");
    add_action("ceasefire", "ceasefire");

}

int standdown(string str) {
	if(ETO != owner) return 1;
	owner->stand_down(find_player(lower_case(str)));
	return 1;
}

int makereport(string str) {
	if(ETO != owner) return 1;
	owner->start_report();
	return 1;
}

int ceasefire(string str) {
	if(ETO != owner) return 1;
	owner->stop_attacking(find_player(lower_case(str)));
	return 1;
}
