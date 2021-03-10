#include <std.h>
#include "/d/deku/inherits/graveyard.h"
inherit TOMB;

int opened, searched;

void create() {
  ::create();
  set_long((:TO,"long_desc":));    	

  set_items(([
    ({"sarcophagus","tomb"}) : (:TO,"tomb_state":),
    ({"floor","grass covered floor","weed covered floor"}) : 
    "%^GREEN%^The floor of this room is covered with a layer of "+
    "thick and dark weeds. The top of a large sarcophagus protrudes "+
    "from the center of it.%^RESET%^",
    ({"ceiling"}) : "%^GREEN%^The ceiling of this building is covered with a thick and wet moss.  The moss masks the identity of the substance that forms the ceiling.%^RESET%^",
    ({"walls","wall","dark blue","dark blue substance","substance"}) : "%^BLUE%^The walls of this building are created from an unknown and dark blue substance.  Strangely, it continually gives off a faint %^CYAN%^glow%^RESET%^%^BLUE%^.%^RESET%^",
    ({"moss","thick moss","wet moss","thick and wet moss"}) : 
    "%^GREEN%^This thick and wet moss covers the ceiling here, "+
    "masking the identity of the substance that forms it.%^RESET%^",
    ({"weeds","thick weeds","dark weeds"}) : "%^GREEN%^These weeds "+
    "are dark and thick, seemingly growing up out of floor.  "+
    "Suprisingly, they appear to still have some life to them."+
    "%^RESET%^",
    ({"glow","faint glow"}) : "%^CYAN%^A faint glow is being continually given off by the walls of this building.%^RESET%^",
    ({"slab","marble slab","heavy slab","lid"}) : (:TO,"slab_state":),
    ]));

    set_exits(([
    "out" : GY_ROOMS+"grave7-4"
    ] ));
    set_door("glowing door",GY_ROOMS+"grave7-4","out");
    set_string("glowing door", "open", "%^CYAN%^The door swings "+
    "silently and effortlessly outward.%^RESET%^");
    set_door_description("glowing door","%^BOLD%^%^CYAN%^This "+
    "glowing door is made from an unknown substance.  It doesn't "+
    "appear to be solid yet somehow it manages to completely "+
    "obscure any attempt at viewing whatever may linger behind "+
    "it.%^RESET%^");
}

void long_desc() {
    if(opened == 0) {
        return "%^BOLD%^%^WHITE%^You find yourself inside of a "+
        "building that is approximately fifteen feet square.  "+
        "The %^RESET%^%^BLUE%^walls%^BOLD%^%^WHITE%^ of this "+
        "building are made from an unknown, %^RESET%^%^BLUE%^dark "+
        "blue%^BOLD%^%^WHITE%^, substance that continually gives off "+
        "a faint %^CYAN%^glow%^BOLD%^%^WHITE%^.  The %^RESET%^"+
        "%^GREEN%^ceiling%^BOLD%^%^WHITE%^ is covered with a layer "+
        "of thick and wet %^RESET%^%^GREEN%^moss%^BOLD%^%^WHITE%^ that "+
        "masks the identity of whatever substance forms it.  "+
        "The %^MAGENTA%^floor%^BOLD%^%^WHITE%^ is covered with a "+
        "darker layer of what appears to be thick %^RESET%^%^GREEN%^"+
        "weeds%^BOLD%^%^WHITE%^.  The top of a large %^RED%^"+
        "sarcophagus%^BOLD%^%^WHITE%^ protrudes from the center of "+
        "the floor, a large %^BOLD%^%^BLACK%^marble slab%^BOLD%^%^WHITE%^ "+
        "set atop it, effectively sealing it.  An aura of tangible "+
        "%^BOLD%^%^BLACK%^darkness%^BOLD%^%^WHITE%^ radiates out from "+
        "the sarcophagus, infiltrating the air in the room and making "+
        "it difficult to see or breathe.  A %^CYAN%^glowing door"+
        "%^BOLD%^%^WHITE%^ leads out of this building to whatever lies "+
        "beyond.%^RESET%^";   
    }

if(opened == 1) {
        return "%^BOLD%^%^WHITE%^You find yourself inside of a "+
        "building that is approximately fifteen feet square.  "+
        "The %^RESET%^%^BLUE%^walls%^BOLD%^%^WHITE%^ of this "+
        "building are made from an unknown, %^RESET%^%^BLUE%^dark "+
        "blue%^BOLD%^%^WHITE%^, substance that continually gives off "+
        "a faint %^CYAN%^glow%^BOLD%^%^WHITE%^.  The %^RESET%^"+
        "%^GREEN%^ceiling%^BOLD%^%^WHITE%^ is covered with a layer "+
        "of thick and wet %^RESET%^%^GREEN%^moss%^BOLD%^%^WHITE%^ that "+
        "masks the identity of whatever substance forms it.  "+
        "The %^MAGENTA%^floor%^BOLD%^%^WHITE%^ is covered with a "+
        "darker layer of what appears to be thick %^RESET%^%^GREEN%^"+
        "weeds%^BOLD%^%^WHITE%^.  The top of a large %^RED%^"+
        "sarcophagus%^BOLD%^%^WHITE%^ protrudes from the center of "+
        "the floor, a large %^BOLD%^%^BLACK%^marble slab%^BOLD%^%^WHITE%^ "+
        "leans against its right side.  An aura of tangible "+
        "%^BOLD%^%^BLACK%^darkness%^BOLD%^%^WHITE%^ radiates out from "+
        "the sarcophagus, infiltrating the air in the room and making "+
        "it difficult to see or breathe.  A %^CYAN%^glowing door"+
        "%^BOLD%^%^WHITE%^ leads out of this building to whatever lies "+
        "beyond.%^RESET%^"; 
    }
}

