//Octothorpe (1/2/12)
//Shadow, Main Plaza

#include <std.h>
#include "../defs.h"
inherit "/std/rquestroom.c";

void create(){
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_travel(PAVED_ROAD);
    set_terrain(CITY);
    set_climate("temperate");
    set_name("Magistrates' Plaza");
    set_short("%^BOLD%^Magistrates' Plaza, Shadow%^RESET%^");
    set_long("%^BOLD%^Magistrates' Plaza, Shadow%^RESET%^\n "+
        "%^RESET%^The intersection of the two major thoroughfares through "+
        "the %^BOLD%^%^BLACK%^City of Shadow %^RESET%^forms this magnificent "+
        "plaza that serves as the bureaucratic and geographic center of "+
        "the city. %^CYAN%^Melistel Avenue %^RESET%^and %^BLUE%^Shadow Way "+
        "%^RESET%^merge into a broad roundabout that circumscribes a "+
        "large %^BOLD%^marble %^RESET%^statue that faces southward in "+
        "the center of the plaza. During the day the plaza is choked by "+
        "a muddled mess of citizens, adventurers, and merchants making "+
        "their way across the city or to parts beyond. A wide series of "+
        "st%^BOLD%^o%^RESET%^ne steps lead up to a bluff overlooking the "+
        "plaza that houses the Magistrate's Hall and associated "+
        "government offices. The %^YELLOW%^Bank of Shadow %^RESET%^is "+
        "situated at the southeast corner of the plaza. There is a wooden %^ORANGE%^board%^RESET%^ standing, with notices and %^CYAN%^%^BOLD%^map%^RESET%^ of the area pinned to it.\n");
    set_smell("default","Your nose catches the miasma of thousands "+
        "of humanoids in close proximity.");
    set_listen("default","You hear the dull roar of conversations and "+
        "pedestrians and wagons rumbling down the street.");
    set_items(([
        ({"thoroughfares","streets","street","avenue","shadow way","Shadow Way","melistel avenue","Melistel Avenue","roundabout"}) :
            "The wide street allows for four horse-drawn wagons to "+
            "travel abreast of each other. Thousands of octogonal pavers "+
            "carved out of a fairly mundane dark %^BOLD%^%^BLACK%^st"+
            "%^RESET%^o%^BOLD%^%^BLACK%^ne %^RESET%^compose the surface "+
            "of the road. The center of the street is crested, with the "+
            "edges slightly graded to provide runoff during inclement weather.",
        ({"statue","marble statue","pedestal"}) : "%^BOLD%^Standing atop "+
            "a limestone pedestal is a ten foot tall statue of a male human "+
            "carved flawlessly out of marble. The style is reminiscent "+
            "of the late Zin'Charu empire, complete with the flourish of a "+
            "laurel wreath on his head, something that without a doubt "+
            "is an anachronism. He is draped in ceremonial robes and is "+
            "carrying fasces. The figure is standing over a broken "+
            "crescent and a cowering dragon, both symbols of the "+
            "Tsarven Empire, no doubt dating the sculpture after the "+
            "Tsarven occupation of Prince Caenil during the 640s SG. "+
            "Engraved on the pedestal is:\n "+
            "Bornen Whysifer - First Lord Magistrate of Shadow\n"+
            " 11 Renewal, 525 SG to 24 Sundays, 529 SG\n%^RESET%^",
        ({"bluff","steps","stone steps","Magistrate's Hall","magistrate's hall","offices"}) :
            "A series of fifty wide st%^BOLD%^o%^RESET%^ne steps lead "+
            "up to a bluff overlooking the plaza. The somber edifice "+
            "of Magistrate's Hall frowns down upon the plaza from atop "+
            "the bluff.",
        ({"bank","bank of shadow","Bank of Shadow"}) : "The Bank of "+
            "Shadow is an impressive four story building that is an "+
            "excellent example of Perpendicular architecture. The "+
            "importance of the bank to commerce in the city cannot "+
            "be overstated due to the amount of people entering and "+
            "exiting the veritable temple to money in the city.",
        ({"church","cathedral"}) : "%^BOLD%^This impressive "+
            "limestone cathedral towers to the height of nearly "+
            "175 feet. Its architecture is indicative of the "+
            "Perpendicular style, but is certainly more grandiose "+
            "than the %^YELLOW%^Bank of Shadow %^WHITE%^done in "+
            "same style. Mulitple %^RED%^s%^RESET%^%^ORANGE%^t"+
            "%^MAGENTA%^a%^BOLD%^i%^YELLOW%^n%^RESET%^%^RED%^e"+
            "%^BOLD%^%^BLACK%^d %^WHITE%^glass windows are "+
            "found all along the facade%^RESET%^.",
        "map":(:TO,"map":)
    ]));
    set_exits(([
        "north" : ROOMS"melistel1",
        "south" : ROOMS"melistela",
        "west" : ROOMS"shadway0",
        "east" : ROOMS"shadwaya",
        "northwest" : ROOMS"church",
        "southeast" : ROOMS"bank",
    ]));
    set_quest_daemon("/daemon/quests_mid");
    {
        object ob;
        ob = new("/std/bboard");
        ob->set_name("board");
        ob->set_id( ({ "board", "bulletin board" }) );
        ob->set_board_id("union_board");
        ob->set_short("%^RESET%^%^CYAN%^Arcane Bulletin Board");
        ob->set_long("This corkboard has been nailed to the wall of the "+
            "inn to allow businesses to advertise and citizens and adventurers "+
            "to communicate about events.");
        ob->set_max_posts(50);
        ob->set_location("/d/shadow/city/room/plaza.c");
    }
}

void reset(){
    object sms_store;
    object sms_vendor;
    ::reset();
    if (!present("street_light", TO)) {
        // new("/d/common/obj/misc/street_light")->move(TO);
        new(OBJ+"street_light")->move(TO);// blame jenna
    }
    sms_store = find_object_or_load("/d/player_stores/poffices/shadow");
    if (objectp(sms_vendor = present("clerk", sms_store))) {
        sms_vendor->notify_players();
    }
}

void map(){
    TP->more("/d/common/text/main_map");
}

