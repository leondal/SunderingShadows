//tent1.c

#include <std.h>

inherit ROOM;

int searched;

void create(){
    ::create();

        set_name("A dark forboding cavern.");
  set_short("The forest linnorm's cave");
    set_properties((["indoors":1,"light":2]));
    set_terrain(BUILT_CAVE);
    set_travel(FOOT_PATH);
    set_long(
@OLI
    This cave built by the sweat of hundreds is obviously being enjoyed
by a creature of both disgusting habits and disgusting wealth. Great
riches are all around you. Yet also around you are the sights of the
horrors done here. There are black marks on the wall that you desparately
hope are part of the wall. Bones eaten clean as if left for years to the
maggots. This could truly be a place of horrors for you. You do notice
however that this creature keeps many twigs and sticks around him.
OLI
    );
    set_exits(([
      "exit":"/d/tharis/forest/evil14",
        ]));
    set_items(([
        "marks":"The outline what could have been once humanoid simply basted into the wall.",
        "bones":"Eaten clean but by what ... no normal animal could do such a thorough job.",
        "sticks":"Strewn around the room these sticks have a delibrate appearance about them."
        ]));
set_property("no teleport",1);

    set_search("default",(:TO,"search_func":));
   set_smell("default","Something makes you wheeze and convulse.");
   set_listen("default","Silence.");

}

void search_func(){
    object ob,ob2;

    if(present("dragon"))
        return tell_object(TP,"Search while the owner is watching .. I think not!\n");

    if(!searched) {
        write("You find several heavy chests!");
        tell_room(TO,"You see "+TPQCN+" find a chests",TP);

        ob = new("/d/shadow/obj/misc/lkchest");
        ob->set_weight(1000);
        ob2 = new("/std/obj/coins");
        ob2->add_money("gold",1000);
        ob2->add_money("platinum",50);
        ob2->move(ob);
        searched = 1;
        ob->toggle_closed();
        ob->toggle_lock();
        ob->move(TO);

    } else
        write("You find nothing odd");
}

void reset(){
    ::reset();

    searched =0;

    if(!present("forest"))
        new("/d/tharis/monsters/forestd")->move(TO);
}



