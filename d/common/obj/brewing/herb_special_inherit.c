#include <std.h>
inherit "/d/common/obj/brewing/herb_inherit";

void create(){
   ::create();
   set_name("component");
   set_id(({ "component" }));
   set_short("component");
   set_long("Error - contact a wiz.");
   set_weight(1);
   set_value(0);
}

int use_em(string str){
   if(!id(str)) return 0;
   tell_object(TP,"That's not the kind of alchemical component you can just use on yourself! Try to brew it in something.",TP);
   return 1;
}

void set_herb_name(string str){
    string *herbs;
    mapping herb_map = ([]);

    if(!str) return 0;
    herb_map = ([ 
        "bone dust" : ([ "found" : "skeletons and similar undead", "value" : 15 ]),
        "breath of winter" : ([ "found" : "creatures of the far arctic reaches", "value" : 402 ]),
        "corrupted fey lifeblood" : ([ "found" : "corrupted fey creatures, such as Fey'ri", "value" : 1046 ]),
        "divine essence" : ([ "found" : "divinities and other similarly immortal beings", "value" : 9720 ]),
        "dragon scales" : ([ "found" : "dragonkin", "value" : 4000 ]),
        "dream fragment" : ([ "found" : "creatures that inhabit the realm of dreams", "value" : 300 ]),
        "eye of newt" : ([ "found" : "newts, which tend to breed in places of searing heat", "value" : 1390 ]),
        "reptile scales" : ([ "found" : "snakes and other reptiles", "value" : 11 ]),
        "fur" : ([ "found" : "various wild animals", "value" : 5 ]),
        "heart of an ancient wyrm" : ([ "found" : "the mightiest of dragons", "value" : 11500 ]),
        "lich dust" : ([ "found" : "the greatest and most fearsome undead, an arch-lich", "value" : 9919 ]),
        "living stone" : ([ "found" : "stone elementals and other planar beings of earth", "value" : 705 ]),
        "nycissa orchid" : ([ "found" : "within the depths of the Dark Forest of Antioch", "value" : 1890 ]),
        "patch of demonskin" : ([ "found" : "greater demons", "value" : 170 ]),
        "peryton talon" : ([ "found" : "perytons in Kildare", "value" : 53 ]),
        "spiderweb" : ([ "found" : "spiders", "value" : 35 ]),
        "spirit essence" : ([ "found" : "wraiths, ghosts, and other spectral undead", "value" : 1240 ]),
        "tendril of flame" : ([ "found" : "planar entities of fire", "value" : 685 ]),
        "werebeast fang" : ([ "found" : "were creatures, such as those on the halfling meadowlands", "value" : 105 ]),
    ]);

    herbs = keys(herb_map);
    if(member_array(str,herbs) == -1) return 0;

    herb_name = str;
    set_name("component");
    set_id(({"component",""+str+""}));
    set_short("%^RESET%^"+str+"%^RESET%^");
    set_long("This "+str+" is a rare component used by alchemists across the land, to create wonderful potions, poisons, and other strange brews.  It is commonly found by hunting "
+herb_map[str]["found"]+".");
    set_value(herb_map[str]["value"]);
    set_weight(1);
}