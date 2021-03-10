//updated by Circe 1/11/05 with desc by Lusell
#include "/d/dagger/tonovi/town/short.h"

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
    ::create();
    set_terrain(WOOD_BUILDING);
    set_travel(PAVED_ROAD);
    set_property("light", 3);
    set_property("indoors", 1);
    set_name("Restaurant of the Hotel Grande");
    set_short("Restaurant of the Hotel Grande");
/*
    set_long(
      "This is a rather large meeting hall with several tables.  A room in the back is where the cook works.  A waiter zips right to you as you sit ready to take your order. \n   %^BOLD%^%^BLUE%^There is a menu here."
    );
*/
    set_long("%^BOLD%^%^WHITE%^This is a fairly large and rather "+
       "posh restaurant.  The tables are exquisitely decorated with "+
       "%^MAGENTA%^silks %^WHITE%^and other expensive cloths.  The "+
       "%^RESET%^silverware %^BOLD%^%^WHITE%^ and china are spotless "+
       "and engraved with the seal of %^BLACK%^Tonovi%^WHITE%^.  The "+
       "stemware is made from the finest %^CYAN%^crystal %^WHITE%^in "+
       "the lands.  The buzz of a dozen or so conversations mingle "+
       "together and reach your ears.  Waiters flit here and there "+
       "very quickly.  One stops just long enough to politely place "+
       "a %^BLUE%^menu %^WHITE%^on the table, then rushes away.%^RESET%^\n");
    set_smell("default","You smell the odor of cooking food.");
    set_listen("default", "You hear the voices of many conversations "+
       "going on at once.");
    set_items(([
	"menu" : "A thick sheet of ivory parchment engraved in greens and "+
         "blacks.  You may read it to see today's choices.",
      ({"tabel","tables","silks"}) : "The round tables are decorated "+
         "in thick silks draped in multiple layers.  They are topped "+
         "with expensive china, silverware, and stemware.",
      ({"crystal","stemware"}) : "The flawless stemware is made from "+
         "the finest crystal to be found anywhere in the lands.  Each "+
         "glass is fluted and multi-faceted, carved to reflect the light.",
      ({"silverware","china","plates"}) : "The silverware bears an "+
         "engraving of the seal of Tonovi, which matches the hand-"+
         "painted design on the china.  Each place is set complete with "+
         "every piece needed for a formal dinner.",
      ({"waiter","waiters"}) : "The waiters seem to look very much "+
         "alike, each with the short, dark hair common in Tonovi.  "+
         "They are dressed in green and black livery trimmed in "+
         "red, and they move with an uncommon speed.  No patron "+
         "goes for want with these men on the job."
    ]));
    set_exits( ([
	"east" : RPATH "hotel2"
      ]) );
}

void reset() {
    ::reset();
    if(!present("waiter"))
	new(MPATH "waiter")->move(TO);
}

int read(string str) {
    object ob;
    int i;

    if(str!="menu")
	return 0;
    ob = present("waiter");
    if(!ob) {
	write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    write("%^BOLD%^%^GREEN%^--<--{%^RED%^@    %^WHITE%^Grand Tonovi Hotel Restaurant    %^RED%^@%^GREEN%^}-->--%^RESET%^");
    write("                     %^BOLD%^%^BLACK%^Appetizers%^RESET%^");
    write("%^ORANGE%^Lamb Barley Soup\t\t\t%^BOLD%^%^WHITE%^"+(int)ob->get_price("lamb barley soup")+" silver");
    write("%^BOLD%^%^MAGENTA%^Grilled Prawns\t\t\t\t%^WHITE%^"+(int)ob->get_price("grilled prawns")+" silver");
    write("%^ORANGE%^Mushroom Medley\t\t\t\t%^BOLD%^%^WHITE%^"+(int)ob->get_price("mushroom medley")+" silver");
    write("%^BOLD%^%^GREEN%^--<--{%^RED%^@                                      @%^GREEN%^}-->--");
    write("                     %^BOLD%^%^BLACK%^Main Course%^RESET%^");
    write("%^BOLD%^%^MAGENTA%^Pan-seared Salmon\t\t\t%^WHITE%^"+(int)ob->get_price("pan-seared salmon")+" silver");
    write("%^YELLOW%^Roasted Chicken\t\t\t\t%^WHITE%^"+(int)ob->get_price("roasted chicken")+" silver");
    write("%^RED%^Steak and Prawns\t\t\t%^BOLD%^%^WHITE%^"+(int)ob->get_price("steak and prawns")+" silver");
    write("%^BOLD%^%^GREEN%^--<--{%^RED%^@                                      @%^GREEN%^}-->--");
    write("                       %^BOLD%^%^BLACK%^Desserts%^RESET%^");
    write("%^YELLOW%^Creme Brulee\t\t\t\t%^WHITE%^20 silver");
    write("%^MAGENTA%^Sticky Toffee Pudding\t\t\t%^BOLD%^%^WHITE%^"+(int)ob->get_price("sticky toffee pudding")+" silver");
    write("%^BOLD%^%^BLACK%^Chocolate Drambuie Trifle\t\t%^WHITE%^"+(int)ob->get_price("chocolate drambuie trifle")+" silver");
    write("%^BOLD%^%^GREEN%^--<--{%^RED%^@                                      @%^GREEN%^}-->--");
    write("                        %^BOLD%^%^BLACK%^Drinks%^RESET%^");
    write("%^YELLOW%^Lemon Water\t\t\t\t%^WHITE%^"+(int)ob->get_price("lemon water")+" silver");
    write("%^BOLD%^%^MAGENTA%^Chamomile Tea\t\t\t\t%^WHITE%^"+(int)ob->get_price("chamomile tea")+" silver");
    write("%^BOLD%^%^GREEN%^--<--{%^RED%^@                                      @%^GREEN%^}-->--");
    write("                       %^BOLD%^%^BLACK%^Nightcaps%^RESET%^");
    write("%^RED%^Iced Brandy\t\t\t\t%^BOLD%^%^WHITE%^"+(int)ob->get_price("iced brandy")+" silver");
    write("%^BOLD%^%^BLACK%^Smoked Sherry\t\t\t\t%^WHITE%^"+(int)ob->get_price("smoked sherry")+" silver");
    write("%^ORANGE%^Aged Scotch\t\t\t\t%^BOLD%^%^WHITE%^"+(int)ob->get_price("aged scotch")+" silver");
    write("%^YELLOW%^Golden Chardonnay\t\t\t%^WHITE%^"+(int)ob->get_price("golden chardonnay")+" silver");
    write("%^BOLD%^%^GREEN%^----------------------------------------------------");
    write("<buy dish_name> gets you the food.");
    return 1;
}

