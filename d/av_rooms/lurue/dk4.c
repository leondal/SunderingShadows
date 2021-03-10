#include <std.h> 
//#include "../tharis.h" 
inherit ROOM; 

// Duke's Private Hunting Preserve - Hunting Lodge - dk4 (lodge)
// LoKi - August 2008

void create(){ 
::create(); 
set_property("light",1); 
set_property("indoors",1); 

set_terrain(STONE_BUILDING); 
set_travel(PAVED_ROAD); 

set_name("Duke's Hunting Lounge"); 
set_short("%^RESET%^%^ORANGE%^Duke's Hunting Lounge%^RESET%^"); 

set_long("%^RESET%^%^ORANGE%^Duke's Hunting Lounge%^RESET%^ \n"+
"%^BOLD%^%^WHITE%^Several pannels of floor to ceiling %^RESET%^%^CYAN%^windows %^BOLD%^%^WHITE%^look out over a large, clear blue %^CYAN%^mountain lake%^WHITE%^, dominating the comfortably attired hunting lounge with their stunning %^CYAN%^vista%^WHITE%^. Designed to give a panaramic view of the surrounding %^RESET%^%^GREEN%^hunting preserve %^BOLD%^%^WHITE%^the lodge was built out over the water and is circular in shape. Large, richly appointed %^RESET%^%^CYAN%^sitting chairs %^BOLD%^%^WHITE%^are discretely set around the room in small clusters, with %^RESET%^%^ORANGE%^smoking tables %^BOLD%^%^WHITE%^nearby. Deep, %^RESET%^%^ORANGE%^earth tones %^BOLD%^%^WHITE%^and %^RESET%^%^GREEN%^muted greens %^BOLD%^%^WHITE%^adorn the room, while %^BLACK%^trophies %^WHITE%^of prior hunts are mounted on the wall.%^RESET%^");
 
set_smell("default","Fine tobacco and leather create a pleasing masculine scent."); 
set_listen("default","The soft murmur of voices drifts about the room."); 
set_items(([ 

({"trophies"}):"The heads of many of the Duke's personal hunts are shown here.  Everything from a twenty point stag to the eagle shaped head of a griffin can be seen.",

({"chairs","sitting chairs","tables","smoking tables"}):"The plushy appointed chairs are covered in muted earth toned leather.  Several have small stands beside them with trays for ash and supplies for lighting one's pipe.",

({"hunting preserve","preserve","forest"}):"The hunting preserve is the Duke's private grounds and only those who have the Duke's personal permission are allowed to hunt within it.  Pristine and beautiful, the trees are healthy and full of vibrance that is clearly a gift from one of the nature gods.",

({"windows","window","vista","lake","mountain lake","waters"}):"The large, floor to ceiling windows ring the majority of the room, presenting a stunning view of the forest and mountain lake.  Crystalline waters glisten coldly in the lake fed by mountain streams, while the trees of the preserve glow with health and vitality.", 

])); 

set_exits(([ 
 
"north":"dk2", 

])); 
}

void reset(){
    ::reset();
		if(!present("attendant")){new("/d/av_rooms/lurue/attendant.c")->move(TO);}
}

void init(){
    ::init();
	add_action("read","read");
}


int read(string str)
{
        object obj;
        int i;
        string *names;
  	 obj = present("attendant");
        if(str == "menu") {
                say(""+TPQCN+" reads over the menu.");
                message("Ninfo","The attendant hands you a fine sheet of paper with a flowing masculine script listing the day's services:\n"+
                "%^ORANGE%^================================================\n",TP);
                message("Ninfo","\t%^RESET%^%^RED%^A Snifter of Cognac%^RESET%^              \t"+
                " "+(int)obj->get_price("a snifter of cognac")+" platinum pieces\n",TP);
				message("Ninfo","\t%^RESET%^%^RED%^A Glass of Berrywine%^RESET%^             \t"+
                " "+(int)obj->get_price("a glass of berrywine")+" platinum pieces\n",TP);
				message("Ninfo","\t%^RESET%^%^RED%^A Flute of Sparkling Cider%^RESET%^       \t"+
                " "+(int)obj->get_price("a flute of sparkling cider")+" platinum pieces\n",TP);
				message("Ninfo","\t%^RESET%^%^RED%^A Glass of Mountain Spring Water%^RESET%^ \t"+
                " "+(int)obj->get_price("a glass of mountain spring water")+" platinum pieces\n",TP);
                message("Ninfo","%%^ORANGE%^================================================\n",TP);
                message("Ninfo","\t%^RESET%^%^RED%^Cold Roasted Boar Sandwich%^RESET%^       \t "+
                " "+(int)obj->get_price("cold roasted boar sandwich")+" platinum pieces\n",TP);
				message("Ninfo","\t%^RESET%^%^RED%^Almond Crusted Trout Filet%^RESET%^       \t "+
                " "+(int)obj->get_price("almond crusted trout filet")+" platinum pieces\n",TP);
				message("Ninfo","\t%^RESET%^%^RED%^Pinenut and Wild Greens Salad%^RESET%^    \t "+
                " "+(int)obj->get_price("pinenut and wild greens salad")+" platinum pieces\n",TP);
				message("Ninfo","\t%^RESET%^%^RED%^Sampling of Cheeses%^RESET%^              \t "+
                " "+(int)obj->get_price("sampling of cheeses")+" platinum pieces\n",TP);
                message("Ninfo","%%^ORANGE%^================================================\n",TP);
                return 1;
        }
}
