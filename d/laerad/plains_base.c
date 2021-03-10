//Coded by Bane//
#include <std.h>
inherit ROOM;

void create(){
    ::create();
    set_name("Gods Plains");
    set_short("%^BOLD%^%^BLACK%^The Gods Plains%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^You stand on a charred plain.  Blades of grass "
	"struggle to push their way up from the blackened earth.  Dark %^RESET%^clouds "
	"%^BOLD%^%^BLACK%^roil angrily in the sky above the impassable mountains that form the border of "
	"the plains to the north.  A fierce wind "
	"dances and cackles around you.  Desolation is all that is more abundant than the "
	"%^RED%^blood stains %^BLACK%^on the parched earth and the %^WHITE%^"
	"bones %^BLACK%^that have been picked clean by vultures.  Perhaps the "
	"rumors that the Gods themselves once waged a war here that caused the "
	"desolation and destruction are true.  Regardless of the cause, the "+
	"curse upon this land must truly be terrible.\n");
    set_terrain(SCRUB_LANDS);
    set_travel(FOOT_PATH);
    set_climate("desert");
    set_property("indoors",0);
    set_property("light",2);
    set_property("wild magic",5);
    if(random(5))
	set_property("no sticks", 1);
    set_smell("default","A bitter wind stings your face.");
    set_listen("default","You hear the screeching of %^BOLD%^%^BLACK%^vultures %^RESET%^%^GREEN%^circling above.");
    set_post_exit_functions( ({ "east", "west" }), ({ "blast_em", "blast_em" }) );
}

void blast_em() {
  if(!random(10)) {
     if(member_array("laeradmon", TP->query_id()) != -1)  
	return;
     if(TP->query_true_invis())  
	return;
     if(!random(10)) {
        tell_object(TP, "%^ORANGE%^A crack opens in the ground below you!\n"
	  "%^YELLOW%^An acidic, sulfurous jet of steam spews up and burns you!");
        tell_room(TO, "%^YELLOW%^An acidic, sulfurous jet of steam spews up and burns "+TPQCN+"!", TP);
        TP->do_damage(TP->return_target_limb(),roll_dice(5,5));     
        TP->add_attacker(TO);
        TP->continue_attack();
        if(objectp(TP))    TP->remove_attacker(TO);
        return;
     }
     if(!random(3)){
        tell_room(TO, "%^ORANGE%^A crack opens in the ground, and an acidic, sulfurous jet of steam spews up, barely missing you!\n");
     }
   }
}
/*    
string ldesc(string str) {
   return("%^BOLD%^%^BLACK%^You stand on a charred plain.  Blades of grass "
	"struggle to push their way up from the blackened earth.  Dark %^RESET%^clouds "
	"%^BOLD%^%^BLACK%^roil angrily in the sky above the impassable mountains that form the border of "
	"the plains to the north.  A fierce wind "
	"dances and cackles around you.  Desolation is all that is more abundant than the "
	"%^RED%^blood stains %^BLACK%^on the parched earth and the %^WHITE%^"
	"bones %^BLACK%^that have been picked clean by vultures.  Perhaps the "
	"rumors that the Gods themselves once waged a war here that caused the "
	"desolation and destruction are true.  Regardless of the cause, the "+
	"curse upon this land must truly be terrible.\n"
   );
}
*/

void reset(){
   ::reset();
   if(!present("wild_gen") && base_name(TO) != "/d/laerad/plains_base.c"){
      new("/d/laerad/mon/wild_gen.c")->move(TO);
   }
}
