#include <std.h>
inherit MONSTER;

void create(){
    ::create();
    set_name("Amazon Queen");
    set_id( ({"amazon","queen"}) );
    set_short("Amazon Queen");
    set_long("She is extremely muscular like the rest of "
             "her kind.  Unlike the others however she is "
             "dressed extremely well and even wears jewelry. "
             "She seems troubled.  Perhaps you can ask her "
             "about something."
            );
    set_gender("female");
set_property("full attacks",1);
    set_race("human");
    set_body_type("human");
    set_overall_ac(4);
    set_hd(30,10);
    set("agressive",3);
    set_size(2);
    set_hp(300);
    set_emotes(10, ({
               "The Queen mumbles something about a marsh.",
               }),0);
}
void init(){
    ::init();
    add_action("ask_func","ask");
}
int ask_func(string str){
    if(!str){
       return notify_fail("What?");
    }
    if( (str =="queen about marsh") || (str == "amazon about marsh")) {
    message ("environment",
              "The Queen smiles at you.\n"
    +"  %^RESET%^%^MAGENTA%^The Queen says: %^RESET%^I hope you brave adventurers can help my people save the forest.  I am saddened to say that a great evil has befallen this island.\n\n"
     +"%^RESET%^%^MAGENTA%^The Queen says%^RESET%^:  The forest is the last place that good can walk safely.\n"
      +"%^RESET%^%^MAGENTA%^The Queen says%^RESET%^:  This whole area was once a peaceful place.  The castle was ruled by a kind king.  He let my people roam the forest free.  One day, however, My scouts reported a dark sorceress walking through the forest towards the castle.\n"
       +"%^RESET%^%^MAGENTA%^The Queen says%^RESET%^:  He took control of the king's son and had an ancient demon possesses the child.  The king said he would give himself to the demon if he would release the child.  So the demon released the child and possessed the king.  It was too late unfortunately.  The child's heart had been corrupted and he wanted only evil.  Swarms of demons descended upon the castle and the marsh.\n"
      +"%^RESET%^%^MAGENTA%^The Queen says%^RESET%^:  We have kept them out of the forest by patrolling the cliffs but every once in a while a demon escapes the marsh and enters the forest.\n"
       +"%^RESET%^%^MAGENTA%^The Queen says%^RESET%^:  The castle was enveloped in an impenetrable fog.  My high priestess works endlessly trying to find some way to allow people to get through the fog.\n"
     +"%^RESET%^%^MAGENTA%^The Queen says%^RESET%^:  When she does find a way please help us by defeating the powers that control the king.\n\n"
      +"%^RESET%^%^MAGENTA%^The Queen says%^RESET%^:  Good luck brave adventurers."
                          ,environment (TO));
    return 1;
    }
}
