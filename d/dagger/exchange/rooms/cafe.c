// Cafe - Merchant Exchange - LoKi - 19-02-2008 ((trading.c)

#include <std.h>
#include "../exchange.h"


inherit ROOM;

#include "../prices.h"

void init() {
  ::init();
  add_action("read", "read");
}

void create() {
    ::create();
    set_terrain(STONE_BUILDING);
        set_property("no teleport",1);
    set_travel(PAVED_ROAD);
    set_property("indoors",1);
    set_name("A Quiet Cafe");
    set_short("%^RESET%^%^ORANGE%^A Quiet Cafe%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^The cafe is an open balcony "+
"overlooking the busy trading floor. Great care and planning "+
"have been made to eliminate most of the sounds from the clerks"+
" and traders below. Twenty or so tables dot the space, furnished"+
" with comfortable%^RESET%^%^RED%^ high backed chairs%^RESET%^"+
"%^ORANGE%^. The area near the railing has been cleared, and "+
"several people stand there watching the trading with interest. "+
"A long m%^RESET%^%^RED%^a%^RESET%^%^ORANGE%^hog%^RESET%^%^RED%^a"+
"%^RESET%^%^ORANGE%^ny ba%^RESET%^%^RED%^r%^RESET%^%^ORANGE%^ "+
"dominates the eastern wall and %^RESET%^%^WHITE%^dis%^RESET%^"+
"%^BOLD%^%^WHITE%^p%^RESET%^%^WHITE%^lay cases %^RESET%^%^ORANGE%^"+
"show food that can be purchased. There is a %^RESET%^%^BOLD%^"+
"%^BLACK%^large menu %^RESET%^%^ORANGE%^posted above the bar. "+
"A giant %^RESET%^%^RED%^copper machine %^RESET%^%^ORANGE%^sits"+
" at one end of the bar, puffing %^RESET%^%^BOLD%^%^WHITE%^steam"+
" %^RESET%^%^ORANGE%^and making odd noises.%^RESET%^");
    set_exits(([
        "down" : ROOMS"trading",
    ]));
    set_items(([
        ({"tables"}) : "%^RESET%^%^ORANGE%^The tables scattered "+
"amongst the room are fine oak, each has four chairs.%^RESET%^",
        ({"chairs","high backed chairs"}) : "%^RESET%^%^RED%^The"+
" chairs set at the tables are high backed and covered in a fine "+
"thick red fabric.%^RESET%^",
        ({"railing"}) : "%^RESET%^%^ORANGE%^The railing is a fine "+
"oak and has been scuffed and marked by the traders constantly "+
"leaning against it to look at the trading floor.%^RESET%^",
        ({"bar"}) : "%^RESET%^%^ORANGE%^The bar dominates the "+
"eastern wall, holding large display cases.%^RESET%^",
        ({"cases","display cases"}) : "%^RESET%^%^BOLD%^expensive glass "+
"cases show examples of the food and drink here.%^RESET%^",
        ({"menu"}) : "%^RESET%^%^ORANGE%^The menu over the bar "+
"displays the wares here. You should read it.%^RESET%^",
        ({"machine","copper machine"}) : "%^RESET%^%^RED%^A "+
"large machine sits on the counter. It has several copper tubes"+
" and spigots on it and %^RESET%^%^BOLD%^steam%^RESET%^%^RED%^ "+
"bursts from it occasionally.%^RESET%^",
    ]));

set_smell("default","%^RESET%^%^ORANGE%^The smell of roasting coffee fills the area.%^RESET%^");
set_listen("default","%^RESET%^%^GREEN%^Hushed conversations from several tables fill the area.%^RESET%^");

}

void reset(){
    ::reset();
    if(!present("trader"))
		switch(random(2)){
            case 0:
                new(MOBS"babra.c")->move(TO);
            break;

            case 1:
                new(MOBS"watts.c")->move(TO);
            break;
    }
    if(!present("waitress")){new(MOBS"stefanie.c")->move(TO);}
}

int read(string str)
{
        object obj;
        int i;
        string *names;
  	 obj = present("waitress");
        if(str == "menu") {
                say(""+TPQCN+" reads over the menu.");
                message("Ninfo","The menu is on a small sign on the bar, and it"+
                " lists these drinks:\n"+
                "%^GREEN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~\n\n",TP);
                message("Ninfo","                  %^BOLD%^%^BLUE%^Alcoholic Drinks\n\n",TP);


                message("Ninfo","\t%^RESET%^%^ORANGE%^Late Harvest Red Wine%^RESET%^        \t"+
                " "+(int)obj->get_price("late harvest red wine")+" gold pieces\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Aged Whiskey%^RESET%^        \t\t"+
                " "+(int)obj->get_price("aged whiskey")+" gold pieces\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Traders Pale Ale%^RESET%^        \t "+
                " "+(int)obj->get_price("traders pale ale")+" gold pieces\n",TP);


                message("Ninfo","%^GREEN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"+
                "*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n\n",TP);
                message("Ninfo","                  %^BOLD%^%^BLUE%^  Non-Alcoholic Drinks\n\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Dark Coffee%^RESET%^        \t\t"+
                " "+(int)obj->get_price("dark coffee")+" gold pieces\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Sweet Coffee%^RESET%^        \t\t"+
                " "+(int)obj->get_price("sweet coffee")+" gold pieces\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Lemon Iced Tea%^RESET%^        \t\t"+
                " "+(int)obj->get_price("lemon iced tea")+" gold pieces\n",TP);

                message("Ninfo","%^GREEN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"+
                "*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n\n",TP);
                message("Ninfo","                  %^BOLD%^%^BLUE%^  Food\n\n",TP);


                message("Ninfo","\t%^RESET%^%^ORANGE%^Chicken Herb Wrap%^RESET%^        \t"+
                " "+(int)obj->get_price("chicken herb wrap")+" gold pieces\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Chef's Salad%^RESET%^        \t\t"+
                " "+(int)obj->get_price("chef's salad")+" gold pieces\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Pulled Pork Sandwich%^RESET%^        \t"+
                " "+(int)obj->get_price("pulled pork sandwich")+" gold pieces\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Chocolate Swirl Cheesecake%^RESET%^  \t"+
                " "+(int)obj->get_price("chocolate swirl cheesecake")+" gold pieces\n",TP);

                message("Ninfo","\t%^RESET%^%^ORANGE%^Rice Pudding%^RESET%^        \t\t "+
                " "+(int)obj->get_price("rice pudding")+" gold pieces\n",TP);

                message("Ninfo","%^GREEN%^~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~"+
                "*~*~*~*~*~*~*~*~*~*~*~*~%^RESET%^\n",TP);
                message("Ninfo","<buy item> gets you served.\n",TP);
                return 1;
        }
}
