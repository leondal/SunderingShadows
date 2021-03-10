//forest2.c

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
loom over you almost basking in their grandure. Around you you
sense a horrible feeling of pain. Nature's work is here but that
work is being hurt. You see to the east an opening in the world.
This must be the rumoured entrance to the portion of the world controlled
by evil. If it is it should drop you right into the middle of evil's
control.
OLI
    );
    set_items((["floor":"The ground is cluttered  with twigs and leaves.",
                "trees":"These grand creatures range from oak and hickory to Pine and spruce."
                ]));
    set_exits(([
                "west":"/d/tharis/forest/forest2c",
                "enter":"/d/tharis/forest/forest134"
                ]));
    set_smell("default","The lush fragrances of the forest quell your worries.");
    set_listen("default","The silence of the forest is unnatural, as if all the insects and birds are hiding.");

    set_pre_exit_functions(({"enter"}),({"GoThroughDoor"}));

}

int GoThroughDoor(){
    write("%^CYAN%^A shimmer of light flashes and leaves you in another part of the forest, Evil's power must be great!");
    return 1;
}
