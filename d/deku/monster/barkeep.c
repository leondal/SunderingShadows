#include <std.h>
#include <daemons.h>
inherit BARKEEP;

void make_me() {
    if((string)EVENTS_D->query_time_of_day() == "night") {
        set_name("durga daarlay");
        set_id( ({ "durga", "barkeep","durga daarlay"}) );
        set_short("Durga Daarlay, Verre barkeep");
        set_long("%^RED%^The man before you is horribly "+
        "scarred.  His body looks like it has been completely "+
        "torn open and then hastily stitched back together "+
        "in several places.  His face is distorted, his nose "+
        "abnormally large and twisted grotesquely to the left.  "+
        "His wide eyes are a dark brown and seem to glance "+
        "around frequently, never settling on a particular "+
        "item.  The hair atop his head is thick and black, "+
        "and suprisingly it has been kept clean.  His teeth "+
        "appear to be yellowed or darkened to the point of "+
        "rot.%^RESET%^");
        set_race("half-ogre");
        set_stats("strength",19);
        return;
    }
    set_name("kyanus galanodel");
    set_id(({"kyanus","kyanus galanodel","barkeep"}));
    set_short("Kyanus Galanodel, Verre barkeep");
    set_race("half-elf");
    set_long("This short man stands a little less than "+
    "five feet tall.  His hair is a thick brown and "+
    "is kept tied back behind his head.  His eyes are a "+
    "dark, forest green color and sparkle with a "+
    "natural curiosity.  His facial features are well "+
    "defined, an obvious give away to his apparent "+
    "elven heritage.  His flesh is a light, not quite pale, "+
    "color, and shows the normal signs of aging and hard "+
    "work.  There is nothing really remarkable about this man.");
    set_stats("strength",16);
    return;
}

    

create() {
    ::create();
    set_alignment(6);
    set_gender("male");
    set("aggressive",0);
    set_level(12 + random(4));
    set_hd(12 + random(4),2);
    set_hp(query_hd() * 7 + random(31));
    make_me();
    set_stats("intelligence",15);
    set_stats("wisdom",12);
    set_stats("dexterity",13);
    set_stats("constitution",11);
    set_stats("charisma",10);
    add_money("copper", random(20));
    set_exp(query_hp() * 5);
    set_body_type("human");
    set_currency("silver");
    set_menu(
        ({"wine", "beer", "ale","water","spring water","coffee","roast beef sandwich", "pork stew", "salad","leg of worg","block of cheese","slab of meat","burningdeath",}),
        ({ "alcoholic", "alcoholic", "alcoholic", "water", "water","caffeine", "food", "food", "food","food","food","food","alcoholic","alcoholic",}),
        ({ 10, 7, 5, 1, 2, 10, 10, 9, 3, 50, 3, 15,25,})
    );
    set_my_mess(
	({
	"You savour the taste of the fine wine!\n",
	"You feel the beer flow down your throat!\n",
	"You down some ale.\n",
	"The water quenches your thirst.\n",
    "The crisp cool spring water soothes your thirst.\n",
    "The hot coffee opens your eyes a bit.\n",
    "The delicious sandwich is thick and full of beef.\n",
    "The stew is very pleasing to the taste.\n",
    "The salad is very refreshing.\n",
    "The leg is spicy and wet.\n",
    "The block of cheese is old and stale.\n",
    "The slab of undercooked meat is saturated with salt.\n",
    "You chug the thick drink and groan as it burns down your throat and into your guts.\n",
	})
    );
    set_your_mess(
	({
	"savours the taste of the fine wine.\n",
        "slowly pours a mug of thick beer down his throat.\n",
        "drinks some hearty ale.\n",
	    "guzzles a glass of water.\n",
        "enjoys a glass of crisp clear spring water.\n",
        "sips the bitter hot coffee.\n",
        "takes several bites into the sandwich.\n",
        "wastes no time in finishing off the stew.\n",
        "looks renewed after eating the salad\n",
        "hungrily tears into the leg\n",
        "chokes down the block of cheese\n",
        "tears into the undercooked meat\n",
        "chugs the thick drink and groans loudly\n",
        })
    );
    set_menu_short(
        ({
	"A fine wine",
	"A dark beer",
	"A pale ale",
	"A mug of water",
    "A glass of spring water",
    "A cup of coffee",
    "A hefty roast beef sandwich",
    "A bowl of pork stew",
    "A bowl of salad",
    "A leg of worg",
    "A block of cheese",
    "A slab of meat",
    "A burningdeath",})
    );
    set_menu_long(
        ({
        "A fine wine from the lands across the ocean.\n",
        "A dark beer brewed to the far west of here.\n",
        "A pale ale brewed in the farming fields outside Shadow.\n",
	    "A clear and filtered water, from nearby streams.\n",
        "A crisp clear and cool water, imported from some distant spring.\n",
        "A bitter strong coffee. Sure to help sober you up a bit.\n",
        "A big sandwich made by wheat bread and plenty of beef.\n",
        "A bowl of stew with several chunks of pork.\n",
        "A zesty salad with dressing imported from Asgard.\n",
        "A leg of worg that has been seasoned and roasted.\n",
        "A thick block of cheese that looks old.\n",
        "A slab of red, undercooked meat.\n",
        "A thick and odorless drink.\n",
        })
    );
}

