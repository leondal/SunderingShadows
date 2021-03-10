#include <std.h>
#include <daemons.h>

inherit BARKEEP;

void create()
{
    ::create();
    set_name("Selena");
    set_id(({"innkeeper", "Selena", "selena"}));
    set_short("%^RESET%^%^WHITE%^Selena,%^ORANGE%^ the Innkeeper%^RESET%^");
    set_long("%^WHITE%^Reaching to just over 6 feet when at full height, this statuesque beastkin woman is covered in luxuriously soft, silken fur, a molten silver color put on display by a gentle gleam.");
    set_gender("female");
    set_alignment(6);
    set_race("beastkin");
    set_gender("female");
    set_hd(19, 1);
    set_hp(200);

    set_currency("gold");

/* varargs int add_menu_item  ( string  item_name,            */
/*                              string  item_type,            */
/*                              int     item_strength,        */
/*                              string  item_short,           */
/*                              string  item_long,            */
/*                              string  item_my_mess,         */
/*                              string  item_your_mess,       */
/*                              string  item_empty_container  */
/*                            )                               */

    {
        string color;

        color = "%^ORANGE%^";

        color = "%^MAGENTA%^";
        add_menu_item("wine", "alcoholic", 10,
                      color + "A fine wine", color + "A fine wine from the lands across the ocean.",
                      color + "You savour the taste of the fine wine", color + "savours the taste of the fine wine.",);
        color = "%^ORANGE%^";

        add_menu_item("beer", "alcoholic", 7,
                      color + "A dark beer", color + "A dark beer brewed to the far west of here.",
                      color + "You feel the beer flow down your throat!", color + "slowly pours a mug of thick beer down his throat.",);

        color = "%^CYAN%^";

        add_menu_item("ale", "alcoholic", 7,
                      color + "A pale ale", color + "A pale ale brewed in the farming fields outside Shadow.",
                      color + "You down some ale.!", color + "drinks some hearty ale.",);

        add_menu_item("water", "water", 1,
                      color + "A mug of water", color + "A clear and filtered water, from nearby streams.",
                      color + "The water quenches your thirst.", color + "guzzles a glass of water.",);

        color = "%^RED%^";

        add_menu_item("blood", "blood", 10000,
                      color + "A cup of blood", color + "A cup of fresh blood.",
                      color + "The blood flows down your throat.", color + "guzzles a glass of blood.",);


    }
}
