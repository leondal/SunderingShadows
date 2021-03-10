#include <std.h>

inherit ROOM;

#define ITEMZ ([\
"pier"          : "The pier appears to be several hundred years old, as the pilings are rotten and the planks teeter as you tread upon them",\
"beach"         : "A nice looking beach of sand and small plants appears to a welcome sight for any vacationer",\
"plants"        : "Small bits of crabgrass and the occaisional struggling bush try to survive on just sand and sky.",\
"bird"          : "A bird, with red wings, and a black beak circles above you screeching with joy or hatred, it's hard to tell",\
"sand"          : "Miles upon miles of golden sand is to the left and right of you.",\
"rocks"         : "Large rocks, the size of small elephants, and the same colour appear to try and block your way",\
"path"          : "The path is strewn with pebbles and scrub",\
"scrub"         : "Small plants struggle to stay alive in this area",\
"hills"         : "Vague outlines of purple hills, are dotted with bright reds, greens and orange wildflowers",\
"wildflowers"   : "Purple thistle, wild roses, and buttercups are among the few wildflowers you can identify upon the hills",\
"boughs"        : "Great leafy boughs create a canopy of life above your head",\
"trees"         : "Great stands of poplar, interwoven with the occaisional birch tree form this small forest",\
"island"        : "Yes! You are on an island",\
"path"          : "The path is strewn with pebbles and scrub",\
"hills"         : "Vague outlines of purple hills, are dotted with bright reds, greens and orange wildflowers",\
"bones"         : "Bleached bones lie upon the pathway and under the trees as if thrown carelessly by the diner",\
"boughs"        : "Great leafy boughs create a canopy of life above your head",\
"bone"          : "You see bits of tiny bone scattered about, as if the diner had thrown it carelessly away, after consumption.",\
"walls"         : "The walls are woven branches, keeping out the wind and rain",\
"roof"          : "The boughs create a green canopy over your head",\
"blankets"      : "At one time, these blankets were finely woven and brightly patterned, however, time has taken its toll on the fabric, but signs of beauty still show through.",\
"bed"           : "A beautifully carved bed, with designs of flowers, and wild animals.",\
"window"        : "As you look out the window you can see the sea, sand and sky",\
"ceiling"       : "The boughs create a green canopy over your head.",\
"skeletons"     : "You hope it is your imagination, however, isn't that skeleton over there on the right, just about the right size and shape for a human.",\
"sea"           : "Crystal blue-green ocean lapping upon sand, sounds and feels wonderful",\
"pond"          : "You really don't want to get too close to that pond",\
"bushes"        : "Low bushes, three to four feet in height appear, full of lovely scented blossoms",\
"fish"          : "Small tropical fish swim around in schools, creating a beautiful underwater picture, and larger fish, such as sharks, whales and the like jump over the waves.",\
"oars"          : "Well, you have to have oars, ever tried rowing without one, or two",\
"supplies"      : "Tar, a bucket and some nails lie in the front of the rowboat for emergency repairs.",\
"vines"         : "Vines of every hue, drape from the trees, some are only half an inch wide but some are as thick as hawsers and as tough.",\
"hut"           : "Perhaps you should take a closer look",\
"huts"          : "Small round huts appear off to the east, built of small saplings and leaves",\
"skiffs"        : "Small low boats made from large trees, carved out, rest upon the sand.",\
"nets"          : "Nets woven from the brightly coloured vines abundant in the forest, await their owners.", ])

void do_setup();

void create()
{
    :: create();
    set_property("light", 2);
    set_property("indoors", 0);
    set_property("no teleport",1);
    set_short("%^ORANGE%^A Pathway%^RESET%^");
    set_long("%^ORANGE%^You have stepped from the boat onto a pier of wooden planks.  "
        "The pier is somewhat rickety and rotting, and you are not sure if it will hold "
        "your weight let alone the members of the rest of your party.  Small stains of "
        "rust red drops, signal that this area is dangerous to your well-being.  Off to "
        "the left and right is a sandy beach.  Small plants struggle to hold onto life "
        "within the dry and unforgiving sand.  Some type of bird is circling overhead "
        "as if waiting for dinner.");
    do_setup();
}

void reset()
{
    string room;
    int num;

    ::reset();

    if(!objectp(TO)) { return; }

    room = base_name(TO);
    room = replace_string(room,"/d/hm_quest/rooms/quest","");
    num = to_int(room);

    switch(num)
    {
    case 3:
        if(!present("rock")) { new("/realms/svaha/items/rock")->move(TO); }
        break;
    case 8:
        if(!present("chair")) { new("/realms/svaha/items/qchair")->move(TO); }
        if(!present("table")) { new("/realms/svaha/items/qtable")->move(TO); }
        if(!present("chest")) { new("/realms/svaha/items/qchest")->move(TO); }
        break;
    case 13..14:
        if(!present("rowboat")) { new("/realms/svaha/items/rowboat")->move(TO); }
        break;
    case 21:
        if(!present("bough")) { new("/realms/svaha/items/bough")->move(TO); }
        break;
    case 31:
        if(!present("table")) { new("/d/hm_quest/obj/table")->move(TO); }
        break;
    default:
        return;
    }
    return;
}

