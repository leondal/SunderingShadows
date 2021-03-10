//
// Paladin Tithe Room -- Paladin Guild Hall
// Coded by Grazzt@Shadowgate
//
// This room is meant for Paladins to be able to tithe money to their
// god. It more or less allows them to purchase holy water, but is coded
// in such a way as to reflect the tithe principle of the Paladin class.
// I doubt the Paladin player would tithe gold if not receiving something
// in return, so this will hopefully add to the spirit of the class.
// The value of 30 gold per holy water is my suggestion but can be set at
// any value by those who balance these things.
//

#include <std.h>
#define RPATH "/d/shadow/room/city/cguild/paladin/"+
#define OPATH "/d/shadow/room/city/cguild/paladin/"+
inherit ROOM;
void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
//    set_property("no teleport", 1);
    set_short("%^CYAN%^Room of the Tithe%^RESET%^");
    set_long(
	"%^CYAN%^Room of the Tithe.\nYou stand within the room in which "
	"%^WHITE%^Paladins%^CYAN%^"
	" are able to honour their god through a holy ritual "
	"known as the tithe. A %^ORANGE%^sign%^CYAN%^ detailing this "
	"ritual hangs upon the south wall. A simple %^RESET%^stone coffer "
   "%^CYAN%^lays upon a pedestal in the center of the "
	"room. Gleaming%^YELLOW%^ "
	"gold coins%^RESET%^%^CYAN%^ can be seen to be contained within "
	"the "
	"%^RESET%^stone coffer%^CYAN%^. Large ironworked %^MAGENTA%^"
	"holy symbols%^CYAN%^ hang upon the otherwise bare stone walls."
	"%^RESET%^"
    );
    set_listen("default",
	"You hear the faint sound of chimes blowing in the wind."
    );
    set_smell("default",
	"It smells of purity."
    );
    set_items(([
	"sign":"A sign detailing the ritual of the tithe hangs upon the "
	"south wall. Read sign to see what it says.",
   "pedestal":"%^CYAN%^%^BOLD%^The pedestal has a fountain like spout "
   "upon the face of it. Upon the pedestal is a %^RESET%^stone coffer"
	"%^BOLD%^%^CYAN%^ full of %^YELLOW%^gold%^CYAN%^.",
	"cabinet":"%^ORANGE%^The cabinet is full of empty vials.%^RESET%^",
	"coffer":"The stone coffer is full of %^BOLD%^%^YELLOW%^gold"
	" %^RESET%^which has been tithed "
	"to the gods by various paladins of the realms.",
	"spout":"No water emerges from the spout.",
	"symbols":"The symbols are larger versions of the holy symbols "
	"carried by the paladins of the realms and hang upon the walls "
	"around the room."
    ]));
    set_exits(([
        "west": RPATH "sanctum"
    ]));
}
void init() {
    ::init();
    add_action("tithe_fun","tithe");
    add_action("get_fun","get");
    add_action("readsign_fun","read");	
}
int tithe_fun(string str) {
    string type,vl,vit;
    int x,y,i;
    if(!TP->is_class("paladin")){
 	notify_fail("You may not tithe!\n");
	return 0;
    }	
    if(!str) {
	notify_fail("Tithe what?\n");
	return 0;
    }
    if(sscanf(str,"%d %s", x, type ) !=2) {
	notify_fail("Tithe <amount> gold>\n");
        return 0;
    }
    if(type != "gold") {
	notify_fail("Only gold please!\n");
	return 0;
    }
    if(x <= 29) {
        notify_fail("Too little!\n");
        return 0;
    }
    if((int)TP->query_money("gold") < x ) {
	notify_fail("You do not have that much gold!\n");
        return 0;
    }
    y = x/30;
    if(y<2) {
	vl = "vial";
        vit = "it";
    } else {
	vl = "vials";
        vit = "them";
    }	
    message("my_action",
	"%^BOLD%^%^CYAN%^"
	"You tithe "+x+" %^YELLOW%^gold%^CYAN%^ "
	"into the %^RESET%^stone coffer%^BOLD%^%^CYAN%^.\n"
	"%^BOLD%^%^YELLOW%^"
	"Holy water slowly flows from the spout on the\n"
   "pedestal and you quickly grab "+y+" "+vl+" from the cabinet\n"
	"and fill "+vit+". You mutter a brief prayer of thanks.%^RESET%^"
    ,TP);
    message("other_action",
	"%^BOLD%^%^CYAN%^"+TPQCN+
	" tithes some %^YELLOW%^gold%^CYAN%^ "
	"into the %^RESET%^stone coffer%^BOLD%^%^CYAN%^.\n"
	"%^BOLD%^%^YELLOW%^"
	"Holy water slowly flows from the spout on the\n"
   "pedestal and "+TPQCN+" quickly grabs "+y+" vials from the cabinet\n"
	"and fills them. "+TPQCN+" mutters a brief prayer.%^RESET%^"
    ,environment(TP),TP);
   TP->add_money("gold",(-(x)));
    for(i=1;i<y+1;i++) {
    new( OPATH "hlywater.c")->move(TP);
    }
    write_file("/realms/grazzt/paladin/logs/tithe",
        ""+TPQCN+" tithed "+x+" gold to the gods at the paladin tithe "
	"room: "
	+ctime(time())+"");
    return 1;
}
int get_fun(string str) {
    string what;
    what = str;
    if(!str) {
	notify_fail("Get what?\n");
	return 0;
    }
    if(what != "gold" && what != "vial" && what != "vials") {
 	notify_fail("Get what?\n");
	return 0;
    }
    if(what == "gold") {
        if(!TP->is_class("paladin")){
	    write("A magical force prevents removing gold from the coffer.");
	    return 1;
	} else {	
            write(
	        "You may not get the gold!\nGreed is not the way of the Paladin!"
	    );
            return 1;
        }
    } 
    if(what == "vial" || what == "vials") {
        if(!TP->is_class("paladin")){
	    write("A magical force prevents taking vials from the cabinet.");
            return 1;
	} else {	
            write(
	        "You have no need for empty vials at this moment and decide to "
	        "leave them for those who need them."
	    );
            return 1;
        }
    }
}
int readsign_fun(string str) {
    string sig;
    sig = str;	
    if(!str) {
	notify_fail("Read what?\n");
	return 0;
    }
    if(sig != "sign") {
        notify_fail("Read what?\n");
        return 0;
    }	
    if(!TP->is_class("paladin")){
        write(
            "The writing on the sign is in the holy language of the "
            "paladins, a language which you do not understand."
        );
        return 1;
    } else {
        write(
            "The act of the tithe is a ritual that all paladins regard as\n"
            "a sacred method of honouring their respective god. As a\n"
            "paladin you are expected to maintain little monetary wealth\n"
            "and to tithe your money gained while crusading against evil\n"
            "to your god. Your god will look upon your deeds and tithe and\n"
            "aid you as the god sees fit.\n"
            "Syntax: tithe <amount> gold\n"
        );
        return 1;
    }
}		

