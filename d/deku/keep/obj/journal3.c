#include <std.h>
inherit OBJECT;

void create()
{
    ::create();
    set_name("journal entry");
    set_id(({ "journal entry", "journal","parchment","paper"}));
    set_short("a piece of parchment");
    set_obvious_short("a piece of parchment");
    set_long("This is a piece of parchment with writing on it.");
    set_read("I have just entered the tunnel that I was told about, it was easy enough to "+
    "find, but I have no idea as to what may dwell down here.  I'm not sure what I've "+
    "gotten myself into.  I still contend that those bone rings have some significance "+
    "and must in some manner provide a way into this lair I'm searching for.  I've found "+
    "the corpse of one of the two men I've been looking for, judging by his corpse "+
    "he was slain rather brutally.  I still search for the other... I can only hope "+
    "that his fate was not so horrendous, but I fear the worst.  I've been told "+
    "to watch for some hieroglyphics, that they have significance, and that words issued near "+
    "them are important, I've no idea of any of the words though.  I have no idea what "+
    "to expect.  I'll hide this here, in the remains of my friend, in the hope that if "+
    "I.... meet a similiar fate, this will be a warning and perhaps an aid to whoever "+
    "stumbles upon this place after me.");
    set_language("gnomish");
    set_weight(1);
    set_value(1);
}