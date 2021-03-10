#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(RUINS); //allows commune with nature spell and others that require true wilderness
    set_travel(FOOT_PATH);
    set_name("A quiet grove");
    set_short("%^RESET%^%^GREEN%^A quiet grove%^RESET%^");
    set_long((:TO,"ldesc":));
    set_smell("default","The air is filled with the scents of the forest.");
    set_listen("default","The spring bubbles in a soothing manner.");
    set_property("fill waterskin",1);
    if(base_name(TO) == "/d/magic/temples/eldath") {
        set_items(([
                       ({"spring"}) : "%^GREEN%^The %^BOLD%^%^CYAN%^spring%^RESET%^%^GREEN%^ bubbles to life here, trickling into a quiet stream that winds its way through the grove.%^RESET%^",
                       ]));
    }
    set_exits( ([
                    "north" : "/d/antioch/vale/forest/aash_trail1",
                    "out" : "/d/antioch/wild/forest/trail6"
                    ]) );
}

init()
{
    ::init();

    add_action("drink", "drink");

}

int drink(string str){
    if(!str) return 0;
    if(str !="from spring") return 0;
    if(!TP->add_quenched(50)){
        write("%^CYAN%^As tempting as the water looks you decide against any right now.");
        return 1;
    }
    write("%^CYAN%^You take a large drink from the spring.");
    say("%^CYAN%^"+TPQCN+" takes a large drink from the fountain and seems to savor the flavor.");
    return 1;
}

void reset() {
    if(base_name(TO) == "/d/magic/temples/eldath") {
        if(!present("statue")) new("/d/magic/obj/eldathstatue")->move(TO);
    }
}

string ldesc() {
    if(base_name(TO) == "/d/magic/temples/eldath") {
        return("%^BOLD%^%^CYAN%^Grove of Tranquility\n%^RESET%^"
               "%^GREEN%^Pushing through the forest, you come upon a %^BOLD%^verdant green "
               "%^RESET%^%^GREEN%^paradise.  Lush foliage and grass thrive with a healthy "
               "radiance here.  A %^BOLD%^%^CYAN%^spring %^RESET%^%^GREEN%^bubbles to life, "
               "trickling out to become a stream that meanders through the grove.  Resting "
               "at the base of the spring is a %^BOLD%^%^WHITE%^crystalline "
               "statue%^RESET%^%^GREEN%^.  Hugging close to the stream are delicate "
               "%^CYAN%^ferns %^GREEN%^that sway softly.  The canopy of trees provides shade "
               "to the grove, with streams of "
               "%^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t "
               "%^RESET%^%^GREEN%^filtering in.  All about you a peaceful "
               "%^BOLD%^%^CYAN%^tranquility %^RESET%^%^GREEN%^hangs in the air.%^RESET%^");
    }
    else {
        return("%^BOLD%^%^GREEN%^A Quiet Grove\n%^RESET%^"
               "You are standing in a peaceful grove, surrounded by trees. A stream borders "
               "the grove, surrounded by tall trees.  The bubbling stream is a crystalline "
               "blue that dances over the rocks, and the banks of the stream are grassy and "
               "soft.  Strangely, a somber feeling hangs in the air here, despite the quiet "
               "serenity and beauty of the grove.");
    }
}
