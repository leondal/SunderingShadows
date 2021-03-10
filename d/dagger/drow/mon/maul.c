#include <std.h>
inherit MONSTER;
void create() {
    :: create();
    set_name("maul");
    set_id(({
	"maul","maul the executioner","executioner"
    }));
   set_short("%^RED%^Maul the Executioner%^RESET%^");
    set_long(
	"%^RED%^Maul the Executioner stands towering at a height of 12 "
	"feet. He bears a shaved head and his eyes burn a bright red "
	"color. Although he bears drow features, he appears to be a "
	"cross breed between a hill giant and a drow. Large muscles "
	"ripple across his body and he appears to be quite capable of "
      	"holding his own in battle.%^RESET%^"
    );
    set_gender("male");
    set_hd(18,1);
    set_size(3);
    set_wielding_limbs(({"right hand","left hand"}));
    set_overall_ac(0);
    set_hp(100);
    set_max_hp(100);
    set_exp(5500);
    set_body_type("human");
    set_race("giant");
    set_class("fighter");
    set_guild_level("fighter",18);
    set_stats("strength",19);
    set_stats("constitution",19);
    set_stats("dexterity",19);
    set_stats("wisdom",14);
    set_stats("intelligence",13);
    set_stats("charisma",5);
    set_emotes(10, ({
   "%^MAGENTA%^Maul says%^RESET%^: Ho Ho, what have we here? More enemies of the Drow "
	"perhaps who need to be executed!?!",
	"Maul glances slyly at you.",
	"Maul grins evilly.",
   "%^MAGENTA%^Maul says%^RESET%^: It is my job to kill you...It is your job to die."
    }),0);
    set_funcs(({"box"}));
    set_func_chance(25);
}
void box(object targ){
    string dam;
    if("daemon/saving_d"->saving_throw(targ,"breath_weapon")) {
	dam="crunches";
    } else {
	dam="obliterates";
    }
    tell_object(targ,
	"%^RED%^Maul, in a sudden fury, "+dam+" your head between both of "
  	"his hands!%^RESET%^"
    );
    tell_room(environment(targ),
	"%^RED%^Maul, in a sudden fury, "+dam+" "+targ->query_cap_name()+
	"'s head between both of his hands!%^RESET%^"
    ,targ);
    if(dam=="crunches") {
    	targ->do_damage("head",roll_dice(2,6));
    	targ->set_paralyzed(25,
	    "You are still reeling from the blow to your head!"
    	);
    } else {
    	targ->do_damage("head",roll_dice(4,6));
    	targ->set_paralyzed(50,
	    "You are still reeling from the blow to your head!"
	);
    }
    return 1;
}
