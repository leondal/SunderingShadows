#include <std.h>
#include <daemons.h>
#include "../juran.h"
inherit MONSTER;

int FLAG,dlevel,num,timer;
object ob;

void do_check();

create() {
    	::create();
    	set_name("kobold");
    	set_id(({"monster","kobold"}));
    	set_short("kobold");
   	set_wimpy(15);
    	set_long("This creature stands no more than three feet tall and "+
    		"has scaly skin that ranges from dark, rusty brown to a rusty "+
    		"black.  The kobold's eyes glow with a red spark, two small "+
    		"horns protrude from his forehead and he has a rat-like tail.");
    	set_body_type("humanoid");
    	dlevel = random(4) + 3;
    	set_hd(dlevel,6);
    	set_class("fighter");
    	set_mlevel("fighter", dlevel);
    	add_search_path("/cmds/fighter");
      set_wielding_limbs(({"right hand","left hand"}));
    	set_stats("intelligence",9);
    	set_stats("wisdom",9);
    	set_stats("strength",14);
    	set_stats("charisma",3);
    	set_stats("dexterity",18);
    	set_stats("constitution",12);
    	set_alignment(9);
    	set_race("kobold");
    	set_overall_ac(5);
    	set_exp(dlevel*20);
    	set_max_hp((random(40)+(dlevel*6)));
    	set_hp(query_max_hp());
    	set_achats(3,({
		"Kobold snarls and spits at you.",
		"Kobold circles you warily looking for an opening.",
		"Kobold tries to bite your ankle.",
		"Kobold gets behind you and tries to stick you with his sword.",
		"Kobold dodges your swing.",
    	}),0);
    	set_emotes(3,({
		"Kobold watches everything closely.",
        	"Kobold keeps his eye on you.",
		"Kobold barks some