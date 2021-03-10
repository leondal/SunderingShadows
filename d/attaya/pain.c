#include <std.h>
#include <objects.h>



inherit ROOM;

void create() {
    ::create();
    set_property("light",3);
    set_property("indoors",0);
    set_short("Volcanic rift valley.");
    set_long("
    You lie battered and bruised against the rocks in a volcanic rift valley.  Luckily for you, a rising shaft of hot air threw you from certain death in the lava.  You are, however scathed and scarred now.
    Lava rages all around you.  The only escape is to scale the cliff to the south, taking you back into the lower valley, and the trail.
");

    set_smell("default", "The lava around you spews black smoke that blackens your body and stings your eyes.");
 
    set_exits(([

       "cliff" : "/d/attaya/jun32",

    ] ));
    set_items(([
        "cliff" : "The cliff is jagged and glowing red hot in places, but it is not impossible to climb down from above.  It would, however be impossible to get back up here.",
        "lava" : "It is a glowing yellow-red magma that churns and bubbles around you.",
        "ground" : "The ground is covered by nearly a foot of ash.",
    ] ));
}
