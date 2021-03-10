#include <std.h>
#include "../area_stuff.h"
inherit BARKEEP;

void create()
{
    ::create();
    NPCCRE->build_me(TO);
    add_id(({"oasis barkeep"}));
    
    set_currency("gold");
    
    set_menu(
        ({"jug of ale", "sandy death", "red wine", "spring water", "lemonade sour", "thick honey water", "mystery ribs", "platter of chunks", "roasted camel"}),
        ({ "alcoholic", "alcoholic", "alcoholic", "water", "water", "water", "food", "food", "food"}),
        ({ 25, 150, 15, 25, 35, 35, 45, 50, 150})
    );
    
    set_my_mess(
	({
	"You down the smooth jug of ale!\n",
    "The %^RESET%^%^ORANGE%^sandy death%^RESET%^ burns all the way down!\n",
    "You sip the sweet and light red wine!\n",
	"The clean pure water quenches your thirst.\n",
    "The %^BOLD%^%^YELLOW%^lemonade%^RESET%^ is exceptionally sour!\n",
    "mmmm, the water is thick and sweet!\n",
    "Delicious! You managed to make quite the mess while devouring the thick delicious ribs!\n",
    "You carefully eat the chunks from the platter, they are surprising good.\n",
    "Hmmm... not bad for roasted camel and quite filling!\n"
	})
    );
    
    set_your_mess(
	({
	"downs the jug of ale.\n",
    "screams as the %^RESET%^%^ORANGE%^sandy death%^RESET%^ goes down!\n",
    "sips the sweet and light red wine.\n",
    "drinks the clean and pure water.\n",
    "puckers up as the lemonade sour goes down.\n",
    "drinks the delicious looking thick honey water.\n",
    "makes quite the mess while devouring the thick ribs.\n",
    "carefully eats the chunks of meat from the platter.\n",
    "casually eats the slices of roasted camel.\n"
        })
    );
    
    set_menu_short(
        ({
	"Jug of Ale",
	"A sandy death",
	"Sweet and light red wine",
    "A glass of clean and pure spring water",
    "An exceptionally sour lemonade",
    "A glass of thick honey water",
    "Some mystery ribs",
    "A platter of meat chunks",
    "Slices of roasted camel"})
    );
    
    set_menu_long(
        ({
        "A jug of dark and thick ale. It looks smooth.\n",
        "A glass of very dark and thick liquid. Known as the sandy death for a reason.\n",
        "A glass of sweet and light red wine.\n",
	    "A glass of pure and clean spring water.\n",
        "A very sour and very sweet lemonade. Nothing better to beat the desert heart.\n",     
        "A jug of thick and sweet honey water. Also good at beating the desert heat.\n",
        "Some thick and well done mystery ribs. They look surprising good but messy.\n",
        "A large platter of meat chunks. They are well done and thick.\n",
        "Several slices of roasted camel. Prepared with various spices and herbs, it looks good.\n"
        })
    );
}