// /d/tharis/Tharis/market9.c //
#include <std.h>
#include <daemons.h>
inherit VAULT;
int count;
int lock_door();
void create() {
        ::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
   set_property("no teleport",1);
        set_light(2);
   set_indoors(0);
   set_short("This is the marketplace in the center of Tharis");
        set_long(
@OLI
        This is the marketplace in the center of Tharis.
The people of Tharis and surrounding areas come here
to buy and sell goods. Vendors frequent the market,
selling goods off carts. One will never know what vendors
will be in that market, although very likely would be food
and trinket vendors.
	Bordering the marketplace to the west and south is the 
Merchant Guild Hall. 
		 The market bustles around you.
OLI
		 );
	  set_smell("default","Your senses are accosted by the normal smells of a
city.");
	  set_listen("default"," The city bustles around you");
	  set_exits(([
		    "north" : "/d/tharis/Tharis/market4",
		    "south":"/d/tharis/Tharis/guild2",
		    "east":"/d/tharis/Tharis/market8",
		    "west":"/d/tharis/Tharis/guild1",
		    "northeast":"/d/tharis/Tharis/market5"
		    ]));
	  set_door("west door","/d/tharis/Tharis/guild1","west","guild key");

	  set_open("west door",0);
	  set_locked("west door",1);
	  "/d/tharis/Tharis/guild1"->set_open("east door",0);
	  "/d/tharis/Tharis/guild1"->set_locked("east door",1);
	  "/d/tharis/Tharis/guild2"->set_open("north door",0);
	  "/d/tharis/Tharis/guild2"->set_locked("north door",0);
 }
void reset(){
           int num;
           int number;
           object ob;
        int x;
        string time;
        ::reset();
        set_open("west door",0);
        set_locked("west door",1);
        set_open("south door",0);
        set_locked("south door",0);
        "/d/tharis/Tharis/guild1"->set_open("east door",0);
        "/d/tharis/Tharis/guild1"->set_locked("east door",1);
        "/d/tharis/Tharis/guild2"->set_open("north door",0);
        "/d/tharis/Tharis/guild2"->set_locked("north door",0);
        if(!present("street_light",TO))
                new("/d/tharis/obj/street_light")->move(TO);
        while(present("thief")){
              if(ob=present("thief",TO)){
                     ob->move("d/shadowgate/void");
                     ob->remove();
       }
        }
                 while(present("patrol")){
                if(ob=present("patrol",TO)){
                     ob->move("d/shadowgate/void");
                     ob->remove();
        }
        }
                while(present("citizen")){
                if(ob=present("citizen",TO)){
                     ob->move("d/shadowgate/void");
                     ob->remove();
        }
        }
          while(present("vendor")){
                if(ob=present("vendor",TO)){
                     ob->move("d/shadowgate/void");
                     ob->remove();
}
}
        num = random(9);
                 for(x = 1; x <= num;x++){
                number = random(10);
                switch (number){
                        case 0:
                        case  1: break;
                        case 2:
                        case 3:
                        case 4:
                case 5:
                        new("d/tharis/monsters/citizen")->move(TO);
                        break;
                        case 6:
                        case 7:
                case 8:
                        new("d/tharis/monsters/patrol")->move(TO);
                break;
                case 9:
                        new("d/tharis/monsters/thief")->move(TO);
                        break;
                }
        }
        time = EVENTS_D->query_time_of_day();
        if(time!="night"){
        num=random(2);
                for(x = 1; x <= num;x++){
                        number = random(9);
                        switch (number){
                        case 0:
                        case 1:
                           new("/d/tharis/monsters/tb_vendor")->move(TO);
                           break;
                        case 2:
                        case 3:
                           new("/d/tharis/monsters/cl_vendor")->move(TO);
                           break;
                        case 4:
                        case 5:
                        case 6:
                           new("/d/tharis/monsters/f_vendor")->move(TO);
                           break;
                        case 7:
                           new("/d/tharis/monsters/perfume")->move(TO);
                            break;
                        case 8:
                           new("/d/tharis/monsters/ring")->move(TO);
                           break;
                        case 9:
                           new("/d/tharis/monsters/scribe")->move(TO);
                           break;
                        }
                }
        }
}

/*
//This query weather is for a plot.  Remove when no longer needed.
//~Circe~ 7/15/08
query_weather() { return "%^BOLD%^%^BLACK%^Stormclouds %^CYAN%^roll in the %^BLUE%^sky%^CYAN%^, shedding a steady downpour of %^BLUE%^rain%^CYAN%^.%^RESET%^"; }
*/