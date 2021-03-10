#include <std.h>
#include "flower.h"

inherit ROOM;

int ITEM,CHECKER;
object SENDER;

void init() {
    ::init();
    add_action("send_fun","send");
	add_action("read", "read");
} 
void create() {
    ::create();
    set_light(2);
    set_indoors(1);
    set_short("%^GREEN%^D'Zeron's Chocolate and Flower Shop");
    set_long(
	"%^GREEN%^You have stepped into D'zeron's Chocolate and Flower Shop. "
	"Beautiful coloured baskets and intricately carved boxes of handmade "
	"chocolates line the shelves.  On the other side of the room, handcrafted "
	"urns contain goldenrod, lavender, wineleaf, lotuswheel, angelflick, "
	"larkspur and roses.  You can purchase a box of chocolates or flowers here. "
	"D'zeron would be more than happy to assist you. <list> will get you the "
	"information you require."
	" There is a sign on the wall, please <read sign>, that will help "
	" you in buying or having items delivered.");
    set_items(([
	"baskets" : "round, oval, square, rectangle.  Many baskets of different "
	"colours are filled with flowers.",
	"urns" : "Hand thrown urns with shapes of straight simple lines are stacked "
	"against one wall, while on the other shapes reminiscent of Salvadore Dali "
	"reside.",
	"shelves" : "Shelves cut by hand, eight feet long and two inches thick give "
	"the flowers and chocolates room", 
	"flowers" : "Many varieties, some as bold as lions mingle with others "
	"delicate as lace."
    ]));
set_exits((["out" : "/d/shadow/room/city/nroad"]));
    set_property("no castle", 1);
    set_property("no attack", 1);
    set_smell("default",
	 "%^RED%^The odour of chocolates and flowers mingle to delight "
	"the senses."
    );
    set_listen("default", 
	"%^CYAN%^The sounds of customers oohing and aahing over the "
	"wares is the loudest sound you hear." );
}
int read(string str) {
if(str!="sign")
return 0;
write(
@PTALKIN
%^CYAN%^The sign reads: To buy an item from the list type <buy item>,
for example <buy roses>.  In the case of the chocolate items, however
you type <buy peach> NOT <buy chocolate peach>.
To send an item, you need not <buy> just <send item to player>
For example <send roses to tristan>.  The money will be taken from you 
in accordance to the price list.  The one small note to make however, is 
that the roses, should be given to the ladies, not the men.
PTALKIN
);
tell_room(environment(TP), TPQCN+" reads the sign upon the wall.", TP);
return 1;
}
int send_fun(string str) {
    string target, prop;
    object ob,locale,type,who;
    object servant, PRESENT;
    int amnt,cost;
    if(!str) {
	notify_fail("send what to who?\n");
	return 0;
    }
    if( (sscanf(str, "%d %s to %s", amnt, type, who) != 3) ||
        (sscanf(str, "chocolate %s to %s",type, who) != 2) ) {
      if(sscanf(str, "%s to %s", type,who) != 2) { 
 	notify_fail("send what to who?\n");
	return 0;
      }
    }
     if (member_array(type, OBJECTS) == -1 ) {
	notify_fail("Chocolates, eveningstars, goldenslippers and roses are "
"and Christmas items are the only items we deliver here!\n");
	return 0;
}
      switch(type) {
      case "peach" : 
	ITEM = 1;
	cost = 25; 
	break;
      case "tree" :
	ITEM = 2;
	cost = 30;
	break;
      case "rose" :
	ITEM = 3;
	cost = 35;
	break;
      case "eveningstars" :
	ITEM = 4;
	cost = 15;
	break;
      case "goldenslippers" :
	ITEM = 5;
	cost = 20;
 	break;   
      case "roses" :
	ITEM = 6;
	cost = 25;
	break;
	case "teddybear":
ITEM = 7;
cost = 40;
break;
	case "candycane":
ITEM = 8;
cost = 2;
break;
	case "christmascard":
ITEM = 9;
cost = 1;
break;
	case "gingerbreadman":
ITEM = 10;
cost = 3;
break;
	case "eggnog":
ITEM = 11;
cost = 5;
break;
	case "torque":
ITEM = 12;
cost = 150;
break;
	case "necklace":
ITEM = 13;
cost = 150;
break;
	case "stocking":
ITEM = 14;
cost = 5;
break;
     }
    if((int)TP->query_money("gold") < cost) {
	notify_fail("You do not have the gold to pay for that!\n");
	return 0;
    }
    ob = find_player(who);
    if(!ob) {
        notify_fail("Sorry but that person is not within our realms!\n");
        return 0;
    }
    if(ob == TP) {
        notify_fail("Send it to yourself?\n");
        return 0;
    }    
    if(ob->query_ghost()) {
      notify_fail("We don't deliver to ghosts!\n");
      return 0;
    }
    if(ob->is_player() && !interactive(ob)) {
        notify_fail("We don't deliver to link dead players!\n");
        return 0;
    }
    if(!userp(ob)) {
	notify_fail("We don't deliver to that type of creature!\n");
	return 0;
    }
    if(ob->query_invis() && (int)TP->query_level() < (int)ob->query_level()) {
        notify_fail("Sorry but that person is not within our realms!\n");
        return 0;
    }
    if(CHECKER == 1) {
	notify_fail("Please wait a minute as it seems the delivery boy is quite busy currently!\n");
	return 0;
    }

    CHECKER = 1;
        if(present("delivery_boy")) {
           say("%^CYAN%^The delivery boy wanders in ready to"+
               " make a delivery!%^RESET%^"); }
        else {
           servant=new("/d/ptalkin/mon/deliveryboy.c");
           servant->move(TO);
	     }

        servant->force_me("bow "+(string)TP->query_true_name());
	switch (ITEM) {
	  case 1 : PRESENT=new(PEACH); break;
	  case 2 : PRESENT=new(TREE);  break;
	  case 3 : PRESENT=new(ROSE);  break;
	  case 4 : PRESENT=new(STARS); break;
	  case 5 : PRESENT=new(SLIPS); break;
	  case 6 : PRESENT=new(ROSES); break;
	case 7: PRESENT=new(TEDDYBEAR); break;
	case 8: PRESENT=new(CANDYCANE); break;
	case 9: PRESENT=new(CARD); break;
	case 10: PRESENT=new(GINGERBREADMAN); break;
	case 11: PRESENT=new(EGGNOG); break;
	case 12: PRESENT=new(TORQUE); break;
	case 13: PRESENT=new(NECKLACE); break;
	case 14: PRESENT=new(STOCKING); break;
		}
	    SENDER = TP;
            ITEM=0;
	    servant->force_me("say I will deliver the present at once!");
	    say("%^CYAN%^Delivery boy runs off to deliver the order!%^RESET%^");
	    TP->add_money("gold",(-(amnt)));
            call_out("deliver",5,ob,servant,PRESENT);
    return 1;
}

int deliver(object ob, object servant, object PRESENT) {
    servant->move_player(environment(ob), "running very fast");
    tell_object(ob,
	"%^CYAN%^A delivery boy runs into the area and stops in front of you!%^RESET%^"
    );
    servant->force_me("bow");
    servant->force_me("say I have a very special delivery for you from a secret admirer");
    PRESENT->move(ob);
    tell_object(ob,
	"The servant gives you a special present");
    tell_room(environment(ob),
	"%^CYAN%^The delivery boy runs off to make the rest of his deliveries!%^RESET%^");
	servant->move_player("/d/ptalkin/room/flower.c","running very fast");
    servant->force_me("say The gift was delivered to "+ob->query_cap_name()+" as you ordered.");
    servant->force_me("say Well work never seems to end, see you later!");
    servant->force_me("wave");
    servant->force_me("east");
    servant->remove();
    CHECKER = 0;
}  

void reset(){
::reset();
if(!present("d'zeron"))
new("/d/ptalkin/mon/d'zeron")->move(TO);
}