void do_smells(int num)
{
    switch(num)
    {
    case 0..3:
        set_smell("default", "%^CYAN%^\nYou can smell damp earth and the faint odour of sea.");
        set_listen("default", "%^BLUE%^The sound of sea gives way to bird calls and creature movement.");
        break;
    case 4..7:
        set_smell("default", "%^CYAN%^\nThe smell of sea is replaced by damp earth and rotting vegetation.");
        set_listen("default", "%^BLUE%^The sound of the breeze through the trees whispers gently.");
        break;
    case 8:
        set_smell("default", "%^CYAN%^\nThe heady smell of leaves and sunlight fills your senses.");
        set_listen("default", "%^BLUE%^The sound of the breeze through the trees whispers gently.");
        break;
    case 9..11:
        set_smell("default", "%^CYAN%^\nThe smell of sea is replaced by damp earth and rotting vegetation.");
        set_listen("default", "%^BLUE%^The sound of the breeze through the trees whispers gently.");
        break;
    case 12..21:
        set_smell("default", "%^CYAN%^The smell of brine mingles with the leafy forest.");
        set_listen("default", "%^BLUE%^You can hear the sound of the sea return.");
        break;
    case 22..24:
        set_smell("default", "%^CYAN%^\nYou smell damp earth and heavy scented flowers");
        set_listen("default", "%^BLUE%^You can hear insects and the odd scurrying small animal, "
            "and your own heavy breathing.");
        break;
    case 25:
        set_smell("default", "%^RED%^The smell of blood and fear turns your stomach.");
        set_listen("default", "%^RED%^No sound reaches this sad little domain, except your own breathing.");
        break;
    case 26..30:
        set_smell("default", "%^CYAN%^\nYou smell damp earth and heavy scented flowers");
        set_listen("default", "%^BLUE%^You can hear insects and the odd scurrying small animal, "
            "and your own heavy breathing.");
        break;
    case 31:
        set_smell("default", "You can smell the fires burning, a sweet jasmine odour.");
        set_listen("default", "All is quiet here, peaceful, the flickering of the flame "
            "snapping in a slight breeze is the only sound.");
        break;
    }
    return;
}

void do_items(int num)
{
    mapping items=([]);
    string *words;
    int i;

    switch(num)
    {
    case 1:
        words = ({ "pier","beach","plants","bird","sand" });
        break;
    case 2..3:
        words = ({ "pier","beach","rocks","path","scrub","hills","wildflowers","plants","bird","sand"});
        break;
    case 4..5:
        words = ({"boughs","trees","island","rocks","path","scrub","hills","wildflowers","plants","bird","sand"});
        break;
    case 6..7:
        words = ({ "bones","boughs","trees","island","rocks","path","scrub","hills","bone","wildflowers","plants","bird","sand"});
        break;
    case 8:
        words = ({ "walls","roof","blankets","bed","window","ceiling","boughs","trees","sand" });
        break;
    case 9:
        words = ({ "bones","boughs","trees","island","rocks","path","scrub","hills","bone","wildflowers","plants","bird","sand"});
        break;
    case 10..11:
        words = ({"bones","boughs","trees","island","rocks","path","scrub","hills","skeletons","sand"});
        break;
    case 12:
        words = ({"sea","bones","pond","boughs","trees","island","rocks","bushes","path","scrub","hills","wildflowers","plants","bird","sand"});
        break;
    case 13..21:
        words = ({"bushes","sand","fish","oars","supplies","sea","bones","pond","boughs","trees","island","rocks","path","scrub","hills","wildflowers","plants","bird","sand"});
        break;
    case 22..23:
        words = ({"bushes","sand","sea","boughs","trees","island","rocks","vines","path","scrub","hills","wildflowers","plants","bird","sand"});
        break;
    case 24:
        words = ({ "hut" });
        break;
    case 25..26:
        words = ({"bushes","sand","sea","boughs","trees","island","rocks","vines","path","scrub","hills","wildflowers","plants","bird","sand"});
        break;
    case 27..30:
        words = ({"huts","skiffs","nets","bushes","sand","sea","boughs","trees","island","rocks","vines","path","scrub","hills","wildflowers","plants","bird","sand"});
        break;
    }
    
    for(i=0;i<sizeof(words);i++)
    {
        items += ([ words[i] : ITEMZ[words[i]] ]);
    }

    set_items(items);

    return;
}

void do_setup()
{
    string room;
    int num;

    room = base_name(TO);
    room = replace_string(room,"/d/hm_quest/rooms/quest","");
    num = to_int(room);

    do_smells(num);
    do_items(num);

    return;
}