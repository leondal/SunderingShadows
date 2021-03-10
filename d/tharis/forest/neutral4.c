//neutral3.c

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
    %^BOLD%^%^GREEN%^A small twisting path through the forest%^RESET%^
As you enter the forest you notice a quiet all around you. Tall trees
loom over you almost basking in their grandure. You realize that
around you nature seems to have returned to a state of normality.
Birds sing, squirels climb, and animals in general seem to have peace.
Some how this small area has escaped the sufferings of war.
OLI
    );
    set_items((["floor":"The ground is cluttered  with twigs and leaves.",
                "trees":"These grand creatures range from oak and hickory to Pine and spruce."
                ]));
    set_exits(([

                "southwest":"/d/tharis/forest/neutral3",
                ]));
    set_smell("default","The lush fragrances of the forest quell your worries.");
    set_listen("default","The bustle of the forest is natural and full");
}

void reset(){
    ::reset();

    if(!present("hermit"))
        new("/d/tharis/monsters/hermit")->move(TO);
}
