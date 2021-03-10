#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("journal entry");
    set_id(({ "journal entry", "journal","parchment","paper"}));
    set_short("blood smeared parchment");
    set_obvious_short("blood smeared parchment");
    set_long("This parchment is smeared with blood.");
    set_read("I just arrived here to find the carnage, the places of "+
    "peace that I heard were "+
    "within this keep are gone.  Ruins remain in their place, "+
    "I am certain that lord hawk did not cause "+
    "this or even command it.  Perhaps the wolves my friend "+
    "told me about had something to do with it..."+
    "I dread to think of what could be here just "+
    "beyond what I am seeing.  I believe the rings "+
    "that some of the guards wear has something to do "+
    "with it.  I am not sure what, but I believe "+
    "they are a key to something.  I am going to "+
    "seek out the hidden entrance I was told about, "+
    "it's supposed to be somewhere within the forest.  "+
    "I'll hide this here for now... in case.."+
    "well, it'll be here for now.");
    set_language("gnomish");
    set_weight(1);
    set_value(1);
}