void tomb_state() {
    if(opened == 0) {
        return "%^RED%^This large sarcophagus protrudes from "+
        "the center of the floor.  It spans perhaps seven "+
        "feet in length and four feet in width and is "+
        "covered with a large %^BOLD%^%^BLACK%^marble slab"+
        "%^RESET%^%^RED%^ that is far too heavy to lift.%^RESET%^";
    }
    if(opened == 1) {
        return "%^RED%^This large sarcophagus protrudes from "+
        "the center of the floor.  It spans perhaps seven "+
        "feet in length and four feet in width and a "+
        "large %^BOLD%^%^BLACK%^marble slab%^RESET%^%^RED%^ "+
        "leans against its right side.  Only darkness is visible "+
        "from the depths of the sarcophagus, perhaps it warrants "+
        "a %^CYAN%^search%^RESET%^%^RED%^?%^RESET%^";
    }
}

void slab_state() {
    if(opened == 0) {
       return "%^BOLD%^%^BLACK%^This heavy marble slab could "+
       "easily be several feet thick.  It serves as the lid to "+
       "the sarcophagus here, effectively sealing it.  It appears "+
       "far too heavy to be lifted, whatever dwells within the "+
       "sarcophagus is obviously going to stay there.%^RESET%^";
    }
    if(opened == 1) {
        return "%^BOLD%^%^BLACK%^This heavy marble slab could "+
       "easily be several feet thick.  It appears to have served "+
       "as the lid to the sarcophagus here at one point, but now "+
       "rests lazily againsts its right side.%^RESET%^";
    }
}


void reset() {
    	::reset();
    	if(!present("vampire") && !random(2)) 
	{
        	new(GY_MOBS+"vampire")->move(TO);
		if(opened == 1) 
		{
        		tell_room(TO,"A %^BLUE%^LOUD%^RESET%^ grating sound, of "+
		      "stone on stone, fills the room as the %^BOLD%^%^BLACK%^"+
        		"marble slab%^RESET%^ slides slowly into place atop the "+
        		"sarcophagus.");
        		searched = 0;
        		opened = 0;
        		TO->remove_search("tomb");
        		TO->remove_search("sarcophagus");
    		}
	}
}

void do_open() {
    opened = 1;
    tell_room(TO,"%^BOLD%^%^RED%^A %^BLUE%^LOUD%^RESET%^%^RED%^ "+
    "grating sound, of stone on stone, fills the room as "+
    "the heavy marble lid suddenly slides to the side!%^RESET%^");
    TO->set_search("tomb",(:TO,"search_tomb":));
    TO->set_search("sarcophagus",(:TO,"search_tomb":));
}

int search_tomb() {
    object ob;
    string what;
    if(opened != 1) return 0;
    if(!TP->query_invis()) {
        tell_room(TO,TPQCN+"%^BOLD%^%^BLACK%^ carefully searches in "+
        "the large tomb.%^RESET%^",TP);
    }
    if(searched == 0) {
        switch(random(2)) {
            case 0:
                what = "pair of gloves.";
                ob = GY_OBJS+"light_gloves";
                break;
            case 1:
                what = "silver circlet.";
                ob = GY_OBJS+"blasting_circlet";
                break;
            }

        tell_object(TP,"You carefully search the inside of the "+
        "large sarcophagus and find a "+what);
        new(ob)->move(TO);
        searched = 1;
        return 1;
    }
    if(searched == 1) {
        tell_object(TP,"You carefully search the inside of the large "+
        "sarcophagus but find nothing of value.");
        return 1;
    }
}
