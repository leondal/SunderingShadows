#include <std.h>
#define RPATH "/d/shadow/room/city/cguild/paladin/"+
inherit ROOM;
void init() {
    ::init();
    add_action("stand_func","stand");
}

void create() {
    ::create();
    set_property("light",2);
    set_property("indoors",1);
//    set_property("no teleport", 1);
    set_short( (:TO,"shrt_fun" :) );
    set_long( (:TO,"lng_fun" :) );
    set_smell("default",
	"The scent of holiness and intangible power fills the air."
    );
    set_listen("default","A slight ringing fills your ears.");

    set_items(([
	"walls":"%^CYAN%^Within these %^MAGENTA%^stone walls%^CYAN%^ "
	"is provided absolute safety and security to those belonging "
        "to the Paladin Order.%^RESET%^",
	"archways":"%^CYAN%^Three massive %^BLUE%^archways%^CYAN%^ "
        "adorn the north, west and east walls. The %^BLUE%^archways%^CYAN%^"
        " are made from many small intertwining "
	"%^YELLOW%^angelic figures%^RESET%^%^CYAN%^.%^RESET%^",
	"archway":"%^CYAN%^Three massive %^BLUE%^archways%^CYAN%^ "
        "adorn the north, west and east walls. The %^BLUE%^archways%^CYAN%^"
        " are made from many small intertwining "
	"%^YELLOW%^angelic figures%^RESET%^%^CYAN%^.%^RESET%^",
        "keep":"%^CYAN%^You are surrounded by the "
	"%^RESET%^purity%^CYAN%^ of the stone keep you have "
	"arrived in.%^RESET%^",
        "portal":"%^CYAN%^Upon the south wall "
	"is a shimmering %^RED%^red portal%^CYAN%^. You realise this portal "
	"will return you back to the evil world outside the sanctum."
	"%^RESET%^",
        "crests":"%^CYAN%^Emblazed into the floor "
	"are the various and numerous %^GREEN%^crests%^CYAN%^ representing "
	"the different Gods which the paladins worship. It is well "
	"known that by %^GREEN%^<stand crest>%^CYAN%^ a devout paladin "
	"is able to pray for healing from his or hers God.%^RESET%^",
        "crest":"%^CYAN%^Emblazed into the floor "
	"are the various and numerous %^GREEN%^crests%^CYAN%^ representing "
	"the different Gods which the paladins worship.%^RESET%^",
        "figures":"%^WHITE%^The angelic figures are intricately carved "
	"to form the massive archways on the north, west and east walls."
	"%^RESET%^"
    ]));
    set_exits(([
        "portal": RPATH "fountain",
	"west": RPATH "questroom",
	"east": RPATH "room1",
	"north": RPATH "main",
        "northwest": RPATH "store",
"northeast" : "d/shadow/room/city/cguild/paladin/stable"
    ]));
    set_pre_exit_functions(({"portal"}),({"exit_fun"}));
}
string lng_fun(string str) {
    str =
	"%^CYAN%^You are surrounded by the "
	"%^RESET%^purity%^CYAN%^ of the stone keep you have "
	"arrived in. Within these %^MAGENTA%^stone walls%^CYAN%^ "
	"is provided absolute safety and security to those belonging "
        "to the Paladin Order. Three massive %^BLUE%^archways%^CYAN%^ "
        "adorn the north, west and east walls. The %^BLUE%^archways%^CYAN%^"
        " are made from many small intertwining "
	"%^YELLOW%^angelic figures%^RESET%^%^CYAN%^. Upon the south wall "
	"is a shimmering %^RED%^red portal%^CYAN%^. Emblazed into the floor "
	"are the various and numerous %^GREEN%^crests%^CYAN%^ representing "
	"the different Gods which the paladins worship."
        "%^CYAN%^ ";
    if(present("grazzt")) {
	str += "\n%^BOLD%^%^BLACK%^You stand within the long shadow cast "
	"by the evil presense of Grazzt.%^RESET%^";
    }
    return str;
}
string shrt_fun(string str) {
    str = "%^CYAN%^The Inner Sanctum of the Paladins%^RESET%^";
    return str;
}

int exit_fun() {
    write("%^CYAN%^You vanish through the portal and are transported "
        "back into the evil world.%^RESET%^" );
    say("%^CYAN%^"+TPQCN+" leaves the purity of the sanctum.%^RESET%^" ,TP);
    return 1;
}	
int stand_func(string str) {
    if(!str) {
	notify_fail("Stand where?");
	return 0;
    }
    if(str != "crest") {
	notify_fail("Stand where?");
        return 0;
    }
    if((int)TP->query_level() < 6) {
	notify_fail("You have not proved yourself enough to your Gods "
		    "and they ignore your prayer.");
	return 0;
    }
    write("%^YELLOW%^As you stand within the %^BLUE%^crest%^YELLOW%^ of your "
	"God you begin to lose contact with your surroundings.\n"
        "%^WHITE%^You feel the holy healing power of your God enter your "
	"body.%^RESET%^" );
    say("%^YELLOW%^"+TPQCN+" stands within the %^BLUE%^crest%^YELLOW%^ "
	"belonging to "+TP->query_possessive()+" God and bows deeply.\n"
	"%^WHITE%^"+TPQCN+" is surrounded by a white light and remains "
	"motionless in deep prayer."
        "%^RESET%^",TP);
    tell_object(TP,"You feel your faith flow through your veins.");
    return 1;
}
