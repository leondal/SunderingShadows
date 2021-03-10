#include <std.h>
#include <daemons.h>
#include <rooms.h>
inherit ROOM;

void create() {
    room::create();
    set_property("light",2);
    set_property("indoors",1);
    set_short("The Setter");
    set_long((:TO, "my_long":));
    set_property("no teleport", 1);
    set_property("training", 1);
    set_items(([
        "room" : "The nothingness from which you will be born into Shadowgate.",
    ]));
}

void init() 
{
    ::init();
    if(!TP->query_race()) TP->set_race("unborn");
    add_action("begin","press");
    add_action("begin","push");
}

string my_long()
{
    string ret;
    if(!objectp(TP) || !present("setter object", TP))
    {
        ret = "%^RESET%^%^CYAN%^Your soul floats casually around in the huge void that surrounds you.  "+
              "There are other spirits in the void with you, some are lost souls, "+
              "waiting for reincarnation. Suddenly the room is filled with a loud "+
              "voice. It informs you to %^YELLOW%^<press button> %^RESET%^%^CYAN%^to press the button on the "+
              "wall to start your journey into the world of ShadowGate.\n\n"+
              "%^BOLD%^%^RED%^Note: %^BOLD%^%^WHITE%^If you are a veteran player, this is a good time to associate "+
              "your character with your account if you want to roll a restricted race.  "+
              "New players may want to read %^YELLOW%^<help account> %^BOLD%^%^WHITE%^for information about "+
              "user accounts on Shadowgate.";
    }
    else if(present("setter object", TP))
    {
        ret = "%^RESET%^%^CYAN%^Your soul floats casually around in the huge void that surrounds you.  "+
              "There are other spirits in the void with you, some are lost souls, "+
              "waiting for reincarnation. Suddenly the room is filled with a loud "+
              "voice. It informs you to %^YELLOW%^<review> %^RESET%^%^CYAN%^to continue "+
              "your journey into the world of ShadowGate.\n\n"+
              "%^BOLD%^%^RED%^Note: %^BOLD%^%^WHITE%^If you are a veteran player, this is a good time to associate "+
              "your character with your account if you want to roll a restricted race.  "+
              "New players may want to read %^YELLOW%^<help account> %^BOLD%^%^WHITE%^for information about "+
              "user accounts on Shadowgate.";
    }
    return ret;
}

int begin(string str) 
{
    object ob;
    if(objectp(present("setter object", TP))) return 0;
    new("/d/shadowgate/setter_object.c")->move(TP);
    TP->force_me("review");
    return 1;
}

