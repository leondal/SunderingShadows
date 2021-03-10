#include <std.h>
#include <daemons.h>
#define HLA "deku_plains_herb_location"
inherit ROOM;

string original_long;
void place_herbs();

void create() {
    string file,*herb_loc;
    ::create();
    set_property("light",1);
    set_property("indoors",0);
    set_name("Northern Plains");
    set_short("%^ORANGE%^Northern Plains%^RESET%^");
    set_terrain(GRASSLANDS);
    set_travel(FOOT_PATH);
    set_long( (: TO, "ldesc" :) );
    set_listen("default","You hear the rustling of small creatures scurrying "
      "amidst the grass.");
   set_smell("default","The smell of the damp, musty grass is strong.");
   set_items(([
     "grass" : "The blades appear sturdy and resilient enough to be woven "
        "into flexible baskets or the like but right now are a hindrance.",
     "blades" : "Most of the blades are six or eight foot long or more.  They "
       "are somewhat striped with a tint of green running along the center vein."
    ] ));
    set_exits(([
       "east" : "/d/deku/plains/plains02",
       "west" : "/d/deku/plains/plains04"
    ] ));

   file = base_name(TO) +".c";
   if(member_array(file,SAVE_D->query_array(HLA)) != -1) {
         place_herbs();
    }
}


void reset() {
    string *rooms;
    ::reset();
    if(sizeof(SAVE_D->query_array(HLA)) == 0) {
        rooms = get_dir("/d/deku/plains/plains*");
        SAVE_D->set_value(HLA,"/d/deku/plains/"+rooms[random(sizeof(rooms))]);
    }
}  

void init() {
    ::init();
    if(member_array(base_name(TO) + ".c",SAVE_D->query_array(HLA)) != -1) {
        add_action("pull_herbs","pull");
    }
}

void place_herbs() {
    TO->add_items(({"herbs","herb","flowers","wilted 
    flowers"}),"%^YELLOW%^These once beautiful flowers are "+
    "in a state of disarray.  The life has left most of "+
    "them and their petals have wilted and fell away.  "+
    "The bulbous head of several herbs can be "+
    "seen sticking up from beneath the dead remains of some "+
    "of them.  You could pull them up easily enough.%^RESET%^");
    original_long = TO->query_long();
    TO->set_long(TO->query_long() +"Several dead and wilted "+
    "%^YELLOW%^flowers%^RESET%^ blend with the tall grass here.  %^RESET%^");
}   

void pull_herbs(string str) {
    if(!str) return 0;
    if(str == "herbs") {
        tell_object(TP,"You easily pull the herbs from the ground.");
        tell_room(TO,TPQCN+" easily pulls the herbs from the ground.",TP);
        remove_action("pull_herbs","pull");
        SAVE_D->remove_array(HLA);
        TO->set_long(original_long);
        TO->remove_item("flowers");
        TO->remove_item("herbs");
        TO->remove_item("herb");
        TO->remove_item("wilted flowers");
        return 1;
    }
}

string ldesc(string str) {
   return("%^ORANGE%^Northern Plains%^RESET%^\n"
      "Within this sullen, shadowy place the grass grows tall.  Unlike normal "
      "grass, this is mostly brownish in color and the blades are wider than "
      "a human finger.  It "
      "is so tall and thick it blocks your view and passage completely except "
      "where a path has been kept trampled down over time.\n" );
}