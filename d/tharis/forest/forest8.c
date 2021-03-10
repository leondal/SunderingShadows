//forest8.c

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_name("Forest clearing");
    set_short("Forest clearing");
    set_property("indoors",0);
    set_property("light",2);
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_long(
@OLI
    %^BOLD%^%^GREEN%^A small forest clearing%^RESET%^
You have stumbled into a small clearing that seems to have survived
untouched the onslaught of evil that this forest is suffering. You
feel a joy around this place. The deep green grass appears untouched.
you can see the sky through the opening in the trees.
OLI
    );
    set_exits(([
               "northeast":"/d/tharis/forest/forest7",
        ]));

    set_smell("default","A rich smell of green, life and nature abounds here.");
    set_listen("default","You can almost hear laughing and playing that has and always will fill this place.");
    }

void reset(){
    int num, i;
    object ob, scroll;
    ::reset();

    if(!present("satyr")){
        num = random(5)+1;
        for(i=0;i<num;i++)
            new("/d/tharis/monsters/satyr")->move(TO);
    }

    if(!present("korred")){
        ob = new("/d/tharis/monsters/korred");
        scroll = new("/d/magic/scroll");
                scroll->set_spell(7);
        scroll->move(ob);
        ob->move(TO);
    }
}
