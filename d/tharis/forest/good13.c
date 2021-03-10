//good5.c

#include <std.h>

inherit ROOM;

void create(){
    ::create();
    set_name("Forest Path");
    set_short("A small path through the forest");
    set_property("indoors",0);
    set_property("light",1);
    set_terrain(HEAVY_FOREST);
    set_travel(FOOT_PATH);
    set_long(
@OLI
    %^BOLD%^%^GREEN%^The good Camp%^RESET%^
Tall trees loom over you almost basking in their grandure. Around
you, you sense a horrible feeling of pain. Nature's work is here but
that work is being hurt but you feel an attempt to heal here. Small
plants grow around the floor of the forest, fighting for sunshine as
it creeps sparcely through the thick canopy. You see here a single
large tent. Light flickers from within the flaps of the tent as
obvious plans for the army of good are being made! You can feel a
suspiscious benevolence around you.
OLI
    );
    set_items((["floor":"The ground is cluttered  with twigs and leaves.",
                "trees":"These grand creatures range from oak and hickory to Pine and spruce.",
                "tent":"This tent is enormous. It must be reserved for the leader"
                ]));
    set_exits(([
                "west":"/d/tharis/forest/good12",
                "enter":"/d/tharis/forest/tent1"
                ]));
set_property("no teleport",1);
    set_smell("default","The lush fragrances of the forest quell your worries.");
    set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");
}


void reset(){
    ::reset();
    if(!present("elf"))
        new("/d/tharis/monsters/e_archer")->move(TO);
    if(!present("tree"))
        new("/d/tharis/monsters/treant")->move(TO);
}

