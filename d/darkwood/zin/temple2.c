//      Darkwood Forest
//      Zincarla@ShadowGate
//      04/11/95

#include <std.h>
#include "./zin.h"

inherit ROOM;

int shattered;

void create() {
    ::create();
    seteuid(getuid());
    set_smell("default", "It smells of decay and horrid death.");
    set_listen("default", "Deep chanting echo about.");
    set_property("indoors", 1);
    set_property("light", 1);
    set("short", "The Ogre Temple");
    set("long", "You have found the heart of the Ogre Temple.  A "+
        "great altar of shiny black stone has erupted from the "+
        "floor of the temple and radiates with fearful power.  Chained "+
        "the the top of the altar is a freshly sacrificed corpse "+
        "drained of all blood.  A huge arch is set into the west wall, "+
        "while a dark mirror covers the southeast corner and "+
        "almost appears to absorb all light from the room.  A few "+
        "torches line the walls which cast dreadful shadows all "+
        "about.");
    set_items( ([
        "shadows": "They dance about...almost watching you...",
        "water": "It has left multicoloured streaks along the walls.",
        "arch": "It is actually very beautiful and lead west.",
        "altar": "You know it just has to be magically formed.",
        "torches": "They cast a very dim light about the room.",
        "corpse": "It looks fresh, yet is drained of blood.",
        "mirror": (:this_object(), "mirror_desc":),
    ]) );
    set_exits( ([
        "west": ROOM_DIR+"temple1",
    ]) );
}

string mirror_desc() {
    if(shattered)
        return "It has been shattered into a million pieces.  You now "+
               "notice a passageway leading through it to the southeast.";
    return "You see a darker figure of yourself in it.  There also appears "+
           "to be something on the other side of it!  You recall rumours "+
           "about the Shamans entering it to meet their 'God'.";
}

void reset() {
    ::reset();
    shattered = 0;
    if(!present("shaman")) {
        new(MON_DIR+"kobold_shaman")->move(this_object());
    }
}

void init() {
    ::init();
    add_action("go_enter", "enter");
    add_action("shatter", "shatter");
}

int go_enter(string str) {
    object ob;
    if(!str || str != "mirror") {
        tell_object(TP,"Enter what?");
        return 1;
    }
    if(present("shaman",TO)){
        tell_object(TP,"%^BOLD%^%^BLUE%^The Shaman will not let you near the mirror!\n");
        tell_room(TO,"%^BOLD%^%^BLUE%^You see the Shaman keep "+TPQCN+" away from the mirror.",TP);
        return 1;
    }
    if(shattered) {
        tell_object(TP,"The mirror has been shattered!");
        return 1;
    }
    ob = present("shaman robe",TP);
    if(!ob || !ob->query_worn()){
      tell_object(TP,"%^BOLD%^%^BLUE%^Your nose gets crushed against the mirror.  You hear an evil voice cackle and bellow %^WHITE%^'You are not of the faith, begone!'");
      tell_room(TO,"%^BLUE%^"+TPQCN+" tries to enter the mirror but only ends up with a crushed nose.  An evil voice cackles and bellows %^WHITE%^'You are not of the faith, begone!'",TP);
      return 1;
    }
    tell_object(TP,"%^BOLD%^%^BLUE%^You hear a somewhat evil voice whisper %^WHITE%^'You may enter, my child'");
    tell_object(TP,"%^BOLD%^%^GREEN%^You feel a little afraid as you enter into the mirror...\n");
    tell_room(TO,"%^GREEN%^You see "+TPQCN+" disappear into the mirror!\n",TP);
    TP->move_player("/realms/vetri/workroom");
    return 1;
}

int shatter(string str) {
    if(!str) {
        tell_object(TP,"Shatter what?");
        return 1;
    }
    if(!present("stone of shattering", this_player())) {
        tell_object(TP,"You need something in order to do that.");
        return 1;
    }
    if(str != "mirror") {
        tell_player(TP,"You fail to shatter "+str+".");
        return 1;
    }
    if(shattered) {
    message("my_action", "The mirror has already been shattered!\n",
            this_player());
    return 1;
    }
    if(present("shaman",TO)){
        tell_object(TP,"%^BOLD%^%^BLUE%^The Shaman will not let you near the mirror!\n");
        tell_room(TO,"%^BOLD%^%^BLUE%^You see the Shaman keep "+TPQCN+" away from the mirror.",TP);
        return 1;
    }
    message("my_action", "The stone grows hot in your grasp.  Suddenly "+
            "the stone screams and shatters the mirror into a million "+
            "shards of glass.", this_player());
    message("other_action", (string)this_player()->query_cap_name()+
            "'s stone screams and the mirror shatters into a million "+
            "pieces!", environment(this_player()), this_player());
   add_exit("/d/antioch/temple/pass0","southeast");
    shattered = 1;
    return 1;
}     
