//Coded by Bane//
#include <std.h>

inherit ROOM;

object ob;

void create(){
    ::create();
   set_property("no teleport",1);
    set_name("storage room");
    set_short("Storage room");
    set_long(
	"This is a storage room.  You shouldnt be here, either teleport out or "+
	"ask a wiz to get you out."
    );
    set_property("indoors",1);
    set_property("light",2);
}
void reset(){
    ::reset();
    if(!present("dagger")){
	new("/d/laerad/obj/ice_dagger")->move(this_object());
    }
    if(!present("net")){
	new("/d/laerad/obj/net")->move(this_object());
    }
    if(!present("glove")){
	new("/d/laerad/obj/glove")->move(this_object());
    }
    if(!present("bracelet")){
	new("/d/laerad/obj/bracelet")->move(this_object());
    }
    if(!present("bag")){
	new("/d/laerad/obj/bag")->move(this_object());
	new("/d/laerad/obj/bag")->move(this_object());
    }
    if(!present("chalice")){
	new("/d/laerad/obj/chalice")->move(this_object());
    }
    if(!present("ring of detection")){
    new("/d/laerad/obj/ring_of_detection")->move(this_object());
    }
    if(!present("studded")){
	if(!random(10)){
	    ob = new("/d/shadow/obj/armor/studded");
	    ob->move(TO);
	    ob->set_property("enchantment",random(4)-1);
	    ob->set_size(random(3)+1);
       ob->set_value(2000+absolute_value((int)ob->query_property("enchantment") * 2000));
	}
    }
    if(!present("hide")){
	if(!random(15)){
	    ob = new("/d/shadow/obj/armor/hide");
	    ob->move(TO);
	    ob->set_property("enchantment",random(4)-1);
	    ob->set_size(random(2)+1);
         ob->set_value(2500+absolute_value((int)ob->query_property("enchantment")*2500));
	}
    }
    if(!present("chain")){
	if(!random(10)){
	    ob = new("/d/shadow/obj/armor/chain");
	    ob->move(TO);
	    ob->set_property("enchantment",random(3)-1);
	    ob->set_size(random(2)+1);
         ob->set_value(2000+absolute_value((int)ob->query_property("enchantment")*2000));
	}
    }
    if(!present("case"))
    {
        ob = new("/d/dagger/arctic/obj/scroll_case.c");
        ob->move(TO);
        ob->set_value(5000);
    }

}
