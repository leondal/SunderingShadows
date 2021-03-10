#include <std.h>

inherit BARKEEP;

create() {
    ::create();
    set_property("no bump", 1);
    set_name("Drisman");
    set_id( ({ "drisman", "barkeep" }) );
    set_short("Drisman, the barkeep");
    set("aggressive", 0);
    set_long("He is a tall husky fellow who stands at the bar being very attentive to everything that goes on."+
    " His blue eyes scan across the room as he looks for trouble, while ready to take"+
    " orders. Over his shoulder is a large black towel that he uses to wipe down the"+
    " bar top.");
    set_gender("male");
    set_alignment(2);
   set_race("human");
    set_level(12);
    set_hd(12,2);   
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(400));
    set_max_mp(query_mp());
    add_money("copper", random(20));
    set_exp(20);
    set_body_type("human");
   set_currency("gold");
    set_menu(
        ({"wine", "beer", "ale", "soda", "water", "coffee", "chips", "pretzels"}),
        ({ "alcholic", "alcoholic", "alcoholic", "soft drink", "water", "caffeine", "food", "food" }),
        ({ 10, 7, 5, 3, 1, 5, 7, 7 })
    );
    set_my_mess(
	({
	"You savour the taste of the fine wine!\n",
	"You feel the beer flow down your throat!\n",
	"You down some ale.\n",
	"The soda tastes good going down.\n",
	"The water quenches your thirst.",
        "The hot coffee opens your eyes a bit.",
        "The chips are crunchy and have a strong potato flavor.",
        "The crisp pretzels are a tasty snack."
	})
    );
    set_your_mess(
	({
       "sips the fine wine slowoly, savouring the taste.\n",
        "slowly downs a mug of thick beer.\n",
        "drinks some hearty ale.\n",
	"sips on a soda.\n",
	"guzzles a glass of water.\n",
        "sips the bitter hot coffee.\n",
        "munches loudly on the chips.\n",
        "digs into a bowl of pretzels.\n"
        })
    );
    set_menu_short(
        ({
	"A fine wine",
	"A dark beer",
	"A pale ale",
	"A soda pop",
	"A mug of water",
        "A cup of coffee",
        "A bowl of potato chips",
        "A bowl of pretzels"})
    );
    set_menu_long(
        ({
        "A fine wine from the lands acrossed the mountians.\n",
        "A dark beer brewed to the far west of here.\n",
        "A pale ale brewed in the farming fields outside Shadow.\n",
	"A carbonated soda pop from far away lands.\n",
	"A clear and filtered water, from nearby streams.\n",
        "A bitter strong coffee. Sure to help sober you up a bit.\n",
        "A bowl of greasy potato chips. They are scattered amongst the bowl in large crisp wafers.\n",
        "A bowl of pretzels that have been poured in a sloppy manner.\n"
        })
    );
}

void init(){
    ::init();
    if((TP->is_class("thief") || TP->is_class("assassin") || TP->is_class("bard")) && !TP->query_invis()){
      tell_object(TP, "As you enter the bar, Drisman nods to you with a small smile.");
    }
}
