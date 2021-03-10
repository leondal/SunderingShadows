//char_poster3.c - Yellow poster for character info. room

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("Yellow poster");
    set_id( ({"Yellow poster", "yellow poster", "poster"}) );
    set_short("%^YELLOW%^Yellow poster%^RESET%^");
    set_long(
@STYX
%^YELLOW%^ADJECTIVES AND DESCRIPTIONS - A helpful post by THORN%^RESET%^
Please review this and your adjective and description several times.  It is difficult to be sure you are using descriptive words rather than telling people how they should react.  Try to remember the difference betwThorn made this post a few weeks after adjectives were implemented to help make the difference in word choice clearer for everyone.  For instance, Riley's description would be VERY wrong for a character.  Although we try to make the mobs and NPC's descriptions' paint a picture for you, we also need to convey other information to you that a player character should do in words and actions instead.

STYX
    );
    set_weight(10000);
    set_property("no animate",1);
}
