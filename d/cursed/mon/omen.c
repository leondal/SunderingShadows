#include "/d/shadow/mon/melnmarn.h";
inherit MONSTER;

create()
{
	::create();
		set_name("Omen");
		set_id( ({"omen", "dog", "mutt"}) );
		set_race("dog");
		set_body_type("quadruped");
		set_size(1);
		set_gender("male");
                set_class("fighter");
		set_short("Ore's pet guard dog, a mutt named Omen!");
		set_long(
@STOP
Omen is a drooling, butt ugly mutt.
You can only wonder if he is as dumb
as he looks.  He is just as pathetic
as his master, if not more so.
STOP
);
		set_max_sp(10);
		set_hd(100,1000);
                set_max_hp(25);
                set_hp(25);
                set_exp(10);
		set_stats("strength",7);
		set_stats("intelligence",2);
		set_stats("wisdom",3);
		set_stats("dexterity",4);
		set_stats("constitution",5);
		set_stats("charsma",1);
                set("aggressive",1);
		set_alignment(5);
		set_overall_ac(8);
		set_level(10);
                set_emotes(15,({"%^CYAN%^%^BOLD%^Omen barks at you.%^RESET%^"}));
	
}

void init()
{
	::init();
	add_action("kill", "kill");
}

int kill(string X)
{
	if(X=="ore" || X=="Ore" || X=="shopkeeper" || X=="shop keeper")
          {     kill_ob(TP,1);
		return 0;
          }
        return 0;
}
